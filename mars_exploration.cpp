#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>


using namespace std;
/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int res = 0;
    vector<char> sequency = {'S','O','S'};
    int index = 0;
    for (char letter : s) {
        cout << index << endl;
        if (letter != sequency[index]) res++;
        index ++;
        if (index > 2) index = 0;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
