//
//
//

#include "the_player.h"

ThePlayer::ThePlayer() : QMediaPlayer(NULL)
{
    setVolume(0); // be slightly less annoying
    connect(this, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(playStateChanged(QMediaPlayer::State)));

    // connect bar to player
    videoToolBar = new TheVideoToolBar;
    connect(videoToolBar, &TheVideoToolBar::playClicked, this, &ThePlayer::play);
    connect(videoToolBar, &TheVideoToolBar::pauseClicked, this, &ThePlayer::pause);
    connect(videoToolBar, &TheVideoToolBar::seek, this, &ThePlayer::setPosition);
    connect(videoToolBar, &TheVideoToolBar::volumeChanged, this, &ThePlayer::setVolume);

    connect(this, &QMediaPlayer::positionChanged, videoToolBar, &TheVideoToolBar::updatePosition);
    connect(this, &QMediaPlayer::durationChanged, videoToolBar, &TheVideoToolBar::updateDuration);
    connect(this, &QMediaPlayer::volumeChanged, videoToolBar, &TheVideoToolBar::updateVolume);
}

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<TheButton *> *b, std::vector <TheButtonInfo> *i)
{
    buttons = b;
    infos = i;
    jumpTo(buttons->at(0)->info);
}


void ThePlayer::playStateChanged(QMediaPlayer::State ms)
{
    switch (ms)
    {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
        default:
            break;
    }
}

void ThePlayer::jumpTo(TheButtonInfo *button)
{
    setMedia(*button->url);
    play();
}

void ThePlayer::setMediaPosition(int position)
{
    setPosition(position);
}
