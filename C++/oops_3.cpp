#include <iostream>
using namespace std;

class Shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void)
    {
        counter = 0;
    }

    void setPrice(void);
    void displayPrice(void);
};

void Shop::setPrice(void)
{
    if (counter >= 100)
    {
        cout << "Cannot add more items. Maximum limit reached." << endl;
        return;
    }
    cout << "Enter id of your item: ";
    cin >> itemId[counter];
    cout << "Enter price of your item: ";
    cin >> itemPrice[counter];
    counter++;
}

void Shop::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "Item ID: " << itemId[i] << ", Price: " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop myShop;
    myShop.initCounter();

    int choice;
    while (true)
    {
        cout << "Enter 1 to add item price, 2 to display all prices, 0 to exit: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            myShop.setPrice();
            break;
        case 2:
            myShop.displayPrice();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
