#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size())) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

int N, M, K;
vector<pair<int, int>> cows;

signed main() {
    setIO();
    cin >> N >> M >> K;

    // Read cows' data
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cows.push_back({a, b});
    }

    // Sort cows in descending order based on the first value (distance)
    sort(cows.rbegin(), cows.rend());

    // Priority queue to store tower sizes, using a max heap
    priority_queue<pair<int, int>> towers;

    // Add a special initial tower with an effectively infinite capacity
    towers.push({INT_MAX, M});

    int ans = 0;

    // Keep track of the cows' remaining needs and iterating over towers efficiently
    for (int i = 0; i < N; i++) {
        int remaining_capacity = cows[i].second;

        // Process as much of the current cow's need as possible
        while (remaining_capacity > 0 && !towers.empty()) {
            auto top_tower = towers.top();
            towers.pop();

            if (top_tower.first >= cows[i].first + K) {
                // Calculate the number of cows we can accommodate using this tower
                int size = min(top_tower.second, remaining_capacity);

                // Deduct the number of cows we accommodate from the tower's remaining capacity
                remaining_capacity -= size;
                ans += size;

                // If there's still capacity left in the tower, push it back into the priority queue
                if (top_tower.second > size) {
                    towers.push({top_tower.first, top_tower.second - size});
                }

                // Insert the current cow's requirement into the tower system
                towers.push({cows[i].first, size});
            }
        }
    }

    cout << ans << endl;
    return 0;
}
