#include <QtGui>
#include <QListWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QShortcut>
#include <QGridLayout>
#include <QTreeWidgetItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>


#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i=0;

    ui->inicioBtn->setText(tr("start"));
    ui->salirBtn->setText(tr("exit"));
    ui->informePdfBtn->setText(tr("PDF report"));
    ui->informeHtmlBtn->setText(tr("HTML report"));
    ui->accessPointBtn->setText(tr("A.P. Timecourse"));
    ui->channelBtn->setText(tr("channel usage"));
    ui->resetBtn->setText(tr("reset"));
    ui->barraProg->setTextVisible(false);
    ui->barraProg->setValue(i);


    //LISTA DE WIFIS

    model = new QStandardItemModel;
    model->insertRows(0, 1);
    model->insertColumns(0, 1);

    QModelIndex index = model->index(0, 0);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Placement ITIS"));
    model->setData(index,QVariant(tr("Wifi Scanner Bye Jose Chorva")));

    ItemDelegate *delegate = new ItemDelegate();
    ui->treeView->setModel(model);
    ui->treeView->setItemDelegate(delegate);




    //GRAFICOS
    imagen = new QLabel();
    imagen->setPixmap(QPixmap("/tmp/wifiscan/wifiscan.png"));
    ui->imageLayout->addWidget(imagen);
    ui->imageLayout->sizeHint();


    //Acciones
    connect(ui->salirBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->inicioBtn, SIGNAL(clicked()), this, SLOT(startOrStopThread()));
    connect(ui->resetBtn, SIGNAL(clicked()), &hilo, SLOT(resetVector()));
    connect(ui->informeHtmlBtn, SIGNAL(clicked()), this, SLOT(HTMLReport()));
    connect(ui->informePdfBtn, SIGNAL(clicked()), this, SLOT(PDFReport()));

    (void) new QShortcut(Qt::CTRL + Qt::Key_Q, this, SLOT(close()));
    connect(&hilo, SIGNAL(escaneoListo()), this, SLOT(escaneoCompletado()));
    connect(&hilo, SIGNAL(errorCard()), this, SLOT(errorWifiCard()));


    connect(ui->accessPointBtn, SIGNAL(clicked()), this, SLOT(actualizaGrafico()));
    connect(ui->channelBtn, SIGNAL(clicked()), this, SLOT(actualizaGrafico2()));



    //titulo del programa
    setWindowTitle(tr("Wifi Scanner"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startOrStopThread()
{
    if (hilo.isRunning() )
    {
        hilo.stop();
        ui->inicioBtn->setText(tr("Start scan"));
    }
    else
    {
        hilo.start();
        ui->inicioBtn->setText(tr("Stop scan"));
    }
}

void MainWindow::actualizaGrafico()
{
    imagen->setPixmap(QPixmap("/tmp/wifiscan/accesspoint.png"));
    imagen->adjustSize();
    ui->imageLayout->addWidget(imagen);
    ui->imageLayout->sizeHint();
}

void MainWindow::actualizaGrafico2()
{
    imagen->setPixmap(QPixmap("/tmp/wifiscan/channel.png"));
    imagen->adjustSize();
    ui->imageLayout->addWidget(imagen);
    ui->imageLayout->sizeHint();


}

void MainWindow::actualizaVector()
{
    lista.clear();
    lista = hilo.getLista();
}

void MainWindow::barraProgreso()
{
    i=hilo.getEscaneo();
    i=i%10 *10;
    ui->barraProg->setValue(i);
}


void MainWindow::actualizaLista()
{

    model = new QStandardItemModel;
    model->insertRows(0, lista.size());
    model->insertColumns(0, 7);


    for (unsigned int row = 0; row < lista.size(); row++)
    {
        QModelIndex index = model->index(row, 7);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("BSSID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ESSID"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Channel"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Signal"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Quality"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("key"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Mode"));
        model->insertRow(0);
        model->setData(model->index(0,0), QString::fromStdString(lista[row].BSSID));
        model->setData(model->index(0,1), QString::fromStdString(lista[row].ESSID));
        model->setData(model->index(0,2), QString::fromStdString(lista[row].Channel));
        model->setData(model->index(0,3), lista[row].senyal[lista[row].senyal.size()-1]);
       model->setData(model->index(0,4), QString::fromStdString(lista[row].Quality));
        model->setData(model->index(0,5), QString::fromStdString(lista[row].key));
        model->setData(model->index(0,6), QString::fromStdString(lista[row].mode));
    }

    ItemDelegate *delegate = new ItemDelegate();
    ui->treeView->setModel(model);
    ui->treeView->setItemDelegate(delegate);
    ui->treeView->setColumnWidth(0, 200);
    ui->treeView->setColumnWidth(1, 200);
    ui->treeView->setColumnWidth(2, 70);
    ui->treeView->setColumnWidth(3, 70);
    ui->treeView->setColumnWidth(4, 100);
    ui->treeView->setColumnWidth(5, 70);
    ui->treeView->setColumnWidth(6, 50);
}

void MainWindow::HTMLReport()
{
    crearWeb(lista);
}
void MainWindow::PDFReport()
{
    crearPDF(lista);
}

void MainWindow::errorWifiCard()
{
    startOrStopThread();
    QMessageBox::warning(this,tr("ERROR"),tr("wlan0     Failed to read scan data : Network is down"));
}



void MainWindow::escaneoCompletado()
{
    actualizaVector();
    actualizaLista();
    barraProgreso();

    //llamar a gnuplot
    dibujarGraficoChannel(lista);
    dibujarGraficoSenyal(lista);
    gnuPlot();

    if(ui->channelBtn->isChecked())
    {
        imagen->setPixmap(QPixmap("/tmp/wifiscan/channel.png"));
    }
    else
    {
        imagen->setPixmap(QPixmap("/tmp/wifiscan/accesspoint.png"));
    }
    imagen->adjustSize();
    ui->imageLayout->addWidget(imagen);
    ui->imageLayout->sizeHint();
}
