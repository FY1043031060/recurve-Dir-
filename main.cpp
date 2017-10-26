#include <QCoreApplication>
#include <QDir>
#include <iostream>
void recurve(QString strPath);
void operateFileInfos(QFileInfoList list)
{
    std::cout << "     Bytes Filename" << std::endl;

    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
                                                .arg(fileInfo.fileName()));
        std::cout << std::endl;
        if(fileInfo.isDir())
        {
            ////Ä¿Â¼µÝ¹é
            recurve(fileInfo.absoluteFilePath());
        }
    }
}

void recurve(QString strPath)
{
    QDir dir(strPath);
    dir.setFilter(QDir::Files /*| QDir::Hidden*/ | QDir::NoSymLinks |QDir::Dirs);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    operateFileInfos(list);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    recurve(".");
    return 0;
}
