#include <bits/stdc++.h>

using namespace std;

/* My code below */

string timeConversion(string s) {
    string k = s;
    int hr = stoi(k.erase(2));
    string ampm = s.substr(s.length()-2);
    
    string ns;

    if(ampm == "PM"){

        if(hr < 12){

            hr += 12;
            ns = s.erase(s.length()-2);
            ns = ns.substr(2);
            ns = to_string(hr) + ns;

        }else{

            ns = s.erase(s.length()-2);

        }
    }else{

        if(hr == 12){
            
            ns = s.erase(s.length()-2);
            ns = ns.substr(2);
            ns = "00" + ns;

        }else{

            ns = s.erase(s.length()-2);

        }
    }

    return ns;
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
