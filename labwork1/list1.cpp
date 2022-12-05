#include <iostream>
#include <string>
#include "list1.h"
#include "dice.h"

template <typename T>
void Element<T>::print() {
    std::cout << "(" << data << ")  ";
}

template <typename T>
void Element<T>::get_pr() {
    priority = (std::size_t)data;
}

template <>
void Element<std::string>::get_pr() {
    std::size_t i = 0, l = data.length();
    while (i < l) {
        priority *= 10;
        priority += (std::size_t)data[i];
        i++;
    }
}

//  - Priority Queue

template <typename T>
Priority_queue<T>::Priority_queue() {
    head = nullptr;
    tail = head;
}

template <typename T>
Priority_queue<T>::~Priority_queue() {
    clear();
}

template <typename T>
bool Priority_queue<T>::is_empty() {
    if (!head) return true;
    return false;
}

template <typename T>
void Priority_queue<T>::insert(T data) {
    Queue_node* new_node = new Queue_node;
    new_node->node.data = data;
    new_node->node.get_pr();
    if (is_empty()) {
        new_node->prev = nullptr;
        new_node->next = nullptr;
        head = new_node;
        tail = new_node;
        return;
    }
    Queue_node* current = head;
    if (current->node.priority > new_node->node.priority) {
        current->prev = new_node;
        new_node->next = current;
        new_node->prev = nullptr;
        head = new_node;
        return;
    }
    while (current->next && new_node->node.priority > current->node.priority) current = current->next;
    if (current->node.priority < new_node->node.priority) {
        current->next = new_node;
        new_node->prev = current;
        new_node->next = nullptr;
        tail = new_node;
        return;
    }
    current->prev->next = new_node;
    new_node->prev = current->prev;
    new_node->next = current;
    current->prev = new_node;
}

template <typename T>
void Priority_queue<T>::delete_hp() {
    if (is_empty()) return;
    if (!head->next) {
        head = nullptr;
        tail = nullptr;
        return;
    }
    Queue_node* current = tail;
    tail = current->prev;
    tail->next = nullptr;
    delete current;
}

template <typename T>
void Priority_queue<T>::clear() {
    while (!is_empty()) delete_hp();
}

template <typename T>
void Priority_queue<T>::print() {
    if (is_empty()) {
        std::cout << "Queue is empty\n\n";
        return;
    }
    Queue_node* current = head;
    while (current) {
        current->node.print();
        current = current->next;
    }
    std::cout << "\n\n";
}

template <typename T>
Element<T> Priority_queue<T>::get_hp() {
    Element<T> e;
    if (is_empty()) {
        e.data = T();
        e.priority = 0;
        return e;
    }
    e.data = tail->node.data;
    e.priority = tail->node.priority;
    return e;
}

// - Array

template <typename T>
void Array<T>::get_size() {
    std::cout << "Enter the size of the Array: ";
    std::cin >> size;
}

template <typename T>
Array<T>::Array(std::size_t a) {
    if (a == 0) get_size();
    else size = a;
    el = new Element<T>[size];
    for (std::size_t i = 0; i < size; i++) {
        el[i].data = T();
        el[i].priority = 0;
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] el;
}

template <typename T>
bool Array<T>::is_empty() {
    if (el[0].priority == 0) return true;
    return false;
}

template <typename T>
void Array<T>::insert(T data) {
    if (el[size - 1].priority > 0) {
        std::cout << "Array is full\n\n";
        return;
    }
    std::size_t i = 0;
    while (el[i].priority > 0) i++;
    el[i].data = data;
    el[i].get_pr();
}

template <typename T>
void Array<T>::delete_hp() {
    if (is_empty()) return;
    std::size_t max_pr = 0, n = 0, i = 0;
    while (el[i].priority > 0 && i < size) {
        if (el[i].priority > max_pr) {
            max_pr = el[i].priority;
            n = i;
        }
        i++;
    }
    i = n + 1;
    while (el[i].priority > 0 && i < size) {
        el[i - 1].data = el[i].data;
        el[i - 1].priority = el[i].priority;
        i++;
    }
    el[i - 1].data = T();
    el[i - 1].priority = 0;
}

template <typename T>
void Array<T>::print() {
    if (is_empty()) {
        std::cout << "Array is empty\n\n";
        return;
    }
    std::size_t i = 0;
    while (el[i].priority > 0 && i < size) {
        el[i].print();
        i++;
    }
    std::cout << "\n\n";
}

template <typename T>
void Array<T>::clear() {
    if (is_empty()) return;
    std::size_t i = 0;
    while (el[i].priority > 0 && i < size) {
        el[i].data = (T)0;
        el[i].priority = 0;
        i++;
    }
}

template <>
void Array<std::string>::clear() {
    if (is_empty()) return;
    std::size_t i = 0;
    while (el[i].priority > 0 && i < size) {
        el[i].data = "";
        el[i].priority = 0;
        i++;
    }
}

template <typename T>
Element<T> Array<T>::get_hp() {
    Element<T> e;
    if (is_empty()) {
        e.data = T();
        e.priority = 0;
        return e;
    }
    std::size_t n = 0, max_pr = 0, i = 0;
    while (el[i].priority > 0 && i < size) {
        if (el[i].priority > max_pr) {
            max_pr = el[i].priority;
            n = i;
        }
        i++;
    }
    e.data = el[n].data;
    e.priority = el[n].priority;
    return e;
}

// - Tree

template <typename T>
void Tree_node<T>::print() {
    node.print();
    std::cout << "{";
    if (left) {
        std::cout << "l: ";
        left->print();
    }
    if (right) {
        std::cout << "r: ";
        right->print();
    }
    std::cout << "}  ";
}

template <typename T>
Binary_tree<T>::Binary_tree() {
    root = nullptr;
}

template <typename T>
Binary_tree<T>::~Binary_tree() {
    clear();
}

template <typename T>
bool Binary_tree<T>::is_empty() {
    if (!root) return true;
    return false;
}

template <typename T>
Tree_node<T>* Binary_tree<T>::rec_insert(T data, Tree_node<T>* current) {
    Element<T> el;
    el.data = data;
    el.get_pr();
    if (!current) {
        current = new Tree_node<T>(el);
        return current;
    }
    if (current->node.priority < el.priority) {
        current->right = rec_insert(data, current->right);
    }
    else {
        current->left = rec_insert(data, current->left);
    }
    return current;
}

template <typename T>
void Binary_tree<T>::insert(T data) {
    root = rec_insert(data, root);
}

template <typename T>
Tree_node<T>* Binary_tree<T>::help_func(Tree_node<T>* c1, Tree_node<T>* c2) {
    Tree_node<T>* to_del;
    if (c1->right) { c1->right = help_func(c1->right, c2); }
    else {
        c2->node.priority = c1->node.priority;
        c2->node.data = c1->node.data;
        to_del = c1;
        c1 = c1->left;
        delete to_del;
    }
    return c1;
}

template <typename T>
Tree_node<T>* Binary_tree<T>::rec_delete_hp(Tree_node<T>* current) {
    Tree_node<T>* to_del;
    if (current) {
        if (current->right) {
            current->right = rec_delete_hp(current->right);
        }
        else if (current->left) {
            current->left = help_func(current->left, current);
        }
        else {
            to_del = current;
            current = current->right;
            delete to_del;
        }
    }
    return current;
}

template <typename T>
void Binary_tree<T>::delete_hp() {
    root = rec_delete_hp(root);
}

template <typename T>
void Binary_tree<T>::clear() {
    while (!is_empty()) delete_hp();
}

template <typename T>
void Binary_tree<T>::print() {
    if (is_empty()) {
        std::cout << "Binary tree is empty\n\n";
        return;
    }
    root->print();
    std::cout << "\n\n";
}

template <typename T>
Element<T> Binary_tree<T>::get_hp() {
    Element<T> e;
    if (is_empty()) {
        e.data = T();
        e.priority = 0;
        return e;
    }
    Tree_node<T>* current = root;
    while (current->right) current = current->right;
    e.data = current->node.data;
    e.priority = current->node.priority;
    return e;
}

template
class Element<int>;
template
class Element<float>;
template
class Element<double>;
template
class Element<char>;
template
class Element<std::string>;

template
class Priority_queue<int>;
template
class Priority_queue<float>;
template
class Priority_queue<double>;
template
class Priority_queue<char>;
template
class Priority_queue<std::string>;

template
class Array<int>;
template
class Array<float>;
template
class Array<double>;
template
class Array<char>;
template
class Array<std::string>;

template 
class Tree_node<int>;
template
class Tree_node<float>;
template
class Tree_node<double>;
template
class Tree_node<char>;
template
class Tree_node<std::string>;

template
class Binary_tree<int>;
template
class Binary_tree<float>;
template
class Binary_tree<double>;
template
class Binary_tree<char>;
template
class Binary_tree<std::string>;