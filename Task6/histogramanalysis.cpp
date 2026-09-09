#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//returns the modes like all frequently repeating values
vector<int> findMode(const vector<int>& arr) {
    vector<int> modes;
    // no data so there is no mode
    if (arr.empty()) {
        return modes;}

    //frequency histogram; if value comes so count increases
    unordered_map<int, int> frequency;
    for (int value : arr) {
        frequency[value]++;}

    //the highest frequency 
    int maxFrequency = 0;
    for (const auto& entry : frequency) {
        maxFrequency = max(maxFrequency, entry.second); }

    //collecting every value that reaches the highest frequency 
    for (const auto& entry : frequency) {
        if (entry.second == maxFrequency) {
            modes.push_back(entry.first);}
    }

    return modes;
}