#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node*);
Node *addFrontNode(Node*, int);
Node *addTailNode(Node*, int);
Node *deleteNode(Node*, int);
Node *insertNode(Node*, int);
Node *deleteEntireList(Node*);

int main() {
    Node *head = nullptr;
    int count = 0;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addFrontNode(head, tmp_val);
    }
    output(head);

    // adding a node to the tail
    int tailVal = 99;
    head = addTailNode(head, tailVal);
    cout << "New list after adding a node to the tail:" << endl;
    output(head);
    
    // deleting a node
    Node *current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    head = deleteNode(head, entry);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    head = insertNode(head, entry);
    output(head);

    // deleting the linked list
    head = deleteEntireList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node *addFrontNode(Node *head, int tmp_val) {
    Node *newVal = new Node;
        
    // adds node at head
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = tmp_val;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = head;
        newVal->value = tmp_val;
        head = newVal;
    }
    return head;
}

Node *addTailNode(Node *head, int tailVal) {
    Node *newVal = new Node;
    newVal->value = tailVal;
    newVal->next = nullptr;
    
    return head;
}

Node *deleteNode(Node *head, int entry) {
     // traverse that many times and delete that node
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

    return head;
}

Node *insertNode(Node* head, int entry) {
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;

    return head;
}

Node *deleteEntireList(Node* head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;

    return head;
}
