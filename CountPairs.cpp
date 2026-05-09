#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000001;
int distinct_primes[MAXN];
long long power_of_two[32]; 
void sieve() {
    for (int i = 2; i < MAXN; ++i) {
        if (distinct_primes[i] == 0) { 
            for (int j = i; j < MAXN; j += i) {
                distinct_primes[j]++;
            }
        }
    }
    power_of_two[0] = 1;
    for (int i = 1; i < 32; ++i) {
        power_of_two[i] = power_of_two[i - 1] * 2;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n"; 
        } else {
            cout << power_of_two[distinct_primes[n]] << "\n";
        }
    }

    return 0;
}