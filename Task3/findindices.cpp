#include <vector>
using namespace std;

//finding all indices 
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;

    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] == key) {
            indices.push_back(i); //keeps track of the matching index
        }
    }

    return indices; //will be empty if key was nvr found OR arr was empty 
}