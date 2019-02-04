//AC IN one go // spoj PPATH //
/*the concept is simple we just have to find all the four digit combination
 of the prime numbers by replacing a digit at a time and putting them at the same level of tree

 */

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
bool prime[10000+1];
void sieve(ll n){

    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
           for(int k=i*i;k<=n;k+=i){
                prime[k]=false;
           }
        }
    }
}
int main(){
    sieve(10000);
    ll T;
    cin>>T;
    while(T--){
        ll N,M;
        cin>>N>>M;
        queue<pair<ll,ll> > q;
        q.push(make_pair(N,0));
        bool mark[10000];
        memset(mark,false,sizeof(mark));//marking the integers so that they can be used only once
        while(!q.empty()){
            ll top=q.front().first;
            if(top==M){
                cout<<q.front().second<<'\n';
                break;
            }
            else{
                ll ones=top%10;
                ll tens=(top/10)%10;
                ll hun=(top/100)%10;
                ll th=(top/1000)%10;
                for(int i=0;i<=9;i++){
                    ll num=th*1000+hun*100+tens*10+i;//hitting the values at ones place
                    if(mark[num]==false&&prime[num]){
                        q.push(make_pair(num,q.front().second+1));
                        mark[num]=true;
                    }
                }
                for(int i=0;i<=9;i++){
                    ll num=th*1000+hun*100+i*10+ones;//hitting the values at tens place
                    if(mark[num]==false&&prime[num]){
                        q.push(make_pair(num,q.front().second+1));
                        mark[num]=true;
                    }
                }
                for(int i=0;i<=9;i++){
                    ll num=th*1000+i*100+tens*10+ones;//hitting the values at hundredth place
                    if(mark[num]==false&&prime[num]){
                        q.push(make_pair(num,q.front().second+1));
                        mark[num]=true;
                    }
                }
                for(int i=1;i<=9;i++){
                    ll num=i*1000+hun*100+tens*10+ones;//hitting the values at thousandth place we can't hit 0 in this
                    if(mark[num]==false&&prime[num]){
                        q.push(make_pair(num,q.front().second+1));
                        mark[num]=true;
                    }
                }
            }
            q.pop();
        }
    }
}
