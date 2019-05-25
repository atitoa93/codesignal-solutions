// https://app.codesignal.com/interview-practice/task/Ki9zRh5bfRhH6oBau

struct TrieNode {
    vector <pair <int, int> > idxs;
    unordered_map <char, TrieNode*> children;
};

void insert(TrieNode *root, string word, int wordIdx, int charIdx) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); ++i) {
        TrieNode *newNode = cur->children[word[i]];
        if (!newNode) {
            newNode = new TrieNode();
            cur->children[word[i]] = newNode;
        }
        newNode->idxs.push_back(make_pair(wordIdx, charIdx + i));
        cur = newNode;
    }
}

vector <pair <int, int> > search(TrieNode *root, string word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); ++i) {
        TrieNode *node = cur->children[word[i]];
        if (!node) return vector <pair <int, int> >();
        cur = node;
    }
    return cur->idxs;
}

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    int n = words.size();
    int m = parts.size();

    TrieNode *root = new TrieNode();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            insert (root, words[i].substr(j), i, j);
        }
    }

    vector <pair <int, int> > sol(n, make_pair(INT_MAX, 0));
    
    for (int i = 0; i < m; ++i) {
        vector <pair <int, int> > idxs = search(root, parts[i]);
        
        int partLen = parts[i].size();
        for (int j = 0; j < idxs.size(); ++j) {
            int wordIdx = idxs[j].first;
            int charIdx = idxs[j].second - partLen + 1;
            int &curWordStartIdx = sol[wordIdx].first;
            int &curWordMaxLen = sol[wordIdx].second;

            if (curWordMaxLen < partLen || (curWordMaxLen == partLen && charIdx < curWordStartIdx)) {
                curWordMaxLen = partLen;
                curWordStartIdx = charIdx;
            }
        }
    }

    vector <string> ret = words;
    for (int i = 0; i < n; ++i) {
        if (sol[i].second) {
            ret[i].insert(sol[i].first, "[");
            ret[i].insert(sol[i].first + sol[i].second + 1, "]");
        }
    }

    return ret;
}
