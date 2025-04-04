#include "Menu.h"
std::shared_ptr<Beverage> Menu:: chooseBeverage(){
    for(size_t i{};i < m_beverages.size(); ++i){
        std::cout << "Choose Beverage!"<<std::endl;
        std::cout << i+1<<':';m_beverages[i] -> getndescription();
    }
    int k;
    while (true)
    {
        std::cin >> k;
        if(k <= 0 || k > m_beverages.size())
        {
            std::cout << "insert the Beverage number again\n";
        }
        else{
            break;
        }
    }
    return m_beverages[k-1];
}
void Menu:: addBeveragetoMenu(std::shared_ptr<Beverage> bev){
    m_beverages.push_back(bev);
} 