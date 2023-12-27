//
// MainWindow_player Class Implementation
//

#include "mainwindow_player.h"
#include "ui_mainwindow_player.h"

// Constructor
MainWindow_player::MainWindow_player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_player)
{
    ui->setupUi(this);

    // Hide the status bar
    statusBar()->hide();

    // Initialize the media player
    player = new QMediaPlayer(this);
    player->setNotifyInterval(1000);
    player->setVideoOutput(ui->widget_video);

    // Check the language
    QLocale currentLocale = QLocale::system();
    QString language = currentLocale.languageToString(currentLocale.language());
    if (language == "Chinese") {
        ui->pushButton_language->setChecked(1);
    }

    // Connect signals and slots for media player events
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(onPositionChanged(qint64)));

    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
}

// Destructor
MainWindow_player::~MainWindow_player()
{
    delete ui;
}

// Slot for Play/Pause button toggle
void MainWindow_player::on_pushButton_playandpause_toggled(bool checked)
{
    if (checked == 0) {
        // Pause
        player->pause();
    } else {
        // Play
        player->play();
    }
}

// Slot for Mute/Unmute button toggle
void MainWindow_player::on_pushButton_volume_toggled(bool checked)
{
    if (checked == 0) {
        // Unmute
        player->setMuted(false);
    } else if (ui->horizontalSlider_volume->value() != 0) {
        // Mute
        player->setMuted(true);
    }
}

// Slot for Full Screen toggle
void MainWindow_player::on_pushButton_screencontrol_toggled(bool checked)
{
    if (checked == 1) {
        m_rect = ui->widget_player->geometry();
        ui->widget_player->setFocus();
        showFullScreen();
        ui->widget_player->setGeometry(0, 0, width(), height());

        // Adjust the size of ui->widget_video to fill the entire ui->widget_player
        ui->widget_video->setGeometry(0, 0, width(), height() - ui->widget_toolbar->height());

        // Adjust the size of ui->widget_toolbar to fill ui->widget_player
        ui->widget_toolbar->setGeometry(0,
                                        height() - ui->widget_toolbar->height(),
                                        width(),
                                        ui->widget_toolbar->height());
    } else {
        showNormal();

        ui->widget_player->setGeometry(m_rect);

        // Restore the geometry of ui->widget_video
        ui->widget_video->setGeometry(0,
                                      0,
                                      m_rect.width(),
                                      m_rect.height() - ui->widget_toolbar->height());

        // Restore the geometry of ui->widget_toolbar
        ui->widget_toolbar->setGeometry(0,
                                        m_rect.height() - ui->widget_toolbar->height(),
                                        m_rect.width(),
                                        ui->widget_toolbar->height());
    }
}

// Slot for Play Speed button click
void MainWindow_player::on_pushButton_playspeed_clicked()
{
    // Speed range: 0.5 - 2.0

    // When clicked, change button text info
    QString playSpeedStr = ui->pushButton_playspeed->text();
    playSpeedStr.chop(1);
    double playSpeedDouble = playSpeedStr.toDouble();

    playSpeedDouble += 0.25;
    if (playSpeedDouble > 2.0)
        playSpeedDouble = 0.5;

    playSpeedStr = QString::number(playSpeedDouble);
    playSpeedStr += "x";

    ui->pushButton_playspeed->setText(playSpeedStr);

    qreal initialPlaybackRate = playSpeedDouble;
    player->setPlaybackRate(initialPlaybackRate);
}

// Slot for Volume Slider value change
void MainWindow_player::on_horizontalSlider_volume_valueChanged(int value)
{
    // Set the volume
    player->setVolume(value);
}

// Slot for Position Slider value change
void MainWindow_player::on_horizontalSlider_position_valueChanged(int value)
{
    // Set the media player position
    player->setPosition(value);
}

// Slot for Media Duration change
void MainWindow_player::onDurationChanged(qint64 duration)
{
    // Set the maximum range for the position slider
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

    ui->label_duration->setText(durationTime);
}

// Slot for Media Position change
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

// Slot for Jumping to a specific media position
void MainWindow_player::jumpTo(TheButtonInfo *buttonInfo)
{
    // Jump to a specific position in the media
    player->setMedia(*buttonInfo->url);
    player->setVolume(ui->horizontalSlider_volume->value());
    ui->pushButton_playandpause->setChecked(0);
    player->play();
    player->pause();
    ui->label_videoname->setText(buttonInfo->url->fileName());
}

// Function to initialize the video list
void MainWindow_player::videosListInit(std::vector<TheButtonInfo> v)
{
    tmpVideos = v;
    if (videos.empty())
        videos = v;

    // Create widgets for the video list
    QWidget *videosListLayout = new QWidget(ui->scrollArea_videoslist);
    QWidget *buttonWidget = new QWidget();

    // Create a vertical layout manager
    QVBoxLayout *verticalLayout = new QVBoxLayout(videosListLayout);
    buttonWidget->setLayout(verticalLayout);

    // Populate the list with buttons
    for (const TheButtonInfo &video : tmpVideos) {
        TheButton *button = new TheButton(buttonWidget);
        connect(button, &TheButton::jumpTo, this, &MainWindow_player::jumpTo);
        verticalLayout->addWidget(button);
        button->init(&video);
    }

    // Set the layout for the video list
    videosListLayout->setLayout(verticalLayout);
    ui->scrollArea_videoslist->setWidget(videosListLayout);
}

// Slot for moving forward in the media
void MainWindow_player::on_pushButton_movefoward_clicked()
{
    qint64 currentPosition = player->position();
    qint64 currentDuration = player->duration();

    currentPosition += 10 * 1000;
    if (currentPosition > currentDuration)
        currentPosition = currentDuration;

    player->setPosition(currentPosition);
}

// Slot for moving backward in the media
void MainWindow_player::on_pushButton_moveback_clicked()
{
    qint64 currentPosition = player->position();

    currentPosition -= 10 * 1000;
    if (currentPosition < 0)
        currentPosition = 0;

    player->setPosition(currentPosition);
}

// Mouse press event for the player widget
void MainWindow_player::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    QRect widgetRect = ui->widget_player->geometry();
    widgetRect.setBottom(widgetRect.top() + ui->widget_video->geometry().bottom());

    if (widgetRect.contains(x, y)) {
        ui->pushButton_playandpause->setChecked((ui->pushButton_playandpause->isChecked() ^ 1));
    }
}

// Mouse double click event for the player widget
void MainWindow_player::mouseDoubleClickEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    QRect widgetRect = ui->widget_player->geometry();
    widgetRect.setBottom(widgetRect.top() + ui->widget_video->geometry().bottom());

    if (widgetRect.contains(x, y)) {
        ui->pushButton_screencontrol->setChecked((ui->pushButton_screencontrol->isChecked() ^ 1));
    }
}

// Key press event for handling various shortcuts
void MainWindow_player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        if (ui->pushButton_screencontrol->isChecked())
            ui->pushButton_screencontrol->setChecked(0);
    }

    if (event->key() == Qt::Key_Space) {
        ui->pushButton_playandpause->setChecked((ui->pushButton_playandpause->isChecked() ^ 1));
    }

    if (event->key() == Qt::Key_Left) {
        on_pushButton_moveback_clicked();
    }

    if (event->key() == Qt::Key_Right) {
        on_pushButton_movefoward_clicked();
    }

    if (event->key() == Qt::Key_Up) {
        int tmpVolume = player->volume();
        tmpVolume += 10;

        if (tmpVolume > 99)
            tmpVolume = 99;

        player->setVolume(tmpVolume);
        ui->horizontalSlider_volume->setValue(tmpVolume);
    }

    if (event->key() == Qt::Key_Down) {
        int tmpVolume = player->volume();
        tmpVolume -= 10;

        if (tmpVolume < 0)
            tmpVolume = 0;

        player->setVolume(tmpVolume);
        ui->horizontalSlider_volume->setValue(tmpVolume);
    }
}

// Slot for clearing the comment text area
void MainWindow_player::on_pushButton_sendcomment_clicked()
{
    ui->textEdit_comment->setText("");
}

// Slot for searching videos based on input content
void MainWindow_player::on_pushButton_search_clicked()
{
    QString searchContent = ui->textEdit_search->toPlainText();
    ui->textEdit_search->setText("");
    std::vector<TheButtonInfo> filteredVideos;

    for (auto video : videos) {
        QUrl *tmpUrl = video.url;
        QString fileName = tmpUrl->fileName();

        if (fileName.contains(searchContent)) {
            filteredVideos.push_back(video);
        }
    }

    videosListInit(filteredVideos);
}

// Slot for toggling between Chinese and English language
void MainWindow_player::on_pushButton_language_toggled(bool checked)
{

    QFont englishFont11("Yu Gothic UI Semibold", 11);
    QFont englishFont14("Mistral", 14);
    QFont chineseFont11("宋体", 11);
    QFont chineseFont14("宋体", 14);

    QFont englishSlogan("Mistral", 15);
    QFont chineseSlogan("Times New Roman", 11);

    if (checked) {
        // size 14
        ui->pushButton_account->setText("账户");
        ui->label_comment->setText("写下你所想！");
        ui->pushButton_sendcomment->setText("发送");
        ui->pushButton_account->setFont(chineseFont14);
        ui->label_comment->setFont(chineseFont14);
        ui->pushButton_sendcomment->setFont(chineseFont14);

        // size 11
        ui->pushButton_likelist->setText("喜爱列表");
        ui->pushButton_collection->setText("收藏夹");
        ui->pushButton_screenshotlibrary->setText("截图库");
        ui->pushButton_language->setText("切换语言");
        ui->pushButton_mode->setText(ui->pushButton_mode->isChecked() ? "夜间模式" : "日间模式");
        ui->pushButton_likelist->setFont(chineseFont11);
        ui->pushButton_collection->setFont(chineseFont11);
        ui->pushButton_screenshotlibrary->setFont(chineseFont11);
        ui->pushButton_language->setFont(chineseFont11);
        ui->pushButton_mode->setFont(chineseFont11);

        // 标语/Slogan
        ui->label_videoslist->setText("你所热爱的！");
        ui->label_videoslist->setFont(chineseSlogan);

        // no font size
        ui->textEdit_search->setPlaceholderText("输入视频标题...");
        ui->textEdit_comment->setPlaceholderText("输入内容...");

    } else {
        // size 14
        ui->pushButton_account->setText("Account");
        ui->label_comment->setText("Write down your opinion!");
        ui->pushButton_sendcomment->setText("POST");
        ui->pushButton_account->setFont(englishFont14);
        ui->label_comment->setFont(englishFont14);
        ui->pushButton_sendcomment->setFont(englishFont14);

        // size 11
        ui->pushButton_likelist->setText("Like List");
        ui->pushButton_collection->setText("Collection");
        ui->pushButton_screenshotlibrary->setText("Screenshot Library");
        ui->pushButton_language->setText("Change Language");
        ui->pushButton_mode->setText(ui->pushButton_mode->isChecked() ? "Dark Modal" : "Light Modal");
        ui->pushButton_likelist->setFont(englishFont11);
        ui->pushButton_collection->setFont(englishFont11);
        ui->pushButton_screenshotlibrary->setFont(englishFont11);
        ui->pushButton_language->setFont(englishFont11);
        ui->pushButton_mode->setFont(chineseFont11);

        // 标语/Slogan
        ui->label_videoslist->setText(" Grab You Like!");
        ui->label_videoslist->setFont(englishSlogan);

        // no font size
        ui->textEdit_search->setPlaceholderText("type to search...");
        ui->textEdit_comment->setPlaceholderText("type the comment...");
    }
}

// Slot for taking a screenshot of the video player
void MainWindow_player::on_pushButton_screenshot_clicked()
{
    // Take a screenshot of the player's position from the full screen
    QLayout *tmpLayout = picWindow.layout();

    if (tmpLayout) {
        // Delete the layout and all its internal widgets
        QLayoutItem *item;
        while ((item = tmpLayout->takeAt(0)) != nullptr) {
            QWidget *widget = item->widget();
            if (widget) {
                delete widget;
            } else {
                QLayout *childLayout = item->layout();
                if (childLayout) {
                    delete childLayout;
                } else {
                    delete item;
                }
            }
        }
        delete tmpLayout;
    }

    ui->pushButton_playandpause->setChecked(0);

    QScreen *screen = QGuiApplication::primaryScreen();

    QRect windowGeometry = this->geometry();
    m_rect = ui->widget_player->geometry();

    windowGeometry.setRect(windowGeometry.x() + m_rect.x(),
                           windowGeometry.y() + m_rect.y(),
                           m_rect.width(),
                           m_rect.height() - ui->widget_toolbar->height());

    QRect cropRect(windowGeometry);
    QPixmap pixmap = screen->grabWindow(0);
    pixmap = pixmap.copy(cropRect);

    picWindow.setWindowTitle("Image Viewer");
    picWindow.setWindowModality(Qt::ApplicationModal);

    QLabel *label = new QLabel(&picWindow);
    label->setScaledContents(true);
    label->setPixmap(pixmap);

    QPushButton *pushButton_save = new QPushButton("Save", &picWindow);

    QVBoxLayout *layout = new QVBoxLayout(&picWindow);
    layout->addWidget(label);
    layout->addWidget(pushButton_save);

    picWindow.setLayout(layout);

    connect(pushButton_save, &QPushButton::clicked, [=]() { saveImage(pixmap); });

    picWindow.show();
}

void MainWindow_player::saveImage(QPixmap pixmap)
{
    QString dateTime = QDateTime::currentDateTime().toString("yyyyMMdd-hhmmss");

    QString fileName = "image-" + dateTime + ".png";

    QString filePath = QFileDialog::getSaveFileName(nullptr,
                                                    "Save Image",
                                                    fileName,
                                                    "Images (*.png *.bmp *.jpg)");

    if (!filePath.isEmpty()) {
        QString directory = QFileInfo(filePath).dir().path() + "/image";
        QDir().mkpath(directory);

        filePath = directory + "/" + fileName;
        QImageWriter writer(filePath);
        writer.setFormat("PNG");
        writer.write(pixmap.toImage());
    }
}

void MainWindow_player::on_pushButton_mode_toggled(bool checked)
{
    QFont englishFont11("Mistral", 11);
    QFont chineseFont11("宋体", 11);

    //blue
    if(!checked){
        ui->pushButton_mode->setText(ui->pushButton_language->isChecked() ? "日间模式" : "Light Model");
        ui->pushButton_mode->setFont(ui->pushButton_language->isChecked() ? chineseFont11 : englishFont11);

        ui->label_logoname->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgb(0, 85, 255);\nborder-radius:10px");
        ui->widget_navigation->setStyleSheet("background-color: rgb(28, 63, 170);");
        ui->pushButton_mode->setStyleSheet("color:white;\n\nbackground-color: rgb(0, 85, 255);\nborder-radius:10px\n");
        ui->pushButton_language->setStyleSheet("color:white;\nbackground-color: rgb(0, 85, 255);\nborder-radius:10px\n");
        ui->label_logoname_3->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgb(0, 85, 255);\nfont: 22pt \"Mistral\";\n\n");
        ui->widget_additionalfunction->setStyleSheet("border-radius:10px;\nbackground-color: rgb(255, 255, 255);");
        ui->textEdit_comment->setStyleSheet("color: rgb(45, 45, 45);\nbackground-color: rgb(247, 247, 247);\nborder-radius:10px;\npadding-left:5px;\npadding-top:2px;");
        ui->label_comment->setStyleSheet("background-color: rgb(28, 63, 170);\ncolor: rgb(255, 255, 255);\nborder-bottom-right-radius:0px;\nborder-bottom-left-radius:0px;\n");
        ui->label_logoname_4->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgb(0, 85, 255);\nborder-bottom-right-radius:0px;\nborder-bottom-left-radius:0px;\n");
        ui->widget_videoslist->setStyleSheet("background-color: rgb(28, 63, 170);\nborder-radius:10px");
        this->setStyleSheet("background-color: rgb(238, 238, 238);\n");
        ui->widget_player->setStyleSheet("border-radius:10px;");
        ui->pushButton_sendcomment->setStyleSheet("color: rgb(255, 255, 255);\n\nbackground-color: rgb(55, 125, 255);\n");
        ui->widget_searchbox->setStyleSheet("background-color: white; \nborder-radius: 10px;");

        ui->pushButton_uploadfile->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgb(0, 85, 255);\n");
    }

    //black
    else{
        ui->pushButton_mode->setText(ui->pushButton_language->isChecked() ? "夜间模式" : "Dark Model");
        ui->pushButton_mode->setFont(ui->pushButton_language->isChecked() ? chineseFont11 : englishFont11);

        ui->label_logoname->setStyleSheet("color: rgb(255, 179, 1);\nbackground-color: rgb(40, 40, 40);\nborder-radius:10px");
        ui->widget_navigation->setStyleSheet("background-color: rgb(25, 25, 25);");
        ui->pushButton_mode->setStyleSheet("color:white;\nbackground-color: rgb(40, 40, 40);\nborder-radius:10px\n");
        ui->pushButton_language->setStyleSheet("color:white;\nbackground-color: rgb(40, 40, 40);\nborder-radius:10px\n");
        ui->label_logoname_3->setStyleSheet("color: rgb(255, 179, 1);\nbackground-color: rgb(50, 50, 50);\n");
        ui->widget_additionalfunction->setStyleSheet("border-radius:10px;\nbackground-color: rgb(25, 25, 25);");
        ui->textEdit_comment->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgb(40, 40, 40);\nborder-radius:10px;\npadding-left:5px;\npadding-top:2px;");
        ui->label_comment->setStyleSheet("background-color: rgb(40, 40, 40);\ncolor: rgb(255, 179, 1);\nborder-bottom-right-radius:0px;\nborder-bottom-left-radius:0px;\n");
        ui->label_logoname_4->setStyleSheet("color: rgb(255, 179, 1);\nbackground-color: rgb(27, 27, 27);\nborder-bottom-right-radius:0px;\nborder-bottom-left-radius:0px;\n");
        ui->widget_videoslist->setStyleSheet("background-color: rgba(27, 27, 27, 0.6);\nborder-radius:10px");
        this->setStyleSheet("background-color: rgb(50, 50, 50);\n");
        ui->widget_player->setStyleSheet("border-radius:10px;\nbackground-color: rgb(40, 40, 40);");
        ui->pushButton_sendcomment->setStyleSheet("color: rgb(255, 255, 255);\n\nbackground-color: rgb(40, 40, 40);\n");
        ui->widget_searchbox->setStyleSheet("background-color: white; \nborder-radius: 10px;\nbackground-color: rgba(27, 27, 27, 0.6);\ncolor: rgba(255, 255, 255, 0.7);");

        ui->pushButton_uploadfile->setStyleSheet("color: rgb(255, 179, 1);\nbackground-color: rgba(27, 27, 27, 0.6);\n");
    }
}
