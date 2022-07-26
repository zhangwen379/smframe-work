#include "mainwindow.h"
#include <QApplication>

#include "varsm_thread_allsystem.h"
#ifdef _DEBUG
#include "vld.h"
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    m_gAllSystem.Init();
    MainWindow w;
    w.show();
    return a.exec();
}
