#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QVector>
#include <QRegularExpression>

class Login;

class User
{
public:
    QString Username;
    QString Email;
    QString Password;

};

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    bool ValidateInput ();
    bool isUserTaken(QString Username);
    void saveUser(User &utilizator);
    void showMessage(const QString &mesaj);
    void loadUsers();
    bool isEmailValid(const QString &email);
    bool isValidPassword(QString &password);
signals:
    void returnToLogin();

private slots:
    void on_SignUp_but_clicked();

    void on_Cancel_but_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

private:
    Ui::SignUp *ui;
    QVector<User> users;
    Login *loginWindow;
};

#endif // SIGNUP_H
