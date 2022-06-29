#include "linkedlist.h"

void menu();

list *l;

int main(){
    l = new list();
    system("clear");
    menu();
}

void menu(){
    int input;
    cout << "---- Select Menu ---- \n1. Add \n2. Delete \n3. Print \n4. Exit \nInput : ";
    cin >> input;
    switch (input)
    {
    case 1:
        system("clear");
        l->add();
        menu();
        break;
    case 2:
        system("clear");
        l->del();
        menu();
        break;
    case 3:
        system("clear");
        l->print();
        menu();
        break;
    case 4:
        system("clear");
        l->exit(l);
        break;
    default:
        system("clear");
        menu();
        break;
    }
}
