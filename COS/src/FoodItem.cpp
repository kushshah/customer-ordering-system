#include "FoodItem.h"
#include <iostream>
#include<cstring>

FoodItem::FoodItem()
{
    //ctor
}
FoodItem::FoodItem(char* name, double price, int calCount)
{
    //std::cout<<"in cstr fi"<<'\n';
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);
    this->price = price;
    this->calCount = calCount;
}
FoodItem::FoodItem(const FoodItem& fi)
{
    this->name = new char[strlen(fi.name) + 1];
    strcpy(this->name,fi.name);
    this->price = fi.price;
    this->calCount = fi.calCount;
}
void FoodItem::print()
{
    std::cout<<'\t'<<"Name of the Dish is:"<<this->name<<'\n';
    std::cout<<'\t'<<"Price of the Dish is:"<<this->price<<'\n';
    std::cout<<'\t'<<"The Dish has "<<this->calCount<<'\n';
}
FoodItem::~FoodItem()
{
    //dtor
    //std::cout<<"in destr fi"<<'\n';
    delete[] name;
}
