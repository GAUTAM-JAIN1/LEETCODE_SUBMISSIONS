class Solution {
public:

int maxer(int x){
    vector<int>a;
    while(x>0){
        int m = x%10;
        a.push_back(m);
        x/=10;
    }
    sort(a.rbegin(),a.rend());
    int b=0;
          for(int i=0;i<a.size();i++){
                    b = b+(a[i]*(pow(10,a.size()-i-1)));
          }  
          return b;
}
    long long maximizeSum(vector<int>& nums, int k) {
        int n  = nums.size();
       vector<int>largest(n,0);
       for(int i=0;i<n;i++){
        largest[i] = maxer(nums[i])-nums[i];
       }
       long long ans=0;
      sort(largest.rbegin(),largest.rend());
      for(int i=0;i<k;i++){
            ans+=largest[i];
      }
                for(int i=0;i<n;i++){
                    ans+=nums[i];
                }
                return ans;
    }
};