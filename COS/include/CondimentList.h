#ifndef CONDIMENTLIST_H
#define CONDIMENTLIST_H
#include<CondimentListNode.h>

class CondimentList
{
    public:
        /** Default constructor */
        CondimentList();
        CondimentList(CondimentList* &cl);

        CondimentListNode* copyHelper(CondimentListNode* &clNode);
        void add_Condiment(char* condiment);
        void print_condiment();

        /** Default destructor */
        virtual ~CondimentList();

    protected:
         CondimentListNode* head;
    private:
};

#endif // CONDIMENTLIST_H
