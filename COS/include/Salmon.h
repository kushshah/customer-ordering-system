#ifndef SALMON_H
#define SALMON_H
#include<FoodItem.h>

class Salmon: public FoodItem
{
    public:
        enum cooking_style{RARE,MEDIUM,WELLDONE};

        /** Default constructor */
        Salmon();
        Salmon(char* sideDish, Salmon::cooking_style ck);
        Salmon(const Salmon& sm);

        virtual Salmon* myCopy();
        virtual void print();

        /** Default destructor */
        virtual ~Salmon();

    protected:
        char* sideDish;
        cooking_style ck;
    private:
};

#endif // SALMON_H
