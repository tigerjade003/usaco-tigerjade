#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
struct Event {
    int l, type, r, cut;
};
bool comp(const Event& a, const Event& b) {
    if (a.l == b.l) return a.type < b.type;
    return a.l < b.l;
}
int main() {
    setIO();
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        sort(x.begin(), x.end());

        vector<Event> events;
        for (int i = 0; i < n; i++) {
            events.push_back({x[i], 0, 0, 0});
        }
        for (int i = 0; i < k; i++) {
            int l, r, t;
            cin >> l >> r >> t;
            int existing = upper_bound(x.begin(), x.end(), r) - lower_bound(x.begin(), x.end(), l);
            events.push_back({l, -1, r, existing - t});
        }
        sort(events.begin(), events.end(), comp);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;

        for (auto [l, type, r, cut] : events) {
            if (type == -1) {
                pq.push({ans + cut, r});
            } else {
                while (!pq.empty() && pq.top().second < l) {
                    pq.pop();
                }
                if (pq.empty() || pq.top().first != ans) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
