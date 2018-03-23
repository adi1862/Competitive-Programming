/*created by adi1862 FLIPPING THE COIN*/
#include <stdio.h>
#include<limits.h>
#include<math.h>
int sum(int a,int b){   //for returning miniumum
    return a+b;
}
void build(int a[],int seg[],int low, int high,int pos){    //build segment tree
    if(high==low){seg[pos]=a[low];  return;}  // condition to check leaf node
    int mid=(high+low)/2;  
    build(a,seg,low,mid,pos*2+1);             //left child
    build(a,seg,mid+1,high,pos*2+2);            //right child
    seg[pos]=sum(seg[2*pos+1],seg[2*pos+2]);    //setting parent node according to the requirement
    
}
int query(int seg[],int lazy[],int low, int high,int qlow, int qhigh,int pos ){ // query function
    if(high<low)return 0;             
    if(lazy[pos]!=0){                         
        seg[pos]=(high-low+1)-seg[pos];    //upating the segment tree according to lazy tree
        if(high!=low){          // if this is not the leaf node then propagate the value
        
            lazy[2*pos+1]=1-lazy[pos*2+1]; // to left child node
            lazy[2*pos+2]=1-lazy[pos*2+2]; // to right child node
            
        }
        lazy[pos]=0;
    }
    if(qlow<=low&&qhigh>=high)return seg[pos]; // total overlapping 
    if(qlow>high||qhigh<low)return 0;     // no overlapping
     
     
     int mid=(high+low)/2;
        return sum(query(seg,lazy,low,mid,qlow, qhigh,pos*2+1),query(seg,lazy,mid+1,high,qlow, qhigh,pos*2+2)); // returning the miniumum to the parent
    
    
}
void update(int seg[],int lazy[],int low,int high,int ulow,int uhigh,int delta ,int pos){
    if(low>high)return;
    if(lazy[pos]!=0){
        
        seg[pos]=(high-low+1)-seg[pos];           //updating the segment tree with corresponding lazy 
        
        if(high!=low){
            
            lazy[2*pos+1]=1-lazy[pos*2+1]; //propagating to the left child
            lazy[2*pos+2]=1-lazy[pos*2+2]; // propagating to the right child
        
            
        }
        lazy[pos]=0;
    }
    if(ulow<=low&&uhigh>=high) // total overlapping
    {
        seg[pos]=(high-low+1)-seg[pos];       // updating the parent child 
        if(high!=low){
            lazy[2*pos+1]=1-lazy[pos*2+1];  // updating the left child
            lazy[2*pos+2]=1-lazy[pos*2+2];  // updating the right child
        }
       return ;
    }
    if(ulow>high||uhigh<low)return ;
    int mid=(high+low)/2;
    update(seg,lazy,low,mid,ulow,uhigh,delta,2*pos+1); 
    update(seg,lazy,mid+1,high,ulow,uhigh,delta,2*pos+2); 
    seg[pos]=sum(seg[pos*2+1],seg[2*pos+2]);
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    int A[n];
    int m=pow(2,1+ceil(log2(n)));
    int seg[m],lazy[m];
    for(int i=0;i<m;i++){lazy[i]=0;seg[i]=0;}
    for(int i=0;i<n;i++)A[i]=0;
    
    //for(int i=0;i<n;i++)scanf("%d",&A[i]);
    
    build(A,seg,0,n-1,0);

     int k,left,right,value;
    
    while(q!=0){
        scanf("%d",&k);
        
        if(k==0){
        scanf("%d%d",&left,&right);
        update(seg,lazy,0,n-1,left,right,value,0);
        }
        else if(k==1){
        scanf("%d%d",&left,&right);
        printf("%d\n",query(seg,lazy,0,n-1,left,right,0));
        }
        q--;
    }
//	for(int i=0;i<m;i++)printf("%d ",seg[i]);
	return 0;
}
