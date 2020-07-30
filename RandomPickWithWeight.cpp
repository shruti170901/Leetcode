class Solution 
{
private:
    vector<int> temp;
    int sum;
public:
    Solution(vector<int> w) {
        srand(time(NULL));
        sum = 0;
        vector<int>::iterator itr;
        for (itr = w.begin(); itr < w.end(); itr++) {
            int weight = *itr;
            sum += weight;
            temp.push_back(sum);
        }
    }

    int pickIndex() {
        int x = rand() % sum;
        int left = 0, right = temp.size() - 1;
        while (left < right) {
            int mid = (left+right)/2;
            if (temp[mid] <= x) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
