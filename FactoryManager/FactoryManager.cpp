#include "FactoryManager.h"
FactoryManager::FactoryManager()
{
    runSimulation();
}

FactoryManager::~FactoryManager()
{
}

int FactoryManager::checkIfNumber()
{
    string TheInput;
    float x;
    while (true)
    {
        try
        {
            cout << "please enter the number: ";
            cin >> TheInput;
            cout << endl;
            x = stof(TheInput);
            break;
        }
        catch (...)
        {
            cout << "your input isnt a number, please enter a valid number" << endl;
        }
    }
    return x;
}

int FactoryManager::checkIfNumber(int x, int y)
{
    string TheInput;
    float num;
    while (true)
    {
        try
        {
            cout << "please enter the number between " << x << " and " << y << " :" << endl;
            cin >> TheInput;
            for (char c : TheInput)
            {
                if (!isdigit(c))
                {
                    throw "its not a number! please enter a number";
                }
            }

            cout << endl;
            num = stof(TheInput);
            if (num < x && num > y)
            {
                throw "input number out of range";
            }
            break;
        }
        catch (const char *msg)
        {
            cout << "error: " << msg << endl;
        }
    }
    return num;
}

Product FactoryManager::choosingProduct()
{

    int choice;
    cout << "please choose the product's you want by typing its number";
    cout << "1- Officer Chair" << endl;
    cout << "2- Wooden Desk" << endl;
    cout << "3- Gaming Desk" << endl;
    cout << "4- Bookshelf" << endl;
    cout << "5- Drawer Cabient" << endl;
    choice = checkIfNumber(1, 5);
    if (choice == 1)
    {
        return Product::OFFICER_CHAIR;
    }
    else if (choice == 2)
    {
        return Product::WOODEN_DESK;
    }
    else if (choice == 3)
    {
        return Product::GAMING_DESK;
    }
    else if (choice == 4)
    {
        return Product::BOOKSHELF;
    }
    else
    {
        return Product::DRAWER_CABINET;
    }
}

Order::Priority FactoryManager::setPriority()
{

    int choice;
    cout << "please choose the order's priority you want by typing its number" << endl;
    cout << "1- Normal" << endl;
    cout << "2- VIP" << endl;
    cout << "3- Urgent" << endl;
    choice = checkIfNumber(1, 3);
    if (choice == 1)
    {
        return Order::Priority::NORMAL;
    }
    else if (choice == 2)
    {
        return Order::Priority::VIP;
    }
    else
    {
        return Order::Priority::URGENT;
    }
}

void FactoryManager::AddOrder()
{

    cout << "please, enter the required order's information in order" << endl;
    Product chosenProduct = choosingProduct();

    cout << "please, enter the quantity you want: " << endl;
    int quantity = checkIfNumber();

    cout << "please, set the priority: " << endl;
    Order::Priority priorityChosen = setPriority();

    Order TheOrder(priorityChosen, quantity, chosenProduct);

    orderManager.receiveOrder(TheOrder);
    int id = TheOrder.getID();
    cout << "your order's ID is: " << id << endl;
    cout << "your order's total price is: " << TheOrder.getTotalValue() << endl;
}

void FactoryManager::editOrder(int orderID)
{
    cout << "please enter the order's ID: " << endl;
    if (orderManager.orderExist(orderID) == false)
    {
        cout << "order not found, ID is wrong, please try again.";
        return;
    }
    orderManager.getOrderByID(orderID);
    cout << "please choose what do you want to change by typing the number of it:" << endl;
    cout << "1- edit order's priority" << endl;
    cout << "2- edit order's quantity" << endl;
    cout << "3- edit orders's product" << endl;

    int choice;
    choice = checkIfNumber(1, 3);
    if (choice == 1)
    {
        orderManager.getOrderByID(orderID).setPriority(setPriority());
    }
    else if (choice == 2)
    {
        int newQuantity = checkIfNumber();
        orderManager.getOrderByID(orderID).setQuantity(newQuantity);
        // cout << "the new price of your order: " << orderManager.getOrderByID(orderID).totalValue << endl;
    }
    else if (choice == 3)
    {
    }
}

void FactoryManager::showHistory()
{
    cout << "this is all order's history: " << endl;
    orderManager.getAllOrdersHistory();
}

void FactoryManager::deleteOrder()
{
}

void FactoryManager::runSimulation()
{
    cout << "Welcom" << endl;
    int programRunning = 0;
    while (programRunning == 0)
    {
        cout << "please choose one of the following actions by choosing its number: " << endl;
        cout << "1- if you want to add an order" << endl;
        cout << "2- if you want to edit and existing order" << endl;
        cout << "3- if you want to to delete order" << endl;
        cout << "4- if want to see all order's history" << endl;
        cout << "5- if you want to stop the program" << endl;
        int UserChoice;
        UserChoice = checkIfNumber(1, 4);
        if (UserChoice == 1)
        {
            AddOrder();
        }
        else if (UserChoice == 2)
        {
            int id;
            id = checkIfNumber();
            editOrder(id);
        }
        else if (UserChoice == 3)
        {
            deleteOrder();
        }
        else if (UserChoice = 4)
        {
            showHistory();
        }
        else if (UserChoice = 5)
        {
            programRunning = 1;
            continue;
        }
    }
}
