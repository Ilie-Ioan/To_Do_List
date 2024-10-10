#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
    ,loginWindow(loginWindow)
{
    ui->setupUi(this);
    loadUsers();

}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::loadUsers()
{
    QFile file("utilizatori.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        User user;
        QString line = in.readLine();


        if (line.startsWith("Username : "))
        {
            user.Username = line.mid(11).trimmed();
        }


        line = in.readLine();
        if (line.startsWith("Email :"))
        {
            user.Email = line.mid(7).trimmed();
        }


        line = in.readLine();
        if (line.startsWith("Password :"))
        {
            user.Password = line.mid(11).trimmed();
        }

        users.push_back(user);
    }

    file.close();
}

void SignUp::on_SignUp_but_clicked()
{
    if(!ValidateInput())
    {
        return;
    }

    User utilizator_nou;
    utilizator_nou.Username = ui->Username_LineEdit->text();
    utilizator_nou.Email = ui->Email_LineEdit->text();
    utilizator_nou.Password = ui->Password_LineEdit->text();

    if(isUserTaken(utilizator_nou.Username))
    {
        ui->Error_Label->setText("Username already taken");
        return;
    }

    if(!isEmailValid(ui->Email_LineEdit->text()))
    {
        ui->Error_Label->setText("Invalid email format");
        return;
    }
    users.push_back(utilizator_nou);

    saveUser(utilizator_nou);

    showMessage("User registered successfully.");

    this->accept();
    emit returnToLogin();



}

bool SignUp::ValidateInput()
{
    if(ui->Username_LineEdit->text().isEmpty() || ui->Email_LineEdit->text().isEmpty() || ui->Password_LineEdit->text().isEmpty() || ui->Confirm_LineEdit->text().isEmpty())
    {
        ui->Error_Label->setText("Please fill all the fields");
         return false;
    }
    else
        if(ui->Password_LineEdit->text() != ui->Confirm_LineEdit->text())
        {
            ui->Error_Label->setText("Passwords do not match");
            return false;
        }
    return true;

}

bool SignUp::isUserTaken(const QString username)
{
    for(const User &user : users)
    {
        if(user.Username ==  username)
        {

            return true;
        }
    }
    return false;
}

bool SignUp::isEmailValid(const QString &email)
{
    QRegularExpression regex(R"((\w+)(\.{1}|\w+)*@(\w+)(\.\w+)+)");
    return regex.match(email).hasMatch();
}


bool SignUp::isValidPassword(QString &password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUpper = false;

    bool hasSpecial = false;

    bool hasDigit = false;

    for (const QChar &c : password) {
        if (c.isUpper()) {
            hasUpper = true;
        }
        if (c.isDigit()) {
            hasDigit = true;
        }
        if (!c.isLetterOrNumber()) {
            hasSpecial = true;
        }
    }

    return hasUpper && hasSpecial && hasDigit;
}

void SignUp::showMessage(const QString &mesaj)
{
    QMessageBox msgBox;
    msgBox.setText(mesaj);
    msgBox.setStyleSheet("QMessageBox { background-color: #f5f5f5; }"
                         "QMessageBox QLabel { color: #333; }"
                         "QPushButton { background-color: #007BFF; color: white; border: none; border-radius: 5px; padding: 10px; }"
                         "QPushButton:hover { background-color: #0056b3; }");

    msgBox.exec();
}

void SignUp::saveUser(User &utilizator)
{
    QFile file("utilizatori.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        ui->Error_Label->setText("Unable to open the file: " + file.errorString());
        return;
    }

    QTextStream out(&file);
    out<<"Username : "<<utilizator.Username<<"\n";
    out<<"Email : "<<utilizator.Email<<"\n";
    out <<"Password : "<<utilizator.Password<<"\n";

    file.close();
}

void SignUp::on_Cancel_but_clicked()
{
    emit returnToLogin();
    this->reject();

}

void SignUp::on_checkBox_stateChanged(int state)
{
    ui->Password_LineEdit->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}

void SignUp::on_checkBox_2_stateChanged(int state)
{
    ui->Confirm_LineEdit->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}

