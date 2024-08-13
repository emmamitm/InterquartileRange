#include <iostream>
#include "Node.h"
using namespace std;
int main() {
    // Example input data: 2 4 4 5 6 7 8
    int values[] = {2, 4, 4, 5, 6, 7, 8, 9, 10};
    Node* head = nullptr;
    // Create the linked list from the input values
    for (int value : values) {
        head = insertEnd(head, value);
    }
    // Call the interQuartile function and print the result
    float iqr = interQuartile(head);
    std::cout << "Interquartile Range: " << std::fixed << std::setprecision(2) << iqr << std::endl;

    // Free memory by deleting the linked list nodes
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
