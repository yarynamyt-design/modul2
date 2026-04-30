#include "task2.h"
map<string, int> loadWarehouse(const string& filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open JSON file");
    }

    json j;
    file >> j;

    map<string, int> warehouse;

    for (json::iterator it = j.begin(); it != j.end(); ++it) {
        string key = it.key();
        int value = it.value();
        warehouse[key] = value;
    }

    return warehouse;
}

void processOrders(std::map<string, int>& warehouse,
    queue<Order>& orders) {

    while (!orders.empty()) {
        Order o = orders.front();
        orders.pop();

        // перев≥рка чи ≥снуЇ товар
        map<std::string, int>::iterator it = warehouse.find(o.product);

        if (it == warehouse.end()) {
            throw out_of_range("Product not found: " + o.product);
        }

        if (it->second < o.quantity) {
            throw out_of_range("Not enough product: " + o.product);
        }

        it->second -= o.quantity;
    }
}

void saveToCSV(const std::map<string, int>& warehouse,
    const string& filename) {

    ofstream file(filename.c_str());
    if (!file.is_open()) {
        throw runtime_error("Cannot open CSV file");
    }

    // заголовок (€к таблиц€)
    file << "Product,Quantity\n";

    map<string, int>::const_iterator it;
    for (it = warehouse.begin(); it != warehouse.end(); ++it) {
        file << it->first << "," << it->second << "\n";
    }
}