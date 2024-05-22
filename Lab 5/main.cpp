#include <iostream>
#include "dice.h"

using namespace std;

int main()
{
    int choice;
    Dice dice;
    while(true){
    cout<<"Choose ur option: "<<endl;
    cout<<"1.Roll dices"<<endl;
    cout<<"2.Show results"<<endl;
    cin>>choice;
    if(choice==1){
        dice.rollDice();
    }else if(choice==2){
        dice.displayState();
    }else{
        cout<<"Invalid input!";
    }
    }

}