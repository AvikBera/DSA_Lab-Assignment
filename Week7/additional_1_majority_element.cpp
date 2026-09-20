#include <iostream>
#include <vector>
using namespace std;

// Boyer-Moore Voting Algorithm - O(n) time, O(1) space
// Works because the majority element appears more than n/2 times, so it
// always survives the cancelling-out process against all other elements.
int majorityElement(vector<int>& nums) {
    int candidate = nums[0], count = 0;

    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    vector<int> nums1 = {3, 2, 3};
    cout << "Input: [3, 2, 3] -> Majority Element: " << majorityElement(nums1) << endl;

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Input: [2, 2, 1, 1, 1, 2, 2] -> Majority Element: " << majorityElement(nums2) << endl;

    return 0;
}
