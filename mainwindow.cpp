#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QFile>
#include <QLabel>
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
    ui->action_statusBar_On->setCheckable(true);
    ui->action_statusBar_Off->setCheckable(true);
    ui->action_statusBar_Off->setChecked(true);
    ui->action_Word_Counter_On->setCheckable(true);
    ui->action_Word_Counter_Off->setCheckable(true);
    ui->action_Word_Counter_Off->setChecked(true);
    ui->action_Character_Counter_On->setCheckable(true);
    ui->action_Character_Counter_Off->setCheckable(true);
    ui->action_Character_Counter_Off->setChecked(true);
    ui->action_Lines_Counter_On->setCheckable(true);
    ui->action_Lines_Counter_Off->setCheckable(true);
    ui->action_Lines_Counter_Off->setChecked(true);

    ui->action_statusBar_On->setChecked(false);
    ui->action_statusBar_Off->setChecked(true);
    ui->action_Word_Counter_On->setDisabled(true);
    ui->action_Word_Counter_Off->setDisabled(true);
    ui->action_Character_Counter_On->setDisabled(true);
    ui->action_Character_Counter_Off->setDisabled(true);
    ui->action_Lines_Counter_On->setDisabled(true);
    ui->action_Lines_Counter_Off->setDisabled(true);
    ui->action_statusBar_Font->setDisabled(true);
    ui->action_statusBar_Font_Color->setDisabled(true);
    ui->action_statusBar_Appearance->setDisabled(true);
    ui->action_statusBar_Reset_to_default->setDisabled(true);
    ui->statusbar->hide();

    wordCountLabel = new QLabel(this);
    charCountLabel = new QLabel(this);
    linesCountLabel = new QLabel(this);

    ui->statusbar->addPermanentWidget(wordCountLabel, 1);
    ui->statusbar->addPermanentWidget(charCountLabel, 15);
    ui->statusbar->addPermanentWidget(linesCountLabel, 300);

    QStringList arguments = QCoreApplication::arguments();
        if(arguments.length() > 1)
        {
            outsideFileName = arguments[1];
            this->outsideNotepadOpen();
        }

    LoadSettings();

    QColor textfcolor = ui->textEdit->textColor();
    textfontcolor = textfcolor.name();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SaveSettings()
{
    QSettings setting("ncyxie", "Notepad-DOT-Qt");

    setting.beginGroup("MainWindow");
    setting.setValue("geometry", saveGeometry());
    setting.setValue("windowState", saveState());
    setting.endGroup();

    setting.beginGroup("Widget");
    setting.setValue("widget.stylesheet", styleSheet());
    setting.setValue("widgetbcolor", widgetbcolor);
    setting.endGroup();

    setting.beginGroup("TextEdit");
    setting.setValue("textedit.word.wrap", ui->action_Word_Wrap->isChecked());
    setting.setValue("textedit.stylesheet", ui->textEdit->styleSheet());
    setting.setValue("textedit.font.color", ui->textEdit->textColor());
    setting.setValue("textedit.frame.shape.box", ui->action_Box->isChecked());
    setting.setValue("textedit.frame.shape.panel", ui->action_Panel->isChecked());
    setting.setValue("textedit.frame.shape.win.panel", ui->action_Win_Panel->isChecked());
    setting.setValue("textedit.frame.shape.styled.panel", ui->action_Styled_Panel->isChecked());
    setting.setValue("textedit.frame.shape.no.frame", ui->action_No_Frame->isChecked());
    setting.setValue("textedit.scroll.bar.vertical", ui->action_Vertical->isChecked());
    setting.setValue("textedit.scroll.bar.horizontal", ui->action_Horizontal->isChecked());
    setting.setValue("textedit.scroll.bar.both", ui->action_Both->isChecked());
    setting.setValue("textedit.scroll.bar.none", ui->action_None->isChecked());
    setting.setValue("tfontfamily", tfontfamily);
    setting.setValue("tfontsize", tfontsize);
    setting.setValue("tfontweight", tfontweight);
    setting.setValue("tfontstyle", tfontstyle);
    setting.setValue("tfontdecoration", tfontdecoration);
    setting.setValue("texteditbcolor", texteditbcolor);
    setting.endGroup();

    setting.beginGroup("MenuBar");
    setting.setValue("menubar.stylesheet", ui->menubar->styleSheet());
    setting.setValue("mfontfamily", mfontfamily);
    setting.setValue("mfontsize", mfontsize);
    setting.setValue("mfontweight", mfontweight);
    setting.setValue("mfontstyle", mfontstyle);
    setting.setValue("mfontdecoration", mfontdecoration);
    setting.setValue("menubarbcolor", menubarbcolor);
    setting.setValue("menubarfcolor", menubarfcolor);
    setting.endGroup();

    setting.beginGroup("StatusBar");
    setting.setValue("statusbar.on", ui->action_statusBar_On->isChecked());
    setting.setValue("statusbar.off", ui->action_statusBar_Off->isChecked());
    setting.setValue("statusbar.stylesheet", ui->statusbar->styleSheet());
    setting.setValue("statusbar.word.counter.on", ui->action_Word_Counter_On->isChecked());
    setting.setValue("statusbar.word.counter.off", ui->action_Word_Counter_Off->isChecked());
    setting.setValue("statusbar.char.counter.on", ui->action_Character_Counter_On->isChecked());
    setting.setValue("statusbar.char.counter.off", ui->action_Character_Counter_Off->isChecked());
    setting.setValue("statusbar.lines.counter.on", ui->action_Lines_Counter_On->isChecked());
    setting.setValue("statusbar.lines.counter.off", ui->action_Lines_Counter_Off->isChecked());

    setting.endGroup();
}

void MainWindow::LoadSettings()
{
    QSettings setting("ncyxie", "Notepad-DOT-Qt");

    setting.beginGroup("MainWindow");
    restoreGeometry(setting.value("geometry").toByteArray());
    restoreState(setting.value("windowState").toByteArray());
    setting.endGroup();

    setting.beginGroup("Widget");
    QString widgetstylesheet = setting.value("widget.stylesheet").toString();
    setStyleSheet(widgetstylesheet);
    widgetbcolor = setting.value("widgetbcolor").toString();
    setting.endGroup();

    setting.beginGroup("TextEdit");
    bool wordwrapchecked = setting.value("textedit.word.wrap").toBool();

    if (wordwrapchecked == true)
    {
        ui->action_Word_Wrap->setChecked(true);
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
        ui->action_Word_Wrap->setChecked(false);
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
        ui->action_Horizontal->setEnabled(true);
        ui->action_Both->setEnabled(true);
    }


    QString texteditstylesheet = setting.value("textedit.stylesheet").toString();
    ui->textEdit->setStyleSheet(texteditstylesheet);
    QString texteditfontcolor = setting.value("textedit.font.color").toString();
    ui->textEdit->setTextColor(texteditfontcolor);

    bool isframeboxchecked = setting.value("textedit.frame.shape.box").toBool();

    if (isframeboxchecked == true)
    {
        on_action_Box_triggered();
    }

    bool isframepanelchecked = setting.value("textedit.frame.shape.panel").toBool();

    if (isframepanelchecked == true)
    {
        on_action_Panel_triggered();
    }

    bool isframewinpanelchecked = setting.value("textedit.frame.shape.win.panel").toBool();

    if (isframewinpanelchecked == true)
    {
        on_action_Win_Panel_triggered();
    }

    bool isframestyledpanelchecked = setting.value("textedit.frame.shape.styled.panel").toBool();

    if (isframestyledpanelchecked == true)
    {
        on_action_Styled_Panel_triggered();
    }

    bool isframenoframechecked = setting.value("textedit.frame.shape.no.frame").toBool();

    if (isframenoframechecked == true)
    {
        on_action_No_Frame_triggered();
    }

    bool scrollbarvertical = setting.value("textedit.scroll.bar.vertical").toBool();

    if (scrollbarvertical == true)
    {
        on_action_Vertical_triggered();
    }

    bool scrollbarhorizontal = setting.value("textedit.scroll.bar.horizontal").toBool();

    if (scrollbarhorizontal == true)
    {
        on_action_Horizontal_triggered();
    }

    bool scrollbarboth = setting.value("textedit.scroll.bar.both").toBool();

    if (scrollbarboth == true)
    {
        on_action_Both_triggered();
    }

    bool scrollbarnone = setting.value("textedit.scroll.bar.none").toBool();

    if (scrollbarnone == true)
    {
        on_action_None_triggered();
    }
    tfontfamily = setting.value("tfontfamily").toString();
    tfontsize = setting.value("tfontsize").toString();
    tfontweight = setting.value("tfontweight").toString();
    tfontstyle = setting.value("tfontstyle").toString();
    tfontdecoration = setting.value("tfontdecoration").toString();
    texteditbcolor = setting.value("texteditbcolor").toString();
    setting.endGroup();

    setting.beginGroup("MenuBar");
    QString menubarstylesheet = setting.value("menubar.stylesheet").toString();
    ui->menubar->setStyleSheet(menubarstylesheet);
    mfontfamily = setting.value("mfontfamily").toString();
    mfontsize = setting.value("mfontsize").toString();
    mfontweight = setting.value("mfontweight").toString();
    mfontstyle = setting.value("mfontstyle").toString();
    mfontdecoration = setting.value("mfontdecoration").toString();
    menubarbcolor = setting.value("menubarbcolor").toString();
    menubarfcolor = setting.value("menubarfcolor").toString();
    setting.endGroup();

    setting.beginGroup("StatusBar");

    bool statusbaron = setting.value("statusbar.on").toBool();

    if (statusbaron == true)
    {
        on_action_statusBar_On_triggered();
    }

    bool statusbaroff = setting.value("statusbar.off").toBool();

    if (statusbaroff == true)
    {
        on_action_statusBar_Off_triggered();
    }

    QString statusbarstylesheet = setting.value("statusbar.stylesheet").toString();
    ui->statusbar->setStyleSheet(statusbarstylesheet);

    bool statusbarwordcounteron = setting.value("statusbar.word.counter.on").toBool();

    if (statusbarwordcounteron == true)
    {
        on_action_Word_Counter_On_triggered();
    }

    bool statusbarwordcounteroff = setting.value("statusbar.word.counter.off").toBool();

    if (statusbarwordcounteroff == true)
    {
        on_action_Word_Counter_Off_triggered();
    }

    bool statusbarcharcounteron = setting.value("statusbar.char.counter.on").toBool();

    if (statusbarcharcounteron == true)
    {
        on_action_Character_Counter_On_triggered();
    }

    bool statusbarcharcounteroff = setting.value("statusbar.word.counter.off").toBool();

    if (statusbarcharcounteroff == true)
    {
        on_action_Character_Counter_Off_triggered();
    }

    bool statusbarlinescounteron = setting.value("statusbar.lines.counter.on").toBool();

    if (statusbarlinescounteron == true)
    {
        on_action_Lines_Counter_On_triggered();
    }

    bool statusbarlinescounteroff = setting.value("statusbar.lines.counter.off").toBool();

    if (statusbarlinescounteroff == true)
    {
        on_action_Lines_Counter_Off_triggered();
    }
    setting.endGroup();
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
    else
    {
        if (isFresh == false)
        {
            this->setWindowTitle(currentFile + " - Notepad DOT Qt");
        }
        else
        {
            this->setWindowTitle("Untitled - Notepad DOT Qt");
        }
    }

    if (wordsOn == true)
    {
        wordCountLabel->setText(tr("Words: ") + QString::number(ui->textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), Qt::SkipEmptyParts).count()));
    }

    if (charOn == true)
    {
        charCountLabel->setText(tr("Characters: ") + QString::number(ui->textEdit->document()->characterCount() - 1));
    }

    if (linesOn == true)
    {
        QString flags;

        linesCountLabel->setText(tr("Lines: ") + QString::number(ui->textEdit->document()->lineCount()) + flags);
    }

    if (ui->textEdit->toPlainText() == "")
    {
        ui->textEdit->setTextColor(textfontcolor);
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

    SaveSettings();
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
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
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
                fileName = QFileDialog::getSaveFileName(this, "Save");
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
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");
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
    bool ok;
    tfont = QFontDialog::getFont(&ok, ui->textEdit->font(), this);
    if(ok)
    {
        tfontsize = QString::number(tfont.pointSize());

        tfontfamily = tfont.family();
        if (tfont.weight() == 0)
        {
            tfontweight = "100";
        }
        else if (tfont.weight() == 12)
        {
            tfontweight = "200";
        }
        else if (tfont.weight() == 25)
        {
            tfontweight = "300";
        }
        else if (tfont.weight() == 50)
        {
            tfontweight = "400";
        }
        else if (tfont.weight() == 57)
        {
            tfontweight = "500";
        }
        else if (tfont.weight() == 63)
        {
            tfontweight = "600";
        }
        else if (tfont.weight() == 75)
        {
            tfontweight = "700";
        }
        else if (tfont.weight() == 81)
        {
            tfontweight = "800";
        }
        else if (tfont.weight() == 87)
        {
            tfontweight = "900";
        }

        if (tfont.italic() == true)
        {
            tfontstyle = "italic";
        }
        else
        {
            tfontstyle = "normal";
        }

        if (tfont.underline() == true)
        {
            tfontdecoration = "underline";
        }
        else if (tfont.strikeOut() == true)
        {
            tfontdecoration = "line-through";
        }
        else
        {
            tfontdecoration = "none";
        }

            if (texteditbcolor != "")
            {
                ui->textEdit->setStyleSheet("background-color: " + texteditbcolor + "; font-family: " + tfontfamily + "; font-size: " + tfontsize + "pt" + "; font-weight: " + tfontweight + "; font-style: " + tfontstyle + "; text-decoration: " + tfontdecoration + ";");
            }
            else
            {
                ui->textEdit->setStyleSheet("font-family: " + tfontfamily + "; font-size: " + tfontsize + "pt" + "; font-weight: " + tfontweight + "; font-style: " + tfontstyle + "; text-decoration: " + tfontdecoration + ";");
            }
    }
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
                ui->menubar->setStyleSheet("background-color: " + color.name() + "; color: " + menubarfcolor + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("background-color: " + color.name() + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
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
                ui->menubar->setStyleSheet("background-color: " + color.name() + "; color: " + menubarfcolor + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("background-color: " + color.name() + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
            }
        }
    }
}

void MainWindow::on_action_menubar_Font_triggered()
{
    bool ok;
    mfont = QFontDialog::getFont(&ok, ui->menubar->font(), this);
    if(ok)
    {
        mfontsize = QString::number(mfont.pointSize());

        mfontfamily = mfont.family();
        if (mfont.weight() == 0)
        {
            mfontweight = "100";
        }
        else if (mfont.weight() == 12)
        {
            mfontweight = "200";
        }
        else if (mfont.weight() == 25)
        {
            mfontweight = "300";
        }
        else if (mfont.weight() == 50)
        {
            mfontweight = "400";
        }
        else if (mfont.weight() == 57)
        {
            mfontweight = "500";
        }
        else if (mfont.weight() == 63)
        {
            mfontweight = "600";
        }
        else if (mfont.weight() == 75)
        {
            mfontweight = "700";
        }
        else if (mfont.weight() == 81)
        {
            mfontweight = "800";
        }
        else if (mfont.weight() == 87)
        {
            mfontweight = "900";
        }

        if (mfont.italic() == true)
        {
            mfontstyle = "italic";
        }
        else
        {
            mfontstyle = "normal";
        }

        if (mfont.underline() == true)
        {
            mfontdecoration = "underline";
        }
        else if (mfont.strikeOut() == true)
        {
            mfontdecoration = "line-through";
        }
        else
        {
            mfontdecoration = "none";
        }

            if (menubarbcolor != "")
            {
                if (menubarfcolor != "")
                {
                    ui->menubar->setStyleSheet("background-color: " + menubarbcolor + "; color: " + menubarfcolor + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
                }
                else
                {
                    ui->menubar->setStyleSheet("background-color: " + menubarbcolor + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
                }

            }
            else
            {
                if (menubarfcolor != "")
                {
                    ui->menubar->setStyleSheet("color: " + menubarfcolor + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
                }
                else
                {
                    ui->menubar->setStyleSheet("font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
                }
            }
    }
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
                ui->menubar->setStyleSheet("background-color: " + menubarbcolor + + "; color: " + color.name() + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("color: " + color.name() + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
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
                ui->menubar->setStyleSheet("background-color: " + menubarbcolor + + "; color: " + color.name() + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
            }
            else
            {
                ui->menubar->setStyleSheet("color: " + color.name() + "; font-family: " + mfontfamily + "; font-size: " + mfontsize + "pt" + "; font-weight: " + mfontweight + "; font-style: " + mfontstyle + "; text-decoration: " + mfontdecoration + ";");
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

            if (texteditbcolor != "")
            {
                ui->textEdit->setStyleSheet("background-color: " + texteditbcolor + "; font-family: " + tfontfamily + "; font-size: " + tfontsize + "pt" + "; font-weight: " + tfontweight + "; font-style: " + tfontstyle + "; text-decoration: " + tfontdecoration + ";");
            }
            else
            {
                ui->textEdit->setStyleSheet("font-family: " + tfontfamily + "; font-size: " + tfontsize + "pt" + "; font-weight: " + tfontweight + "; font-style: " + tfontstyle + "; text-decoration: " + tfontdecoration + ";");
            }
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(Qt::white, this);

        if (color.isValid())
        {
            texteditbcolor = color.name();
            if (texteditbcolor != "")
            {
                ui->textEdit->setStyleSheet("background-color: " + texteditbcolor + "; font-family: " + tfontfamily + "; font-size: " + tfontsize + "pt" + "; font-weight: " + tfontweight + "; font-style: " + tfontstyle + "; text-decoration: " + tfontdecoration + ";");
            }
            else
            {
                ui->textEdit->setStyleSheet("font-family: " + tfontfamily + "; font-size: " + tfontsize + "pt" + "; font-weight: " + tfontweight + "; font-style: " + tfontstyle + "; text-decoration: " + tfontdecoration + ";");
            }
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
    widgetbcolor = "";
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
        ui->action_Word_Wrap->setChecked(true);
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
        ui->action_Word_Wrap->setChecked(false);
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

void MainWindow::on_action_statusBar_On_triggered()
{
    ui->action_statusBar_On->setChecked(true);
    ui->action_statusBar_Off->setChecked(false);
    ui->action_Word_Counter_On->setEnabled(true);
    ui->action_Word_Counter_Off->setEnabled(true);
    ui->action_Character_Counter_On->setEnabled(true);
    ui->action_Character_Counter_Off->setEnabled(true);
    ui->action_Lines_Counter_On->setEnabled(true);
    ui->action_Lines_Counter_Off->setEnabled(true);
    ui->action_statusBar_Font->setEnabled(true);
    ui->action_statusBar_Font_Color->setEnabled(true);
    ui->action_statusBar_Appearance->setEnabled(true);
    ui->action_statusBar_Reset_to_default->setEnabled(true);
    ui->statusbar->show();
}

void MainWindow::on_action_statusBar_Off_triggered()
{
    ui->action_statusBar_On->setChecked(false);
    ui->action_statusBar_Off->setChecked(true);
    ui->action_Word_Counter_On->setDisabled(true);
    ui->action_Word_Counter_Off->setDisabled(true);
    ui->action_Character_Counter_On->setDisabled(true);
    ui->action_Character_Counter_Off->setDisabled(true);
    ui->action_Lines_Counter_On->setDisabled(true);
    ui->action_Lines_Counter_Off->setDisabled(true);
    ui->action_statusBar_Font->setDisabled(true);
    ui->action_statusBar_Font_Color->setDisabled(true);
    ui->action_statusBar_Appearance->setDisabled(true);
    ui->action_statusBar_Reset_to_default->setDisabled(true);
    ui->statusbar->hide();
}

void MainWindow::on_action_Word_Counter_On_triggered()
{
    ui->action_Word_Counter_On->setChecked(true);
    ui->action_Word_Counter_Off->setChecked(false);
    wordsOn = true;
    wordCountLabel->setText(tr("Words: ") + QString::number(ui->textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), Qt::SkipEmptyParts).count()));
}

void MainWindow::on_action_Word_Counter_Off_triggered()
{
    ui->action_Word_Counter_On->setChecked(false);
    ui->action_Word_Counter_Off->setChecked(true);
    wordsOn = false;
    wordCountLabel->setText("");
}

void MainWindow::on_action_Character_Counter_On_triggered()
{
    ui->action_Character_Counter_On->setChecked(true);
    ui->action_Character_Counter_Off->setChecked(false);
    charOn = true;
    charCountLabel->setText(tr("Characters: ") + QString::number(ui->textEdit->document()->characterCount() - 1));
}

void MainWindow::on_action_Character_Counter_Off_triggered()
{
    ui->action_Character_Counter_On->setChecked(false);
    ui->action_Character_Counter_Off->setChecked(true);
    charOn = false;
    charCountLabel->setText("");
}

void MainWindow::on_action_Lines_Counter_On_triggered()
{
    QString flags;

    ui->action_Lines_Counter_On->setChecked(true);
    ui->action_Lines_Counter_Off->setChecked(false);
    linesOn = true;
    linesCountLabel->setText(tr("Lines: ") + QString::number(ui->textEdit->document()->lineCount()) + flags);
}

void MainWindow::on_action_Lines_Counter_Off_triggered()
{
    ui->action_Lines_Counter_On->setChecked(false);
    ui->action_Lines_Counter_Off->setChecked(true);
    linesOn = false;
    linesCountLabel->setText("");
}

void MainWindow::on_action_statusBar_Font_triggered()
{
    ui->statusbar->setFont(QFontDialog::getFont(nullptr,ui->statusbar->font(),this));

    wordCountLabel->setFont(ui->statusbar->font());
    charCountLabel->setFont(ui->statusbar->font());
    linesCountLabel->setFont(ui->statusbar->font());
}

void MainWindow::on_action_statusBar_Font_Color_triggered()
{
    if (statusbarfcolor != "")
    {
        QColor color = QColorDialog::getColor(statusbarfcolor, this);

        if (color.isValid())
        {
            statusbarfcolor = color.name();

            if (statusbarbcolor != "")
            {
                ui->statusbar->setStyleSheet("background-color: " + statusbarbcolor + ";" + "color: " + color.name() + ";");
            }
            else
            {
                ui->statusbar->setStyleSheet("color: " + color.name() + ";");
            }
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(Qt::black, this);

        if (color.isValid())
        {
            statusbarfcolor = color.name();

            if (statusbarbcolor != "")
            {
                ui->statusbar->setStyleSheet("background-color: " + statusbarbcolor + ";" + "color: " + color.name() + ";");
            }
            else
            {
                ui->statusbar->setStyleSheet("color: " + color.name() + ";");
            }
        }
    }
}

void MainWindow::on_action_statusBar_Appearance_triggered()
{
    if (statusbarbcolor != "")
    {
        QColor color = QColorDialog::getColor(statusbarbcolor, this);

        if (color.isValid())
        {
            statusbarbcolor = color.name();

            if (statusbarfcolor != "")
            {
                ui->statusbar->setStyleSheet("background-color: " + color.name() + ";" + "color: " + statusbarfcolor + ";");
            }
            else
            {
                ui->statusbar->setStyleSheet("background-color: " + color.name() + ";");
            }
        }
    }
    else
    {
        QColor color = QColorDialog::getColor(Qt::white, this);

        if (color.isValid())
        {
            statusbarbcolor = color.name();

            if (statusbarfcolor != "")
            {
                ui->statusbar->setStyleSheet("background-color: " + color.name() + ";" + "color: " + statusbarfcolor + ";");
            }
            else
            {
                ui->statusbar->setStyleSheet("background-color: " + color.name() + ";");
            }
        }
    }
}

void MainWindow::on_action_statusBar_Reset_to_default_triggered()
{
    statusbarbcolor = "";

    if (statusbarfcolor != "")
    {
        ui->statusbar->setStyleSheet("color: " + statusbarfcolor + ";");
    }
    else
    {
        ui->statusbar->setStyleSheet("");
    }
}
