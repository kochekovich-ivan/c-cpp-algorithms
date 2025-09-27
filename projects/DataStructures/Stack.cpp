#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* head = nullptr;
    int counter{ 0 };

public:
    void push(int value) {
        Node* n = new Node(value);
        n->next = head; 
        head = n;
        counter++;
    }

    int pop() {
        if (counter == 0) {
            cerr << "Stack is empty!" << endl;
            return -1; 
        }
        Node* temp = head;
        int res = temp->data;
        head = head->next;
        delete temp;
        counter--;
        return res;
    }
    int size() {
        return counter;
    }
    bool isEmpty() {
        if(counter == 0)
            return true;
        else
            return false;
    }
    int peek() {        
        if (counter == 0) {
            cerr << "Stack is empty!" << endl;
            return -1; 
        }
        return head->data;
    }
    ~Stack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    cout << myStack.size() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.isEmpty() << endl; 
    cout << myStack.size() << endl;
    cout << myStack.peek() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.size() << endl;
    cout << myStack.isEmpty() << endl;
    cout << myStack.pop() << endl;
    return 0;
}
