#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int vPuntuacion[5]={};
bool roboj1 = false, roboj2 = false, SaltoTurnoJ16=false, SaltoTurnoJ26=false;
int maximaPuntuacion=0, cartasMalUbicadas;
string ganador, maximoGanador;


// Definici�n de la estructura Carta, se crea como un nuevo tipo de dato, el dato "Carta". "Carta" representa una carta de un palo y su valor.
struct Carta {
    string palo;
    string valor;
};

// Funci�n para inicializar la baraja con 20 cartas. & significa que recibe al vector por referencia. esto permite modificar el vector dentro de la funcion.
void inicializarBaraja(Carta baraja[]) {
    string palos[] = {"Corazones", "Diamantes", "Treboles", "Picas"};
    string valores[] = {"10", "J", "Q", "K", "A"};

    int ind=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {

            baraja[ind].palo = palos[i];
            baraja[ind].valor = valores[j];
            ind++;

        }
    }
}

// Funci�n para repartir cartas a dos jugadores
void repartirCartas(Carta baraja[], Carta jugador1[], Carta jugador2[], int TAM) {

    srand(static_cast<unsigned>(time(nullptr)));  // Inicializar la semilla aleatoria.

    int cartasPorJugador = 5; ///se declara una variable con la cantidad de cartas para cada jugador.

    // Repartir cartas a cada jugador
    for (int i = 0; i < cartasPorJugador; i++) {

        int indice = rand() % TAM; // Generar un �ndice aleatorio entre 0 y el tama�o de la baraja(menos 1 = 0 - 19), y lo guarda en la variable "indice".
        jugador1[i] = baraja[indice];  /// Agregar la carta al vector "jugador 1" dependiendo de la posicion aleatoria guardada en "indice".
        baraja[indice] = baraja[TAM-1];  // Eliminar la carta de la baraja para que no se repita.
        TAM--;

        indice = rand() % TAM; ///repetir el proceso para el vector "jugador 2".
        jugador2[i] = baraja[indice];
        baraja[indice] = baraja[TAM-1];//elimina un elemento del vector baraja.
        TAM--;
    }
}

// Funci�n para mostrar las cartas de un jugador
void mostrarCartas(Carta jugador[], int tam, string nombreJugador) {
    cout << "==================================" << endl;
    cout << nombreJugador << " TIENE LAS SIGUIENTES CARTAS:" << endl;
    cout << "==================================" << endl;
    cout << endl;
    for (int i=0; i<tam; i++) { ///ciclo que recorre el vector "jugador (jugar1 y jugador2)"
        cout << " " << jugador[i].valor << " de " << jugador[i].palo << endl; //accede a los elementos del vector de tipo carta y muestra sus elementos.
    }
    cout << endl;
}

// Funci�n para determinar el jugador que comienza
string determinarJugadorQueComienza(Carta jugador1[], Carta jugador2[],int& turno) {

    // Contadores
    int vC1[5]={};
    int vC2[5]={};
    int c=4;
    bool quienEmpieza = true;

    // Calcular la cantidad de Ases y Ks para cada jugador
    for (int i = 0; i < 5; i++) {
        if (jugador1[i].valor == "A") {
            vC1[4]++;
        }
        if (jugador2[i].valor == "A") {
            vC2[4]++;
        }
        if (jugador1[i].valor == "K") {
            vC1[3]++;
        }
        if (jugador2[i].valor == "K") {
            vC2[3]++;
        }
        if (jugador1[i].valor == "Q") {
            vC1[2]++;
        }
        if (jugador2[i].valor == "Q") {
            vC2[2]++;
        }
        if (jugador1[i].valor == "J") {
            vC1[1]++;
        }
        if (jugador2[i].valor == "J") {
            vC2[1]++;
        }
        if (jugador1[i].valor == "10") {
            vC1[0]++;
        }
        if (jugador2[i].valor == "10") {
            vC2[0]++;
        }
    }
    // Determinar qui�n comienza
    while(quienEmpieza){

        if(vC1[c]>vC2[c]){
            quienEmpieza = false;
            turno=1;
            return "JUGADOR 1";
        }
        else{
            if(vC1[c]<vC2[c]){
                quienEmpieza = false;
                turno=2;
                return "JUGADOR 2";
            }
        }
        c--;
        if(c==0){
            return "EMPATE";
        }
    }
}

//Funcion comienzo aleatorio.
string comienzoAleaotorio(int& turno){
    int indice = (rand()%2)+1;

    if(indice == 1){
        turno=1;
        return "JUGADOR 1.";
    }
    else{
        turno=2;
        return "JUGADOR 2.";
    }
return 0;
}

//Funcion para tirar los dados.
int TirarDado(){
    return (rand() % 6) + 1; //genera un numero aleatorio entre el 1 y el tama�o elegido, en este caso 6 y retorna su valor;
}

//funcion dado 1.
void funcionDado1(Carta jugador[], Carta baraja[], int ce, bool bloqueo[]){

    int ind = (rand() % 10) + 1;
    Carta aux;

    aux = jugador[ce-1];
    jugador[ce-1] = baraja[ind-1];
    baraja[ind-1] = aux;

   if(bloqueo[ce-1] == true){

        bloqueo[ce-1] = false;

    }
}

//funcion dado 2.
void funcionDado2(Carta jugador2[], int ce, Carta baraja[],bool BloqueoJ2[]){

    Carta aux;
    int n;
    if(BloqueoJ2[ce-1]){

        cout<<"ESTA CARTA SE ENCUENTRA BLOQUEADA, ELIJA OTRA CARTA "; cin>>ce;
        while(BloqueoJ2[ce-1]){
        cout<<"ESTA CARTA SE ENCUENTRA BLOQUEADA, ELIJA OTRA CARTA "; cin>>ce;
        }
        n=(rand() % 10) + 1;
        aux = baraja[n-1];
        baraja[n-1] = jugador2[ce-1];
        jugador2[ce-1] = aux;

    }
    else{
        n = (rand() % 10) + 1;
        aux = baraja[n-1];
        baraja[n-1] = jugador2[ce-1];
        jugador2[ce-1] = aux;
    }
}

//funciion dado 3.
void funcionDado3(int ce1, int ce2, Carta j1[], Carta j2[], bool bloqueo[]){

    Carta aux;

    if(bloqueo[ce2-1]){

        cout << "CARTA BOQUEADA, ELIJA OTRA CARTA."; cin >> ce2;
        while(bloqueo[ce2-1]){
            cout << "CARTA BOQUEADA, ELIJA OTRA CARTA."; cin >> ce2;
        }

        aux = j1[ce1-1];
        j1[ce1-1] = j2[ce2-1];
        j2[ce2-1] = aux;

    }
    else{
        aux = j1[ce1-1];
        j1[ce1-1] = j2[ce2-1];
        j2[ce2-1] = aux;
    }

}

//funcion dado 4.
void funcionDado4(Carta jugador[], int ce, int ce1, bool bloqueo[]){

    Carta aux;
    aux = jugador[ce-1];
    jugador[ce-1] = jugador[ce1-1];
    jugador[ce1-1] = aux;

    bloqueo[ce-1] = false;
    bloqueo[ce1-1] = true;

}

//funcion dado 5
void funcionDado5(Carta jugador[], int ce, bool bloqueo[]){

    if(bloqueo[ce-1==true]){
        cout<<"ESTA CARTA YA ESTA BLOQUEADA, ELIJA OTRA CARTA: "<<endl;
        cin>>ce;
        while(bloqueo[ce-1]){
        cout<<"ESTA CARTA YA ESTA BLOQUEADA, ELIJA OTRA CARTA: "<<endl;
        cin>>ce;
        }
        bloqueo[ce-1] = true;
        cout << "SE BLOQUEO LA CARTA " << jugador[ce-1].valor << " DE " << jugador[ce-1].palo << endl;
    }
    else{
        bloqueo[ce-1] = true;
        cout << "SE BLOQUEO LA CARTA " << jugador[ce-1].valor << " DE " << jugador[ce-1].palo << endl;
    }
}

//funcion dado 6.
void funcionDado6(int ce, int turno, Carta jugador1[], Carta jugador2[], Carta baraja[], bool BloqueoJ1[], bool BloqueoJ2[]){

    int ce1, cartaElegida1, cartaElegida2;
    switch(ce){
        case 1:

            cout << "ELIJE UNA CARTA PARA INTERCAMBIAR CON LA BARAJA 1-5:" << " "; cin >> ce;
            if(turno==1){
                funcionDado1(jugador1, baraja, ce, BloqueoJ1);
            }
            else{
                funcionDado1(jugador2, baraja, ce, BloqueoJ2);
            }
            system("pause");

        break;

        case 2:

            cout << "Elegir una carta del corral del contrario (1-5) y robar una carta del mazo" << " "; cin >> ce;
            if(turno==1){
                funcionDado2(jugador2,ce,baraja,BloqueoJ2);
            }
            else{
                funcionDado2(jugador1,ce,baraja,BloqueoJ1);
            }
            system("pause");

        break;

        case 3:

            cout<<"ELEGIR UNA CARTA DEL CORRAL PROPIO (1-5) E INTERCAMBIARLA POR UNA DEL CORRAL OPONENTE (1-5). "<<endl;
            if(turno==1){
                cout << "CARTA DE TU CORRAL(1-5):" << " "; cin >> cartaElegida1; cout << endl;
                cout << "CARTA DEL CORRAL CONTRARIO(1-5):" << " "; cin >> cartaElegida2; cout << endl;
                funcionDado3(cartaElegida1, cartaElegida2, jugador1, jugador2, BloqueoJ2);
                roboj2 = true;
                if(jugador1[0].valor == "10" && jugador1[1].valor == "J" && jugador1[2].valor == "Q" && jugador1[3].valor == "K" && jugador1[4].valor == "A"){
                    vPuntuacion[1]+=10;
                }
            }
            else{
                cout << "CARTA DE TU CORRAL(1-5):" << " "; cin >> cartaElegida1; cout << endl;
                cout << "CARTA DEL CORRAL CONTRARIO(1-5):" << " "; cin >> cartaElegida2; cout << endl;
                funcionDado3(cartaElegida1, cartaElegida2, jugador2, jugador1, BloqueoJ1);
                roboj1 = true;
                if(jugador1[0].valor == "10" && jugador1[1].valor == "J" && jugador1[2].valor == "Q" && jugador1[3].valor == "K" && jugador1[4].valor == "A"){
                    vPuntuacion[1]+=10;
                }
            }
            system("pause");

        break;

        case 4:

            cout << "ELIGE DOS CARTAS DE TU MAZO (1-5) Y SE INTERCAMBIAN ENTRE SI."; cin >> ce; cout << " "; cin >> ce1;
            if(turno==1){
                funcionDado4(jugador1, ce, ce1, BloqueoJ1);
            }
            else{
                funcionDado4(jugador2, ce, ce1, BloqueoJ2);
            }
            system("pause");

        break;

        case 5:

            cout << "ELIJE UNA CARTA DE TU CORRAL PARA BLOQUEARLA:" << " "; cin >> ce;
            if(turno==1){
                funcionDado5(jugador1, ce, BloqueoJ1);
            }
            else{
                funcionDado5(jugador2, ce, BloqueoJ2);
            }
            system("pause");

        break;

       default:
            cout << "Pasando el turno..." <<endl;
            system("pause");
        break;
    }
}

//funcion para mostrar los creditos.
void creditos() {
    cout << " " << " +"<<"=======================+"<<endl;
	cout << " " << " |"<<"       CREDITOS.       |"<<endl;
	cout << " " << " +"<<"=======================+" << endl;
	cout << " " << " |                       |"<< endl;
    cout << " " << " |"<< "     +HECHO POR+"; cout << "       |" << endl;
    cout << " " << " |                       |"<< endl;
    cout << " " << " |"<< "- MATUSALEN PECCHINI"; cout << "   |" << endl;
    cout << " " << " |                       |"<< endl;
    cout << " " << " |"<< "- SEBASTIAN DIAZ"; cout << "       |" << endl;
    cout << " " << " |                       |"<< endl;
    cout << " " << " |"<< "- MARTIN MORINICO"; cout << "      |" << endl;
    cout << " " << " |                       |"<< endl;
    cout << " " << " +"<<"=======================+" << endl;
    cout << " " << " |"<<"  GRACIAS POR JUGAR!!  |"<<endl;
    cout << " " << " +"<<"=======================+" << endl;
}

//funcion para guardar los nombres.
void nombres(char vNombre1[], char vNombre2[], int tam) {


    vNombre1[tam] = {};
    vNombre2[tam] = {};
    cin.getline(vNombre1, tam, '\n');

    cout << "JUGADOR 1: " << " ";
    cin.getline(vNombre1, tam, '\n');
    cout << endl;
    cout << "JUGADOR 2: " << " ";
    cin.getline(vNombre2, tam, '\n');
    cout << endl;
}

//MENU PRINCIPAL.
int main() {

    system("cls");
    bool partida=true;
    const int TAM=20, TAM2=5;
    int opcion, dado;
    char c;
    int ce, ce1, turno=0, cartaElegida1, cartaElegida2, totalPuntos=0;

    Carta baraja[TAM]={};  // Vector para almacenar la baraja de cartas
    Carta jugador1[TAM2]={};  // Vector para las cartas del jugador 1
    Carta jugador2[TAM2]={};  // Vector para las cartas del jugador 2
    char vNombre1[TAM];
    char vNombre2[TAM];
    bool BloqueoJ1[TAM2]={};
    bool BloqueoJ2[TAM2]={};

    cout << " " << " +"<< "=====================+" << endl;
    cout << " " << " |"<<"       CLUTCH.       |"<<endl;
    cout << " " << " +"<< "=====================+" << endl;
    cout << " " << " |                     |"<< endl;
    cout << " " << " |"<< " 1 - JUGAR"; cout << "           |" << endl;
    cout << " " << " |                     |"<< endl;
    cout << " " << " |"<< " 2 - ESTADISTICAS"; cout << "    |" << endl;
    cout << " " << " |                     |"<< endl;
    cout << " " << " |"<< " 3 - CREDITOS"; cout << "        |" << endl;
    cout << " " << " |                     |"<< endl;
    cout << " " << " +"<< "=====================+" << endl;
    cout << " " << " |"<<" 0 - SALIR           |"<<endl;
    cout << " " << " +"<< "=====================+" << endl;
    cout << endl;
    cout << " >> "; cin >> opcion;
    cout << endl;

    switch (opcion) {

        case 1:
            system("cls");
            cout << "=====================" << endl;
            cout << "CLUTCH" << endl;
            cout << "=====================" << endl;
            cout << endl;
            cout << "ANTES DE COMENZAR DEBEN REGISTRAR SUS NOMBRES." << endl;
            cout << endl;
            nombres(vNombre1, vNombre2, TAM);
            cout << "?CONFIRMAR NOMBRES? (S/N)" << " "; cin >> c;
            cout << endl;

            if(c=='N' || c=='n'){

                return main();

            }
            else{
                if(c=='s' || c=='S'){

                    system("cls");
                    for(int i=0; i<5; i++){
                        vPuntuacion[i] = 0;

                    }
                    cartasMalUbicadas=0;
                    totalPuntos=0;

                    // Inicializar la baraja con 20 cartas
                    inicializarBaraja(baraja);
                    // Repartir 5 cartas a cada jugador
                    repartirCartas(baraja, jugador1, jugador2, TAM);

                    // Verificar si alguno de los jugadores tiene 10-J-Q-K-A de manera ordenada
                    if (jugador1[0].valor == "10" && jugador1[1].valor == "J" && jugador1[2].valor == "Q" && jugador1[3].valor == "K" && jugador1[4].valor == "A") {
                        cout << "Las cartas del Jugador 1 est�n ordenadas. Mezclando y repartiendo nuevamente." << endl;
                        inicializarBaraja(baraja);
                        repartirCartas(baraja, jugador1, jugador2, TAM);
                    }
                    else if (jugador2[0].valor == "10" && jugador2[1].valor == "J" && jugador2[2].valor == "Q" && jugador2[3].valor == "K" && jugador2[4].valor == "A") {
                        cout << "Las cartas del Jugador 2 est�n ordenadas. Mezclando y repartiendo nuevamente." << endl;
                        inicializarBaraja(baraja);
                        repartirCartas(baraja, jugador1, jugador2, TAM);
                    }

                    // Mostrar las cartas de cada jugador por separado
                    mostrarCartas(jugador1, TAM2, vNombre1);
                    mostrarCartas(jugador2, TAM2, vNombre2);

                }

            }
            if(determinarJugadorQueComienza(jugador1, jugador2, turno) != "EMPATE"){
                cout << "=======================" << endl;
                cout << "COMIENZA EL " << determinarJugadorQueComienza(jugador1, jugador2,turno) << endl;
                cout << "=======================" << endl;
            }
            else{
                cout << "=======================" << endl;
                cout << " " << determinarJugadorQueComienza(jugador1, jugador2,turno) << "!!" << endl;
                cout << "=======================" << endl;
                cout << "COMENZADO ALEATORIAMENTE..." << endl;
                cout << "=======================" << endl;
                cout << "COMIENZA EL " << comienzoAleaotorio(turno) << endl;
                cout << "=======================" << endl;

            }

            while(partida){

                dado = TirarDado();
                cout << "=======================" << endl;
                cout << "LANZAMIENTO DE DADO...: #" << dado << endl;
                cout << "=======================" << endl;

                switch(dado){
                    case 1:

                        cout << endl;
                        cout << "ELIJE UNA CARTA PARA INTERCAMBIAR CON LA BARAJA 1-5:" << " "; cin >> ce;
                        if(turno==1){
                            funcionDado1(jugador1, baraja, ce, BloqueoJ1);
                        }
                        else{
                        funcionDado1(jugador2, baraja, ce, BloqueoJ2);
                        }
                        system("pause");

                    break;

                    case 2:

                        cout << endl;
                        cout << "ELIJE UNA CARTA DEL CORRAL CONTRARIO (1-5) Y CAMBIASELA POR UNA DE LA BARAJA" << " "; cin >> ce;
                        if(turno==1){
                            funcionDado2(jugador2,ce,baraja,BloqueoJ2);
                        }
                        else{
                            funcionDado2(jugador1,ce,baraja,BloqueoJ1);
                        }
                        system("pause");

                    break;

                    case 3:

                        cout << endl;
                        cout<<"ELEGIR UNA CARTA DEL CORRAL PROPIO (1-5) E INTERCAMBIARLA POR UNA DEL CORRAL CONTRARIO (1-5). "<<endl;
                        if(turno==1){
                            cout << endl;
                            cout << "CARTA DE TU CORRAL(1-5):" << " "; cin >> cartaElegida1; cout << endl;
                            cout << "CARTA DEL CORRAL CONTRARIO(1-5):" << " "; cin >> cartaElegida2; cout << endl;
                            funcionDado3(cartaElegida1, cartaElegida2, jugador1, jugador2, BloqueoJ2);
                            roboj2 = true;
                            if(jugador1[0].valor == "10" && jugador1[1].valor == "J" && jugador1[2].valor == "Q" && jugador1[3].valor == "K" && jugador1[4].valor == "A"){
                                vPuntuacion[1]+=10;
                            }
                        }
                        else{
                            cout << endl;
                            cout << "CARTA DE TU CORRAL(1-5):" << " "; cin >> cartaElegida1; cout << endl;
                            cout << "CARTA DEL CORRAL CONTRARIO(1-5):" << " "; cin >> cartaElegida2; cout << endl;
                            funcionDado3(cartaElegida1, cartaElegida2, jugador2, jugador1, BloqueoJ1);
                            roboj1 = true;
                            if(jugador1[0].valor == "10" && jugador1[1].valor == "J" && jugador1[2].valor == "Q" && jugador1[3].valor == "K" && jugador1[4].valor == "A"){
                                vPuntuacion[1]+=10;
                            }
                        }
                        system("pause");

                    break;

                    case 4:

                        cout << endl;
                        cout << "ELIGE DOS CARTAS DE TU MAZO (1-5) Y SE INTERCAMBIAN ENTRE SI."; cin >> ce; cout << " "; cin >> ce1;
                        if(turno==1){
                            funcionDado4(jugador1, ce, ce1, BloqueoJ1);
                        }
                        else{
                            funcionDado4(jugador2, ce, ce1, BloqueoJ2);
                        }
                        system("pause");

                    break;

                    case 5:

                        cout << endl;
                        cout << "ELIJE UNA CARTA DE TU CORRAL PARA BLOQUEARLA:" << " "; cin >> ce;
                        if(turno==1){
                            funcionDado5(jugador1, ce, BloqueoJ1);
                        }
                        else{
                            funcionDado5(jugador2, ce, BloqueoJ2);
                        }
                        system("pause");

                    break;

                    case 6:

                        cout << endl;
                        ///DADO 6.
                        ///---------------------------------------------------------------------------------------.

                        cout <<  "ELIGE CUALQUIER ACCION DEL DADO (1-5) " << endl;
                        cout <<  "1 Elegir una carta de su propio corral (1-5) y robar una carta del mazo. " << endl;
                        cout <<  "2 Elegir una carta del corral del contrario (1-5) y robar una carta del mazo." << endl;
                        cout <<  "3 Elegir una carta del corral propio (1-5) e intercambiarla por una carta del corral del contrario (1-5)" << endl;
                        cout <<  "4 Se eligen dos cartas del propio corral (1-5) y se intercambian entre s�." << endl;
                        cout <<  "5 Bloquear una carta del corral " << endl;
                        cout <<  "6 Pasar de turno" << endl;
                        cin >> ce;
                        funcionDado6(ce, turno, jugador1, jugador2, baraja, BloqueoJ1, BloqueoJ2);

                        ///---------------------------------------------------------------------------------------.
                        ///DADO 6.

                    break;

                }

                if(turno == 1){
                    turno=2;
                }
                else{
                    turno=1;
                }

                system("cls");
                cout << endl;
                cout << "=======================" << endl;
                cout<<"TURNO DEL JUGADOR "<<turno<<endl;
                cout << "=======================" << endl;
                mostrarCartas(jugador1, TAM2, vNombre1);
                mostrarCartas(jugador2, TAM2, vNombre2);


                if (jugador1[0].valor == "10" && jugador1[1].valor == "J" && jugador1[2].valor == "Q" && jugador1[3].valor == "K" && jugador1[4].valor == "A") {
                    cout << " + EL GANADOR ES " << vNombre1 << " FELICITACIONES!!! +" << endl;
                    vPuntuacion[0]+=15;
                    partida = false;

                    if(jugador2[0].valor != "10"){
                        vPuntuacion[2]+=5;
                        cartasMalUbicadas++;
                    }
                    if(jugador2[1].valor != "J"){
                        vPuntuacion[2]+=5;
                        cartasMalUbicadas++;
                    }
                    if(jugador2[2].valor != "Q"){
                        vPuntuacion[2]+=5;
                        cartasMalUbicadas++;
                    }
                    if(jugador2[3].valor != "K"){
                        vPuntuacion[2]+=5;
                        cartasMalUbicadas++;
                    }
                    if(jugador2[4].valor != "A"){
                        vPuntuacion[2]+=5;
                        cartasMalUbicadas++;
                    }


                    if(SaltoTurnoJ16 == 0){
                        vPuntuacion[3]+=10;
                    }

                    ganador = vNombre1;

                    cout << endl;
                    cout << "+ VOLVER AL MENU (M) SALIR (S) +" << " "; cin >> c;
                    cout << endl;
                    if(c=='M' || c=='m'){

                        return main();

                    }
                    else{
                        if(c=='S' || c=='s'){

                            system("pause");

                        }
                    }

                }
                else{
                    if(jugador2[0].valor == "10" && jugador2[1].valor == "J" && jugador2[2].valor == "Q" && jugador2[3].valor == "K" && jugador2[4].valor == "A"){
                        cout << "EL GANADOR ES " << vNombre2 << " FELICITACIONES" << endl;
                        vPuntuacion[0]+=15;
                        partida = false;

                        if(jugador1[0].valor != "10"){
                            vPuntuacion[2]+=5;
                            cartasMalUbicadas++;
                        }
                        if(jugador1[1].valor != "J"){
                            vPuntuacion[2]+=5;
                            cartasMalUbicadas++;
                        }
                        if(jugador1[2].valor != "Q"){
                            vPuntuacion[2]+=5;
                            cartasMalUbicadas++;
                        }
                        if(jugador1[3].valor != "K"){
                            vPuntuacion[2]+=5;
                            cartasMalUbicadas++;
                        }
                        if(jugador1[4].valor != "A"){
                            vPuntuacion[2]+=5;
                            cartasMalUbicadas++;
                        }

                        if(SaltoTurnoJ26 == 0){
                            vPuntuacion[3]+=10;
                        }

                        ganador = vNombre2;

                        cout << endl;
                        cout << "+ VOLVER AL MENU (M) SALIR (S) +" << " "; cin >> c;
                        cout << endl;
                        if(c=='M' || c=='m'){

                            return main();

                        }
                        else{
                            if(c=='S' || c=='s'){

                                system("pause");

                            }
                        }

                    }
                }

            }

        break;

        case 2:

            system("cls");

            for(int i=0; i<5; i++){

                totalPuntos += vPuntuacion[i];

            }

            if(maximaPuntuacion == 0){

                maximaPuntuacion = totalPuntos;
                maximoGanador = ganador;

                cout << "CLUTCH" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << "HITO" << endl;
                cout << maximoGanador << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << "GANAR LA PARTIDA                                                      " << vPuntuacion[0] << endl;
                cout << endl;
                cout << "ROBO LA ULTIMA CARTA AL JUGADOR RIVAL                                 " << vPuntuacion[1] << endl;
                cout << endl;
                cout << "CARTAS MAL UBUCADAS DEL RIVAL X" << cartasMalUbicadas << "                                      " << vPuntuacion[2] << endl;
                cout << endl;
                cout << "SIN PASAR DE TURNO                                                    " << vPuntuacion[3] << endl;
                cout << endl;
                cout << "SIN HABER SUFRIDO UN ROBO DEL RIVAL                                   " << vPuntuacion[4] << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << "TOTAL " << maximaPuntuacion << "PTS" <<endl;
                cout << endl;
                cout << "GANADOR: "<< maximoGanador << " con " << maximaPuntuacion <<" puntos de victoria."<< endl;
                cout << endl;
                cout << "PRESIONE 0 PARA CONTINUAR." << endl;

            }
            else{
                if(totalPuntos >= maximaPuntuacion){

                    maximaPuntuacion = totalPuntos;
                    maximoGanador = ganador;

                    cout << "CLUTCH" << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "HITO" << endl;
                    cout << maximoGanador << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "GANAR LA PARTIDA                                                      " << vPuntuacion[0] << endl;
                    cout << endl;
                    cout << "ROBO LA ULTIMA CARTA AL JUGADOR RIVAL                                 " << vPuntuacion[1] << endl;
                    cout << endl;
                    cout << "CARTAS MAL UBUCADAS DEL RIVAL X" << cartasMalUbicadas << "                                      " << vPuntuacion[2] << endl;
                    cout << endl;
                    cout << "SIN PASAR DE TURNO                                                    " << vPuntuacion[3] << endl;
                    cout << endl;
                    cout << "SIN HABER SUFRIDO UN ROBO DEL RIVAL                                   " << vPuntuacion[4] << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "TOTAL " << maximaPuntuacion << "PTS" <<endl;
                    cout << endl;
                    cout << "GANADOR: "<< maximoGanador << " con " << maximaPuntuacion <<" puntos de victoria."<< endl;
                    cout << endl;
                    cout << "PRESIONE 0 PARA CONTINUAR." << endl;

                }
                else{
                    cout << "CLUTCH" << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "HITO" << endl;
                    cout << maximoGanador << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "GANAR LA PARTIDA                                                      " << vPuntuacion[0] << endl;
                    cout << endl;
                    cout << "ROBO LA ULTIMA CARTA AL JUGADOR RIVAL                                 " << vPuntuacion[1] << endl;
                    cout << endl;
                    cout << "CARTAS MAL UBUCADAS DEL RIVAL X" << cartasMalUbicadas << "                                      " << vPuntuacion[2] << endl;
                    cout << endl;
                    cout << "SIN PASAR DE TURNO                                                    " << vPuntuacion[3] << endl;
                    cout << endl;
                    cout << "SIN HABER SUFRIDO UN ROBO DEL RIVAL                                   " << vPuntuacion[4] << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "TOTAL " << maximaPuntuacion << "PTS" <<endl;
                    cout << endl;
                    cout << "GANADOR: "<< maximoGanador << " con " << maximaPuntuacion <<" puntos de victoria."<< endl;
                    cout << endl;
                    cout << "PRESIONE 0 PARA CONTINUAR." << endl;

                }
            }
            system("pause");
            return main();

        break;

        case 3:

            system("cls");
            creditos();
            cout << endl;
            cout << "+ VOLVER AL MENU (M) SALIR (S) +" << " "; cin >> c;
            cout << endl;
            if(c=='M' || c=='m'){

                return main();

            }
            else{
                if(c=='S' || c=='s'){

                    system("pause");

                }
            }

        break;

        case 0:

            system("pause");

        break;

    }
    return 0;
}
