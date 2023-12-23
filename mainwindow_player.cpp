#include "mainwindow_player.h"
#include "ui_mainwindow_player.h"

MainWindow_player::MainWindow_player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_player)
{
    ui->setupUi(this);
}

MainWindow_player::~MainWindow_player()
{
    delete ui;
}



void MainWindow_player::on_pushButton_playandpause_toggled(bool checked)
{
    if(checked == 1)
    {
        // play
    }
    else
    {
        // pause
    }
}


void MainWindow_player::on_pushButton_volume_toggled(bool checked)
{
    if(checked == 1)
    {
        // unmute
    }
    else
    {
        // mute
    }
}


void MainWindow_player::on_pushButton_screencontrol_toggled(bool checked)
{
    if(checked == 1)
    {
        // unmute
    }
    else
    {
        // mute
    }
}


void MainWindow_player::on_pushButton_playspeed_clicked()
{
    // 0.5 - 2.0
    QString playSpeedStr = ui->pushButton_playspeed->text();
    playSpeedStr.chop(1);
    double playSpeedDouble = playSpeedStr.toDouble();

    playSpeedDouble += 0.25;
    if(playSpeedDouble > 2.0) playSpeedDouble = 0.5;

    playSpeedStr = QString::number(playSpeedDouble);
    playSpeedStr += "x";

    ui->pushButton_playspeed->setText(playSpeedStr);
}

