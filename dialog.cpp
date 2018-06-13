#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent, CSymulacja *sym) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->sym=sym;
    QString text;
    text = QString::number(sym->getpopulacja().at(0));
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

    text = QString::number(sym->getx());
    ui->textWyspaSzerokosc->setText(text);
    text = QString::number(sym->gety());
    ui->textWyspaWysokosc->setText(text);

}

Dialog::~Dialog()
{
    delete ui;
//    delete sym;
}

CSymulacja *Dialog::getsym()
{
    return sym;
}

void Dialog::on_buttonBox_accepted()
{
    cout<<"tu"<<endl;
    delete sym;
    QString text;
    cout<<"tu"<<endl;
    text = ui->textWyspaSzerokosc->toPlainText();
    cout<<"tu"<<endl;
    int x = text.toInt();
    cout<<"tu"<<endl;
    text = ui->textWyspaWysokosc->toPlainText();
    int y = text.toInt();
    text = ui->textWilk->toPlainText();
    int lw = text.toInt();
    text = ui->textOwca->toPlainText();
    int lo = text.toInt();
    text = ui->textDrzewo->toPlainText();
    int ld = text.toInt();
    text = ui->textSkala->toPlainText();
    int ls = text.toInt();
    text = ui->textZajac->toPlainText();
    int lz = text.toInt();
    text = ui->textLis->toPlainText();
    int ll = text.toInt();

//    sym->start(x, y, lw, lo, ld, ls, lz, ll);
    sym->start();
    cout<<"tu"<<endl;
    this->close();
}

void Dialog::on_buttonBox_rejected()
{
    //koniec
    this->close();
}
