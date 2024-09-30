//NAME: Sam R Burns
//DATE:9/12/2024
//ASSIGNMENT: 303 asignment2- Single-linked-list-class
//SOURCES: CHATGPT for base coding understanding/start,303 class Syed Jawad Hussain Shah, PhD Candidate for base understanding of linkedlists, stacks, & classes. 

#include <iostream>
#include <vector>
#include <numeric>

class Stack {
private:
    std::vector<int> data;  // Vector store stack elements

public:
    // Check if stack is empty
    bool is_empty() const {
        return data.empty();  // Return true if no elements are in stack
    }

    // Push an integer onto stack
    void push(int value) {
        data.push_back(value);  // Add an element to end of vector (top)
    }

    // Pop top integer from stack
    void pop() {
        if (!is_empty()) {
            data.pop_back();  // Remove last element (top of stack)
        } else {
            std::cout << "Stack is empty. Cannot pop a value.\n";
        }
    }

    // Get top element of the stack
    int top() const {
        if (!is_empty()) {
            return data.back();  // Return last element (top of stack)
        } else {
            throw std::runtime_error("Stack is empty. No top element.");  // Throwif the stack is empty
        }
    }

    // Get average value of stack elements
    double average() const {
        if (!is_empty()) {
            int sum = std::accumulate(data.begin(), data.end(), 0);  // Calculate sum of elements
            return static_cast<double>(sum) / data.size();  // Return average as  double
        } else {
            throw std::runtime_error("Stack IS empty. Cannot calculate average.");  // Throw ex if stack is empty
        }
    }

    // Print elements of stack
    void print_stack() const {
        std::cout << "Stack elements (from bottom to top): ";
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << data[i] << " ";  // Print each element in stack
        }
        std::cout << "\n";
    }
};

int main() {
    Stack my_stack;  //Create a stack object

    //Check if the stack is empty
    if (my_stack.is_empty()) {
        std::cout << "The stack is empty.\n";
    } else {
        std::cout << "The stack is NOT empty.\n";
    }

    //Insert some integer values onto stack
    int num_values;
    std::cout << "Enter number of values to push onto the stack: ";
    std::cin >> num_values;

    // Loop to input & push values onto stack
    for (int i = 0; i < num_values; ++i) {
        int value;
        std::cout << "Enter number/value " << (i + 1) << ": ";
        std::cin >> value;
        my_stack.push(value);  // Push each value onto stack
    }

    // Print stack after pushing values
    my_stack.print_stack();

    // Remove element from the stack
    std::cout << "Popping the top element from the stack...\n";
    my_stack.pop();  // Remove top element

    // Print after popping
    my_stack.print_stack();

    //Find the top of stack
    try {
        int top_value = my_stack.top();  // Get top element
        std::cout << "The top element of the stack is: " << top_value << "\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";  // Catch & display any errors
    }

    //Find average value of stack elements
    try {
        double avg = my_stack.average();  // Calculate average of stack
        std::cout << "The average value of the stack elements is: " << avg << "\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";  // Catch display any errors
    }

    return 0;
}
