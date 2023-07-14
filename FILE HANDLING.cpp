/*
BY:ADITYA KUMAR  
Topic: FILE HANDLING
*/

#include <bits/stdc++.h>
using namespace std;

struct DoB
{
    int day, month, year;
};

struct stdform
{
    int roll_no;
    string name, address;
    DoB dob;
    float percent;
};

class filee
{
    stdform std_rec;
    public :
        void CreateAFile();
        void AddNewRecord();
        void DisplayFileContent();
        void SearchRecord();
        void ModifyRecord();
        void DeleteRecord();
};

void filee :: CreateAFile()
{
    ifstream file_exist("Data.txt");
    if(file_exist) 
    {
        cout<<"\nFile 'Data.txt' already exist\n";
        return;
    }
    fstream file("Data.txt", ios::out | ios::binary); 
    cout<<"\nNew file Data.txt created..\n";
    AddNewRecord();
    file.close();
}

void filee :: AddNewRecord()
{
    cout<<"\nFill student details :\nRoll No. : ";
    cin>>std_rec.roll_no;
    cin.ignore();
    fstream write_file("Data.txt", ios::app | ios::binary); 
    fstream read_file("Data.txt", ios::in | ios::binary); 
    
    stdform s1;
    read_file.read((char*)&s1, sizeof(s1));
    int flag = 1;
    while(!read_file.eof())
    {
        if(s1.roll_no == std_rec.roll_no)
        {
            cout<<"\nStudent with roll no. "<<std_rec.roll_no<<" already exist !\n";
            flag = 0;
            break;
        }
        else
        {
            read_file.read((char*)&s1, sizeof(s1));
        }
    }
    if(flag == 1)
    {
        cout<<"\nName : ";
        getline(cin, std_rec.name);
        cout<<"\nAddress : ";
        getline(cin, std_rec.address);
        cout<<"\nDate of birth(DD/MM/YYYY) : ";
        string date;
        getline(cin, date);
        std_rec.dob.day = stoi(date.substr(0, 2));
        std_rec.dob.month = stoi(date.substr(3, 2));
        std_rec.dob.year = stoi(date.substr(6, 4));
        cout<<"\nPercentage marks : ";
        cin>>std_rec.percent;
        write_file.write((char*)&std_rec, sizeof(std_rec)); 
        cout<<"\nRecord added successfully to the file !\n";
    }
    read_file.close();
    return;
}

void filee :: DisplayFileContent()
{
    fstream read_file;
    read_file.open("Data.txt", ios::in | ios::binary);
    if(!read_file)
    {
        cout<<"\nFile Not Found !\n";
        return;
    }
    else
    {
        read_file.read((char*)&std_rec, sizeof(std_rec)); 
        cout<<"\nRoll No.\tName\t\tDoB\t\tPercentage\tAddress\n";
        while(!read_file.eof())
        {
            cout<<"\n"<<std_rec.roll_no<<"\t\t"<<std_rec.name<<"\t"<<std_rec.dob.day<<"/"<<std_rec.dob.month<<"/"<<std_rec.dob.year<<"\t"<<std_rec.percent<<"\t\t"<<std_rec.address;
            read_file.read((char*)&std_rec, sizeof(std_rec)); 
        }
    }
    read_file.close();
}

void filee :: SearchRecord()
{
    fstream read_file("Data.txt", ios::in | ios::binary); 
    if(!read_file)
    {
        cout<<"\nFile Not Found !\n";
        return;
    }
    else
    {
        bool flag = false;
        cout<<"\nEnter roll no. to be searched : ";
        int key;
        cin>>key;
        read_file.read((char*)&std_rec, sizeof(std_rec));
        while(!read_file.eof())
        {
            if(std_rec.roll_no == key)
            {
                cout<<"\nRecord found !\n";
                flag = true; 
                cout<<"\nRoll No.\tName\t\tDoB\t\tPercentage\tAddress\n---------------------------------------------------------------------------";
                cout<<"\n"<<std_rec.roll_no<<"\t\t"<<std_rec.name<<"\t"<<std_rec.dob.day<<"/"<<std_rec.dob.month<<"/"<<std_rec.dob.year<<"\t"<<std_rec.percent<<"\t\t"<<std_rec.address;  
                break;
            }
            else
            {
                read_file.read((char*)&std_rec, sizeof(std_rec)); 
            }
        }
        if(!flag) 
            cout<<"\nRecord not found !\n";
    }
    read_file.close();
}

void filee :: ModifyRecord()
{
    cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    fstream read_file("Data.txt", ios::in | ios::binary); 
    fstream newFile("temp.txt", ios::out | ios::binary); 
    if(!read_file)
    {
        cout<<"\nFile Not Found !\n";
        return;
    }
    else
    {
        read_file.read((char*)&std_rec, sizeof(std_rec));
        while(!read_file.eof())
        {
            if(std_rec.roll_no != rno)  
            {
                newFile.write((char*)&std_rec, sizeof(std_rec));  
            }
            else
            {
                cout<<"\nRecord Found !\n";
                flag = 1;
                cout<<"\nFill student details :\nRoll No. : "<<rno;
                std_rec.roll_no = rno;
                cin.ignore();
                cout<<"Name : ";
                getline(cin, std_rec.name);
                cout<<"Address : ";
                getline(cin, std_rec.address);
                cout<<"Date of birth(DD/MM/YYYY) : ";
                string date;
                getline(cin, date);
                std_rec.dob.day = stoi(date.substr(0, 2));
                std_rec.dob.month = stoi(date.substr(3, 2));
                std_rec.dob.year = stoi(date.substr(6, 4));
                cout<<"Percentage marks : ";
                cin>>std_rec.percent;
                newFile.write((char*)&std_rec, sizeof(std_rec));  
                cout<<"Record updated successfully to the file !\n"; 
            }
            read_file.read((char*)&std_rec, sizeof(std_rec));  
        }
        read_file.close();
        newFile.close();
        remove("Data.txt");
        rename("temp.txt", "Data.txt");
        if(flag == 0) 
        {
            cout<<"\nRecord with roll no. "<<rno<<" is not found in the file 'Data.txt'\n";
        }
    }
}

void filee :: DeleteRecord()
{
    cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    fstream read_file("Data.txt", ios::in | ios::binary); 
    fstream newFile("temp.txt", ios::out | ios::binary);
    if(!read_file)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        read_file.read((char*)&std_rec, sizeof(std_rec));
        while(!read_file.eof())
        {
            if(std_rec.roll_no != rno) 
            {
                newFile.write((char*)&std_rec, sizeof(std_rec)); 
            }
            else 
            {
                cout<<"\nRecord Found and Deleted!\n";
                flag = 1;
            }
            read_file.read((char*)&std_rec, sizeof(std_rec)); 
        }
        read_file.close();
        newFile.close();
        remove("Data.txt");
        rename("temp.txt", "Data.txt");
        if(flag == 0)
        {
            cout<<"\nRecord with roll no. "<<rno<<" is not found in the file 'Data.txt'\n";
        }
    }
}
void menu()
{
        cout<<"<--------------MENU------------------->"<<endl;
        cout<<"Choose the desired option : "<<endl;
        cout<<"1.Create File"<<endl;
        cout<<"2.Add Record"<<endl;
        cout<<"3.View Records "<<endl;
        cout<<"4.Search Record"<<endl;
        cout<<"5.Modify Record"<<endl;
        cout<<"6.Delete Record"<<endl;
        cout<<"7.Exit"<<endl;
}
int main()
{
    filee fileOp;
    while(true)
	{
		menu() ;
	    int choice ;
	    cin >> choice ;
	    cout << "\n" ;
	    if(choice == 1)
	    
              {  fileOp.CreateAFile();
                break;}
            else if(choice==2)
               { fileOp.AddNewRecord();
                break;}
            else if(choice==3)
               { fileOp.DisplayFileContent();
                break;}
            else if(choice==4)
               { fileOp.SearchRecord();
                break;}
            else if(choice==5)
               { fileOp.ModifyRecord();
                break;}
            else if(choice==6)
               { fileOp.DeleteRecord();
                break;}
            else if(choice == 7)
	         {cout << "Thank You!" ;
	    	}
	    else
	    {cout << "Invalid Choice. Try again." ;
	    }
    }
   
}

