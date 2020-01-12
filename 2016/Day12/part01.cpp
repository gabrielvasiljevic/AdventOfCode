#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int a, b, c, d;

int extractValue(string x){
    if(x == "a") return a;
    if(x == "b") return b;
    if(x == "c") return c;
    if(x == "d") return d;

    stringstream ss(x);
    int value;
    ss >> value;

    return value;
}

void cpy(string x, char y){
    int vx = extractValue(x);
    switch(y){
        case 'a':
            a = vx;
        break;

        case 'b':
            b = vx;
        break;

        case 'c':
            c = vx;
        break;

        case 'd':
            d = vx;
    }
}

void inc(char x){
    switch(x){
        case 'a':
            a++;
        break;

        case 'b':
            b++;
        break;

        case 'c':
            c++;
        break;

        case 'd':
            d++;
    }
}

void dec(char x){
    switch(x){
        case 'a':
            a--;
        break;

        case 'b':
            b--;
        break;

        case 'c':
            c--;
        break;

        case 'd':
            d--;
    }
}

int main(){

    string input;
    vector<string> instructions;

    a = b = c = d = 0;

    while(getline(cin, input)){
        instructions.push_back(input);
    }

    int n = instructions.size();
    int ic = 0;

    while(ic < n){
        istringstream iss(instructions[ic]);
        string inst;

        iss >> inst;

        if(inst == "cpy"){
            string x;
            char y;
            iss >> x >> y;
            cpy(x, y);
            ic++;
        }
        if(inst == "inc"){
            char x;
            iss >> x;
            inc(x);
            ic++;
        }
        if(inst == "dec"){
            char x;
            iss >> x;
            dec(x);
            ic++;
        }
        if(inst == "jnz"){
            string x, y;
            iss >> x >> y;

            if(extractValue(x)){
                ic += extractValue(y);
            }
            else ic++;
        }
    }

    debug(a);

    return 0;
}
