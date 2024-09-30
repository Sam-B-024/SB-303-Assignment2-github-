#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

// Define Stack class using vector
class Stack {
private:
    std::vector<int> stack; // Internal storage for the stack

public:
    // Check if the stack is empty
    bool is_empty() const {
        return stack.empty();
    }

    // Push an integer onto the stack
    void push(int value) {
        stack.push_back(value);
    }

    // Pop the top integer from the stack
    void pop() {
        if (!is_empty()) {
            stack.pop_back();
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Get the top element of the stack
    int top() const {
        if (!is_empty()) {
            return stack.back();
        } else {
            throw std::runtime_error("Stack is empty. No top element.");
        }
    }

    // Find the average of the elements in the stack
    double average() const {
        if (is_empty()) {
            throw std::runtime_error("Stack is empty. Cannot calculate average.");
        }

        int sum = std::accumulate(stack.begin(), stack.end(), 0);
        return static_cast<double>(sum) / stack.size();
    }

    // Print the stack (for debugging purposes)
    void print_stack() const {
        std::cout << "Stack: ";
        for (int value : stack) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

// Main function to test the stack
int main() {
    Stack my_stack;

    // Check if the stack is empty
    if (my_stack.is_empty()) {
        std::cout << "The stack is currently empty." << std::endl;
    }

    // Push some integers onto the stack
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);
    my_stack.push(40);

    // Print the current stack
    my_stack.print_stack();

    // Remove an element (pop the stack)
    std::cout << "Popping top element..." << std::endl;
    my_stack.pop();
    my_stack.print_stack();

    // Find the top element of the stack
    try {
        std::cout << "Top of the stack: " << my_stack.top() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Calculate the average of the stack elements
    try {
        std::cout << "Average value of the stack elements: " << my_stack.average() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}