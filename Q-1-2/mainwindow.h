#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVector>

#include "newreservoirdialog.h"
#include "newzonedialog.h"
#include "reservoir.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addReservoirButton_clicked();

    void on_editReservoirButton_clicked();

    void on_reservoirTable_cellClicked(int row, int column);

    void on_seeReservoirsButton_clicked();

    void on_addLineButton_clicked();

    void on_zonesTable_cellClicked(int row, int column);

    void on_removeZoneButton_clicked();

private:
    Ui::MainWindow *ui;

    QVector<Reservoir *> reservoirs;
    Reservoir * selectedReservoir;
    PriorityZone selectedZone;

    void updateList();
    void updateZoneList();
};

#endif // MAINWINDOW_H
