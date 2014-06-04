#include "EggplantCasserole.h"
#include <iostream>
#include<cstring>

EggplantCasserole::EggplantCasserole()
{
    //ctor
}
EggplantCasserole::EggplantCasserole(const EggplantCasserole& ec):FoodItem(ec)
{
    this->noOfOunces = ec.noOfOunces;
    this->sideDish = new char[strlen(ec.sideDish) + 1];
    strcpy(this->sideDish, ec.sideDish);
}
EggplantCasserole::EggplantCasserole(int noOfOunces, char* sideDish):FoodItem("Eggplant Casserole", 11, 200)
{
    //std::cout<<"in cstr epc"<<'\n';
    this->noOfOunces = noOfOunces;
    this->sideDish = new char[strlen(sideDish) + 1];
    strcpy(this->sideDish, sideDish);
}
void EggplantCasserole::print()
{
    FoodItem::print();
    std::cout<<'\t'<<"Side Dish is :"<<this->sideDish<<'\n';
    std::cout<<'\t'<<"Number of ounces are :"<<this->noOfOunces<<'\n';
}
EggplantCasserole* EggplantCasserole::myCopy()
{
    EggplantCasserole* result = new EggplantCasserole(*this);
    return result;
}
EggplantCasserole::~EggplantCasserole()
{
    //dtor
    //std::cout<<"in destr epc"<<'\n';
    delete[] sideDish;
}
