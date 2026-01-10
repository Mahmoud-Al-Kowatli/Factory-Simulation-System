#include<ProductionFloor.h>

ProductionFloor::ProductionFloor(int numLines){
    if (numLines < 2) numLines = 2; 
    lines.resize(numLines);
    emergencyLineIndex = numLines - 1;
}

void ProductionFloor::assignOrder(int linID ,Order o ){
        if ( linID >= 0 && linID <lines.size()){
            lines[linID].push(o);
            cout<<"Order " <<o.getID()<<"assigned to line "<<linID<<endl;
        }
        else{
            cout<<"Error Line ID out of bounds \n";
        }
}

void ProductionFloor::processNextOrder(int lineID) {
    if (lineID >= 0 && lineID < lines.size() && !lines[lineID].empty()) {
        Order topOrder = lines[lineID].top();
        lines[lineID].pop();

        ProductUnit unit(topOrder.getID(), topOrder.getID());
        unit.addEvent("Production started.");
        
        activeUnits[topOrder.getID()] = unit;
        
        cout << "Processing Unit: " << topOrder.getID() << " on line " << lineID << endl;
    }
}

void ProductionFloor::handleLineBreakdown(int brokenLineID) {
    if (brokenLineID < 0 || brokenLineID >= lines.size()) return;

    cout << "CRITICAL: Line " << brokenLineID << " failure detected!" << endl;

    // 1. Extract pending orders from the broken line
    vector<Order> affectedOrders;
    while (!lines[brokenLineID].empty()) {
        affectedOrders.push_back(lines[brokenLineID].top());
        lines[brokenLineID].pop();
    }

    // 2. Redistribute orders
    for (Order& o : affectedOrders) {
        int target = findBestAvailableLine(brokenLineID);
        
        // If all normal lines are overloaded, use the Emergency Line
        if (target == -1 || lines[target].size() > 10) { 
            target = emergencyLineIndex;
            cout << "Normal lines overloaded. Using Emergency Line for Order " << o.getID() << endl;
        }
        lines[target].push(o);
    }
    // Inside handleLineBreakdown
    for (auto& pair : activeUnits) {
        // If we can track which line the unit was on
        pair.second.addEvent("Warning: Line " + to_string(brokenLineID) + " down. Checking unit integrity.");
    }
}

int ProductionFloor::findBestAvailableLine(int excludedLine) {
    int bestLine = -1;
    size_t minOrders = 999999;

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
    cout << "\n================= FACTORY PRODUCTION FLOOR STATUS =================" << endl;
    
    // 1. Display status of each production line
    for (int i = 0; i < lines.size(); i++) {
        string lineType = (i == emergencyLineIndex) ? " [EMERGENCY LINE]" : " [NORMAL LINE]";
        cout << "Line " << i << lineType << " - Pending Orders: " << lines[i].size() << endl;
    }

    // 2. Display units currently being processed (from the Map)
    cout << "\n--- Active Units in Production (O(1) Tracking) ---" << endl;
    if (activeUnits.empty()) {
        cout << "No units currently active." << endl;
    } else {
        for (auto const& [id, unit] : activeUnits) {
            cout << "Unit ID: " << id << " | Status: Processing..." << endl;
        }
    }
    cout << "==================================================================\n" << endl;
}