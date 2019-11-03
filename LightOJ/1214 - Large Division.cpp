#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int main() {
    char ch;
    int t = 0;

    long long int test;
    cin >> test;
    while (test--) {
        t++;
        long long int arr[1000] = {}, num;
        int i = 0;
        while (1) {
            (!i) ? scanf(" %c", &ch) : scanf("%c", &ch);
            if (ch != '-' && ch != ' ') {
//              cout <<endl <<  "CH" << " " ;
                arr[i] = ch - '0' + 0;
                //cout << "arr" <<arr[i] << endl ;
                i++;
            } else if (ch == ' ') {
                break;
            }
        }
        //printf("arr: %s",arr);
        int idx;
        idx = (i - 1);
        //cout << "idx = " << idx << endl ;
        cin >> num;


        i = 0;
        long long int a, b, rem;
        a = arr[i];
        b = num;
        while (i <= idx) {
            rem = a % b;
            i++;
            a = rem * 10 + arr[i];
        }

        //cin>> ch ;

        if (!rem) {
            printf("Case %d: divisible\n", t);
        } else {
            printf("Case %d: not divisible\n", t);
        }
        //cout <<endl << rem <<endl ;
        //arr = ch - '1'
        //cout << a << endl ;
    }
    return 0;
}
 