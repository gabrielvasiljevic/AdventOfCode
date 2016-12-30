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
    unsigned a, b, c, i = 0;

    unsigned batchA[3], batchB[3], batchC[3];

    while(cin >> a >> b >> c){
        batchA[i] = a;
        batchB[i] = b;
        batchC[i] = c;

        if(++i > 2){
            i = 0;

            total += isValid(batchA[0], batchA[1], batchA[2]) +
                     isValid(batchB[0], batchB[1], batchB[2]) +
                     isValid(batchC[0], batchC[1], batchC[2]);
        }

    }

    cout << total << endl;

    return 0;
}
