#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QPixmap>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    setWindowTitle("About");
    setFixedSize(width(), height());
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QPixmap pix(":/img/Notepad-DOT-icon.ico");
    ui->icon_pic->setPixmap(pix.scaled(190, 196, Qt::KeepAspectRatio));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_closeButton_clicked()
{
    close();
}
