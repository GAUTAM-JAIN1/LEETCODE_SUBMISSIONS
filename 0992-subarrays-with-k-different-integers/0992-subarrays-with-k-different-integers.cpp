class Solution {
public:
    int kincluded(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i = 0, j = 0;
        map<int, int> mpp;
        while (j < n) {
            mpp[nums[j]]++;

            while (mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kincluded(nums, k) - kincluded(nums, k - 1);
    }
};

// O(n^3 solution)
/* bool goodsub(vector<int> arr, int k) {
     map<int, int> mpp;
     int n = arr.size();
     int j = 0;
     while (j < n) {
         mpp[arr[j]]++;
         j++;
         if (mpp.size() > k)
             return false;
     }
        return mpp.size() == k;
 }

 int subarraysWithKDistinct(vector<int>& nums, int k) {
     int n = nums.size();
   int count=0;
     for(int i=0;i<n;i++){
           vector<int>a;
         for(int j=i;j<n;j++){
                 a.push_back(nums[j]);
                   if(goodsub(a,k))count++;
         }

     }
     return count;*/