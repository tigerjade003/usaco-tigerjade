#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

struct rule {
    int start, end, min;
};

// Fenwick Tree (Binary Indexed Tree) for range queries and updates
struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) {
        tree.assign(n + 1, 0);  // 1-indexed Fenwick Tree
    }

    // Update the Fenwick Tree at index idx by delta
    void update(int idx, int delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += idx & -idx;  // Move to parent node
        }
    }

    // Query the sum from index 1 to idx
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;  // Move to parent node
        }
        return sum;
    }

    // Query the sum from index left to right
    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int T, N, K;

signed main() {
    setIO();
    cin >> T;

    while (T--) {
        cin >> N >> K;
        vector<int> loc(N);
        vector<rule> rules(K);
        set<int> compressed;

        // Read locations of trees
        for (int i = 0; i < N; i++) {
            cin >> loc[i];
            compressed.insert(loc[i]);
        }

        // Read the rules
        for (int i = 0; i < K; i++) {
            int a, b, x;
            cin >> a >> b >> x;
            rules[i] = {a, b, x};
            compressed.insert(a);
            compressed.insert(b);
        }

        // Compress the coordinates of the trees and rules
        vector<int> nums(compressed.begin(), compressed.end());
        map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++) {
            mapp[nums[i]] = i + 1;  // 1-indexed for Fenwick Tree
        }

        // Map locations to compressed coordinates
        for (int i = 0; i < N; i++) {
            loc[i] = mapp[loc[i]];
        }

        // Initialize Fenwick Tree for rule counting
        FenwickTree fenwick(nums.size());

        // Set up how many trees satisfy each rule
        vector<vector<int>> add(nums.size() + 1);
        vector<vector<int>> remove(nums.size() + 1);

        // Fill add/remove information for the rules
        for (int i = 0; i < K; i++) {
            rules[i].start = mapp[rules[i].start];
            rules[i].end = mapp[rules[i].end];
            add[rules[i].start].push_back(i);
            remove[rules[i].end + 1].push_back(i);
        }

        // Maintain current rule fulfillments using Fenwick Tree
        vector<int> howmany(K, 0);  // Declare howmany to track the number of trees satisfying each rule

        // Precompute the impact of each tree on rules
        for (int i = 0; i < N; i++) {
            for (int j : add[loc[i]]) {
                howmany[j]++;  // Increment how many trees fulfill the rule
            }
        }

        // Sort trees based on the number of rules they help fulfill (descending)
        vector<pair<int, int>> trees;
        for (int i = 0; i < N; i++) {
            trees.push_back({howmany[i], loc[i]});
        }
        sort(trees.begin(), trees.end(), greater<pair<int, int>>());

        // Now, greedily choose trees to remove based on their impact
        int ans = 0;
        vector<bool> isup(N, true);

        // Iterate over the sorted trees
        for (auto &[impact, treeLoc] : trees) {
            int treeIndex = treeLoc;

            // If this tree is currently fulfilling no rule, we remove it
            if (impact == 0) {
                ans++;
                continue;
            }

            int minleeway = INT_MAX;

            // Check the minimum leeway for the rules affected by this tree
            for (int ruleIndex : add[treeLoc]) {
                minleeway = min(minleeway, howmany[ruleIndex] - rules[ruleIndex].min);
            }

            // If this tree is helpful, we "cut" it and update the rule fulfillments
            if (minleeway > 0) {
                for (int ruleIndex : add[treeLoc]) {
                    howmany[ruleIndex] -= 1;  // Update the count for rules
                }
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
