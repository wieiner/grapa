// grcalcul.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "grapainter.h"



int main()
{
    grapainter gr;
    gr.calculate_mthrded(CalcHedraTypes::cGrawitaHedra);

    //current_ini_creator(CalcHedraTypes::cGrawitaHedra, 256, 8); // GrawitaHedra 16 process, 4 threads

    std::cout << "calculation done!\n Have a nice day!\n";

    
}

