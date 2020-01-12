#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;
    stack<char> polymer;

    cin >> input;

    size_t stringSize = input.size();

    unsigned smallestPolymerSize = stringSize;
    char currentUnit = 'a';

    while(currentUnit <= 'z'){
        while(!polymer.empty()){
            polymer.pop();
        }

        for(size_t i = 0; i < stringSize; i++){
            if(tolower(input.at(i)) != currentUnit){
                if(!polymer.empty() and
                   (input.at(i) == polymer.top() + 32 or
                    input.at(i) == polymer.top() - 32)){
                    polymer.pop();
                }
                else{
                   polymer.push(input.at(i));
                }
            }
        }

        smallestPolymerSize = min(smallestPolymerSize, polymer.size());

        currentUnit++;

    }

    debug(smallestPolymerSize);

    return 0;
}
