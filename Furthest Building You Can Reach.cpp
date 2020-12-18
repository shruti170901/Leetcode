/*problem link:-
 https://leetcode.com/problems/furthest-building-you-can-reach/
*/ 
class Solution {

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        // Special case. If there is no bricks and no ladders,
        // the result is the lenght of the longest non-decreasing sub list.
        if (bricks == 0 && ladders == 0) {
            size_t k = 0;

            while (k < heights.size() - 1) {
                if (heights[k] >= heights[k+1]) {
                    ++k;
                } else {
                    return k;
                }
            }
            return k;
        }

        size_t k = 0;
        int remainingBricks = bricks;
        int remainingLadders = ladders;

        // Uss a priority queue to keep the largest cost.
        // The cost is the number of bricks we need to jumpt to next building.
        priority_queue<int> q{};

        while (remainingBricks + remainingLadders > 0) {

            if (k == heights.size() - 1) {
                return k;
            }

            int cost = heights[k+1] - heights[k];

            if (cost < 0) {
                // We don't need to do anything. Just move to the next building.
                ++k;
            } else if (cost <= remainingBricks) {
                // If we have enough bricks, use them and move forward.
                remainingBricks -= cost;
                q.push(cost);
                ++k;
            } else {
                // In this case, we don't have enough bricks.

                if (q.empty()) { // we haven't used any bricks
                    if (remainingLadders > 0) {
                        --remainingLadders;
                        ++k;
                    } else {
                        // if we don't have ladders, then we cannot move forward.
                        return k;
                    }
                } else {
                    // replace the bricks with a ladder.
                    int potentialRefund = q.top();

                    if (potentialRefund <= cost && remainingLadders > 0) {
                        --remainingLadders;
                        ++k;
                    } else {
                        // We need to use a ladder to replace some bricks.
                        while (remainingLadders > 0 && cost > remainingBricks) {
                            int refund = q.top();
                            q.pop();
                            --remainingLadders;
                            remainingBricks += refund;
                        }

                        if (remainingLadders == 0 && cost > remainingBricks) {
                            return k;
                        }
                    }
                }
            }
        }
        return k;
    }
};