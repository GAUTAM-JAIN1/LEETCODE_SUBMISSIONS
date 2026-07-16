class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>mx(n,0);
        mx[0]=nums[0];
        for(int i=1;i<n;i++){
            mx[i] = max(nums[i],mx[i-1]);
        }
        vector<int>prefixgcd(n);
        for(int i=0;i<n;i++){
            prefixgcd[i]=gcd(nums[i],mx[i]);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int l=0,r=n-1;
        long long sum=0;
        while(l<r){
            sum+=gcd(prefixgcd[l],prefixgcd[r]);
            l++,r--;
        }
        return sum;
    }
};