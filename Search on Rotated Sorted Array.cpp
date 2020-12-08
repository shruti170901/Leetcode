class Solution {
public:
    int search(vector<int>& arr, int key) {
        int s = 0;
        int e = arr.size()-1;
        
        while(s<=e){

		int mid = (s+e)/2;

		if(key == arr[mid]){
			return mid;
		}
		else if(arr[s]<= arr[mid]){

			if(key >= arr[s] && key<= arr[mid]){
				e = mid-1;
			}
			else {
				s = mid+1;
			}
		}
		else{
			if(key>=arr[mid] && key<=arr[e]){
				s = mid+1;
			}
			else {
				e = mid-1;
			}
		}
	}
	return -1;
    }
};
