#include "newzonedialog.h"
#include "ui_newzonedialog.h"

NewZoneDialog::NewZoneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewZoneDialog)
{
    ui->setupUi(this);
}

NewZoneDialog::~NewZoneDialog()
{
    delete ui;
}

void NewZoneDialog::on_buttonBox_accepted() {
    this->priorityZone = new PriorityZone(0.0, ui->newZoneTopLimitSpinBox->value(), -1);
}

PriorityZone *NewZoneDialog::getPriorityZone() const {
    return priorityZone;
}
