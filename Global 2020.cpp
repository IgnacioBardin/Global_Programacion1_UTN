#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

void leerDatos();

int main(int argc, char *argv[]) {

    leerDatos();

    return 0;
}

void leerDatos() {

    ifstream leerDatos;
    leerDatos.open("datos1.txt");

    if (!leerDatos) {
        cout << "ERROR. NO SE PUDO ENCONTRAR EL ARCHIVO.";
        system("pause");
        exit(-1);
    }

    double x = 0, y = 0, xMayor = -10000, xMenor = 10000, yMayor = -10000, yMenor = 10000;
    int contador=0;
    int antenasParaAgregar=0;

    double anchoCelda = 0, altoCelda = 0;

    vector <double> coorX;
    vector <double> coorY;

    leerDatos >> x;


    antenasParaAgregar = x;
    if(x >= 5 && x <= 15) {
        cout << "La cantidad de antenas es: " << antenasParaAgregar << endl;

        do {
            leerDatos >> x >> y;

            if (x == 0 && y == 0) {
                break;
            } else {
                coorX.push_back(x);
                coorY.push_back(y);
            }

            if(xMenor > x) {
                xMenor=x;
            }

            if(xMayor < x) {
                xMayor = x;
            }

            if(yMenor > y) {
                yMenor = y;
            }

            if(yMayor < y) {
                yMayor = y;
            }
            cout << contador << ": " << coorX[contador] << " // " << coorY[contador] << endl;
            contador++;

        } while(!leerDatos.eof());


        anchoCelda = (xMayor - xMenor) / 100;
        altoCelda = (yMayor - yMenor) / 100;

        cout << endl << "X menor: " << xMenor << endl << "X mayor: " << xMayor << endl << "Y menor: " << yMenor << endl << "Y mayor: " << yMayor << endl;


        cout << endl << "El ancho de celda es: " << anchoCelda << endl << endl;


        double xCeldaElegida, yCeldaElegida, distancia, minimaDistancia = 10000, xCelda, yCelda, xDistancia, yDistancia, maximaMinimaDistancia = -1;
        int antenasExistentes = contador;
        int A, B;

        for(int iterador = 0; iterador < antenasParaAgregar; iterador++) {
            maximaMinimaDistancia = -1;
            for(int columnaCelda = 0; columnaCelda < 100; columnaCelda++) {
                for(int filaCelda = 0; filaCelda < 100; filaCelda++) {
                    xCelda = xMenor + (columnaCelda * anchoCelda + (anchoCelda/2));
                    yCelda = yMayor - (filaCelda * altoCelda) - (altoCelda/2);
                    minimaDistancia = 10000;
                    for(int nroAntena = 0; nroAntena < antenasExistentes; nroAntena++) {
                        xDistancia = abs(xCelda - coorX[nroAntena]);
                        yDistancia = abs(yCelda - coorY[nroAntena]);
                        distancia = sqrt( pow(xDistancia, 2) + pow(yDistancia, 2));

                        if(distancia < minimaDistancia) {
                            minimaDistancia = distancia;
                        }


                    }
                    if(minimaDistancia > maximaMinimaDistancia) {
                        maximaMinimaDistancia = minimaDistancia;
                        xCeldaElegida = xCelda;
                        yCeldaElegida = yCelda;
                        A = filaCelda;
                        B = columnaCelda;
                    }

                }
            }

            antenasExistentes++;
            coorX.push_back(xCeldaElegida);
            coorY.push_back(yCeldaElegida);

            cout << "La celda elegida es: " << xCeldaElegida << " " << yCeldaElegida << " La maxima minima distancia es: " << maximaMinimaDistancia << " Fila: " << A << " Columna: " << B << endl;
        }

    } else {
        cout << "ERROR. NUMERO INVALIDO" << endl;
    }





    leerDatos.close();


}
