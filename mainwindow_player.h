//
//
//

#ifndef MAINWINDOW_PLAYER_H
#define MAINWINDOW_PLAYER_H

#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QImageWriter>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMouseEvent>
#include <QScreen>
#include <QVideoWidget>
#include <Qstring>

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

    void videosListInit(std::vector<TheButtonInfo> v);

    void jumpTo(TheButtonInfo *buttonInfo);

    void saveImage(QPixmap pixmap);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseDoubleClickEvent(QMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    QMediaPlayer *player;
    QString durationTime;
    QString positionTime;
    std::vector<TheButtonInfo> videos, tmpVideos;
    QRect m_rect;
    QWidget picWindow;

private slots:
    void on_pushButton_playandpause_toggled(bool checked);

    void on_pushButton_volume_toggled(bool checked);

    void onDurationChanged(qint64 duration);

    void onPositionChanged(qint64 position);

    void on_pushButton_screencontrol_toggled(bool checked);

    void on_pushButton_playspeed_clicked();

    void on_horizontalSlider_volume_valueChanged(int value);

    void on_horizontalSlider_position_valueChanged(int value);

    void on_pushButton_movefoward_clicked();

    void on_pushButton_moveback_clicked();

    void on_pushButton_sendcomment_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_language_toggled(bool checked);

    void on_pushButton_screenshot_clicked();

    void on_pushButton_mode_toggled(bool checked);

private:
    Ui::MainWindow_player *ui;
};

#endif // MAINWINDOW_PLAYER_H
