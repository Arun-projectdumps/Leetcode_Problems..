
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;
    int m, n;

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node) {
        char c = board[i][j];

        if (c == '#' || !node->children[c - 'a'])
            return;

        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = ""; // Avoid duplicates
        }

        board[i][j] = '#';

        if (i > 0) dfs(board, i - 1, j, node);
        if (j > 0) dfs(board, i, j - 1, node);
        if (i + 1 < m) dfs(board, i + 1, j, node);
        if (j + 1 < n) dfs(board, i, j + 1, node);

        board[i][j] = c; // Backtrack
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        for (string& word : words)
            insert(word);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};
