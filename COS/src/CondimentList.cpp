#include "CondimentList.h"
#include<iostream>

CondimentList::CondimentList()
{
    //ctor
    head = nullptr;
}
CondimentList::CondimentList(CondimentList* &cl)
{
    head = copyHelper(cl->head);
}
CondimentListNode* CondimentList::copyHelper(CondimentListNode* &clNode)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    CondimentListNode* newNode = new CondimentListNode(clNode->condiment);
    newNode->next = copyHelper(clNode->next);
    return newNode;
}
void CondimentList::add_Condiment(char* condiment)
{
    CondimentListNode* node = new CondimentListNode(condiment);
    CondimentListNode* temp = head;
    if(temp == nullptr)
    {
        head = node;
    }
    else
    {
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}
void CondimentList::print_condiment()
{
    if(head != nullptr)
    {
        std::cout<<'\t'<<"Condiments to be added are..."<<'\n';
        CondimentListNode* temp = head;
        while(temp->next != nullptr)
        {
            std::cout<<'\t'<<temp->condiment<<'\n';
            temp=temp->next;
        }
        std::cout<<temp->condiment<<'\n';
    }
    else
    {
        std::cout<<"No condiments suggested"<<'\n';
    }
}
CondimentList::~CondimentList()
{
    //dtor
    CondimentListNode* temp = head;
    CondimentListNode* current = head;
    while(current!=nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
}
