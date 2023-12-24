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

    // Hide the status bar
    statusBar()->hide();

    // Initialize the media player
    player = new QMediaPlayer(this);
    player->setNotifyInterval(2000);
    player->setVideoOutput(ui->widget_video);

    // Connect signals and slots for media player events
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onstateChanged(QMediaPlayer::State)));

    connect(player, SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));

    connect(player, SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));
}

MainWindow_player::~MainWindow_player()
{
    delete ui;
}

void MainWindow_player::on_pushButton_playandpause_toggled(bool checked)
{
    if (checked == 0)
    {
        // Pause
        player->pause();
    }
    else
    {
        // Play
        player->play();
    }
}

void MainWindow_player::on_pushButton_volume_toggled(bool checked)
{
    if (checked == 0)
    {
        // Unmute
        player->setMuted(false);
    }
    else if (ui->horizontalSlider_volume->value() != 0)
    {
        // Mute
        player->setMuted(true);
    }
}

void MainWindow_player::on_pushButton_screencontrol_toggled(bool checked)
{
    if(checked == 1)
    {
        m_rect = ui->widget_player->geometry();
        ui->widget_player->setWindowFlags(Qt::Window);
        ui->widget_player->setFocus();
        ui->widget_player->showFullScreen();
        // 调整 ui->widget_video 的大小以填充整个 ui->widget_player
        ui->widget_video->setGeometry(0, 0, ui->widget_player->width(), ui->widget_player->height() - ui->widget_toolbar->height());

        // 调整 ui->widget_toolbar 的大小以填满 ui->widget_player
        ui->widget_toolbar->setGeometry(0, ui->widget_player->height() - ui->widget_toolbar->height(), ui->widget_player->width(), ui->widget_toolbar->height());

    }
    else
    {
        ui->widget_player->setWindowFlags(Qt::SubWindow);
        ui->widget_player->showNormal();

        ui->widget_player->setGeometry(m_rect);

        // 恢复 ui->widget_video 的大小
        ui->widget_video->setGeometry(0, 0, m_rect.width(), m_rect.height() - ui->widget_toolbar->height());

        // 恢复 ui->widget_toolbar 的大小和位置
        ui->widget_toolbar->setGeometry(0, m_rect.height() - ui->widget_toolbar->height(), m_rect.width(), ui->widget_toolbar->height());
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
    // Set the volume
    player->setVolume(value);
}

void MainWindow_player::on_horizontalSlider_position_valueChanged(int value)
{
    // Set the media player position
    player->setPosition(value);
}

void MainWindow_player::onDurationChanged(qint64 duration)
{
    // Set the maximum range for position slider
    ui->horizontalSlider_position->setMaximum(duration);

    // Format the duration time
    duration /= 1000;
    int secs = duration % 60;
    int mins = (duration / 60) % 60;
    int hours = duration / 3600;

    QString secsStr = QString::number(secs).rightJustified(2, '0');
    QString minsStr = QString::number(mins).rightJustified(2, '0');
    QString hoursStr = QString::number(hours).rightJustified(2, '0');

    durationTime = hoursStr + ":" + minsStr + ":" + secsStr;
    qDebug() << durationTime << endl;
    ui->label_duration->setText(durationTime);
}

void MainWindow_player::onPositionChanged(qint64 position)
{
    if (ui->horizontalSlider_position->isSliderDown())
        return;

    // Update the position slider
    ui->horizontalSlider_position->setSliderPosition(position);

    // Format the position time
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
    // Jump to a specific position in the media
    player->setMedia(*buttonInfo->url);
    player->setVolume(ui->horizontalSlider_volume->value());
    ui->pushButton_playandpause->setChecked(0);
}

void MainWindow_player::videosListInit(std::vector <TheButtonInfo> v)
{
    videos = v;

    // Create widgets for the video list
    QWidget *videosListLayout = new QWidget(ui->scrollArea_videoslist);
    QWidget *buttonWidget = new QWidget();

    // Create a vertical layout manager
    QVBoxLayout *verticalLayout = new QVBoxLayout(videosListLayout);
    buttonWidget->setLayout(verticalLayout);

    // Populate the list with buttons
    for (const TheButtonInfo &video : videos) {
        TheButton *button = new TheButton(buttonWidget);
        connect(button, &TheButton::jumpTo, this, &MainWindow_player::jumpTo);
        verticalLayout->addWidget(button);
        button->init(&video);
    }

    // Set the layout for the video list
    videosListLayout->setLayout(verticalLayout);
    ui->scrollArea_videoslist->setWidget(videosListLayout);
}

void MainWindow_player::on_pushButton_movefoward_clicked()
{
    qint64 currentPosition = player->position();
    qint64 currentDuration = player->duration();

    currentPosition += 10 * 1000;
    if(currentPosition > currentDuration) currentPosition = currentDuration;

    player->setPosition(currentPosition);
}


void MainWindow_player::on_pushButton_moveback_clicked()
{
    qint64 currentPosition = player->position();

    currentPosition -= 10 * 1000;
    if(currentPosition < 0) currentPosition = 0;

    player->setPosition(currentPosition);
}

