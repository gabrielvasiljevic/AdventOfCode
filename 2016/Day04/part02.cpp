#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

string decrypt(const string& name, unsigned times){
    string result = name;
    int i;
    int n = result.size();

    while(times--){
        for(i = 0; i < n; i++){
            result[i] = 'a' + (result[i] - 'a' + 1)%26;
        }
    }

    return result;
}

void separateValues(const string input, string& name, unsigned& id, string& checksum){
    int i = input.size() - 2;
    unsigned power = 0;
    name = checksum = "";
    id = 0;

    //checksum
    while(input[i] != '['){
        checksum += input[i--];
    }
    i--;

    //id
    while(input[i] != '-'){
        id += (input[i] - '0')*pow(10, power++);
        i--;
    }

    //name
    while(i >= 0){
        if(isalpha(input[i])){
            name += input[i];
        }
        i--;
    }

    reverse(name.begin(), name.end());
    reverse(checksum.begin(), checksum.end());

    return;
}

bool isValid(const string name, const string checksum){
    map<char, int> freqs;
    vector<pair<char, int>> orderedPairs;
    string orderedLetters = "";

    for(auto& letter : name){
        freqs[letter]++;
    }

    for(auto& letter : freqs){
        orderedPairs.push_back(make_pair(letter.first, letter.second));
    }

    sort(orderedPairs.begin(), orderedPairs.end(), [](pair<char, int> const& a, pair<char, int> const& b){
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });

    for(int i = 0; i < 5; i++){
        orderedLetters += orderedPairs[i].first;
    }

    return orderedLetters == checksum;
}


int main(){

    string input;

    while(cin >> input){

        string name, checksum;
        unsigned id;

        separateValues(input, name, id, checksum);

        if(isValid(name, checksum)){
            cout << decrypt(name, id) << " " << id << endl;
        }
    }

    return 0;
}
