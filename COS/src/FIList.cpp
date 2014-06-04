#include "FIList.h"
#include <iostream>
#include<FoodItem.h>
FIList::FIList()
{
    //ctor
    head = nullptr;
    //std::cout<<"in filist cstr"<<'\n';
}
FIList* FIList::operator=(FIList* &linkedlist)
{
    if(this != linkedlist)
    {
        head = copyHelper(linkedlist->head);
    }
    return this;
}
FIListNode* FIList::copyHelper(FIListNode* &node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    FIListNode* newNode = new FIListNode(node->fi->myCopy());
    newNode->next = copyHelper(node->next);
    return newNode;
}
void FIList::listPrint()
{
    if(head != nullptr)
    {
        FIListNode* temp = head;
        while(temp->next != nullptr)
        {
            (temp->fi)->print();
            temp=temp->next;
        }
        temp->fi->print();
    }
    else
    {
        std::cout<<"List is empty"<<'\n';
    }


}
void FIList::addNode(FoodItem* fi)
{
    FIListNode* fiNode = new FIListNode(fi);
    FIListNode* temp = head;
    if(temp == nullptr){
        head = fiNode;
    }
    else
    {
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = fiNode;
    }
}
FIList::~FIList()
{
    //dtor
    FIListNode* temp = head;
    FIListNode* current = head;
    while(current!=nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
}
