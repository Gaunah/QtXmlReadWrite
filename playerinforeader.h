#ifndef PLAYERINFOREADER_H
#define PLAYERINFOREADER_H

#include <QIODevice>
#include <QPoint>
#include <QXmlStreamReader>

struct InventoryItem {
    enum Type { Weapon, Armor, Gem, Book, Other } type;
    QString subType;
    int durability;
};

struct Player {
    QString name;
    QString password;
    int experience;
    int hitPoints;
    QList<InventoryItem> inventory;
    QString location;
    QPoint position;
};

struct PlayerInfo {
    QList<Player> players;
};

enum Token {
    T_Invalid = -1,
    T_PlayerInfo,                                       /* root tag */
    T_Player,                                           /* in PlayerInfo */
    T_Name, T_Password, T_Inventory, T_Location,        /* in Player */
    T_Position,                                         /* in Location */
    T_InvItem                                           /* in Inventory */
};

class PlayerInfoReader
{
public:
    explicit PlayerInfoReader(QIODevice *dev);
    inline const PlayerInfo &result() const { return m_pinfo; }

private:
    QXmlStreamReader reader;
    PlayerInfo m_pinfo;
};

#endif // PLAYERINFOREADER_H
