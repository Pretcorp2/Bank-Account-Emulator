#include <cstdlib>
#include "Tools/Main.hpp"

using namespace std;

void menu();
void nlinea(int);

int main(int argc, char** argv) {
    Cuenta user;
    bool flag=true;
    int opcion;
    while(flag){
        menu();
        cin>>opcion;
        switch(opcion){
            case 1:
                user.MostrarSaldo();
                nlinea(1);
                break;
            case 2:
                user.Movimiento();
                nlinea(1);
                break;
            case 0:
                nlinea(6);
                user.salir();
                exit(1);
            default:
                cout<<"No selecciono una orden correcta, intente denuevo \n";
                nlinea(4);
        }
        
    }
    
    
    
    
    return 0;
}

void menu(){
    cout<<"================== M E N U ==================\n";
    cout<<"2-Agregar Movimiento de Balance \n";
    cout<<"1-Mostrar Balance actual\n";
    cout<<"0-Salir\n";
}

void nlinea(int veces=1){
    for(int i;i<=veces;i++){
        cout<<'\n';
    }
}