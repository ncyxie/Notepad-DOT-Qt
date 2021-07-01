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
    this->setWindowTitle("Untitled - Notepad DOT Qt");
    fileText = ui->textEdit->toPlainText();
    ui->action_Word_Wrap->setCheckable(true);
    ui->action_Vertical->setCheckable(true);
    ui->action_Horizontal->setCheckable(true);
    ui->action_Both->setCheckable(true);
    ui->action_None->setCheckable(true);
    ui->action_Both->setChecked(true);
    ui->action_Box->setCheckable(true);
    ui->action_Panel->setCheckable(true);
    ui->action_Win_Panel->setCheckable(true);
    ui->action_Styled_Panel->setCheckable(true);
    ui->action_No_Frame->setCheckable(true);
    ui->action_Styled_Panel->setChecked(true);

    QStringList arguments = QCoreApplication::arguments();
        if(arguments.length() > 1)
        {
            outsideFileName = arguments[1];
            this->outsideNotepadOpen();
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
    if (fileText != ui->textEdit->toPlainText())
    {
        if (isFresh == false)
        {
            this->setWindowTitle("*" + currentFile + " - Notepad DOT Qt");
        }
        else
        {
            this->setWindowTitle("*Untitled - Notepad DOT Qt");
        }
    }
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if (fileText != ui->textEdit->toPlainText())
    {
        if (isFresh == false)
        {
            QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Exit", "Do you want to save changes to " + currentFile + "?\n",
                                                                    QMessageBox::No | QMessageBox::Yes | QMessageBox::Cancel,
                                                                    QMessageBox::Cancel);

            if (resBtn == QMessageBox::No) {
                event->accept();
            } else if (resBtn == QMessageBox::Cancel) {
                event->ignore();
            }
            else if (resBtn == QMessageBox::Yes) {
                on_action_Save_triggered();
            }
        }
        else
        {
            QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Exit", "Do you want to save changes to Untitled?\n",
                                                                    QMessageBox::No | QMessageBox::Yes | QMessageBox::Cancel,
                                                                    QMessageBox::Cancel);

            if (resBtn == QMessageBox::No) {
                event->accept();
            } else if (resBtn == QMessageBox::Cancel) {
                event->ignore();
            }
            else if (resBtn == QMessageBox::Yes) {
                on_action_Save_As_triggered();
            }
        }
    }
}

void MainWindow::outsideNotepadOpen()
{
    if(!outsideFileName.isEmpty())
    {
            QFile *file = new QFile;
            file->setFileName(outsideFileName);
            currentFile = outsideFileName;

            bool isOpen = file->open(QIODevice::ReadOnly);
            if(isOpen)
            {
                ui->textEdit->clear();
                QTextStream in(file);

                while (!in.atEnd())
                {
                    ui->textEdit->append(in.readLine());
                    ui->textEdit->moveCursor(QTextCursor::End);
                }

                ui->textEdit->document()->toPlainText();
                this->setWindowTitle(currentFile + " - Notepad DOT Qt");
                file->close();
                isFresh = false;
                fileText = ui->textEdit->toPlainText();
            }
    }
}

void MainWindow::on_action_New_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
    this->setWindowTitle("Untitled - Notepad DOT Qt");
    isFresh = true;
}

void MainWindow::on_action_Open_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file", QDir::currentPath(), tr("Text Documents (*.txt)(*.txt);;All files (*.*)(*)"));
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    ui->textEdit->setTextCursor(cursor);
    this->setWindowTitle(currentFile + " - Notepad DOT Qt");
    file.close();
    isFresh = false;
    fileText = ui->textEdit->toPlainText();
}

void MainWindow::on_action_Save_triggered()
{
    QString fileName;

        if (currentFile.isEmpty()) {
            fileName = QFileDialog::getSaveFileName(this,"Save File", QDir::currentPath(), tr("Text Documents (*.txt)(*.txt);;All files (*.*)(*)"));
            currentFile = fileName;
        } else {
            fileName = currentFile;
        }
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
            return;
        }
        this->setWindowTitle(currentFile + " - Notepad DOT Qt");
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
        isFresh = false;
        fileText = ui->textEdit->toPlainText();
}

void MainWindow::on_action_Save_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save File", QDir::currentPath(), tr("Text Documents (*.txt)(*.txt);;All files (*.*)(*)"));
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return;
    }
    currentFile = fileName;
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    this->setWindowTitle(currentFile + " - Notepad DOT Qt");
    file.close();
    isFresh = false;
    fileText = ui->textEdit->toPlainText();
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
        QColor color = QColorDialog::getColor(ui->textEdit->textColor());
        if (color.isValid())
        {
            ui->textEdit->selectAll();
            ui->textEdit->setTextColor(color);
            ui->textEdit->setTextCursor(cursor);
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(ui->textEdit->textColor());
        if (color.isValid())
        {
            ui->textEdit->setTextColor(color);
        }
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

void MainWindow::on_action_Uppercase_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if (cursor.hasSelection()) {
        QString newText = cursor.selectedText().toUpper();
        cursor.insertText(newText);
    }
}

void MainWindow::on_action_Lowercase_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if (cursor.hasSelection()) {
        QString newText = cursor.selectedText().toLower();
        cursor.insertText(newText);
    }
}

void MainWindow::on_action_menubar_Appearance_triggered()
{
    if (menubarbcolor != "")
    {
        QColor color = QColorDialog::getColor(menubarbcolor, this);

        if (color.isValid())
        {
            menubarbcolor = color.name();

            if (menubarfcolor != "")
            {
                ui->menubar->setStyleSheet("background-color: " + color.name() + ";" + "color: " + menubarfcolor + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("background-color: " + color.name() + ";");
            }
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(Qt::white, this);

        if (color.isValid())
        {
            menubarbcolor = color.name();

            if (menubarfcolor != "")
            {
                ui->menubar->setStyleSheet("background-color: " + color.name() + ";" + "color: " + menubarfcolor + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("background-color: " + color.name() + ";");
            }
        }
    }
}

void MainWindow::on_action_menubar_Font_triggered()
{
    ui->menubar->setFont(QFontDialog::getFont(nullptr,ui->menubar->font(),this));
}

void MainWindow::on_action_menubar_Font_Color_triggered()
{
    if (menubarfcolor != "")
    {
        QColor color = QColorDialog::getColor(menubarfcolor, this);

        if (color.isValid())
        {
            menubarfcolor = color.name();

            if (menubarbcolor != "")
            {
                ui->menubar->setStyleSheet("background-color: " + menubarbcolor + ";" + "color: " + color.name() + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("color: " + color.name() + ";");
            }
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(Qt::black, this);

        if (color.isValid())
        {
            menubarfcolor = color.name();

            if (menubarbcolor != "")
            {
                ui->menubar->setStyleSheet("background-color: " + menubarbcolor + ";" + "color: " + color.name() + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("color: " + color.name() + ";");
            }
        }
    }
}

void MainWindow::on_action_textEdit_Appearance_triggered()
{
    if (texteditbcolor != "")
    {
        QColor color = QColorDialog::getColor(texteditbcolor, this);

        if (color.isValid())
        {
            texteditbcolor = color.name();
            ui->textEdit->setStyleSheet("background-color: " + color.name());
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(Qt::white, this);

        if (color.isValid())
        {
            texteditbcolor = color.name();
            ui->textEdit->setStyleSheet("background-color: " + color.name());
        }
    }
}

void MainWindow::on_action_widget_Appearance_triggered()
{
    if (widgetbcolor != "")
    {
        QColor color = QColorDialog::getColor(widgetbcolor, this);

        if (color.isValid())
        {
            widgetbcolor = color.name();

            setStyleSheet("background-color: " + color.name() + ";");
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(Qt::white, this);

        if (color.isValid())
        {
            widgetbcolor = color.name();

            setStyleSheet("background-color: " + color.name() + ";");
        }
    }
}

void MainWindow::on_action_widget_Appearance_Reset_to_default_triggered()
{
    setStyleSheet("");
}

void MainWindow::on_action_menubar_Appearance_Reset_to_default_triggered()
{
    menubarbcolor = "";

    if (menubarfcolor != "")
    {
        ui->menubar->setStyleSheet("color: " + menubarfcolor + ";");
    }
    else
    {
        ui->menubar->setStyleSheet("");
    }
}

void MainWindow::on_action_textEdit_Reset_to_default_triggered()
{
    ui->textEdit->setStyleSheet("");
    texteditbcolor = "";
}

void MainWindow::on_action_Word_Wrap_triggered()
{
    if (ui->action_Word_Wrap->isChecked())
    {
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);

        if (ui->action_Horizontal->isChecked())
        {
            ui->action_Horizontal->setChecked(false);
            ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            ui->action_None->setChecked(true);
        }

        if (ui->action_Both->isChecked())
        {
            ui->action_Both->setChecked(false);
            ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
            ui->action_Vertical->setChecked(true);
        }

        ui->action_Horizontal->setEnabled(false);
        ui->action_Both->setEnabled(false);
    }
    else
    {
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
        ui->action_Horizontal->setEnabled(true);
        ui->action_Both->setEnabled(true);
    }
}

void MainWindow::on_action_Vertical_triggered()
{
    ui->action_Vertical->setChecked(true);
    ui->action_Horizontal->setChecked(false);
    ui->action_Both->setChecked(false);
    ui->action_None->setChecked(false);
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void MainWindow::on_action_Horizontal_triggered()
{
    ui->action_Horizontal->setChecked(true);
    ui->action_Vertical->setChecked(false);
    ui->action_Both->setChecked(false);
    ui->action_None->setChecked(false);
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindow::on_action_Both_triggered()
{
    ui->action_Both->setChecked(true);
    ui->action_Vertical->setChecked(false);
    ui->action_Horizontal->setChecked(false);
    ui->action_None->setChecked(false);
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void MainWindow::on_action_None_triggered()
{
    ui->action_None->setChecked(true);
    ui->action_Vertical->setChecked(false);
    ui->action_Horizontal->setChecked(false);
    ui->action_Both->setChecked(false);
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindow::on_action_Box_triggered()
{
    ui->action_Box->setChecked(true);
    ui->action_Panel->setChecked(false);
    ui->action_Win_Panel->setChecked(false);
    ui->action_Styled_Panel->setChecked(false);
    ui->action_No_Frame->setChecked(false);
    ui->textEdit->setFrameShape(QFrame::Box);
}

void MainWindow::on_action_Panel_triggered()
{
    ui->action_Panel->setChecked(true);
    ui->action_Box->setChecked(false);
    ui->action_Win_Panel->setChecked(false);
    ui->action_Styled_Panel->setChecked(false);
    ui->action_No_Frame->setChecked(false);
    ui->textEdit->setFrameShape(QFrame::Panel);
}

void MainWindow::on_action_Win_Panel_triggered()
{
    ui->action_Win_Panel->setChecked(true);
    ui->action_Panel->setChecked(false);
    ui->action_Box->setChecked(false);
    ui->action_Styled_Panel->setChecked(false);
    ui->action_No_Frame->setChecked(false);
    ui->textEdit->setFrameShape(QFrame::WinPanel);
}

void MainWindow::on_action_Styled_Panel_triggered()
{
    ui->action_Styled_Panel->setChecked(true);
    ui->action_Win_Panel->setChecked(false);
    ui->action_Panel->setChecked(false);
    ui->action_Box->setChecked(false);
    ui->action_No_Frame->setChecked(false);
    ui->textEdit->setFrameShape(QFrame::StyledPanel);
}

void MainWindow::on_action_No_Frame_triggered()
{
    ui->action_No_Frame->setChecked(true);
    ui->action_Styled_Panel->setChecked(false);
    ui->action_Win_Panel->setChecked(false);
    ui->action_Panel->setChecked(false);
    ui->action_Box->setChecked(false);
    ui->textEdit->setFrameShape(QFrame::NoFrame);
}
