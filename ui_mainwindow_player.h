/********************************************************************************
** Form generated from reading UI file 'mainwindow_player.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_PLAYER_H
#define UI_MAINWINDOW_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
#include <qvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_player
{
public:
    QWidget *centralwidget;
    QWidget *widget_additionalfunction;
    QPushButton *pushButton_like;
    QPushButton *pushButton_share;
    QPushButton *pushButton_screenshot;
    QPushButton *pushButton_sendcomment;
    QFrame *line;
    QPushButton *pushButton_self;
    QLabel *label_comment;
    QPushButton *pushButton_collect;
    QTextEdit *textEdit_comment;
    QWidget *widget_navigation;
    QPushButton *pushButton_language;
    QFrame *line_3;
    QPushButton *pushButton_logo;
    QLabel *label_logoname;
    QPushButton *pushButton_account;
    QFrame *line_4;
    QPushButton *pushButton_selficon;
    QPushButton *pushButton_likelist;
    QPushButton *pushButton_collection;
    QPushButton *pushButton_screenshotlibrary;
    QWidget *widget_player;
    QVideoWidget *widget_video;
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
    QPushButton *pushButton_screencontrol;
    QWidget *widget_videoslist;
    QLabel *label_videoslist;
    QScrollArea *scrollArea_videoslist;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widget_searchbox;
    QPushButton *pushButton_search;
    QTextEdit *textEdit_search;
    QWidget *widget_tittle;
    QLabel *label_videotittle;
    QLabel *label_videoname;
    QFrame *line_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_player)
    {
        if (MainWindow_player->objectName().isEmpty())
            MainWindow_player->setObjectName(QString::fromUtf8("MainWindow_player"));
        MainWindow_player->setWindowModality(Qt::ApplicationModal);
        MainWindow_player->resize(1366, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow_player->sizePolicy().hasHeightForWidth());
        MainWindow_player->setSizePolicy(sizePolicy);
        MainWindow_player->setMinimumSize(QSize(1366, 768));
        MainWindow_player->setMaximumSize(QSize(3780, 2160));
        MainWindow_player->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow_player);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_additionalfunction = new QWidget(centralwidget);
        widget_additionalfunction->setObjectName(QString::fromUtf8("widget_additionalfunction"));
        widget_additionalfunction->setGeometry(QRect(210, 570, 841, 161));
        pushButton_like = new QPushButton(widget_additionalfunction);
        pushButton_like->setObjectName(QString::fromUtf8("pushButton_like"));
        pushButton_like->setGeometry(QRect(10, 10, 32, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/src/like.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/icons/src/liked.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_like->setIcon(icon);
        pushButton_like->setIconSize(QSize(20, 20));
        pushButton_like->setCheckable(true);
        pushButton_share = new QPushButton(widget_additionalfunction);
        pushButton_share->setObjectName(QString::fromUtf8("pushButton_share"));
        pushButton_share->setGeometry(QRect(110, 10, 32, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/src/share.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_share->setIcon(icon1);
        pushButton_share->setIconSize(QSize(20, 20));
        pushButton_screenshot = new QPushButton(widget_additionalfunction);
        pushButton_screenshot->setObjectName(QString::fromUtf8("pushButton_screenshot"));
        pushButton_screenshot->setGeometry(QRect(790, 10, 32, 26));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/src/screenshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_screenshot->setIcon(icon2);
        pushButton_screenshot->setIconSize(QSize(20, 20));
        pushButton_sendcomment = new QPushButton(widget_additionalfunction);
        pushButton_sendcomment->setObjectName(QString::fromUtf8("pushButton_sendcomment"));
        pushButton_sendcomment->setGeometry(QRect(700, 90, 101, 51));
        QFont font;
        font.setPointSize(15);
        pushButton_sendcomment->setFont(font);
        pushButton_sendcomment->setStyleSheet(QString::fromUtf8(""));
        pushButton_sendcomment->setIconSize(QSize(16, 16));
        line = new QFrame(widget_additionalfunction);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 841, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_self = new QPushButton(widget_additionalfunction);
        pushButton_self->setObjectName(QString::fromUtf8("pushButton_self"));
        pushButton_self->setGeometry(QRect(30, 90, 52, 51));
        pushButton_self->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 10px; /* \350\256\276\347\275\256\345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\346\225\260\345\200\274 */\n"
"    padding: 10px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235\357\274\214\344\273\245\347\241\256\344\277\235\345\206\205\345\256\271\344\270\215\344\274\232\350\247\246\347\242\260\345\210\260\350\276\271\347\274\230 */\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/src/account.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_self->setIcon(icon3);
        pushButton_self->setIconSize(QSize(40, 40));
        label_comment = new QLabel(widget_additionalfunction);
        label_comment->setObjectName(QString::fromUtf8("label_comment"));
        label_comment->setGeometry(QRect(30, 50, 111, 31));
        label_comment->setFont(font);
        pushButton_collect = new QPushButton(widget_additionalfunction);
        pushButton_collect->setObjectName(QString::fromUtf8("pushButton_collect"));
        pushButton_collect->setGeometry(QRect(60, 10, 32, 26));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/src/collect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/new/icons/src/collected.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_collect->setIcon(icon4);
        pushButton_collect->setIconSize(QSize(20, 20));
        pushButton_collect->setCheckable(true);
        textEdit_comment = new QTextEdit(widget_additionalfunction);
        textEdit_comment->setObjectName(QString::fromUtf8("textEdit_comment"));
        textEdit_comment->setGeometry(QRect(110, 90, 541, 51));
        widget_navigation = new QWidget(centralwidget);
        widget_navigation->setObjectName(QString::fromUtf8("widget_navigation"));
        widget_navigation->setGeometry(QRect(-10, 0, 161, 751));
        widget_navigation->setStyleSheet(QString::fromUtf8("background-color: gray; "));
        pushButton_language = new QPushButton(widget_navigation);
        pushButton_language->setObjectName(QString::fromUtf8("pushButton_language"));
        pushButton_language->setGeometry(QRect(10, 700, 151, 23));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icons/src/languageEnglish.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/new/icons/src/languageChinese.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_language->setIcon(icon5);
        pushButton_language->setCheckable(true);
        line_3 = new QFrame(widget_navigation);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 50, 151, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton_logo = new QPushButton(widget_navigation);
        pushButton_logo->setObjectName(QString::fromUtf8("pushButton_logo"));
        pushButton_logo->setGeometry(QRect(20, 12, 31, 31));
        QFont font1;
        font1.setPointSize(18);
        pushButton_logo->setFont(font1);
        label_logoname = new QLabel(widget_navigation);
        label_logoname->setObjectName(QString::fromUtf8("label_logoname"));
        label_logoname->setGeometry(QRect(60, 20, 53, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Onyx"));
        font2.setPointSize(20);
        label_logoname->setFont(font2);
        pushButton_account = new QPushButton(widget_navigation);
        pushButton_account->setObjectName(QString::fromUtf8("pushButton_account"));
        pushButton_account->setGeometry(QRect(70, 80, 71, 23));
        line_4 = new QFrame(widget_navigation);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 670, 151, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        pushButton_selficon = new QPushButton(widget_navigation);
        pushButton_selficon->setObjectName(QString::fromUtf8("pushButton_selficon"));
        pushButton_selficon->setGeometry(QRect(20, 70, 48, 42));
        pushButton_selficon->setStyleSheet(QString::fromUtf8(""));
        pushButton_selficon->setIcon(icon3);
        pushButton_selficon->setIconSize(QSize(36, 36));
        pushButton_likelist = new QPushButton(widget_navigation);
        pushButton_likelist->setObjectName(QString::fromUtf8("pushButton_likelist"));
        pushButton_likelist->setGeometry(QRect(20, 130, 131, 23));
        pushButton_likelist->setStyleSheet(QString::fromUtf8("text-align:left;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/icons/src/like.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_likelist->setIcon(icon6);
        pushButton_collection = new QPushButton(widget_navigation);
        pushButton_collection->setObjectName(QString::fromUtf8("pushButton_collection"));
        pushButton_collection->setGeometry(QRect(20, 170, 131, 23));
        pushButton_collection->setStyleSheet(QString::fromUtf8("text-align:left;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/icons/src/collect.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_collection->setIcon(icon7);
        pushButton_screenshotlibrary = new QPushButton(widget_navigation);
        pushButton_screenshotlibrary->setObjectName(QString::fromUtf8("pushButton_screenshotlibrary"));
        pushButton_screenshotlibrary->setGeometry(QRect(20, 210, 131, 23));
        pushButton_screenshotlibrary->setStyleSheet(QString::fromUtf8("text-align:left;"));
        pushButton_screenshotlibrary->setIcon(icon2);
        widget_player = new QWidget(centralwidget);
        widget_player->setObjectName(QString::fromUtf8("widget_player"));
        widget_player->setGeometry(QRect(210, 100, 841, 461));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_player->sizePolicy().hasHeightForWidth());
        widget_player->setSizePolicy(sizePolicy1);
        widget_video = new QVideoWidget(widget_player);
        widget_video->setObjectName(QString::fromUtf8("widget_video"));
        widget_video->setGeometry(QRect(0, 0, 841, 431));
        sizePolicy1.setHeightForWidth(widget_video->sizePolicy().hasHeightForWidth());
        widget_video->setSizePolicy(sizePolicy1);
        widget_video->setMinimumSize(QSize(0, 183));
        widget_video->setCursor(QCursor(Qt::PointingHandCursor));
        widget_video->setStyleSheet(QString::fromUtf8("background-color: lightgray;"));
        widget_toolbar = new QWidget(widget_player);
        widget_toolbar->setObjectName(QString::fromUtf8("widget_toolbar"));
        widget_toolbar->setGeometry(QRect(0, 430, 841, 31));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_toolbar->sizePolicy().hasHeightForWidth());
        widget_toolbar->setSizePolicy(sizePolicy2);
        widget_toolbar->setStyleSheet(QString::fromUtf8("background-color: white;"));
        formLayout = new QFormLayout(widget_toolbar);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(6, 3, 6, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        pushButton_playandpause = new QPushButton(widget_toolbar);
        pushButton_playandpause->setObjectName(QString::fromUtf8("pushButton_playandpause"));
        pushButton_playandpause->setMinimumSize(QSize(23, 23));
        pushButton_playandpause->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/icons/src/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/new/icons/src/pause.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_playandpause->setIcon(icon8);
        pushButton_playandpause->setCheckable(true);

        horizontalLayout->addWidget(pushButton_playandpause);

        pushButton_playspeed = new QPushButton(widget_toolbar);
        pushButton_playspeed->setObjectName(QString::fromUtf8("pushButton_playspeed"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_playspeed->sizePolicy().hasHeightForWidth());
        pushButton_playspeed->setSizePolicy(sizePolicy3);
        pushButton_playspeed->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_playspeed);

        label_position = new QLabel(widget_toolbar);
        label_position->setObjectName(QString::fromUtf8("label_position"));
        sizePolicy3.setHeightForWidth(label_position->sizePolicy().hasHeightForWidth());
        label_position->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(label_position);

        pushButton_moveback = new QPushButton(widget_toolbar);
        pushButton_moveback->setObjectName(QString::fromUtf8("pushButton_moveback"));
        sizePolicy3.setHeightForWidth(pushButton_moveback->sizePolicy().hasHeightForWidth());
        pushButton_moveback->setSizePolicy(sizePolicy3);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/icons/src/moveback.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_moveback->setIcon(icon9);

        horizontalLayout->addWidget(pushButton_moveback);

        horizontalSlider_position = new QSlider(widget_toolbar);
        horizontalSlider_position->setObjectName(QString::fromUtf8("horizontalSlider_position"));
        horizontalSlider_position->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_position);

        pushButton_movefoward = new QPushButton(widget_toolbar);
        pushButton_movefoward->setObjectName(QString::fromUtf8("pushButton_movefoward"));
        sizePolicy3.setHeightForWidth(pushButton_movefoward->sizePolicy().hasHeightForWidth());
        pushButton_movefoward->setSizePolicy(sizePolicy3);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/icons/src/movefoward.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_movefoward->setIcon(icon10);

        horizontalLayout->addWidget(pushButton_movefoward);

        label_duration = new QLabel(widget_toolbar);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));
        sizePolicy3.setHeightForWidth(label_duration->sizePolicy().hasHeightForWidth());
        label_duration->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(label_duration);

        pushButton_volume = new QPushButton(widget_toolbar);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/icons/src/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/new/icons/src/mutevolume.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_volume->setIcon(icon11);
        pushButton_volume->setCheckable(true);

        horizontalLayout->addWidget(pushButton_volume);

        horizontalSlider_volume = new QSlider(widget_toolbar);
        horizontalSlider_volume->setObjectName(QString::fromUtf8("horizontalSlider_volume"));
        sizePolicy3.setHeightForWidth(horizontalSlider_volume->sizePolicy().hasHeightForWidth());
        horizontalSlider_volume->setSizePolicy(sizePolicy3);
        horizontalSlider_volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_volume);

        pushButton_screencontrol = new QPushButton(widget_toolbar);
        pushButton_screencontrol->setObjectName(QString::fromUtf8("pushButton_screencontrol"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/icons/src/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/new/icons/src/smallscreen.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_screencontrol->setIcon(icon12);
        pushButton_screencontrol->setCheckable(true);

        horizontalLayout->addWidget(pushButton_screencontrol);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        widget_videoslist = new QWidget(centralwidget);
        widget_videoslist->setObjectName(QString::fromUtf8("widget_videoslist"));
        widget_videoslist->setGeometry(QRect(1100, 30, 241, 691));
        label_videoslist = new QLabel(widget_videoslist);
        label_videoslist->setObjectName(QString::fromUtf8("label_videoslist"));
        label_videoslist->setGeometry(QRect(0, 30, 241, 31));
        sizePolicy2.setHeightForWidth(label_videoslist->sizePolicy().hasHeightForWidth());
        label_videoslist->setSizePolicy(sizePolicy2);
        label_videoslist->setFont(font);
        scrollArea_videoslist = new QScrollArea(widget_videoslist);
        scrollArea_videoslist->setObjectName(QString::fromUtf8("scrollArea_videoslist"));
        scrollArea_videoslist->setGeometry(QRect(0, 120, 241, 571));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea_videoslist->sizePolicy().hasHeightForWidth());
        scrollArea_videoslist->setSizePolicy(sizePolicy4);
        scrollArea_videoslist->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_videoslist->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 239, 569));
        scrollArea_videoslist->setWidget(scrollAreaWidgetContents_2);
        widget_searchbox = new QWidget(widget_videoslist);
        widget_searchbox->setObjectName(QString::fromUtf8("widget_searchbox"));
        widget_searchbox->setGeometry(QRect(0, 70, 241, 31));
        widget_searchbox->setStyleSheet(QString::fromUtf8("background-color: white; \n"
"border-radius: 10px;"));
        pushButton_search = new QPushButton(widget_searchbox);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(200, 0, 31, 31));
        pushButton_search->setStyleSheet(QString::fromUtf8(""));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/icons/src/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_search->setIcon(icon13);
        textEdit_search = new QTextEdit(widget_searchbox);
        textEdit_search->setObjectName(QString::fromUtf8("textEdit_search"));
        textEdit_search->setGeometry(QRect(10, 0, 181, 31));
        widget_tittle = new QWidget(centralwidget);
        widget_tittle->setObjectName(QString::fromUtf8("widget_tittle"));
        widget_tittle->setGeometry(QRect(210, 30, 841, 71));
        label_videotittle = new QLabel(widget_tittle);
        label_videotittle->setObjectName(QString::fromUtf8("label_videotittle"));
        label_videotittle->setGeometry(QRect(0, 0, 151, 41));
        sizePolicy2.setHeightForWidth(label_videotittle->sizePolicy().hasHeightForWidth());
        label_videotittle->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setPointSize(16);
        label_videotittle->setFont(font3);
        label_videoname = new QLabel(widget_tittle);
        label_videoname->setObjectName(QString::fromUtf8("label_videoname"));
        label_videoname->setGeometry(QRect(0, 30, 841, 41));
        label_videoname->setFont(font1);
        line_2 = new QFrame(widget_tittle);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 30, 131, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        MainWindow_player->setCentralWidget(centralwidget);
        widget_tittle->raise();
        widget_videoslist->raise();
        widget_additionalfunction->raise();
        widget_navigation->raise();
        widget_player->raise();
        statusbar = new QStatusBar(MainWindow_player);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow_player->setStatusBar(statusbar);

        retranslateUi(MainWindow_player);

        QMetaObject::connectSlotsByName(MainWindow_player);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_player)
    {
        MainWindow_player->setWindowTitle(QApplication::translate("MainWindow_player", "MainWindow", nullptr));
        pushButton_like->setText(QString());
        pushButton_share->setText(QString());
        pushButton_screenshot->setText(QString());
        pushButton_sendcomment->setText(QApplication::translate("MainWindow_player", "Post", nullptr));
        pushButton_self->setText(QString());
        label_comment->setText(QApplication::translate("MainWindow_player", "Comments:", nullptr));
        pushButton_collect->setText(QString());
        textEdit_comment->setPlaceholderText(QApplication::translate("MainWindow_player", "type the comment...", nullptr));
        pushButton_language->setText(QApplication::translate("MainWindow_player", "Change Language", nullptr));
        pushButton_logo->setText(QApplication::translate("MainWindow_player", "T", nullptr));
        label_logoname->setText(QApplication::translate("MainWindow_player", "Temeo", nullptr));
        pushButton_account->setText(QApplication::translate("MainWindow_player", "Account", nullptr));
        pushButton_selficon->setText(QString());
        pushButton_likelist->setText(QApplication::translate("MainWindow_player", "Like List", nullptr));
        pushButton_collection->setText(QApplication::translate("MainWindow_player", "Collection", nullptr));
        pushButton_screenshotlibrary->setText(QApplication::translate("MainWindow_player", "Screenshot Library", nullptr));
        pushButton_playandpause->setText(QString());
        pushButton_playspeed->setText(QApplication::translate("MainWindow_player", "1.0x", nullptr));
        label_position->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        pushButton_moveback->setText(QString());
        pushButton_movefoward->setText(QString());
        label_duration->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        pushButton_volume->setText(QString());
        pushButton_screencontrol->setText(QString());
        label_videoslist->setText(QApplication::translate("MainWindow_player", "Videos list:", nullptr));
        pushButton_search->setText(QString());
        textEdit_search->setPlaceholderText(QApplication::translate("MainWindow_player", "type to search...", nullptr));
        label_videotittle->setText(QApplication::translate("MainWindow_player", "Video Tittle:", nullptr));
        label_videoname->setText(QApplication::translate("MainWindow_player", "a.wmv", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_player: public Ui_MainWindow_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_PLAYER_H
