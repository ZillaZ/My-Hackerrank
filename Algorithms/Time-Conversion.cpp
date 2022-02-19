#include <bits/stdc++.h>

using namespace std;

/* My code below */

string timeConversion(string s) {
    string k = s;
    int hr = stoi(k.erase(2));
    string ampm = s.substr(s.length()-2);
    
    if(ampm == "PM"){

        if(hr < 12){

            hr += 12;
            string ns = s.erase(s.length()-2);
            ns = ns.substr(2);
            return to_string(hr) + ns;

        }else{

            string ns = s.erase(s.length()-2);
            return ns;

        }
    }else{

        if(hr == 12){

            string ns = s.erase(s.length()-2);
            ns = ns.substr(2);
            return "00" + ns;

        }else{

            string ns = s.erase(s.length()-2);
            return ns;

        }
    }

    return "a";
}

/* ends here */

int main()
{

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    return 0;
}
