#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;
    stack<char> polymer;

    cin >> input;

    size_t stringSize = input.size();

    for(size_t i = 0; i < stringSize; i++){
        if(!polymer.empty() and
           (input.at(i) == polymer.top() + 32 or
            input.at(i) == polymer.top() - 32)){
            polymer.pop();
        }
        else{
           polymer.push(input.at(i));
        }


    }

    debug(polymer.size());

    return 0;
}
