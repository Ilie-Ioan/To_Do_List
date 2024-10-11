#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "signup.h"
#include "to_do.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_SignUp_but_clicked();

    void on_Exit_but_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_Login_but_clicked();



private:
    Ui::Login *ui;
    SignUp *signUpForm;
    To_Do *toDoWindow;
    bool isValidCredentials(const QString &username, const QString &password);
    void clearError();
    void setError(const QString &message);
    void showMessage(const QString &mesaj);
};
#endif // LOGIN_H
