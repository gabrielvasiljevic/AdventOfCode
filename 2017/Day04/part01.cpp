#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;

    int valids = 0;

    while(getline(cin, input)){
        istringstream iss(input);
        map<string, int> passphrases;
        string word;
        bool isValid = true;

        while(iss >> word){
            passphrases[word]++;
        }

        for(auto& wrd : passphrases){
            if(wrd.second > 1){
                isValid = false;
            }
        }

        if(isValid) valids++;
    }

    debug(valids);

    return 0;
}
