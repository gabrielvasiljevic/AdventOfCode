#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

char pad[3][3] = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};

int main(){

    int posI, posJ;
    posI = posJ = 1;

    string input;
    string output = "";

    while(cin >> input){

        for(auto& dir : input){
            switch(dir){
                case 'U':
                    posI--;
                    if(posI < 0){
                        posI++;
                    }
                break;
                case 'D':
                    posI++;
                    if(posI > 2){
                        posI--;
                    }
                break;
                case 'L':
                    posJ--;
                    if(posJ < 0){
                        posJ++;
                    }
                break;
                case 'R':
                    posJ++;
                    if(posJ > 2){
                        posJ--;
                    }
                break;
            }
        }
        output += pad[posI][posJ];
    }

    cout << output << endl;

    return 0;
}
