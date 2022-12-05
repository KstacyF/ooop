#pragma once

#ifndef LIST1_H
#define LIST1_H

template <typename T>
class Element {
public:
    T data;
    std::size_t priority;

    Element(T data = T(), std::size_t priority = 0) {
        this->data = data;
        this->priority = priority;
    }

    void print();
    void get_pr();
};

extern template
class Element<int>;

extern template
class Element<double>;

extern template
class Element<std::string>;

extern template
class Element<char>;

template <typename T>
class Priority_queue {
private:
    class Queue_node {
    public:
        Element<T> node;
        Queue_node* next;
        Queue_node* prev;

        Queue_node(Element<T> node = Element<T>(), Queue_node* next = nullptr, Queue_node* prev = nullptr) {
            this->node = node;
            this->next = next;
            this->prev = prev;
        }
    };
    Queue_node* head;
    Queue_node* tail;
public:
    Priority_queue();
    ~Priority_queue();
    bool is_empty();
    void insert(T data);
    void delete_hp(); // hp -- highest priority
    void clear();
    void print();
    Element<T> get_hp();
};

extern template
class Priority_queue<int>;

extern template
class Priority_queue<double>;

extern template
class Priority_queue<std::string>;

extern template
class Priority_queue<char>;

template <typename T>
class Array {
private:
    std::size_t size;
    void get_size();
    Element<T>* el;
public:
    Array(std::size_t a = 0);
    //Array();
    ~Array();
    bool is_empty();
    void insert(T data);
    void delete_hp();
    void print();
    void clear();
    Element<T> get_hp();
};

extern template
class Array<int>;

extern template
class Array<double>;

extern template
class Array<std::string>;

extern template
class Array<char>;

template <typename T>
class Tree_node {
public:
    Element<T> node;
    Tree_node* right;
    Tree_node* left;

    Tree_node(Element<T> node = Element<T>(), Tree_node* right = nullptr, Tree_node* left = nullptr) {
        this->node = node;
        this->right = right;
        this->left = left;
    }

    void print();
};

extern template
class Tree_node<int>;

extern template
class Tree_node<double>;

extern template
class Tree_node<std::string>;

extern template
class Tree_node<char>;

template <typename T>
class Binary_tree {
private:
    Tree_node<T>* root;
public:
    Binary_tree();
    ~Binary_tree();
    bool is_empty();
    Tree_node<T>* rec_insert(T data, Tree_node<T>* current);
    void insert(T data);
    Tree_node<T>* help_func(Tree_node<T>* c1, Tree_node<T>* c2);
    Tree_node<T>* rec_delete_hp(Tree_node<T>* current);
    void delete_hp();
    void print();
    void clear();
    Element<T> get_hp();
};

extern template
class Binary_tree<int>;

extern template
class Binary_tree<double>;

extern template
class Binary_tree<std::string>;

extern template
class Binary_tree<char>;

#endif