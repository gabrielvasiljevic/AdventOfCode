#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#include "md5.h"

using namespace std;

const string input = "abbhdwsy";

template<typename T>
string toString(T number){

    stringstream ss;
    ss << number;
    return ss.str();

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
                if(password[position] == '-'){
                    password[position] = hashCandidate[6];
                    foundDigits++;

                    cout << password << endl;
                }
            }
        }
    }

    cout << endl;

    return 0;
}
