#include <iostream>
#include <cassert>
///PROTOTIPOS:
bool esBisiesto(int anio);
unsigned getCantidadDias(unsigned mes, unsigned anio);

//IMPLEMENTACIONES:

int main()
{
    //PRUEBAS:
    assert(esBisiesto(1600));
    assert(!esBisiesto(1700));
    assert(!esBisiesto(1800));
    assert(!esBisiesto(1900));
    assert(esBisiesto(1584));
    assert(esBisiesto(1628));
    assert(esBisiesto(1776));
    assert(esBisiesto(1888));
    assert(esBisiesto(1912));
    assert(!esBisiesto(1700));
    assert(esBisiesto(2004));
    assert(esBisiesto(2020));
    assert(!esBisiesto(2021));
    assert(esBisiesto(2044));
    assert(!esBisiesto(2094));
    assert(esBisiesto(2096));

    assert(29 == getCantidadDias(2,2020));
    assert(31 == getCantidadDias(10,2021));

    std::cout << "La funcion paso las pruebas";

    std::cin.get();  //Para pausar en debug
}

bool esBisiesto(int anio){
    /*  DESCRIPCION:
        PRECONDICIONES:     */

    assert(anio > 1582 && anio < 3021);
    return (anio % 4 == 0) && (anio % 100!=0) || (anio % 4 == 0) && (anio % 100==0) && (anio % 400==0);
    // (divisible por 4 y no divisible por 100 => bisiesto) O (divisible por 4 y 100 y por 400 => bisiesto)
}

unsigned getCantidadDias(unsigned mes, unsigned anio){
    /*  DESCRIPCION:
        PRECONDICIONES:     */
    
    return (mes == 4 || mes == 6 || mes == 9 || mes == 11) ?
        30 :
        mes != 2 ? 
            31 :
            esBisiesto(anio) ?
                29 :
                28
    ;
}