#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int getNumberOfVowels(string str){
    int vowels = 0;

    for(auto& c : str){
        if(c == 'a' ||
           c == 'e' ||
           c == 'i' ||
           c == 'o' ||
           c == 'u')
            vowels++;
    }

    return vowels;
}

bool hasTwiceInARow(string str){
    for(int i = 0; i < str.size() - 1; i++){
        if(str[i] == str[i+1]){
            return true;
        }
    }

    return false;
}

bool hasBadString(string str){
    if(str.find("ab") != string::npos ||
       str.find("cd") != string::npos ||
       str.find("pq") != string::npos ||
       str.find("xy") != string::npos)
       return true;
    else return false;
}

int main(){

    string input;

    int nices = 0;

    while(cin >> input){
        if(getNumberOfVowels(input) >= 3
           && hasTwiceInARow(input)
           && not hasBadString(input)){
            nices++;
        }
    }

    cout << nices << endl;
    return 0;
}
