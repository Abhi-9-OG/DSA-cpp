#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++) {
        int pos = 0;

        while (nums2[pos] != nums1[i]) {
            pos++;
        }

        int greater = -1;

        for (int j = pos + 1; j < nums2.size(); j++) {
            if (nums2[j] > nums1[i]) {
                greater = nums2[j];
                break;
            }
        }

        ans.push_back(greater);
    }

    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}