#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    string fname = "day2.txt";
    ifstream infile(fname);
    string line;
    vector<int> arr;
    vector<string> arr2;
    string s;
    int a;
    while(infile >> s >> a){
        arr2.push_back(s);
        arr.push_back(a);
    }
    int x = 0;
    int y = 0;
    int aim = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr2[i].compare("forward") == 0){
            x += arr[i];
            y += aim*arr[i];
        }
        else if(arr2[i].compare("down") == 0){
            aim += arr[i];
        }
        else if(arr2[i].compare("up") == 0){
            aim -= arr[i];
        }        
    }
    cout<<x*y;
    return 0;
}