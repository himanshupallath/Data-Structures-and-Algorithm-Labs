#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main() {
    List<char> test;
    char c[] = {'z', 'p', 'r', 'p', 'd', 'a', 'h', 'q', 'o', 'r', 'r', 'r'};
    for (int i = 0; i < 8; i++) {
        test.insertEnd(c[i]);
    }
    test.print("Test");
    test.removeAt(2);
    test.print("Test");
    cout<<endl;

    return 1;
}