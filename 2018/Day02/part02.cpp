#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

unsigned getNumberOfNonMatches(string wordA, string wordB){
    unsigned nonMatches = 0;

    for(size_t i = 0; i < wordA.size(); i++){
        if(wordA.at(i) != wordB.at(i)){
            nonMatches++;
        }
    }

    return nonMatches;
}

string excludeNonMatches(string wordA, string wordB){
    string result = "";

    for(size_t i = 0; i < wordA.size(); i++){
        if(wordA.at(i) == wordB.at(i)){
            result += wordA.at(i);
        }
    }

    return result;
}

int main(){

    string input;
    vector<string> words;

    while(cin >> input){
        words.push_back(input);
    }

    for(size_t i = 0; i < words.size() - 1; i++){
        for(size_t j = i + 1; j < words.size(); j++){
            if(getNumberOfNonMatches(words.at(i), words.at(j)) == 1){
                debug(excludeNonMatches(words.at(i), words.at(j)));
            }
        }
    }

    return 0;
}
