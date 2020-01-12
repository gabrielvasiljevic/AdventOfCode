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

        for(int i = 0; i < in.size(); i++){
            for(int j = 0; j < in.size(); j++){
                if(in[i]%in[j] == 0 && in[i] != in[j]){
                    checksum += in[i]/in[j];
                }
            }
        }
    }

    cout << checksum << endl;

    return 0;
}
