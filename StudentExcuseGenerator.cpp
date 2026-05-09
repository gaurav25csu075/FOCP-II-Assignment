#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Seed the random number generator with the current system time.
    // This ensures that the sequence of random numbers is different every time the app starts.
    srand(static_cast<unsigned int>(time(0)));

    string studentName;
    cout << "--- Student Excuse Generator ---" << endl;
    cout << "Enter the student's name: ";
    
    // Using getline to capture the full name, including spaces.
    getline(cin, studentName);

    // Robustness: Check if the user entered an empty string.
    if (studentName.empty()) {
        cout << "Notice: No name entered. Generating a generic excuse instead..." << endl;
        studentName = "The student";
    }

    // Data Storage: A vector containing 10 creative excuse templates with a {name} placeholder.
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name} couldn't complete the work because a stray cat sat on the power button and refused to move.",
        "{name} finished the homework, but it was accidentally saved in a folder that was then sucked into a black hole.",
        "The assignment was ready, but {name}'s printer started printing in ancient hieroglyphics.",
        "{name} was halfway through when the mouse cursor developed a mind of its own and deleted everything.",
        "A sudden power surge caused {name}'s computer to restart right before the save button was clicked.",
        "{name} prepared the file, but the USB drive was mistaken for a snack by a very hungry dog.",
        "{name} would have submitted it, but the laptop battery reached 0% and the charger is currently 'missing'."
    };

    // Randomization Logic: Select a random index based on the size of the vector.
    // rand() % 10 gives a number between 0 and 9.
    int randomIndex = rand() % excuses.size();
    string selectedTemplate = excuses[randomIndex];

    // Placeholder Replacement: Locate the "{name}" tag and replace it with the actual studentName.
    string placeholder = "{name}";
    size_t position = selectedTemplate.find(placeholder);

    if (position != string::npos) {
        // .replace(starting_pos, length_of_target, replacement_string)
        selectedTemplate.replace(position, placeholder.length(), studentName);
    }

    // Display the final unique excuse.
    cout << "\nYour Excuse:" << endl;
    cout << selectedTemplate << endl;

    return 0;
}