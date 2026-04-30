#include "task1.h"
int main() {
    list<int> lst;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    if (!cin || n < 0) {
        cout << "Invalid input\n";
        return 1;
    }

    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> x;

        if (!cin) {
            cout << "Invalid input\n";
            return 1;
        }

        lst.push_back(x);
    }

    try {
        removeEvenOrThrow(lst);

        cout << "Result list: ";
        for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    }
    catch (const domain_error& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}