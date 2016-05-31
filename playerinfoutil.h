#ifndef PLAYERINFOUTIL_H
#define PLAYERINFOUTIL_H

#include <QPoint>


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

static Token tokenByName(const QStringRef &r)
{
    static QStringList tokenList = QStringList()
                                   << "PlayerInfo" << "Player"
                                   << "Name" << "Password"
                                   << "Inventory" << "Location"
                                   << "Position" << "InvItem";
    int idx = tokenList.indexOf(r.toString());
    return (Token)idx;
}

#endif // PLAYERINFOUTIL_H
