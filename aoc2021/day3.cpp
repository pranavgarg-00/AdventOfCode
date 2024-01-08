#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    string fname = "day3.txt";
    ifstream infile(fname);
    string line;
    vector<string> arr;
    string s;
    while(infile >> s){
        arr.push_back(s);
    }
    int lenstring = arr[0].size();
    int size = arr.size();
    vector<int> counts;
    for(int i = 0; i < lenstring; i++){
        int temp = 0;
        for(int j = 0; j < size; j++){
            temp += ((int)arr[j][i] - 48);
        }
        counts.push_back(temp);
    }
    string res1 = "";
    string res2 = "";
    for(int i = 0; i < lenstring; i++){
        if(counts[i] > size/2){
            res1 = res1 + "1";
            res2 = res2 + "0";
        }
        else{
            res1 = res1 + "0";
            res2 = res2 + "1";
        }
    }

    
    int index = 0;
    vector<string> compliant1;
    vector<string> temp = arr;
    while(temp.size() > 1){
        int ctr1 = 0;
        for(int i = 0; i < temp.size(); i++){
            ctr1 += ((int)temp[i][index] - 48);
        }
        string curres1 = "";
        if(ctr1 >= temp.size()/2.0){
            curres1 += "1";
        }
        else{
            curres1 += "0";
        }

        for(int i = 0; i < temp.size(); i++){
            if(temp[i][index] == curres1[0]){
                compliant1.push_back(temp[i]);
            }
        }
        index++;
        temp = compliant1;
        compliant1.clear();
    }

    index = 0;
    vector<string> compliant2;
    vector<string> temp2 = arr;
    while(temp2.size() > 1){
        int ctr2 = 0;
        for(int i = 0; i < temp2.size(); i++){
            ctr2 += ((int)temp2[i][index] - 48);
        }
        string curres2 = "";
        if(ctr2 < temp2.size()/2.0){
            curres2 += "1";
        }
        else{
            curres2 += "0";
        }
        for(int i = 0; i < temp2.size(); i++){
            if(temp2[i][index] == curres2[0]){
                compliant2.push_back(temp2[i]);
            }
        }
        index++;
        temp2 = compliant2;
        compliant2.clear();
    }
    cout << stoi(temp[0], nullptr, 2)*stoi(temp2[0], nullptr, 2) << endl;
    cout << stoi(temp[0], nullptr, 2) << endl;
    cout << stoi(temp2[0], nullptr, 2) << endl;

    return 0;
}