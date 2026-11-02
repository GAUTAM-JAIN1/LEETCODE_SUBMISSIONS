class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            vector<int> order;
            for (int j = i; j < n; j++) {
                if (mpp[nums[j]] == 0) {
                    order.push_back(nums[j]);
                }
                mpp[nums[j]]++;
                bool valid = true;
                for (int k = 0; k < order.size(); k++) {
                    if (mpp[order[k]] != k + 1) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    ans++;
            }
        }
        return ans;
    }
};