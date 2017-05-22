#ifndef NEWRESERVOIRDIALOG_H
#define NEWRESERVOIRDIALOG_H

#include <QDialog>

#include "reservoir.h"

namespace Ui {
class NewReservoirDialog;
}

class NewReservoirDialog : public QDialog {
    Q_OBJECT

public:
    explicit NewReservoirDialog(QWidget *parent = 0);
    ~NewReservoirDialog();

    Reservoir * getReservoir();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewReservoirDialog *ui;
    Reservoir * reservoir;

};

#endif // NEWRESERVOIRDIALOG_H
