#include <ctime>
#include <cstdlib>
#include <iostream>
class Dice
{
    private:
      int all_dices[3];
      int totalPoints;
    public:
      Dice(){
        srand(time(0));
        for(int i=0;i<3;i++)
        {
            all_dices[i]=0;
        }
        totalPoints=0;
      }
      virtual ~Dice();
      void rollDice();
      void displayState();
      Dice operator++();
      Dice& operator+=(int q);
      bool operator>(const Dice& other);
      bool operator<(const Dice& other);
      Dice operator=(const Dice& other);
      friend ostream& operator<<(ostream& os, const Dice& obj);
}; 