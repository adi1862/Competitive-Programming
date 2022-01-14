#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll T;
    cin>>T;
    while(T--){
        ll N,K;
        cin>>N>>K;
        ll A[N+1], curr_sum=0;
        
        for(int i=0; i<N; i++){
            if(i==0)A[i]=1;
            else if(i&1){
                A[i]=(i+1);
            }else{
                A[i]=-(i+1);
            }
        }
        if(K <= ((int)(N/2)+1)){
            for(int i=0;i<N;i++){
                if(A[i]>0)K--;
                if(K<0){
                    A[i]=-(i+1);
                }
            }    
        }else{
            ll new_k=K - (((int)(N/2)+1));
            for(int i=N-1;i>=0;i--){
                if(A[i]<0 && new_k > 0){
                    A[i]=(i+1);
                    new_k--;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            cout<<A[i]<<" ";
        }
        cout<<'\n';
    }
	return 0;
}





// 1 -2 -3 
// 1 2 -3 -4 -5 -6 -7 -8 -9 -10 
// 1 2 -3 4 -5 -6 -7 -8 -9 -10 
// 1 2 -3 4 -5 6 -7 -8 -9 -10 
// 1 2 -3 4 -5 6 -7 8 -9 -10 
// 1 2 -3 4 -5 6 -7 8 -9 10 


// 1 2 -3 4 -5 6 -7 8 -9 10 
// 1 2 -3 4 -5 6 -7 8 -9 10 
// 1 2 -3 4 -5 6 -7 8 -9 10 
// 1 2 -3 4 -5 6 -7 8 -9 10 

