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
    T_PlayerInfo,                               /* root tag */
    T_Player,                                   /* in PlayerInfo */
    T_Name, T_Inventory, T_Location,            /* in Player */
    T_Position,                                 /* in Location */
    T_InvItem                                   /* in Inventory */
};

static const QStringList tokenList = QStringList()
                                     << "PlayerInfo" << "Player" << "Name"
                                     << "Inventory" << "Location"
                                     << "Position" << "InvItem";

static Token tokenByName(const QStringRef &r)
{
    return (Token) tokenList.indexOf(r.toString());
}

static QString nameByToken(const Token &t)
{
    return tokenList.at((int) t);
}

#endif // PLAYERINFOUTIL_H
