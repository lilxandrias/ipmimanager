#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QProcess>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the QTextEdit widget to read-only
    ui->outputTextEdit->setReadOnly(true);

    // Connect button signals to slots
    connect(ui->runPowerButton, &QPushButton::clicked, this, &MainWindow::on_runPowerButton_clicked);
    connect(ui->runSensorButton, &QPushButton::clicked, this, &MainWindow::on_runSensorButton_clicked);
    connect(ui->persistentCheckBox, &QCheckBox::stateChanged, this, &MainWindow::on_persistentCheckBox_stateChanged);

    // Load saved credentials if available
    loadCredentials();

    // Set "Save Credentials" checkbox ticked by default
    ui->persistentCheckBox->setChecked(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runPowerButton_clicked()
{
    QString hostname = ui->hostnameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString command = ui->powerComboBox->currentText();

    // Construct the IPMI command
    QString ipmiCommand = "ipmitool -H " + hostname + " -U " + username + " -P " + password + " power " + command;

    executeCommand(ipmiCommand);
}

void MainWindow::on_runSensorButton_clicked()
{
    QString hostname = ui->hostnameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString command = ui->sensorComboBox->currentText();

    // Construct the IPMI sensor command
    QString ipmiCommand = "ipmitool -H " + hostname + " -U " + username + " -P " + password + " sdr";

    executeCommand(ipmiCommand);
}

void MainWindow::on_persistentCheckBox_stateChanged(int state)
{
    // Save or remove credentials based on checkbox state
    if (state == Qt::Checked) {
        QString hostname = ui->hostnameLineEdit->text();
        QString username = ui->usernameLineEdit->text();
        QString password = ui->passwordLineEdit->text();

        // Save credentials to settings
        QSettings settings;
        settings.setValue("hostname", hostname);
        settings.setValue("username", username);
        settings.setValue("password", password);
    } else {
        // Remove saved credentials
        QSettings settings;
        settings.remove("hostname");
        settings.remove("username");
        settings.remove("password");
    }
}

void MainWindow::loadCredentials()
{
    // Load saved credentials from settings
    QSettings settings;
    QString hostname = settings.value("hostname").toString();
    QString username = settings.value("username").toString();
    QString password = settings.value("password").toString();

    // Set loaded credentials in line edits
    ui->hostnameLineEdit->setText(hostname);
    ui->usernameLineEdit->setText(username);
    ui->passwordLineEdit->setText(password);
}

void MainWindow::executeCommand(const QString& command)
{
    // Run the command and capture output
    QProcess process;
    QStringList args = command.split(' '); // Split the command into arguments
    process.start(args.takeFirst(), args); // Start with the program name and the remaining arguments
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
