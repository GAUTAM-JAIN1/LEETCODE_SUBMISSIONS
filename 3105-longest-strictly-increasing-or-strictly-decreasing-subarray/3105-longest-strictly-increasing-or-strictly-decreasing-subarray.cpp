class Solution {
public:
    bool issorted(vector<int> arr) {
        int n = arr.size();
        vector<int> x = arr;
        sort(x.begin(), x.end());
        for(int i = 0; i + 1 < n; i++) {
            if(x[i] == x[i+1]) return false;
        }

        if(x == arr) return true;
        return false;
    }
    bool isrsorted(vector<int> arr) {
        int n = arr.size();
        vector<int> y = arr;
        sort(y.rbegin(), y.rend());

        for(int i = 0; i + 1 < n; i++) {
            if(y[i] == y[i+1]) return false;
        }

        if(y == arr) return true;
        return false;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> arr;

            for(int j = i; j < n; j++) {
                arr.push_back(nums[j]);

                if(issorted(arr) || isrsorted(arr))
                    ans = max(ans, (int)arr.size());
            }
        }
        return ans;
    }
};