#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runPowerButton_clicked();
    void on_runSensorButton_clicked();
    void on_persistentCheckBox_stateChanged(int state);
    void loadCredentials();
    void executeCommand(const QString& command); // Add this line

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
