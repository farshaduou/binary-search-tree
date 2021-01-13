// Binary Search Tree

#include <iostream>
#include <string>

template <typename T>
class Node {
 public:
  T key;
  Node* left;
  Node* right;

  Node(const T& key) : key{key}, left{nullptr}, right{nullptr} {}
};

template <typename T>
class Tree {
 private:
  Node<T>* root;
 
 public:
  Tree() { root = nullptr; }

 public:
  void add(const T& key) {
    if (root == nullptr)  // tree is empty
      root = new Node<T>{key};
    else
      addR(root, key);
  }

 private:
  void addR(Node<T>* node, const T& key) {
    if (key == node->key) return;  // equal to (set is unique)
    if (key < node->key)           // less than
      if (node->left == nullptr)   // no left child
        node->left = new Node<T>{key};
      else
        addR(node->left, key);
    else                             // greater than
        if (node->right == nullptr)  // no right child
      node->right = new Node<T>{key};
    else
      addR(node->right, key);
  }

 public:
  void print() { printR(root); }

 private:
  void printR(Node<T>* node) {
    if (node == nullptr) return;
    printR(node->left);
    std::cout << node->key << "\n";
    printR(node->right);
  }

 public:
  bool contain(const T& key) { return containR(root, key); }

 private:
  bool containR(Node<T>* node, const T& key) {
    if (node == nullptr) return false;                      // doesn't exist
    if (key == node->key) return true;                      // equal to (exist)
    if (key < node->key) return containR(node->left, key);  // less than
    return containR(node->right, key);                      // greater than
  }
};

void test01();
void test02();
void test03();

int main() {
  test01();
  test02();
  test03();

  return 0;
}

void test01() {
  std::cout << "--- Test 1 ---\n";
  Tree<int> t;

  t.add(3);
  t.add(2);
  t.add(5);
  t.add(3);
  t.add(1);
  t.add(4);

  t.print();
}

void test02() {
  std::cout << "--- Test 2 ---\n";
  Tree<int> t;

  t.add(3);
  t.add(2);
  t.add(5);
  t.add(3);
  t.add(1);
  t.add(4);

  std::cout << "4 is in tree: " << t.contain(4) << "\n";
  std::cout << "5 is in tree: " << t.contain(5) << "\n";
  std::cout << "6 is in tree: " << t.contain(6) << "\n";
}

void test03() {
  std::cout << "--- Test 3 ---\n";
  Tree<std::string> t;

  t.add("mohammad");
  t.add("ahmad");
  t.add("yasin");
  t.add("ali");
  t.add("farshad");
  t.add("ehsan");

  t.print();

  std::cout << "ali is in tree: " << t.contain("ali") << "\n";
  std::cout << "yasin is in tree: " << t.contain("yasin") << "\n";
  std::cout << "alo is in tree: " << t.contain("alo") << "\n";
}
