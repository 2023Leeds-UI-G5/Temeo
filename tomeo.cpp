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
#include <QDesktopServices>
#include <QImageReader>
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
#include <string>
#include <vector>

// read in videos and thumbnails to this directory
std::vector<TheButtonInfo> getInfoIn(std::string loc)
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

int main(int argc, char *argv[])
{
    // // let's just check that Qt is operational first
    // qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    std::vector<TheButtonInfo> videos;

    //std::string filename = "C:\\Program Files (noroot)\\UI\\Final_proj\\final\\G5UI-cwk\\videos";

    if (argc == 2)
        videos = getInfoIn(std::string(argv[1]));

    //videos = getInfoIn(filename);

    if (videos.size() == 0) {
        const int result = QMessageBox::information(
            NULL,
            QString("Tomeo"),
            QString("no videos found! Add command line argument to \"quoted\" file location."));
        exit(-1);
    }

    MainWindow_player mainWindow;

    mainWindow.videosListInit(videos);

    mainWindow.show();

    return app.exec();
}
