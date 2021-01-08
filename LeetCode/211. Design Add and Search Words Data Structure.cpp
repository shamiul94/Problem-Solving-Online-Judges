class WordDictionary {
public:
    /** Initialize your data structure here. */
    class TrieNode {
        public: 
            vector<TrieNode*> vec;
        
            bool isEndOfAWord;
            
            TrieNode(){
                isEndOfAWord = false; 
                vec = vector<TrieNode*> (27); 
            }
    }; 
    
    TrieNode* root; 
    
    WordDictionary() {
        this->root = new TrieNode(); 
    }
    
    void addWord(string word) {
        TrieNode* curr = root; 
        int i = 0; 
        int len = word.length(); 
        
        char ch; 
        while(i < len){
            ch = word[i]; 
            
            if(curr->vec[ch-'a'] == 0){
                // was empty 
                curr->vec[ch-'a'] = new TrieNode(); 
            } 
            
            curr = curr->vec[ch-'a']; 
            i++; 
        }
        curr->vec[ch-'a']->isEndOfAWord = true; 
    }
    
    bool search(string word) {
        TrieNode* curr = root; 
        int i = 0; 
        int len = word.length(); 

        return util(word, 0, root);
    }
    
    bool util(string &word, int i, TrieNode* node){
        // cout << "hi" << endl ;
        if(node==0) return false; 
        
        if(i == word.length()-1){
            return node->isEndOfAWord;
        }
    
        char ch = word[i]; 
        if(ch != '.'){
            cout << word<< ": dot e mara: " << ch << " " << ch-'a' << endl; 
            return util(word, i+1, node->vec[ch-'a']);
        } else {
            cout << word<< ": char e mara" << endl ;
            bool flag = false; 
            for(int j = 0; j < node->vec.size(); j++){
                // cout<<j << " ";
                flag = flag || util(word, i+1, node->vec[j]); 
                if (flag == true){
                    break; 
                }
            }
            return flag; 
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */