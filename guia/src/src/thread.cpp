#include "thread.h"
#include <QMessageBox>
#include <QtCore>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>

using namespace std;


Thread::Thread()
{
    stopped = false;
    escaneos = 1;
}

void Thread::lee()
{
    int foo=0;
    //si no existe el directorio wifiscan, crearlo???
    foo=system("iwlist wlan0 scan > /tmp/wifiscan/lista.txt");
    sleep(2);
}

void Thread::scan()
{

    string str, vacio;

    string noWifi("No");
    string failedWifi("Failed");
    string okWifi("completed");
    string addressExist("Address");
    string channelExists("Channel:");
    string frequencyExists("Frequency");
    string qualityExits("Quality");
    string encryptionExists("Encryption");
    string essidExists("ESSID");
    string modeExists("Mode");
    string wpaExists("802.11i/WPA2");
    string tsfExists("tsf=");
    string beaconExists("beacon");

    size_t found;
    size_t exit;

    int senyal=0;
    bool finish = false;
    bool cifrado = false;

    WIFI scanned;
    int scans = escaneos;
    fstream file_op;
    bool structCompleto= false;

    file_op.open("/tmp/wifiscan/lista.txt");

    //Ha encontrado wifi?
    getline(file_op, str,'\n');
    found=str.find(noWifi);
    if(found!=string::npos)
    {
        cout << "wlan0  no scan results" <<endl;
        for(unsigned int i= 0; i< lista.size(); i++)
            lista[i].senyal.push_back(0);

        emit errorScan();
    }

    //Tengo la wifi conectada?
    found=str.find(failedWifi);
    if(found!=string::npos)
    {
        cout << "wlan0     Failed to read scan data : Network is down" << endl;
        emit errorCard();
    }

    //Esta todo Ok? pues adelante

    found=str.find(okWifi);
    if(found!=string::npos)
    {

        while(!file_op.eof())
        {

            getline(file_op, str,'\n');
            found=scanned.key.find("WEP");
            if(found!=string::npos)
            {
                found=str.find(wpaExists);
                if(found!=string::npos)
                {
                    scanned.key="WPA";
                    structCompleto = true;
                }
            }

            found=str.find(beaconExists);
            if(found!=string::npos)
            {
                splitstring(str, "L", vacio, str);
                splitstring(str, ":", vacio, str);
                splitstring(str, " ", vacio, str);
                splitstring(str, "m", scanned.beacon, vacio);
                //si no hay clave, ha finalizado;
                found=scanned.key.find("off");
                if(found!=string::npos)
                {
                    structCompleto = true;
                }
            }   

            found=str.find(tsfExists);
            if(found!=string::npos)
            {
                splitstring(str, "=", vacio, str);
                scanned.tsf=str;
            }


            found=str.find(modeExists);
            if(found!=string::npos)
            {
                splitstring(str, ":", vacio, str);
                scanned.mode=str;
            }


            found=str.find(essidExists);
            if(found!=string::npos)
            {
                splitstring(str, "\"", vacio, str);
                splitstring(str, "\"", scanned.ESSID, vacio);
            }



            found=str.find(encryptionExists);
            if(found!=string::npos)
            {
                splitstring(str, ":", vacio, str);
                found=str.find("on");
                if(found!=string::npos)
                {
                    scanned.key = "WEP";
                }
                else
                    scanned.key = str;
            }


           found=str.find(frequencyExists);
            if(found!=string::npos)
            {
                splitstring(str, ":", vacio, str);
                splitstring(str, " ", str, vacio);
                scanned.frequency = str; //frequency
            }


            found=str.find(channelExists);
            if(found!=string::npos)
            {
                splitstring(str, ":", vacio, str);
                scanned.Channel = str; //Channel
            }


            found=str.find(qualityExits);
            if(found!=string::npos)
            {
                splitstring(str, "=", vacio, str);
                splitstring(str, " ", scanned.Quality, vacio);
                splitstring(str, "-", vacio, str);
                splitstring(str, " ", scanned.signal, vacio);
            }


            found = str.find(addressExist);
            if(found != string::npos)
            {
                if(!structCompleto && scanned.BSSID != "")
                {
                    insertarEnLista(lista, scanned, scans);
                    structCompleto = false;
                }
                    
                splitstring(str, ":", vacio, str);
                splitstring(str, " ", vacio, str);
                scanned.BSSID = str; //BSSID

            }
            if(structCompleto)
            {
                insertarEnLista(lista, scanned, scans);
                structCompleto = false;
            }

        }
    }

    else
    {
        emit errorRead();
    }

    file_op.close();

//comprobar que todas las lecturas de las wifis del vector (arbol?) tengan la misma cantidad de elementos
   /////////////////////////////////////////////////////////////////////////
    compruebaLista(lista, escaneos);


    if(lista.size()>0)
    {
        emit escaneoListo();
    }

cout << "escaneos = " << escaneos<<endl;
}

vector<WIFI> Thread::getLista()
{
    return lista;
}

void Thread::resetVector()
{
    lista.clear();
    escaneos = 1;
}

void Thread::run()
{
    while(!stopped)
    {
        lee();
        sleep(2);
        scan();
        escaneos++;
    }
    stopped = false;
}

int Thread::getEscaneo()
{
    return escaneos;
}

void Thread::stop()
{
    stopped = true;
}


