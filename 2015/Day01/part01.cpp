#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;

    cin >> input;
    int floor = 0;

    for(auto& c : input){
        if(c == '(') floor++;
        else floor --;
    }

    cout << floor << endl;

    return 0;
}
