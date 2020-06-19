#include "item.h"

int Item::lastId_ = 0;

Item::Item(string title)
{
    id_ = lastId_;
    lastId_++;
    title_ = title;
}
