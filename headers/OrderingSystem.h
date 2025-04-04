#ifndef ORDERINGSYSTEM_H
#define ORDERINGSYSTEM_H
#include "Menu.h"
#include "Order.h"
#include "Decorator.h"
class Order;
class Menu;
class OrderingSystem{
    std::vector<std::shared_ptr<Order>> m_orders;
    std::unique_ptr<Menu> m_menu;
    static inline std::shared_ptr<OrderingSystem> singletone = nullptr; 
    OrderingSystem() = default;
public:
    static std::shared_ptr<OrderingSystem> createorderingsystem( );
    void setmenu(std::unique_ptr<Menu> menuptr);
    void createorder();
};
#endif