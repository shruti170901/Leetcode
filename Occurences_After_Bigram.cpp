class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream s(text); 
	    string word; 
	    vector<string> st;
	    while (s >> word){ 
         st.push_back(word);
        } 
        vector<string> res;
        for(int i=0;i<st.size();i++)
            if(st[i]==first && st[i+1]==second)
                if(i+2<st.size())
                    res.push_back(st[i+2]);
        return res;
    }
};

