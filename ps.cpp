#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct process{
    int pid;
    int burst_time;
    int waiting_time;
    int priority;
    int turn_around_time;
};

void swap(process &a,process &b){
    process temp=a;
    a=b;
    b=temp;
}
int main(){
    int n;
    cout<<"enter number of processes: ";
    cin>>n;
    vector<process>p(n);
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        cout<<"enter burst time for process"<<p[i].pid<<" :";
        cin>>p[i].burst_time;
        cout<<"enter priority for process"<<p[i].pid<<" :";
        cin>>p[i].priority;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].priority>p[j].priority){
                swap(p[i],p[j]);
            }
        }
    }
    p[0].waiting_time=0;
    for(int i=1;i<n;i++){
        p[i].waiting_time=0;
        for(int j=0;j<i;j++){
            p[i].waiting_time+=p[j].burst_time;
        }
    }
    for(int i=0;i<n;i++){
        p[i].turn_around_time=p[i].burst_time+p[i].waiting_time;
    }
    float avg_tat=0,avg_wt=0;
    cout<<"pid\tburst\tpriority\twaiting\tturnaround\n";
    for(int i=0;i<n;i++){
        cout<<p[i].pid<<"\t"<<p[i].burst_time<<"\t"<<p[i].priority
        <<"\t\t"<<p[i].waiting_time<<"\t"<<p[i].turn_around_time<<endl;  
    }
    for(int i=0;i<n;i++){
        avg_tat+=p[i].turn_around_time;
        avg_wt+=p[i].waiting_time;
    }
    cout<<"average turn around time"<<avg_tat/n<<endl;
    cout<<"average waiting time"<<avg_wt/n;
    return 0;


}