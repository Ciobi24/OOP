#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<queue>
#include <utility>
#include<vector>
#include<algorithm>
#include<cctype>
#include<iomanip>
using namespace std;
ifstream file("input.txt");
string line, word;
size_t word_c, word_p;
map<string, int> m;


class ComparePairs {
public:
    static bool lexCompare(const string& s1, const string& s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len = min(len1, len2);

        for (int i = 0; i < len; i++) {
            if (s1[i] < s2[i]) {
                return false;
            }
            else if (s1[i] > s2[i]) {
                return true;
            }
        }

        return (len1 < len2);
    }
    typedef pair<string, int> value_type;
    bool operator()(const value_type& lhs, const value_type& rhs) const {
        if (lhs.second == rhs.second)
            return lhs.first.compare(rhs.first) > 0;
        else
        return lhs.second < rhs.second;
    }
};



int main()
{
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
	getline(file, line);
    transform(line.begin(), line.end(), line.begin(), [](unsigned char c) {return tolower(c);});
    word_c = line.find_first_of(" ,.?!");
    word_p = 0;
    while (word_c!=string::npos)
    {
        word = line.substr(word_p, word_c - word_p);
        if (word.size() > 0)
            m[word]++;
        word.clear();
        word_p = word_c + 1;
        word_c = line.find_first_of(" ,.?!",word_p);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePairs> q;
    for (auto i = m.begin(); i != m.end(); i++)
        q.push(pair<string,int>(i->first,i->second));
    while (!q.empty()) {
        cout << q.top().first << " => " << q.top().second<<endl;
        q.pop();
    }
}
