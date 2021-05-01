#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

// custom header files
#include "helper.h"
#include "utils.h"


// You code goes below


int main(){
    vector<vector<int>> vv;
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(2);
    
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(2);
    
    vv.push_back(v1);
    vv.push_back(v2);
    
    vector<vector<int>> cv(vv.size());
    copy(vv.begin(), vv.end(), cv.begin());
    
    sort(cv.begin(), cv.end());
    for(int x=0; x<(int)cv.size(); x++) 
    {
        cout << &cv[x] <<endl;
        for(auto y: cv[x])
            cout << y <<"\t";
        cout << endl;
    }
    cout << endl;
    
    vector<int> tv = merge_vector(v1, v2);
    for(auto x: tv) cout << x << "\t";
    cout << endl;
    
    if( !is_uniq(tv) )
        cout<<"and it's not uniq!";
    else
        cout<<"and it's uniq";
    
    return 0;
}

