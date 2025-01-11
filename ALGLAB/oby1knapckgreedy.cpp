#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number of elements ";
    cin>>n;
    int mc;
    cout<<"Enter maximum capacity ";
    cin>>mc;
    vector<int>profits(n),weights(n);
    vector<double>p_by_w(n);
    cout<<"enter profits ";
    for(int i=0;i<n;i++){
        cin>>profits[i];
    }
    cout<<"enter weights ";
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    for(int i=0;i<n;i++){
        p_by_w[i]=profits[i]/(weights[i]*1.0);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p_by_w[i]<p_by_w[j]){
                //arranging in descending order
                swap(p_by_w[i],p_by_w[j]);

                //profits accordingly
               swap(profits[i],profits[j]);

                //weights accordingly
               swap(weights[i],weights[j]);
            }
        }
    }
    //calculating the maximum profit required
    double profit=0;
    for(int i=0;i<n;i++){
        if(mc<weights[i]){
            profit+=mc*p_by_w[i];
            break;
        }
        else{
            profit+=profits[i];
            mc-=weights[i];
        }
    }
    cout<<"maximumprofit is "<<profit<<endl;

}