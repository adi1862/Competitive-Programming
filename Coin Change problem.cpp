#include<bits/stdc++.h>
using namespace std;
/*---------------------------Coin Change Probelm--------------------------------------------------

The idea behind this algorithm is to create a combination array that will contain the combination of the coin of given denomination
corresponding to each index, index is actually denoting the value that we want to get using these coins.  

we will take coins one by one of given denomination then we will first check if the coin value is less than the amount(index)
i.e if(inddex >= coin[i])

if th above combination is true then simply update the corresponding value of combination 
i.e combination[index] += combination[index - coin[i]];

*/


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
