/*Immediately return false if the length of A and B differ or if A equals B and A is comprised of all unique chars such that a swap of the same character at different positions in the string cannot be performed.

Let j and k be the candidate swap indices where A[j] != B[j] and A[k] != B[k]. Return true if and only if A equals B after swapping the characters A[j] and A[k].*/

class Solution {
public:
    using Set = unordered_set<char>;
    bool buddyStrings(string A, string B) {
        int M = A.size(),
            N = B.size();
        if (M != N)
            return false;
        if (A == B)
            return Set{ A.begin(), A.end() }.size() < N;
        auto j = -1,
             k = -1;
        for (auto i{ 0 }; i < N; ++i)
            if (A[i] != B[i])
                j = k, k = i;
        if (j == -1 || k == -1)
            return false;
        swap(A[j], A[k]);
        return A == B;
    }
};
