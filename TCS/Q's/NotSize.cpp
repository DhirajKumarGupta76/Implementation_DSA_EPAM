#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    // Stores the entire input line
    string input;

    // Example Input:
    // 10 20 30 40 50
    getline(cin, input);

    // Convert string into stream
    stringstream ss(input);

    // Vector to store integers
    vector<int> nums;

    // Variable to store one token as string
    string token;

    // Read until a space (' ') is found
    while (getline(ss, token, ' ')) {

        // Convert string to integer
        int number = stoi(token);

        // Store integer in vector
        nums.push_back(number);
    }

    // Print vector
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}