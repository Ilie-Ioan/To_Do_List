#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDate>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();
    void setUsername(QString &username);
signals:
    void taskAdded();
    void returnToToDo();
private slots:
    void on_add_butt_clicked();
    void on_close_butt_clicked();

public slots:
    void resed_fields();

private:
    Ui::add *ui;
    QString currentUsername;
};

#endif // ADD_H
