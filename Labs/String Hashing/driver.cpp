#include "stringset.h"
#include <iostream>
#include <fstream>
using namespace std;

void testStringset(Stringset &words);
// void loadStringset(Stringset &words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

int main() {
    Stringset words;
    loadStringset(words, "wordlist.txt");
}