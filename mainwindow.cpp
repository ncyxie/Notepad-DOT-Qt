#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <QCloseEvent>
#include <QFontDialog>
#include <QColorDialog>
#include <QTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Untitled - Notepad DOT");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit",
                                                                tr("Are you sure you want to exit application?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}


void MainWindow::on_action_New_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
    this->setWindowTitle("Untitled - Notepad DOT");
}

void MainWindow::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    this->setWindowTitle(currentFile + " - Notepad DOT");
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_action_Save_triggered()
{
    QString fileName;

        if (currentFile.isEmpty()) {
            fileName = QFileDialog::getSaveFileName(this, "Save");
            currentFile = fileName;
        } else {
            fileName = currentFile;
        }
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
            return;
        }
        this->setWindowTitle(currentFile + " - Notepad DOT");
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
}

void MainWindow::on_action_Save_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    this->setWindowTitle(currentFile + " - Notepad DOT");
    file.close();
}

void MainWindow::on_action_Paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_Redo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_action_About_triggered()
{
    aboutdialog = new AboutDialog(this);
    aboutdialog->show();
}

void MainWindow::on_action_Exit_triggered()
{
    QWidget::close();
}

void MainWindow::on_action_Font_triggered()
{
    ui->textEdit->setFont(QFontDialog::getFont(nullptr,ui->textEdit->font(),this));
}

void MainWindow::on_action_Color_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QString text = ui->textEdit->toPlainText();

    if (text != "")
    {
        ui->textEdit->selectAll();
        ui->textEdit->setTextColor(QColorDialog::getColor(ui->textEdit->textColor(),this));
        ui->textEdit->setTextCursor( cursor );
    }
    else
    {
        ui->textEdit->setTextColor(QColorDialog::getColor(ui->textEdit->textColor(),this));
    }

}

void MainWindow::on_action_Delete_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
        if(cursor.hasSelection()) {
            cursor.deleteChar();
        }
}

void MainWindow::on_action_Select_All_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        return;
    }
    ui->textEdit->print(&printer);
}

void MainWindow::on_action_GitHub_repository_triggered()
{
    QString link = "https://github.com/ncyxie/Notepad-DOT-Qt";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_action_GitHub_releases_triggered()
{
    QString link = "https://github.com/ncyxie/Notepad-DOT-Qt/releases";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_action_Telegram_support_triggered()
{
    QString link = "https://t.me/ncyxie";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_action_Search_with_Google_triggered()
{
    QTextCursor cursor= ui->textEdit->textCursor();
        if(cursor.hasSelection()) {
            QString link = "https://www.google.com/search?q=" + cursor.selectedText();
            QDesktopServices::openUrl(QUrl(link));
        }
}

void MainWindow::on_action_Search_with_Bing_triggered()
{
    QTextCursor cursor= ui->textEdit->textCursor();
        if(cursor.hasSelection()) {
            QString link = "https://www.bing.com/search?q=" + cursor.selectedText();
            QDesktopServices::openUrl(QUrl(link));
        }
}

void MainWindow::on_action_Search_with_DuckDuckGo_triggered()
{
    QTextCursor cursor= ui->textEdit->textCursor();
        if(cursor.hasSelection()) {
            QString link = "https://duckduckgo.com/?q=" + cursor.selectedText();
            QDesktopServices::openUrl(QUrl(link));
        }
}

void MainWindow::on_action_Search_with_Yahoo_triggered()
{
    QTextCursor cursor= ui->textEdit->textCursor();
        if(cursor.hasSelection()) {
            QString link = "https://search.yahoo.com/search?p=" + cursor.selectedText();
            QDesktopServices::openUrl(QUrl(link));
        }
}

void MainWindow::on_action_New_Window_triggered()
{
    MainWindow *newWindow = new MainWindow();
    newWindow->show();
}

void MainWindow::on_action_Date_Time_triggered()
{
    dateTime = QDateTime::currentDateTime();
    QString str = dateTime.toString();
    ui->textEdit->insertPlainText(str);
}

void MainWindow::on_action_Discord_support_triggered()
{
    ddialog = new discorddialog(this);
    ddialog->show();
}

void MainWindow::on_action_Appearance_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this);

    if (color.isValid())
    {
        QPalette p = ui->textEdit->palette();
        p.setColor(QPalette::Base, color);
        ui->textEdit->setPalette(p);
    }
    else
    {
        return;
    }
}
