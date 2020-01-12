#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

bool containPairsWithoutOverlapping(string str){
    int i, j, n = str.size();

    for(i = 0; i < n - 2; i++){
        for(j = i + 2; j < n; j++){
            if(str[i] == str[j] && str[i+1] == str[j+1]){
                return true;
            }
        }
    }

    return false;
}

bool containRepeatingWithOneInBetween(string str){

    for(int i = 0; i < str.size() - 2; i++){
        if(str[i] == str[i + 2]){
            return true;
        }
    }

    return false;
}

int main(){

    string input;

    int nices = 0;

    while(cin >> input){
        if(containPairsWithoutOverlapping(input)
           && containRepeatingWithOneInBetween(input)){
            nices++;
        }
    }

    cout << nices << endl;
    return 0;
}
