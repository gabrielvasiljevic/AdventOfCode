#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int input;
    int totalFuel = 0;

    while(cin >> input){
        while(floor(input/3) - 2 > 0){
            totalFuel += floor(input/3) - 2;
            input = floor(input/3) - 2;
        }
    }

    cout << totalFuel << endl;

    return 0;
}
