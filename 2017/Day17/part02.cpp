#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    int input = 329;

    list<int> circularBuffer;
    circularBuffer.push_back(0);
    int currentPosition = 0;
    int value = 0;

    for(int i = 1; i <= 50000000; i++){
        currentPosition = (currentPosition + input)%i + 1;

        if(currentPosition == 1){
            value = i;
        }
    }

    debug(value);

    return 0;
}
