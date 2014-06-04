#include "CondimentListNode.h"
#include<cstring>

CondimentListNode::CondimentListNode()
{
    //ctor
    next = nullptr;
}
CondimentListNode::CondimentListNode(char* condiment)
{
    next = nullptr;
    this->condiment = new char[strlen(condiment)+1];
    strcpy(this->condiment,condiment);
}
CondimentListNode::~CondimentListNode()
{
    //dtor
    delete[] condiment;
}
