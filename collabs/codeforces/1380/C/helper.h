/*/
 * author: mash-97
 * purpose: merges two vectors into a single one
 * returns: returns a vector containing both of the elements in v1 and v2
/*/
vector<int> merge_vector(vector<int> v1, vector<int> v2)
{
    vector<int> v;
    for(auto x: v1) v.push_back(x);
    for(auto x: v2) v.push_back(x);
    return v;
}


/*/
 * author: mash-97
 * purpose: checks if the given vector is unique or not
 * returns: return true if uniq otherwise false
/*/
bool is_uniq(vector<int> v)
{
    vector<int> cv(v.size());
    for(int i=1; i<(int)cv.size(); i++)
    {
        if(cv[i-1]==cv[i]) return false;
    }
    return true;
}

