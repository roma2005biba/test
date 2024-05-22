 #include <iostream>
#include <string>
#include <cstring>

using namespace std;

int func(int* arr, int length, int number)
{
    for(int i=length-1; i>=0; i--){
        if(arr[i] == number)
           return i;
    }
    return -1;
}

int func(char* str, char ch)
{
    int numberOfCharacter = strlen(str);
    for(int i = numberOfCharacter; i >= 0 ; i--){
        if(str[i] == ch)
        return i;
    }
    return -1;
}

int main()
{
    int numbers[100], lengthOfArray, choice, findNumber;
    cout<<"Choose: numbers or chars?"<<endl;
    cout<<"1.Numbers "<<endl;
    cout<<"2.Chars "<<endl;
    cin>>choice;
    cin.ignore();
    if(choice == 1){
        cout<<"Enter the amount of numbers in an array and array itself!"<<endl;
        cin>>lengthOfArray;
        for(int i=0 ; i<lengthOfArray; i++)
        {
            cin>>numbers[i];
        }
        cout<<"Now enter a number which u want to find: ";
        cin>>findNumber;
        cout<<"Last index of this number is: "<<func(numbers , lengthOfArray, findNumber);

    }else if(choice == 2){
        cout<<"Enter ur line!"<<endl;
        string lineStart ; char characterToFind;
        getline(cin,lineStart);
        const int maxSize = 100;
        char charArray [maxSize + 1];
        lineStart.copy(charArray, maxSize);
        charArray[lineStart.length()] = '\0';

        cout<<"What character do u want to find?"<<endl;
        cin>>characterToFind;
        cout<<"Index of ur character is: "<<func(charArray, characterToFind);

    }else cout<<"There are no options with such index!";
}