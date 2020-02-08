#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


enum CalcHedraTypes {cTetraHedra, cOctaHedra, cPentaHedra, cGrawitaHedra, cMaxHedra};
class cgrobj
{
public:
    vector<int> inner_gralinks;
    string name;
};

class cgralinks
{
public:
    int x, z, a;// source obj id, dest obj id, link attribute (L4 symbol)
    string name;
};

class grapainter
{

public:
    fstream fs;
    int        numABC;
    vector<string>     namesABC;
    vector<cgrobj>       grobj;
    vector<cgralinks>   gralinks;
    void tetrahedra() {
        namesABC.clear();   namesABC.push_back("T"); namesABC.push_back("F"); namesABC.push_back("U");
        numABC=namesABC.size();
        cgrobj tmp;
        tmp.name = "X";//0
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(1);//XZ
        tmp.inner_gralinks.push_back(2);//XB
        grobj.push_back(tmp);

        tmp.name = "A";//1
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(3);//AZ
        tmp.inner_gralinks.push_back(5);//BA
        grobj.push_back(tmp);

        tmp.name = "B";//2
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(2);//XB
        tmp.inner_gralinks.push_back(4);//ZB
        tmp.inner_gralinks.push_back(5);//BA
        grobj.push_back(tmp);

        tmp.name = "Z";//3
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(1);//XZ
        tmp.inner_gralinks.push_back(3);//AZ
        tmp.inner_gralinks.push_back(4);//ZB
        grobj.push_back(tmp);

        cgralinks tmpl;
        

        tmpl.name = "XA";//0
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 1;
        gralinks.push_back(tmpl);

        tmpl.name = "XZ";//1
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "XB";//2
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "AZ";//3
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "ZB";//4
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "BA";//5
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 1;
        gralinks.push_back(tmpl);

    };
    void octahedra() {
        namesABC.clear(); namesABC.push_back("N"); namesABC.push_back("T"); namesABC.push_back("F"); namesABC.push_back("U");
        numABC = namesABC.size();
        cgrobj tmp;
        tmp.name = "X";//0
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(1);//XB
        tmp.inner_gralinks.push_back(2);//XC
        tmp.inner_gralinks.push_back(3);//XD
        grobj.push_back(tmp);

        tmp.name = "A";//1
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(4);//AB
        tmp.inner_gralinks.push_back(7);//AD
        tmp.inner_gralinks.push_back(8);//AZ
        grobj.push_back(tmp);

        tmp.name = "B";//2
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(1);//XB
        tmp.inner_gralinks.push_back(4);//AB
        tmp.inner_gralinks.push_back(5);//BC
        tmp.inner_gralinks.push_back(9);//BZ
        grobj.push_back(tmp);

        tmp.name = "C";//3
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(2);//XC
        tmp.inner_gralinks.push_back(5);//BC
        tmp.inner_gralinks.push_back(6);//CD
        tmp.inner_gralinks.push_back(10);//CZ
        grobj.push_back(tmp);

        tmp.name = "D";//4
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(3);//XD
        tmp.inner_gralinks.push_back(6);//CD
        tmp.inner_gralinks.push_back(7);//AD
        tmp.inner_gralinks.push_back(11);//DZ
        grobj.push_back(tmp);

        tmp.name = "Z";//5
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(8);//AZ
        tmp.inner_gralinks.push_back(9);//BZ
        tmp.inner_gralinks.push_back(10);//CZ
        tmp.inner_gralinks.push_back(11);//DZ
        grobj.push_back(tmp);

        cgralinks tmpl;


        tmpl.name = "XA";//0
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 1;
        gralinks.push_back(tmpl);

        tmpl.name = "XB";//1
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "XC";//2
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "XD";//3
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 4;
        gralinks.push_back(tmpl);

        tmpl.name = "AB";//4
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "BC";//5
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "CD";//6
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 4;
        gralinks.push_back(tmpl);

        tmpl.name = "DA";//7
        tmpl.a = -1; tmpl.x = 4; tmpl.z = 1;
        gralinks.push_back(tmpl);

        tmpl.name = "AZ";//8
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "BZ";//9
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "CZ";//10
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "DZ";//11
        tmpl.a = -1; tmpl.x = 4; tmpl.z = 5;
        gralinks.push_back(tmpl);


    };
    void pentahedra() {
         namesABC.clear(); namesABC.push_back("V"); namesABC.push_back("N"); namesABC.push_back("T"); namesABC.push_back("F"); namesABC.push_back("U");
         numABC = namesABC.size();
        cgrobj tmp;
        tmp.name = "X";//0
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(1);//XB
        tmp.inner_gralinks.push_back(2);//XC
        tmp.inner_gralinks.push_back(3);//XD
        tmp.inner_gralinks.push_back(12);//XZ
        grobj.push_back(tmp);

        tmp.name = "A";//1
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(4);//AB
        tmp.inner_gralinks.push_back(7);//AD
        tmp.inner_gralinks.push_back(8);//AZ
        tmp.inner_gralinks.push_back(14);//AC
        grobj.push_back(tmp);

        tmp.name = "B";//2
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(1);//XB
        tmp.inner_gralinks.push_back(4);//AB
        tmp.inner_gralinks.push_back(5);//BC
        tmp.inner_gralinks.push_back(9);//BZ
        tmp.inner_gralinks.push_back(13);//BD
        grobj.push_back(tmp);

        tmp.name = "C";//3
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(2);//XC
        tmp.inner_gralinks.push_back(5);//BC
        tmp.inner_gralinks.push_back(6);//CD
        tmp.inner_gralinks.push_back(10);//CZ
        tmp.inner_gralinks.push_back(14);//AC
        grobj.push_back(tmp);

        tmp.name = "D";//4
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(3);//XD
        tmp.inner_gralinks.push_back(6);//CD
        tmp.inner_gralinks.push_back(7);//AD
        tmp.inner_gralinks.push_back(11);//DZ
        tmp.inner_gralinks.push_back(13);//BD
        grobj.push_back(tmp);

        tmp.name = "Z";//5
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(8);//AZ
        tmp.inner_gralinks.push_back(9);//BZ
        tmp.inner_gralinks.push_back(10);//CZ
        tmp.inner_gralinks.push_back(11);//DZ
        tmp.inner_gralinks.push_back(12);//XZ
        grobj.push_back(tmp);

        cgralinks tmpl;


        tmpl.name = "XA";//0
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 1;
        gralinks.push_back(tmpl);

        tmpl.name = "XB";//1
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "XC";//2
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "XD";//3
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 4;
        gralinks.push_back(tmpl);

        tmpl.name = "AB";//4
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "BC";//5
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "CD";//6
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 4;
        gralinks.push_back(tmpl);

        tmpl.name = "DA";//7
        tmpl.a = -1; tmpl.x = 4; tmpl.z = 1;
        gralinks.push_back(tmpl);

        tmpl.name = "AZ";//8
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "BZ";//9
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "CZ";//10
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "DZ";//11
        tmpl.a = -1; tmpl.x = 4; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "XZ";//12
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "BD";//13
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 4;
        gralinks.push_back(tmpl);

        tmpl.name = "AC";//14
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 3;
        gralinks.push_back(tmpl);


    };
    void grawitahedra() {
        namesABC.clear(); namesABC.push_back("M"); namesABC.push_back("V"); namesABC.push_back("N"); namesABC.push_back("T"); namesABC.push_back("F"); namesABC.push_back("U");
        numABC = namesABC.size();
        cgrobj tmp;
        tmp.name = "X";//0
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(1);//XB
        tmp.inner_gralinks.push_back(2);//XC
        tmp.inner_gralinks.push_back(3);//XD
        tmp.inner_gralinks.push_back(12);//XZ
        grobj.push_back(tmp);

        tmp.name = "A";//1
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(0);//XA
        tmp.inner_gralinks.push_back(4);//AB
        tmp.inner_gralinks.push_back(7);//AD
        tmp.inner_gralinks.push_back(8);//AZ
        tmp.inner_gralinks.push_back(14);//AO
        grobj.push_back(tmp);

        tmp.name = "B";//2
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(1);//XB
        tmp.inner_gralinks.push_back(4);//AB
        tmp.inner_gralinks.push_back(5);//BC
        tmp.inner_gralinks.push_back(9);//BZ
        tmp.inner_gralinks.push_back(13);//BO
        grobj.push_back(tmp);

        tmp.name = "C";//3
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(2);//XC
        tmp.inner_gralinks.push_back(5);//BC
        tmp.inner_gralinks.push_back(6);//CD
        tmp.inner_gralinks.push_back(10);//CZ
        tmp.inner_gralinks.push_back(16);//CO
        grobj.push_back(tmp);

        tmp.name = "D";//4
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(3);//XD
        tmp.inner_gralinks.push_back(6);//CD
        tmp.inner_gralinks.push_back(7);//AD
        tmp.inner_gralinks.push_back(11);//DZ
        tmp.inner_gralinks.push_back(15);//DO
        grobj.push_back(tmp);

        tmp.name = "Z";//5
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(8);//AZ
        tmp.inner_gralinks.push_back(9);//BZ
        tmp.inner_gralinks.push_back(10);//CZ
        tmp.inner_gralinks.push_back(11);//DZ
        tmp.inner_gralinks.push_back(12);//XO
        grobj.push_back(tmp);

        tmp.name = "O";//6
        tmp.inner_gralinks.clear();
        tmp.inner_gralinks.push_back(12);//XO
        tmp.inner_gralinks.push_back(13);//BO
        tmp.inner_gralinks.push_back(14);//AO
        tmp.inner_gralinks.push_back(15);//DO
        tmp.inner_gralinks.push_back(16);//CO
        tmp.inner_gralinks.push_back(17);//ZO
        grobj.push_back(tmp);

        cgralinks tmpl;


        tmpl.name = "XA";//0
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 1;
        gralinks.push_back(tmpl);

        tmpl.name = "XB";//1
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "XC";//2
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "XD";//3
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 4;
        gralinks.push_back(tmpl);

        tmpl.name = "AB";//4
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 2;
        gralinks.push_back(tmpl);

        tmpl.name = "BC";//5
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 3;
        gralinks.push_back(tmpl);

        tmpl.name = "CD";//6
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 4;
        gralinks.push_back(tmpl);

        tmpl.name = "DA";//7
        tmpl.a = -1; tmpl.x = 4; tmpl.z = 1;
        gralinks.push_back(tmpl);

        tmpl.name = "AZ";//8
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "BZ";//9
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "CZ";//10
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "DZ";//11
        tmpl.a = -1; tmpl.x = 4; tmpl.z = 5;
        gralinks.push_back(tmpl);

        tmpl.name = "XO";//12
        tmpl.a = -1; tmpl.x = 0; tmpl.z = 6;
        gralinks.push_back(tmpl);

        tmpl.name = "BO";//13
        tmpl.a = -1; tmpl.x = 2; tmpl.z = 6;
        gralinks.push_back(tmpl);

        tmpl.name = "AO";//14
        tmpl.a = -1; tmpl.x = 1; tmpl.z = 6;
        gralinks.push_back(tmpl);

        tmpl.name = "DO";//15
        tmpl.a = -1; tmpl.x = 4; tmpl.z = 6;
        gralinks.push_back(tmpl);

        tmpl.name = "CO";//16
        tmpl.a = -1; tmpl.x = 3; tmpl.z = 6;
        gralinks.push_back(tmpl);

        tmpl.name = "ZO";//17
        tmpl.a = -1; tmpl.x = 5; tmpl.z = 6;
        gralinks.push_back(tmpl);

    };
    void calculate(int idelta, int igap);
    int calculate_mthrded(CalcHedraTypes ect);
    bool proof();
};

