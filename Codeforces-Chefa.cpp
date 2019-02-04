#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define eb(a) emplace_back(a);
#define ef(a) emplace_front(a);
#define boost ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
    boost
    ll N;
    cin>>N;
    ll A[N+2];
    for(int i=0;i<N;i++)cin>>A[i];
    ll j=0,max=0,count=0;
    for(ll i=1;i<N;i++){
        if(A[i]<A[j]){
            j=i;
            count=0;
            //if((i-j+1)>max)max=i-j+1;
            continue;
        }
        count++;
        if(count>max)max=count;
        j++;
    }
    cout<<max+1;
}
