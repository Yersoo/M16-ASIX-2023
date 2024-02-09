#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>



using namespace std;
int Corazones[13];
int Picas[13];
int Treboles[13];
int Diamantes[13];
int jugador = 0;
int croupier = 0;



int calcularValorCarta(int carta, string palo) {
    int valorCarta = 0;
    //valoramos el AS
    if (carta == 0) {
        //Que valor le quieres dar. 1 u 11
        bool valorCarrecto = false;
        while(!valorCarrecto){
        cout << "La carta es un AS de " << palo << "\n";
        cout << "Quieres que sea 1 o 11? " << "\n";
        cin >> valorCarta;
        if (valorCarta != 11 && valorCarta != 1) {
            cout << "El valor es erroneo." << "\n";
        }
        else {
            valorCarrecto = true;
        }
        }
    }
    //Valoramos si la carta está entre el 2 y el 10
    else if (carta > 0 && carta < 10) {
        valorCarta = carta + 1;
        cout << "La carta es un " << valorCarta << " de " << palo << "\n";
    }
    //Valoramos si la carta es una figura
    else if (carta >= 10) {
        valorCarta = 10;
        if (carta == 10) {
            cout << "La carta es una Sota de " << palo << "\n";
        }
        else if (carta == 11) {
            cout << "La carta es un Caballo de " << palo << "\n";
        }
        else if (carta == 12) {
            cout << "La carta es una Rey de " << palo << "\n";
        }
    }
    return valorCarta;
}



int entregarCarta() {
    //Bucle hasta que encuentre la carta

    bool cartaEntregada = false;

    int valorCarta = 0;

    int valorCartaFinal = 0;

    while (cartaEntregada == false) {

        //Elige el palo
        const int numPalos = 4;

        const int numCartasPorPalo = 13; //al declararlo como constante siempre va haber este numero de cartas y igual con los palos, nunca varian.

        int paloElegido = std::rand() % numPalos;

        int cartaElegida = std::rand() % numCartasPorPalo;

        switch (paloElegido) {
        case 0:
            if (Corazones[cartaElegida] > 0) {
                valorCarta = Corazones[cartaElegida];
                cartaEntregada = true;
                Corazones[cartaElegida] = 0;
                valorCartaFinal = calcularValorCarta(cartaElegida, "Corazones");
            }
            break;
        case 1:
            if (Picas[cartaElegida] > 0) {
                valorCarta = Picas[cartaElegida];
                cartaEntregada = true;
                Picas[cartaElegida] = 0;
                valorCartaFinal = calcularValorCarta(cartaElegida, "Picas");
            }
            break;
        case 2:
            if (Treboles[cartaElegida] > 0) {
                valorCarta = Treboles[cartaElegida];
                cartaEntregada = true;
                Treboles[cartaElegida] = 0;
                valorCartaFinal = calcularValorCarta(cartaElegida, "Treboles");
            }
            break;
        case 3:
            if (Diamantes[cartaElegida] > 0) {
                valorCarta = Diamantes[cartaElegida];
                cartaEntregada = true;
                Diamantes[cartaElegida] = 0;
                valorCartaFinal = calcularValorCarta(cartaElegida, "Diamantes");
            }
            break;
        }

    }
    return valorCartaFinal;
}



int main() {
    std::srand(std::time(0));


    //Inicializamos las arrays
    for (int i = 0; i < 13; ++i) {
        Corazones[i] = i;
    }



    for (int i = 0; i < 13; ++i) {
        Picas[i] = i;
    }



    for (int i = 0; i < 13; ++i) {
        Treboles[i] = i;
    }



    for (int i = 0; i < 13; ++i) {
        Diamantes[i] = i;
    }

    int respuesta = 0;

    jugador = jugador + entregarCarta();
    cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    jugador = jugador + entregarCarta();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\n";
    cout << "la puntuacion del jugador es :" << jugador << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\n";

    
    croupier = croupier + entregarCarta();
    cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    cout << "la puntuacion del croupier es :" << croupier << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (respuesta != 2 && jugador < 21)
    {
        cout << "Quiere otra carta?:\n";
        cout << "1.- SI\n";
        cout << "2.- NO\n";

        cin >> respuesta;

        if (respuesta == 1)
        {
            jugador = jugador + entregarCarta();
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "la puntuacion del jugador es :" << jugador << "\n";
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "la puntuacion del croupier es :" << croupier << "\n";
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else if (respuesta == 2)
        {

        }
        else
        {
            cout << "ERROR \n";
        }
    }
    if (jugador > 21)
    {
        cout << "El jugador pierde, la banca GANA";
    }
    else
    {
        while (croupier <= 21 && croupier <= jugador)
        {
            croupier = croupier + entregarCarta();
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

            cout << "la puntuacion del jugador es :" << jugador << "\n";
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "la puntuacion del croupier es :" << croupier << "\n";
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
         if (jugador > croupier && jugador <= 21)
        {
            cout << "El jugador gana, la banca PIERDE";
        }
        else if (croupier > 21)
        {
            cout << "El jugador gana, la banca PIERDE";
        }
        else
        {
            cout << "El jugador pierde, la banca GANA";
        }
    }

    return 0;
}
