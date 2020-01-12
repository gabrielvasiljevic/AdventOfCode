#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int input;
    int totalFuel = 0;

    while(cin >> input){
        totalFuel += floor(input/3) - 2;
    }

    cout << totalFuel << endl;

    return 0;
}
