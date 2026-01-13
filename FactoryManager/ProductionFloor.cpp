#include"ProductionFloor.h"

vector<priority_queue<Order>> ProductionFloor::lines = {};

unordered_map<int, ProductUnit> ProductionFloor::activeUnits = {};

int ProductionFloor::emergencyLineIndex = 0;

void ProductionFloor::setNumberOfLines(int linesNum)
{
    if (linesNum < 2) linesNum = 2;
    lines.resize(linesNum);
    emergencyLineIndex = linesNum - 1;
}

void ProductionFloor::assignOrder(int linID ,Order o){
    if (linID >= 0 && linID < lines.size()){
        lines[linID].push(o);
        cout<<"Order " << o.getID() << "assigned to line "<< linID <<endl;
    }
    else{
        cout << "Error Line ID out of bounds\n";
    }
}

void ProductionFloor::processNextOrder(int lineID) {
    if (lineID >= 0 && lineID < lines.size() && !lines[lineID].empty()) {
        Order topOrder = lines[lineID].top();
        lines[lineID].pop();

        Event event("Production started.");
        vector<ProductUnit> vUnits;

        int rq = topOrder.getRequiredQuantity();
        for (int i = 0; i < rq; i++)
        {
            ProductUnit unit(topOrder.getID(), topOrder.getProductID());
            unit.addEvent(event.getID());
            activeUnits[unit.getID()] = unit;
        }
        
        cout << "Processing Unit: " << topOrder.getID() << " on line " << lineID << endl;
    }
}

void ProductionFloor::handleLineBreakdown(int brokenLineID) {
    if (brokenLineID < 0 || brokenLineID >= lines.size()) return;

    cout << "CRITICAL: Line " << brokenLineID << " failure detected!" << endl;
    vector<Order> affectedOrders;
    while (!lines[brokenLineID].empty()) {
        affectedOrders.push_back(lines[brokenLineID].top());
        lines[brokenLineID].pop();
    }

    for (Order& o : affectedOrders) {
        int target = findBestAvailableLine(brokenLineID);
        
        if (target == -1 || lines[target].size() > 10) { 
            target = emergencyLineIndex;
            cout << "Normal lines overloaded. Using Emergency Line for Order " << o.getID() << endl;
        }
        lines[target].push(o);
    }
    for (auto& pair : activeUnits) {
        Event event("Warning: Line " + to_string(brokenLineID) + " down. Checking unit integrity.");
        pair.second.addEvent(event.getID());
    }
}

int ProductionFloor::findBestAvailableLine(int excludedLine) {
    int bestLine = -1;
    int minOrders = INT_MAX;

    for (int i = 0; i < lines.size(); i++) {
        if (i != excludedLine && i != emergencyLineIndex) {
            if (lines[i].size() < minOrders) {
                minOrders = lines[i].size();
                bestLine = i;
            }
        }
    }
    return bestLine;
}

void ProductionFloor::displayStatus() {
    cout << "\n================= Factory Production Floor Status =================" << endl;
    
    for (int i = 0; i < lines.size(); i++) {
        string lineType = (i == emergencyLineIndex) ? " [Emergency Line]" : " [Normal Line]";
        cout << "Line " << i << lineType << " - Pending Orders: " << lines[i].size() << endl;
    }

    cout << "\n--- Active Units in Production ---" << endl;
    if (activeUnits.empty()) {
        cout << "No units currently active." << endl;
    } else {
        for (auto const& unit : activeUnits) {
            cout << "Unit ID: " << unit.first << " | Status: Processing..." << endl;
        }
    }
    cout << "==================================================================\n" << endl;
}