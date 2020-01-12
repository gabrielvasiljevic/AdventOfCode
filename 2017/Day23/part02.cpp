#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    int b, d, f, h;

    h = 0;

    for(b = 109300; b <= 126300; b += 17){
        f = 1;

        for(d = 2; d < sqrt(b); d++){
            if(b%d == 0){
                f = 0;
                break;
            }
        }

        if(f == 0){
            h++;
        }
    }

    debug(h);

    return 0;
}
