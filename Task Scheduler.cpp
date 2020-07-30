class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        for (const auto& task : tasks)
            ++v[task - 'A'];
        sort(v.begin() , v.end() , [](int a , int b){return a > b;});
        int most = 1;
        for (auto i = 1 ; i < v.size() ; ++i){
            if (v[i] < v[i-1]) break;
            ++most;
        }
        return max((v[0]-1) * (n+1) + most , (int)tasks.size());
    }
};
