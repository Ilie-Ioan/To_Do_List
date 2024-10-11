#ifndef TO_DO_H
#define TO_DO_H

#include <QDialog>
#include "add.h"

namespace Ui {
class To_Do;
}

class To_Do : public QDialog
{
    Q_OBJECT

public:
    explicit To_Do(QWidget *parent = nullptr);
    ~To_Do();
    void set_Username(QString &username);
    void loadTasksForUser(const QString &username);

signals:
    void returnToLogin();
private slots:
    void on_exit_but_clicked();

    void on_sign_button_clicked();

    void on_add_but_clicked();

    void on_refresh_but_clicked();

private:
    Ui::To_Do *ui;
    add *addWindow;


};

#endif // TO_DO_H
