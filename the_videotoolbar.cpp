//
//
//

#include "the_videotoolbar.h"

TheVideoToolBar::TheVideoToolBar(QWidget *parent) : QWidget(parent)
{
    // set position bar as horizontal
    positionSlider = new QSlider(Qt::Horizontal);
    // set as string temporary, will be change to img later.
    playButton = new QPushButton("Play");
    pauseButton = new QPushButton("Pause");
    // set volume bar as horizontal
    volumeSlider = new QSlider(Qt::Horizontal);

    // volumn range
    volumeSlider->setRange(0, 100);

    // connect button to slot function
    connect(playButton, &QPushButton::clicked, this, &TheVideoToolBar::playClicked);
    connect(pauseButton, &QPushButton::clicked, this, &TheVideoToolBar::pauseClicked);

    // connect slider to slot function
    connect(positionSlider, &QSlider::valueChanged, this, &TheVideoToolBar::seek);
    connect(volumeSlider, &QSlider::valueChanged, this, &TheVideoToolBar::volumeChanged);

    // layout
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(playButton);
    layout->addWidget(pauseButton);
    layout->addWidget(positionSlider);
    layout->addWidget(volumeSlider);

    setLayout(layout);
}

void TheVideoToolBar::updatePosition(qint64 position)
{
    if(position)
        positionSlider->setValue(static_cast<int>(position));
}

void TheVideoToolBar::updateDuration(qint64 duration)
{
    if(duration)
        positionSlider->setRange(0, static_cast<int>(duration));
}

void TheVideoToolBar::updateVolume(int volume)
{
    volumeSlider->setValue(volume);
}
