#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* tail{nullptr};
    Node* head{nullptr};
    int counter{0};
public:
    void enqueue(int value){
        if(counter == 0)
        {
            Node* n = new Node(value);
            head = n;
            tail = n;
            counter++;
        }
        else {
            Node* n = new Node(value);
            tail->next = n;
            tail = tail->next;
            counter++;
        }
    }    
    
    int dequeue() {
        if (counter == 0) {
            return -1;
        }
        Node* remove = head;
        head = head->next;
        int res = remove->data;
        delete remove;
        counter--;
        if (counter == 0) {
            tail = nullptr;
        }
        return res;
    }


    int front() {
        if(counter != 0)
            return head->data;
        else
            return -1; 
    }

    int size() {
        return counter;
    }

    bool isEmpty() {
        if(counter != 0)
            return false;
        else
            return true;
    }
    ~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main() {
    Queue myQueue;
    cout << myQueue.isEmpty() << endl;
    myQueue.enqueue(10);
    cout << myQueue.size() << endl;
    cout << myQueue.front() << endl;
    cout << myQueue.isEmpty() << endl;
    myQueue.enqueue(20);
    cout << myQueue.size() << endl;
    cout << myQueue.front() << endl;
    cout << myQueue.isEmpty() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.size() << endl;
    cout << myQueue.front() << endl;
    cout << myQueue.isEmpty() << endl;
    return 0;
}
