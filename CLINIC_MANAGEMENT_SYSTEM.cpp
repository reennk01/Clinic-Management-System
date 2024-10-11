#include<iostream>
using namespace std;

#define PERSONS_LIMIT 50 //preprocessor directive to declare a constant 

int countPersons = 0; //global variable 

class Persons {
public:
    int Id; //members
    char Name[30];
    int Age;
    char Dob[20];
    char Doctorname[30];
    char Gender;
};

Persons obj[PERSONS_LIMIT];  //object = obj , for class Person and have given the size of Person_Limit which is 50

void input() { //taking input here about the patient
    if (countPersons < PERSONS_LIMIT) {
        cout << "\n Enter id (number): ";
        cin >> obj[countPersons].Id;
        cout << "\n Enter Name (30 characters): ";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.getline(obj[countPersons].Name, 30);
        cout << "\n Enter Age (number): ";
        cin >> obj[countPersons].Age;
        cout << "\n Enter DOB (dd-mm-yyyy): ";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.getline(obj[countPersons].Dob, 20);
        cout << "\n Enter Doctor's Name \n(Dr. Sohail Khan, Dr. Nosheen, Dr. Sameena): ";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.getline(obj[countPersons].Doctorname, 30);
        cout << "\n Enter Gender (M/F) : ";
        cin >> obj[countPersons].Gender;
        countPersons++;
    }
    else {
        cout << "\n Error : Limit is only " << PERSONS_LIMIT;
    }
}

void printAll() {
    cout << "\n **** **** Printing All Records **** ****";
    cout << "\n total number of persons : " << countPersons << endl;
    for (int i = 0; i < countPersons; i++) {
        cout << "\n Id : " << obj[i].Id;
        cout << "\t Name : " << obj[i].Name;
        cout << "\t Age : " << obj[i].Age;
        cout << "\t DOB : " << obj[i].Dob;
        cout << "\t Appointment with Doctor: " << obj[i].Doctorname;
        cout << "\t Gender : " << obj[i].Gender;
    }
}

void printbyAge() {
    cout << "\n **** **** Printing All Records by Age********";
    int count40plus = 0;
    int count20plus = 0;
    int lessthen20 = 0;

    for (int i = 0; i < countPersons; i++) {
        if (obj[i].Age > 40)
            count40plus++;
        else if (obj[i].Age > 20)
            count20plus++;
        else
            lessthen20++;
    }

    cout << "\n Persons more than 40 : " << count40plus;
    cout << "\n Persons more than 20 : " << count20plus;
    cout << "\n Persons less than 20 : " << lessthen20;
}

void printGenderCount() {
    cout << "\n **** **** Printing All Records by Gender Count ********";
    int malecount = 0;
    int femalecount = 0;

    for (int i = 0; i < countPersons; i++) {
        if (obj[i].Gender == 'M')
            malecount++;
        else if (obj[i].Gender == 'F')
            femalecount++;
    }
    cout << "\n Number of Male : " << malecount;
    cout << "\n Number of Female : " << femalecount;
}

int main() {
    int choice = -1;

    while (choice != 0) {
        cout << "\n\n ============Program Menu==========";
        cout << "\n 1 Input Records ";
        cout << "\n 2 Print All Records";
        cout << "\n 3 Print by Age";
        cout << "\n 4 Print by Gender count";
        cout << "\n 0 to exit";

        cout << "\n Enter your choice : ";
        cin >> choice;

        switch (choice) {

        case 1:
            input();
            break;
        case 2:
            printAll();
            break;
        case 3:
            printbyAge();
            break;
        case 4:
            printGenderCount();
            break;
        case 0:
            cout << "\n Have A Nice Day Ahead :) !!";
            break;
        default:
            cout << "\n Error: Invalid Selection";
        }
    }

    return 0;
}

