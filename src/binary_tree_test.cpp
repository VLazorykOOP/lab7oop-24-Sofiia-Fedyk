// binary_tree_test.cpp
#include "binary_tree.h"

// Test functions, extracted from binary_tree.h

// Function to test an empty tree
void testEmptyTree() {
    std::cout << "=== Empty Tree Test ===" << std::endl;
    BinaryTree<int> tree;
    
    // Check if empty
    std::cout << "Tree is empty: " << (tree.empty() ? "yes" : "no") << std::endl;
    
    // Attempt to iterate through an empty tree
    std::cout << "Iterating through empty tree: ";
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "completed" << std::endl << std::endl;
}

// Function to test a tree with a single element
void testSingleElement() {
    std::cout << "=== Single Element Tree Test ===" << std::endl;
    BinaryTree<int> tree;
    tree.insert(42);
    
    std::cout << "Tree is empty: " << (tree.empty() ? "yes" : "no") << std::endl;
    std::cout << "Tree elements: ";
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

// Function to test a tree with multiple elements
void testMultipleElements() {
    std::cout << "=== Multiple Elements Tree Test ===" << std::endl;
    BinaryTree<int> tree;
    
    // Add elements in different order
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 65};
    int size = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < size; i++) {
        tree.insert(values[i]);
    }
    
    std::cout << "Added elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "In-order traversal: ";
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

// Function to test duplicates
void testDuplicateElements() {
    std::cout << "=== Duplicates Test ===" << std::endl;
    BinaryTree<int> tree;
    
    tree.insert(25);
    tree.insert(15);
    tree.insert(25); // duplicate
    tree.insert(35);
    tree.insert(15); // duplicate
    tree.insert(30);
    
    std::cout << "Elements after adding duplicates: ";
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

// Function to test the copy constructor
void testCopyConstructor() {
    std::cout << "=== Copy Constructor Test ===" << std::endl;
    BinaryTree<int> originalTree;
    originalTree.insert(100);
    originalTree.insert(50);
    originalTree.insert(150);
    originalTree.insert(25);
    originalTree.insert(75);
    
    std::cout << "Original tree: ";
    for (auto it = originalTree.begin(); it != originalTree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Create a copy
    BinaryTree<int> copiedTree = originalTree;
    
    std::cout << "Copied tree: ";
    for (auto it = copiedTree.begin(); it != copiedTree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

// Function to test the assignment operator
void testAssignmentOperator() {
    std::cout << "=== Assignment Operator Test ===" << std::endl;
    BinaryTree<int> tree1;
    BinaryTree<int> tree2;
    
    tree1.insert(200);
    tree1.insert(100);
    tree1.insert(300);
    
    tree2.insert(500);
    tree2.insert(400);
    
    std::cout << "Tree 1: ";
    for (auto it = tree1.begin(); it != tree1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Tree 2 before assignment: ";
    for (auto it = tree2.begin(); it != tree2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Assign
    tree2 = tree1;
    
    std::cout << "Tree 2 after assignment: ";
    for (auto it = tree2.begin(); it != tree2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

// Function to test iterator operations
void testIteratorOperations() {
    std::cout << "=== Iterator Operations Test ===" << std::endl;
    BinaryTree<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    
    // Test different iterator operations
    auto it = tree.begin();
    std::cout << "First element: " << *it << std::endl;
    
    ++it;
    std::cout << "Second element: " << *it << std::endl;
    
    it++;
    std::cout << "Third element: " << *it << std::endl;
    
    // Test iterator comparisons
    auto it2 = tree.begin();
    std::cout << "it == tree.begin(): " << (it == tree.begin() ? "" : "no") << std::endl;
    std::cout << "it2 == tree.begin(): " << (it2 == tree.begin() ? "yes" : "no") << std::endl;
    std::cout << "it != tree.end(): " << (it != tree.end() ? "yes" : "no") << std::endl;
    
    std::cout << std::endl;
}

// Function to test a tree with strings
void testStringTree() {
    std::cout << "=== String Test ===" << std::endl;
    BinaryTree<std::string> stringTree;
    
    stringTree.insert("banana");
    stringTree.insert("apple");
    stringTree.insert("cherry");
    stringTree.insert("date");
    stringTree.insert("elderberry");
    
    std::cout << "Strings in alphabetical order: ";
    for (auto it = stringTree.begin(); it != stringTree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

// Function to run all tests
void runAllTests() {
    std::cout << "========== BINARY TREE TESTING ==========" << std::endl << std::endl;
    
    testEmptyTree();
    testSingleElement();
    testMultipleElements();
    testDuplicateElements();
    testCopyConstructor();
    testAssignmentOperator();
    testIteratorOperations();
    testStringTree();
    
    std::cout << "========== TESTING COMPLETED ==========" << std::endl;
}