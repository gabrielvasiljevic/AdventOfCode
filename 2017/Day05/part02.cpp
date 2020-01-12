#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;
    vector<int> instructions;

    while(cin >> input){
        istringstream iss(input);
        int inst;

        iss >> inst;
        instructions.push_back(inst);

    }

    int steps = 0;
    int nSize = instructions.size();
    int pc = 0;

    while(pc < nSize){
        pc += (instructions[pc] < 3 ? instructions[pc]++ : instructions[pc]--);
        steps++;
    }

    debug(steps);

    return 0;
}
