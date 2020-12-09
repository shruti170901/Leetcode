// https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator {
public:
    string sup;
    int i, j, len, n;
    int *idx;
    bool nex=true;
    CombinationIterator(string characters, int combinationLength) {
        sup=characters;
        n=sup.size();
        len=combinationLength;
        idx=new int[len];
        for(i=0;i<len;i++){
            idx[i]=i;
        }
    }
    
    string next() {
        string temp="";
        for(i=0;i<len;i++){
            temp+=sup[idx[i]];
        }
        j=len-1;
        while(j>=0 && idx[j]==n-len+j) j--;
        if(j>=0){
            idx[j]++;
            j++;
            while(j<len){
                idx[j]=idx[j-1]+1;
                j++;
            }
        }
        else nex=false;
        return temp;
        
    }
    
    bool hasNext() {
        return nex;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */