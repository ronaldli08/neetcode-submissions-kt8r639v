class PrefixTree {
public:

    struct TrieNode {
        TrieNode* children[26];

        bool isEnd;
    };

    TrieNode* bigWord;

    PrefixTree() {
        bigWord = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = bigWord;
        for(char c:word) {
            if(!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = bigWord;
        for(char c:word) {
            if(!cur->children[c-'a']) {
                return false;
            }
            else {
                cur = cur->children[c-'a'];
            }
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = bigWord;
        for(char c:prefix) {
            if(!cur->children[c-'a']) {
                return false;
            }
            else {
                cur = cur->children[c-'a'];
            }
        }
        return true;
    }
};
