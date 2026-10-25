class TrieNode{
    public:
        TrieNode* children[26];
        bool endWord;
        TrieNode(){
            for( int i =0; i<26;i++){
                children[i]=nullptr;
            }
            endWord=false;
        }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root=new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* cur= root;
        for(char w:word){
            int i=w-'a';
            if(cur->children[i]==nullptr){
                cur->children[i]= new TrieNode();
            }
            cur=cur->children[i];
        }
        cur->endWord=true;
    }
    
    bool search(string word) {
         TrieNode* cur= root;
        for(char w:word){
            int i=w-'a';
            if(cur->children[i]==nullptr){
                return false;
            }
            cur=cur->children[i];
        }
        if(cur->endWord==true){return true;}
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur= root;
        for(char w:prefix){
            int i=w-'a';
            if(cur->children[i]==nullptr){
                return false;
            }
            cur=cur->children[i];
        }
        //if(cur->endWord==true){return false;}
        return true;
    }
};
