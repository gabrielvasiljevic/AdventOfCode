#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

string knotHash(string input){
    vector<int> lengths;
    vector<int> numbers;

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

    return knotHash;
}

void floodFill(vector<vector<bool>>& grid, int posY, int posX){
    if(grid[posY][posX]){
        grid[posY][posX] = 0;

        floodFill(grid, max(0, posY - 1), posX);
        floodFill(grid, posY,  max(0, posX - 1));
        floodFill(grid, min(posY + 1, static_cast<int>(grid.size() - 1)), posX);
        floodFill(grid, posY, min(posX + 1, static_cast<int>(grid[posY].size() - 1)));
    }
}

int getNumberOfRegions(vector<vector<bool>> grid){
    int regions = 0;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j]){
                regions++;
                floodFill(grid, i, j);
            }
        }
    }

    return regions;
}

int main(){

    string input = "ljoxqyyw";
    //cin >> input;

    vector<vector<bool>> grid;

    for(int i = 0; i < 128; i++){
        string khash = knotHash(input + "-" + to_string(i));
        grid.push_back(vector<bool>());

        for(auto& c : khash){
            stringstream ss;
            ss << hex << c;

            unsigned n;
            ss >> n;
            bitset<4> bits(n);

            for(auto& bit : bits.to_string()){
                grid[grid.size() - 1].push_back(static_cast<bool>(bit - '0'));
            }

        }

    }

    debug(getNumberOfRegions(grid));

    return 0;
}
