struct Tree {  
    vector<int> parent, tin, tout, order; 
    vector<vector<int>> first;  

    Tree(int n, vector<vector<int>>& edges) : parent(n), tin(n), tout(n) {
        vector<int> head(n + 1), adj(2 * n); 
        for (auto& e : edges) head[e[0] + 1]++, head[e[1] + 1]++;
        partial_sum(head.begin(), head.end(), head.begin());
        vector<int> pos(head.begin(), head.end() - 1);
        for (auto& e : edges) adj[pos[e[0]]++] = e[1], adj[pos[e[1]]++] = e[0];

        vector<int> stack = {0};
        while (!stack.empty()) {  
            int x = stack.back();
            stack.pop_back();
            if (x < 0) {
                tout[~x] = order.size();
                continue;
            }
            tin[x] = order.size();
            order.push_back(x);
            stack.push_back(~x);
            for (int i = head[x]; i < head[x + 1]; i++)
                if (int y = adj[i]; y != parent[x]) {
                    parent[y] = x;
                    stack.push_back(y);
                }
        }

        first.emplace_back(n);
        for (int i = 0; i < n; i++) first[0][i] = tin[parent[order[i]]];
        for (int k = 1; 1 << k <= n; k++) {
            first.emplace_back(n - (1 << k) + 1);
            for (int i = 0; i + (1 << k) <= n; i++) first[k][i] = min(first[k - 1][i], first[k - 1][i + (1 << (k - 1))]);
        }
    }

    int lca(int u, int v) { 
        if (u == v) return u;
        auto [l, r] = minmax(tin[u], tin[v]);
        int k = bit_width(unsigned(r - l)) - 1;
        return order[min(first[k][l + 1], first[k][r - (1 << k) + 1])];
    }
};

struct RootPaths { 
    Tree& tree;
    vector<int> start, fenwick;  

    RootPaths(Tree& tree, vector<int>& bit) : tree(tree), start(bit), fenwick(bit.size() + 1) {
        for (int x : tree.order)  
            if (x != tree.parent[x]) start[x] ^= start[tree.parent[x]];
    }

    void flip(int x, int d) { 
        for (int i : {tree.tin[x] + 1, tree.tout[x] + 1})   
            for (; i < (int)fenwick.size(); i += i & -i) fenwick[i] ^= d;
    }

    int operator[](int x) {
        int mask = start[x];
        for (int i = tree.tin[x] + 1; i > 0; i -= i & -i) mask ^= fenwick[i];
        return mask;
    }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        Tree tree(n, edges);
        vector<int> bit(n); 
        for (int x = 0; x < n; x++) bit[x] = 1 << (s[x] - 'a');
        RootPaths paths(tree, bit);

        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 'u') {  
                int x = number(q, 7), newBit = 1 << (q.back() - 'a');
                paths.flip(x, bit[x] ^ newBit);  
                bit[x] = newBit;
            } else {  
                int u = number(q, 6), v = number(q, q.rfind(' ') + 1);
                int mask = paths[u] ^ paths[v] ^ bit[tree.lca(u, v)];  
                ans.push_back(popcount(unsigned(mask)) <= 1);  
            }
        }
        return ans;
    }

private:
    static int number(const string& q, int i) { 
        int x = 0;
        for (; i < (int)q.size() && isdigit(q[i]); i++) x = x * 10 + (q[i] - '0');
        return x;
    }
};