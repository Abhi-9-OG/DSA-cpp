#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Hash map to store number and its index
        unordered_map<int, int> mp;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Find the required complement
            int need = target - nums[i];

            // Check if complement already exists
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            // Store current number and index
            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices: ";
    for (int index : ans) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}