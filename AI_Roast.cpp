#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateRoast() {
    string name;
    cout << "Enter your name for a roast: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Even the AI can't roast someone who doesn't exist. Enter a name!" << endl;
        return;
    }

    vector<string> templates = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "The only thing {name} optimizes is the length of their lunch breaks.",
        "If {name} was any more laid back, they'd be horizontal.",
        "I've seen better organized code in a bowl of alphabet soup than in {name}'s projects.",
        "{name} uses Stack Overflow so much they should start paying them rent."
    };

    srand(time(0));
    int randomIndex = rand() % templates.size();
    string roast = templates[randomIndex];

    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}", pos + name.length());
    }

    cout << "\n>>> " << roast << endl;
}

int main() {
    generateRoast();
    return 0;
}