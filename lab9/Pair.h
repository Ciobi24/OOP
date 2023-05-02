#pragma once
template <typename K, typename V>
class Pair {
public:
    K first;
    V second;
    Pair(K f, V s) : first(f), second(s) {}
    bool operator==(const Pair<K, V>& other) const {
        return (first == other.first && second == other.second);
    }
};
