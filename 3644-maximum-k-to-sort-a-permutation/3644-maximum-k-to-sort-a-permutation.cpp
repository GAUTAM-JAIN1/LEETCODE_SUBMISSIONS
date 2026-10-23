class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int>a;
         vector<int>b;
         a=nums;
         sort(a.begin(),a.end());

        
        for(int i=0;i<n;i++){
                if(nums[i]==a[i])continue;
                else b.push_back(nums[i]);
        }
        
           if (b.empty()) return 0;

        int x = b[0];

        for (int i = 1; i < b.size(); i++) {
            x = x & b[i];
        }

            return x;
    }
};