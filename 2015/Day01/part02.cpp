#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;

    cin >> input;
    int floor = 0, bas = 0;

    size_t n = input.size();

    for(int i = 0; i < n; i++){
        if(input[i] == '(') floor++;
        else floor --;

        if(floor == -1){
            bas = i;
            i = n;
        }
    }

    cout << bas << endl;

    return 0;
}
