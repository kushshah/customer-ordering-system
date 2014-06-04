#include "Salmon.h"
#include <iostream>
#include<cstring>
Salmon::Salmon()
{
    //ctor
}
Salmon::Salmon(const Salmon& sm):FoodItem(sm)
{
    this->ck = sm.ck;
    this->sideDish = new char[strlen(sm.sideDish) + 1];
    strcpy(this->sideDish, sm.sideDish);
}
Salmon::Salmon(char* sideDish,Salmon::cooking_style ck):FoodItem("Salmon",10,100)
{
    //std::cout<<"in cstr salmon"<<'\n';
    this->ck = ck;
    this->sideDish = new char[strlen(sideDish) + 1];
    strcpy(this->sideDish, sideDish);
}
void Salmon::print()
{
    FoodItem::print();
    std::cout<<'\t'<<"Side Dish is :"<<this->sideDish<<'\n';
    std::cout<<'\t'<<"Cooking Style is :"<<this->ck<<'\n';
}
Salmon* Salmon::myCopy()
{
    Salmon* result = new Salmon(*this);
    return result;
}
Salmon::~Salmon()
{
    //dtor
    //std::cout<<"in destr salmon"<<'\n';
    delete[] sideDish;
}
