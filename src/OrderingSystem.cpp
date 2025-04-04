#include "OrderingSystem.h"
std::shared_ptr<OrderingSystem> OrderingSystem:: createorderingsystem(){
    if(!singletone)
    {
        singletone = std::shared_ptr<OrderingSystem>(new OrderingSystem());
    }
    return singletone; 
}
void OrderingSystem:: setmenu(std::unique_ptr<Menu> menuptr){
    m_menu = std::move(menuptr);
}
void OrderingSystem:: createorder(){
    std::cout << "Choose order type!\n"<< "1.Cashier Order\n" << "2.Kiosk Order\n" << "3.Mobile Order\n" << std::endl;
    int p {};
    while(true){
      std::cin >> p;
      if(p > 3 || p < 1){
        std::cout <<"insert correct number\n";
      }   
      else{
        break;
      }
    }
    std::shared_ptr<Order> order = nullptr;       
    if(p == 1){
        order = FactoryCashierOrder().createorder();
    }
    else if(p == 2){
        order = FactoryKioskOrder().createorder();
    }
    else{
        order = FactoryMobileOrder().createorder();
        std::dynamic_pointer_cast<MobileOrder>(order)->setadress();
    }
    while(true){
       std::shared_ptr<Beverage> beverage = m_menu -> chooseBeverage();

       if(std::dynamic_pointer_cast<Coffee>(beverage)){
            std::cout <<"would you like to add Sugar??\nif yes insert 1 else 0\n";
            int s = 0;
            std::cin >> s;
            if(s){
                beverage = std::make_shared<Sugar>(beverage);
            } 
            std::cout <<"would you like to add Milk??\nif yes insert 1 else 0\n";
            int m = 0;
            std::cin >> m;
            if(m){
                beverage = std::make_shared<Milk>(beverage);
            }
            std::cout <<"would you like to add Caramel??\nif yes insert 1 else 0\n";
            int c = 0;
            std::cin >> c;
            if(m){
                beverage = std::make_shared<Caramel>(beverage);
            }
            
        }
       else{
            std::cout <<"would you like to add Sugar??\nif yes insert 1 else 0\n";
            int s = 0;
            std::cin >> s;
            if(s){
                beverage = std::make_shared<Sugar>(beverage);
            } 
            std::cout <<"would you like to add Limon??\nif yes insert 1 else 0\n";
            int L = 0;
            std::cin >> L;
            if(L){
                beverage = std::make_shared<Lemon>(beverage);
            }
            std::cout <<"would you like to add Honey??\nif yes insert 1 else 0\n";
            int H = 0;
            std::cin >> H;
            if(H){
                beverage = std::make_shared<Honey>(beverage);
            }
        }
        order ->addBeverage(beverage);
        std::cout <<" If you want to choose another Beverage insert 1 else 0\n";
        int k;
        std::cin >> k;
        if( !k ){
            break;
        }
    
    }
    m_orders.push_back(order);
    order -> getsum();
}
