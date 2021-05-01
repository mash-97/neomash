#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

// custom header files
#include "helper.h"
#include "utils.h"


// You code goes below


int main(){
    vector<vector<int>> vv;
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(2);
    
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(2);
    
    vv.push_back(v1);
    vv.push_back(v2);
    
    for(int x=0; x<(int)vv.size(); x++) 
    {
        cout << &vv[x] <<endl;
        for(auto y: vv[x])
            cout << y <<"\t";
        cout << endl;
    }
    return 0;
}

