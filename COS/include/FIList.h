#ifndef FILIST_H
#define FILIST_H
#include<FIListNode.h>

class FIList
{
    public:
        /** Default constructor */
        FIList();

        FIList* operator=(FIList* &linkedlist);

        void addNode(FoodItem* fi);
        FIListNode* copyHelper(FIListNode* &node);
        void listPrint();

        /** Default destructor */
        virtual ~FIList();

    protected:
        FIListNode* head;
    private:
};

#endif // FILIST_H
