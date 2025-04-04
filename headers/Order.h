#ifndef ORDER_H
#define ORDER_H
#include "Beverage.h"
class Order{
protected:
    std::string m_clientname;
    std::vector<std::shared_ptr<Beverage>> m_order;
    int sum;
public:
    virtual void getsum() = 0;
    virtual  void addBeverage(std::shared_ptr<Beverage> bev);
    virtual ~Order() = default;
};
class CashierOrder:public Order{
public: 
    void getsum();
};
class KioskOrder:public Order{
    void getsum();
};
class MobileOrder:public Order{
    std::string m_adress;
public:
    void addBeverage(std::shared_ptr<Beverage> bev);
    void setadress();
    void getsum();
};
class FactoryOrder{
public:
    virtual std::shared_ptr<Order> createorder()=0;
    virtual ~FactoryOrder() = default;
};
class FactoryCashierOrder:public FactoryOrder{
public:
    std::shared_ptr<Order> createorder(){
        return std::make_shared<CashierOrder>();
}
};
class FactoryMobileOrder:public FactoryOrder{
public:
    std::shared_ptr<Order> createorder(){
        return std::make_shared<MobileOrder>();
    }
};
class FactoryKioskOrder:public FactoryOrder{
public:
    std::shared_ptr<Order> createorder(){
        return std::make_shared<KioskOrder>();
    }
};
#endif