#include "Order.h"
void Order:: addBeverage(std::shared_ptr<Beverage> bev){
    m_order.push_back(bev); 
    sum += bev -> cost();

}
void CashierOrder:: getsum(){
    std::cout << "Order cost is: " << sum << std::endl;
}
void KioskOrder:: getsum(){
    std::cout << "Order cost is: " << sum << std::endl;
}


void MobileOrder:: addBeverage(std::shared_ptr<Beverage> bev){
    m_order.push_back(bev); 
    sum += bev -> cost();
    sum += 500;
}
void MobileOrder:: setadress(){
    std::getline(std::cin,m_adress);
} 
void MobileOrder:: getsum(){
    std::cout << "Order cost is: " << sum;
    std:: cout << "\t500 for delivery" << std::endl;
}