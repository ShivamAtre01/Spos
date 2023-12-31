#include<iostream>
#include<string.h>
using namespace std;

void SJF_pre(int n,int BT[],string p[],int AT[])
{
    int Finish_time[10],TA[10],WT[10];
    float cnt=0,count=0;
    for (int i = 0; i<n; i++)
    {
        if(i==0)
        {   Finish_time[i]=BT[i]+AT[i];
            TA[i]=Finish_time[i]-AT[i];
        }
        else
        {
            Finish_time[i]=BT[i]+Finish_time[i-1];
            TA[i]=Finish_time[i]-AT[i];
        }
    }
    cout<<endl;
    cout<<"Premptive"<<endl;
    cout<<"GANTT-CHART"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"  "<<p[i]<<"  ";
    }
    cout<<endl;
    cout<<AT[0];
    int d=BT[0]+AT[0];
    for(int i=0;i<n;i++)
    {
        cout<<"    "<<d;
        d=d+BT[i+1];
    }
    cout<<endl;
    cout<<"TURN-AROUND TIME "<<endl;
    for (int i = 0; i<n; i++)
    {
        cout<<"Turn-around time of "<<p[i]<<"= "<<TA[i]<<" msec"<<endl;
    }
    for (int i = 0; i<n; i++)
    {
        cnt+=TA[i];
    }
    cnt=cnt/n;
    cout<<"Average Turn-around time of = "<<cnt<<" msec"<<endl;
    cout<<endl;
    for (int i = 0; i<n; i++)
    {
        WT[i]=TA[i]-BT[i];
        cout<<"Waiting time of "<<p[i]<<"= "<<WT[i]<<" msec"<<endl;
    }
    for (int i = 0; i<n; i++)
    {
        count+=WT[i];
    }
    count=count/n;
    cout<<"Average Waiting time of = "<<count<<" msec"<<endl;
}

int main()
{
    int n,s, BT[10],AT[10];
    string p[10];
    cout<<"Enter the number of process: ";
    cin>>s;
    for (int i = 0; i<s; i++)
    {
        cout<<"Enter the process name: ";
        cin>>p[i];
        cout<<"Enter the Burst time :";
        cin>>BT[i];
        cout<<"Enter the Arrival time : ";
        cin>>AT[i];
        if(AT[i]!=0)
        {
            if(i>1)
            {
                if(BT[i]<BT[i-1])
                {
                    int c=BT[i];
                    string q=p[i];
                    BT[i]=BT[i-1];
                    p[i]=p[i-1];
                    BT[i-1]=c;
                    p[i-1]=q;
                }
            }
        }
    }
    SJF_pre(s,BT,p,AT);
    return 0;
