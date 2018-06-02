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
    timer->setInterval(1000);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_2_clicked()));

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
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    sym->start();
    scene->addItem(sym->getgwyspa());
    for(int i=0; i<sym->getwyspa()->getGO().size(); i++)
        scene->addItem(sym->getwyspa()->getGO().at(i));
}

void MainWindow::on_pushButton_2_clicked()
{
    //update
    sym->update();
    ui->graphicsView->update();
}

void MainWindow::on_pushButton_3_clicked()
{
    //stop
    timer->stop();
}

void MainWindow::on_pushButton_4_clicked()
{
    qApp->exit();
}
