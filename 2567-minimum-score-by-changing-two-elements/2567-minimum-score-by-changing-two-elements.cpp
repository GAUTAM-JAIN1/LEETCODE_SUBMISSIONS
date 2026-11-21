class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        int high=0;
        if(n==3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int a = abs(nums[2]-nums[n-1]);
           int b = abs(nums[1]-nums[n-2]);
              int c = abs(nums[0]-nums[n-3]);
high = min(a,min(b,c));
       return high;
    }
};
