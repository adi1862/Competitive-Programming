#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int> coins,int amount){
    int com[amount+3];
    memset(com,0,sizeof(com));
    com[0]=1;
    
    for(int i=0;i<coins.size();i++){
        for(int j=0;j<=amount;j++){
            if(j>=coins[i]){
                com[j]+=com[j-coins[i]];
            }
        }
    }
    //for(int i=0;i<=amount;i++)cout<<com[i]<<' ';
    return com[amount];

}
int main(){
    int amount,n;
    vector<int> v={1,2,5};
    cin>>amount;
    cout<<coinChange(v,amount);

}
