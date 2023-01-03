// backtracking
vector<vector<int>> combinations;

void combinationSum3_(int k, int n, vector<int>&current, vector<vector<int>>& combinations) {
    if(current.size() == k && n == 0) {
        combinations.push_back(current);
        return;
    } else {
        int i = (current.size() > 0) ? current.back() + 1 : 1;
        for(i; i < 10; i++) {
            // cout << k;
            if(current.size() < k) {
                current.push_back(i);
                combinationSum3_(k, n-i, current, combinations);
                current.pop_back();
            } 
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> current;
    combinationSum3_(k, n, current, combinations);
    return combinations;
}
