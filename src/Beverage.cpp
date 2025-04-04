#include "Beverage.h"
Beverage::Beverage(int price,const std::string& name):m_price(price),m_name(name){};
int Beverage:: cost(){
    return m_price;
}
void Beverage:: getndescription(){ 
    std::cout << "Name: " << m_name << "\nPrice: " << m_price << std::endl;
}

