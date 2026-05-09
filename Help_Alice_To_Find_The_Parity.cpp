#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long L, R;
    if (!(cin >> L >> R)) return 0;
    auto countOdds = [](long long n) {
        return (n + 1) / 2;
    };
    long long oddCount = countOdds(R) - countOdds(L - 1);
    if (oddCount % 2 == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }

    return 0;
}