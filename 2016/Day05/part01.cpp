#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#include "md5.h"

using namespace std;

const string input = "abbhdwsy";

bool startsWith(string word, string substring){
    unsigned subSize = substring.size();
    int i;

    for(i = 0; i < subSize; i++){
        if(word[i] != substring[i]){
            return false;
        }
    }

    return true;
}


template<typename T>
string toString(T number){

    stringstream ss;
    ss << number;
    return ss.str();

}

string toHex(string word){
    std::stringstream converter;

    converter << std::hex << word;

    return converter.str();
}

int main(){

    string password = "";
    unsigned long long index = 0;

    while(password.size() < 8){

        string candidate = input + toString(index);
        string hashCandidate = md5(candidate);

        if(startsWith(toHex(hashCandidate), "00000")){
            password += hashCandidate[5];
            cout << hashCandidate[5];
        }

        index++;
    }

    cout << endl;

    return 0;
}
