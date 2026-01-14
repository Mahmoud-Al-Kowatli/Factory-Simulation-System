#include "FactoryManager.h"

void FactoryManager::pressAnyButtonToContinue() {
cout << "\nPress Enter to continue....";

    #ifdef _WIN32
        // Code just fo Windows User 
        // Handling system commands for different Operating Systems:
        // Windows uses 'pause' and 'cls'
        // Linux (Arch) uses 'cin.get' and 'clear'
        
        system("pause>0");
        system("cls");
    #else
        // Code just for  Linux User (Arch) and other distro Linux 
        // Clear input buffer and wait for Enter key on Linux
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("clear");
    #endif
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
            cout << "\nplease enter the number: ";
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
            cout << "\nplease enter the number between " << x << " and " << y << " :" << endl;
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

void FactoryManager::registerOrder() 
{
    Order order;
    bool orderExists = OrdersManager::tryGetTopOrder(order);

    cout << "\n";

    if (!orderExists || order.getID() == 0)
    {
        cout << "There are no orders to start the production, wait for some Clients to Order some Products\n";
        return;
    }
    bool status = WarehouseManager::consumeMaterialsForOrder(order);
    cout << "Next order is: [" << order.getID() << "] For the Client: " << order.getClient().getName() << endl;
    order.printOrder();

    if (!status)
    {
        cout << "There are no enough materials! \n";

        cout << "The product needs:\n";


        cout << "\n================================================================\n";
        for (auto& i : order.getTotalRequiredMaterials())
        {
            cout << i.first.getName() << " : " << i.second << endl;
        }
        cout << "\n================================================================\n";

        cout << "Please go and buy the missing materials.";
        return;
    }
  
    int Line = ProductionFloor::findBestAvailableLine(0);
    ProductionFloor::assignOrder(Line, order);
    OrdersManager::tryDeleteFromList();
    cout << "\nThe order " << order.getID() << " was placed in the line[" << Line << "].";
    
}

void FactoryManager::processOrder()
{

    for (int i = 0; i < ProductionFloor::getNoOfLines(); i++)
    {
        if (ProductionFloor::isLineEmpty(i))
        {
            cout << "Line [" << i << "] is empty!, there are no orders to process.\n"; 
            continue;
        }
        ProductionFloor::processNextOrder(i);
    }
}


void FactoryManager::buyMaterial()
{
    cout << "======================================\n";
    Material::traverse([](Material m) { cout << m.getID() << ") " << m.getName() << ", each box has " << m.getQuantity() << " units" << endl; });
    cout << "======================================\n";
    cout << "\nChoose the material you want to buy by typing its number: ";
    int maximum = Material::getMaterialsNumber();
    int materialID = checkIfNumber(1, maximum);
    cout << "Enter the number of boxes you want from this material: ";
    int requiredNumber = checkIfNumber();
    Material m = Material::getMaterial(materialID);
    WarehouseManager::addMaterial(m, requiredNumber);
    cout << "You ordered number of boxes: " << requiredNumber << " of material '" << m.getName() << "'\nTotal quantity: " << requiredNumber * m.getQuantity();
}

void FactoryManager::prepareForShipping()
{
    if (!ProductionFloor::tryLoadForShipping())
    {
        cout << "Nothing to go for shipping";
        return;
    }
    cout << "Prepared for shipping successfully";
}

void FactoryManager::shipping()
{
    Order o;
    if (!OrdersManager::tryGetTopOrderReadyForShipping(o))
    {   
        cout << "No product for shipping!";
        return;
    }
    cout << "---------------------------------------\n";
    cout << "Order ID: " << o.getID() << endl;
    cout << "Applicant client: " << o.getClient().getName() << endl;
    cout << "The product: " << o.getProduct().getPrice() << endl;
    cout << "The required quantity: " << o.getRequiredQuantity() << endl;
    cout << "---------------------------------------\n";
    cout << "Do you want to ship right now or no (1 for yes, 2 for no): ";
    int choice = checkIfNumber(1, 2);
    if (choice == 2)
        return;
    OrdersManager::shipTopOrder();
    cout << "\n\nShipping done successfully!";
}

void FactoryManager::displayProductUnitsReadyForShipping()
{
    ProductionFloor::showActiveUnits();
}

void FactoryManager::startProduction()
{
    while (true)
    {
        cout << "\n================================================================\n";
        cout << "please choose one of the following actions by choosing its number: " << endl;
        cout << "1- Start making an order" << endl;
        cout << "2- Emergency" << endl;
        cout << "3- Buy materials" << endl;
        cout << "4- Display production floor statues" << endl;
        cout << "5- Process next order" << endl;
        cout << "6- Show how much materials in warehouse" << endl;
        cout << "7- Display products that are finished" << endl;
        cout << "8- Navigate the finished products to warehouse for shipping" << endl;
        cout << "9- Do the shipping" << endl;
        cout << "10- Return to main menu" << endl;
        cout << "\n================================================================\n";
        int UserChoice;
        UserChoice = checkIfNumber(1, 10);
                #ifdef _WIN32
            #define CLEAR_SCREEN "cls"
        #else
            #define CLEAR_SCREEN "clear"
        #endif
        switch (UserChoice)
        {
        case 1:
            registerOrder();
            pressAnyButtonToContinue();
            break;
        case 2:
			handleLineBreakdown();
            pressAnyButtonToContinue();
            break;
        case 3:
            buyMaterial();
            pressAnyButtonToContinue();
            break;
        case 4:
            ProductionFloor::displayStatus();
            pressAnyButtonToContinue();
            break;
        case 5:
            processOrder();
            pressAnyButtonToContinue();
            break;
        case 6:
            showMaterialsInWarehouse();
            pressAnyButtonToContinue();
            break;
        case 7:
            displayProductUnitsReadyForShipping();
            pressAnyButtonToContinue();
            break;
        case 8:
            prepareForShipping();
            pressAnyButtonToContinue();
            break;
        case 9:
            shipping();
            pressAnyButtonToContinue();
            break;
        case 10:
            return;
        default:
            break;
        }
    }
}

void FactoryManager::handleLineBreakdown()
{
	int Line = checkIfNumber(1, ProductionFloor::getNoOfLines() - 1);

    if (ProductionFloor::isLineEmpty(Line))
    {
        cout << "Line is empty and will be fixed ASAP!\n";
		return;
    }

	ProductionFloor::handleLineBreakdown(Line);
    cout << "Success! the products were moved to the other line(s) and will be handled there";
    pressAnyButtonToContinue();
}

void FactoryManager::showMaterialsInWarehouse()
{
    WarehouseManager::showMaterials();
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
    cout << "2- edit order's quantity" << endl;
    cout << "3- return" << endl;
    cout << "================================================================\n";
    int choice = checkIfNumber(1, 2);
    if (choice == 1)
    {
        order.setPriority(setPriority());
        cout << "the new price of your order: " << order.getTotalValue() << endl;
    }
    else if (choice == 2)
    {
        int newQuantity = checkIfNumber();
        order.setQuantity(newQuantity);
        cout << "the new price of your order: " << order.getTotalValue() << endl;
    }
    else
        return;
    OrdersManager::changeOrder(order);
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

void FactoryManager::seedInitialData()
{
    ProductionFloor::setNumberOfLines(3);
    WarehouseManager::addMaterial(Material::SCREW, 3);
    WarehouseManager::addMaterial(Material::METAL_FRAME, 7);
    WarehouseManager::addMaterial(Material::FABRIC, 2);
}

void FactoryManager::runSimulation()
{
    seedInitialData();
        #ifdef _WIN32
            #define CLEAR_SCREEN "cls"
        #else
            #define CLEAR_SCREEN "clear"
        #endif
    cout << "+-------+" << endl;
    cout << "|Welcome|" << endl;
    cout << "+-------+" << endl;
    
    while (true)
    {
        cout << "\n================================================================\n";
        cout << "please choose one of the following actions by choosing its number: " << endl;
        cout << "1- if you want to add an order" << endl;
        cout << "2- if you want to edit an existing order" << endl;
        cout << "3- if you want to to delete order" << endl;
        cout << "4- if want to see all order's history" << endl;
        cout << "5- Start production" << endl;
        cout << "6- Show All Events" << endl;
        cout << "7- if you want to stop the program" << endl;
        cout << "================================================================\n";
        int UserChoice;
        UserChoice = checkIfNumber(1, 7);

        #ifdef _WIN32
            #define CLEAR_SCREEN "cls"
        #else
            #define CLEAR_SCREEN "clear"
        #endif
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
            startProduction();
            break;
        case 6:
            Event::printAllEvents();
			pressAnyButtonToContinue();
            break;
        case 7:
            cout << "Thank you for using our services :-)\n";
            pressAnyButtonToContinue();
            return;
        default:
            break;
        }

    }
}
