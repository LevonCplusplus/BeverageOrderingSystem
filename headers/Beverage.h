#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
class Beverage{
    int m_price;
    std::string m_name;
public:
    Beverage () = default;
    Beverage (int price,const std::string& name);
    virtual int cost();
    virtual void getndescription();
    virtual ~Beverage() = default;
};
class Coffee:public Beverage{
public:
    Coffee () = default;
    Coffee(int price, const std::string& name) : Beverage(price, name) {}
};
class Tea:public Beverage{
public:
    Tea() = default;
    Tea(int price, const std::string& name) : Beverage(price, name) {}
    
};
class Espresso:public Coffee {
public:
    Espresso():Coffee(800,"Espresso"){};
};
class Late: public Coffee{
public:
    Late():Coffee(950,"Late"){};
};
        
class GreenTea:public Tea{
public:
    GreenTea():Tea(700,"Green Tea"){};
};
class BlackTea:public Tea{
public:
    BlackTea():Tea(700,"Black Tea"){};
};

#endif