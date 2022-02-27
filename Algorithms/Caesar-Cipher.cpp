#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string caesarCipher(string s, int k) {
    
    while(k >= 26){
        k-=26;
    }
    
    string abc = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    vector<int> index;
    
    for(int i = 0; i < s.length(); i++){
        if(isupper(s[i])){
            index.push_back(i);
        }
        s[i] = tolower(s[i]);
    }
    
    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i])){
            int ind = abc.find_first_of(s[i]) + k;
            s[i] = abc.at(ind);
        }
    }
    
    for(int i = 0; i < index.size(); i++){
        s[index.at(i)] = toupper(s[index.at(i)]);
    }
    return s;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

