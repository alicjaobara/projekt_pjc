#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    timer = new QTimer(this);
    timer->setInterval(100);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(symupdate()));

    sym = new CSymulacja();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete sym;
    delete timer;
}

void MainWindow::on_pushButton_clicked()
{
    //start
    timer->start();
    sym->start();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->addItem(sym->getgwyspa());
    for(int i=0; i<sym->getwyspa()->getGO().size(); i++)
        scene->addItem(sym->getwyspa()->getGO().at(i));
}

void MainWindow::symupdate()
{
    //update
    sym->update();

    const int limit = 600;
    if (sym->getpopulacja().at(6)<=limit)
    {
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
        scene->addItem(sym->getgwyspa());
        for(int i=0; i<sym->getwyspa()->getGO().size(); i++)
            scene->addItem(sym->getwyspa()->getGO().at(i));

        ui->graphicsView->update();

        QString text = QString::number(sym->getpopulacja().at(0));
        ui->textWilk->setText(text);
        text = QString::number(sym->getpopulacja().at(1));
        ui->textOwca->setText(text);
        text = QString::number(sym->getpopulacja().at(2));
        ui->textDrzewo->setText(text);
        text = QString::number(sym->getpopulacja().at(3));
        ui->textSkala->setText(text);
        text = QString::number(sym->getpopulacja().at(4));
        ui->textZajac->setText(text);
        text = QString::number(sym->getpopulacja().at(5));
        ui->textLis->setText(text);
    }
    else
    {
        timer->stop();
        QMessageBox::information(this,"Komunikat","Za dużo obiektów.");
        return;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    //koniec
    this->close();
//    qApp->exit();
}

void MainWindow::on_pushButton_3_clicked()
{
    //stop
    timer->stop();
}

void MainWindow::on_pushButton_5_clicked()
{
    //kont
    timer->start();
}
