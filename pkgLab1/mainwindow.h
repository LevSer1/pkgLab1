
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_2_activated(int index);

    void on_comboBox_3_activated(int index);

    void on_comboBox_4_activated(int index);

private:
    Ui::MainWindow *ui;
    QColor mainColor;

    void buttonColor();

    void setFirst(QString);
    void setSecond(QString);
    void setThird(QString);
};

#endif // MAINWINDOW_H
