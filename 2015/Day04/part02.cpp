#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#include "md5.c"

using namespace std;

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

int main(){

    string input;

    cin >> input;
    unsigned answer = 0;

    while(!startsWith(md5(input + toString(answer)), "000000")){
        answer++;
    }

    debug(answer);

    return 0;
}
