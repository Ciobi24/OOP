#pragma once
#include <iostream>
#include"Pair.h"
template<typename K, typename V>
class Map {
protected:
    struct Node {
        K key;
        V value;
        int index;
        Node* next;
    };
    Node* start;
    int count;
public:
    Map() { count = 0; start = nullptr; }
    ~Map()
    {
        count = 0;
        while (start != nullptr)
        {
            Node* nod = start->next;
            delete start;
            start = nod;
        }
    }
    void update_indexes() { 
        Node* current = start;
        int index = 0;
        while (current != nullptr) {
            current->index = index;
            current = current->next;
            ++index;
        }
    }
    void Set(const K& key, const V& value) {
        Node* current = start;
        while (current != nullptr && current->key < key) {
            current = current->next;
        }
        if (current != nullptr && current->key == key) {
            current->value = value;
        }
        else {
            Node* new_node = new Node;
            new_node->key = key;
            new_node->value = value;
            new_node->next = current;
            current = new_node;
            ++count;
            update_indexes();
        }
    }
    bool Get(const K& key, V& value) {
        Node* current = start;
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    int Count() {
        return count;
    }
    void Clear() {
        count = 0;
        while (start != nullptr)
        {
            Node* nod = start->next;
            delete start;
            start = nod;
        }
    }
    bool Delete(const K& key) {
        Node* current = start;
        while (current != nullptr) {
            if (current->key == key) {
                Node* temp = current;
                current = temp->next;
                delete temp;
                --count;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool Includes(const Map<K, V>& other) {
        Node* current = start;
        while (current != nullptr) {
            V other_value;
            if (other.Get(current->key, other_value)) {
                if (current->value != other_value) {
                    return false;
                }
            }
            else {
                return false;
            }
            current = current->next;
        }
        return true;
    }
    class Iterator {
    private:
        Node* current;
        int index;

    public:
        Iterator(Node* ptr, int ind) : current(ptr), index(ind) {}
        bool operator!=(const Iterator& other) {
            return current != other.current;
        }

        void operator++() {
            current = current->next;
            ++index;
        }

        Pair<K, V> operator*() {
            return Pair<K, V>(current->key, current->value,current->index);
        }
    };
        Iterator begin() {
            return Iterator(start, 0);
        }

        Iterator end() {
            return Iterator(nullptr, count);
        }
        V& operator[](const K& key) {
            Node* current = start;
            Node* prev = nullptr;

            while (current != nullptr && current->key < key) {
                prev = current;
                current = current->next;
            }

            if (current != nullptr && current->key == key) {
                return current->value;
            }
            else {
                Node* newNode = new Node;
                newNode->key = key;
                newNode->value = V();
                if (prev == nullptr) {
                    newNode->next = start;
                    start = newNode;
                    update_indexes();
                }
                else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                    update_indexes();
                }
                return newNode->value;
            }
        }
    
};

