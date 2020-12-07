class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {    
        // check possibility
        bool isA = true, isB = true;
        for (int i = 1; i < A.size(); i ++) {
            if (A[0] != A[i] && A[0] != B[i]) {
                isA = false;
                break;
            }
        }
        for (int i = 1; i < A.size(); i ++) {
            if (B[0] != A[i] && B[0] != B[i]) {
                isB = false;
                break;
            }
        }
        if (!isA && !isB) return -1;
        
        // find minRotation
        int rotateA = INT_MAX, rotateB = INT_MAX;
        if (isA) {
            int rotateA1 = 0;
            int rotateA2 = 0;
            for (int i = 0; i < A.size(); i ++) {
                if (A[i] != A[0]) rotateA1 ++;
                if (B[i] != A[0]) rotateA2 ++;
            }
            rotateA = min(rotateA1, rotateA2);
        }
        if (isB) {
            int rotateB1 = 0;
            int rotateB2 = 0;
            for (int i = 0; i < A.size(); i ++) {
                if (B[i] != B[0]) rotateB1 ++;
                if (A[i] != B[0]) rotateB2 ++;
            }
            rotateB = min(rotateB1, rotateB2);
        }
        
        return min(rotateA, rotateB);
    }
};
