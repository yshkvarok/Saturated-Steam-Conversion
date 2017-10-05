#include "dialog.h"
#include "ui_dialog.h"
#include "conversiontable.h"
#include <QString>
#include <iterator>
#include <list>
#include <algorithm>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

double Dialog::convertToPSIG(double ogValue, QString ogUnitType)
{
        if (ogUnitType == "PSI G")
            return ogValue;

//        else if (ogUnitType == "PSI abs")
//        {
//            ogValue -= 14.7;
//            return ogValue;
//        }

        else if (ogUnitType == "BAR G")
        {
            ogValue *= 14.5038;
            return ogValue;
        }

//        else if (ogUnitType == "BAR abs")
//        {
//            ogValue -= 1.01325;  // First converts to BAR Guaged
//            ogValue *= 14.5038;  // And then to PSI Guaged
//            return ogValue;
//        }

        else if (ogUnitType == "kg/cm2 G")
        {
            ogValue *= 14.2233;
            return ogValue;
        }

//        else if (ogUnitType == "kg/cm2 abs")
//        {
//            ogValue -= 1.03323;  // First converts to kg/cm2 Guaged      ******Cannot be under 1.03323 or error occurs*******
//            ogValue *= 14.2233;  // And then to PSI Guaged
//            return ogValue;
//        }

        else if (ogUnitType == "Kilopascal G")
        {
            ogValue *= 0.145038;
            return ogValue;
        }

//        else if (ogUnitType == "Kilopascal abs")
//        {
//            ogValue -= 101.325;  // First converts to kPa Guaged
//            ogValue *= 0.145038;  // Then converts to PSI Guaged
//            return ogValue;
//        }

        else
            return -1;
}

double Dialog::convertToTemp(double PSIG)
{
    if (PSIG <= 150 && PSIG == floor(PSIG))
        return conversiontable::values.at(PSIG);  // Return value from chart if PSIG is whole number

    if (PSIG > 150 && PSIG <= 200 && remainder(PSIG, 2) == 0)
        return conversiontable::values.at(PSIG);
    else if (PSIG > 200 && PSIG <= 300 && remainder(PSIG, 5) == 0)
        return conversiontable::values.at(PSIG);
    else if (PSIG > 300 && PSIG <= 600 && remainder(PSIG, 10) == 0)
        return conversiontable::values.at(PSIG);
    else
        return estimateTemp(PSIG);  // Estimate temperature if PSIG is not whole number
}

double Dialog::estimateTemp(double PSIG)
{
    int lowerPSIG = floor(PSIG);
    int upperPSIG = ceil(PSIG);

    if (lowerPSIG > 150 && upperPSIG <= 200)
    {
        if (lowerPSIG % 2 != 0)
            lowerPSIG--;
        if (upperPSIG % 2 != 0)
            upperPSIG++;
    }

    else if (lowerPSIG > 200 && upperPSIG <= 300)
    {
        while (lowerPSIG % 5 != 0)
            lowerPSIG--;
        while (upperPSIG % 5 != 0)
            upperPSIG++;
    }

    else if (lowerPSIG > 300 && upperPSIG <= 600)
    {
        while (lowerPSIG % 10 != 0)
            lowerPSIG--;
        while (upperPSIG % 10 != 0)
            upperPSIG++;
    }

    double lowerTemp = conversiontable::values.at(lowerPSIG);
    double upperTemp = conversiontable::values.at(upperPSIG);

    double convertedTemp = (upperTemp - lowerTemp)/(upperPSIG - lowerPSIG);
    convertedTemp = convertedTemp*(PSIG - lowerPSIG);
    convertedTemp += lowerTemp;

    return convertedTemp;
}

void Dialog::on_lineEdit_pressure_textEdited(const QString &arg1)
{
    if (ui->lineEdit_pressure->text().isEmpty())
    {
        ui->lineEdit_temperature->clear();
        return;
    }

    else if (ui->comboBox_pressure->currentText() == "PSI G" &&
             (ui->lineEdit_pressure->text().toDouble() < 0 || ui->lineEdit_pressure->text().toDouble() > 600))
    {
        ui->lineEdit_temperature->setText(ui->comboBox_pressure->currentText() + " must be between 0 and 600");
        return;
    }

    else if (ui->comboBox_pressure->currentText() == "BAR G" &&
             (ui->lineEdit_pressure->text().toDouble() < 0 || ui->lineEdit_pressure->text().toDouble() > 41.37))
    {
        ui->lineEdit_temperature->setText(ui->comboBox_pressure->currentText() + " must be between 0 and 41.37");
        return;
    }

    else if (ui->comboBox_pressure->currentText() == "kg/cm2 G" &&
             (ui->lineEdit_pressure->text().toDouble() < 0 || ui->lineEdit_pressure->text().toDouble() > 42.1857))
    {
        ui->lineEdit_temperature->setText(ui->comboBox_pressure->currentText() + " must be between 0 and 42.1857");
        return;
    }

    else if (ui->comboBox_pressure->currentText() == "Kilopascal G" &&
             (ui->lineEdit_pressure->text().toDouble() < 0 || ui->lineEdit_pressure->text().toDouble() > 4137))
    {
        ui->lineEdit_temperature->setText(ui->comboBox_pressure->currentText() + " must be between 0 and 4137");
        return;
    }

    ui->lineEdit_temperature->clear();

    double PSIG = convertToPSIG(ui->lineEdit_pressure->text().toDouble(), ui->comboBox_pressure->currentText());

    double convertedTemp = convertToTemp(PSIG);

    if (ui->comboBox_temperature->currentText() == "Fahrenheit")
        ui->lineEdit_temperature->setText(QString::number(convertedTemp));

    else if (ui->comboBox_temperature->currentText() == "Celsius")
    {
        double celsius = convertedTemp-32;  // Convert Farenheit to Celsius
        celsius = celsius*5/9;
        ui->lineEdit_temperature->setText(QString::number(celsius));
    }

    else if (ui->comboBox_temperature->currentText() == "Kelvin")
    {
        double kelvin = convertedTemp+459.67;  // Convert Farenheit to Kelvin
        kelvin = kelvin*5/9;
        ui->lineEdit_temperature->setText(QString::number(kelvin));
    }

}

void Dialog::on_lineEdit_temperature_textEdited(const QString &arg1)
{
    if (ui->lineEdit_temperature->text().isEmpty())
    {
        ui->lineEdit_pressure->clear();
        return;
    }

    double temp = ui->lineEdit_temperature->text().toDouble();

    if (ui->comboBox_temperature->currentText() == "Celsius")
    {
        temp = temp*1.8;  // Convert Celsius to Fahrenheit
        temp = temp+32;
    }
    else if (ui->comboBox_temperature->currentText() == "Kelvin")
    {
        temp = temp*1.8;  // Convert Kelvin to Fahrenheit
        temp = temp-459.67;
    }

    if (temp < 212 || temp > 488.79)
    {
        if (ui->comboBox_temperature->currentText() == "Fahrenheit")
            ui->lineEdit_pressure->setText(ui->comboBox_temperature->currentText() + " must be between 212 and 488.79");
        else if (ui->comboBox_temperature->currentText() == "Celsius")
            ui->lineEdit_pressure->setText(ui->comboBox_temperature->currentText() + " must be between 100 and 253.772");
        else if (ui->comboBox_temperature->currentText() == "Kelvin")
            ui->lineEdit_pressure->setText(ui->comboBox_temperature->currentText() + " must be between 373.15 and 526.922");
        return;
    }

    std::pair<int, double> highest = *conversiontable::values.rbegin();          // last element

    std::map<int, double>::iterator it = conversiontable::values.begin();

    double upperPSIG;
    double lowerPSIG;
    double upperTemp;
    double lowerTemp;
    double convertedPSIG;

    do {
        if (it->second == temp)
        {
            convertedPSIG = it->first;
            break;
        }

        if (temp < it->second)
        {
            upperPSIG = it->first;
            lowerPSIG = (it->first)-1;

            lowerTemp = conversiontable::values[lowerPSIG];
            upperTemp = it->second;

            convertedPSIG = temp - lowerTemp;
            convertedPSIG *= (upperPSIG-lowerPSIG);
            convertedPSIG /= (upperTemp-lowerTemp);
            convertedPSIG += lowerPSIG;

            break;
        }
    } while (conversiontable::values.value_comp()(*it++, highest));

    if (ui->comboBox_pressure->currentText() == "BAR G")
        convertedPSIG /= 14.5038;
    else if (ui->comboBox_pressure->currentText() == "kg/cm2 G")
        convertedPSIG /= 14.2233;
    else if (ui->comboBox_pressure->currentText() == "Kilopascal G")
        convertedPSIG /= 0.145038;

    ui->lineEdit_pressure->setText(QString::number(convertedPSIG));
}

void Dialog::on_comboBox_pressure_activated(const QString &arg1)
{
    ui->lineEdit_pressure->clear();
    ui->lineEdit_temperature->clear();
}

void Dialog::on_comboBox_temperature_activated(const QString &arg1)
{
    ui->lineEdit_pressure->clear();
    ui->lineEdit_temperature->clear();
}
