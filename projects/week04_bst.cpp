#include <iostream>
#include <optional>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

ostream& operator<<(ostream& os, const optional<int>& opt) {
    if (opt) os << *opt;
    else os << "Tree is empty";
    return os;
}

class BST {
private:
  Node* root = nullptr;
  int counter = 0;

  void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }

  void destroy(Node* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
  }

  bool find(Node* node, int x) {
    if (node == nullptr) return false;
    if (node->data == x) return true;
    if (x < node->data) return find(node->left, x);
    else return find(node->right, x);
  }

  Node* removeNode(Node* node, int x) {
    if (node == nullptr) return nullptr;
    if (x < node->data) node->left = removeNode(node->left, x);
    else if (x > node->data) node->right = removeNode(node->right, x);
    else {
      counter--;
      if (!node->left) {
        Node* temp = node->right;
        delete node;
        return temp;
      }
      else if (!node->right) {
        Node* temp = node->left;
        delete node;
        return temp;
      }
      else {
        Node* temp = node->right;
        while (temp->left) temp = temp->left;
        node->data = temp->data;
        node->right = removeNode(node->right, temp->data);
      }
    }
    return node;
  }

public:
  void push(int x) {
    if (root == nullptr) {
      root = new Node(x);
      counter++;
      return;
    }

    Node* tail = root;
    while (true) {
      if (x < tail->data) {
        if (tail->left == nullptr) {
          tail->left = new Node(x);
          counter++;
          return;
        }
        tail = tail->left;
      }
      else if (x > tail->data) {
        if (tail->right == nullptr) {
          tail->right = new Node(x);
          counter++;
          return;
        }
        tail = tail->right;
      }
      else {
        return;
      }
    }
  }

  int size() {
    return counter;
  }

  void show_tree() {
    inorder(root);
    cout << endl;
  }

  bool find(int x) {
    return find(root, x);
  }

  bool isEmpty() {
    return counter == 0;
  }

  void remove(int x) {
    if (find(x))
      root = removeNode(root, x);
    else
      cout << "there is no " << x << " in the tree" << endl;
  }

  std::optional<int> min() {
    if (isEmpty()) return std::nullopt;
    Node* ptr = root;
    while (ptr->left != nullptr) ptr = ptr->left;
    return ptr->data;
  }

  ~BST() {
    destroy(root);
  }
};

int main() {
  BST tree;
  cout << tree.isEmpty() << endl;
  tree.push(5);
  tree.push(3);
  tree.push(7);
  tree.push(2);
  tree.push(4);
  tree.push(6);
  tree.push(8);

  cout << "Tree in-order: ";
  tree.show_tree();

  cout << tree.isEmpty() << endl;

  cout << "Size: " << tree.size() << endl;
  cout << "Find: " << tree.find(8) << endl;
  tree.remove(8);

  cout << "Tree in-order: ";
  tree.show_tree();

  cout << "Size: " << tree.size() << endl;
  cout << "Find: " << tree.find(8) << endl;
  
  
  cout << "Min: " << tree.min() << "; Max: " << tree.max() << endl;
  
  
  
  return 0;
}
