#include <bits/stdc++.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string str) {
    unordered_set<char> mySet;

    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (char letter : str){
        mySet.insert(letter);
    }
    return (mySet.size() == 26) ? "pangram" : "not pangram";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
