#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

vector<pair<string, int>> Enc(string text) {
  vector<pair<string, int>> FF; 
  srand(static_cast<unsigned int>(time(NULL))); 
 
  int key = (rand() % 5) + 1;
   
  for(int i = 0; i<text.size(); i++) {
    char c = text[i];
    if(c >= 32 && c <= 126) {
      c = 32 + ((c - 32 + key) % 95);
    }
    text[i] = c;
  }
  
  FF.push_back({text,key});
  return FF;
  
}

string Dec(string text, int key) {
  if(key < 1 || key > 5) {
    cout << "ERROR: Invalid key!" << endl;
    return "Err";
  }
  for(int i = 0; i<text.size(); i++) {
    char c = text[i];
    if(c >= 32 && c <= 126) {
      c = 32 + ((c - 32 - key) % 95);
    }
    text[i] = c;
  }

  return text;
}

int main() {
  string text;
  int ans1;
  while(true) {
  cout << "[1] Encrypt\t[2] Decrypt\t[3] Exit\n";
  cout << "Enter 1-3: ";
  cin >> ans1;
  if(ans1 == 1) {
    cout << "Enter your text: ";
    getline(cin >> ws, text);
    vector<pair<string,int>> FF = Enc(text);
    cout << "Result: " << FF[0].first << endl;
    cout << "Key: " << FF[0].second << " !DO NOT SHOW IT TO ANYONE!" << endl;
    cout << endl << endl;
  }
  else if(ans1 == 2) {
    int key;
    cout << "Enter your text: ";
    getline(cin >> ws, text);
    cout << "Enter a key: ";
    cin >> key;
    cout << "Result: " << Dec(text, key) << endl;
    cout << endl << endl;
  }
  else if(ans1 == 3) {
    cout << "Exiting..." << endl;
    return 0;
  } 
  else {
    cout << "You have to use 1 or 2 or 3" << endl;
  }
  }
  return 0;
}
