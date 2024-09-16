#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <sstream>
#include <json/json.h>  // Make sure to include the JSON parser library

using namespace std;

int decodeValue(const string& value, int base) {
    int result = 0;
    for (char digit : value) {
        if (isdigit(digit)) {
            result = result * base + (digit - '0');
        } else if (isalpha(digit)) {
            result = result * base + (tolower(digit) - 'a' + 10);  // Handle hex and higher bases
        }
    }
    return result;
}

// Function to parse the input JSON and extract the points
void parseInput(const string& input, vector<pair<int, int>>& points) {
    Json::Value root;
    Json::Reader reader;

    if (!reader.parse(input, root)) {
        cerr << "Error parsing JSON input" << endl;
        return;
    }

    // Number of points (roots)
    int n = root["keys"]["n"].asInt();
    int k = root["keys"]["k"].asInt(); // Not really needed for solving, but useful for verification

    // Extract the points
    for (auto it = root.begin(); it != root.end(); ++it) {
        if (it.key().asString() == "keys") continue;  // Skip "keys" part
        int x = stoi(it.key().asString());  // x is the key of the JSON object
        string baseStr = (*it)["base"].asString();
        string valueStr = (*it)["value"].asString();

        int base = stoi(baseStr);
        int y = decodeValue(valueStr, base);  // Convert y to base 10

        points.push_back({x, y});
    }
}

// Function to perform Lagrange interpolation and get the constant term (c)
double lagrangeInterpolation(const vector<pair<int, int>>& points) {
    int k = points.size();
    double secret = 0.0;

    for (int i = 0; i < k; i++) {
        double term = points[i].second;  // y_i

        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0.0 - points[j].first) / (points[i].first - points[j].first);
            }
        }

        secret += term;
    }

    return secret;
}

int main() {
    // Prompt the user to enter JSON input
    cout << "Enter JSON input: ";
    string input;
    getline(cin, input);

    vector<pair<int, int>> points;
    parseInput(input, points);

    // Perform Lagrange interpolation to find the secret (constant term)
    double secret = lagrangeInterpolation(points);

    cout << "The constant term (secret) is: " << secret << endl;

    return 0;
}
