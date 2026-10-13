class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>squared(n);
        for(int i=0;i<n;i++){
            squared[i]=nums[i]*nums[i];
        }
        sort(squared.begin(),squared.end());
        int i=0,j=n-1;
        long long ans= 0;
        while(i<j){
                ans+=squared[j];
                ans-=squared[i];
                i++;
                j--;
        }
        if(i==j){
            ans+=squared[j];
        }
        return ans;
    }
};