#ifndef DISCORDDIALOG_H
#define DISCORDDIALOG_H

#include <QDialog>

namespace Ui {
class discorddialog;
}

class discorddialog : public QDialog
{
    Q_OBJECT

public:
    explicit discorddialog(QWidget *parent = nullptr);
    ~discorddialog();

private slots:
    void on_closeButton_clicked();

private:
    Ui::discorddialog *ui;
};

#endif // DISCORDDIALOG_H
