#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
string splitString(string &);
string compareString(string &);

int main()
{
    string n_temp;

    while (getline(cin, n_temp))
    {

        size_t pos = n_temp.find("S");
        if (pos != string::npos)
        {
            n_temp = splitString(n_temp);
        }
        else
        {
            n_temp = compareString(n_temp);
        }
        cout << ltrim(rtrim(n_temp)) << endl;
    }

    return 0;
}

string compareString(string &str)
{
    str.erase(0, 2);

    size_t pos = str.find("C");
    if (pos != string::npos)
    {
        str.erase(pos, 2);
        str[pos] = toupper(str[pos]);
    }
    else
    {
        size_t pos = str.find("M");
        str.erase(0, 2);
        if (pos != string::npos)
        {
            str.insert(str.size(), "()");
        }
    }

    for (size_t i = 0; i < str.size(); i++)
    {
        if (isspace(str[i]))
        {
            str[i+1] = toupper(str[i+1]);
            str.erase(i, 1);
        }
    }

    return str;
}

string splitString(string &str)
{
    str.erase(0, 4);
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
            str.insert(i, " ");
            i++;
        }
    }
    size_t pos = str.find("()");

    if (pos != string::npos)
    {
        str.erase(pos, 2);
    }
    return str;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}