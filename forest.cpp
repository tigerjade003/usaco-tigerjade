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
            mapp[nums[i]] = i + 1;  // 1-indexed for ease of use
        }

        // Map locations to compressed coordinates
        for (int i = 0; i < N; i++) {
            loc[i] = mapp[loc[i]];
        }

        // Initialize rule contribution for each tree
        vector<int> ruleImpact(K, 0);
        vector<int> treeImpact(N, 0);

        // Track which rules each tree affects
        vector<vector<int>> affectedRules(N);

        for (int i = 0; i < K; i++) {
            // Mark all trees affected by each rule
            for (int j = 0; j < N; j++) {
                if (loc[j] >= mapp[rules[i].start] && loc[j] <= mapp[rules[i].end]) {
                    affectedRules[j].push_back(i);
                    ruleImpact[i]++;
                }
            }
        }

        // Sort trees based on how many rules they help fulfill (descending)
        vector<pair<int, int>> trees;  // (impact, treeIndex)
        for (int i = 0; i < N; i++) {
            trees.push_back({affectedRules[i].size(), i});
        }
        sort(trees.begin(), trees.end(), greater<pair<int, int>>());

        // Greedily remove trees
        int removedTrees = 0;
        vector<bool> isTreeRemoved(N, false);

        for (auto &[impact, treeIndex] : trees) {
            if (impact == 0) {
                break;
            }

            // Check if we can remove this tree without violating any rules
            bool canRemove = true;
            for (int ruleIndex : affectedRules[treeIndex]) {
                if (ruleImpact[ruleIndex] <= rules[ruleIndex].min) {
                    canRemove = false;
                    break;
                }
            }

            if (canRemove) {
                // Remove the tree and update rule impact
                isTreeRemoved[treeIndex] = true;
                removedTrees++;

                // Update the rule impacts (decrease for the affected rules)
                for (int ruleIndex : affectedRules[treeIndex]) {
                    ruleImpact[ruleIndex]--;
                }
            }
        }

        cout << removedTrees << endl;
    }

    return 0;
}
