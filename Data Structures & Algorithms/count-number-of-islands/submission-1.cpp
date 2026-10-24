class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //vector<vector<bool> visited(grid.size(),grid[0].size());
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        int island=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0; c<grid[0].size();c++){
                if(grid[r][c]=='1'){
                    dfs(grid,r,c,directions);
                    island++;
                }
            }
        }
        return island;
    }
    void dfs(vector<vector<char>>& grid,int r, int c,const vector<vector<int>>& directions){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            dfs(grid, r+directions[i][0],c+directions[i][1],directions);
        }
    }
};
