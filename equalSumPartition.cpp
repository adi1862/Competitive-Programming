bool canPartition(vector<int>& nums) {
          // code here
        long long sum=0;
        int N=nums.size();
        for(int i=0;i<N;i++)sum+=nums[i];
        if(sum%2 !=0)return 0;
        else{
            return subsetSum(sum/2, nums, N);
        }
    }
    int subsetSum(long long sum, vector<int>& arr, int N){
        // int t[N+1][sum+1];
        // for(int i=0;i<=N;i++){
        //     for(int j=0;j<=sum;j++){
        //         if(i==0){
        //             t[i][j]=0;
        //         }
        //         if(j==0){
        //             t[i][j]=1;
        //         }
        //     }
        // }
        // for(int i=1;i<=N;i++){
        //     for(int j=1;j<=sum;j++){
        //         if(arr[i-1]<=j){
        //             // t[i][j] = v[n-1] + t[n-1][w-wt[n-1]] , t[n-1][w] 
        //             t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j]; 
        //         }
        //         else{
        //             t[i][j] = t[i-1][j];
        //         }
        //     }
        // }
        // return t[N][sum];
        if(sum == 0)return 1;
        if(N == 0 && sum != 0)return 0;
        
        if(arr[N-1] <= sum){
            return subsetSum(sum-arr[N-1],arr, N-1 ) || subsetSum(sum, arr,N-1);
            
        }
        else{
            return subsetSum(sum, arr,N-1);
        }
    }
