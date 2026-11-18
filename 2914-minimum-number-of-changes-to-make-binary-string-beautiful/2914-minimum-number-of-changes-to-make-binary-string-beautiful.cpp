class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i+1<n;i++){
            if(s[i]==s[i+1])i++;
            else{
                ans++;
                i++;
            }
        }
        return ans;
    }
};