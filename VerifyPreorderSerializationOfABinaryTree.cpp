class Solution {
public:
    
    bool isValidSerialization(string preorder) {
        vector<string> list;
        split(preorder, ',', list);
        //we initailize the counter as 1, 
        //because we expect at lease 1 node in the tree.
        int node_expected = 1;
        for (auto node : list) {
            if (node_expected == 0) return false;
            node == "#" ? node_expected-- : node_expected++;
        }
        return node_expected == 0;
    }
    
    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
};
