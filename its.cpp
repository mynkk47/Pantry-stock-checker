#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()

{

    while (true)
{
  

    cout << "----------------------------------" << endl;
    cout << "Welcome to item stock checker tool" << endl;
    cout << endl;

    map<string, int> pantry;

    int choice;

    cout << "--------------------" << endl;
    cout << "What you want to do?" << endl;
    cout << endl;
    cout << "1. creating product directory" << endl;
    cout << "2. restocking products" << endl;
    cout << "3. checking availability of product" << endl;
    cout << "4. displaying whole stock in pantry" << endl;
    cout << "5. withdrawing product from pantry" << endl;

    cin >> choice;

    switch (choice)
    {

    case 1:  // adding product to pantryy
    {
        cout << "-------------------------------------------" << endl;
        cout << "How many products you want to add to pantry" << endl;
        cout << endl;

        int x;
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            string productname;

            cout << "-------------------------------" << endl;
            cout << "Please Enter your product name " << i + 1 << endl;
            cout << endl;
            cin >> productname;

            int stock;

            cout << "-------------------------------" << endl;
            cout << "Please Enter the stock of " << productname << " ?" << endl;
            cout << endl;
            cin >> stock;

            pantry[productname] = stock;
            cout<<endl;
            cout << "Added product named: " << productname
                 << " And available stock is : " << stock << endl;
                 cout<<endl;
        }

        break;
    }

    case 2:   // restocking pantry
    {
        int a;

        cout << "How many products you want to restock?" << endl;
        cin >> a;

        for (int i = 0; i < a; i++)
        {
            string modified;

            cout << "-----------------------------------------------" << endl;
            cout << "Enter the name of product you want to restock?" << endl;
            cout << endl;
            cin >> modified;

            int newq;

            cout << "-----------------------------------" << endl;
            cout << "Enter the stock you want to add to " << modified << endl;
            cout << endl;
            cin >> newq;

            if (pantry.find(modified) != pantry.end())         // bug#1 
            {
                pantry[modified] += newq;

                cout << "Stock updated successfully!" << endl;
                cout << endl;
                cout << "---------------------------------" << endl;
                cout << "New Stock of " << modified << " is : "
                     << pantry[modified] << endl;
                cout << endl;
            }
            else
            {
                cout << "Product not found in pantry!" << endl;
                cout << endl;
            }
        }

        break;
    }

    case 3:  // checking pantry stocks
    {
        string name;

        cout << "Enter the Product name to Check stock of it" << endl;
        cout << endl;

        cin >> name;

        if (pantry.count(name))
        {
            cout << name << " Available in pantry with stock "
                 << pantry[name] << endl;
        }
        else
        {
            cout << "Product doesn't exist in pantry." << endl;
        }

        break;
    }

    case 4:  // displaying all  available products in pantry
    {
        cout << endl;
        cout << "---------------------------------------------" << endl;
        cout << "The list of available items and their stock :" << endl;
        cout << endl;

        for (auto ls : pantry)
        {
            cout << ls.first << " : " << ls.second << endl;
        }

        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Total Products available in pantry is : "
             << pantry.size() << endl;
        cout << endl;

        break;
    }

    case 5:  // withdrawin products from pantry
    {
        cout << "Withdraw feature not implemented yet." << endl;
        break;
    }

    default:
    {
        cout << "Invalid Choice!" << endl;
        break;
    }
    }

    
}

    return 0;
}