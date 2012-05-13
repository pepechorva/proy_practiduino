#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QDialog>
#include <QMainWindow>
#include <QtGui>
#include <vector>
#include <string>
 #include <QTranslator>
#include <QThread>
#include "wifiStruct.h"
#include "thread.h"
#include "funciones.h"
#include "itemDelegate.h"

using namespace std;
namespace Ui
{
    class MainWindow;
}


class QListWidget;
class QTreeWidget;
class QThread;


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startOrStopThread();
    void escaneoCompletado();
    void HTMLReport();
    void PDFReport();
    void errorWifiCard();
    void actualizaGrafico();
    void actualizaGrafico2();
 
signals:
    void actualizado();

private:
    Ui::MainWindow *ui;
   void barraProgreso();
    void actualizaVector();
    void actualizaLista();

    vector<WIFI> lista;
    Thread hilo;
    QLabel *imagen;
    QStringList stringList;
    QStandardItemModel *model;
    int i;
};

#endif // MAINWINDOW_H




