// https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int arr[26]={0};
        for(auto it:tiles) arr[it-'A']++;
        int ans=0;
        cnt(arr, ans);
        return ans;
    }
    
    void cnt(int arr[], int &ans){
        for(int i=0;i<26;i++){
            if(arr[i]){
                arr[i]--;
                ans++;
                cnt(arr, ans);
                arr[i]++;
            }
        }
        return;
    }
};