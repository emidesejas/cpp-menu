#ifndef _ITEM_
#define _ITEM_

#include <string>

using namespace std;

class Item
{
protected:
    static int lastId_;
    int id_;
    string title_;
public:
    Item(string title_);
    virtual string getTitle() = 0;
};

#endif
