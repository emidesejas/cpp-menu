#ifndef _MENU_
#define _MENU_

#include<map>
#include<string>
#include "item.h"

using namespace std;

class Menu : public Item
{
private:
    map<int, Item*> entries_;
    Menu* selectedMenu_;
    Menu* previous_;
public:
    Menu(string title);
    Menu(string title, Menu* previous);
    void setPrevious(Menu* menu);
    void addItem(int position, Item* item);
    void selectOption(int position);
    void back();
    void show();
    string getTitle();
    ~Menu();
};

#endif
