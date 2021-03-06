#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main(){
    unsigned int n, i;
    int g;
    string s;
    string l = "abcdefghijklmnopqrstuvwxyz";
    string u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int c[26];

    cin >> n;
    getline(cin, s); // it's a hack!
    while (n--){
        memset(c, 0, sizeof(c));
        g = -1;

        getline(cin, s);
        for (i = 0; i < s.size(); i++){
            if (l.find_first_of(s.at(i)) != string::npos){
                c[l.find_first_of(s.at(i))]++;
                if (c[l.find_first_of(s.at(i))] > g) g = c[l.find_first_of(s.at(i))];
            }

            if (u.find_first_of(s.at(i)) != string::npos){
                c[u.find_first_of(s.at(i))]++;
                if (c[u.find_first_of(s.at(i))] > g) g = c[u.find_first_of(s.at(i))];
            }
        }

        for (i = 0; i < 26; ++i){
            if (c[i] == g) cout << l.at(i);
        }
        cout << endl;
    }

    return 0;
}
