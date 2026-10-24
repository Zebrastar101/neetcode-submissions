class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for( int r= 0 ; r<grid.size();r++){
            for( int c=0; c<grid[0].size();c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                    visited[r][c]=true;
                }
            }
        }
        int dist=1;
        while(!q.empty()){
            int q_size=q.size();
            for(int i=0;i<q_size;i++){
            
            int r= q.front().first;
            int c=q.front().second;
            q.pop();
            addroom(r+1,c,grid,dist,q,visited);
            addroom(r-1,c,grid,dist,q,visited);
            addroom(r,c+1,grid,dist,q,visited);
            addroom(r,c-1,grid,dist,q,visited);}
            dist+=1;
        }
    }
    void addroom(int r, int c, vector<vector<int>>&grid, int dist, queue<pair<int,int>>& q,vector<vector<bool>>& visited){
        
        if(r<0||r>=grid.size()||c<0||c>=grid[0].size()||grid[r][c]==0 ||grid[r][c]==-1||visited[r][c]){
            return;
        }
        grid[r][c]=dist;
        visited[r][c]=true;
        q.push({r,c});
        
    }
    
};
