#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        if (s == goal) {
            for (int i = 0; i < s.length(); i++) {
                for (int j = i + 1; j < s.length(); j++) {
                    if (s[i] == s[j])
                        return true;
                }
            }
            return false;
        }

        int first = -1;
        int second = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (first == -1)
                    first = i;
                else if (second == -1)
                    second = i;
                else
                    return false;
            }
        }

        if (second == -1)
            return false;

        return s[first] == goal[second] &&
               s[second] == goal[first];
    }
};

int main() {
    Solution obj;

    string s = "ab";
    string goal = "ba";

    cout << boolalpha << obj.buddyStrings(s, goal);

    return 0;
}