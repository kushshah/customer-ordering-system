#ifndef EGGPLANTCASSEROLE_H
#define EGGPLANTCASSEROLE_H
#include<FoodItem.h>

class EggplantCasserole: public FoodItem
{
    public:
        /** Default constructor */
        EggplantCasserole();
        EggplantCasserole(int noOfOunces, char* sideDish);
        EggplantCasserole(const EggplantCasserole& ec);

        virtual EggplantCasserole* myCopy();
        virtual void print();

        /** Default destructor */
        virtual ~EggplantCasserole();

    protected:
        int noOfOunces;
        char* sideDish;
    private:
};

#endif // EGGPLANTCASSEROLE_H
