class Solution {
public:
    struct TrieNode {
        int children[26];
        int bestIdx; // index of best string in wordsContainer
        TrieNode() {
            fill(children, children + 26, -1);
            bestIdx = -1;
        }
    };
    
    vector<TrieNode> trie;
    
    void insert(const string& word, int idx, vector<string>& wordsContainer) {
        int node = 0;
        // Update bestIdx at root considering this word
        auto isBetter = [&](int newIdx, int curIdx) {
            if (curIdx == -1) return true;
            int newLen = wordsContainer[newIdx].size();
            int curLen = wordsContainer[curIdx].size();
            return newLen < curLen || (newLen == curLen && newIdx < curIdx);
        };
        
        if (isBetter(idx, trie[node].bestIdx))
            trie[node].bestIdx = idx;
        
        for (char c : word) {
            int ch = c - 'a';
            if (trie[node].children[ch] == -1) {
                trie[node].children[ch] = trie.size();
                trie.push_back(TrieNode());
            }
            node = trie[node].children[ch];
            if (isBetter(idx, trie[node].bestIdx))
                trie[node].bestIdx = idx;
        }
    }
    
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(TrieNode()); // root
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            string rev = wordsContainer[i];
            reverse(rev.begin(), rev.end());
            insert(rev, i, wordsContainer);
        }
        
        vector<int> ans;
        for (auto& q : wordsQuery) {
            string rev = q;
            reverse(rev.begin(), rev.end());
            
            int node = 0;
            for (char c : rev) {
                int ch = c - 'a';
                if (trie[node].children[ch] == -1) break;
                node = trie[node].children[ch];
            }
            ans.push_back(trie[node].bestIdx);
        }
        return ans;
    }
};
