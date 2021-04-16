#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    QString currentFile;
};


#endif // MAINWINDOW_H
