#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

stack<char> pile;


int main(){

    string input;
    cin >> input;

    for(int i = input.size() - 1; i >= 0; i--){
        pile.push(input[i]);
    }

    int totalGarbage = 0;

    while(!pile.empty()){
        switch(pile.top()){

            case '<':{
                totalGarbage--;
                while(pile.top() != '>'){
                    if(pile.top() == '!'){
                        pile.pop();
                        totalGarbage--;
                    }

                    totalGarbage++;
                    pile.pop();
                }
            } break;

            case '!':{
                pile.pop();
            } break;
        }

        pile.pop();
    }

    debug(totalGarbage);

    return 0;
}
