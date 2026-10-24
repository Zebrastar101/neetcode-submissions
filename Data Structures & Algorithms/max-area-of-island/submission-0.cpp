class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //vector<vector<bool> visited(grid.size(),grid[0].size());
        if(grid.size()==0){return 0;}
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        int area=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0; c<grid[0].size();c++){
                if(grid[r][c]==1){
                    area=std::max(area,dfs(grid,r,c,directions));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>>& grid,int r, int c,const vector<vector<int>>& directions){
        int count=1;
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            count+=dfs(grid, r+directions[i][0],c+directions[i][1],directions);
        }
        return count;
    }
};

    

