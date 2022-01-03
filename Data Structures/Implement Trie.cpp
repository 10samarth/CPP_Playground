class Node{
public:
    bool HasValue;
    Node** Children;
    
    Node(){
        Children = new Node*[26]();
        HasValue = false;
    }
    
    ~Node(){
        for(int i=0; i<26; i++){
            delete Children[i];
        }
        
        delete[] Children;
    }
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        getNode(word,true)->HasValue = true;
    }
    
    bool search(string word) {
        Node* pNode = getNode(word,false);
        return (pNode != NULL && pNode->HasValue);
    }
    
    bool startsWith(string prefix) {
        return (getNode(prefix,false)!=NULL);
    }
private:
    Node* root;
    
    Node* getNode(const string& word, bool create){
        Node* pNode = root;
        int id = 0;
        int n = word.size();
        for(int i = 0; i<n ; i++){
            id = word[i]-'a';
            if(pNode->Children[id] == NULL){
                if(create)
                    pNode->Children[id] = new Node();
                else
                    return NULL;
            }
            pNode = pNode->Children[id];
        }
        
        return pNode;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */