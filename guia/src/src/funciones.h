#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <QtGui>
#include <string>
#include <iostream>
#include <fstream>
 #include <QTranslator>
#include <vector>
#include "wifiStruct.h"

using namespace std;


void splitstring(string str, string separator, string &first, string &second); //will split a string into 2

void limpiar(string str, string separator, string &resultado); //will split a string and you get the second item

void insertarEnLista(vector<WIFI> &lista, WIFI &scanned,  int escaneos);

void crearPDF(vector<WIFI> &lista);

void crearWeb(vector<WIFI> &lista);

void compruebaLista(vector<WIFI> &lista, int escaneos);

void vaciarStruct(WIFI &scanned);

void dibujarGraficoChannel(vector<WIFI> &lista);

void dibujarGraficoSenyal(vector<WIFI> &lista);

void gnuPlot();


#endif // FUNCIONES_H
