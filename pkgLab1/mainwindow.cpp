
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mainColor(Qt::black)
{
    ui->setupUi(this);

    buttonColor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Выберите цвет");

    if (color.isValid())
    {
        mainColor = color;
        buttonColor();
    }
}

void MainWindow::buttonColor()
{
    QString styleSheet = QString("background-color: %1").arg(mainColor.name());
    ui->pushButton->setStyleSheet(styleSheet);
}

void MainWindow::setFirst(QString sys)
{
    if (sys == "RGB")
    {
        ui->label_2->setText("RGB");
        ui->label_3->setText("R");
        ui->label_4->setText("G");
        ui->label_5->setText("B");
        ui->label_6->setText("-");

        ui->doubleSpinBox_4->setEnabled(false);

        ui->doubleSpinBox->setMaximum(255);
        ui->doubleSpinBox->setMinimum(0);
        ui->doubleSpinBox->setDecimals(0);

        ui->doubleSpinBox_2->setMaximum(255);
        ui->doubleSpinBox_2->setMinimum(0);
        ui->doubleSpinBox_2->setDecimals(0);

        ui->doubleSpinBox_3->setMaximum(255);
        ui->doubleSpinBox_3->setMinimum(0);
        ui->doubleSpinBox_3->setDecimals(0);

        return;
    }
    if (sys == "CMYK")
    {
        ui->label_2->setText("CMYK");
        ui->label_3->setText("C");
        ui->label_4->setText("M");
        ui->label_5->setText("Y");
        ui->label_6->setText("K");

        ui->doubleSpinBox_4->setEnabled(true);

        ui->doubleSpinBox->setMaximum(100);
        ui->doubleSpinBox->setMinimum(0);
        ui->doubleSpinBox->setDecimals(3);

        ui->doubleSpinBox_2->setMaximum(100);
        ui->doubleSpinBox_2->setMinimum(0);
        ui->doubleSpinBox_2->setDecimals(3);

        ui->doubleSpinBox_3->setMaximum(100);
        ui->doubleSpinBox_3->setMinimum(0);
        ui->doubleSpinBox_3->setDecimals(3);

        ui->doubleSpinBox_4->setMaximum(100);
        ui->doubleSpinBox_4->setMinimum(0);
        ui->doubleSpinBox_4->setDecimals(3);

        return;
    }
    if (sys == "HSV")
    {
        ui->label_2->setText("HSV");
        ui->label_3->setText("H");
        ui->label_4->setText("S");
        ui->label_5->setText("V");
        ui->label_6->setText("-");

        ui->doubleSpinBox_4->setEnabled(false);

        ui->doubleSpinBox->setMaximum(360);
        ui->doubleSpinBox->setMinimum(0);
        ui->doubleSpinBox->setDecimals(3);

        ui->doubleSpinBox_2->setMaximum(100);
        ui->doubleSpinBox_2->setMinimum(0);
        ui->doubleSpinBox_2->setDecimals(3);

        ui->doubleSpinBox_3->setMaximum(100);
        ui->doubleSpinBox_3->setMinimum(0);
        ui->doubleSpinBox_3->setDecimals(3);

        return;
    }
    if (sys == "HSL")
    {
        ui->label_2->setText("HSL");
        ui->label_3->setText("H");
        ui->label_4->setText("S");
        ui->label_5->setText("L");
        ui->label_6->setText("-");

        ui->doubleSpinBox_4->setEnabled(false);

        ui->doubleSpinBox->setMaximum(360);
        ui->doubleSpinBox->setMinimum(0);
        ui->doubleSpinBox->setDecimals(3);

        ui->doubleSpinBox_2->setMaximum(100);
        ui->doubleSpinBox_2->setMinimum(0);
        ui->doubleSpinBox_2->setDecimals(3);

        ui->doubleSpinBox_3->setMaximum(100);
        ui->doubleSpinBox_3->setMinimum(0);
        ui->doubleSpinBox_3->setDecimals(3);

        return;
    }
    if (sys == "XYZ")
    {
        ui->label_2->setText("XYZ");
        ui->label_3->setText("X");
        ui->label_4->setText("Y");
        ui->label_5->setText("Z");
        ui->label_6->setText("-");

        ui->doubleSpinBox_4->setEnabled(false);

        ui->doubleSpinBox->setMaximum(95.047);
        ui->doubleSpinBox->setMinimum(0);
        ui->doubleSpinBox->setDecimals(3);

        ui->doubleSpinBox_2->setMaximum(100);
        ui->doubleSpinBox_2->setMinimum(0);
        ui->doubleSpinBox_2->setDecimals(3);

        ui->doubleSpinBox_3->setMaximum(108.883);
        ui->doubleSpinBox_3->setMinimum(0);
        ui->doubleSpinBox_3->setDecimals(3);

        return;
    }
    if (sys == "LAB")
    {
        ui->label_2->setText("LAB");
        ui->label_3->setText("L");
        ui->label_4->setText("A");
        ui->label_5->setText("B");
        ui->label_6->setText("-");

        ui->doubleSpinBox_4->setEnabled(false);

        ui->doubleSpinBox->setMaximum(100);
        ui->doubleSpinBox->setMinimum(0);
        ui->doubleSpinBox->setDecimals(3);

        ui->doubleSpinBox_2->setMaximum(128);
        ui->doubleSpinBox_2->setMinimum(-128);
        ui->doubleSpinBox_2->setDecimals(3);

        ui->doubleSpinBox_3->setMaximum(128);
        ui->doubleSpinBox_3->setMinimum(-128);
        ui->doubleSpinBox_3->setDecimals(3);

        return;
    }
}

void MainWindow::setSecond(QString sys)
{
    if (sys == "RGB")
    {
        ui->label_8->setText("RGB");
        ui->label_11->setText("R");
        ui->label_10->setText("G");
        ui->label_7->setText("B");
        ui->label_9->setText("-");

        ui->doubleSpinBox_8->setEnabled(false);

        ui->doubleSpinBox_5->setMaximum(255);
        ui->doubleSpinBox_5->setMinimum(0);
        ui->doubleSpinBox_5->setDecimals(0);

        ui->doubleSpinBox_7->setMaximum(255);
        ui->doubleSpinBox_7->setMinimum(0);
        ui->doubleSpinBox_7->setDecimals(0);

        ui->doubleSpinBox_6->setMaximum(255);
        ui->doubleSpinBox_6->setMinimum(0);
        ui->doubleSpinBox_6->setDecimals(0);

        return;
    }
    if (sys == "CMYK")
    {
        ui->label_8->setText("CMYK");
        ui->label_11->setText("C");
        ui->label_10->setText("M");
        ui->label_7->setText("Y");
        ui->label_9->setText("K");

        ui->doubleSpinBox_8->setEnabled(true);

        ui->doubleSpinBox_5->setMaximum(100);
        ui->doubleSpinBox_5->setMinimum(0);
        ui->doubleSpinBox_5->setDecimals(3);

        ui->doubleSpinBox_7->setMaximum(100);
        ui->doubleSpinBox_7->setMinimum(0);
        ui->doubleSpinBox_7->setDecimals(3);

        ui->doubleSpinBox_6->setMaximum(100);
        ui->doubleSpinBox_6->setMinimum(0);
        ui->doubleSpinBox_6->setDecimals(3);

        ui->doubleSpinBox_8->setMaximum(100);
        ui->doubleSpinBox_8->setMinimum(0);
        ui->doubleSpinBox_8->setDecimals(3);

        return;
    }
    if (sys == "HSV")
    {
        ui->label_8->setText("HSV");
        ui->label_11->setText("H");
        ui->label_10->setText("S");
        ui->label_7->setText("V");
        ui->label_9->setText("-");

        ui->doubleSpinBox_8->setEnabled(false);

        ui->doubleSpinBox_5->setMaximum(360);
        ui->doubleSpinBox_5->setMinimum(0);
        ui->doubleSpinBox_5->setDecimals(3);

        ui->doubleSpinBox_7->setMaximum(100);
        ui->doubleSpinBox_7->setMinimum(0);
        ui->doubleSpinBox_7->setDecimals(3);

        ui->doubleSpinBox_6->setMaximum(100);
        ui->doubleSpinBox_6->setMinimum(0);
        ui->doubleSpinBox_6->setDecimals(3);

        return;
    }
    if (sys == "HSL")
    {
        ui->label_8->setText("HSL");
        ui->label_11->setText("H");
        ui->label_10->setText("S");
        ui->label_7->setText("L");
        ui->label_9->setText("-");

        ui->doubleSpinBox_8->setEnabled(false);

        ui->doubleSpinBox_5->setMaximum(360);
        ui->doubleSpinBox_5->setMinimum(0);
        ui->doubleSpinBox_5->setDecimals(3);

        ui->doubleSpinBox_7->setMaximum(100);
        ui->doubleSpinBox_7->setMinimum(0);
        ui->doubleSpinBox_7->setDecimals(3);

        ui->doubleSpinBox_6->setMaximum(100);
        ui->doubleSpinBox_6->setMinimum(0);
        ui->doubleSpinBox_6->setDecimals(3);

        return;
    }
    if (sys == "XYZ")
    {
        ui->label_8->setText("XYZ");
        ui->label_11->setText("X");
        ui->label_10->setText("Y");
        ui->label_7->setText("Z");
        ui->label_9->setText("-");

        ui->doubleSpinBox_8->setEnabled(false);

        ui->doubleSpinBox_5->setMaximum(95.047);
        ui->doubleSpinBox_5->setMinimum(0);
        ui->doubleSpinBox_5->setDecimals(3);

        ui->doubleSpinBox_7->setMaximum(100);
        ui->doubleSpinBox_7->setMinimum(0);
        ui->doubleSpinBox_7->setDecimals(3);

        ui->doubleSpinBox_6->setMaximum(108.883);
        ui->doubleSpinBox_6->setMinimum(0);
        ui->doubleSpinBox_6->setDecimals(3);

        return;
    }
    if (sys == "LAB")
    {
        ui->label_8->setText("LAB");
        ui->label_11->setText("L");
        ui->label_10->setText("A");
        ui->label_7->setText("B");
        ui->label_9->setText("-");

        ui->doubleSpinBox_8->setEnabled(false);

        ui->doubleSpinBox_5->setMaximum(100);
        ui->doubleSpinBox_5->setMinimum(0);
        ui->doubleSpinBox_5->setDecimals(3);

        ui->doubleSpinBox_7->setMaximum(128);
        ui->doubleSpinBox_7->setMinimum(-128);
        ui->doubleSpinBox_7->setDecimals(3);

        ui->doubleSpinBox_6->setMaximum(128);
        ui->doubleSpinBox_6->setMinimum(-128);
        ui->doubleSpinBox_6->setDecimals(3);

        return;
    }
}

void MainWindow::setThird(QString sys)
{
    if (sys == "RGB")
    {
        ui->label_13->setText("RGB");
        ui->label_16->setText("R");
        ui->label_15->setText("G");
        ui->label_12->setText("B");
        ui->label_14->setText("-");

        ui->doubleSpinBox_12->setEnabled(false);

        ui->doubleSpinBox_9->setMaximum(255);
        ui->doubleSpinBox_9->setMinimum(0);
        ui->doubleSpinBox_9->setDecimals(0);

        ui->doubleSpinBox_11->setMaximum(255);
        ui->doubleSpinBox_11->setMinimum(0);
        ui->doubleSpinBox_11->setDecimals(0);

        ui->doubleSpinBox_10->setMaximum(255);
        ui->doubleSpinBox_10->setMinimum(0);
        ui->doubleSpinBox_10->setDecimals(0);

        return;
    }
    if (sys == "CMYK")
    {
        ui->label_13->setText("CMYK");
        ui->label_16->setText("C");
        ui->label_15->setText("M");
        ui->label_12->setText("Y");
        ui->label_14->setText("K");

        ui->doubleSpinBox_12->setEnabled(true);

        ui->doubleSpinBox_9->setMaximum(100);
        ui->doubleSpinBox_9->setMinimum(0);
        ui->doubleSpinBox_9->setDecimals(3);

        ui->doubleSpinBox_11->setMaximum(100);
        ui->doubleSpinBox_11->setMinimum(0);
        ui->doubleSpinBox_11->setDecimals(3);

        ui->doubleSpinBox_10->setMaximum(100);
        ui->doubleSpinBox_10->setMinimum(0);
        ui->doubleSpinBox_10->setDecimals(3);

        ui->doubleSpinBox_12->setMaximum(100);
        ui->doubleSpinBox_12->setMinimum(0);
        ui->doubleSpinBox_12->setDecimals(3);

        return;
    }
    if (sys == "HSV")
    {
        ui->label_13->setText("HSV");
        ui->label_16->setText("H");
        ui->label_15->setText("S");
        ui->label_12->setText("V");
        ui->label_14->setText("-");

        ui->doubleSpinBox_12->setEnabled(false);

        ui->doubleSpinBox_9->setMaximum(360);
        ui->doubleSpinBox_9->setMinimum(0);
        ui->doubleSpinBox_9->setDecimals(3);

        ui->doubleSpinBox_11->setMaximum(100);
        ui->doubleSpinBox_11->setMinimum(0);
        ui->doubleSpinBox_11->setDecimals(3);

        ui->doubleSpinBox_10->setMaximum(100);
        ui->doubleSpinBox_10->setMinimum(0);
        ui->doubleSpinBox_10->setDecimals(3);

        return;
    }
    if (sys == "HSL")
    {
        ui->label_13->setText("HSL");
        ui->label_16->setText("H");
        ui->label_15->setText("S");
        ui->label_12->setText("L");
        ui->label_14->setText("-");

        ui->doubleSpinBox_12->setEnabled(false);

        ui->doubleSpinBox_9->setMaximum(360);
        ui->doubleSpinBox_9->setMinimum(0);
        ui->doubleSpinBox_9->setDecimals(3);

        ui->doubleSpinBox_11->setMaximum(100);
        ui->doubleSpinBox_11->setMinimum(0);
        ui->doubleSpinBox_11->setDecimals(3);

        ui->doubleSpinBox_10->setMaximum(100);
        ui->doubleSpinBox_10->setMinimum(0);
        ui->doubleSpinBox_10->setDecimals(3);

        return;
    }
    if (sys == "XYZ")
    {
        ui->label_13->setText("XYZ");
        ui->label_16->setText("X");
        ui->label_15->setText("Y");
        ui->label_12->setText("Z");
        ui->label_14->setText("-");

        ui->doubleSpinBox_12->setEnabled(false);

        ui->doubleSpinBox_9->setMaximum(95.047);
        ui->doubleSpinBox_9->setMinimum(0);
        ui->doubleSpinBox_9->setDecimals(3);

        ui->doubleSpinBox_11->setMaximum(100);
        ui->doubleSpinBox_11->setMinimum(0);
        ui->doubleSpinBox_11->setDecimals(3);

        ui->doubleSpinBox_10->setMaximum(108.883);
        ui->doubleSpinBox_10->setMinimum(0);
        ui->doubleSpinBox_10->setDecimals(3);

        return;
    }
    if (sys == "LAB")
    {
        ui->label_13->setText("LAB");
        ui->label_16->setText("L");
        ui->label_15->setText("A");
        ui->label_12->setText("B");
        ui->label_14->setText("-");

        ui->doubleSpinBox_12->setEnabled(false);

        ui->doubleSpinBox_9->setMaximum(100);
        ui->doubleSpinBox_9->setMinimum(0);
        ui->doubleSpinBox_9->setDecimals(3);

        ui->doubleSpinBox_11->setMaximum(128);
        ui->doubleSpinBox_11->setMinimum(-128);
        ui->doubleSpinBox_11->setDecimals(3);

        ui->doubleSpinBox_10->setMaximum(128);
        ui->doubleSpinBox_10->setMinimum(-128);
        ui->doubleSpinBox_10->setDecimals(3);

        return;
    }
}

void MainWindow::on_comboBox_2_activated(int index)
{
    switch (index)
    {
    case 0:
        setFirst("RGB");
        break;
    case 1:
        setFirst("CMYK");
        break;
    case 2:
        setFirst("HSV");
        break;
    case 3:
        setFirst("HSL");
        break;
    case 4:
        setFirst("XYZ");
        break;
    case 5:
        setFirst("LAB");
        break;

    default:
        break;
    }
}

void MainWindow::on_comboBox_3_activated(int index)
{
    switch (index)
    {
    case 1:
        setSecond("RGB");
        break;
    case 2:
        setSecond("CMYK");
        break;
    case 3:
        setSecond("HSV");
        break;
    case 4:
        setSecond("HSL");
        break;
    case 5:
        setSecond("XYZ");
        break;
    case 0:
        setSecond("LAB");
        break;

    default:
        break;
    }
}

void MainWindow::on_comboBox_4_activated(int index)
{
    switch (index)
    {
    case 1:
        setThird("RGB");
        break;
    case 0:
        setThird("CMYK");
        break;
    case 2:
        setThird("HSV");
        break;
    case 3:
        setThird("HSL");
        break;
    case 4:
        setThird("XYZ");
        break;
    case 5:
        setThird("LAB");
        break;

    default:
        break;
    }
}
