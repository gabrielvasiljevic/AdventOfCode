#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int diskLength = 272;

string fillDisk(string str){
    int length = str.size();

    string dataCopy = str;

    while(dataCopy.size() < diskLength){
        string a = dataCopy;
        string b = a;

        reverse(b.begin(), b.end());

        for(auto& bit : b){
            bit = (bit == '1'? '0' : '1');
        }

        dataCopy = a + '0' + b;
    }

    return dataCopy.substr(0, diskLength);
}

string createChecksum(string str){
    string result = str;
    int n = result.size();

    do{
        string checksum = "";
        debug(result.size());
        for(int i = 0; i < result.size() - 1; i += 2){
            checksum += (result[i] == result[i+1] ? '1' : '0');
        }

        result = checksum;

    } while(result.size()%2 == 0);

    return result;
}

int main(){

    string input;

    cin >> input;

    string filledDisk = fillDisk(input);

    string checksum = createChecksum(filledDisk);

    debug(checksum);

    return 0;
}
