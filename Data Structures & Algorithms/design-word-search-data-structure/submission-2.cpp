class WordDictionary {
public:

    struct TrieNode{
        TrieNode* children[26];
        bool word = false;
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c:word) {
            if(!cur->children[c-'a']) cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* cur = root;
        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if(c != '.') {
                if(!cur->children[c-'a']) return false;
                cur = cur->children[c-'a'];
            }
            else {
                for(TrieNode* child:cur->children) {
                    if(child && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return cur->word;
    }
};
