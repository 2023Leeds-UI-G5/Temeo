/********************************************************************************
** Form generated from reading UI file 'mainwindow_player.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_PLAYER_H
#define UI_MAINWINDOW_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_player
{
public:
    QWidget *centralwidget;
    QWidget *widget_additionalfunction;
    QPushButton *pushButton_sendcomment;
    QPushButton *pushButton_self;
    QTextEdit *textEdit_comment;
    QLabel *label_comment;
    QLabel *label_logoname_3;
    QWidget *widget_navigation;
    QPushButton *pushButton_language;
    QFrame *line_3;
    QLabel *label_logoname;
    QPushButton *pushButton_account;
    QFrame *line_4;
    QPushButton *pushButton_selficon;
    QPushButton *pushButton_likelist;
    QPushButton *pushButton_collection;
    QPushButton *pushButton_screenshotlibrary;
    QPushButton *pushButton_mode;
    QFrame *line_5;
    QWidget *widget_player;
    QVideoWidget *widget_video;
    QLabel *label_videoname;
    QWidget *widget_toolbar;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_playandpause;
    QPushButton *pushButton_playspeed;
    QLabel *label_position;
    QPushButton *pushButton_moveback;
    QSlider *horizontalSlider_position;
    QPushButton *pushButton_movefoward;
    QLabel *label_duration;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volume;
    QPushButton *pushButton_screenshot;
    QPushButton *pushButton_screencontrol;
    QPushButton *pushButton_like;
    QPushButton *pushButton_collect;
    QPushButton *pushButton_share;
    QFrame *line_6;
    QFrame *line_2;
    QWidget *widget_videoslist;
    QLabel *label_videoslist;
    QScrollArea *scrollArea_videoslist;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widget_searchbox;
    QPushButton *pushButton_search;
    QTextEdit *textEdit_search;
    QLabel *label_logoname_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_player)
    {
        if (MainWindow_player->objectName().isEmpty())
            MainWindow_player->setObjectName("MainWindow_player");
        MainWindow_player->setWindowModality(Qt::ApplicationModal);
        MainWindow_player->resize(1366, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow_player->sizePolicy().hasHeightForWidth());
        MainWindow_player->setSizePolicy(sizePolicy);
        MainWindow_player->setMinimumSize(QSize(1366, 768));
        MainWindow_player->setMaximumSize(QSize(3780, 2160));
        MainWindow_player->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 238);\n"
""));
        centralwidget = new QWidget(MainWindow_player);
        centralwidget->setObjectName("centralwidget");
        widget_additionalfunction = new QWidget(centralwidget);
        widget_additionalfunction->setObjectName("widget_additionalfunction");
        widget_additionalfunction->setGeometry(QRect(210, 520, 841, 201));
        widget_additionalfunction->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_sendcomment = new QPushButton(widget_additionalfunction);
        pushButton_sendcomment->setObjectName("pushButton_sendcomment");
        pushButton_sendcomment->setGeometry(QRect(720, 160, 81, 31));
        QFont font;
        font.setWeight(QFont::DemiBold);
        pushButton_sendcomment->setFont(font);
        pushButton_sendcomment->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sendcomment->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"\n"
"background-color: rgb(55, 125, 255);\n"
"font-weight:600;\n"
"font-size:16px"));
        pushButton_sendcomment->setIconSize(QSize(16, 16));
        pushButton_self = new QPushButton(widget_additionalfunction);
        pushButton_self->setObjectName("pushButton_self");
        pushButton_self->setGeometry(QRect(30, 90, 52, 51));
        pushButton_self->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\346\225\260\345\200\274 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235\357\274\214\344\273\245\347\241\256\344\277\235\345\206\205\345\256\271\344\270\215\344\274\232\350\247\246\347\242\260\345\210\260\350\276\271\347\274\230 */\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("src/mine_\346\210\221\347\232\204.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_self->setIcon(icon);
        pushButton_self->setIconSize(QSize(40, 40));
        textEdit_comment = new QTextEdit(widget_additionalfunction);
        textEdit_comment->setObjectName("textEdit_comment");
        textEdit_comment->setGeometry(QRect(90, 90, 711, 61));
        textEdit_comment->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit_comment->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 45);\n"
"background-color: rgb(247, 247, 247);\n"
"border-radius:10px;\n"
"padding-left:5px;\n"
"padding-top:2px;"));
        label_comment = new QLabel(widget_additionalfunction);
        label_comment->setObjectName("label_comment");
        label_comment->setGeometry(QRect(0, 0, 841, 61));
        QFont font1;
        font1.setBold(true);
        label_comment->setFont(font1);
        label_comment->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 63, 170);\n"
"color: rgb(255, 255, 255);\n"
"font-size:25px;\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"font-weight:700;"));
        label_comment->setLineWidth(1);
        label_logoname_3 = new QLabel(widget_additionalfunction);
        label_logoname_3->setObjectName("label_logoname_3");
        label_logoname_3->setGeometry(QRect(20, 10, 101, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Mistral")});
        font2.setPointSize(22);
        font2.setBold(false);
        font2.setItalic(false);
        label_logoname_3->setFont(font2);
        label_logoname_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 255);\n"
"font: 22pt \"Mistral\";\n"
"\n"
""));
        widget_navigation = new QWidget(centralwidget);
        widget_navigation->setObjectName("widget_navigation");
        widget_navigation->setGeometry(QRect(0, 0, 181, 741));
        widget_navigation->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 63, 170);"));
        pushButton_language = new QPushButton(widget_navigation);
        pushButton_language->setObjectName("pushButton_language");
        pushButton_language->setGeometry(QRect(10, 690, 161, 31));
        pushButton_language->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 600 9pt \"Yu Gothic UI Semibold\";\n"
"background-color: rgb(0, 85, 255);\n"
"border-radius:10px\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("src/userlmn_cdd0880bc13ce3695381c0cfd12147c8.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("src/userlmn_53281e7eb797d755c8df2bd1c7f16340.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_language->setIcon(icon1);
        pushButton_language->setCheckable(true);
        line_3 = new QFrame(widget_navigation);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(10, 50, 181, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_logoname = new QLabel(widget_navigation);
        label_logoname->setObjectName("label_logoname");
        label_logoname->setGeometry(QRect(20, 10, 141, 31));
        label_logoname->setFont(font2);
        label_logoname->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 255);\n"
"font: 22pt \"Mistral\";\n"
"border-radius:10px"));
        pushButton_account = new QPushButton(widget_navigation);
        pushButton_account->setObjectName("pushButton_account");
        pushButton_account->setGeometry(QRect(70, 80, 71, 23));
        pushButton_account->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_account->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"font-weight:800;\n"
"font-size:17px\n"
""));
        line_4 = new QFrame(widget_navigation);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 620, 181, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        pushButton_selficon = new QPushButton(widget_navigation);
        pushButton_selficon->setObjectName("pushButton_selficon");
        pushButton_selficon->setGeometry(QRect(20, 70, 48, 42));
        pushButton_selficon->setStyleSheet(QString::fromUtf8("border-radius:10px"));
        pushButton_selficon->setIcon(icon);
        pushButton_selficon->setIconSize(QSize(36, 36));
        pushButton_likelist = new QPushButton(widget_navigation);
        pushButton_likelist->setObjectName("pushButton_likelist");
        pushButton_likelist->setGeometry(QRect(20, 153, 111, 20));
        pushButton_likelist->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_likelist->setStyleSheet(QString::fromUtf8("text-align:left;\n"
"color:white;\n"
"border-radius:10px;\n"
"font-size:16px;\n"
"font-weight:500;\n"
"text-align:center;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("src/userlmn_e1e7ac054e37e95eff57eb4051a2cab2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_likelist->setIcon(icon2);
        pushButton_collection = new QPushButton(widget_navigation);
        pushButton_collection->setObjectName("pushButton_collection");
        pushButton_collection->setGeometry(QRect(20, 200, 121, 20));
        pushButton_collection->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_collection->setStyleSheet(QString::fromUtf8("text-align:left;\n"
"color:white;\n"
"border-radius:10px;\n"
"font-size:16px;\n"
"font-weight:500;\n"
"text-align:center;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("src/userlmn_6d6eb0a97316eae95cb5872e3d1c7454.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_collection->setIcon(icon3);
        pushButton_screenshotlibrary = new QPushButton(widget_navigation);
        pushButton_screenshotlibrary->setObjectName("pushButton_screenshotlibrary");
        pushButton_screenshotlibrary->setGeometry(QRect(20, 250, 101, 20));
        pushButton_screenshotlibrary->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_screenshotlibrary->setStyleSheet(QString::fromUtf8("text-align:left;\n"
"font-size:16px;\n"
"\n"
"color:white;\n"
"border-radius:10px;\n"
"font-weight:500;\n"
"text-align:center;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("src/userlmn_278961458b697c458f364e56c206c7c7.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_screenshotlibrary->setIcon(icon4);
        pushButton_mode = new QPushButton(widget_navigation);
        pushButton_mode->setObjectName("pushButton_mode");
        pushButton_mode->setGeometry(QRect(10, 650, 161, 31));
        pushButton_mode->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 600 9pt \"Yu Gothic UI Semibold\";\n"
"background-color: rgb(0, 85, 255);\n"
"border-radius:10px\n"
""));
        pushButton_mode->setCheckable(true);
        line_5 = new QFrame(widget_navigation);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(10, 120, 181, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        widget_player = new QWidget(centralwidget);
        widget_player->setObjectName("widget_player");
        widget_player->setGeometry(QRect(210, 30, 841, 471));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_player->sizePolicy().hasHeightForWidth());
        widget_player->setSizePolicy(sizePolicy1);
        widget_player->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        widget_video = new QVideoWidget(widget_player);
        widget_video->setObjectName("widget_video");
        widget_video->setGeometry(QRect(0, 0, 841, 431));
        sizePolicy1.setHeightForWidth(widget_video->sizePolicy().hasHeightForWidth());
        widget_video->setSizePolicy(sizePolicy1);
        widget_video->setMinimumSize(QSize(0, 183));
        widget_video->setCursor(QCursor(Qt::PointingHandCursor));
        widget_video->setStyleSheet(QString::fromUtf8("background-color: lightgray;\n"
"border-bottom-left-radius:0px;\n"
"border-bottom-right-radius:0px;\n"
"border-top-left-radius:10px;\n"
"border-top-right-radius:10px;"));
        label_videoname = new QLabel(widget_video);
        label_videoname->setObjectName("label_videoname");
        label_videoname->setGeometry(QRect(0, 0, 841, 51));
        QFont font3;
        font3.setWeight(QFont::DemiBold);
        font3.setItalic(false);
        label_videoname->setFont(font3);
        label_videoname->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(136, 136, 136, 30);\n"
"font-size:20px;\n"
"font: 600 \"Yu Gothic UI Semibold\";\n"
"padding-left:15px;"));
        widget_toolbar = new QWidget(widget_player);
        widget_toolbar->setObjectName("widget_toolbar");
        widget_toolbar->setGeometry(QRect(0, 400, 841, 31));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_toolbar->sizePolicy().hasHeightForWidth());
        widget_toolbar->setSizePolicy(sizePolicy2);
        widget_toolbar->setStyleSheet(QString::fromUtf8("background-color: rgba(102, 103, 96, 180);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"border-bottom-right-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"opacity:0;\n"
"border:0px;\n"
"padding-bottom:2px;\n"
"padding-top:2px;\n"
"padding-left:2px;\n"
"padding-right:2px;"));
        formLayout = new QFormLayout(widget_toolbar);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(6, 3, 6, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        pushButton_playandpause = new QPushButton(widget_toolbar);
        pushButton_playandpause->setObjectName("pushButton_playandpause");
        pushButton_playandpause->setMinimumSize(QSize(23, 23));
        pushButton_playandpause->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icons/src/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/new/icons/src/pause.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_playandpause->setIcon(icon5);
        pushButton_playandpause->setCheckable(true);

        horizontalLayout->addWidget(pushButton_playandpause);

        pushButton_playspeed = new QPushButton(widget_toolbar);
        pushButton_playspeed->setObjectName("pushButton_playspeed");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_playspeed->sizePolicy().hasHeightForWidth());
        pushButton_playspeed->setSizePolicy(sizePolicy3);
        pushButton_playspeed->setMaximumSize(QSize(40, 16777215));
        pushButton_playspeed->setStyleSheet(QString::fromUtf8("color: rgb(143, 143, 143);"));

        horizontalLayout->addWidget(pushButton_playspeed);

        label_position = new QLabel(widget_toolbar);
        label_position->setObjectName("label_position");
        sizePolicy3.setHeightForWidth(label_position->sizePolicy().hasHeightForWidth());
        label_position->setSizePolicy(sizePolicy3);
        label_position->setStyleSheet(QString::fromUtf8("color: rgb(143, 143, 143);"));

        horizontalLayout->addWidget(label_position);

        pushButton_moveback = new QPushButton(widget_toolbar);
        pushButton_moveback->setObjectName("pushButton_moveback");
        sizePolicy3.setHeightForWidth(pushButton_moveback->sizePolicy().hasHeightForWidth());
        pushButton_moveback->setSizePolicy(sizePolicy3);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/icons/src/moveback.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_moveback->setIcon(icon6);

        horizontalLayout->addWidget(pushButton_moveback);

        horizontalSlider_position = new QSlider(widget_toolbar);
        horizontalSlider_position->setObjectName("horizontalSlider_position");
        horizontalSlider_position->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_position);

        pushButton_movefoward = new QPushButton(widget_toolbar);
        pushButton_movefoward->setObjectName("pushButton_movefoward");
        sizePolicy3.setHeightForWidth(pushButton_movefoward->sizePolicy().hasHeightForWidth());
        pushButton_movefoward->setSizePolicy(sizePolicy3);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/icons/src/movefoward.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_movefoward->setIcon(icon7);

        horizontalLayout->addWidget(pushButton_movefoward);

        label_duration = new QLabel(widget_toolbar);
        label_duration->setObjectName("label_duration");
        sizePolicy3.setHeightForWidth(label_duration->sizePolicy().hasHeightForWidth());
        label_duration->setSizePolicy(sizePolicy3);
        label_duration->setStyleSheet(QString::fromUtf8("color: rgb(143, 143, 143);"));

        horizontalLayout->addWidget(label_duration);

        pushButton_volume = new QPushButton(widget_toolbar);
        pushButton_volume->setObjectName("pushButton_volume");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/icons/src/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/new/icons/src/mutevolume.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_volume->setIcon(icon8);
        pushButton_volume->setCheckable(true);

        horizontalLayout->addWidget(pushButton_volume);

        horizontalSlider_volume = new QSlider(widget_toolbar);
        horizontalSlider_volume->setObjectName("horizontalSlider_volume");
        sizePolicy3.setHeightForWidth(horizontalSlider_volume->sizePolicy().hasHeightForWidth());
        horizontalSlider_volume->setSizePolicy(sizePolicy3);
        horizontalSlider_volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_volume);

        pushButton_screenshot = new QPushButton(widget_toolbar);
        pushButton_screenshot->setObjectName("pushButton_screenshot");
        pushButton_screenshot->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/icons/src/screenshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_screenshot->setIcon(icon9);
        pushButton_screenshot->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_screenshot);

        pushButton_screencontrol = new QPushButton(widget_toolbar);
        pushButton_screencontrol->setObjectName("pushButton_screencontrol");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/icons/src/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/new/icons/src/smallscreen.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_screencontrol->setIcon(icon10);
        pushButton_screencontrol->setCheckable(true);

        horizontalLayout->addWidget(pushButton_screencontrol);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        pushButton_like = new QPushButton(widget_player);
        pushButton_like->setObjectName("pushButton_like");
        pushButton_like->setGeometry(QRect(120, 437, 32, 26));
        pushButton_like->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("src/like gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/new/icons/src/liked.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_like->setIcon(icon11);
        pushButton_like->setIconSize(QSize(20, 20));
        pushButton_like->setCheckable(true);
        pushButton_collect = new QPushButton(widget_player);
        pushButton_collect->setObjectName("pushButton_collect");
        pushButton_collect->setGeometry(QRect(410, 440, 32, 26));
        pushButton_collect->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("src/collect gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/new/icons/src/collected.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_collect->setIcon(icon12);
        pushButton_collect->setIconSize(QSize(20, 20));
        pushButton_collect->setCheckable(true);
        pushButton_share = new QPushButton(widget_player);
        pushButton_share->setObjectName("pushButton_share");
        pushButton_share->setGeometry(QRect(680, 440, 32, 26));
        pushButton_share->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("src/share gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_share->setIcon(icon13);
        pushButton_share->setIconSize(QSize(20, 20));
        line_6 = new QFrame(widget_player);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(560, 435, 16, 31));
        line_6->setStyleSheet(QString::fromUtf8("border-left:2px solid rgb(186, 186, 186);"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widget_player);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(280, 435, 16, 31));
        line_2->setStyleSheet(QString::fromUtf8("border-left:2px solid rgb(186, 186, 186);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget_videoslist = new QWidget(centralwidget);
        widget_videoslist->setObjectName("widget_videoslist");
        widget_videoslist->setGeometry(QRect(1080, 30, 261, 721));
        widget_videoslist->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 63, 170);\n"
"border-radius:10px"));
        label_videoslist = new QLabel(widget_videoslist);
        label_videoslist->setObjectName("label_videoslist");
        label_videoslist->setGeometry(QRect(20, 60, 211, 31));
        sizePolicy2.setHeightForWidth(label_videoslist->sizePolicy().hasHeightForWidth());
        label_videoslist->setSizePolicy(sizePolicy2);
        label_videoslist->setFont(font1);
        label_videoslist->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size:20px;\n"
"font-weight:700;"));
        scrollArea_videoslist = new QScrollArea(widget_videoslist);
        scrollArea_videoslist->setObjectName("scrollArea_videoslist");
        scrollArea_videoslist->setGeometry(QRect(10, 150, 241, 551));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea_videoslist->sizePolicy().hasHeightForWidth());
        scrollArea_videoslist->setSizePolicy(sizePolicy4);
        scrollArea_videoslist->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_videoslist->setStyleSheet(QString::fromUtf8("background-color: rgba(207, 207, 207, 50);"));
        scrollArea_videoslist->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 241, 551));
        scrollArea_videoslist->setWidget(scrollAreaWidgetContents_2);
        widget_searchbox = new QWidget(widget_videoslist);
        widget_searchbox->setObjectName("widget_searchbox");
        widget_searchbox->setGeometry(QRect(10, 100, 241, 31));
        widget_searchbox->setStyleSheet(QString::fromUtf8("background-color: white; \n"
"border-radius: 10px;"));
        pushButton_search = new QPushButton(widget_searchbox);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(200, 0, 31, 31));
        pushButton_search->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_search->setStyleSheet(QString::fromUtf8(""));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/icons/src/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_search->setIcon(icon14);
        textEdit_search = new QTextEdit(widget_searchbox);
        textEdit_search->setObjectName("textEdit_search");
        textEdit_search->setGeometry(QRect(0, 0, 181, 31));
        textEdit_search->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_logoname_4 = new QLabel(widget_videoslist);
        label_logoname_4->setObjectName("label_logoname_4");
        label_logoname_4->setGeometry(QRect(20, 20, 101, 31));
        label_logoname_4->setFont(font2);
        label_logoname_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 255);\n"
"font: 22pt \"Mistral\";\n"
"\n"
""));
        MainWindow_player->setCentralWidget(centralwidget);
        widget_videoslist->raise();
        widget_additionalfunction->raise();
        widget_navigation->raise();
        widget_player->raise();
        statusbar = new QStatusBar(MainWindow_player);
        statusbar->setObjectName("statusbar");
        MainWindow_player->setStatusBar(statusbar);

        retranslateUi(MainWindow_player);

        QMetaObject::connectSlotsByName(MainWindow_player);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_player)
    {
        MainWindow_player->setWindowTitle(QCoreApplication::translate("MainWindow_player", "MainWindow", nullptr));
        pushButton_sendcomment->setText(QCoreApplication::translate("MainWindow_player", "Post", nullptr));
        pushButton_self->setText(QString());
        textEdit_comment->setPlaceholderText(QCoreApplication::translate("MainWindow_player", "type the comment...", nullptr));
        label_comment->setText(QCoreApplication::translate("MainWindow_player", "                       Write down your opinion!", nullptr));
        label_logoname_3->setText(QCoreApplication::translate("MainWindow_player", "  Temeo", nullptr));
        pushButton_language->setText(QCoreApplication::translate("MainWindow_player", "Change Language", nullptr));
        label_logoname->setText(QCoreApplication::translate("MainWindow_player", " Temeo beta", nullptr));
        pushButton_account->setText(QCoreApplication::translate("MainWindow_player", "Account", nullptr));
        pushButton_selficon->setText(QString());
        pushButton_likelist->setText(QCoreApplication::translate("MainWindow_player", "Like List", nullptr));
        pushButton_collection->setText(QCoreApplication::translate("MainWindow_player", "Collection", nullptr));
        pushButton_screenshotlibrary->setText(QCoreApplication::translate("MainWindow_player", "Library", nullptr));
        pushButton_mode->setText(QCoreApplication::translate("MainWindow_player", "Dark mode", nullptr));
        label_videoname->setText(QCoreApplication::translate("MainWindow_player", "a.wmv", nullptr));
        pushButton_playandpause->setText(QString());
        pushButton_playspeed->setText(QCoreApplication::translate("MainWindow_player", "1.0x", nullptr));
        label_position->setText(QCoreApplication::translate("MainWindow_player", "00:00:00", nullptr));
        pushButton_moveback->setText(QString());
        pushButton_movefoward->setText(QString());
        label_duration->setText(QCoreApplication::translate("MainWindow_player", "00:00:00", nullptr));
        pushButton_volume->setText(QString());
        pushButton_screenshot->setText(QString());
        pushButton_screencontrol->setText(QString());
        pushButton_like->setText(QString());
        pushButton_collect->setText(QString());
        pushButton_share->setText(QString());
        label_videoslist->setText(QCoreApplication::translate("MainWindow_player", "Grab You Like!", nullptr));
        pushButton_search->setText(QString());
        textEdit_search->setPlaceholderText(QCoreApplication::translate("MainWindow_player", "type to search...", nullptr));
        label_logoname_4->setText(QCoreApplication::translate("MainWindow_player", "  Temeo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_player: public Ui_MainWindow_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_PLAYER_H
