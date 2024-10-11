#include "to_do.h"
#include "ui_to_do.h"

To_Do::To_Do(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::To_Do)
{
    ui->setupUi(this);
    addWindow = new add(this);
    connect(ui->add_but, &QPushButton::clicked, this, &To_Do::on_add_but_clicked);


}

To_Do::~To_Do()
{
    delete ui;
}

void To_Do::on_exit_but_clicked()
{
    QApplication::exit();

}


void To_Do::on_sign_button_clicked()
{
    emit returnToLogin();
}
void To_Do::set_Username(QString &username)
{
    ui->User_label->setText("Logged in as: " + username);
    loadTasksForUser(username);
}

void To_Do::loadTasksForUser(const QString &username)
{
    QString filename = username + "_task.txt";
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open task file for reading.");
        return;
    }

    ui->Task_List->clear();

    QTextStream in(&file);
    QString line;
    QList<QString> tasks;

    while (!in.atEnd()) {
        line = in.readLine();
        if (line.isEmpty() || line == "-----------------------------------") {
            continue;
        }

        QString title, description, date, priority;

        title = line;
        description = in.readLine();
        date = in.readLine();
        priority = in.readLine();

        QString taskString = QString("Title: %1 | Description: %2 | Date: %3 | Priority: %4")
                                 .arg(title, description, date, priority);

        tasks.append(taskString);
    }

    std::sort(tasks.begin(), tasks.end(), [](const QString &a, const QString &b) {
        QString priorityA = a.section('|', 3, 3).trimmed().split(" ").last();
        QString priorityB = b.section('|', 3, 3).trimmed().split(" ").last();
        return priorityA < priorityB;
    });

    for (const QString &task : tasks) {
        ui->Task_List->addItem(task);
    }

    file.close();
}

void To_Do::on_add_but_clicked()
{
    QString username = ui->User_label->text().mid(14);
    addWindow->setUsername(username);
    addWindow->resed_fields();
    connect(addWindow, &add::accepted, this, [this]() {
        this->show();
    });
    connect(addWindow, &add::returnToToDo, this, [this]() {
        this->show();
    });

    addWindow->show();
    this->hide();
}


void To_Do::on_refresh_but_clicked()
{
    QString username = ui->User_label->text().mid(14);
    loadTasksForUser(username);

}

