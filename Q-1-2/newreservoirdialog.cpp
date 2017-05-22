#include "newreservoirdialog.h"
#include "ui_newreservoirdialog.h"

NewReservoirDialog::NewReservoirDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewReservoirDialog) {
    ui->setupUi(this);
}

NewReservoirDialog::~NewReservoirDialog() {
    delete ui;
}

Reservoir * NewReservoirDialog::getReservoir() {
    return this->reservoir;
}

void NewReservoirDialog::on_buttonBox_accepted() {
    this->reservoir = new Reservoir(
        ui->InitialValueSpinBox->value(),
        ui->minimumValueSpinBox->value(),
        ui->maximumValueSpinBox->value()
    );
}
