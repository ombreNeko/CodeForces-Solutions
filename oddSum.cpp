

    #include <iostream>
    #include <vector>
    using namespace std;
    typedef long long ll;
     
    vector<int> output;
     
    void shift(int index){
     
        output.push_back(0);
        for(int j= output.size()-2;j>=0;j--){
            output[j+1]=output[j];
        }
        output[0]=index;
     
    }
     
    bool oddSumSegments(ll*input,int n,int k,int x,int*dp){
        if(n==0 && k==0){
            return true;
        }
        if((n!=0 && k==0) || (n==0 && k!=0) || n<0){
            return false;
        }
     
        bool ans=false;
        if(input[0]%2 !=0){
            if(dp[0+x-1]!=-1){
                return dp[0+x-1];
            }
            ans= oddSumSegments(input+1,n-1,k-1,x+1,dp);
            
            dp[0+x-1]=ans;
     
            if(ans){
                shift(0+x);
                return true;
            }
        }
        if(ans==false){
            ll first=input[0]%2;
            for(int i=1;i<n;i++){
                ll second=input[i]%2;
                if(first != second){
                    if(dp[i+x-1]!=-1){
                        return dp[i+x-1];
                    }
                    ans=oddSumSegments(input+i+1,n-(i+1),k-1,x+i+1,dp);
                    dp[i+x-1]=ans;
                    if(ans){
                        shift(i+x);
                        return true;
                        //shift , put output[0],break;
                    }
                }
                first=0;
            }
        }
        return false;
    }
     
     
    int main(){
        int q;
        cin>>q;
        while(q--){
            
            int n,k,x=1;
            cin>>n>>k;
            ll*input=new ll [n];
            int*dp=new int[n];
            for(int i=0;i<n;i++){
                dp[i]=-1;
            }
            for(int i=0;i<n;i++){
                cin>>input[i];
            }
     
            if(oddSumSegments(input,n,k,x,dp)){
                cout<<"YES"<<endl;
                vector<int> :: iterator it; 
                for(it=output.begin();it!=output.end() && *it != 0;it++){
                    cout<<*it<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            output.clear();
        }
        
    }