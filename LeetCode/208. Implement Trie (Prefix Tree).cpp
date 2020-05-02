// original - mock interview - 50%, 50%

class Trie {
public:

    bool endmark;
    Trie *next[26];

    /** Initialize your data structure here. */
    Trie() {
        endmark = false;
        for (int i = 0; i < 26; i++) {
            next[i] = 0;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *curr = this;
        for (int i = 0; i < word.length(); i++) {
            int id = word[i] - 'a';
            if (curr->next[id] == NULL) {
                curr->next[id] = new Trie();
            }
            curr = curr->next[id];
        }
        curr->endmark = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *curr = this;
        for (int i = 0; i < word.length(); i++) {
            int id = word[i] - 'a';
            if (curr->next[id] != NULL) {
                curr = curr->next[id];
            } else {
                return false;
            }
        }
        return curr->endmark;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Trie *curr = this;
        for (int i = 0; i < word.length(); i++) {
            int id = word[i] - 'a';
            if (curr->next[id] != NULL) {
                curr = curr->next[id];
            } else {
                return false;
            }
        }
        // return curr->endmark;
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

// With destructor
// performance degrades.

class Trie2 {
public:

    bool endmark;
    Trie** next;

    /** Initialize your data structure here. */
    Trie() {
        endmark = false;
        next = new Trie*[26];
        for(int i = 0 ; i < 26; i++){
            next[i] = NULL;
        }
    }

    // ~Trie(){
    //     delete[] next;
    // }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for(int i = 0 ; i < word.length(); i++){
            int id = word[i] - 'a';
            if(curr->next[id] == NULL){
                curr->next[id] = new Trie();
            }
            curr = curr->next[id];
        }
        curr->endmark = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        for(int i = 0 ; i < word.length(); i++){
            int id = word[i]-'a';
            if(curr->next[id] != NULL){
                curr = curr->next[id];
            } else {
                return false;
            }
        }
        return curr->endmark;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Trie* curr = this;
        for(int i = 0 ; i < word.length(); i++){
            int id = word[i]-'a';
            if(curr->next[id] != NULL){
                curr = curr->next[id];
            } else {
                return false;
            }
        }
        // return curr->endmark;
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
