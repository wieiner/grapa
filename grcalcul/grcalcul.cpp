// grcalcul.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "grapainter.h"



int main()
{
    grapainter gr;
    gr.calculate_mthrded(CalcHedraTypes::cTetraHedra);
    std::cout << "calculation done!\n Have a nice day!\n";
}

