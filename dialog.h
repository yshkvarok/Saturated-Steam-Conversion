#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    double convertToPSIG(double ogValue, QString ogUnitType);
    double convertToTemp(double PSIG);
    double estimateTemp(double PSIG);

private slots:
    void on_lineEdit_pressure_textEdited(const QString &arg1);

    void on_lineEdit_temperature_textEdited(const QString &arg1);

    void on_comboBox_pressure_activated(const QString &arg1);

    void on_comboBox_temperature_activated(const QString &arg1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
