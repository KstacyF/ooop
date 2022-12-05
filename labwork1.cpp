#include <iostream>
#include "list1.h"
#include "dice.h"

void dem_mode() {
    std::cout << "Let's create priority queue with integer elements {1}, {6}, {2} and {6}\n\nWe are going to: 1. Print queue\n\t\t 2. Insert elements\n\t\t 3. Print queue\n\t\t 4. Get element with highest priority\n\t\t 5. Delete all elements one by one\n\t\t 6. Print queue\n\n";
    Element<int> e1, e2, e3;
    std::cout << "Using Array ----------------------------------\n\n";
    Array<int> one(4);
    one.print();
    one.insert({ 1 });
    one.insert({ 6 });
    one.insert({ 2 });
    one.insert({ 6 });
    one.print();
    e1 = one.get_hp();
    e1.print();
    std::cout << "\n\n";
    one.delete_hp();
    one.print();
    one.delete_hp();
    one.print();
    one.delete_hp();
    one.print();
    one.delete_hp();
    one.print();
    std::cout << "Using Linked list ----------------------------\n\n";
    Priority_queue<int> queue;
    queue.print();
    queue.insert({ 1 });
    queue.insert({ 6 });
    queue.insert({ 2 });
    queue.insert({ 6 });
    queue.print();
    e2 = queue.get_hp();
    e2.print();
    std::cout << "\n\n";
    queue.delete_hp();
    queue.print();
    queue.delete_hp();
    queue.print();
    queue.delete_hp();
    queue.print();
    queue.delete_hp();
    queue.print();
    std::cout << "Using Binary tree ----------------------------\n\n";
    Binary_tree<int> tree;
    tree.print();
    tree.insert({ 1 });
    tree.insert({ 6 });
    tree.insert({ 2 });
    tree.insert({ 6 });
    tree.print();
    e3 = tree.get_hp();
    e3.print();
    std::cout << "\n\n";
    tree.delete_hp();
    tree.print();
    tree.delete_hp();
    tree.print();
    tree.delete_hp();
    tree.print();
    tree.delete_hp();
    tree.print();
    std::cout << "Let's create priority queue with char elements {b}, {c}, {a} and {m} using Array\n\n";
    Element<char> e4;
    Array<char> two(4);
    two.insert('b');
    two.insert('c');
    two.insert('a');
    two.insert('m');
    two.print();
    e4 = two.get_hp();
    e4.print();
    std::cout << "\n\n";
    two.delete_hp();
    two.print();
    two.delete_hp();
    two.print();
    two.delete_hp();
    two.print();
    two.delete_hp();
    two.print();
    std::cout << "Let's create priority queue with string elements {akka}, {lam}, {spring} and {ww} using Linked list\n\n";
    Element<std::string> e5;
    Priority_queue<std::string> list;
    list.insert({ "akka" });
    list.insert({ "lam" });
    list.insert({ "spring" });
    list.insert({ "ww" });
    list.print();
    e5 = list.get_hp();
    e5.print();
    std::cout << "\n\n";
    list.delete_hp();
    list.print();
    list.delete_hp();
    list.print();
    list.delete_hp();
    list.print();
    list.delete_hp();
    list.print();
    std::cout << "Let's create 5 different dice\n\n";
    Dice a1(2, { 0.4, 0.6 });
    a1.print();
    Dice a2(4, { 0.25, 0.25, 0.25, 0.25 });
    a2.print();
    Dice a3(8, { 0.1, 0.1, 0.2, 0.1, 0.1, 0.1, 0.2, 0.1 });
    a3.print();
    Dice a4(10, { 0.05, 0.3, 0.1, 0.04, 0.01, 0.15, 0.1, 0.1, 0.12, 0.03 });
    a4.print();
    Dice a5(12, { 0.1, 0.04, 0.07, 0.09, 0.2, 0.05, 0.15, 0.12, 0.08, 0.01, 0.05, 0.04 });
    a5.print();
    std::cout << "Dividing them into two sets...\n\n";
    Set s1, s2;
    s1.add(a1); s1.add(a2); s1.add(a5);
    s2.add(a3); s2.add(a4);
    s1.print(); s2.print();
    std::cout << "Finding probabilities of sums in this two sets...\n\n";
    Result r1, r2;
    s1.sum(r1); s2.sum(r2);
    std::cout << "Set 1:\n";
    s1.print();
    std::cout << "Set 2:\n";
    s2.print();
    std::cout << "Comparing...\n\n";
    comparison(r1, r2);
    system("pause");
}

int get_set_number(int si) {
    std::cout << "Set number: ";
    int n = 0;
    std::cin >> n;
    while (n > si) {
        std::cout << "Set " << n << " not found. Set number: ";
        std::cin >> n;
    }
    return n;
}

void dice_mode() {
    int c = 0, si = 0, n = 0, n1 = 0, n2 = 0;
    Dice d;
    std::vector<Result> results;
    std::vector<Set> sets;
    do {
        std::cout << "(1) Create set -- (2) Add die to set -- (3) Remove the last die -- (4) Find probabilities of sums -- (5) Compare two sets -- (0) Exit : ";
        std::cin >> c;
        std::cout << "\n";
        switch (c) {
        case 1:
            si++;
            sets.push_back(Set());
            results.push_back(Result());
            std::cout << "Set " << si << " created successfully\n\n";
            break;
        case 2:
            n = get_set_number(si);
            d.get_die();
            sets[n].add(d);
            std::cout << "Done!\n\n";
            break;
        case 3:
            n = get_set_number(si);
            sets[n].pop_back();
            std::cout << "Done!\n\n";
            break;
        case 4:
            n = get_set_number(si);
            sets[n].sum(results[n]);
            results[n].print();
            break;
        case 5:
            std::cout << "Choose two sets:\n";
            n1 = get_set_number(si);
            n2 = get_set_number(si);
            if (n1 == n2) std::cout << "Attention! You chose the same set\n";
            comparison(results[n1], results[n2]);
            break;
        case 0:
            return;
        }
    } while (c != 0);
}

int choice() {
    int c1 = 0;
    std::cout << "(1) Array -- (2) Linked list -- (3) Binary tree : ";
    std::cin >> c1;
    std::cout << "\n";
    return c1;
}

template <typename T>
T get_el() {
    T element;
    std::cout << "Element: ";
    std::cin >> element;
    return element;
}

template <typename T>
void queue_mode() {
    Array<T> arr;
    Priority_queue<T> list;
    Binary_tree<T> tree;
    Element<T> e;
    T el;
    int c = 0, c1 = 0;
    do {
        std::cout << "(1) Insert element -- (2) Delete the highest priority element -- (3) Get the highest priority element -- (4) Print -- (0) Exit : ";
        std::cin >> c;
        std::cout << "\n";
        switch (c) {
        case 1:
            el = get_el<T>();
            c1 = choice();
            switch (c1) {
            case 1:
                arr.insert(el);
                break;
            case 2:
                list.insert(el);
                break;
            case 3:
                tree.insert(el);
            }
            break;
        case 2: 
            c1 = choice();
            switch (c1) {
            case 1:
                arr.delete_hp();
                break;
            case 2:
                list.delete_hp();
                break;
            case 3:
                tree.delete_hp();
            }
            break;
        case 3:
            c1 = choice();
            switch (c1) {
            case 1:
                e = arr.get_hp();
                e.print();
                break;
            case 2:
                e = list.get_hp();
                e.print();
                break;
            case 3:
                e = tree.get_hp();
                e.print();
            }
            break;
        case 4:
            c1 = choice();
            switch (c1) {
            case 1:
                arr.print();
                break;
            case 2:
                list.print();
                break;
            case 3:
                tree.print();
            }
            break;
        case 0:
            return;
        }
    } while (c != 0);
}

void inter_mode() {
    int c = 0, c1 = 0;
    do {
        std::cout << "(1) Use Priority queue -- (2) Use Dice -- (0) Exit : ";
        std::cin >> c;
        std::cout << "\n";
        switch (c) {
        case 1:
            c1 = 0;
            std::cout << "Choose type: (1) Integers -- (2) Double -- (3) String -- (4) Char : ";
            std::cin >> c1;
            std::cout << "\n";
            switch (c1) {
            case 1:
                queue_mode<int>();
                break;
            case 2:
                queue_mode<double>();
                break;
            case 3:
                queue_mode<std::string>();
                break;
            case 4:
                queue_mode<char>();
            }
            break;
        case 2:
            dice_mode();
            break;
        case 0:
            return;
        }
    } while (c != 0);
}

void menu() {
    int c = 0;
    do {
        std::cout << "Choose the mode -- (1) Interactive -- (2) Demonstrative -- (0) Exit : ";
        std::cin >> c;
        std::cout << "\n";
        switch (c) {
        case 1:
            inter_mode();
            break;
        case 2:
            dem_mode();
            break;
        case 0:
            return;
        default:
            std::cout << "There is no such action :)\n\n";
        }
    } while (c != 0);
}

int main() {
    menu();
    system("pause");
    return 0;
}