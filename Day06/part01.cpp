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
        int bigger = 0;
        char mostFrequent;

        for(auto& element : freqs[i]){
            if(element.second > bigger){
                bigger = element.second;
                mostFrequent = element.first;
            }
        }

        cout << mostFrequent;
    }

    return 0;
}
