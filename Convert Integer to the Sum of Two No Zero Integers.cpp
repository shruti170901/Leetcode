class Solution {
public:

	bool containsZero(int n){

		while(n){
			if(n%10 == 0) return false;
			n = n/10;
		}

		return true;
	}

	vector<int> getNoZeroIntegers(int n) {

		vector<int> ans(2,-1);

		for(int i=1;i<=n;i++){

			if(containsZero(i) && containsZero(n-i)){
				ans[0] = i;
				ans[1] = n-i;
				break;
			}

		}

		return ans;
	}