#include "task2.h"

int main() {
    try {
        map<string, int> warehouse = loadWarehouse("task2.json");

        queue<Order> orders;

        Order o1;
        o1.product = "apple";
        o1.quantity = 3;

        Order o2;
        o2.product = "milk";
        o2.quantity = 2;

        orders.push(o1);
        orders.push(o2);

        processOrders(warehouse, orders);

        saveToCSV(warehouse, "result.csv");

        cout << "Done. Check result.csv\n";
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}