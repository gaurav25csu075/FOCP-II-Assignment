#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        counts[val]++;
    }

    // Get unique values and sort them descending
    vector<int> unique_vals;
    for (auto const& [val, count] : counts) {
        unique_vals.push_back(val);
    }
    sort(unique_vals.rbegin(), unique_vals.rend());

    long long alex_total = 0;
    long long bob_total = 0;
    bool alex_turn = true; // Alex starts first

    for (int val : unique_vals) {
        if (counts[val] >= 2) {
            // Both can have this quantity once.
            // This doesn't consume the "turn" for the next single-pile 
            // because both players acted on this sugar level.
            alex_total += val;
            bob_total += val;
        } else {
            // Only one pile exists, so only the current player takes it.
            if (alex_turn) {
                alex_total += val;
            } else {
                bob_total += val;
            }
            // Switch the turn for the next available single pile
            alex_turn = !alex_turn;
        }
    }

    if (alex_total > bob_total) {
        cout << "Alex" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

int main() {
    // Fast I/O is necessary for large constraints
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}