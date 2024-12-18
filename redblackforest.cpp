#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;

struct Restriction {
    int l, r, t; 
};

int solveTestCase(int n, int k, vector<int>& positions, vector<Restriction>& restrictions) {

    sort(positions.begin(), positions.end());

    vector<int> protected_trees(n, 0);

    for (auto& res : restrictions) {

        auto start_it = lower_bound(positions.begin(), positions.end(), res.l);
        auto end_it = upper_bound(positions.begin(), positions.end(), res.r);

        int start_idx = start_it - positions.begin();
        int end_idx = end_it - positions.begin() - 1;

        int already_protected = accumulate(protected_trees.begin() + start_idx, protected_trees.begin() + end_idx + 1, 0);

        int needed = res.t - already_protected;
        if (needed > 0) {
            for (int i = start_idx; i <= end_idx && needed > 0; i++) {
                if (protected_trees[i] == 0) {
                    protected_trees[i] = 1;
                    needed--;
                }
            }
        }
    }

    int total_protected = accumulate(protected_trees.begin(), protected_trees.end(), 0);

    return n - total_protected;
}

int main() {
    int T;
    cin >> T;

    vector<int> results;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> positions(n);
        for (int i = 0; i < n; i++) {
            cin >> positions[i];
        }

        vector<Restriction> restrictions(k);
        for (int i = 0; i < k; i++) {
            cin >> restrictions[i].l >> restrictions[i].r >> restrictions[i].t;
        }

        results.push_back(solveTestCase(n, k, positions, restrictions));
    }
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
