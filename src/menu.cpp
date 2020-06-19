#include "menu.h"
#include <stdexcept>
#include <iostream>

Menu::Menu(string title, Menu* previous)
        :Item(title)
{
    previous_ = previous;
    selectedMenu_ = this;
}

void Menu::addItem(int position, Item* item)
{
    if (dynamic_cast<Menu*>(item) != nullptr)
    {
        Menu* subMenu = dynamic_cast<Menu*>(item);
        if (subMenu == this)
        {
            throw invalid_argument("A menu can't be its own submenu");
        }
        subMenu->setPrevious(this);
    }
    entries_[position] = item;
}

void Menu::setPrevious(Menu* menu)
{
    previous_ = menu;
}

string Menu::getTitle()
{
    return title_;
}

void Menu::show()
{
    if (selectedMenu_ == this)
    {
        cout << "\033c";
        cout << "--" << title_ << "--" << endl;
        for (auto& entry : entries_)
        {
            cout << entry.second->getTitle() << endl;
        }
        if (previous_ != nullptr)
        {
            cout << "Volver" << endl;
        }
    }
    else
    {
        selectedMenu_->show();
    }
    
}

void Menu::selectOption(int option)
{
    int actual = selectedMenu_->entries_.size();
    if (option >= actual)
    {
        back();
    }
    else // Habria que chequear que este dentro de los limites
    {
        Menu* newSelectedMenu = dynamic_cast<Menu*>(selectedMenu_->entries_[option]);
        if (newSelectedMenu != nullptr)
        {
            selectedMenu_ = newSelectedMenu;
        }
    }
}

void Menu::back()
{
    if (selectedMenu_->previous_ != nullptr)
    {
        selectedMenu_ = selectedMenu_->previous_;
    }
    else
    {
        selectedMenu_ = this;
    }
    
}

Menu::~Menu()
{
    for (auto& item : entries_)
    {
        Item* element = item.second;
        delete entries_[item.first];
    }
    entries_.clear();
}

Menu::Menu(string title)
        :Item(title)
{
    previous_ = nullptr;
    selectedMenu_ = this;
}
