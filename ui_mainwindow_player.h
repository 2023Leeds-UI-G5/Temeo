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
    QLabel *label_videoslist;
    QWidget *widget_additionalfunction;
    QWidget *widget_navigation;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVideoWidget *widget_video;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_playandpause;
    QPushButton *pushButton_playspeed;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_position;
    QSlider *horizontalSlider_position;
    QLabel *label_duration;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volume;
    QPushButton *pushButton_screencontrol;
    QVBoxLayout *verticalLayout;
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
        label_videoslist = new QLabel(centralwidget);
        label_videoslist->setObjectName(QString::fromUtf8("label_videoslist"));
        label_videoslist->setGeometry(QRect(1100, 30, 81, 20));
        widget_additionalfunction = new QWidget(centralwidget);
        widget_additionalfunction->setObjectName(QString::fromUtf8("widget_additionalfunction"));
        widget_additionalfunction->setGeometry(QRect(210, 560, 841, 161));
        widget_navigation = new QWidget(centralwidget);
        widget_navigation->setObjectName(QString::fromUtf8("widget_navigation"));
        widget_navigation->setGeometry(QRect(0, 0, 161, 751));
        widget_navigation->setStyleSheet(QString::fromUtf8("background-color: gray;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 60, 841, 481));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_video = new QVideoWidget(layoutWidget);
        widget_video->setObjectName(QString::fromUtf8("widget_video"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_video->sizePolicy().hasHeightForWidth());
        widget_video->setSizePolicy(sizePolicy1);
        widget_video->setMinimumSize(QSize(0, 183));
        widget_video->setStyleSheet(QString::fromUtf8("background-color: lightgray;"));

        verticalLayout_2->addWidget(widget_video);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, 5, -1);
        pushButton_playandpause = new QPushButton(layoutWidget);
        pushButton_playandpause->setObjectName(QString::fromUtf8("pushButton_playandpause"));
        pushButton_playandpause->setMinimumSize(QSize(23, 23));
        pushButton_playandpause->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/src/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/icons/src/pause.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_playandpause->setIcon(icon);
        pushButton_playandpause->setCheckable(true);

        horizontalLayout->addWidget(pushButton_playandpause);

        pushButton_playspeed = new QPushButton(layoutWidget);
        pushButton_playspeed->setObjectName(QString::fromUtf8("pushButton_playspeed"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_playspeed->sizePolicy().hasHeightForWidth());
        pushButton_playspeed->setSizePolicy(sizePolicy2);
        pushButton_playspeed->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_playspeed);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_position = new QLabel(layoutWidget);
        label_position->setObjectName(QString::fromUtf8("label_position"));

        horizontalLayout_2->addWidget(label_position);

        horizontalSlider_position = new QSlider(layoutWidget);
        horizontalSlider_position->setObjectName(QString::fromUtf8("horizontalSlider_position"));
        horizontalSlider_position->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_position);


        horizontalLayout->addLayout(horizontalLayout_2);

        label_duration = new QLabel(layoutWidget);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));

        horizontalLayout->addWidget(label_duration);

        pushButton_volume = new QPushButton(layoutWidget);
        pushButton_volume->setObjectName(QString::fromUtf8("pushButton_volume"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/src/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/icons/src/mutevolume.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_volume->setIcon(icon1);
        pushButton_volume->setCheckable(true);

        horizontalLayout->addWidget(pushButton_volume);

        horizontalSlider_volume = new QSlider(layoutWidget);
        horizontalSlider_volume->setObjectName(QString::fromUtf8("horizontalSlider_volume"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(horizontalSlider_volume->sizePolicy().hasHeightForWidth());
        horizontalSlider_volume->setSizePolicy(sizePolicy3);
        horizontalSlider_volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_volume);

        pushButton_screencontrol = new QPushButton(layoutWidget);
        pushButton_screencontrol->setObjectName(QString::fromUtf8("pushButton_screencontrol"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/src/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/new/icons/src/smallscreen.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_screencontrol->setIcon(icon2);
        pushButton_screencontrol->setCheckable(true);

        horizontalLayout->addWidget(pushButton_screencontrol);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        scrollArea_videoslist = new QScrollArea(centralwidget);
        scrollArea_videoslist->setObjectName(QString::fromUtf8("scrollArea_videoslist"));
        scrollArea_videoslist->setGeometry(QRect(1100, 60, 241, 661));
        sizePolicy1.setHeightForWidth(scrollArea_videoslist->sizePolicy().hasHeightForWidth());
        scrollArea_videoslist->setSizePolicy(sizePolicy1);
        scrollArea_videoslist->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_videoslist->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 239, 659));
        scrollArea_videoslist->setWidget(scrollAreaWidgetContents_2);
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
        label_videoslist->setText(QApplication::translate("MainWindow_player", "Videos list:", nullptr));
        pushButton_playandpause->setText(QString());
        pushButton_playspeed->setText(QApplication::translate("MainWindow_player", "1.0x", nullptr));
        label_position->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        label_duration->setText(QApplication::translate("MainWindow_player", "00:00:00", nullptr));
        pushButton_volume->setText(QString());
        pushButton_screencontrol->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow_player: public Ui_MainWindow_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_PLAYER_H
