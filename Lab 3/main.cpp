#include <iostream>

using namespace std;

void func(int** arr, int number)
{
    int point = number / 2;
    if (number % 2 == 0) {
        int end = number - 1, if_second = 1;
        for (int i = 0; i < number; i++) {
            int old_end = end;
            for (int j = 0; j < number; j++) {
                if (j != end)
                    arr[i][j] = 1;
                else {
                    arr[i][j] = 0;
                    end++;
                }
            }
            end = old_end;
            if (end == point && if_second != 2) {
                if_second++;
            } else if (if_second == 2) {
                end++;
            } else {
                end--;
            }
        }
    } else {
        int end = number - 1;
        bool if_second = false;
        for (int i = 0; i < number; i++) {
            int old_end = end;
            for (int j = 0; j < number; j++) {
                if (j != end)
                    arr[i][j] = 1;
                else {
                    arr[i][j] = 0;
                    end++;
                }
            }
            end = old_end;
            if (end == point || if_second == true) {
                end++;
                if_second = true;\
            } else{
                end--;
            }
        }
    }
    
    
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}


int main()
{
    int number;
    cout<<"Enter order of matrix: ";
    cin>>number;
    int** arr = new int* [number];
    for(int i=0; i<number; i++){
        arr[i] = new int [number];
    }
    func(arr, number);
}