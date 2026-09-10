#include <string>
using namespace std;
class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        for (char c : t) {
            int countS = 0, countT = 0;
            for (char x : s)
                if (x == c)
                    countS++;
            for (char x : t)
                if (x == c)
                    countT++;
            if (countT > countS)
                return c;
        }

        return 0;
    }
};