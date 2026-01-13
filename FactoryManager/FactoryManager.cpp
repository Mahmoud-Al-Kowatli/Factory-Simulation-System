#include "FactoryManager.h"

void pressAnyButtonToContinue() {
    cout << "\nPress any button to continue....";
    system("pause>0");
    system("cls");
}

void FactoryManager::printOrderDetailsForEditOrDelete(Order order)
{
    cout << "\n================================================================\n";
    cout << "ID: " << order.getID();
    cout << "\nClient's Name: " << order.getClient().getName();
    cout << "\nClient's ID: " << order.getClientID();
    cout << "\nQuantity: " << order.getRequiredQuantity();
    cout << "\nPrice: $" << order.getTotalValue();
    cout << "\n================================================================\n";
}

int FactoryManager::checkIfNumber() // checks if user entered a number or not
{
    string TheInput;
    int x;
    while (true)
    {
        try
        {
            cout << "please enter the number: ";
            cin >> TheInput;
            cout << endl;
            x = stoi(TheInput);
            break;
        }
        catch (...)
        {
            cout << "your input isnt a number, please enter a valid number" << endl;
        }
    }
    return x;
}

int FactoryManager::checkIfNumber(int x, int y) // checks if a the input is number & between range x,y
{
    string TheInput;
    int num;
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
            num = stoi(TheInput);
            if (num < x || num > y)
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

int FactoryManager::choosingProductID()
{
    cout << "\n================================================================\n";
    cout << "Please choose the product you want by typing its number:";
    cout << "\n================================================================\n";
    Product::traverse([](Product p) { cout << p.getID() << ") " << p.getName() << endl; });
    int maximum = Product::getProductsNumber();
    return checkIfNumber(1, maximum);
}

int FactoryManager::choosingClientID()
{
    cout << "Which of these clients want to place an order (choose client's number):\n";
    Client::traverse([](Client c) { cout << c.getID() << ") " << c.getName() << endl; });
    int maximum = Client::getClientsNumber();
    return checkIfNumber(1, maximum);
}

Order::Priority FactoryManager::setPriority()
{
    int choice;
    cout << "\n================================================================\n";
    cout << "please choose the order's priority you want by typing its number" << endl;
    cout << "1- Normal" << endl;
    cout << "2- VIP" << endl;
    cout << "3- Urgent";
    cout << "\n================================================================\n";
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

void FactoryManager::addOrder()
{
    cout << "\n================================================================\n";
    cout << "please, enter the required order's information in order" << endl;
    int productID = choosingProductID(), clientID = choosingClientID();

    cout << "please, enter the quantity you want: " << endl;
    int quantity = checkIfNumber();

    cout << "please, set the priority: " << endl;
    Order::Priority priorityChosen = setPriority();

    Order TheOrder(priorityChosen, quantity, productID, clientID);

    OrdersManager::receiveOrder(TheOrder);
    int id = TheOrder.getID();
    cout << "your order's ID is: " << id << endl;
    cout << "your order's total price is: " << TheOrder.getTotalValue();
    cout << "\n================================================================\n";
}

void FactoryManager::editOrder()
{
    Order order;


    OrdersManager::traverse(printOrderDetailsForEditOrDelete);

    cout << "please enter the order's ID: " << endl;
    int orderID = checkIfNumber();

    cout << "\n================================================================\n";
    while (!OrdersManager::getOrderByID(order, orderID))
    {
        cout << "order not found, ID is wrong, please try again.";
        orderID = checkIfNumber();
    }
    cout << "Please choose what do you want to change by typing the number of it:" << endl;
    cout << "1- edit order's priority" << endl;
    cout << "2- edit order's quantity";
    cout << "\n================================================================\n";
    int choice = checkIfNumber(1, 2);
    if (choice == 1)
    {
        order.setPriority(setPriority());
    }
    else if (choice == 2)
    {
        int newQuantity = checkIfNumber();
        order.setQuantity(newQuantity);
        cout << "the new price of your order: " << order.getTotalValue() << endl;
    }
}

void FactoryManager::showHistory()
{
    cout << "this is all order's history: " << endl;
    OrdersManager::getAllOrdersHistory();
}

void FactoryManager::tryDeleteOrder()
{
    Order order;
    OrdersManager::traverse(printOrderDetailsForEditOrDelete);
    cout << "please enter the order's ID: " << endl;
    int orderID = checkIfNumber();
    while (!OrdersManager::getOrderByID(order, orderID))
    {
        cout << "order not found, ID is wrong, please try again.";
        orderID = OrdersManager::getOrderByID(order, orderID);
    }
    if (OrdersManager::tryDeleteOrder(orderID))
        cout << "Failed to delete, try again later";
    else
        cout << "Deleted Successfully!";
}

void FactoryManager::runSimulation()
{
	system("cls");
    cout << "Welcome" << endl;
    
    while (true)
    {
        cout << "\n================================================================\n";
        cout << "please choose one of the following actions by choosing its number: " << endl;
        cout << "1- if you want to add an order" << endl;
        cout << "2- if you want to edit an existing order" << endl;
        cout << "3- if you want to to delete order" << endl;
        cout << "4- if want to see all order's history" << endl;
        cout << "5- if you want to stop the program" << endl;
        cout << "\n================================================================\n";
        int UserChoice;
        UserChoice = checkIfNumber(1, 5);

            system("cls");
        switch (UserChoice)
        {
        case 1:
            addOrder();
            pressAnyButtonToContinue();
            break;
        case 2:
            editOrder();
            pressAnyButtonToContinue();
            break;
        case 3:
			tryDeleteOrder();
            pressAnyButtonToContinue();
            break;
        case 4:
            showHistory();
            pressAnyButtonToContinue();
            break;
        case 5:
            cout << "Thank you for using our services :-)\n";
            pressAnyButtonToContinue();
            return;
        default:
            break;
        }

    }
}
