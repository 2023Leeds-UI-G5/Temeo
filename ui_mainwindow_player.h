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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_player
{
public:
    QWidget *centralwidget;
    QWidget *widget_additionalfunction;
    QWidget *widget_navigation;
    QWidget *widget_player;
    QVideoWidget *widget_video;
    QWidget *widget_toolbar;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_playandpause;
    QPushButton *pushButton_playspeed;
    QLabel *label_position;
    QSlider *horizontalSlider_position;
    QLabel *label_duration;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volume;
    QPushButton *pushButton_screencontrol;
    QWidget *widget_videoslist;
    QLabel *label_videoslist;
    QScrollArea *scrollArea_videoslist;
    QWidget *scrollAreaWidgetContents_2;
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
        widget_additionalfunction->setGeometry(QRect(210, 550, 841, 171));
        widget_navigation = new QWidget(centralwidget);
        widget_navigation->setObjectName(QString::fromUtf8("widget_navigation"));
        widget_navigation->setGeometry(QRect(-10, 0, 161, 751));
        widget_navigation->setStyleSheet(QString::fromUtf8("background-color: gray;"));
        widget_player = new QWidget(centralwidget);
        widget_player->setObjectName(QString::fromUtf8("widget_player"));
        widget_player->setGeometry(QRect(210, 60, 841, 461));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_player->sizePolicy().hasHeightForWidth());
        widget_player->setSizePolicy(sizePolicy1);
        widget_video = new QVideoWidget(widget_player);
        widget_video->setObjectName(QString::fromUtf8("widget_video"));
        widget_video->setGeometry(QRect(0, 0, 839, 431));
        sizePolicy1.setHeightForWidth(widget_video->sizePolicy().hasHeightForWidth());
        widget_video->setSizePolicy(sizePolicy1);
        widget_video->setMinimumSize(QSize(0, 183));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/src/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/icons/src/pause.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_playandpause->setIcon(icon);
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

        horizontalSlider_position = new QSlider(widget_toolbar);
        horizontalSlider_position->setObjectName(QString::fromUtf8("horizontalSlider_position"));
        horizontalSlider_position->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_position);

        label_duration = new QLabel(widget_toolbar);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));
        sizePolicy3.setHeightForWidth(label_duration->sizePolicy().hasHeightForWidth());
        label_duration->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(label_duration);

        pushButton_volume = new QPushButton(widget_toolbar);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/src/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/icons/src/mutevolume.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_volume->setIcon(icon1);
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/src/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/new/icons/src/smallscreen.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_screencontrol->setIcon(icon2);
        pushButton_screencontrol->setCheckable(true);

        horizontalLayout->addWidget(pushButton_screencontrol);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        widget_videoslist = new QWidget(centralwidget);
        widget_videoslist->setObjectName(QString::fromUtf8("widget_videoslist"));
        widget_videoslist->setGeometry(QRect(1100, 30, 241, 691));
        label_videoslist = new QLabel(widget_videoslist);
        label_videoslist->setObjectName(QString::fromUtf8("label_videoslist"));
        label_videoslist->setGeometry(QRect(0, 0, 81, 20));
        scrollArea_videoslist = new QScrollArea(widget_videoslist);
        scrollArea_videoslist->setObjectName(QString::fromUtf8("scrollArea_videoslist"));
        scrollArea_videoslist->setGeometry(QRect(0, 30, 241, 661));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea_videoslist->sizePolicy().hasHeightForWidth());
        scrollArea_videoslist->setSizePolicy(sizePolicy4);
        scrollArea_videoslist->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_videoslist->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 239, 659));
        scrollArea_videoslist->setWidget(scrollAreaWidgetContents_2);
        MainWindow_player->setCentralWidget(centralwidget);
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
        pushButton_playandpause->setText(QString());
        pushButton_playspeed->setText(QApplication::translate("MainWindow_player", "1.0x", nullptr));
        label_position->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        label_duration->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        pushButton_volume->setText(QString());
        pushButton_screencontrol->setText(QString());
        label_videoslist->setText(QApplication::translate("MainWindow_player", "Videos list:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_player: public Ui_MainWindow_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_PLAYER_H
