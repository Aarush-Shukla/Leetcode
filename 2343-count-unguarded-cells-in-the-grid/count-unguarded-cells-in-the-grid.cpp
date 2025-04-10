class Solution {
    vector<int> dir={-1,0,1,0,-1};

    void dfs(int x,int y,int direction,vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>= grid[0].size() || grid[x][y]==2 || grid[x][y]==3){
            return;
            }
            grid[x][y]=1;
            if(direction==0)dfs(x-1,y,direction,grid);//Up
            if(direction==1)dfs(x,y+1,direction,grid);//Right
            if(direction==2)dfs(x+1,y,direction,grid);//Down
            if(direction==3)dfs(x,y-1,direction,grid);//Left
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));

        for(auto& guard: guards){
            grid[guard[0]][guard[1]]=2;
        }
        for(auto& wall: walls){
            grid[wall[0]][wall[1]]=3;
        }

        for(auto& guard:guards){
               for(int i=0;i<4;i++){
                int x=guard[0]+dir[i];
                int y=guard[1]+dir[i+1];
                dfs(x,y,i,grid);
            }
        }

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};