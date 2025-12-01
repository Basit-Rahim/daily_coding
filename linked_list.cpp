#include<iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Function to reverse the linked list iteratively
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        // Store the next node
        next = current->next;
        // Reverse the link
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    
    // prev is now the new head
    return prev;
}

// Function to create a linked list from an array
Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Function to delete the linked list to free memory
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    Node* head = createList(arr, size);
    
    cout << "Original linked list: ";
    printList(head);
    
    // Reverse the linked list
    head = reverseList(head);
    
    cout << "Reversed linked list: ";
    printList(head);
    
    // Clean up memory
    deleteList(head);
    
    return 0;
}