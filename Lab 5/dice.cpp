#include "dice.h"
using namespace std;
Dice::~Dice(){
}
void Dice::rollDice(){
    totalPoints = 0;
    for(int i=0;i<3;i++){
        all_dices[i] = rand()% 6 + 1;
        totalPoints +=all_dices[i];
    }
}
void Dice::displayState(){
    cout<<"Dice values: ";
    for(int i=0;i<3;i++){
        cout<<all_dices[i]<<' ';
    }
    cout<<"Total points: "<<totalPoints<<endl;
}
Dice Dice::operator++()
{
    for(int i=0 ; i<3 ; i++){
    all_dices[i]++;
    }
    return *this;
}
