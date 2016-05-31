#include "playerinfowriter.h"

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

    writer.writeTextElement(nameByToken(T_Name), player.name);

    writeInventory(player.inventory);

    writer.writeStartElement(nameByToken(T_Location));
    writer.writeAttribute("name", player.location);
    writer.writeStartElement(nameByToken(T_Position));
    QXmlStreamAttributes posAttrs;
    posAttrs.append("x" , QString::number(player.position.x()));
    posAttrs.append("y" , QString::number(player.position.y()));
    writer.writeAttributes(posAttrs);
    writer.writeEndElement();

    writer.writeEndElement();
}

void PlayerInfoWriter::writeInventory(QList<InventoryItem> inventory)
{
    writer.writeStartElement(nameByToken(T_Inventory));
    foreach (InventoryItem item, inventory) {
        writer.writeStartElement(nameByToken(T_InvItem));
        QXmlStreamAttributes itemAttrs;
        QString typeStr;
        switch (item.type) {
        case InventoryItem::Weapon:
            typeStr = "Weapon";
            break;
        case InventoryItem::Armor:
            typeStr = "Armor";
            break;
        case InventoryItem::Book:
            typeStr = "Book";
            break;
        case InventoryItem::Gem:
            typeStr = "Gem";
            break;
        case InventoryItem::Other:
            typeStr = "Other";
            break;
        default:
            typeStr = "Unknown";
            break;
        }
        itemAttrs.append("type", typeStr);
        itemAttrs.append("durability", QString::number(item.durability));
        writer.writeAttributes(itemAttrs);
        writer.writeTextElement("SubType", item.subType);
        writer.writeEndElement();
    }
    writer.writeEndElement();
}
