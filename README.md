

---

# Singly Linked List Implementation

This repository contains a simple implementation of a singly linked list in C++. It includes methods to append, delete, and display nodes in the list. 

## Code Overview

### Node Structure

```cpp
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
```

- **Node**: Represents an individual node in the linked list, containing an integer value and a pointer to the next node.

### Global Head Pointer

```cpp
Node* head = nullptr; // Global head pointer
```

- **head**: A global pointer to the head of the linked list. Initially set to `nullptr`.

### Append Function

```cpp
void append(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}
```

- **append(int value)**: Adds a new node with the given value to the end of the list.

### Display Function

```cpp
void display() {
    Node* node = head;
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
```

- **display()**: Prints the values of all nodes in the list.

### Delete Function

```cpp
void deletearry(int value) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "Value " << value << " not found in the list." << std::endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}
```

- **deletearry(int value)**: Removes the node with the specified value from the list. If the node is not found, it prints a message.

### Example Usage

```cpp
int main() {
    append(1);
    append(2);
    append(3);

    display(); // Output: 1 2 3 

    deletearry(2); // Removes node with value 2

    display(); // Output: 1 3 

    deletearry(4); // Attempts to remove node with value 4 (not found)

    append(4);

    display(); // Output: 1 3 4 

    deletearry(1); // Removes node with value 1

    display(); // Output: 3 4 

    deletearry(4); // Removes node with value 4

    display(); // Output: 3 

    return 0;
}
```

- **main()**: Demonstrates appending, deleting, and displaying nodes in the singly linked list.


---
