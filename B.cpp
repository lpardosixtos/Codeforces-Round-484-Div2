#include <bits/stdc++.h>

using namespace std;

int ans[4000000];
string person;

int main(void){

    priority_queue<pair< int, int> > introverts;
    priority_queue<pair< int, int> > free;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int aux;
        cin >> aux;
        pair<int, int> auxi(-aux, i+1);
        free.push(auxi);
    }
    cin >> person;
    for(int i=0; i<2*n; i++){
        if(person[i]=='0'){
            pair<int, int> auxi=free.top();
            auxi.first*=-1;
            ans[i]=auxi.second;
            free.pop();
            introverts.push(auxi);
        }
        else{
            pair<int, int> auxi=introverts.top();
            ans[i]=auxi.second;
            introverts.pop();
        }
    }
    cout << ans[0];
    for(int i=1; i<2*n; i++){
        cout << " " << ans[i];
    }
    cout << "\n";
    return 0;
}
