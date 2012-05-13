#ifndef THREAD_H
#define THREAD_H

#include <QApplication>
#include <QThread>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
 #include <QTranslator>
#include <QtGui>
#include "wifiStruct.h"
#include "funciones.h"

using namespace std;

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread();
    vector<WIFI> getLista();
    void stop();
    void scan();
    void lee();
    int getEscaneo();

public slots:
    void resetVector();

signals:
    void escaneoListo();
    void errorRead();
    void errorCard();
    void errorScan();

protected:
    void  run();

private:
    void actualizaScan();
    volatile bool stopped;
    vector<WIFI> lista;
    int escaneos;

};

#endif // THREAD_H
