#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool canTurnOffAll(int n, int m, const string& bulbs, int k) {
    int operations = 0;
    int i = 0;
    
    while (i < n) {
        if (bulbs[i] == '1') {
            
            operations++;
            
            i += k; 
        } else {
            
            i++;
        }
        
        
        if (operations > m) return false;
    }
    
    return operations <= m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
    if (!(cin >> n >> m)) return 0;
    string bulbs;
    cin >> bulbs;
	int low = 1, high = n;
    int result = n;
	while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canTurnOffAll(n, m, bulbs, mid)) {
            result = mid;    
            high = mid - 1;
        } else {
            low = mid + 1;   
        }
    }
	cout << result << endl;
	return 0;
}