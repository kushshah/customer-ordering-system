#ifndef CONDIMENTLISTNODE_H
#define CONDIMENTLISTNODE_H


class CondimentListNode
{
    public:
        /** Default constructor */
        CondimentListNode();
        CondimentListNode(char* condiment);

        /** Default destructor */
        virtual ~CondimentListNode();
    protected:
        char* condiment;
        CondimentListNode* next;
    private:
    friend class CondimentList;
};

#endif // CONDIMENTLISTNODE_H
