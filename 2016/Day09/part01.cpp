#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;


int main(){

    string input, result = "";

    cin >> input;

    size_t lenght = input.size();

    for(size_t i = 0; i < lenght; i++){
        if(input[i] == '('){
            stringstream ss(input.substr(i + 1));
            unsigned subsequent, times;
            string repeat = "";
            char x;

            ss >> subsequent >> x >> times;

            while(input[i++] != ')'); //skip until ')' and itself

            repeat = "";
            while(subsequent--){
                repeat += input[i++]; //+1
            }

            while(times--){
                result += repeat;
            }

            i--; //-1 for the +1
        }
        else{
            result += input[i];
        }
    }

    cout << result.size() << endl;

    return 0;
}
