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
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode;
    }
    
    void addWord(string word) {
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
        return dfs(0,root,word);
    }
    bool dfs(int index, TrieNode* root, string word){
        TrieNode* cur= root;
        for(int x=index; x<word.length();x++){
            if(word[x]=='.'){
                for(int j=0; j<26;j++){
                    if(cur->children[j]!=nullptr &&dfs(x+1,cur->children[j],word)){
                    return true;
                }}
                
                return false;
            }
            else{
                int i=word[x]-'a';
                if(cur->children[i]==nullptr){
                    return false;
                }
            cur=cur->children[i];
            }
            
        }
        if(cur->endWord!=true){return false;}
        return true;
    }
};
