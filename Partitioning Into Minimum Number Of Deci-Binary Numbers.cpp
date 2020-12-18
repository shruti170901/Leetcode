class Solution {
public:
    int minPartitions(string n) {
    	int max = 0;
        for (int i = 0; i < n.length(); ++i)
        {
        	int x = int(n[i])-48;
        	max = (x>max)?x:max;
        }
        return max;
    }
};