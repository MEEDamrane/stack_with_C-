#include <iostream>

using namespace std;

// Define the Node structure
typedef struct Node {
    int data;
    Node* next;
} Node;

// Define the Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to check if the stack is empty
bool isempty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an item onto the stack
void push(Stack* stack, int item) {
    Node* newNode = new Node();
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to display the elements of the stack
void display(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to pop an item from the stack
int pop(Stack* stack) {
    if (isempty(stack)) {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1; // Assuming -1 is used as an error code
    }
    int item = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    delete temp;
    return item;
}

// Function to peek at the top of the stack
int peek(Stack* stack) {
    if (isempty(stack)) {
        cout << "Stack is empty. Cannot peek." << endl;
        return -1; // Assuming -1 is used as an error code
    }
    return stack->top->data;
}

// Function to check if a specific item is found in the stack
bool isfound(Stack* stack, int item) {
    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == item) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Stack myStack;
    myStack.top = NULL;

    int choice, item;

    do {
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if item is found" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to push: ";
                cin >> item;
                push(&myStack, item);
                break;
            case 2:
                item = pop(&myStack);
                if (item != -1) {
                    cout << "Popped item: " << item << endl;
                }
                break;
            case 3:
                item = peek(&myStack);
                if (item != -1) {
                    cout << "Top of the stack: " << item << endl;
                }
                break;
            case 4:
                cout << "Stack elements: ";
                display(&myStack);
                break;
            case 5:
                cout << "Enter the item to check: ";
                cin >> item;
                cout << (isfound(&myStack, item) ? "Item found" : "Item not found") << endl;
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
