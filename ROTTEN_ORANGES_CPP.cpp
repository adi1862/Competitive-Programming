class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size(), ans=0;
        queue<pair<int, pair<int, int> > > q;
        for(int i=0;i<row;i++){
            for (int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(0,make_pair(i,j)));
                }
            }
        }
        while(!q.empty()){
            int x = ((q.front()).second).first;
            int y = ((q.front()).second).second;
            int level = (q.front()).first;
            q.pop();
            // cout<<x<<" "<<y<<" "<<level<<'\n';
            //bottom
            if(x+1 < row && grid[x+1][y] == 1){
                grid[x+1][y] = 2;
                q.push(make_pair(level+1, make_pair(x+1, y)));
            }
            //top
            if(x-1 >= 0 && grid[x-1][y] == 1){
                grid[x-1][y] = 2;
                q.push(make_pair(level+1, make_pair(x-1, y)));
            }
            //right
            if(y+1 < col && grid[x][y+1] == 1){
                grid[x][y+1] = 2;
                q.push(make_pair(level+1, make_pair(x, y+1)));
            }
            //left
            if(y-1 >= 0 && grid[x][y-1] == 1){
                grid[x][y-1] = 2;
                q.push(make_pair(level+1, make_pair(x, y-1)));
            }
            ans = max(ans, level);
        }
        for(int i=0;i<row;i++){
            for (int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans; 
    }
};
