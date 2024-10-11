#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add)
{
    ui->setupUi(this);
    ui->priority_combo->addItem("Select Priority");
    ui->priority_combo->addItem("High");
    ui->priority_combo->addItem("Medium");
    ui->priority_combo->addItem("Low");
    ui->date_edit->setDate(QDate::currentDate());
}

add::~add()
{
    delete ui;
}

void add::on_add_butt_clicked()
{
    QString title = ui->Text_lineEdit->text().trimmed();
    QString description = ui->description_edit->toPlainText().trimmed();
    QString dueDate = ui->date_edit->text();
    QString priority = ui->priority_combo->currentText();


    ui->error_label->clear();
    ui->error_label->setVisible(false);

    if(title.isEmpty())
    {
        ui->error_label->setText("Please enter a task titile");
        ui->error_label->setVisible(true);
        ui->Text_lineEdit->setFocus();
        return;

    }
    if(description.isEmpty())
    {
        ui->error_label->setText("Please enter a task description");
        ui->error_label->setVisible(true);
        ui->description_edit->setFocus();
        return;
    }
    if(dueDate.isEmpty())
    {
        ui->error_label->setText("Please select a date");
        ui->error_label->setVisible(true);
        ui->date_edit->setFocus();
        return;
    }
    if (priority == "Select Priority") {
        ui->error_label->setText("Not selected. Please select a priority.");
        ui->error_label->setVisible(true);
        return;
    }
    QString filename = currentUsername +"_task.txt";
    QFile file(filename);
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        ui->error_label->setText("Could not open tasks file for writing.");
        ui->error_label->setVisible(true);
        return;
    }
    QTextStream out(&file);
    out << "Task: " << title << "\n"
        << "Description: " << description << "\n"
        << "Due Date: " << dueDate << "\n"
        << "Priority: " << priority << "\n"
        << "-----------------------------------\n";
    file.close();

    ui->Text_lineEdit->clear();
    ui->description_edit->clear();
    ui->date_edit->clear();
    ui->priority_combo->setCurrentIndex(0);

    ui->error_label->setVisible(false);

    ui->error_label->setText("Task added successfully!");
    ui->error_label->setStyleSheet("color: green;");
    ui->error_label->setVisible(true);

    QMessageBox::information(this, "Success", "Task added successfully.", QMessageBox::Ok);
    this->accept();



}
void add::setUsername(QString &username) {
    currentUsername = username;
}
void add::resed_fields()
{
    ui->Text_lineEdit->clear();
    ui->description_edit->clear();
    ui->date_edit->clear();
    ui->priority_combo->setCurrentIndex(0);
    ui->error_label->clear();
     ui->error_label->setVisible(false);
}


void add::on_close_butt_clicked()
{
    emit returnToToDo();
    this->hide();
}
