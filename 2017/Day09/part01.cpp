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

    int level = 0;
    int totalScore = 0;

    while(!pile.empty()){
        switch(pile.top()){
            case '{':{
                level++;
                totalScore += level;
            } break;

            case '<':{
                while(pile.top() != '>'){
                    if(pile.top() == '!'){
                        pile.pop();
                    }

                    pile.pop();
                }
            } break;

            case '!':{
                pile.pop();
            } break;

            case '}':{
                level--;
            } break;

        }

        pile.pop();
    }

    debug(totalScore);

    return 0;
}
