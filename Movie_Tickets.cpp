#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MovieTicket {
private:
    unordered_map<int, int> movie_availability;
    unordered_map<int, unordered_set<int>> customer_bookings;
    const int MAX_SLOTS = 100;

public:
    bool book(int x, int y) {
        if (movie_availability.find(y) == movie_availability.end()) {
            movie_availability[y] = MAX_SLOTS;
        }
        if (customer_bookings[x].count(y) || movie_availability[y] <= 0) {
            return false;
        }
        customer_bookings[x].insert(y);
        movie_availability[y]--;
        return true;
    }

    bool cancel(int x, int y) {
        if (customer_bookings.find(x) == customer_bookings.end() || !customer_bookings[x].count(y)) {
            return false;
        }
        customer_bookings[x].erase(y);
        movie_availability[y]++;
        return true;
    }

    bool is_booked(int x, int y) {
        return customer_bookings.count(x) && customer_bookings[x].count(y);
    }

    int available_tickets(int y) {
        if (movie_availability.find(y) == movie_availability.end()) {
            return MAX_SLOTS;
        }
        return movie_availability[y];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if (!(cin >> q)) return 0;
    MovieTicket system;
    while (q--) {
        string type;
        cin >> type;
        if (type == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (system.book(x, y) ? "true" : "false") << "\n";
        } else if (type == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (system.cancel(x, y) ? "true" : "false") << "\n";
        } else if (type == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (system.is_booked(x, y) ? "true" : "false") << "\n";
        } else if (type == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << system.available_tickets(y) << "\n";
        }
    }
    return 0;
}