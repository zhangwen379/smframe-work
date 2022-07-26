#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "varsm_thread_allsystem.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    VarSM_Thread * pSM=m_gAllSystem.get_VarSM_Thread(VarSM_Ball_ID);
    m_gAllSystem.ReadConfig();
    ui->tableWidget->Init(&(pSM->m_Variants));
    startTimer(m_gdProcessTime*1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *pEvent)
{
    UNUSED(pEvent);
    ui->tableWidget->Fresh();
}

void MainWindow::timerEvent(QTimerEvent * )
{
    ui->widget->refreshPixmap();
    m_gAllSystem.pushBack_Msg(VarSM_Ball_ID,VarMsg(VarMsg_Ball_FreshPOS));
}

void MainWindow::on_pushButton_WriteConfig_clicked()
{
    ui->tableWidget->Apply();
    m_gAllSystem.WriteConfig();
}

void MainWindow::on_pushButton_ReadConfig_clicked()
{
    m_gAllSystem.ReadConfig();
    ui->tableWidget->Fresh();
}

void MainWindow::on_pushButton_ReadFile_clicked()
{
    m_gAllSystem.ReadFile();
    ui->tableWidget->Fresh();
}

void MainWindow::on_pushButton_WriteFile_clicked()
{
    ui->tableWidget->Apply();
    m_gAllSystem.WriteFile();
}

void MainWindow::on_pushButton_Start_clicked()
{
    m_gAllSystem.pushBack_Msg(VarSM_Ball_ID,VarMsg(VarMsg_Start_ID));
}

void MainWindow::on_pushButton_Pause_clicked()
{
    m_gAllSystem.pushBack_Msg(VarSM_Ball_ID,VarMsg(VarMsg_Pause_ID));
}

void MainWindow::on_pushButton_Stop_clicked()
{
    m_gAllSystem.pushBack_Msg(VarSM_Ball_ID,VarMsg(VarMsg_Stop_ID));

}
