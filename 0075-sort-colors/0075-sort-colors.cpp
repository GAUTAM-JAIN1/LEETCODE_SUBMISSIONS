class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeros=0,ones=0,twos=0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0)zeros++;
            if(nums[i]==1)ones++;
            if(nums[i]==2)twos++;
        }
        int i = 0;
        while(zeros>0){
            nums[i]=0;
            i++;
            zeros--;
        }
        
         while(ones>0){
            nums[i]=1;
            i++;
            ones--;
        }

         while(twos>0){
            nums[i]=2;
            i++;
            twos--;
        }
       
    }
};