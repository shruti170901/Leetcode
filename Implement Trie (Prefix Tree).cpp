// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    /** Initialize your data structure here. */
    typedef struct node{
        char c;
        vector<node*> v;
    } Node;
    Node* root=new Node;
    Trie() {
       root->c='A';
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *t2=root, *te;
        vector<Node*>::iterator t1;
        te=new Node;
        te->c=0;
        int idx=0;
        while(1){
            int flag=0;
            for(t1=t2->v.begin(); t1!=t2->v.end();t1++){
                if((*t1)->c==word[idx]){
                    flag=1;
                    break;
                }
            }
            if(flag==0) break;
            idx++;
            if(idx==word.size()){
                (*t1)->v.push_back(te);
                break;
            }
            t2=*t1;   
        }
        while(idx<word.size()){
            Node* it=new Node;
            it->c=word[idx];
            t2->v.push_back(it);
            idx++;
            if(idx==word.size()){
                it->v.push_back(te);
            }
            t2=it;
        }
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *t2=root;
        vector<Node*>::iterator t1;
        int idx=0, n=word.size();
        while(idx<n){
            for(t1=t2->v.begin(); t1!=t2->v.end();t1++){
                if((*t1)->c==word[idx]){
                    break;
                }
            }
            if(t1==t2->v.end()) return false;
            idx++;
            t2=*t1;
        }
        for(t1=t2->v.begin(); t1!=t2->v.end();t1++){
            if((*t1)->c==0) return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
         Node *t2=root;
        vector<Node*>::iterator t1;
        int idx=0, n=word.size();
        while(idx<n){
            for(t1=t2->v.begin(); t1!=t2->v.end();t1++){
                if((*t1)->c==word[idx]){
                    //cout<<word[idx]<<endl;
                    break;
                }
            }
            if(t1==t2->v.end()) return false;
            idx++;
            t2=*t1;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */