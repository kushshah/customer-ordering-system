#include "FIListNode.h"
#include<iostream>
FIListNode::FIListNode()
{
    //ctor
    fi = nullptr;
    next = nullptr;
}
FIListNode::FIListNode(FoodItem* fi)
{
    //std::cout<<"in filnode cstr";
    this->fi = fi;
    next = nullptr;
}
FIListNode::~FIListNode()
{
    //dtor
    delete fi;
}
