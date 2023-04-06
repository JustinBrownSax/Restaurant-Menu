//
//  main.cpp
//  Csis 223 9.5
//
//  Created by Justin Brown on 1/24/23.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
    int cnt;
    menuItemType() {
        menuItem="";
        menuPrice=0.0;
        cnt=0;
    }
};

void getData(ifstream &inf,menuItemType menuList[],int &count) {
string name, str;
while(getline(inf,name)) {
    menuList[count].menuItem=name;
    getline(inf,str);
    menuList[count].menuPrice=atof(str.c_str());
    count++;
    }
inf.close();
}

void showMenu(menuItemType menuList[], int x) {
    int count;
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << "----Today's Menu----" << endl;
    for (count = 0; count < x; count++) {
        cout << setw(1) << left << count + 1 << ": ";
        cout<<setw(30)<<left<< menuList[count].menuItem << '$'
        << menuList[count].menuPrice << endl;
    }
}

void printCheck(menuItemType menuList[]) {
    double checkTotal = 0;
    double checkTax = 0;
    const double tax = .05;
    cout << "Welcome to Johnny's Restaurant" << endl;
    for (int i = 0; i < 8; i++) {
        if(menuList[i].cnt!=0) {
            cout<<setw(5)<<left<<menuList[i].cnt << setw(20) << left << menuList[i].menuItem
            << '$' << menuList[i].menuPrice*menuList[i].cnt << endl;
            checkTotal += (menuList[i].menuPrice*menuList[i].cnt);
        }

    }
    checkTax = checkTotal * tax;
    checkTotal += checkTax;
    cout << setw(15) << left << " Tax"<<setw(11)<<right<<"$" << checkTax << endl;
    cout<< setw(14) << left<< " Amount Due "<<setw(11)<<right<<"$" << checkTotal << endl;
    system("pause");
}


int main() {
   cout << setprecision(2) << fixed;
    int menuItems = 0;
    menuItemType menuList[100];
    int orderChoice = 0;
    bool ordering = true;
    char selection;
    ifstream inf;
    inf.open("Ch9_Ex4Data.txt");

    if(inf.fail()) {
        cout<<"Cannot open the input file. program Terminates!"<<endl;
        exit(0);
    }
    else {

        getData(inf,menuList,menuItems);
        showMenu(menuList, menuItems);
        cout << "You can make up to 8 single order selections" << endl;
        cout << "Do you want to make selection Y/y (Yes), N/n (No): ";
        while (ordering) {
            cin >> selection;
            if (selection == 'Y' || selection == 'y') {
                cout << "Enter item number: ";
                cin >> orderChoice;
                if ((orderChoice > 0 && orderChoice <= menuItems) && menuList[orderChoice - 1].cnt>0) {
                ++menuList[orderChoice - 1].cnt;
                }
                else if (orderChoice > 0 && orderChoice <= menuItems) {
                    ++menuList[orderChoice - 1].cnt;
                    }
            
                cout << "Select another item Y/y (Yes), N/n (No): ";

            }
            else {
                ordering = false;
            }
        }

        printCheck(menuList);
    }


    return 0;
}
