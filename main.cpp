#include "playerinforeader.h"

#include <QFile>
#include <QDebug>
#include <QDir>

int main(int argc, char **argv)
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QDir dir  = QDir::current();
    dir.cd("../QtSerialization");
    QString path = dir.absolutePath() + "/PlayerInfo.xml";

    if (!QFile::exists(path)) {
        qDebug() << "file:" << path << "don't exsits.";
        return 1;
    }

    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    PlayerInfoReader pir(&file);

    if (pir.read()) {
        PlayerInfo playerInfo = pir.result();
        //TODO
    } else {
        qDebug() << "Could not read file";
    }
    return 0;
}
