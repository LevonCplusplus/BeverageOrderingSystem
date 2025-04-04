#ifndef DECORATOR_H
#define DECORATOR_H
#include "Beverage.h"
class Decorator:public Beverage{
protected:
    std::shared_ptr<Beverage> m_ptr;
public:
    Decorator(std::shared_ptr<Beverage> ptr):m_ptr(ptr){};
    
};
class Lemon:public Decorator{
public:
    Lemon(std::shared_ptr<Beverage> ptr):Decorator(ptr){};
    int cost()  
    {
        return m_ptr->cost() + 100;
    }
       
};
    
class Honey:public Decorator{
public:
    Honey(std::shared_ptr<Beverage> ptr ):Decorator(ptr){};
    int cost(){
        return m_ptr->cost() + 200;
    }
};
    
    
class Milk:public Decorator{
public:
    Milk(std::shared_ptr<Beverage> ptr):Decorator(ptr){};
    int cost()  
    {
        return m_ptr->cost() + 100;
    }
           
};
class Sugar:public Decorator{
public:
    Sugar(std::shared_ptr<Beverage> ptr ):Decorator(ptr){};
    int cost(){
        return m_ptr->cost() + 50;
    }
};
        
class Caramel:public Decorator{
public:
    Caramel(std::shared_ptr<Beverage> ptr ):Decorator(ptr){};
    int cost(){
        return m_ptr->cost() + 100;
    }
};
    

#endif