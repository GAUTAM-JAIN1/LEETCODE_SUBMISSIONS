class Solution {
public:
    int minMoves(vector<int>& nums) {
       int sum=0;
       int min=INT_MAX;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<min){
            min=nums[i];
        }
       } 
        for(int i=0;i<nums.size();i++){
       sum = sum + (nums[i]-min);
       } 
    return sum;
    }
};