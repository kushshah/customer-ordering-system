#include "TurkeySandwich.h"
#include <iostream>
#include<cstring>

TurkeySandwich::TurkeySandwich()
{
    //ctor
}
TurkeySandwich::TurkeySandwich(sandwich_bread bread,CondimentList* &cl):FoodItem("Turkey Sandwich",10,100)
{
    this->bread = bread;
    this->cl = cl;
}
TurkeySandwich::TurkeySandwich(const TurkeySandwich& ts):FoodItem(ts)
{
    this->bread = ts.bread;
    this->cl = ts.cl;
}
void TurkeySandwich::print()
{
    FoodItem::print();
    std::cout<<'\t'<<"Type of Bread is :"<<this->bread<<'\n';
    this->cl->print_condiment();
}
TurkeySandwich* TurkeySandwich::myCopy()
{
    TurkeySandwich* result = new TurkeySandwich(*this);
    return result;
}
TurkeySandwich::~TurkeySandwich()
{
    //dtor
    delete cl;
}
