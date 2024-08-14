# LLIQR (Linked List Interquartile Range)
LLIQR is the C++ implementation of Interquartile Range (IQR) determination using a linked list. The IQR is a statistical range that measures the statistical dispersion, being equal to the difference between 75th and 25th percentiles, or between upper and lower quartiles. IQR is a measure of variability, based on dividing a data set into quartiles.

<img width="455" alt="image" src="https://github.com/user-attachments/assets/9aa8e418-d117-4611-94d3-1f80fd022240">

## Getting Started
Clone this repository to start working with LLIQR.

    git clone https://github.com/[username]/LLIQR.git

## Dependencies
Make sure you have C++ compiler installed which is fully compliant with C++ standards. The software should be able to compile and run on any system with a modern C++ compiler.
## Building
You can build the LLIQR code with cmake. The build steps are as follows:

        mkdir build
        cd build
        cmake ..
        make 
## Code Structure
The main function locates in the root directory of the project in the main.cpp file.
Here is a sample usage of LLIQR:

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
