#include "playerinforeader.h"
#include "playerinfowriter.h"

#include <QFile>
#include <QDebug>
#include <QDir>

int main(int argc, char **argv)
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    //quick and dirty file path
    QDir dir  = QDir::current();
    dir.cd("../QtXmlReadWrite");
    QString path = dir.absolutePath() + "/PlayerInfo.xml";

    if (!QFile::exists(path)) {
        qDebug() << "file:" << path << "don't exsits.";
        return 1;
    }

    QFile fileRead(path);
    fileRead.open(QFile::ReadOnly | QFile::Text);
    PlayerInfoReader pir(&fileRead);

    if (pir.read()) {
        PlayerInfo playerInfo = pir.result();
        fileRead.close();

        QFile fileWrite("TestOut.xml");
        fileWrite.open(QFile::WriteOnly | QFile::Truncate);
        PlayerInfoWriter piw(&fileWrite);
        piw.write(playerInfo);
        fileWrite.close();
    } else {
        qDebug() << "Could not read file";
    }
    return 0;
}
