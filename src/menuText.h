#ifndef _MENU_TEXT_
#define _MENU_TEXT_

#include "item.h"
#include <string>

using namespace std;

class MenuText : public Item
{
public:
    MenuText(string title);
    string getTitle();
};

#endif
