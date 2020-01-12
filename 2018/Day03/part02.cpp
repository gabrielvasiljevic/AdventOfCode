#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const size_t vecSize = 1100;

vector<vector<vector<string>>> cloth(vecSize);
map<string, unsigned> iDCount;


int main(){

    string input;

    string id;
    char atSign, comma, colon, times;
    unsigned leftEdge, topEdge, width, height;

    long total = 0;

    for(int i = 0; i < vecSize; i++){
        for(int j = 0; j < vecSize; j++){
            cloth.at(i).push_back(vector<string>());
        }

    }

    while(getline(cin, input)){
        stringstream ss(input);
        ss >> id >> atSign >> leftEdge >> comma >> topEdge >> colon >> width >> times >> height;

        iDCount[id] = 0;

        for(int i = topEdge; i < topEdge + height; i++){
            for(int j = leftEdge; j < leftEdge + width; j++){
                cloth.at(i).at(j).push_back(id);
            }
        }
    }

    for(int i = 0; i < vecSize; i++){
        for(int j = 0; j < vecSize; j++){
            if(cloth.at(i).at(j).size() > 1){
                for(auto& id : cloth.at(i).at(j)){
                    iDCount[id]++;
                }
            }
        }

    }

    for(auto& id : iDCount){
        if(id.second == 0){
            debug(id.first);
        }
    }

    return 0;
}
