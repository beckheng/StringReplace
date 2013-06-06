#include "dialog.h"
#include "ui_dialog.h"

#include <QRegularExpression>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->ui->plainTextEdit_src->setFocus();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_replace_clicked()
{
    this->ui->label_tips->setText(QString("查找中:%1").arg(this->ui->lineEdit_search->text()));

    QString destText = this->ui->plainTextEdit_src->toPlainText();

    destText.replace(QRegularExpression(this->ui->lineEdit_search->text()), this->ui->lineEdit_replace->text());

    this->ui->plainTextEdit_dest->setPlainText(destText);

    this->ui->label_tips->setText(QString("替换完成!"));
}
