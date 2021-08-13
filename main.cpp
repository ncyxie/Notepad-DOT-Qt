#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setOrganizationName("ncyxie");
    app.setApplicationName("Notepad DOT Qt");
    app.setApplicationVersion("1.0.1-s2");
    MainWindow w;
    w.show();

    return app.exec();
}
