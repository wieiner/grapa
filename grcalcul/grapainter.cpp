#include "grapainter.h"
#include <thread>
long long pow1(int basis, int exponent)
{
    long long res = 1;
    for (long long e = 0; e < exponent; e++)
        res *=  (long long)basis;
    return res;
}

void calcshell(grapainter* t, int idelta, int igap)
{
    t->calculate(idelta, igap);
}

int grapainter::calculate_mthrded (CalcHedraTypes ect)
{
    
    int num_threads = thread::hardware_concurrency();
    //num_threads = 8;
    std::cout << endl << "preparing " << num_threads << " treads " << endl;
    fs << endl << "preparing " << num_threads << " treads " << endl;
    

    grapainter* grv = new grapainter[num_threads];
    
    for (int i = 0; i < num_threads; i++)
    {
        
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

    
    fs.open("log"+ to_string(idelta+1) +".txt", std::fstream::in | std::fstream::out | std::fstream::app);

    cout << "tread " << idelta+1 << " started" << endl;
    fs << "tread " << idelta+1 << " started" << endl;

    int l = gralinks.size();
    long long len = pow1(numABC , l);
    cout << " number of steps of calculation = " << len << endl;
    for (long long i = idelta; i < (long long)len; i+= igap )
    {
        if ((i % 8000000) == 0) cout << "calculation  step  #" << i << " passed.. it is " << (( (long double)1.0 / (len / ((long long)(1+idelta)*i+1))) * 10000)/100 << " percent of work.." << endl;
        for (int j = 0; j < l; j++)
        {
            long long p =  pow1(numABC, j+1);
            long long remndr  = i - (i / p)* p; //otrezali werchnie razrjady
            remndr = remndr / (pow1(numABC, j));
            
            gralinks[j].a = remndr;
        }
            

        proof();
    }

    fs << endl << "calculate_mthrded() ended " << endl;
    fs.close();
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
            fs << endl << "combination " << i << ") error not attributed link found" << endl;
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
    fs << endl << i << ") ";
    if (isNotAllSymbolsUsed) fs << "NOT ALL SYMBOLS USED |";    
    for (auto a : gralinks) fs << "name " << a.name << " a = " << namesABC[a.a] << " | ";
    
    delete[] bv; bv = nullptr;
    return true;
}
