#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *pEvent);
    void timerEvent(QTimerEvent *);
private slots:
    void on_pushButton_WriteConfig_clicked();

    void on_pushButton_ReadConfig_clicked();

    void on_pushButton_ReadFile_clicked();

    void on_pushButton_WriteFile_clicked();

    void on_pushButton_Start_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_Stop_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
