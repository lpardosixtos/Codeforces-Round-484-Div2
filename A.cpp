#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n;
    string s;
    cin >> n >> s;

    int rights=0;
    int ones=0;
    if(n==1){
        if(s[0]=='1'){
            cout << "Yes\n";
        }
        else cout << "No\n";
        return 0;

    }
    if(n==2){
        for(int i=0; i<n; i++){
            if(s[i]=='0') rights++;
        }
        if(rights!=1) cout << "No\n";
        else cout << "Yes\n";
        return 0;
    }
    int ind=0;
    while(s[ind]=='0') ind++;
    if(ind>1){
        cout << "No\n";
        return 0;
    }
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            rights++;
            ones=0;
            if(rights==3){
                cout << "No\n";
                return 0;
            }
        }
        else{
            ones++;
            rights=0;
            if(ones==2){
                cout << "No\n";
                return 0;
            }
        }
    }
    if(s[n-2]=='0' && s[n-1]=='0'){
        cout << "No\n";
    }
    else cout << "Yes\n";


    return 0;
}
