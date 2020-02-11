#include "grapainter.h"
#include <thread>

#include <direct.h> //for mkdir current_ini_creator only


static array<string, cMaxHedra> sCalcHedraTypes  { "cTetraHedra", "cOctaHedra", "cPentaHedra", "cGrawitaHedra" };


long long pow1(int basis, int exponent)
{
    long long res = 1;
    for (long long e = 0; e < exponent; e++)
        res *=  (long long)basis;
    return res;
}



void current_ini_creator(CalcHedraTypes ect, int parts, int threads)
{
    fstream f;
    f.open("parts.txt", fstream::out);
    fstream ftmp;


    grapainter gr;
    gr.ahedrize_it(ect);

    long long len = pow1(gr.numABC, gr.gralinks.size());

    
    
    f << "length = " << len << endl;
    f << "divided on " << parts << " parts " << endl;
    
    long long chnk_size = len / parts;
    f << "each chunk " << chnk_size << " steps " << endl;

    int d = 0;
    string scurrdir;

    for (long long i = 0; i < len; i += chnk_size, d++)
    {

        scurrdir = "pid" + std::to_string(d);
        _mkdir(scurrdir.c_str());
        

        f << "============" << d << " of " << len << endl;
        long long endval = i + chnk_size;
        if (endval > len) endval = len;

        for (long long j = 0; j < threads; j++)
        {
            ftmp.open((scurrdir + "\\current" + to_string(j) + ".ini").c_str(), fstream::out);
            ftmp << i + j << endl << i + j << endl << endval << endl;
            ftmp.close();

            f << i + j << endl << i + j << endl << endval << endl;
        }
    }

    

    f.close();
}




void calcshell(grapainter* t, int idelta, int igap)
{
    t->calculate(idelta, igap);
}


int grapainter::calculate_mthrded (CalcHedraTypes ect)
{
    
    int num_threads = thread::hardware_concurrency();
    num_threads = 8;//prinujdenie k STSCHETY  w 8 potoka!!!

    std::cout  << endl << "begin painting " << sCalcHedraTypes[ect] << " graph " << endl;
    std::cout << endl << "preparing " << num_threads << " threads " << endl;
    
    

    grapainter* grv = new grapainter[num_threads];
    
    for (int i = 0; i < num_threads; i++)
    {
        grv[i].ahedrize_it(ect);
        /*
        switch (ect)
        {
        case cTetraHedra:
            (grv[i]).tetrahedra();
            break;

        case cOctaHedra:
            (grv[i]).octahedra();
            break;

        case cPentaHedra:
            (grv[i]).pentahedra();
            break;

        case cGrawitaHedra:
            (grv[i]).grawitahedra();
            break;

        }
        */

    }


    vector<thread> thrv;

    for (int i = 0; i < num_threads; i++) {
        thrv.push_back( thread(calcshell, &grv[i], i, num_threads));
    }
        
    for (int i = 0; i < num_threads; i++) {
        thrv[i].join();
    }

    cout << endl << "calculate_mthrded() ended " << endl;
    thrv.clear();
    delete[] grv; grv = nullptr;
    return 0;
}

void grapainter::calculate(int idelta, int igap)
{

    logilog.inite(idelta);

    fs_results.open("results"+ to_string(idelta+1) +".txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs_results << endl << "begin painting " << sCalcHedraTypes[crnt_type] << " graph " << endl;
    fs_results  << "preparing " << igap << " threads " << endl;

    cout << "tread " << idelta+1 << " started" << endl;
    fs_results << "tread " << idelta+1 << " started" << endl;

    int l = gralinks.size();
    long long len;

    if (logilog.end_inclusive==0)
    {
        cout << " number of steps of calculation in ini file not found. All interval used " << endl;
        fs_results << " number of steps of calculation in ini file not found. All interval used " << endl;
        len = pow1(numABC, l);
    } 
    else
        len = logilog.end_inclusive;

    cout << " number of steps of calculation = " << len << endl;
    fs_results << "begin/currpos " << logilog.beg_inclusive  << " / " << logilog.current_position
        << " number of steps of calculation = " << len << endl;
    for (long long i = logilog.current_position, jpage=0; i < (long long)len; i+= igap, jpage++ )
    {
        if ((jpage % 3200000) == 0) {
            cout << "calculation  step  #" << i << " passed.. it is " << (((long double)1.0 / (len / ((long long)(1 + idelta) * i + 1))) * 10000) / 100 << " percent of work.." << endl;
            logilog.current_position = i;
            logilog.end_inclusive = len;
            logilog.autosave(idelta);
        }

        for (int j = 0; j < l; j++)
        {
            long long p =  pow1(numABC, j+1);
            long long remndr  = i - (i / p)* p; //otrezali werchnie razrjady
            remndr = remndr / (pow1(numABC, j));
            
            gralinks[j].a = remndr;
        }
            

        proof();
    }

    fs_results << endl << "calculate_mthrded() ended " << endl;
    fs_results.close();
    return;
}


bool grapainter::proof()
{
    static int i = 0;
    i++;
    bool isNotAllSymbolsUsed = false;
    int* bv = new int[numABC+1];
    for (auto a : grobj) {
        
        for (int k = 0; k <= numABC; k++)  bv[k] = 0;
        for (auto l : a.inner_gralinks)
        {
            if (gralinks[l].a < 0) bv[numABC]++;
            else  bv[gralinks[l].a]++;
        }
     
        if (bv[numABC])
        {
            fs_results << endl << "combination " << i << ") error not attributed link found" << endl;
            return false;
        }
        for (int k = 0; k < numABC; k++)
            if (bv[k] > 1)
        {
            //it is not good combination. return
            delete[] bv; bv = nullptr;
            return false;
        } else 
            if (bv[k] == 0) isNotAllSymbolsUsed = true;
    }

    //ok! godgiven combination found. will record it!
    fs_results << endl << i << ") ";
    if (isNotAllSymbolsUsed) fs_results << "NOT ALL SYMBOLS USED |";    
    for (auto a : gralinks) fs_results << "name " << a.name << " a = " << namesABC[a.a] << " | ";
    
    delete[] bv; bv = nullptr;
    return true;
}
