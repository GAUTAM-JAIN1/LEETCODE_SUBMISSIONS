class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        for(int i=0;i<n;i++){
            long double prod = 1;
           long long gc = 0;
            long long lc = 1;
            
            for(int j=i;j<n;j++){
                prod*=nums[j];
                if(j==i){
                    gc = nums[j];
                    lc= nums[j];
                    
                }
                else {
                    gc = gcd(gc,nums[j]);
                    lc= lcm(lc,nums[j]);
                }
                if(prod == lc*gc){
                    len  = max(len,j-i+1);
                }
                    
            }
        }
        return len;
    }
};