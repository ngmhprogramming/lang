#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, string>> vpis;
vpis tokens;
string line;

void tokenize(string a){
  string b, open;
  int c;
  for(int i = 0; i < a.size(); i++){
    c = -1;
    if(a[i] != '\n') b += a[i];
    if(a[i] == '\"') open = a[i];
    if(open == "\"" && a[i] == '\"') c = 10;
    if(b == "int") c = 1;
    if(b == "string") c = 2;
    if(b == "array") c = 3;
    if(b == "stack") c = 4;
    if(b == "queue") c = 5;
    if(c != -1){
      tokens.push_back(make_pair(c, b));
      b = "";
      open = "";
    }
  }
}

int main() {
  freopen("code.txt", "r", stdin);
  while(!cin.eof()){
    getline(cin, line, ';');
    tokenize(line);
  }
  for(vpis::iterator it = tokens.begin(); it != tokens.end(); it++){
    cout<<(*it).first<<" "<<(*it).second<<endl;
  }
}
