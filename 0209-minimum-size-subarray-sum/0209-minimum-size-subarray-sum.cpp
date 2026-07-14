class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minl = INT_MAX;
        int i = 0, j = 0;
        int sum = 0;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                minl = min(minl, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if (minl == INT_MAX)
            return 0;
        return minl;
    }
};