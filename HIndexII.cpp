class Solution {
public:
  int hIndex(vector<int>& citations) {
        int n = citations.size();
        int i = 0, j = n-1;
        while (i <= j) {
            int m = (i+j) / 2;
            if (citations[m] >= n-m)
                j = m-1;
            else
                i = m+1;
        }
        return n-i;
    }
};
