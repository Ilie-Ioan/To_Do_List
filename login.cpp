#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->Error_label->setVisible(false);
    signUpForm = new SignUp(this);
    connect(signUpForm, &SignUp::returnToLogin, this, [this](){
        clearError();
        this->show();
        signUpForm->hide();

    });
    ui->Error_label->clear();
    toDoWindow = new To_Do(this);
    connect(toDoWindow,&To_Do::returnToLogin,this,[this](){
        this->show();
        toDoWindow->hide();


    });

}

Login::~Login()
{
    delete ui;
}

void Login::on_SignUp_but_clicked()
{
    signUpForm->show();
    this->hide();
}


void Login::on_Exit_but_clicked()
{
    QApplication::exit();

}


void Login::on_checkBox_stateChanged(int state)
{
    ui->Password_LineEdit->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}


void Login::on_Login_but_clicked()
{
    QString username = ui->Usename_LineEdit->text().trimmed();
    QString password = ui->Password_LineEdit->text().trimmed();
    //qDebug() << "Username entered:" << username;
    //qDebug() << "Password entered:" << password;
     if (isValidCredentials(username, password))
    {
        toDoWindow->set_Username(username);
        showMessage("User logged successfully.");
        toDoWindow->show();
        this->hide();

     }
     else
     {
          setError("Invalid username or password.");
          ui->Usename_LineEdit->clear();
          ui->Password_LineEdit->clear();
          ui->Usename_LineEdit->setFocus();

     }

}
bool Login::isValidCredentials(const QString &username, const QString &password) {
    QFile file("utilizatori.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false; // Nu s-a putut deschide fișierul
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.startsWith("Username : ")) {
            QString storedUsername = line.mid(11).trimmed();
            // qDebug() <<"Stored username is "<<storedUsername<<"\n";
            QString storedPassword;

            line = in.readLine();

            line = in.readLine();

            if (line.startsWith("Password : ")) {
                storedPassword = line.mid(11).trimmed();
               // qDebug() <<"Stored password is "<<storedPassword<<"\n";
            }


            if (username == storedUsername && password == storedPassword) {
                return true;
            }
        }
    }

    return false;
}
void Login::clearError() {
    ui->Error_label->clear();
    ui->Error_label->setVisible(false);
}
void Login::setError(const QString &message) {
    ui->Error_label->setText(message);
    ui->Error_label->setVisible(true);
}
void Login::showMessage(const QString &mesaj)
{
    QMessageBox msgBox;
    msgBox.setText(mesaj);
    msgBox.setStyleSheet("QMessageBox { background-color: #f5f5f5; }"
                         "QMessageBox QLabel { color: #333; }"
                         "QPushButton { background-color: #007BFF; color: white; border: none; border-radius: 5px; padding: 10px; }"
                         "QPushButton:hover { background-color: #0056b3; }");

    msgBox.exec();
}
