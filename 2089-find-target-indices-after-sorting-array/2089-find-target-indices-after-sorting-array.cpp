class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target)ans.push_back(i);
            flag=1;
        }
        if(flag==0)return {};
        return ans;
    }
};