#ifndef TURKEYSANDWICH_H
#define TURKEYSANDWICH_H
#include<FoodItem.h>
#include<CondimentList.h>

class TurkeySandwich: public FoodItem
{
    public:
        enum sandwich_bread{WHITE,WHOLE,WHEAT,RYE};

        /** Default constructor */
        TurkeySandwich();
        TurkeySandwich(sandwich_bread bread,CondimentList* &cl);
        TurkeySandwich(const TurkeySandwich& ts);

        virtual TurkeySandwich* myCopy();
        virtual void print();

        /** Default destructor */
        virtual ~TurkeySandwich();

    protected:
        sandwich_bread bread;
        CondimentList* cl;
    private:
};

#endif // TURKEYSANDWICH_H
