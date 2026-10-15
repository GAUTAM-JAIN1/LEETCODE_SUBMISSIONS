class Solution {
public:
int unique(vector<int>arr){
    set<int>s;
    int a = arr.size();
    for(int i=0;i<a;i++){
    s.insert(arr[i]);
    }
    return s.size();
}
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>arr;
            for(int j=i;j<n;j++){
                arr.push_back(nums[j]);
                    int cnt = unique(arr);
                ans += cnt * cnt;  
            }
        }
        return ans;
    }
};