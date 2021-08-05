#include "discorddialog.h"
#include "ui_discorddialog.h"

discorddialog::discorddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discorddialog)
{
    ui->setupUi(this);
    setWindowTitle("Discord support");
    setFixedSize(width(), height());
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

discorddialog::~discorddialog()
{
    delete ui;
}

void discorddialog::on_closeButton_clicked()
{
    close();
}
