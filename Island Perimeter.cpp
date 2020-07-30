class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int perimeter = 0;
        int ros = grid.size();
        int cos = grid[0].size();
        for (int r = 0; r < ros; ++r) {
            for (int c = 0; c < cos; ++c) {
                if (grid[r][c]) {
                    if (r == 0 || !grid[r-1][c]) ++perimeter;
                    if ((r == ros - 1) || !grid[r+1][c]) ++perimeter;
                    if ((c == cos - 1) || !grid[r][c+1]) ++perimeter;
                    if ((c == 0) || (!grid[r][c-1])) ++perimeter;
                }
            }
        }
        return perimeter;
    }
};
