class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        map<char,int>even1;
        map<char,int>odd1;
        map<char,int>even2;
        map<char,int>odd2;
        for(int i=0;i<n;i++){
            if(i%2==0){
                even1[s1[i]]++;
                even2[s2[i]]++;
            }
            else{
                odd1[s1[i]]++;
                odd2[s2[i]]++;
            }
        }
        if(even1==even2 && odd1==odd2)return true;
        return false;
    }
};