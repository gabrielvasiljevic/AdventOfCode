#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

char pad[5][5] = {{'0', '0', '1', '0', '0'},
                  {'0', '2', '3', '4', '0'},
                  {'5', '6', '7', '8', '9'},
                  {'0', 'A', 'B', 'C', '0'},
                  {'0', '0', 'D', '0', '0'}};

int main(){

    int posI = 2, posJ = 0;

    string input;
    string output = "";

    while(cin >> input){

        for(auto& dir : input){
            switch(dir){
                case 'U':
                    posI--;
                    if(posI < 0 or pad[posI][posJ] == '0'){
                        posI++;
                    }
                break;
                case 'D':
                    posI++;
                    if(posI > 4 or pad[posI][posJ] == '0'){
                        posI--;
                    }
                break;
                case 'L':
                    posJ--;
                    if(posJ < 0 or pad[posI][posJ] == '0'){
                        posJ++;
                    }
                break;
                case 'R':
                    posJ++;
                    if(posJ > 4 or pad[posI][posJ] == '0'){
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
