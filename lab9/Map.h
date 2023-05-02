#pragma once
#include <iostream>
#include"Pair.h"
template<typename K, typename V>
class Map {
protected:
    struct Node {
        K key;
        V value;
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
    bool Includes(const Map<K, V>& other) const {
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

        Pair<K, V> operator*() const {
            return Pair<K, V>(current->key, current->value);
        }

        Iterator begin() const {
            return Iterator(start, 0);
        }

        Iterator end() const {
            return Iterator(nullptr, count);
        }
        const V& operator[](const K& key) {
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
                Node* newNode = new Node(key, V());
                if (prev == nullptr) {
                    // Adãugãm la începutul listei.
                    newNode->next = start;
                    start = newNode;
                }
                else {
                    // Adãugãm dupã nodul prev.
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
                return newNode->value;
            }
        }
    };
};

