#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QStringList headers;
    headers << "Valor Inicial" << "Mínimo" << "Máximo";
    ui->reservoirTable->setHorizontalHeaderLabels(headers);
    ui->reservoirTable->horizontalHeader()->setVisible(true);
    ui->reservoirTable->setColumnCount(3);

    QStringList headersZone;
    headersZone << "Limite Inferior (hm3)" << "Limite Superior (hm3)" << "Volume Disponível" << "Prioridade";
    ui->zonesTable->setHorizontalHeaderLabels(headersZone);
    ui->zonesTable->horizontalHeader()->setVisible(true);
    ui->zonesTable->setColumnCount(3);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addReservoirButton_clicked() {
    NewReservoirDialog d;
    d.exec();

    Reservoir * r = d.getReservoir();
    this->reservoirs << r;
    this->updateList();
}

void MainWindow::updateList() {
    ui->reservoirTable->setRowCount(this->reservoirs.size());
    for(int i = 0; i < this->reservoirs.size(); i++) {
        Reservoir * r = this->reservoirs[i];
        QTableWidgetItem * item1 = new QTableWidgetItem(QString::number(r->getInitialValue()));
        QTableWidgetItem * item2 = new QTableWidgetItem(QString::number(r->getMinimumValue()));
        QTableWidgetItem * item3 = new QTableWidgetItem(QString::number(r->getMaximumValue()));
        ui->reservoirTable->setItem(i, 0, item1);
        ui->reservoirTable->setItem(i, 1, item2);
        ui->reservoirTable->setItem(i, 2, item3);
    }

}

void MainWindow::updateZoneList() {
    ui->zonesTable->setRowCount(this->selectedReservoir->getPriorityZones().size());
    for(int i = 0; i < this->selectedReservoir->getPriorityZones().size(); i++) {
        PriorityZone pz = this->selectedReservoir->getPriorityZones()[i];
        QTableWidgetItem * item1 = new QTableWidgetItem(QString::number(pz.getTopLimit() - pz.getAvailableVolume()));
        QTableWidgetItem * item2 = new QTableWidgetItem(QString::number(pz.getTopLimit()));
        QTableWidgetItem * item3 = new QTableWidgetItem(QString::number(pz.getPriority()));
        ui->zonesTable->setItem(i, 0, item1);
        ui->zonesTable->setItem(i, 1, item2);
        ui->zonesTable->setItem(i, 2, item3);
    }

}


void MainWindow::on_editReservoirButton_clicked() {
    if(ui->reservoirTable->selectedItems().size() > 0)
        ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_reservoirTable_cellClicked(int row, int column) {
    this->selectedReservoir = this->reservoirs[row];
}

void MainWindow::on_seeReservoirsButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addLineButton_clicked() {
    NewZoneDialog d;
    d.exec();

    PriorityZone p = *(d.getPriorityZone());
    this->selectedReservoir->addPriorityZone(p);
    this->updateZoneList();
}

void MainWindow::on_zonesTable_cellClicked(int row, int column) {
    this->selectedZone = this->selectedReservoir->getPriorityZones()[row];
}

void MainWindow::on_removeZoneButton_clicked() {
    this->selectedReservoir->removePriorityZone(this->selectedZone);
    this->updateZoneList();
}
