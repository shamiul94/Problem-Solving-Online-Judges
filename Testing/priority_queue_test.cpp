// program in c++ to use priority_queue with class
#include <iostream>
#include <queue>
using namespace std;

#define ROW 5
#define COL 2

class Person {

public:
    int age;

    float height;

    // this is used to initialize the variables of the class
    Person(int age, float height)
            : age(age), height(height)
    {
    }
};

// we are doing operator overloading through this
bool operator<(const Person& p1, const Person& p2)
{

    // this will return true when second person
    // has greater height. Suppose we have p1.height=5
    // and p2.height=5.5 then the object which
    // have max height will be at the top(or
    // max priority)
    return p1.height < p2.height;
}

int main()
{

    priority_queue<Person> Q;

    vector<vector<float>> arr { { 30, 5.5 }, { 25, 5 },
                            { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } };

    for (int i = 0; i < ROW; ++i) {

        Q.push(Person((int) arr[i][0], arr[i][1]));

        // insert an object in priority_queue by using
        // the Person class constructor
    }

    while (!Q.empty()) {

        Person p = Q.top();

        Q.pop();

        cout << p.age << " " << p.height << "\n";
    }
    return 0;
}
