#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;
    int checksum = 0;

    while(getline(cin, input)){
        istringstream iss(input);

        vector<int> in;
        int x;
        while(iss >> x){
            in.push_back(x);
        }

        int smaller, bigger;
        smaller = bigger = in[0];

        for(int i = 0; i < in.size(); i++){
            if(in[i] > bigger)
                bigger = in[i];
            if(in[i] < smaller)
                smaller = in[i];
        }

        checksum += bigger - smaller;
    }

    cout << checksum << endl;

    return 0;
}
