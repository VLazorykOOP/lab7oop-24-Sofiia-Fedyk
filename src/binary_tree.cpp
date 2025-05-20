// binary_tree.cpp
#include "binary_tree.h"

// Implementation of the runAllExamples function
void runAllExamples() {
    std::cout << "========== BINARY TREE USAGE EXAMPLES ==========" << std::endl << std::endl;
    
    // Basic usage
    std::cout << "=== Basic Usage ===" << std::endl;
    
    BinaryTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    std::cout << "Tree elements: ";
    for (auto value : tree) {
        std::cout << value << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Different data types
    std::cout << "=== Different Data Types ===" << std::endl;
    
    // Tree with integers
    BinaryTree<int> intTree;
    intTree.insert(10);
    intTree.insert(5);
    intTree.insert(15);
    
    std::cout << "Integers: ";
    for (auto value : intTree) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    // Tree with floating point numbers
    BinaryTree<double> doubleTree;
    doubleTree.insert(3.14);
    doubleTree.insert(2.71);
    doubleTree.insert(1.41);
    
    std::cout << "Floating point numbers: ";
    for (auto value : doubleTree) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    // Tree with strings
    BinaryTree<std::string> stringTree;
    stringTree.insert("cherry");
    stringTree.insert("apple");
    stringTree.insert("banana");
    
    std::cout << "Strings: ";
    for (auto value : stringTree) {
        std::cout << value << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Iterator usage
    std::cout << "=== Iterator Usage ===" << std::endl;
    
    BinaryTree<int> iterTree;
    iterTree.insert(25);
    iterTree.insert(15);
    iterTree.insert(35);
    iterTree.insert(10);
    iterTree.insert(20);
    iterTree.insert(30);
    iterTree.insert(40);
    
    // Using iterator with while loop
    std::cout << "Traversal with while: ";
    auto it = iterTree.begin();
    while (it != iterTree.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    // Using iterator with for loop
    std::cout << "Traversal with for: ";
    for (auto iter = iterTree.begin(); iter != iterTree.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Tree copying
    std::cout << "=== Tree Copying ===" << std::endl;
    
    // Create original tree
    BinaryTree<int> original;
    original.insert(100);
    original.insert(50);
    original.insert(150);
    original.insert(25);
    original.insert(75);
    
    std::cout << "Original tree: ";
    for (auto value : original) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    // Copy using copy constructor
    BinaryTree<int> copy1 = original;
    std::cout << "Copy 1: ";
    for (auto value : copy1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    // Copy using assignment operator
    BinaryTree<int> copy2;
    copy2 = original;
    std::cout << "Copy 2: ";
    for (auto value : copy2) {
        std::cout << value << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Finding maximum and minimum elements
    std::cout << "=== Min/Max Elements ===" << std::endl;
    
    BinaryTree<int> mmTree;
    mmTree.insert(50);
    mmTree.insert(30);
    mmTree.insert(70);
    mmTree.insert(20);
    mmTree.insert(40);
    mmTree.insert(60);
    mmTree.insert(80);
    
    if (!mmTree.empty()) {
        auto iter = mmTree.begin();
        int min = *iter;
        int max = min;
        
        for (auto value : mmTree) {
            if (value < min) min = value;
            if (value > max) max = value;
        }
        
        std::cout << "Minimum element: " << min << std::endl;
        std::cout << "Maximum element: " << max << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "========== EXAMPLES COMPLETED ==========" << std::endl;
}