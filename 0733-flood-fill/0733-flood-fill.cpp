class Solution {
public:

void dfs(int sr,int sc,vector<vector<int>>& image,int color,int x){
            int m  = image.size();
        int n = image[0].size();
            if(sr<0||sc<0||sr>=m||sc>=n||image[sr][sc]!=x)return;
            image[sr][sc]=color;
            dfs(sr+1,sc,image,color,x);
            dfs(sr-1,sc,image,color,x);
            dfs(sr,sc+1,image,color,x);
            dfs(sr,sc-1,image,color,x);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m  = image.size();
        int n = image[0].size();
        int x = image[sr][sc];
            if (x == color) return image;
            dfs(sr,sc,image,color,x);
            return image;
    }
};