
/*
BY:ADITYA KUMAR  
Topic: CIRCULAR QUEUE
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int f=-1,r=-1;
void display(int arr[])
{
    if(f==-1 && r==-1)
    {
        cout<<"queue is empty\n";
    }
    else if(f<=r)
    {
            cout<<"QUEUE\n";
        for(int i=f;i<=r;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    else{
          cout<<"QUEUE\n";
        for(int i=f;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=r;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}


void enqueue(int arr[],int val)
{

    if((r+1)%n==f)
    {
        cout<<"\nqueue is full\n";
    }
    else
    {
        if(f==-1)
        {
            f=0;
        }
        r=(r+1)%n;
        arr[r]=val;
    }



}

void dequeue(int arr[])
{
    if(f==-1 && r==-1){
        cout<<"\nQUEUE IS EMPTY\n";
    }
    else if(f==r){
        cout<<arr[f]<<" is deleted from queue\n";
        f=-1;r=-1;

    }
    else
    {
        cout<<arr[f]<<" is deleted from queue\n";
        f=(f+1)%n;
    }
}

void menu( )
{
	  cout<<"Enter your choice: \n";
        cout<<"1.Insertion \n";
        cout<<"2.Deletion \n";
        cout<<"3.Display \n";
        cout<<"4.Exit \n";
}

int main(){
    cout<<"enter size of  array : \n";
    cin>>n;
    int arr[n];
    while(true)
    {
         menu();
        int c;
        cin>>c;
         
         cout<<"\n";
        if(c==1){
            cout<<" ENTER THE VALUE YOU WANT TO INSERT: ";
            int x;cin>>x;
            enqueue(arr,x);
        }
        else if(c==2){
            dequeue(arr);
        }
        else if(c==3){
            display(arr);
        }
        else if(c==4){
            break;
        }
        else{
            cout<<"\n please enter valid choice: \n";
        }
    }

}
