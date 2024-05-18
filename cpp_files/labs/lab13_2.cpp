#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
string hash_func(vector<char>str){
    // for(int i=0;i<str.size();i++){
    //     cout<<str[i]<<" ";
    // }
    vector<pair<int,int>> freq(26,pair<int,int>(0,0));
    for(int i=0;i<str.size();i++){
        freq[str[i]-65].first=str[i];
        freq[str[i]-65].second++;
    }
    sort(freq.begin(), freq.end(), [](const pair<int,int>&a, const pair<int, int>&b){
        if(a.second==b.second)
            return a.first<b.first;
        return a.second<b.second;
    });
    string ans="";
    for(auto&  pair:freq){
        char chr = pair.first;
        for(int i=0; i<pair.second;i++){
            ans+=chr;
        }
    }
    return ans;

}

int main(){
    cout<<"how many letters do u want to give?";
    int size;
    cin >> size;
    cout<<"give the letters as uppercase"<<endl;
    vector<char>str;
    for(int i=0;i<size;i++){
        char alpha;
        cin>>alpha;
        str.push_back(alpha);
    }
    string a=hash_func(str);
    cout<<a;
    return 0;
}