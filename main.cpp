#include <QString>

struct InventoryItem {
    enum Type { Weapon, Armor, Gem, Book, Other } type;
    QString subType;
    int durability;
};

int main(int argc, char **argv)
{

}
