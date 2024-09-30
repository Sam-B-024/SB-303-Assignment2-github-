//Name: Sam R Burns
//Date:9/12/2024
//303 asignment2- Single-linked-list-class

/*

#include "SingleLinkedList.h"
#include <stdexcept>
#include <iostream>

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item, head);
    head = new_node;
    if (!tail) {
        tail = head;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (tail) {
        tail->next = new_node;
    } else {
        head = new_node;
    }
    tail = new_node;
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    Node* old_head = head;
    head = head->next;
    if (!head) {
        tail = nullptr;
    }
    delete old_head;
    num_items--;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    return head->data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    return tail->data;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
    } else if (index >= num_items) {
        push_back(item);
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* new_node = new Node(item, current->next);
        current->next = new_node;
        num_items++;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* node_to_delete = current->next;
        current->next = node_to_delete->next;
        if (node_to_delete == tail) {
            tail = current;
        }
        delete node_to_delete;
        num_items--;
    }
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;  // Not found, return size
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}
*/



/*

#include "SingleLinkedList.h"
#include <iostream>

int main() {
    Single_Linked_List<int> my_list;
    my_list.push_back(10);
    my_list.push_front(5);
    my_list.insert(1, 8);

    std::cout << "Front: " << my_list.front() << std::endl;  // Output: 5
    std::cout << "Back: " << my_list.back() << std::endl;    // Output: 10
    std::cout << "Size: " << my_list.size() << std::endl;    // Output: 3

    my_list.pop_front();
    std::cout << "Front after pop: " << my_list.front() << std::endl;  // Output: 8

    return 0;
}

*/