#ifndef PLAYERINFOWRITER_H
#define PLAYERINFOWRITER_H

#include <QIODevice>
#include <QXmlStreamWriter>

#include "playerinfoutil.h"

class PlayerInfoWriter
{
public:
    explicit PlayerInfoWriter(QIODevice *dev);
    bool write(PlayerInfo pinfo);

private:
    bool writePlayerInfo();
    Player writePlayer();
    QList<InventoryItem> writeInventory();

    QXmlStreamWriter writer;
};

#endif // PLAYERINFOWRITER_H
