#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

bool isValid(unsigned a, unsigned b, unsigned c){
    return  (a < b + c) and
            (b < a + c) and
            (c < a + b);
}

int main(){

    unsigned total = 0;
    unsigned a, b, c;

    while(cin >> a >> b >> c){
        if(isValid(a, b, c))
            total++;
    }

    cout << total << endl;

    return 0;
}
