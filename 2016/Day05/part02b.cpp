#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#include "md5.h"
#include <windows.h>

using namespace std;

const string input = "abbhdwsy";
unsigned animationIndex = 0;
vector<char> animation = {'-', '\\', '|', '/'};

template<typename T>
string toString(T number){

    stringstream ss;
    ss << number;
    return ss.str();

}


void updateAnimation(string& password){

    ++animationIndex %= 4;

    for(auto& c : password){
        if(not isdigit(c) and not isalpha(c)){
            c = animation[animationIndex];
        }
    }

}

void printPassword(const string& password){
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(console, topLeft);

    cout << "Password:\n" << password << endl;
}

int main(){

    string password = "--------";
    unsigned long long i;
    unsigned foundDigits = 0;

    for(i = 0; i < numeric_limits<unsigned long long>::max() and foundDigits < 8; i++){

        string candidate = input + toString(i);
        string hashCandidate = md5(candidate);

        if(hashCandidate.compare(0, 5, "00000") == 0){

            int position = hashCandidate[5] - '0';

            if(position < 8){
                if(not isalpha(password[position]) and
                   not isdigit(password[position])){

                    password[position] = hashCandidate[6];

                    foundDigits++;
                }
            }
        }

        if(i%100 == 0){
            updateAnimation(password);
            printPassword(password);
        }

    }

    cout << endl;

    return 0;
}
