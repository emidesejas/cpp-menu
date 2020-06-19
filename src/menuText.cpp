#include "menuText.h"

MenuText::MenuText(string title)
            :Item(title)
{}

string MenuText::getTitle()
{
    return title_;
}
