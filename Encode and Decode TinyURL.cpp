// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
public:
    vector<string> v;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        v.push_back(longUrl);
        int t=v.size();
        string s="";
        while(t){
            s+='0'+t%10;
            t/=10;
        }
        return "http://tinyurl.com"+s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i=18, t=0;
        while(i<shortUrl.size()){
            t=t*10+shortUrl[i]-'0';
            i++;
        }
        return v[t-1];
    
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));