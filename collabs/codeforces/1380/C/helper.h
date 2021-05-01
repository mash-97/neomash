/*/
 * author: mash-97
 * purpose: merges two vectors into a single one
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
 * purpose: checks
/*/
bool is_uniq(vector<int> v)
{
    return true;
}

