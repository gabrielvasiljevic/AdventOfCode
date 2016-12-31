#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;


int main(){

    string input;

    vector<map<char, int>> freqs(8);

    while(cin >> input){

        for(int i = 0; i < 8; i++){
            freqs[i][input[i]]++;
        }
    }

    for(int i = 0; i < 8; i++){
        unsigned smaller = numeric_limits<unsigned>::max();
        char leastFrequent;

        for(auto& element : freqs[i]){
            if(element.second < smaller){
                smaller = element.second;
                leastFrequent = element.first;
            }
        }

        cout << leastFrequent;
    }

    return 0;
}
