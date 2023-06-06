class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
    // sbse chhota diff nikal,
    // agar sare diff us d ke multiple hain to ap hai

    sort(arr.begin(),arr.end());

   int d= arr[1]-arr[0];
    for(int i=1;i<arr.size()-1;i++){
        if(arr[i+1]-arr[i] != d)
        return 0;
    }
    return 1;



    }
};