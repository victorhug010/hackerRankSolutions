#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hourString = s.substr(0, 2);
    int hourInt = stoi(hourString);
    size_t pos = s.find("PM");
    size_t pos2 = s.find("AM");

    if (pos != string::npos)
    {
        if (hourInt + 12 < 24)
        {
            hourString = to_string(hourInt + 12);
        } else {
            if (hourInt == 12) hourString = "12";
        }
    }

    if (pos2 != string::npos)
    {
        if (hourInt + 12 >23){
            hourString = to_string(hourInt + 12 - 24);
            if (hourString.size() < 2)
            {
                hourString.insert(0, "0");
            }
        }
    }
    s.replace(0,2, hourString);
    s.erase(s.size()-2);
    return s;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
