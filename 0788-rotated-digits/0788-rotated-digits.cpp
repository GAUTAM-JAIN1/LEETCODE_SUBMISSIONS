class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            bool valid = true;
            bool changed = false;
            while (x > 0) {
                int d = x % 10;
                if (d == 3 || d == 4 || d == 7) {
                    valid = false;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    changed = true;
                }
                x /= 10;
            }

            if (valid && changed)
                ans++;
        }

        return ans;
    }
};

/* bool helper(int a){
         int m = a;
         vector<int>arr;
         while(m>0){
             int b = m%10;
             arr.push_back(b);
             m/=10;
         }
         vector<int>ans;
         for(int i=0;i<arr.size();i++){
             if(arr[i]==3 || arr[i]==4 || arr[i]==7)return false;
             else if(arr[i]==0 || arr[i]==1 || arr[i]==8)ans.push_back(arr[i]);
             else if(arr[i]==2)ans.push_back(5);
             else if(arr[i]==5)ans.push_back(2);
             else if(arr[i]==6)ans.push_back(9);
             else if(arr[i]==9)ans.push_back(6);
         }
         if(arr == ans)return false;
         return true;
 }

 int rotatedDigits(int n) {
 int count=0;
         for(int i=1;i<=n;i++){
            if(helper(i))count++;
         }
         return count;*/
