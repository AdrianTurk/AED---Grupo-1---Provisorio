#include <iostream>
#include <cassert>

using std::cout;
using std::cin;


//unsigned getCantidadDias(unsigned mes, unsigned anio);
bool esBisiesto(unsigned anio);
unsigned getCantidadDiasFebrero(unsigned anio);
unsigned getCantidadDias(unsigned mes);

int main(){
    
    {//Pruebas
        void TestCantDias();
        void TestBisiestos();
    
        TestCantDias();
        TestBisiestos();
    
        cout << "La funcion paso las pruebas\n\n";
    }
    
    {//Aplicación
        unsigned obtenerAnio(void);
        unsigned obtenerMes(void);
        unsigned mes;

        mes = obtenerMes();
        cout << "Cantidad de Dias: " << (mes==2 ?
            getCantidadDiasFebrero(obtenerAnio()):
            getCantidadDias(mes));
    }
}

unsigned obtenerMes(void){
    //Solicita ingreso y valida mes
    cout << "Ingrese un mes:\n";
    unsigned mes;
    cin >> mes;
    return (mes > 0 and  mes < 13) ?
        mes :
        (cout<<"Mes no valido\n",
        obtenerMes());
}

unsigned obtenerAnio(void){
    //Solicita ingreso y valida anio
    cout << "Ingrese un año:\n";
    unsigned anio;
    cin >> anio;
    return anio > 1583 and anio < 3020 ?
        anio :
        (cout << "Año no valido\n",
        obtenerAnio());
}


void TestCantDias(){
    assert(31 == getCantidadDias(1));
    assert(31 == getCantidadDias(3));
    assert(30 == getCantidadDias(4));
    assert(31 == getCantidadDias(5));
    assert(30 == getCantidadDias(6));
    assert(31 == getCantidadDias(7));
    assert(31 == getCantidadDias(8));
    assert(30 == getCantidadDias(9));
    assert(31 == getCantidadDias(10));
    assert(30 == getCantidadDias(11));
    assert(31 == getCantidadDias(12));
}

void TestBisiestos(){
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
}

bool esBisiesto(unsigned anio){
    /*  DESCRIPCION:    
        PRECONDICIONES: */
    assert(anio > 1582 and anio < 3021);
    return  (anio % 4 == 0) and (anio % 100!=0) or
            (anio % 4 == 0) and (anio % 100==0) and (anio % 400==0);
    // (divisible por 4 y no divisible por 100 => bisiesto) O (divisible por 4 y 100 y por 400 => bisiesto)
}


unsigned getCantidadDias(unsigned mes){
    /*  DESCRIPCION:
        PRECONDICIONES:     */
    assert(mes < 13 and mes > 0 and mes != 2);
    return (mes == 4 or mes == 6 or mes == 9 or mes == 11) ?
        30:
        31;
}

unsigned getCantidadDiasFebrero(unsigned anio){
    /*  DESCRIPCION:
        PRECONDICIONES:     */
    return esBisiesto(anio) ?
            29 :
            28
    ;
}