#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"(", "6", "-", "(", "5", "-", "(",
                         "(", "4", "-", "(", "3", "-", "(", "2",
                         "-", "1", ")", ")", ")", ")", ")",
                         "+", "42", "-", "(", "30", "-",
                         "(", "20", "-", "(", "12", ")", "-", "(",
                         "6", "-", "(", "4", "-", "2", ")",
                         ")", ")", ")", ")"};
    string postfixExp[47] = {"6", "5", "4", "3", "2", "1",
                             "-", "-", "-", "-", "-",
                             "42", "+", "30", "20", "12", "-", "6", "4",
                             "2", "-", "-", "-", "-", "-"};
    string postfixTest[47];
    int postfixLength = infixToPostfix(infixExp, 47, postfixTest);

    //ASSERT_THAT(postfixExp, ElementsAreArray(postfixTest));
    for (int i=0; i<47; i++)
    {
        if (postfixTest[i] != postfixExp[i])
        {
            cout << "Mismatch at position " << i << ": expected/correct value " << postfixExp[i] << ", actual value when testing " << postfixTest[i] << ".\n";
            return 1;
        }
    }
    cout << "Passed" << endl;
    return 0;
}