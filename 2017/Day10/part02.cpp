#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    vector<int> lengths;
    vector<int> numbers;

    string input;
    cin >> input;
    for(char c : input){
        lengths.push_back(static_cast<int>(c));
    }
    lengths.insert(lengths.end(), {17, 31, 73, 47, 23});

    numbers.reserve(256);
    for(int i = 0; i <= 255; i++){
        numbers.push_back(i);
    }

    int currentPosition = 0;
    int skipSize = 0;

    for(int round = 0; round < 64; round++){

        for(auto& lenght : lengths){
            int listSize = lenght;
            vector<int> reverseOrder;
            int i;

            for(i = currentPosition; listSize > 0; listSize--){
                reverseOrder.push_back(numbers[i]);
                ++i %= numbers.size();
            }

            reverse(reverseOrder.begin(), reverseOrder.end());

            for(int j = 0, i = currentPosition; j < reverseOrder.size(); j++){
                numbers[i] = reverseOrder[j];
                ++i %= numbers.size();
            }

            currentPosition += lenght + skipSize;
            currentPosition %= numbers.size();
            skipSize++;

        }
    }

    vector<int> denseHash;

    for(int i = 0; i < 16; i++){
        int combined = 0;

        for(int j = 0; j < 16; j++){
            combined ^= numbers[i*16 + j];
        }

        denseHash.push_back(combined);
    }

    string knotHash;
    std::stringstream sstream;
    for(auto& n : denseHash){
        sstream << std::setw(2) << std::setfill ('0') << std::hex << n;
    }

    knotHash = sstream.str();

    debug(knotHash);

    return 0;
}
