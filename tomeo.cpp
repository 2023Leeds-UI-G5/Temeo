//
//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//

#include <QApplication>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include <QtCore/QFileInfo>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QFileIconProvider>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include "mainwindow_player.h"
#include "the_button.h"
#include <vector>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // collect all the videos in the folder
    std::vector<TheButtonInfo> videos;

    MainWindow_player mainWindow;

    mainWindow.videosListInit(videos);

    mainWindow.show();

    return app.exec();
}
