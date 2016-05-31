#ifndef PLAYERINFOREADER_H
#define PLAYERINFOREADER_H

#include <QIODevice>
#include <QXmlStreamReader>

#include "playerinfoutil.h"

class PlayerInfoReader
{

public:
    explicit PlayerInfoReader(QIODevice *dev);

    inline const PlayerInfo &result() const { return m_pinfo; }
    bool read();

private:
    bool readPlayerInfo();
    Player readPlayer();
    QList<InventoryItem> readInventory();

    QXmlStreamReader reader;
    PlayerInfo m_pinfo;
};

#endif // PLAYERINFOREADER_H
