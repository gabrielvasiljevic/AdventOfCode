#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

pair<bool, bool> getTwoAndThreeRepetitions(string input){
    bool twoRepeatedLetters = false;
    bool threeRepeatedLetters = false;

    map<char, unsigned> letters;

    for(auto& letter : input){
        letters[letter]++;
    }

    for(auto& value : letters){
        if(value.second == 2){
            twoRepeatedLetters = true;
        }
        else if(value.second == 3){
            threeRepeatedLetters = true;
        }
    }

    return make_pair(twoRepeatedLetters, threeRepeatedLetters);
}

int main(){

    string input;

    unsigned numberOfTwoRepetitions = 0;
    unsigned numberOfThreeRepetitions = 0;
    unsigned long total = 0;

    while(cin >> input){
        pair<unsigned, unsigned> repetitions;

        repetitions = getTwoAndThreeRepetitions(input);

        if(repetitions.first)  numberOfTwoRepetitions++;
        if(repetitions.second) numberOfThreeRepetitions ++;
    }

    total = numberOfTwoRepetitions * numberOfThreeRepetitions;

    debug(total);

    return 0;
}
