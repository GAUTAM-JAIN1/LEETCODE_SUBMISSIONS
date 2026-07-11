class Solution {
public:
    vector<vector<int>> removedup(vector<vector<int>> arr) {
        int n = arr.size();
        vector<vector<int>> abc;
        map<vector<int>, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
            if (mpp[arr[i]] == 1)
                abc.push_back(arr[i]);
        }
        return abc;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    if (sum == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                    }
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
      ans =  removedup(ans);
        return ans;
    }
};