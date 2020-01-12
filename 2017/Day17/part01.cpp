#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    int input = 329;

    vector<int> circularBuffer;
    circularBuffer.push_back(0);
    int currentPosition = 0;

    for(int i = 1; i <= 2017; i++){
        currentPosition = (currentPosition + input)%i + 1;
        circularBuffer.insert(circularBuffer.begin() + currentPosition, i);
    }

    debug(circularBuffer[currentPosition + 1]);

    return 0;
}
