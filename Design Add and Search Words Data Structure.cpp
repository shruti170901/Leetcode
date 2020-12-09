// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    typedef struct node{
        bool end;
        node* v[26];
    } Node;
    
    Node* init(){
        Node* ans=new Node;
        ans->end=false;
        memset(ans->v, NULL, sizeof(ans->v));
        return ans;
    }
    Node* root=init();
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        //cout<<word<<endl;
        Node *t2=root;
        int idx=0, n=word.size();
        while(idx<n){
            if((t2->v)[word[idx]-'a']!=NULL){
                //cout<<word[idx]-'a'<<" .. ";
                t2=(t2->v)[word[idx]-'a'];
                idx++;
                //cout<<"Here\n";
            }
            else break;
        }
        while(idx<n){
            (t2->v)[word[idx]-'a']=init();
            t2=(t2->v)[word[idx]-'a'];
            idx++;
        }
        t2->end=true;
        return;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool sear(string& word, Node* r, int idx){
        int i, n=word.size();
        Node* temp;
        if(word[idx]!='.'){
            temp=(r->v)[word[idx]-'a'];
            if(temp==NULL) return false;
            if(idx==n-1) return temp->end;
            return sear(word, temp, idx+1);
        }
        else{
            bool ans=false;
            for(i=0;i<26;i++){
                if((r->v)[i]!=NULL){
                    if(idx==n-1){
                        if((r->v)[i]->end) return true;
                    }
                    else{
                        ans|=sear(word, (r->v)[i], idx+1);
                    }
                }
            }
            return ans;
        }
    }
    bool search(string word) {
        //cout<<word<<endl;
        return sear(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */