#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    string fname = "day1.txt";
    ifstream infile(fname);
    string line;
    vector<int> arr;
    int a;
    while(infile >> a){
        arr.push_back(a);
    }
    int ctr = 0;
    for(int i = 0; i < arr.size() - 3; i++){
        if(arr[i+1] + arr[i+2] + arr[i+3] > arr[i] + arr[i+1] + arr[i+2]){
            ctr++;
        }
    }
    cout<<ctr;
    return 0;
}