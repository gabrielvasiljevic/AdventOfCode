#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    long input, sum = 0;
    bool repeated = false;

    vector<long> changes;
    while(cin >> input){
        changes.push_back(input);
    }

    unordered_set<long> frequencies;

    while(!repeated){
        for(auto& value : changes){
            sum += value;
            if(!frequencies.insert(sum).second){
                debug(sum);
                repeated = true;
                break;
            }
        }

    }

    return 0;
}
