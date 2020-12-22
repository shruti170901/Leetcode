class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();

        //using a map to aggregate the duplication
        unordered_map<int, int> rec;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                rec[A[i] & A[j]]++;
            }
        }

        int result = 0;
        for (auto &r : rec ) {
            for (int k=0; k<n; k++) {
                if ((r.first & A[k]) == 0) result+=r.second;
            }
        }
        return result;
    }

};
