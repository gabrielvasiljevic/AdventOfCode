#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int A_SEED = 277;
const int B_SEED = 349;

const int A_FACTOR = 16807;
const int B_FACTOR = 48271;

const long long DIVISOR = 2147483647;

int main(){

    int matches = 0;

    long long genA = (A_SEED*A_FACTOR)%DIVISOR,
              genB = (B_SEED*B_FACTOR)%DIVISOR;

    for(int i = 0; i < 40'000'000; i++){

        if((genA & 0xffff) == (genB & 0xffff)){
            matches++;
        }

        genA = (genA*A_FACTOR)%DIVISOR,
        genB = (genB*B_FACTOR)%DIVISOR;

    }

    debug(matches);

    return 0;
}
