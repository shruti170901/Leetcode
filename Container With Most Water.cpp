class Solution {
public:
    int maxArea(vector<int>& h) {
        int mx=0, i=0, j=h.size()-1, temp;
        while(i<j){
            int temp=min(h[i], h[j])*(j-i);
            if(temp>mx) mx=temp;
            if(h[i]<h[j]) i++;
            else j--;
        }
        return mx;
    }
};