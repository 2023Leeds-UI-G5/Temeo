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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_player
{
public:
    QWidget *centralwidget;
    QVideoWidget *widget_video;
    QScrollArea *scrollArea_videoslist;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_position;
    QSlider *horizontalSlider_position;
    QLabel *label_duration;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_playandpause;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volume;
    QPushButton *pushButton_playspeed;
    QPushButton *pushButton_screencontrol;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_player)
    {
        if (MainWindow_player->objectName().isEmpty())
            MainWindow_player->setObjectName(QString::fromUtf8("MainWindow_player"));
        MainWindow_player->resize(320, 480);
        MainWindow_player->setMinimumSize(QSize(320, 480));
        MainWindow_player->setMaximumSize(QSize(3780, 2160));
        MainWindow_player->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow_player);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_video = new QVideoWidget(centralwidget);
        widget_video->setObjectName(QString::fromUtf8("widget_video"));
        widget_video->setGeometry(QRect(20, 19, 281, 151));
        scrollArea_videoslist = new QScrollArea(centralwidget);
        scrollArea_videoslist->setObjectName(QString::fromUtf8("scrollArea_videoslist"));
        scrollArea_videoslist->setGeometry(QRect(20, 260, 281, 191));
        scrollArea_videoslist->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 279, 189));
        scrollArea_videoslist->setWidget(scrollAreaWidgetContents_2);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 190, 281, 51));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_position = new QLabel(widget);
        label_position->setObjectName(QString::fromUtf8("label_position"));

        horizontalLayout_2->addWidget(label_position);

        horizontalSlider_position = new QSlider(widget);
        horizontalSlider_position->setObjectName(QString::fromUtf8("horizontalSlider_position"));
        horizontalSlider_position->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_position);

        label_duration = new QLabel(widget);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));

        horizontalLayout_2->addWidget(label_duration);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_playandpause = new QPushButton(widget);
        pushButton_playandpause->setObjectName(QString::fromUtf8("pushButton_playandpause"));
        pushButton_playandpause->setMinimumSize(QSize(23, 23));
        pushButton_playandpause->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/src/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/icons/src/pause.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_playandpause->setIcon(icon);
        pushButton_playandpause->setCheckable(true);

        horizontalLayout->addWidget(pushButton_playandpause);

        pushButton_volume = new QPushButton(widget);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/src/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/icons/src/mutevolume.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_volume->setIcon(icon1);
        pushButton_volume->setCheckable(true);

        horizontalLayout->addWidget(pushButton_volume);

        horizontalSlider_volume = new QSlider(widget);
        horizontalSlider_volume->setObjectName(QString::fromUtf8("horizontalSlider_volume"));
        horizontalSlider_volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_volume);

        pushButton_playspeed = new QPushButton(widget);
        pushButton_playspeed->setObjectName(QString::fromUtf8("pushButton_playspeed"));
        pushButton_playspeed->setMinimumSize(QSize(41, 23));
        pushButton_playspeed->setMaximumSize(QSize(41, 23));

        horizontalLayout->addWidget(pushButton_playspeed);

        pushButton_screencontrol = new QPushButton(widget);
        pushButton_screencontrol->setObjectName(QString::fromUtf8("pushButton_screencontrol"));
        pushButton_screencontrol->setMinimumSize(QSize(20, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/src/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/new/icons/src/smallscreen.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_screencontrol->setIcon(icon2);
        pushButton_screencontrol->setCheckable(true);

        horizontalLayout->addWidget(pushButton_screencontrol);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow_player->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow_player);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow_player->setStatusBar(statusbar);

        retranslateUi(MainWindow_player);

        QMetaObject::connectSlotsByName(MainWindow_player);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_player)
    {
        MainWindow_player->setWindowTitle(QApplication::translate("MainWindow_player", "MainWindow", nullptr));
        label_position->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        label_duration->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        pushButton_playandpause->setText(QString());
        pushButton_volume->setText(QString());
        pushButton_playspeed->setText(QApplication::translate("MainWindow_player", "1.0x", nullptr));
        pushButton_screencontrol->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow_player: public Ui_MainWindow_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_PLAYER_H
