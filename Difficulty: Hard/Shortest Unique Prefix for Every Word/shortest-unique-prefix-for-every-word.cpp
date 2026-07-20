class Solution {
  public:
    
    struct TrieNode {
        TrieNode* child[26];
        int count;

        TrieNode() {
            count = 0;
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    TrieNode* root = new TrieNode();

    // Insert a word into Trie
    void insert(string &word) {
        TrieNode* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
            node->count++;
        }
    }

    // Find shortest unique prefix
    string getPrefix(string &word) {
        TrieNode* node = root;
        string prefix = "";

        for(char ch : word) {
            int idx = ch - 'a';
            node = node->child[idx];
            prefix += ch;

            if(node->count == 1)
                return prefix;
        }

        return prefix;
    }

    vector<string> findPrefixes(vector<string>& arr) {

        // Step 1: Insert all words into Trie
        for(string &word : arr)
            insert(word);

        // Step 2: Find shortest unique prefix for each word
        vector<string> ans;

        for(string &word : arr)
            ans.push_back(getPrefix(word));

        return ans;
    }
};