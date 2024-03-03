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
    process.waitForFinished();
    QString output = process.readAllStandardOutput();

    // Show output in the QTextEdit widget
    ui->outputTextEdit->setPlainText(output);
}
