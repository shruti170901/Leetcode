class Solution {
public:
    int kthFactor(int n, int k) 
    {  
        vector<int> v;
        int count=0;
        for (int i=1; i<=sqrt(n); i++) 
        { 
            if (n%i == 0) 
            { 
                count++;
                if (n/i == i){
                    v.push_back(i);
                }

                else {
                    v.push_back(i);
                    v.push_back(n/i);
                    //printf("%d %d ", i, n/i);
                }
            } 
        }
        sort(v.begin(),v.end());
        if(k<=v.size())return v[k-1];
        else return -1;
    } 
};
