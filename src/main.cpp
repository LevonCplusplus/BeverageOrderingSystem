#include "OrderingSystem.h"
int main(){
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();
    std::shared_ptr<Beverage> bev1 = std::make_shared<Espresso>();
    std::shared_ptr<Beverage> bev2 = std::make_shared<Late>();   
    std::shared_ptr<Beverage> bev3 = std::make_shared<GreenTea>();
    std::shared_ptr<Beverage> bev4 = std::make_shared<BlackTea>();

    menu -> addBeveragetoMenu(bev1);
    menu -> addBeveragetoMenu(bev2);
    menu -> addBeveragetoMenu(bev3);
    std::shared_ptr<OrderingSystem> CoffeHouse = OrderingSystem::createorderingsystem();
    CoffeHouse ->setmenu(std::move(menu));
    CoffeHouse ->createorder();
}
