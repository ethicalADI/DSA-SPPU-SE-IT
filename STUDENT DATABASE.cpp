/*
BY:ADITYA KUMAR  
Topic: STUDENT DATABASE
*/

#include<bits/stdc++.h>
using namespace std;

class Student{
    string name;
    int roll;
    float marks;
    public:
    void setData(string n, int r, float m)
    {
        cout<<"ENTER NAME  : ";
        cin>>name;
        cout<<"ENTER ROLL NO: ";
        cin>>roll;
        cout<<"ENTER MARKS : ";
        cin>>marks;
        cout<<" \n";
        
    }

    void displayData(){
        cout<<"Name : "<<name<<endl;
        cout<<"Roll no : "<<roll<<endl;
        cout<<"Marks : "<<marks<<endl;
        
    }

    void linearSearch(Student s[],float key ,int n){
        bool flag =false;
        for (int i = 0; i < n; i++)
        {
            if(s[i].marks == key)
            {
                s[i].displayData();
                flag= true;
            }
        }
        if(flag==false)
        {
            cout<<"INVALID INPUT"<<endl;
        }
        
        
    }
    int binarysearch(Student s[], int n, string p)
    {
			Student obj;
			obj.insertionSort(s, n);
			int low = 0;
			int high = n-1;

			while(low<=high)
			{
				int mid = (low + high)/2;
				if(s[mid].name == p)
					{return mid;
					}

				else if(s[mid].name<p)
				{
					low = mid +1;
				}
				else
				{
					high = mid -1;
				}
			}
			return -1;


		}
    

    

    void bubbleSort(Student s[],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(s[j].roll>s[j+1].roll)
                {
                    swap(s[j],s[j+1]);
                }
            }
        }
      
    }
    void insertionSort(Student s[],int n){
        
        for(int i=1;i<n;i++)
        { for(int j=i;j>=1;j--)
         {if(s[j].name<s[j-1].name)
            {swap(s[j],s[j-1]);
            }
           
          }
        }
    }
           
    
  
int partition(Student s[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = s[low].marks;
    while (i < j)
    {
        while (pivot <= s[i].marks)
            i++;
        while (pivot > s[j].marks)
            j--;
        if (i < j)
         swap(s[i], s[j]);
    }
    swap(s[low], s[j]);
    return j;
}
  
void quickSort(Student s[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(s, low, high);
        quickSort(s, low, pivot - 1);
        quickSort(s, pivot + 1, high);
    }
}

    
};


void menu()
    {   cout<<"\n HERE ARE THE CHOICES!\n";
        cout<<"1-->setData \n";
        cout<<"2-->displayData \n";
        cout<<"3-->By Marks (LINEAR SEARCH)\n";
        cout<<"4-->By Name (BINARY SEARCH)\n";
        cout<<"5-->By Roll (BUBBLE SORT)\n";
        cout<<"6-->By Name (INSERTION SORT)\n";
        cout<<"7-->BY Marks (QUICK SORT)\n";
        cout<<"8-->Exit \n";
}
int main(){
    int n;
    cout<<" ENTER NO OF STUDENT:"<<endl;
    cin>>n;
    Student s[n];
     Student search;
    string name;
    int roll,marks;
    while(true)
    {
   
    menu();
    int c;
    cin>>c;

    
    if(c==1)
    {
          for(int i=0;i<n;i++)
        {
            s[i].setData(name,roll,marks);
            cout<<endl;
        }
        
    }
    else if(c==2){
        for(int i=0;i<n;i++){
            s[i].displayData();

        }
        
    }
    else if(c==3){
        float marks;
        cout<<"Enter the marks: ";
        cin>>marks;
        search.linearSearch(s,m,n);
        
    }
    else if(c==4) 
    {
        string m;
		cout<<"Enter the name: ";
		cin>>m;
		int v;
		v=search.binarysearch(s, n, m);
		if(v==-1)
		{
			cout<<"WRONG INPUT"<<endl;
		}
		else
		{
		s[v].displayData();
		}
		v=0;
		
       
    }
   
    else if(c==5){
        search.bubbleSort(s,n);
        for(int i=0;i<n;i++){

            s[i].displayData();
        }
        
    }
    else if(c==6){
        search.insertionSort(s,n);
        for(int i=0;i<n;i++){
            s[i].displayData();
        }
        
    }
    else if(c==7)
    {
        search.quickSort(s,0,n-1);
        reverse(s,s+n);
        int q;
        cout<<"HOW MANY TOPPER LIST YOU WANT : ";
        cin>>q;
        for(int i=0;i<q;i++)
        {
            s[i].displayData();
        }
        
    }
    
      else if(c == 8)
	    {
	    	cout << "Thank You!" ;
	    	
	    }
	    else
	    {
	    	cout << "Invalid Choice. Try again." ;
	    }
    }

}
