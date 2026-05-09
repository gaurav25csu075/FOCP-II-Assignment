#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Bank {
private:
    unordered_map<int, long long> accounts;

public:
    bool create(int x, int y) {
        if (accounts.find(x) != accounts.end()) {
            accounts[x] += y;
            return false;
        }
        accounts[x] = y;
        return true;
    }

    bool debit(int x, int y) {
        if (accounts.find(x) == accounts.end() || accounts[x] < y) {
            return false;
        }
        accounts[x] -= y;
        return true;
    }

    bool credit(int x, int y) {
        if (accounts.find(x) == accounts.end()) {
            return false;
        }
        accounts[x] += y;
        return true;
    }

    long long balance(int x) {
        if (accounts.find(x) == accounts.end()) {
            return -1;
        }
        return accounts[x];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    Bank system;

    while (q--) {
        string type;
        cin >> type;

        if (type == "CREATE") {
            int x, y;
            cin >> x >> y;
            cout << (system.create(x, y) ? "true" : "false") << "\n";
        } else if (type == "DEBIT") {
            int x, y;
            cin >> x >> y;
            cout << (system.debit(x, y) ? "true" : "false") << "\n";
        } else if (type == "CREDIT") {
            int x, y;
            cin >> x >> y;
            cout << (system.credit(x, y) ? "true" : "false") << "\n";
        } else if (type == "BALANCE") {
            int x;
            cin >> x;
            cout << system.balance(x) << "\n";
        }
    }

    return 0;
}