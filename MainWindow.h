#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runButton_clicked();
    void on_sensorButton_clicked(); // Declaration of the sensor button slot

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
