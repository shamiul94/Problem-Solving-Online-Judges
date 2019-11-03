
#include <bits/stdc++.h>

#define llf long long
#define sz 10000+1
#define ln 100
#define md 100000007

using namespace std;
llf a[ln] = {0};
llf b[sz] = {0};
llf n;
llf k;

llf dp() {
    llf i, j;
    for (i = 0; i < n; i++) {
        for (j = 1; j <= k; j++) {
//                llf  x = floor (j/a[i]) ;
//                x = min (k, x) ;
            if (j - a[i] >= 0)
                b[j] = ((b[j]) % md + (b[j - a[i]]) % md) % md;


        }

    }
    return b[k];

}

int main() {
    //freopen("w.txt","w",stdout) ;

    llf total, t = 0;
    llf i = 0, j = 0;
    cin >> total;
    while (total--) {

        t++;
        for (i = 0; i < ln; i++) {
            a[i] = 0;

        }


        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }


        for (j = 0; j < sz; j++) {
            if (j == 0)
                b[j] = 1;

            else
                b[j] = 0;
        }


        cout << "Case " << t << ": " << dp() << endl;

    }
    return 0;
}
 