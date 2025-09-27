#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned int counter{0};

public:
    void push_back(int value) {
        Node* n = new Node(value);
        if (!head) {                // пустой список
            head = tail = n;
        } else {                    // добавляем в конец
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        counter++;
    }

    void del_back() {
        if (!tail) {
            cout << "Not enough elements!" << endl;
            return;
        }
        if (head == tail) {         // один элемент
            delete head;
            head = tail = nullptr;
        } else {
            Node* to_delete = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete to_delete;
        }
        counter--;
    }

    void print_all_el() {
        if (!head) {
            cout << "There is no elements!" << endl;
            return;
        }
        for (Node* i = head; i; i = i->next) {
            cout << i->data << " ";
        }
        cout << endl;
    }

    unsigned int size() {
        return counter;
    }

    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
};

int main() {
    LinkedList my_list;
    my_list.push_back(10);
    my_list.print_all_el();
    cout << my_list.size() << endl;

    my_list.del_back();
    my_list.push_back(22);
    my_list.print_all_el();
    cout << my_list.size() << endl;

    my_list.push_back(10);
    my_list.print_all_el();
    cout << my_list.size() << endl;

    my_list.del_back();
    my_list.print_all_el();
    cout << my_list.size() << endl;

    return 0;
}
