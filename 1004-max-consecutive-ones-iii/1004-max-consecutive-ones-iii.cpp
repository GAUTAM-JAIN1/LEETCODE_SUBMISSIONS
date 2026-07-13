class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxl = 0;

        while (j < n) {
            if (nums[j] == 1)
                j++;
            else if (nums[j] == 0 && k > 0) {
                j++;
                k--;
            } else {
                maxl = max(maxl, j - i);

                while (nums[i] != 0) {
                    i++;
                }
                i++;
                k++;
            }
        }
        maxl = max(maxl, j - i);
        return maxl;
    }
};