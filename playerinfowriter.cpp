#include "playerinfowriter.h"

#include <QDebug>

PlayerInfoWriter::PlayerInfoWriter(QIODevice *dev)
{
    if (dev != nullptr) {
        writer.setDevice(dev);
        writer.setAutoFormatting(true);
    } else {
        qDebug() << Q_FUNC_INFO << "*dev nullptr!";
    }
}

bool PlayerInfoWriter::write(PlayerInfo pinfo)
{
   return writePlayerInfo(pinfo);
}

bool PlayerInfoWriter::writePlayerInfo(PlayerInfo p_info)
{
    writer.writeStartDocument();
    writer.writeStartElement(nameByToken(T_PlayerInfo));
    foreach (const Player &p, p_info.players) {
        writePlayer(p);
    }
    writer.writeEndDocument();
    return true;
}

void PlayerInfoWriter::writePlayer(Player player)
{
    writer.writeStartElement(nameByToken(T_Player));
    QXmlStreamAttributes playerAttr;
    playerAttr.append("hp", QString::number(player.hitPoints));
    playerAttr.append("exp", QString::number(player.experience));
    writer.writeAttributes(playerAttr);
    //TODO
    writer.writeEndElement();
}

void PlayerInfoWriter::writeInventory(QList<InventoryItem> inventory)
{
    qDebug() << Q_FUNC_INFO << "not implemented!";
}
