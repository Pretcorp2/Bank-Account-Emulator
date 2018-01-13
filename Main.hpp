/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.hpp
 * Author: hectorcanalessv
 *
 * Created on January 12, 2018, 6:25 PM
 */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Cuenta{
private:
    double saldo;
public:
    Cuenta();
    static double leerSaldo();
    static void guardarSaldo(double);
    static void guardarMovimiento(double,string);
    void Movimiento();
    void MostrarSaldo();
    void salir();
};

Cuenta::Cuenta(){
    this->saldo=leerSaldo();
    
}

void Cuenta::salir(){
    double aux=this->saldo;
    cout<<"Saliendo del Programa...";
    cout<<endl<<"Guardando Balance actual en el sistema, espere por favor...";
    guardarSaldo(aux);
    cout<<endl<<"El Balance Actual fue guardado exitosamente, nos vemos a la proxima...";
}

double Cuenta::leerSaldo(){
    ifstream archivo;
    double lector;
    archivo.open("Files/Important/saldo.txt");
    if(!archivo){
        cout<<"Cant Access the File";
        exit(1);
    }
    archivo>>lector;
    archivo.close();
    return lector;
}

void Cuenta::MostrarSaldo(){
    cout<<"Estimado Usuario, el balance de su Cuenta es de: "<<this->saldo<<endl;
}

void Cuenta::guardarSaldo(double balance){
    ofstream archivo("Files/Important/saldo.txt",ios::trunc);
    archivo<<balance;
    archivo.close();
}

void Cuenta::guardarMovimiento(double dato, string fecha){
    ofstream archivo("Files/Important/movimientos.txt",ios::app);
    archivo<<"Fecha: "<<fecha<<" Cantidad : "<<dato<<endl;
    archivo.close();
    
}

void Cuenta::Movimiento(){
    double movimiento;
    char user;
    string fecha,descrip;
    bool flag=true;
    cout<<"\n\n\n============Vamos a Registrar un Movimiento en su Cuenta============"<<endl;
    cout<<"\nIngrese el monto:  ";
    cin>>movimiento;
    
    cout<<"\nIngrese la Fecha de su movimiento utilizando el siguiente formato DIA / MES / AÑO : ";
    cin>>fecha;
    
    while(flag){
    cout<<"Ingrese la tecla (e) si su movimiento fue un egreso o la tecla (i) si fue un ingreso: ";
    cin>>user;
    switch(user){
        case 'e':
            flag=false;
            movimiento=movimiento*-1;
            this->saldo=this->saldo+movimiento;
            guardarMovimiento(movimiento,fecha);
            break;
        case 'i':
            flag=false;
            this->saldo=this->saldo+movimiento;
            guardarMovimiento(movimiento,fecha);
            break;
        case 'E':
            flag=false;
            movimiento=movimiento*-1;
            this->saldo=this->saldo+movimiento;
            guardarMovimiento(movimiento,fecha);
            break;
        case 'I':
            flag=false;
            this->saldo=this->saldo+movimiento;
            guardarMovimiento(movimiento,fecha);
             break;
        default:
            cout<<"\n Se equivoco a la hora de ingresar el dato, intente denuevo \n"; 
            break;
            
    }    
    }
    
    
}


#endif /* MAIN_HPP */

