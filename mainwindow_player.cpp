//
//
//

#include "mainwindow_player.h"
#include "ui_mainwindow_player.h"

MainWindow_player::MainWindow_player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_player)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    player->setNotifyInterval(2000);
    player->setVideoOutput(ui->widget_video);
    // (ui->widget_video)->setMediaPlayer(player);

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onstateChanged(QMediaPlayer::State)));

    connect(player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));


    connect(player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));
}

MainWindow_player::~MainWindow_player()
{
    delete ui;
}


void MainWindow_player::on_pushButton_playandpause_toggled(bool checked)
{
    if(checked == 0)
    {
        // pause
        player->pause();
    }
    else
    {
        // play
        player->play();
    }
}

void MainWindow_player::on_pushButton_volume_toggled(bool checked)
{
    if(checked == 0)
    {
        // unmute
        player->setMuted(false);
    }
    else if(ui->horizontalSlider_volume->value() != 0)
    {
        // mute
        player->setMuted(true);
    }
}

void MainWindow_player::on_pushButton_screencontrol_toggled(bool checked)
{
    if(checked == 1)
    {
        showFullScreen();
    }
    else
    {
        showNormal();
    }
}

void MainWindow_player::on_pushButton_playspeed_clicked()
{

    // speed range: 0.5 - 2.0

    // when click, change button text info
    QString playSpeedStr = ui->pushButton_playspeed->text();
    playSpeedStr.chop(1);
    double playSpeedDouble = playSpeedStr.toDouble();

    playSpeedDouble += 0.25;
    if(playSpeedDouble > 2.0) playSpeedDouble = 0.5;

    playSpeedStr = QString::number(playSpeedDouble);
    playSpeedStr += "x";

    ui->pushButton_playspeed->setText(playSpeedStr);

    qreal initialPlaybackRate = playSpeedDouble;
    player->setPlaybackRate(initialPlaybackRate);
}

void MainWindow_player::on_horizontalSlider_volume_valueChanged(int value)
{
    player->setVolume(value);
}

void MainWindow_player::on_horizontalSlider_position_valueChanged(int value)
{
    player->setPosition(value);
}

void MainWindow_player::onDurationChanged(qint64 duration)
{
    // set range
    ui->horizontalSlider_position->setMaximum(duration);

    duration /= 1000;
    int secs = duration % 60;
    int mins = (duration / 60) % 60;
    int hours = duration / 3600;

    QString secsStr = QString::number(secs).rightJustified(2, '0');
    QString minsStr = QString::number(mins).rightJustified(2, '0');
    QString hoursStr = QString::number(hours).rightJustified(2, '0');

    durationTime = hoursStr + ":" + minsStr + ":" + secsStr;

    ui->label_duration->setText(durationTime);
}


void MainWindow_player::onPositionChanged(qint64 position)
{
    if (ui->horizontalSlider_position->isSliderDown())
        return;

    ui->horizontalSlider_position->setSliderPosition(position);

    position /= 1000;
    int secs = position % 60;
    int mins = (position / 60) % 60;
    int hours = position / 3600;

    QString secsStr = QString::number(secs).rightJustified(2, '0');
    QString minsStr = QString::number(mins).rightJustified(2, '0');
    QString hoursStr = QString::number(hours).rightJustified(2, '0');

    positionTime = hoursStr + ":" + minsStr + ":" + secsStr;
    ui->label_position->setText(positionTime);
}


void MainWindow_player::jumpTo(TheButtonInfo* buttonInfo)
{
    player->setMedia(*buttonInfo->url);
    player->setVolume(ui->horizontalSlider_volume->value());
    ui->pushButton_playandpause->setChecked(0);
}

void MainWindow_player::videosListInit(std::vector <TheButtonInfo> v)
{
    videos = v;

    QWidget *videosListLyout = new QWidget(ui->scrollArea_videoslist);
    QWidget *buttonWidget = new QWidget();

    // 创建一个垂直布局管理器
    QVBoxLayout *verticalLayout = new QVBoxLayout(videosListLyout);
    buttonWidget->setLayout(verticalLayout);

    for (const TheButtonInfo &video : videos) {
        TheButton *button = new TheButton(buttonWidget);
        connect(button, &TheButton::jumpTo, this, &MainWindow_player::jumpTo);
        verticalLayout->addWidget(button);
        button->init(&video);
    }

    videosListLyout->setLayout(verticalLayout);
    ui->scrollArea_videoslist->setWidget(videosListLyout);
}
