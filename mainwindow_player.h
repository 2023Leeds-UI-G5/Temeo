//
//
//

#ifndef MAINWINDOW_PLAYER_H
#define MAINWINDOW_PLAYER_H

#include <Qstring>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>

#include "the_button.h"

namespace Ui {
class MainWindow_player;
}

class MainWindow_player : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_player(QWidget *parent = nullptr);
    ~MainWindow_player();

    void videosListInit(std::vector <TheButtonInfo> v);

    void jumpTo(TheButtonInfo* buttonInfo);

private:
    QMediaPlayer *player;
    QString  durationTime;
    QString  positionTime;
    std::vector <TheButtonInfo> videos;
    QRect m_rect;

private slots:
    void on_pushButton_playandpause_toggled(bool checked);

    void on_pushButton_volume_toggled(bool checked);

    void onDurationChanged(qint64 duration);

    void onPositionChanged(qint64 position);

    void on_pushButton_screencontrol_toggled(bool checked);

    void on_pushButton_playspeed_clicked();

    void on_horizontalSlider_volume_valueChanged(int value);

    void on_horizontalSlider_position_valueChanged(int value);

private:
    Ui::MainWindow_player *ui;
};

#endif // MAINWINDOW_PLAYER_H
