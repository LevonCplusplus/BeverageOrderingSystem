#ifndef MENU_H
#define MENU_H
#include "Beverage.h"
class Menu{
    std::vector<std::shared_ptr <Beverage>> m_beverages;
public:
    std::shared_ptr<Beverage> chooseBeverage();
    void addBeveragetoMenu(std::shared_ptr<Beverage> bev);
};

#endif