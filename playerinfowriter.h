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
    bool writePlayerInfo(PlayerInfo p_info);
    void writePlayer(Player player);
    void writeInventory(QList<InventoryItem> inventroy);

    QXmlStreamWriter writer;
};

#endif // PLAYERINFOWRITER_H
