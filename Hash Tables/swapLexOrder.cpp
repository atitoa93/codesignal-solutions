// https://app.codesignal.com/interview-practice/task/5vXzdE9yzjsoMZ9sk

void dfs(vector <vector <int>> &adj, vector <bool> &vis, int node, vector <int> &idxs) {
    if (vis[node]) return;
    vis[node] = 1;
    
    idxs.push_back(node);
    
    for (int i = 0; i < adj[node].size(); ++i) {
        dfs(adj, vis, adj[node][i], idxs);
    }
}
 
std::string swapLexOrder(std::string str, std::vector<std::vector<int>> pairs) {
    vector <vector <int>> adj(str.size(), vector <int> ());
    for (int i = 0; i < pairs.size(); ++i) {
        adj[pairs[i][0] - 1].push_back(pairs[i][1] - 1);
        adj[pairs[i][1] - 1].push_back(pairs[i][0] - 1);
    }
    
    string ret = str;
    
    vector <bool> vis(str.size());
    for (int i = 0; i < str.size(); ++i) {
        if (!vis[i]) {
            vector <int> idxs;
            dfs(adj, vis, i, idxs);
            vector <char> chrs;
            for (int i = 0; i < idxs.size(); ++i) {
                chrs.push_back(str[idxs[i]]);
            }
            sort(idxs.begin(), idxs.end());
            sort(chrs.begin(), chrs.end());
            for (int i = 0; i < chrs.size(); ++i) {
                ret[idxs[i]] = chrs[chrs.size() - 1 - i];
            }
        }
    }
    
    return ret;
}
