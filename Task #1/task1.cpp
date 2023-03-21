#include <iostream>
using namespace std;

int main() {
    cout<<"Ispis:"<<endl;
    for (int i = 1; i <= 100; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
        cout<<"Djeljiv s 3 i 5"<<endl;
    }
    else if(i % 3 == 0) {
        cout<<"Djeljiv s 3"<<endl;
    }
    else if(i % 5 == 0) {
        cout<<"Djeljiv s 5"<<endl;
    }
    else {
        cout<<i<<endl;
    }
}
    return 0;
}
