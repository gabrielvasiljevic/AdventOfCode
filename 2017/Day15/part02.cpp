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

    long long genA = A_SEED,
              genB = B_SEED;

    for(int i = 0; i < 5'000'000; i++){

        do{
            genA = (genA*A_FACTOR)%DIVISOR;
        } while (genA%4 != 0);

        do{
            genB = (genB*B_FACTOR)%DIVISOR;
        } while(genB%8 != 0);

        if((genA & 0xffff) == (genB & 0xffff)){
            matches++;
        }

    }

    debug(matches);

    return 0;
}
