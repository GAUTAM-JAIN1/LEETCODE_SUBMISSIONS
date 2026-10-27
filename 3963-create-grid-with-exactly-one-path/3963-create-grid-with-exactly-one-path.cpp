class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m-1;i++){
                string a=".";
                for(int j=1;j<n;j++){
                    a+='#';
                }
                ans.push_back(a);
        }
        string s="";
        for(int i=0;i<n;i++)s+='.';
        ans.push_back(s);
        return ans;
    }
};