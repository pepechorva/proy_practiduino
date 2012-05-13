#include "funciones.h"
using namespace std;
using namespace Qt;

void crearPDF(vector<WIFI> &lista)
{
    int foo;
    fstream arxiu;
    arxiu.open("/tmp/wifiscan/wifiscan.tex", ofstream::out| ofstream::trunc);
    arxiu << "\\documentclass[landscape, 12pt]{report}" << endl;
    arxiu << "\\usepackage[utf8x]{inputenc}" <<endl;
    arxiu << "\\usepackage[landscape]{geometry}" << endl;
    arxiu << "\\usepackage{graphicx}" <<endl;
    arxiu << "\\usepackage{ucs}" <<endl;
    arxiu << "\\begin{document}" <<endl;
    arxiu << "\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|}" <<endl;
    arxiu << "\\hline"<< endl<< "BSSID & ESSID & channel & Signal Quality & Signal & Encryption & mode \\\\" << endl;
    for(unsigned int i = 0; i < lista.size(); i++)
    {
        arxiu << "\\hline"<< endl << lista[i].BSSID <<"&  " <<  lista[i].ESSID  <<"&  " << lista[i].Channel << " & ";
        arxiu << lista[i].Quality << " & " <<lista[i].signal  << "&  " << lista[i].key << " & " << lista[i].mode <<  " \\\\ " <<endl;

    }
    arxiu << "\\hline " <<endl;
    arxiu << "\\end{tabular} \\\\" <<endl;
    arxiu << "\\includegraphics[scale=0.5]{/tmp/wifiscan/accesspoint.png}\\\\" <<endl;
    arxiu << "\\includegraphics[scale=0.5]{/tmp/wifiscan/channel.png} " <<endl;
    arxiu << "\\end{document}" <<endl;
    arxiu.close();

    foo=system("pdflatex -interaction=nonstopmode /tmp/wifiscan/wifiscan.tex ; xdg-open wifiscan.pdf");

}

void crearWeb(vector<WIFI> &lista)
{
    int foo;
    fstream arxiu;
    arxiu.open("/tmp/wifiscan/informe.html", ofstream::out| ofstream::trunc);
    arxiu << "<HTML> "<< endl;
    arxiu << "<HEAD>"<< endl;
    arxiu << "<TITLE>WifiScan, informe HTML</TITLE>"<< endl;
    arxiu << "</HEAD>"<< endl;
    arxiu << "<BODY>"<< endl;
    arxiu << "<TABLE border=1>"<< endl;
    arxiu << "<TR>"<< endl;
    arxiu << "<TD> BSSID </TD>"<< endl;
    arxiu << "<TD> ESSID </TD>"<< endl;
    arxiu << "<TD> Canal </TD>"<< endl;
    arxiu << "<TD> Senyal </TD>"<< endl;
    arxiu << "<TD> Encriptacion </TD>"<< endl;
    arxiu << "</TR>"<< endl;
    for(unsigned int i = 0; i < lista.size(); i++)
    {
        arxiu << "<TR>"<< endl;
        arxiu << "<TD>" << lista[i].BSSID << "</TD>" << endl;
        arxiu << "<TD>" << lista[i].ESSID<< "</TD>" << endl;
        arxiu << "<TD>" << lista[i].Channel<< "</TD>" << endl;
        arxiu << "<TD>" << lista[i].senyal[lista[i].senyal.size()-1] << "</TD>"<< endl;
        arxiu << "<TD>" << lista[i].key<< "</TD>" << endl;
        arxiu << "</TR>"<< endl;
    }
    arxiu << "</TABLE>"<< endl;

    arxiu << "<IMG SRC=\"/tmp/wifiscan/accesspoint.png\" WIDTH=500 HEIGHT=500 BORDER=2 VSPACE=3 HSPACE=3 ALT=\"Potencia de las senyales\">"<< endl;
    arxiu << "<IMG SRC=\"/tmp/wifiscan/channel.png\" WIDTH=500 HEIGHT=500 BORDER=2 VSPACE=3 HSPACE=3 ALT=\"Canales usados\">"<< endl;

    arxiu << "</BODY>"<< endl;
    arxiu << "</HTML>"<< endl;

    arxiu.close();

    foo = system("firefox /tmp/wifiscan/informe.html");
}




void dibujarGraficoChannel(vector<WIFI> &lista)
{
    fstream arxiu;
    arxiu.open("/tmp/wifiscan/channeluse.plt", ofstream::out| ofstream::trunc);

    vector<int> uso; //numero de vectores
    uso.assign(13,0);

    for(unsigned int i = 0; i < lista.size(); i++)
    {
        uso[atoi(lista[i].Channel.c_str())-1] ++;
    }

    for(unsigned int i = 0; i < uso.size(); i++)
    {
        arxiu << i+1 << "\t" << uso[i] <<endl;
    }

    arxiu.close();

    fstream chanFile;

    chanFile.open("/tmp/wifiscan/chanplot.pg", ofstream::out| ofstream::trunc);

    chanFile << "set terminal png" << endl<< "set xlabel \"canales\" textcolor lt 2" << endl;
    chanFile << "set xtics (\"canal 1\" 1, \"canal 2\" 2, \"canal 3\" 3, \"canal 4\" 4, \"canal 5\" 5, \\" << endl;
    chanFile << "\"canal 6\" 6, \"canal 7\" 7, \"canal 8\" 8, \"canal 9\" 9, \"canal 10\" 10, \\" << endl;
    chanFile << "\"canal 11\" 11, \"canal 12\" 12, \"canal 13\" 13)" << endl;
    chanFile << "set ytics 1" << endl;
    chanFile << "set output \"/tmp/wifiscan/channel.png\"" << endl;
    chanFile << "set boxwidth 0.9 absolute" << endl;
    chanFile << "set style fill solid border -1" << endl;
    chanFile << "set xtics rotate by 90" << endl;
    chanFile << "plot \"/tmp/wifiscan/channeluse.plt\" using 1:2 with boxes notitle" << endl;

    chanFile.close();


}

void gnuPlot()
{
    int foo;
    foo=system("gnuplot /tmp/wifiscan/chanplot.pg");
    foo=system("gnuplot /tmp/wifiscan/applot.pg");
}

void dibujarGraficoSenyal(vector<WIFI> &lista)
{
    fstream arxiu;
    arxiu.open("/tmp/wifiscan/aptime.plt", ofstream::out| ofstream::trunc);

    for(unsigned int j = 0; j < lista[0].senyal.size(); j++)
    {
        arxiu << j << "\t";
        for(unsigned int i = 0; i < lista.size(); i++)
        {
//	        cout << lista[i].senyal[j]*-1 << "\t";
		if(0 <= lista[i].senyal[j]<= 100)
		{
	            arxiu << lista[i].senyal[j] << "\t";
		}
		else
		    arxiu << 0 << "\t";

        }
        arxiu << endl;
//	cout << endl;
    }
    arxiu.close();

    fstream apPlot;
    apPlot.open("/tmp/wifiscan/applot.pg", ofstream::out| ofstream::trunc);
    apPlot << "set xtics 5" <<endl;
    apPlot << "set ytics 10" <<endl;
    apPlot << "set xrange [0:]" <<endl;
    apPlot << "set yrange [0:100]" <<endl;


    apPlot << "set terminal png" << endl << "set output \"/tmp/wifiscan/accesspoint.png\"" << endl;
    apPlot << "set format y \"\%g\%\%\"" << endl;
    apPlot << "plot \\"<<endl;
    for(unsigned int i = lista.size(); i > 1; i--)
    {
        apPlot << "\"/tmp/wifiscan/aptime.plt\" using 1:"<< i << " title \"" << lista[i-1].ESSID << "\" with lines,\\" << endl;
    }
    apPlot << "\"/tmp/wifiscan/aptime.plt\" using 1:2 title \"" << lista[0].ESSID << "\" with lines" <<endl;

    apPlot.close();
}

void splitstring(string str, string separator, string &first, string &second) //will split a string into 2
{
    size_t i = str.find(separator); //find seperator
    if(i != string::npos)
    {
        size_t y = 0;
        if(!str.empty())
        {
            first=""; second="";
            while(y != i)
            {
                first += str[y++]; //creating first string
            }
            y += separator.length(); //jumping forward separator length
            while(y != str.length())
            {
                second += str[y++]; //creating second string
            }
        }
    }
    else
    {
        first = str;
        second = ""; //if seperator is not there then second string == empty string
    }
}

void limpiar(string str, string separator, string &resultado) // basicamente es igual que la funcion split, pero solo devuelve la segunda parte de la cadena
{
    size_t i = str.find(separator); //find seperator
    if(i != string::npos)
    {
        size_t y = 0;
        if(!str.empty())
        {
            resultado="";
            y=i;
            y += separator.length(); //jumping forward separator length
            while(y != str.length())
            {
                resultado += str[y++]; //creating second string
            }
        }
    }
    else
    {
        resultado = str;
    }
}

void compruebaLista(vector<WIFI> &lista, int escaneos)
{
cout << "escaeos = " << escaneos<<endl;
    for(unsigned int i = 0; i < lista.size(); i++)
    {
    cout << lista[i].BSSID << " lista[i].senyal.size()" <<lista[i].senyal.size()<<endl;
    
        if(lista[i].senyal.size() < escaneos)
        {
        cout << "ajuste del vector"<<endl;
            for(unsigned int j =lista[i].senyal.size() ;  j  < escaneos; j++)
            {
                lista[i].senyal.push_back(0); 
            }
        }
    cout << lista[i].BSSID << " al salir del bucle: " <<lista[i].senyal.size()<<endl;
        
    }
}

void insertarEnLista(vector<WIFI> &lista, WIFI &scanned,  int escaneos)
{
    bool nuevaWifi = true;
    unsigned int i = 0;
    while (i < lista.size())
    {
        //si la wifi esta en la lista, comprobar que el vector de senyales esta actualizado
        if (lista[i].BSSID == scanned.BSSID)
        {
/*            if(lista[i].senyal.size() < escaneos){
                for(unsigned int j = 0; j< escaneos - lista[j].senyal.size()-1; j++)
                {
                    lista[i].senyal.push_back(0);
                }
            }//*/
            lista[i].senyal.push_back(atoi(scanned.signal.c_str()));
            lista[i].signal = scanned.signal;
            vaciarStruct(scanned);
            nuevaWifi = false;
        }
        i++;
    }
    //insercion de nueva wifi en el vector
    if (nuevaWifi)
    {
        //escaneos determina cuantas mediciones anteriores se han realizado
        if(escaneos > 0)
        {
            scanned.senyal.assign(escaneos-1, 0);
            scanned.senyal.push_back(atoi(scanned.signal.c_str()));
        }
        else
        {
            scanned.senyal.push_back(atoi(scanned.signal.c_str()));
        }
        lista.push_back(scanned);
        vaciarStruct(scanned);
    }
}

void vaciarStruct(WIFI &scanned)
{
       scanned. BSSID="";
       scanned.Channel="";
       scanned.frequency="";
       scanned.Quality="";
       scanned.signal="";
       scanned.key="";
       scanned.ESSID="";
       scanned.mode="";
       scanned.beacon="";
       scanned.tsf="";
       scanned.senyal.clear();
}

