#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "symulacja.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent, CSymulacja *sym);
    ~Dialog();
    CSymulacja *getsym();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    CSymulacja *sym;
};

#endif // DIALOG_H
