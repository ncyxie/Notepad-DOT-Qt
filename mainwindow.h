#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "aboutdialog.h"
#include "discorddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_action_Save_As_triggered();

    void on_action_Paste_triggered();

    void on_action_Copy_triggered();

    void on_action_Cut_triggered();

    void on_action_Undo_triggered();

    void on_action_Redo_triggered();

    void on_action_About_triggered();

    void on_action_Exit_triggered();

    void on_action_Font_triggered();

    void on_action_Color_triggered();

    void on_action_Delete_triggered();

    void on_action_Select_All_triggered();

    void on_actionPrint_triggered();

    void on_action_GitHub_repository_triggered();

    void on_action_GitHub_releases_triggered();

    void on_action_Telegram_support_triggered();

    void on_action_Search_with_Google_triggered();

    void on_action_Search_with_Bing_triggered();

    void on_action_Search_with_DuckDuckGo_triggered();

    void on_action_Search_with_Yahoo_triggered();

    void on_action_New_Window_triggered();

    void on_action_Date_Time_triggered();

    void on_action_Discord_support_triggered();

    void on_action_Uppercase_triggered();

    void on_action_Lowercase_triggered();

    void on_action_menubar_Appearance_triggered();

    void on_action_menubar_Font_triggered();

    void on_action_menubar_Font_Color_triggered();

    void on_action_textEdit_Appearance_triggered();

    void on_action_widget_Appearance_triggered();

    void on_action_widget_Appearance_Reset_to_default_triggered();

    void on_action_menubar_Appearance_Reset_to_default_triggered();

    void on_action_Word_Wrap_triggered();

    void on_action_Vertical_triggered();

    void on_action_Horizontal_triggered();

    void on_action_Both_triggered();

    void on_action_None_triggered();

    void on_action_Box_triggered();

    void on_action_Panel_triggered();

    void on_action_Win_Panel_triggered();

    void on_action_Styled_Panel_triggered();

    void on_action_No_Frame_triggered();

    void on_textEdit_textChanged();

    void on_action_textEdit_Reset_to_default_triggered();

    void outsideNotepadOpen();

    void on_action_statusBar_On_triggered();

    void on_action_statusBar_Off_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile;
    QString fileText;
    QString outsideFileName;
    QString menubarbcolor = "";
    QString menubarfcolor = "";
    QString widgetbcolor = "";
    QString texteditbcolor = "";
    bool isFresh = true;
    QDateTime dateTime;

    AboutDialog *aboutdialog;
    discorddialog *ddialog;
};


#endif // MAINWINDOW_H
