#include "discorddialog.h"
#include "ui_discorddialog.h"

discorddialog::discorddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discorddialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Discord support");
    setFixedSize(width(), height());
}

discorddialog::~discorddialog()
{
    delete ui;
}

void discorddialog::on_closeButton_clicked()
{
    this->close();
}
