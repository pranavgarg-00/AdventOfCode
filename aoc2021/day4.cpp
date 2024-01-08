#include<iostream>
#include<fstream>
#include<vector>
#include "boost\algorithm\string.hpp"

using namespace std;
int main(){
    string fname = "day4.txt";
    ifstream infile(fname);
    string numbers;
    getline(infile, numbers);
    string line;
    vector<vector<string>> bingos;
    while(getline(infile, line)){
        vector<string> temp;
        for(int i = 0; i < 5; i++){
            string s;
            getline(infile, s);
            temp.push_back(s);
        }
        bingos.push_back(temp);
    }
    vector<vector<vector<int>>> bingos_int;
    for(int i = 0; i < bingos.size(); i++){
        vector<vector<int>> temp;
        for(int j = 0; j < bingos[i].size(); i++){
            vector<int> temp2;
            vector<string> results;
            boost::split(results, bingos[i][j], [](char c){return c == ' '});
            for(int k = 0; k < results.size(); k++){
                stringstream g(results[k]);
                int x = 0;
                g >> x;
                temp2.push_back(x)
            }
            temp.push_back(temp2);
        }
        bingos_int.push_back(temp);
    }
    cout<<bingos_int;
    return 0;
}