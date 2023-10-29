#include <iostream>
using namespace std;

class PriorityQueue {
private:
    struct Node {
        int data,priority;
        string p;
    }*arr;

    int maxCapacity,size;

public:
    PriorityQueue(int maxCapacity){
        size=0; 
        arr = new Node[maxCapacity];
    }

    ~PriorityQueue() {
        delete[] arr;
    }

    void enqueue(int Burst_time, int priority,string name) {
        if (size >= maxCapacity) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        int i = size;

        // Find the appropriate position for the new element based on priority
        while (i > 0 && priority < arr[i - 1].priority) {
            arr[i] = arr[i - 1];
            i--;
        }

        arr[i].data = Burst_time;
        arr[i].p = name;
        arr[i].priority = priority;
        size++;
    }
    
    int dequeue() {
        float cnt=0,count=0;
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a default value indicating failure
        }
        cout<<"GANTT-CHART"<<endl<<"Arrival time=0"<<endl;
        int d=0;
        for(int i=0;i<size;i++)
        {
            cout<<"  "<<arr[i].p<<"  ";
        }
        cout<<endl<<"0";
        for(int i=0;i<size;i++)
        {
            d+=arr[i].data;
            cout<<"    "<<d;
        }
        cout<<endl;
        cout<<"Turn-Around Time"<<endl;
        int a=0,TA[10];
        for(int i=0;i<size;i++)
        {
            a+=arr[i].data;
            TA[i]=a;
            cout<<"Turn-Around time for process "<<arr[i].p<<" = "<<a<<endl;
        }
        for (int i = 0; i<size; i++)
        {
            cnt+=TA[i];
        }
        cnt=cnt/size;
        cout<<"Average Turn-around time of = "<<cnt<<" msec"<<endl;
        cout<<"Waiting Time"<<endl;
        int b=0,WT[10];
        for(int i=0;i<size;i++)
        {
            b+=arr[i].data;
            WT[i]=b-arr[i].data;
            cout<<"Waiting time for process "<<arr[i].p<<" = "<<WT[i]<<endl;
        }
        for (int i = 0; i<size; i++)
        {
            count+=WT[i];
        }
        count=count/size;
        cout<<"Average Waiting time of = "<<count<<" msec"<<endl;
        return 0;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    int n,Burst_time,prio;
    string name;
    PriorityQueue pq(10);

    cout<<"Enter the number of processes : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the name of process :";
        cin>>name;
        cout<<"Enter the Burst time of process :";
        cin>>Burst_time;
        cout<<"Enter the priority of process :";
        cin>>prio;
        pq.enqueue(Burst_time,prio,name);
    }
    
        pq.dequeue();

    return 0;
}