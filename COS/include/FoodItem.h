#ifndef FOODITEM_H
#define FOODITEM_H


class FoodItem
{
    public:
        /** Default constructor */
        FoodItem();
        FoodItem(char* name, double price, int calCount);
        FoodItem(const FoodItem& fi);
        virtual FoodItem* myCopy()=0;//Pure virtual copy scheme and also makes class abstract, pure virtual function
        /** Default destructor */
        virtual void print();//virtual print function
        virtual ~FoodItem();//virtual deletion
    protected:
        char* name;
        double price;
        int calCount;
    private:
};

#endif // FOODITEM_H
