#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the QTextEdit widget to read-only
    ui->outputTextEdit->setReadOnly(true);

    // Connect button signals to slots
    connect(ui->runButton, &QPushButton::clicked, this, &MainWindow::on_runButton_clicked);
    connect(ui->sensorButton, &QPushButton::clicked, this, &MainWindow::on_sensorButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runButton_clicked()
{
    QString hostname = ui->hostnameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString command = ui->commandComboBox->currentText();

    // Construct the IPMI command
    QString ipmiCommand = "ipmitool -H " + hostname + " -U " + username + " -P " + password + " power " + command;

    // Run the IPMI command and capture output
    QProcess process;
    process.start(ipmiCommand);
    if (!process.waitForStarted()) {
        ui->outputTextEdit->setPlainText("Error: Failed to start process.");
        return;
    }
    if (!process.waitForFinished()) {
        ui->outputTextEdit->setPlainText("Error: Process execution timed out.");
        return;
    }
    if (process.error() != QProcess::UnknownError) {
        ui->outputTextEdit->setPlainText("Error: " + process.errorString());
        return;
    }

    QString output = process.readAllStandardOutput();

    // Show output in the QTextEdit widget
    ui->outputTextEdit->setPlainText(output);
}

void MainWindow::on_sensorButton_clicked()
{
    QString hostname = ui->hostnameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // Construct the IPMI sensor command
    QString ipmiCommand = "ipmitool -H " + hostname + " -U " + username + " -P " + password + " sensor";

    // Run the IPMI sensor command and capture output
    QProcess process;
    process.start(ipmiCommand);
    if (!process.waitForStarted()) {
        ui->outputTextEdit->setPlainText("Error: Failed to start process.");
        return;
    }
    if (!process.waitForFinished()) {
        ui->outputTextEdit->setPlainText("Error: Process execution timed out.");
        return;
    }
    if (process.error() != QProcess::UnknownError) {
        ui->outputTextEdit->setPlainText("Error: " + process.errorString());
        return;
    }

    QString output = process.readAllStandardOutput();

    // Show output in the QTextEdit widget
    ui->outputTextEdit->setPlainText(output);
}
