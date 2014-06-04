#include <iostream>
#include<EggplantCasserole.h>
#include<TurkeySandwich.h>
#include<Salmon.h>
#include<FIList.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<limits>
using namespace std;

int main()
{
    FIList* fiListArray[10];
    for(int i=0; i<10; i++)
    {
        fiListArray[i] = nullptr;
    }
    char choice;
    char condOption;
    char sideDish[1024];
    char condiment[1024];
    int noOfOunces;
    int patron;
    int spatron;
    int dpatron;
    int fioption;
    int csoption;
    int sboption;
    Salmon::cooking_style cs;
    TurkeySandwich::sandwich_bread sb;
    FoodItem* fi;
    string restOfLine;
   while(1){
        cout<<'\n';
        cout<<'\t'<<'\t'<<'\t'<<"*****CUSTOMER ORDER SYSTEM*****\n\n";
        cout<<'\t'<<'\t'<<'\t'<<" n - New List.\n";
        cout<<'\t'<<'\t'<<'\t'<<" a - Add List Entry.\n";
        cout<<'\t'<<'\t'<<'\t'<<" c - Copy List.\n";
        cout<<'\t'<<'\t'<<'\t'<<" d - Delete List.\n";
        cout<<'\t'<<'\t'<<'\t'<<" l - List Patron.\n";
        cout<<'\t'<<'\t'<<'\t'<<" s - Swap Orders.\n";
        cout<<'\t'<<'\t'<<'\t'<<" q - Quit.\n";
        choice = getch();
        cout<<choice<<'\n';
        switch(choice){
            case 'n' :
                cout<<"Enter Patron Number between 1 and 10:";
                cin>>patron;
                cout<<patron<<'\n';
                //getline(cin, restOfLine);
                if(patron>0 && patron<11)
                {
                    if(fiListArray[patron-1] == nullptr)
                    {
                        fiListArray[patron-1] = new FIList();
                    }
                    else
                    {
                        cout<<"Seat is occupied"<<'\n';
                    }
                }
                else
                {
                    cout<<"Invalid Patron number"<<'\n';
                }
                break;
            case 'a' :
                cout<<"Enter Patron Number between 1 and 10:";
                cin>>patron;
                getline(cin, restOfLine);
                if(patron>0 && patron<11)
                {
                    if(fiListArray[patron-1] == nullptr)
                    {
                        cout<<"Patron List does not exist, create a new list with option n"<<'\n';
                    }
                    else
                    {
                        cout<<'\n';
                        cout<<"1) For Salmon press 1"<<'\n';
                        cout<<"2) For Turkey Sandwich press 2"<<'\n';
                        cout<<"3) For Eggplant Casserole press 3"<<'\n';
                        cin>>fioption;
                        getline(cin, restOfLine);
                        if(fioption>0 && fioption<4)
                        {
                            if(fioption == 3)
                            {
                                cout<<"Please enter sideDish and terminate with Enter key: ";
                                cin.ignore();
                                std::cin.getline(sideDish,1024);
                                cout<<"Please enter number of Ounces: ";
                                cin>>noOfOunces;
                                EggplantCasserole* ec = new EggplantCasserole(noOfOunces, sideDish);
                                fi = ec;
                                fiListArray[patron -1]->addNode(fi);
                            }
                            else if(fioption == 1)
                            {
                                cout<<"Please enter sideDish and terminate with Enter key: ";
                                cin.ignore();
                                std::cin.getline(sideDish,1024);
                                cout<<"Please enter Cooking Style"<<'\n';
                                cout<<"1) Enter 1 for Rare"<<'\n';
                                cout<<"2) Enter 2 for Medium"<<'\n';
                                cout<<"3) Enter 3 for Well-Done"<<'\n';
                                cin>>csoption;
                                if(csoption==1)
                                {
                                    cs = Salmon::cooking_style::RARE;
                                }
                                else if(csoption == 2)
                                {
                                    cs = Salmon::cooking_style::MEDIUM;
                                }
                                else if(csoption == 3)
                                {
                                    cs = Salmon::cooking_style::WELLDONE;
                                }
                                Salmon* sm = new Salmon(sideDish,cs);
                                fi = sm;
                                fiListArray[patron -1]->addNode(fi);
                            }
                            else if(fioption == 2)
                            {
                                cout<<"Please enter Sandwich Bread"<<'\n';
                                cout<<"1) Enter 1 for White"<<'\n';
                                cout<<"2) Enter 2 for Whole"<<'\n';
                                cout<<"3) Enter 3 for Wheat"<<'\n';
                                cout<<"4) Enter 4 for Rye"<<'\n';
                                cin>>sboption;
                                if(sboption == 1)
                                {
                                    sb = TurkeySandwich::sandwich_bread::WHITE;
                                }
                                else if(sboption == 2)
                                {
                                    sb = TurkeySandwich::sandwich_bread::WHOLE;
                                }
                                else if(sboption == 3)
                                {
                                    sb = TurkeySandwich::sandwich_bread::WHEAT;
                                }
                                else if(sboption == 4)
                                {
                                    sb = TurkeySandwich::sandwich_bread::RYE;
                                }
                                CondimentList* cl= new CondimentList();
                                do
                                {
                                    cout<<"Please enter a condiment with Enter key: ";
                                    cin.ignore();
                                    std::cin.getline(condiment,1024);
                                    cl->add_Condiment(condiment);
                                    cout<<"Enter y to add more condiments or any other to move ahead"<<'\n';
                                    condOption = getch();
                                }
                                while(condOption == 'y');
                                TurkeySandwich* ts = new TurkeySandwich(sb,cl);
                                fi = ts;
                                fiListArray[patron -1]->addNode(fi);
                            }
                        }
                        else
                            cout<<"Invalid Food Item option, try again"<<'\n';
                    }
                }
                else
                {
                    cout<<"Invalid Patron number"<<'\n';
                }
                break;
            case 's' :
                cout<<"Enter swap Patron Number 1 between 1 and 10:";
                cin>>spatron;
                if(spatron>0 && spatron<11)
                {
                    if(fiListArray[spatron-1] == nullptr)
                    {
                        cout<<"Patron Source List does not exist, create a new list with option n"<<'\n';
                    }
                    else
                    {
                        cout<<"Enter swap Patron Number 2 between 1 and 10:";
                        cin>>dpatron;
                        if(dpatron>0 && dpatron<11)
                        {
                            if(fiListArray[dpatron-1] == nullptr)
                            {
                                cout<<"Patron Destination List does not exist, create a new list with option n"<<'\n';
                            }
                            else
                            {
                                FIList* temp;
                                temp = fiListArray[dpatron-1];
                                fiListArray[dpatron-1] = fiListArray[spatron-1];
                                fiListArray[spatron-1] = temp;
                                cout<<"Swap1 is now:"<<'\n';
                                fiListArray[spatron-1]->listPrint();
                                cout<<"Swap2 is now:"<<'\n';
                                fiListArray[dpatron-1]->listPrint();

                            }
                        }
                        else
                        {
                            cout<<"Invalid Destination Patron number"<<'\n';
                        }
                    }
                }
                else
                {
                    cout<<"Invalid Source Patron number"<<'\n';
                }
                break;
            case 'c' :
                cout<<"Enter source Patron Number between 1 and 10:";
                cin>>spatron;
                if(spatron>0 && spatron<11)
                {
                    if(fiListArray[spatron-1] == nullptr)
                    {
                        cout<<"Patron Source List does not exist, create a new list with option n"<<'\n';
                    }
                    else
                    {
                        cout<<"Enter destination Patron Number between 1 and 10:";
                        cin>>dpatron;
                        if(dpatron>0 && dpatron<11)
                        {
                            if(fiListArray[dpatron-1] == nullptr)
                            {
                                cout<<"Patron Destination List does not exist, create a new list with option n"<<'\n';
                            }
                            else
                            {
                                fiListArray[dpatron-1] = fiListArray[spatron-1];
                                cout<<"Copied list is:"<<'\n';
                                fiListArray[dpatron-1]->listPrint();

                            }
                        }
                        else
                        {
                            cout<<"Invalid Destination Patron number"<<'\n';
                        }
                    }
                }
                else
                {
                    cout<<"Invalid Source Patron number"<<'\n';
                }
                break;

            case 'l' :
                cout<<"Enter Patron Number between 1 and 10:";
                cin>>patron;
                if(patron>0 && patron<11)
                {
                    if(fiListArray[patron-1] == nullptr)
                    {
                        cout<<"Patron List does not exist, create a new list with option n"<<'\n';
                    }
                    else
                    {
                        fiListArray[patron-1]->listPrint();
                    }
                }
                else
                {
                    cout<<"Invalid Patron Number between 1 and 10:"<<'\n';
                }
                break;
            case 'd' :
                cout<<"Enter Patron Number between 1 and 10:";
                cin>>patron;
                if(patron>0 && patron<11)
                {
                    if(fiListArray[patron-1] == nullptr)
                    {
                        cout<<"Patron List does not exist, create a new list with option n"<<'\n';
                    }
                    else
                    {
                        delete fiListArray[patron-1];
                        fiListArray[patron-1] = nullptr;
                    }
                }
                else
                {
                    cout<<"Invalid Patron Number between 1 and 10:";
                }
                break;
            case 'q' :
                exit(0);
            default:
                cout<<"Please enter a correct choice"<<'\n';
                break;

        }

    }
    return 0;
}
