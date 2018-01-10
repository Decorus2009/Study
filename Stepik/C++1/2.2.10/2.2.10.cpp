#include <iostream>

using namespace std;

void print_reversed() {
    
    int number = 0;
    cin >> number;
    
    if (number == 0) {
        return;
    }
    print_reversed();
    cout << number << ' ';
}

int main() {
    print_reversed();
    return 0;
}

