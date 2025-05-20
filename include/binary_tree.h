// binary_tree.h
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>

// Forward declarations for test functions
void testEmptyTree();
void testSingleElement();
void testMultipleElements();
void testDuplicateElements();
void testCopyConstructor();
void testAssignmentOperator();
void testIteratorOperations();
void testStringTree();
void runAllTests();

// Структура для вузла дерева
template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

// Простий стек для зберігання вузлів
template<typename T>
class Stack {
private:
    struct StackNode {
        T data;
        StackNode* next;
        StackNode(const T& value) : data(value), next(nullptr) {}
    };
    
    StackNode* top;
    
public:
    Stack() : top(nullptr) {}
    
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
    
    void push(const T& value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (top) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    T& peek() {
        return top->data;
    }
    
    bool empty() const {
        return top == nullptr;
    }
};

// Клас бінарного дерева
template<typename T>
class BinaryTree {
private:
    TreeNode<T>* root;
    
    // Рекурсивна функція для знищення дерева
    void destroyTree(TreeNode<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    
    // Рекурсивна функція для копіювання дерева
    TreeNode<T>* copyTree(TreeNode<T>* node) {
        if (!node) return nullptr;
        
        TreeNode<T>* newNode = new TreeNode<T>(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }
    
    // Рекурсивна функція для додавання елемента
    TreeNode<T>* insertRecursive(TreeNode<T>* node, const T& value) {
        if (!node) {
            return new TreeNode<T>(value);
        }
        
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        
        return node;
    }
    
public:
    // Конструктор
    BinaryTree() : root(nullptr) {}
    
    // Деструктор
    ~BinaryTree() {
        destroyTree(root);
    }
    
    // Конструктор копіювання
    BinaryTree(const BinaryTree& other) : root(nullptr) {
        if (other.root) {
            root = copyTree(other.root);
        }
    }
    
    // Оператор присвоєння
    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            destroyTree(root);
            root = nullptr;
            if (other.root) {
                root = copyTree(other.root);
            }
        }
        return *this;
    }
    
    // Додавання елемента
    void insert(const T& value) {
        root = insertRecursive(root, value);
    }
    
    // Перевірка на порожність
    bool empty() const {
        return root == nullptr;
    }
    
    // Клас ітератора для інфіксного обходу (in-order)
    class Iterator {
    private:
        Stack<TreeNode<T>*> nodeStack;
        TreeNode<T>* current;
        
        // Функція для переходу до найлівішого вузла
        void pushLeftNodes(TreeNode<T>* node) {
            while (node) {
                nodeStack.push(node);
                node = node->left;
            }
        }
        
    public:
        // Конструктор ітератора
        Iterator(TreeNode<T>* root) : current(nullptr) {
            pushLeftNodes(root);
            if (!nodeStack.empty()) {
                current = nodeStack.peek();
                nodeStack.pop();
            }
        }
        
        // Конструктор кінця ітератора
        Iterator() : current(nullptr) {}
        
        // Оператор разименування
        T& operator*() {
            return current->data;
        }
        
        // Оператор доступу до члена
        T* operator->() {
            return &(current->data);
        }
        
        // Оператор префіксного інкременту
        Iterator& operator++() {
            if (current) {
                pushLeftNodes(current->right);
                if (!nodeStack.empty()) {
                    current = nodeStack.peek();
                    nodeStack.pop();
                } else {
                    current = nullptr;
                }
            }
            return *this;
        }
        
        // Оператор постфіксного інкременту
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        
        // Оператор порівняння
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
        
        // Оператор нерівності
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    
    // Початок ітератора
    Iterator begin() {
        return Iterator(root);
    }
    
    // Кінець ітератора
    Iterator end() {
        return Iterator();
    }
};

// Forward declaration of runAllExamples function
void runAllExamples();

#endif // BINARY_TREE_H