
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mainColor(Qt::black)
{
    ui->setupUi(this);

    first = new RGB(0, 0, 0);
    second = new Lab(0, 0, 0);
    third = new CMYK(0, 0, 0, 0);

    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(valueChanged1(double)));
    connect(ui->doubleSpinBox_2, SIGNAL(valueChanged(double)), this, SLOT(valueChanged1(double)));
    connect(ui->doubleSpinBox_3, SIGNAL(valueChanged(double)), this, SLOT(valueChanged1(double)));
    connect(ui->doubleSpinBox_4, SIGNAL(valueChanged(double)), this, SLOT(valueChanged1(double)));

    connect(ui->doubleSpinBox_5, SIGNAL(valueChanged(double)), this, SLOT(valueChanged2(double)));
    connect(ui->doubleSpinBox_7, SIGNAL(valueChanged(double)), this, SLOT(valueChanged2(double)));
    connect(ui->doubleSpinBox_6, SIGNAL(valueChanged(double)), this, SLOT(valueChanged2(double)));
    connect(ui->doubleSpinBox_8, SIGNAL(valueChanged(double)), this, SLOT(valueChanged2(double)));

    connect(ui->doubleSpinBox_9, SIGNAL(valueChanged(double)), this, SLOT(valueChanged3(double)));
    connect(ui->doubleSpinBox_11, SIGNAL(valueChanged(double)), this, SLOT(valueChanged3(double)));
    connect(ui->doubleSpinBox_10, SIGNAL(valueChanged(double)), this, SLOT(valueChanged3(double)));
    connect(ui->doubleSpinBox_12, SIGNAL(valueChanged(double)), this, SLOT(valueChanged3(double)));

    updateColor();
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
        updateColor();
    }
}

void MainWindow::updateColor()
{
    QString styleSheet = QString("background-color: %1").arg(mainColor.name());
    ui->pushButton->setStyleSheet(styleSheet);

    ui->doubleSpinBox->setValue(first->getParam1());
    ui->doubleSpinBox_2->setValue(first->getParam2());
    ui->doubleSpinBox_3->setValue(first->getParam3());
    ui->doubleSpinBox_4->setValue(first->getParam4());

    ui->doubleSpinBox_5->setValue(second->getParam1());
    ui->doubleSpinBox_7->setValue(second->getParam2());
    ui->doubleSpinBox_6->setValue(second->getParam3());
    ui->doubleSpinBox_8->setValue(second->getParam4());

    ui->doubleSpinBox_9->setValue(third->getParam1());
    ui->doubleSpinBox_11->setValue(third->getParam2());
    ui->doubleSpinBox_10->setValue(third->getParam3());
    ui->doubleSpinBox_12->setValue(third->getParam4());
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
        first = second->toRGB();
        break;
    case 1:
        setFirst("CMYK");
        first = second->toCMYK();
        break;
    case 2:
        setFirst("HSV");
        first = second->toHSV();
        break;
    case 3:
        setFirst("HSL");
        first = second->toHLS();
        break;
    case 4:
        setFirst("XYZ");
        first = second->toXYZ();
        break;
    case 5:
        setFirst("LAB");
        first = second->toLAB();
        break;

    default:
        break;
    }

    updateColor();
}

void MainWindow::on_comboBox_3_activated(int index)
{
    switch (index)
    {
    case 1:
        setSecond("RGB");
        second = first->toRGB();
        break;
    case 2:
        setSecond("CMYK");
        second = first->toCMYK();
        break;
    case 3:
        setSecond("HSV");
        second = first->toHSV();
        break;
    case 4:
        setSecond("HSL");
        second = first->toHLS();
        break;
    case 5:
        setSecond("XYZ");
        second = first->toXYZ();
        break;
    case 0:
        setSecond("LAB");
        second = first->toLAB();
        break;

    default:
        break;
    }

    updateColor();
}

void MainWindow::on_comboBox_4_activated(int index)
{
    switch (index)
    {
    case 1:
        setThird("RGB");
        third = second->toRGB();
        break;
    case 0:
        setThird("CMYK");
        third = second->toCMYK();
        break;
    case 2:
        setThird("HSV");
        third = second->toHSV();
        break;
    case 3:
        setThird("HSL");
        third = second->toHLS();
        break;
    case 4:
        setThird("XYZ");
        third = second->toXYZ();
        break;
    case 5:
        setThird("LAB");
        third = second->toLAB();
        break;

    default:
        break;
    }

    updateColor();
}

void MainWindow::valueChanged1(double)
{
    double val1 = ui->doubleSpinBox->value(), val2 = ui->doubleSpinBox_2->value(),
           val3 = ui->doubleSpinBox_3->value(), val4 = ui->doubleSpinBox_4->value();

    first->setParam1(val1);
    first->setParam2(val2);
    first->setParam3(val3);
    first->setParam4(val4);

    mainColor.setRed(first->toRGB()->getParam1());
    mainColor.setGreen(first->toRGB()->getParam2());
    mainColor.setBlue(first->toRGB()->getParam3());
    updateColor();
}

void MainWindow::valueChanged2(double)
{
    double val1 = ui->doubleSpinBox_5->value(), val2 = ui->doubleSpinBox_7->value(),
           val3 = ui->doubleSpinBox_6->value(), val4 = ui->doubleSpinBox_8->value();

    second->setParam1(val1);
    second->setParam2(val2);
    second->setParam3(val3);
    second->setParam4(val4);

    mainColor.setRed(second->toRGB()->getParam1());
    mainColor.setGreen(second->toRGB()->getParam2());
    mainColor.setBlue(second->toRGB()->getParam3());
    updateColor();
}

void MainWindow::valueChanged3(double)
{
    double val1 = ui->doubleSpinBox_9->value(), val2 = ui->doubleSpinBox_11->value(),
           val3 = ui->doubleSpinBox_10->value(), val4 = ui->doubleSpinBox_12->value();

    third->setParam1(val1);
    third->setParam2(val2);
    third->setParam3(val3);
    third->setParam4(val4);

    mainColor.setRed(third->toRGB()->getParam1());
    mainColor.setGreen(third->toRGB()->getParam2());
    mainColor.setBlue(third->toRGB()->getParam3());
    updateColor();
}
