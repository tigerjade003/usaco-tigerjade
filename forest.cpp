#include <bits/stdc++.h>
using namespace std;
#define int long long

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

struct SegmentTree {
    vector<int> tree, stuff;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n, 0);
        stuff.assign(4 * n, 0);
    }

    void builds(int node, int start, int end, int val) {
        tree[node] += (end - start + 1) * val;
        stuff[node] += val;
    }

    void add(int node, int start, int end) {
        if (stuff[node] != 0) {
            int mid = (start + end) / 2;
            builds(2 * node, start, mid, stuff[node]);
            builds(2 * node + 1, mid + 1, end, stuff[node]);
            stuff[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            builds(node, start, end, val);
            return;
        }
        add(node, start, end);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        add(node, start, end);
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }
};

signed main() {
    setIO();
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<int> positions(N);
        vector<tuple<int, int, int>> constraints(K);
        set<int> coords;
        for (int i = 0; i < N; i++) {
            cin >> positions[i];
            coords.insert(positions[i]);
        }
        for (int i = 0; i < K; i++) {
            int a, b, x;
            cin >> a >> b >> x;
            constraints[i] = {a, b, x};
            coords.insert(a);
            coords.insert(b);
        }
        map<int, int> coordIndex;
        int index = 0;
        for (int coord : coords) {
            coordIndex[coord] = index++;
        }
        int compressedSize = index;
        SegmentTree segTree(compressedSize);
        for (int pos : positions) {
            segTree.update(1, 0, compressedSize - 1, coordIndex[pos], coordIndex[pos], 1);
        }
        int left = 0, right = N, answer = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            SegmentTree tempTree = segTree;
            for (int i = 0; i < mid; i++) {
                int pos = positions[i];
                tempTree.update(1, 0, compressedSize - 1, coordIndex[pos], coordIndex[pos], -1);
            }
            bool valid = true;
            for (auto [a, b, x] : constraints) {
                int count = tempTree.query(1, 0, compressedSize - 1, coordIndex[a], coordIndex[b]);
                if (count < x) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
