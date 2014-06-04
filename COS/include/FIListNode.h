#ifndef FILISTNODE_H
#define FILISTNODE_H
#include<FoodItem.h>

class FIListNode//FoodItem Linked List Node Class
{
    public:
        /** Default constructor */
        FIListNode();
        FIListNode(FoodItem* fi);

        /** Default destructor */
        virtual ~FIListNode();

    protected:
        FoodItem* fi;
        FIListNode* next;
    private:
    friend class FIList;
};

#endif // FILISTNODE_H
