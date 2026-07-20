class Solution {
public:

    vector<string> output;

    struct TrieNode{
        TrieNode* children[26];
        bool isEnd = false;
        bool used = false;
        string word;
    };

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int n, int m, TrieNode* cur) {
        visited[i][j] = true;

        if(cur->isEnd && !cur->used) {
            output.push_back(cur->word);
            cur->used = true;
        }

        if(i > 0 && cur->children[board[i-1][j] - 'a'] && !visited[i-1][j]) {
            dfs(board, visited, i-1, j, n, m, cur->children[board[i-1][j] - 'a']);
        }
        if(i < n - 1 && cur->children[board[i+1][j] - 'a'] && !visited[i+1][j]) {
            dfs(board, visited, i+1, j, n, m, cur->children[board[i+1][j] - 'a']);
        }
        if(j > 0 && cur->children[board[i][j-1] - 'a'] && !visited[i][j-1]) {
            dfs(board, visited, i, j-1, n, m, cur->children[board[i][j-1] - 'a']);
        }
        if(j < m - 1 && cur->children[board[i][j+1] - 'a'] && !visited[i][j+1]) {
            dfs(board, visited, i, j+1, n, m, cur->children[board[i][j+1] - 'a']);
        }
        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // create a trie with the list of words we are searching for
        // loop through each position in the grid, that is a starting 
        // point. run the dfs function, that has its own visited for
        // each point. then visit the nearby positions if its in the 
        // trie, part of a word. keep going until is a word or give up
        // if a word is successful we must mark all the letter 
        // positions as visited in the global visited array

        int n = board.size();
        int m = board[0].size();

        TrieNode* root = new TrieNode();

        for(string word : words) {
            TrieNode* cur = root;
            for(char c : word) {
                if(!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
            cur->isEnd = true;
            cur->word = word;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(root->children[board[i][j] - 'a']) {
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    dfs(board, visited, i, j, n, m, root->children[board[i][j] - 'a']);

                }
            }
        }
        return output;
    }
};
