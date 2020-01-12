#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    int sum = 0;
    vector<int> seq;
    string input;

    cin >> input;

    for(auto& c : input){
        seq.push_back(c - '0');
    }


    size_t n = seq.size();
    int half = n/2;

    for(int i = 0; i <= n - 1; i++){
        if(seq[i] == seq[(i + half)%n]){
            sum += seq[i];
        }
    }

    cout << sum << endl;

    return 0;
}
