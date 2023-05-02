template <typename K, typename V>
class Pair {
public:
    K first;
    V second;
    int index; 
    Pair(K f, V s, int i) : first(f), second(s), index(i) {} 
    bool operator==(const Pair<K, V>& other) const {
        return (first == other.first && second == other.second && index == other.index);
    }
};
