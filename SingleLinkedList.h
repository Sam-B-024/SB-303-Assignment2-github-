#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

// template class for a single linked list
template <typename Item_Type>
class Single_Linked_List {
private:
    // internal Node structure for linked list
    struct Node {
        Item_Type data;  // Data held by node
        Node* next;      // Pointer to next node

        // Constructor for Node takes data and a next pointer
        Node(const Item_Type& item, Node* next = nullptr) : data(item), next(next) {}
    };

    Node* head;    // Pointer to first node in list
    Node* tail;    // Pointer to last node in list
    size_t num_items; 

public:
    // Constructor: initialize an empty list
    Single_Linked_List();

    // Destructor: clears the list
    ~Single_Linked_List();

    // Add item to front of the list
    void push_front(const Item_Type& item);

    // Add item to back of the list
    void push_back(const Item_Type& item);

    // Remove item from front of the list
    void pop_front();

    // Remove item from back of the list
    void pop_back();

    // Return first item in list
    Item_Type front() const;

    // Return last item in list
    Item_Type back() const;

    // Check if the list is empty
    bool empty() const;

    // Insert item at a specific index
    void insert(size_t index, const Item_Type& item);

    // Remove item at specific index
    bool remove(size_t index);

    
    size_t find(const Item_Type& item) const;

    // Return number of items in the list
    size_t size() const;
};

// Constructor: initializes head tail item count
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor: clears list removing all elements
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

// Add item to front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item, head);  // Create new node 
    head = new_node;  // Set new node as head
    if (!tail) {      // If list was empty set tail new node
        tail = head;
    }
    num_items++;      // Increment
}

// Add item to the back of list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);  // Create new node with item
    if (tail) {  // If the list is not empty link new node after the tail
        tail->next = new_node;
    } else {     // If the list is empty, new node is both head & tail
        head = new_node;
    }
    tail = new_node;  // Set the new node AS tail
    num_items++;      // Increment
}

// Remove an item from front of list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    Node* old_head = head;  // Store head node
    head = head->next;      // Move the head to the next node
    if (!head) {            // If list is now empty set tail to nullptr
        tail = nullptr;
    }
    delete old_head;        // Delete old head node
    num_items--;            // Decrease count of items
}

// Remove item from the back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    if (head == tail) {  // If there only one item in the list
        delete head;     // Remove it and set both head and tail to nullptr
        head = tail = nullptr;
    } else {
        Node* current = head;
        // Look through list to find node before the tail
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;      // Delete tail node
        tail = current;   // Set new tail
        tail->next = nullptr;
    }
    num_items--;          // Decrease count of items
}

// Return first item in the list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    return head->data;  // Return data of the head node
}

// Return last item in the list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    return tail->data;  // Return data of the tail node
}

// Check if list is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr;  // list is empty if head is nullptr
}

// Insert item at specific index
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);  // Insert at the front
    } else if (index >= num_items) {
        push_back(item);   // Insert at the back if index is out of bounds
    } else {
        Node* current = head;
        // looks through the list to find the node before the insert position
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* new_node = new Node(item, current->next);  // Create new node
        current->next = new_node;  // Link new node into the list
        num_items++;  // Increase item count
    }
}

// Remove item at a specific index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;  // If index is out of bounds, return false
    }
    if (index == 0) {
        pop_front();   // Remove front element
    } else {
        Node* current = head;
        // looks list to find the node before the remove position
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* node_to_delete = current->next;  // Store node to be removed
        current->next = node_to_delete->next;  // Link around the node to delete
        if (node_to_delete == tail) {  // Update the tail if needed
            tail = current;
        }
        delete node_to_delete;  // Delete node
        num_items--;  // Decrease item count
    }
    return true;
}

// Find index of a specific item return size if not found
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    // look thru list to search for the item
    while (current != nullptr) {
        if (current->data == item) {
            return index;  // Return index if the item is found
        }
        current = current->next;
        index++;
    }
    return num_items;  // If not found return the size of the list
}

// Return number of items in the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;  // Return item count
}

#endif

