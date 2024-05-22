#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int surname_length = 0;
int name_length = 0;

int main()
{
    int max_surname = 0, max_name = 0;
    bool is_start = true;
    while(true){
        cout<<"Choose ur option: "<<endl;
        cout<<"Show the data from file - '1': "<<endl;
        cout<<"Add data in file - '2': "<<endl;
        cout<<"Delete data in file - '3': "<<endl;
        cout<<"Exit - '4': "<<endl;
        
        if(is_start){
            ifstream infile;
            infile.open("Students.txt");
            string surname, name;
            int year;
            while(infile >> surname >> name >> year)
            {
                if(surname.length() > max_surname){
                    max_surname=surname.length();
                }if(name.length() > max_name){
                    max_name = name.length();
                }
            }
            infile.clear(); 
            infile.seekg(0);
            infile.close();
        }
        int choice;
        cin>>choice;
        if(choice == 1){
            string surname, name;
            int year;
            ifstream infile;
            infile.open("Students.txt");
            if(!infile){
                cout<<"Сan not open this file!"<<endl;
                return -1;
            }
            cout<< setw(max_surname) << "Surname" << setw(max_name) << "Name" << setw(9) << "Year" << endl;
            while(infile >> surname >> name >> year){
                cout<< setw(max_surname + 3) << surname << setw(max_name + 3) << name << setw(9) << year << endl;
            }
            infile.clear(); 
            infile.seekg(0);
            infile.close();
        }
        else if (choice == 2)
        {
           string surname, name; int year;
           cin>>surname>>name>>year;
           if(surname.length() > max_surname){
                max_surname=surname.length();
            }if(name.length() > max_name){
                max_name = name.length();
            }
           fstream outfile("Students.txt", ios::app);
           if (!outfile)
           {
               cout << "Cannot open file" << endl;
               return -1;
           }
           outfile.setf(ios::left);
           outfile.width(max_surname);
           outfile << surname<<' ';
           outfile.width(max_name);
           outfile << name;
           outfile.width(10);
           outfile << year<<endl;
           outfile.close();
        }else if(choice == 3){
            ofstream outfile("Students.txt", ios::trunc);
            outfile.close();
        }else if(choice == 4){
            break;
        }else{
            cout<<"Invalid choice"<<endl;
        }
        cin.ignore();
        cin.get();
        is_start = false;
    }
    return 0;
}