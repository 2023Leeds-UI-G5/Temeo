//
//
//

#ifndef the_videoToolBar_H
#define the_videoToolBar_H

#include <QWidget>
#include <QMediaPlayer>
#include <QSlider>
#include <QPushButton>
#include <QHBoxLayout>

class QSlider;

class QPushButton;

class TheVideoToolBar : public QWidget
{
    Q_OBJECT

private:
    // control the time position of video
    QSlider *positionSlider;
    // play and pause button, click to play or pause
    QPushButton *playButton;
    QPushButton *pauseButton;
    // control the volume of player
    QSlider *volumeSlider;

public:
    TheVideoToolBar(QWidget *parent = nullptr);

signals:
    void playClicked();

    void pauseClicked();

    void seek(int seconds);

    void volumeChanged(int volumeDegree);

public slots:
    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void updateVolume(int volumeDegree);
};

#endif // the_videoToolBar_H
