#ifndef MAINWINDOW_PLAYER_H
#define MAINWINDOW_PLAYER_H

#include <Qstring>
#include <QMainWindow>

namespace Ui {
class MainWindow_player;
}

class MainWindow_player : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_player(QWidget *parent = nullptr);
    ~MainWindow_player();

private slots:
    void on_pushButton_playandpause_toggled(bool checked);

    void on_pushButton_volume_toggled(bool checked);

    void on_pushButton_screencontrol_toggled(bool checked);

    void on_pushButton_playspeed_clicked();

private:
    Ui::MainWindow_player *ui;
};

#endif // MAINWINDOW_PLAYER_H
