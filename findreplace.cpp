#include <bits/stdc++.h>
using namespace std;

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int letterToNode(char letter) {
    if ('a' <= letter && letter <= 'z') {
        return letter - 'a';
    } else {
        return 26 + (letter - 'A');
    }
}

int main() {
    setIO();
    int T;
    cin >> T;
    while (T--) {
        string before, after;
        cin >> before >> after;

        vector<int> becomes(52, -1);
        bool possible = true;
        set<char> uniqueChars;

        for (int j = 0; j < before.size(); ++j) {
            int b = letterToNode(before[j]);
            int a = letterToNode(after[j]);
            uniqueChars.insert(after[j]);

            if (becomes[b] != -1 && becomes[b] != a) {
                possible = false;
            }
            becomes[b] = a;
        }

        if (uniqueChars.size() == 52) {
            possible = false;
        }
        if (before == after) {
            possible = true;
        }

        int answer = 0;
        if (possible) {
            vector<int> inDegree(52, 0);
            for (int a = 0; a < 52; ++a) {
                if (becomes[a] != -1 && becomes[a] != a) {
                    inDegree[becomes[a]]++;
                }
            }

            for (int a = 0; a < 52; ++a) {
                if (becomes[a] != -1 && becomes[a] != a) {
                    answer++;
                }
            }

            vector<int> seen(52, 0);
            for (int r = 0; r < 52; ++r) {
                if (seen[r] == 0) {
                    int a = r;
                    while (a != -1 && seen[a] == 0) {
                        seen[a] = r + 1;
                        a = becomes[a];
                    }
                    if (a != -1 && a != becomes[a] && seen[a] == r + 1) {
                        int s = a;
                        bool freePass = false;
                        do {
                            seen[a] = 2;
                            if (inDegree[a] > 1) {
                                freePass = true;
                            }
                            a = becomes[a];
                        } while (a != s);
                        if (!freePass) {
                            answer++;
                        }
                    }
                }
            }
        } else {
            answer = -1;
        }

        cout << answer << '\n';
    }

    return 0;
}
