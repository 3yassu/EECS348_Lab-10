#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "calculator.hpp"
using namespace std;
int main(int argc, char *argv[]) {
    string filename;
    cout << "Enter file name (with .txt): ";
    cin >> filename;
    vector<string> valid_str_vec;
    string reader;
    ifstream file(filename);
    while(getline(file, reader)){
        int readsize = reader.size();
        if(readsize == 0){cout << "Not valid!" << endl; continue;}
        if(reader[reader.size() - 1] == 0x0A){reader.erase(reader.size() - 1);}
        while(reader[reader.size() - 1] <= 0x20 || reader[reader.size() - 1] == 0x7F){reader.erase(reader.size() - 1);}
        while(reader[0] <= 0x20 || reader[0] == 0x7F){reader.erase(0, 1);}
        if(isNum(reader)){
            valid_str_vec.push_back(reader);
        }else{
            cout << reader << " is an Invalid double!" << endl;
        }
    }
    int size = valid_str_vec.size();
    for(int i = 0; i < size; i++){
        cout << valid_str_vec[i] << " - 123.456 = " << str_adder(valid_str_vec[i], "-123.456") << endl;
    }
    return 0;
}
