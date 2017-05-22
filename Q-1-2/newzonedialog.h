#ifndef NEWZONEDIALOG_H
#define NEWZONEDIALOG_H

#include <QDialog>

#include "priorityzone.h"

namespace Ui {
class NewZoneDialog;
}

class NewZoneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewZoneDialog(QWidget *parent = 0);
    ~NewZoneDialog();

    PriorityZone *getPriorityZone() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewZoneDialog *ui;

    PriorityZone * priorityZone;
};

#endif // NEWZONEDIALOG_H
