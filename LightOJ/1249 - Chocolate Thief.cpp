#include<iostream>
#include<cstdio>

using namespace std;

class student {
public:
    char name[21];
    int volume;
};

int main() {
    int test, t = 0, i;
    cin >> test;
    while (t < test) {
        int num, l, b, h, thief, victim;
        cin >> num;
        class student arr[num];
        for (i = 0; i < num; i++) {
            scanf(" %s", arr[i].name);
            cin >> l >> b >> h;
            arr[i].volume = l * b * h;
        }

        int maxi = arr[0].volume, mini = arr[0].volume;

        for (i = 0; i < num; i++) {
            if (maxi <= arr[i].volume) {
                maxi = arr[i].volume;
                thief = i;
            }
            if (mini >= arr[i].volume) {
                mini = arr[i].volume;
                victim = i;
            }
        }


        if (maxi == mini) ///It means , all the volumes are same.
        {
            printf("Case %d: no thief\n", t + 1);
        } else {
            printf("Case %d: %s took chocolate from %s\n", t + 1, arr[thief].name, arr[victim].name);
        }

        t++;
    }
    return 0;
}