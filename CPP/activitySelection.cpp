#include<iostream>
using namespace std;
#include<queue>

class activity
{
    public:
    string name;
    int start;
    int finish;
    friend istream& operator>>(istream&,activity&);
    friend ostream& operator<<(ostream&,const activity&);
    bool operator<(const activity&) const;
};
istream& operator>>(istream& in, activity& a)
{
    in>>a.name>>a.start>>a.finish;
}
ostream& operator<<(ostream& out, const activity& a)
{
    out<<a.name<<" ";
}
// overload less than operator so that priority queue can be 
// constructed as desired. We intend to create a min priority
// queue based on finish time of activity
bool activity::operator<(const activity& a) const
{
    return a.finish<finish;
}
void iterative_activity_selector(priority_queue<activity> &pq,vector<activity> &v)
{
    activity a;
    // take activity with minimum finish time
    a = pq.top();
    pq.pop();
    // select it and put it in vector
    v.push_back(a);
    
    while(!pq.empty())
    {
        // if start time of top activity is greater than finish time
        // of current activity then add it to vector and
        // remove top activity from priority queue
        if(pq.top().start>=a.finish)
        {
            a = pq.top();
            v.push_back(a);
        }
        pq.pop();      
        
    }
    
}
int main()
{
    priority_queue<activity> pq;
    int n,i;
    activity a;
    vector<activity> v;
    cin>>n;
    // read input activities and create a priority queue based on
    // finish time 
    for(i=0;i<n;i++)
    {
        cin>>a;
        pq.push(a);
    }

    iterative_activity_selector(pq,v);
    cout<<"Selected activities "<<endl;
    for(auto a:v)
        cout<<a;
}
