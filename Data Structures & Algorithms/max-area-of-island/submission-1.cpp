class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int r=i;
        int c=j;
        int ans=0;
        for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                   ans=ans+ dfs(nrow,ncol,grid,vis);
                }
            }
            return 1+ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans=max(ans,dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};