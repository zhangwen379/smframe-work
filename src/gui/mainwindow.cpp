#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vsmt_allsystem.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    VSM_Thread * pSM=m_gAllSystem.get_VarSM_Thread(VSMT_Ball_ID);
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
    m_gAllSystem.pushBack_Msg(VSMT_Ball_ID,V_Msg(VarMsg_Ball_FreshPOS));
    if(m_gAllSystem.m_bNeedFreshGui)
    {
        ui->tableWidget->Fresh();
        m_gAllSystem.m_bNeedFreshGui=false;
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
//    ui->tableWidget->Fresh();
}

void MainWindow::on_pushButton_WriteConfig_clicked()
{
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
    m_gAllSystem.WriteFile();
}

void MainWindow::on_pushButton_Start_clicked()
{
    m_gAllSystem.pushBack_Msg(VSMT_Ball_ID,V_Msg(VarMsg_Start_ID));
}

void MainWindow::on_pushButton_Pause_clicked()
{
    m_gAllSystem.pushBack_Msg(VSMT_Ball_ID,V_Msg(VarMsg_Pause_ID));
}

void MainWindow::on_pushButton_Stop_clicked()
{
    m_gAllSystem.pushBack_Msg(VSMT_Ball_ID,V_Msg(VarMsg_Stop_ID));

}

void MainWindow::on_pushButton_Apply_clicked()
{
    ui->tableWidget->Apply();
}
