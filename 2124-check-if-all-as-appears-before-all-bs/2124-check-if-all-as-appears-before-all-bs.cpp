class Solution {
public:
    bool checkString(string s) {
        int n  = s.length();
        int a=-1,b=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a')a=i;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                b=i;
                break;
            }
        }
            if(a>b && b>=0)return false;
            return true;
    }
};