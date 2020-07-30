class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        int** tbl = (int**)malloc(sizeof(int*) * row);
        for (int i = 0; i < row; i++) tbl[i] = (int*)malloc(sizeof(int) * col);
        tbl[row - 1][col - 1] = dungeon[row - 1][col - 1] < 0 ? -dungeon[row - 1][col - 1] + 1 : 1;
        for (int i = col - 2; i >= 0; i--){
            if (tbl[row - 1][i + 1] <= dungeon[row - 1][i]){
                tbl[row - 1][i] = 1;
                continue;
            }
            tbl[row - 1][i] = tbl[row - 1][i + 1] - dungeon[row - 1][i];
        }
        for (int i = row - 2; i >= 0; i--){
            if (tbl[i + 1][col - 1] <= dungeon[i][col - 1]){
                tbl[i][col - 1] = 1;
                continue;
            }
            tbl[i][col - 1] = tbl[i + 1][col - 1] - dungeon[i][col - 1];
        }
        for (int r = row - 2; r >= 0; r--){
            for (int c = col - 2; c >= 0; c--){
                if (dungeon[r][c] >= tbl[r][c + 1] || dungeon[r][c] >= tbl[r + 1][c]) tbl[r][c] = 1;
                else tbl[r][c] = min(tbl[r + 1][c], tbl[r][c + 1]) - dungeon[r][c];
            }
        }
        return tbl[0][0];
    }
};
