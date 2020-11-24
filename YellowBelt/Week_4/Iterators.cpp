#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct Lang {
    string name;
    string implementation;
};

ostream& operator<<(ostream& stream, const Lang& lang) {
    stream << lang.name << " " << lang.implementation << endl;
    return stream;
}

template <typename It>
void PrintRange(It range_begin, It range_end, const string& title) {
    cout << title;
    for (auto it = range_begin;
        it != range_end;
        ++it) {
        cout << it->name << " ";
    }
    cout << endl;
}

int main() {
    vector<Lang> langs = {
        {"C/C++", "Compiled"},
        {"Rust", "Compiled"},
        {"Python", "Interpreted"},
        {"JavaScript", "Interpreted"}
    };   

    vector<Lang> script_langs;

    auto it = copy_if(langs.begin(), langs.end(), back_inserter(script_langs),
                      [](const Lang& lang) {
                    return lang.implementation == "Interpreted";
               });

    PrintRange(langs.begin(), langs.end(), "All langs: ");
    PrintRange(script_langs.begin(), script_langs.end(), "Script langs: ");

    return 0;
}