#include "playerinforeader.h"

PlayerInfoReader::PlayerInfoReader(QIODevice *dev)
{
    reader.setDevice(dev);
}
