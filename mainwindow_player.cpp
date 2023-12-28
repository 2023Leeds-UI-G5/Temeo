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

        ui->widget_navigation->setVisible(0);
        ui->widget_videoslist->setVisible(0);
        ui->widget_videoname->setVisible(0);
        ui->widget_functionbar->setVisible(0);
        ui->widget_additionalfunction->setVisible(0);

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

        ui->widget_navigation->setVisible(1);
        ui->widget_videoslist->setVisible(1);
        ui->widget_videoname->setVisible(1);
        ui->widget_functionbar->setVisible(1);
        ui->widget_additionalfunction->setVisible(1);
    }
    if(positionTime == durationTime && player->isVideoAvailable())
    {
        player->setMedia(*nowInfo->url);
        player->setPosition(player->duration());
        player->play();
        player->pause();
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
    nowInfo = buttonInfo;
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
    QFont englishFont14("Times New Roman", 14);
    QFont chineseFont11("幼圆", 12);
    QFont chineseFont14("幼圆", 16);

    if (checked) {
        // size 14
        ui->pushButton_account->setText("账户");
        ui->pushButton_sendcomment->setText("发送");
        ui->pushButton_account->setFont(chineseFont14);
        ui->pushButton_sendcomment->setFont(chineseFont14);

        // size 11
        ui->pushButton_likelist->setText("喜爱列表");
        ui->pushButton_collection->setText("收藏夹");
        ui->pushButton_screenshotlibrary->setText("截图库");
        ui->pushButton_language->setText("切换语言");
        ui->pushButton_uploadfile->setText("选择播放目录");
        ui->pushButton_mode->setText(ui->pushButton_mode->isChecked() ? "夜间模式" : "日间模式");
        ui->pushButton_likelist->setFont(chineseFont11);
        ui->pushButton_collection->setFont(chineseFont11);
        ui->pushButton_screenshotlibrary->setFont(chineseFont11);
        ui->pushButton_language->setFont(chineseFont11);
        ui->pushButton_mode->setFont(chineseFont11);
        ui->pushButton_uploadfile->setFont(chineseFont11);

        // // 标语/Slogan
        // ui->label_comment->setText("写下你所想！");
        // ui->label_videoslist->setText("你所热爱的！");
        // ui->label_comment->setFont(chineseSlogan);
        // ui->label_videoslist->setFont(chineseSlogan);

        // no font size
        ui->textEdit_search->setPlaceholderText("输入视频标题...");
        ui->textEdit_comment->setPlaceholderText("输入内容...");

    } else {
        // size 14
        ui->pushButton_account->setText("Account");
        ui->pushButton_sendcomment->setText("POST");
        ui->pushButton_account->setFont(englishFont14);
        ui->pushButton_sendcomment->setFont(englishFont14);

        // size 11
        ui->pushButton_likelist->setText("Like List");
        ui->pushButton_collection->setText("Collection");
        ui->pushButton_screenshotlibrary->setText("Library");
        ui->pushButton_language->setText("Change Language");
        ui->pushButton_uploadfile->setText("Choose Video File List");
        ui->pushButton_mode->setText(ui->pushButton_mode->isChecked() ? "Dark Modal" : "Light Modal");
        ui->pushButton_likelist->setFont(englishFont11);
        ui->pushButton_collection->setFont(englishFont11);
        ui->pushButton_screenshotlibrary->setFont(englishFont11);
        ui->pushButton_language->setFont(englishFont11);
        ui->pushButton_mode->setFont(chineseFont11);
        ui->pushButton_uploadfile->setFont(chineseFont11);

        // // 标语/Slogan
        // ui->label_comment->setText("Write down your opinion!");
        // ui->label_videoslist->setText("Grab You Like!");
        // ui->label_videoslist->setFont(englishSlogan);
        // ui->label_comment->setFont(englishSlogan);

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

        this->setStyleSheet("background-color: rgb(245,245,220);\n");
        ui->label_videoname->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgba(0, 0, 0, 0.3);\n\nborder-top-left-radius:10px;\nborder-top-right-radius:10px;\npadding-left:15px;");

        // widget_additionalfunction
        ui->widget_additionalfunction->setStyleSheet("border-radius:10px;\nbackground-color: rgb(245, 245, 224);");
        ui->label_comment->setStyleSheet("background-color: rgb(28, 63, 170);\ncolor: rgb(255, 255, 255);\npadding-right: 7px;\nborder-bottom-right-radius:0px;\nborder-bottom-left-radius:0px;\n");
        ui->pushButton_sendcomment->setStyleSheet("QPushButton {\ncolor: rgb(255, 255, 255);\nbackground-color: rgb(55, 125, 255);\n}\n\nQPushButton:hover {\nbackground-color: rgba(55, 125, 255, 0.7\n);\n}\n");
        ui->textEdit_comment->setStyleSheet("color: rgb(45, 45, 45);\nbackground-color: rgba(255, 255, 255, 0.5);\nborder-radius:10px;\npadding-left:5px;\npadding-top:2px;");

        // label_videoname
        ui->label_videoname->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgba(0, 0, 0, 0.3);\n\nborder-top-left-radius:10px;\nborder-top-right-radius:10px;\npadding-left:15px;");

        // widget_functionbar
        ui->widget_functionbar->setStyleSheet("border-top-left-radius:0px;\nborder-top-right-radius:0px;\nborder-bottom-left-radius:10px;\nborder-bottom-right-radius:10px;\nbackground-color: rgb(245, 245, 224);");

        // widget_navigation
        ui->widget_navigation->setStyleSheet("background-color: rgb(28, 63, 170);");
        ui->label_logoname->setStyleSheet("color: rgb(255, 255, 255);\nbackground-color: rgb(0, 85, 255);\nfont: 22pt 'Mistral';\nborder-radius:10px;");
        ui->pushButton_language->setStyleSheet("QPushButton {\ncolor:white;\nbackground-color: rgb(0, 85, 255);\nborder-radius:10px\n}\nQPushButton:hover {\nbackground-color: rgba(0, 85, 255, 0.7);\n}");
        ui->pushButton_mode->setStyleSheet("QPushButton {\ncolor:white;\nbackground-color: rgb(0, 85, 255);\nborder-radius:10px\n}\n\nQPushButton:hover {\nbackground-color: rgba(0, 85, 255, 0.7);\n}\n");
        ui->pushButton_FAQ->setStyleSheet("QPushButton {\ncolor:white;\nbackground-color: rgb(0, 85, 255);\nborder-radius:10px\n}\n\nQPushButton:hover {\nbackground-color: rgba(0, 85, 255, 0.7);\n}\n");

        // widget_player
        ui->widget_player->setStyleSheet("");
        ui->widget_toolbar->setStyleSheet("background-color: white;");
        ui->widget_video->setStyleSheet("background-color: lightgray;");

        // widget_videoslist
        ui->widget_videoslist->setStyleSheet("background-color: rgb(28, 63, 170);\nborder-radius:10px");
        ui->pushButton_uploadfile->setStyleSheet("QPushButton{\n	color:white;\n	background-color: rgb(0, 85, 255);\n}\nQPushButton:hover {\n	background-color: rgba(0, 85, 255, 0.7);\n}");
        ui->widget_searchbox->setStyleSheet("background-color: rgb(245, 245, 224); \nborder-radius: 10px;");
        ui->textEdit_search->setStyleSheet("background-color: white; \nborder-radius: 10px;");
    }

    //black
    else{
        ui->pushButton_mode->setText(ui->pushButton_language->isChecked() ? "夜间模式" : "Dark Model");
        ui->pushButton_mode->setFont(ui->pushButton_language->isChecked() ? chineseFont11 : englishFont11);

        this->setStyleSheet("background-color: rgb(18,18,18);\n");

        // widget_additionalfunction
        ui->widget_additionalfunction->setStyleSheet("border-radius:10px;\nbackground-color: rgb(44, 44, 44);");
        ui->label_comment->setStyleSheet("background-color: rgb(0, 53, 77);\ncolor: rgb(185, 185, 92);\npadding-right: 7px;\nborder-bottom-right-radius:0px;\nborder-bottom-left-radius:0px;\n");
        ui->pushButton_sendcomment->setStyleSheet("QPushButton {\ncolor: rgb(255, 255, 255);\nbackground-color: rgb(0, 85, 127);\n}\n\nQPushButton:hover {\nbackground-color: rgba(0, 85, 127, 0.7);\n}\n");
        ui->textEdit_comment->setStyleSheet("color: rgb(227, 227, 227);\nbackground-color: rgb(68, 68, 68);\nborder-radius:10px;\npadding-left:5px;\npadding-top:2px;");

        // label_videoname
        ui->label_videoname->setStyleSheet("color: rgb(185, 185, 92);\nbackground-color: rgb(0, 53, 77);\n\nborder-top-left-radius:10px;\nborder-top-right-radius:10px;\npadding-left:15px;");

        // widget_functionbar
        ui->widget_functionbar->setStyleSheet("border-top-left-radius:0px;\nborder-top-right-radius:0px;\nborder-bottom-left-radius:10px;\nborder-bottom-right-radius:10px;\nbackground-color: rgb(68, 68, 68);");

        // widget_navigation
        ui->widget_navigation->setStyleSheet("background-color: rgb(0, 53, 77);");
        ui->label_logoname->setStyleSheet("color: rgb(185, 185, 92);\nbackground-color: rgb(0, 85, 127);\nfont: 22pt 'Mistral';\nborder-radius:10px;");
        ui->pushButton_language->setStyleSheet("QPushButton {\ncolor:white;\nbackground-color: rgb(0, 85, 127);\nborder-radius:10px\n}\nQPushButton:hover {\nbackground-color: rgba(0, 85, 127, 0.7);\n}");
        ui->pushButton_mode->setStyleSheet("QPushButton {\ncolor:white;\nbackground-color: rgb(0, 85, 127);\nborder-radius:10px\n}\n\nQPushButton:hover {\nbackground-color: rgba(0, 85, 127, 0.7);\n}\n");
        ui->pushButton_FAQ->setStyleSheet("QPushButton {\ncolor:white;\nbackground-color: rgb(0, 85, 127);\nborder-radius:10px\n}\n\nQPushButton:hover {\nbackground-color: rgba(0, 85, 127, 0.7);\n}\n");

        // widget_player
        ui->widget_player->setStyleSheet("background-color: rgb(44, 44, 44);");
        ui->widget_toolbar->setStyleSheet("background-color: rgb(44, 44, 44);");
        ui->widget_video->setStyleSheet("background-color: rgb(44, 44, 44);");

        // widget_videoslist
        ui->widget_videoslist->setStyleSheet("background-color: rgb(0, 53, 77);\nborder-radius:10px");
        ui->pushButton_uploadfile->setStyleSheet("QPushButton{\nbackground-color: rgb(0, 85, 127);\n}\nQPushButton:hover {\n	background-color: rgba(0, 85, 127, 0.7);\n}");
        ui->widget_searchbox->setStyleSheet("background-color: rgb(0, 85, 127); \nborder-radius: 10px;");
        ui->textEdit_search->setStyleSheet("color: rgb(227, 227, 227);");
    }
}

// read in videos and thumbnails to this directory
std::vector<TheButtonInfo> MainWindow_player::getInfoIn(std::string loc)
{
    std::vector<TheButtonInfo> out = std::vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc));
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

        if (f.contains("."))

#if defined(_WIN32)
        if (f.contains(".wmv")) { // windows
#else
        if (f.contains(".mp4") || f.contains("MOV")) { // mac/linux
#endif

            QString thumb = f.left(f.length() - 4) + ".png";
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                QImage sprite = imageReader->read(); // read the thumbnail
                if (!sprite.isNull()) {
                    QIcon *ico = new QIcon(
                        QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                    QUrl *url = new QUrl(
                        QUrl::fromLocalFile(f)); // convert the file location to a generic url
                    out.push_back(TheButtonInfo(url, ico)); // add to the output list
                } else
                    qDebug() << "warning: skipping video because I couldn't process thumbnail "
                             << thumb << endl;
            } else
                qDebug() << "warning: skipping video because I couldn't find thumbnail "
                         << thumb << endl;
        }
    }

    return out;
}

void MainWindow_player::on_pushButton_uploadfile_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, ui->pushButton_language->isChecked() ? "选择文件夹" : "Choose videos file", QDir::homePath());
    std::string filepath = folderPath.toStdString();

    if (!folderPath.isEmpty()) {
        videos = getInfoIn(filepath);
        videosListInit(videos);
    }
}


void MainWindow_player::on_pushButton_FAQ_clicked()
{
    QLayout *tmpLayout = faqWindow.layout();
    ui->pushButton_playandpause->setChecked(0);

    if (tmpLayout) {

        faqWindow.show();
        return;
    }

    std::string faqText =
        "FAQ\n"
        "English version\n"
        "1. Why does the software show no available video to play when I try to launch it directly?\n"
        "Before playing a video, click on the button in the upper right corner to Choose your playback directory and the video you want to play. After completing this operation, you will be able to play the desired video.\n\n"
        "2.Why do some buttons in the software have no effect when clicked?\n"
        "The main functions of this software include playing, pausing, adjusting video volume, changing playback speed, uploading videos, switching interface language, and toggling between day and night modes. Other buttons are decorative and do not perform specific functions.\n\n"
        "3.Why do I encounter license issues when trying to launch the project?\n"
        "This is due to license verification failure caused by Qt's educational license. To resolve this issue, download the community version of Qt and try registering/logging in with your personal (non-educational) account.\n\n"
        "4.Why does Qt encounter errors during the Qmake process?\n"
        "If you encounter this issue, check the integrity of the current installation files and ensure that no additional modifications have been made to the files. Follow these steps:\n"
        "4.1 Click on the toolbar on the screen and select Maintenance Tool to launch it.\n"
        "4.2 Complete license login and verification.\n"
        "4.3 Select Add or Remove Components.\n"
        "4.4 Check whether it includes all components of Qt Design Studio 4.3.2, Qt 5.15.2, Qt Creator 12.0.1, Qt Creator 12.0.1 CDB Debugger Support, Debugging Tools for Windows (if you are using Windows), Qt Creator 12.0.1 Debug Symbols, Qt Creator 12.0.1 Plugin Development, MinGW 8.1.0 32-bit or MinGW 8.1.0 64-bit, Ninja 1.10.2, OpenSSL 3.0.12 Toolkit.\n"
        "4.5 If some components are not installed, check and install them.\n\n"
        "5.Does the software support streaming services like Netflix or YouTube?\n"
        "No, this software is a local video player and only supports basic local video playback.\n\n"
        "6.Does it support adjusting video quality or resolution?\n"
        "No, this software only supports playing videos in their original resolution.\n\n"
        "7.What video formats does the software support?\n"
        "The software supports WMV format on Windows, MP4 format on Mac, and MOC format on Linux.\n\n"
        "8.How does the software handle user data to protect privacy?\n"
        "All videos are played locally, and the software does not have online functionality. It does not upload or misuse user data.\n\n"
        "9.Can I use different language versions of the software for different regions?\n"
        "Yes, the software can automatically detect the current geographical location. If in China, the language will be set to Chinese. If the user is outside of China, the interface will be set to English.\n\n"
        "10.If the software encounters issues, how can I contact the corresponding personnel?\n\n"
        "Technical Support Contact:\n"
        "Email: 1940660815@qq.com, sc21jz2@leeds.ac.uk, Jingwei Zhang, Sheng Ning\n"
        "Address: Xian Road 999, Sichuan, Southwest Jiaotong University.\n"
        "-------------------------------------------------------------------\n"
        "Chinese version\n"
        "1. 为什么当我尝试直接启动软件的时候显示没有可用的播放视频？\n"
        "在播放视频之前，点击右上角的选择播放目录的按钮，选择你的播放目录和你需要播放的视频，完成操作后就能播放你需要的视频。\n\n"
        "2. 为什么软件中有些按钮点击之后没有对应的效果？\n"
        "本软件的主要功能是实现视频的播放、暂停、视频音量的调节、视频播放倍速调节、视频上传、界面语言切换，以及界面日间模式和夜间模式的切换。其他的按钮均为装饰性按钮。\n\n"
        "3. 为什么尝试启动项目的时候显示许可证问题？\n"
        "这是由于Qt的教育许可证导致的许可证验证失败问题。要解决这个问题，请下载社区版本的Qt并尝试使用自己的非教育账号（私人账号）注册登录。\n\n"
        "4. 为什么Qt在Qmake的过程中出现错误？\n"
        "如遇到此问题，请检查当前的安装文件的完整性，并确保没有对文件进行额外的改动。具体检查操作流程是：\n"
        "4.1点击屏幕上的工具栏，选择 Maintenance Tool 并启动 Maintenance Tool。\n"
        "4.2完成许可证的登录和验证。\n"
        "4.3选择添加或移除组件。\n"
        "4.4检查是否包含了Qt Design Studio 4.3.2，Qt 5.15.2 的所有组件，Developer and Designer Tools 中的Qt Creator 12.0.1，Qt Creator 12.0.1 CDB Debugger Support，Debugging Tools for Windows（如果你使用Windows系统），Qt Creator 12.0.1 Debug Symbols，Qt Creator 12.0.1 Plugin Development，MinGW 8.1.0 32-bit或者MinGW 8.1.0 64-bit，MinGW 8.1.0 64-bit，Ninja 1.10.2，OpenSSL 3.0.12 Toolkit。\n"
        "4.5如果出现部分组件未安装，勾选并安装组件。\n\n"
        "5.是否支持流媒体服务（如Netflix、YouTube等）？\n"
        "不能，此软件是本地的视频播放器，只支持基本的本地视频播放。\n\n"
        "6.是否支持画质或者分辨率的调整？\n"
        "不支持，本软件只支持原生分辨率播放视频。\n\n"
        "7.本软件支持的视频格式有哪些？\n"
        "软件支持Windows系统下WMV格式的视频播放，Mac系统下的MP4格式的视频播放，以及Linux系统下的MOC格式的视频播放。\n\n"
        "8.该软件如何处理用户数据保护用户隐私？\n"
        "对于所有的视频，均采用本地播放的形式，本软件不具备联网的功能，不会上传和滥用用户数据。\n\n"
        "9.对于不同的地区，我能使用不同语言版本的软件吗？\n"
        "可以，软件能够自动获取当前的地理位置。如果是在中国，则将语言自动设置为中文。如果用户地理位置在中国以外的地方，将会采取英文界面。\n\n"
        "10.软件出现问题，我如何联系对应的工作人员呢？\n\n"
        "技术人员联系方式：\n"
        "邮箱：1940660815@qq.com, sc21jz2@leeds.ac.uk,Jingwei Zhang, Sheng Ning\n"
        "联系地址：四川省犀安路999号，西南交通大学。\n";

    faqWindow.setWindowTitle("FaQ Viewer");
    faqWindow.setWindowModality(Qt::ApplicationModal);

    QTextEdit *textEdit = new QTextEdit(&faqWindow);
    textEdit->setPlainText(QString::fromStdString(faqText));
    textEdit->setReadOnly(true);

    // 创建垂直布局，并将QTextEdit添加到布局中
    QVBoxLayout *layout = new QVBoxLayout(&faqWindow);
    layout->addWidget(textEdit);

    // 设置布局到faqWindow
    faqWindow.setLayout(layout);
    faqWindow.setGeometry(this->x() + this->width() / 3,
                          this->y() + this->height() / 3,
                          this->width() / 3,
                          this->height() / 3);

    faqWindow.show();
}

