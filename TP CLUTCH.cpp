#include <iostream>
#include <stdlib.h>
using namespace std;

void menu(int o);
void creditos(string madeby);
char nombres(char vN1[], char vN2[], int);

int main(){
    int opcion, o;
    const int TAM=20;
    char vNombre1[TAM];
    char vNombre2[TAM];
    char c, p;
    cout << endl;
    cout << "=====================" << endl;
    cout << "CLUTCH" << endl;
    cout << "=====================" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "=====================" << endl;
    cout << "0 - SALIR" << endl;
    cout << "=====================" << endl;

    cin >> opcion;
    cout << endl;

    switch (opcion){
        ///-----------------------------------------------------
        case 1:
            cout << "=====================" << endl;
            cout << "CLUTCH" << endl;
            cout << "=====================" << endl;
            cout << "ANTES DE COMENZAR DEBEN REGISTRAR SUS NOMBRES." << endl;
            cout << endl;
            nombres(vNombre1, vNombre2, TAM);
            cout << "?CONFIRMAR NOMBRES? (S/N)" << " "; cin >> c;
            cout << endl;
            if(c == 'n' || c == 'N'){
                c=1;
                menu(c);
            }
            break;
        ///-----------------------------------------------------
        case 2:
            cout << "VOLVER AL MENU (M) || SALIR (S)" << endl;
            cin >> o;
            break;
        ///-----------------------------------------------------
        case 3:
            creditos("=====================");
            creditos("CREDITOS.");
            creditos("=====================");
            creditos("HECHO POR:");
            creditos("");
            creditos("-matusa.");
            creditos("");
            creditos("-tincho.");
            creditos("");
            creditos("-el seba.");
            creditos("");
            creditos("---------------------");
            creditos("GRACIAS POR JUGAR!!!.");
            creditos("---------------------");
            cout << endl;
            cout << "VOLVER AL MENU (M) || SALIR (S)" << " "; cin >> c;
            cout << endl;
            if(c == 'M' || c == 'm'){
                c = 1;
                menu(c);
            }
            else{
                if(c == 'S' || c == 's'){
                    abort();
                }
            }
        ///-----------------------------------------------------
        case 0:
            abort();
        break;

    }

return 0;
}


void menu(int o){

    switch(o){
        case 1:
            int opcion, o;
            const int TAM=20;
            char vNombre1[TAM];
            char vNombre2[TAM];
            char c, p;
            cout << "=====================" << endl;
            cout << "CLUTCH" << endl;
            cout << "=====================" << endl;
            cout << "1 - JUGAR" << endl;
            cout << "2 - ESTADISTICAS" << endl;
            cout << "3 - CREDITOS" << endl;
            cout << "=====================" << endl;
            cout << "0 - SALIR" << endl;
            cout << "=====================" << endl;

            cin >> opcion;
            cout << endl;

            switch (opcion){
                ///-----------------------------------------------------
                case 1:
                    cout << endl;
                    cout << "=====================" << endl;
                    cout << "CLUTCH" << endl;
                    cout << "=====================" << endl;
                    cout << "ANTES DE COMENZAR DEBEN REGISTRAR SUS NOMBRES." << endl;
                    cout << endl;
                    nombres(vNombre1, vNombre2, TAM);
                    cout << "?CONFIRMAR NOMBRES? (S/N)" << " "; cin >> c;
                    cout << endl;
                    if(c == 'n' || c == 'N'){
                        c=1;
                        menu(c);
                    }
                    cout << endl;
                    break;
                ///-----------------------------------------------------
                case 2:
                    cout << "+ VOLVER AL MENU (1) SALIR (0) +" << endl;
                    cin >> o;
                    break;
                ///-----------------------------------------------------
                case 3:
                    creditos("CREDITOS.");
                    creditos("=====================");
                    creditos("HECHO POR:");
                    creditos("");
                    creditos("-matusa.");
                    creditos("");
                    creditos("-tincho.");
                    creditos("");
                    creditos("-el seba.");
                    creditos("");
                    creditos("---------------------");
                    creditos("GRACIAS POR JUGAR!!!.");
                    creditos("---------------------");
                    cout << endl;
                    cout << "+ VOLVER AL MENU (1) SALIR (0) +" << " "; cin >> p;
                    if(p == 'M' || p == 'm'){
                        p = 1;
                        menu(p);
                    }
                    else{
                        if(p == 'S' || p == 's'){
                            abort();
                        }
                    }
                ///-----------------------------------------------------
                case 0:
                    abort();
                break;

            }
    }
}

void creditos(string madeby){
    cout << madeby << endl;
}

char nombres(char vN1[], char vN2[], int tam){

    vN1[tam]={};
    vN2[tam]={};
    cin.getline(vN1, tam, '\n');
    cout << "JUGADOR 1: " << " "; cin.getline(vN1, tam, '\n');
    cout << "JUGADOR 2: " << " "; cin.getline(vN2, tam, '\n'); cout << endl;

}
