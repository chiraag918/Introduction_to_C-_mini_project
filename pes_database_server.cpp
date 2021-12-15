#include "pes_database.h"

char def_deg[][45]={"Bachelor of Technology (B.Tech)","Master of Technology (M.Tech)","Bachelor of Architecture (B.Arch)","Bachelor of Business Administration (BBA)","Master of Business Administration (MBA)"};
char def_tech[][35]={"Computer Science Engg.","Electronics Engg.","Electrical and Electronics Engg.","Mechanical Engg.","Biotech Engg.","Civil Engg.","Business Administration","Architecture"};

pes_info::pes_info()
    {
        name[0]='\0';
        role[0]='\0';
        phno=0;
        email[0]='\0';
        bloodgrp[0]='\0';
    }


void pes_info::input(int d)
    {
        int ch=-1,k=1;
        
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nEnter General Details:"<<endl<<"\nName: ";
        gets(name);
        
        if(d==1)
            strcpy(role,"Student");
        else
            strcpy(role,"Teacher");
        
        cout<<"Phone Number: ";
        cin>>phno;
        cout<<"Email: ";
        cin>>email;
        
        k=1;
        
        while(k==1)
        {
            cout<<"\nBlood Group:\n1.A+  2.B+\n3.AB+ 4.O+\n5.A-  6.B-\n7.AB- 8.O-\nEnter choice: ";
            cin>>ch;
            if(ch>=1&&ch<=8)
            {
                if(ch==1)
                   strcpy(bloodgrp,"A+");
                else if(ch==2)
                    strcpy(bloodgrp,"B+");
                else if(ch==3)
                    strcpy(bloodgrp,"AB+");
                else if(ch==4)
                    strcpy(bloodgrp,"O+");
                else if(ch==5)
                   strcpy(bloodgrp,"A-");
                else if(ch==6)
                    strcpy(bloodgrp,"B-");
                else if(ch==7)
                    strcpy(bloodgrp,"AB-");
                else if(ch==8)
                    strcpy(bloodgrp,"O-");
                
                k=0;
            }
            else
                cout<<"Wrong choice, try again"<<endl;
          
        }
        
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }
    
void pes_info::display()
    {
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nGeneral Details:\n\nName          : "<<name<<endl;
        cout<<"Role          : "<<role<<endl;
        cout<<"Phone Number  : "<<phno<<endl;
        cout<<"E-mail        : "<<email<<endl;
        cout<<"Blood Group   : "<<bloodgrp<<endl;
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }

    
char* pes_info::ret_name()
    {
        return name;
    }
    


student::student()
    {
        pes_info();
        srn[0]='\0';
        cgpa=0;
        curr_sem=0;
        degree[0]='\0';
        branch[0]='\0';
    }
    
  
bool student::compare_srn(const student &first, const student &second)
    {
        if(strcmp(first.srn,second.srn)<0)
            return true;
        return false;
    }
    

bool student::compare_name(student &first, student &second)
    {
        if(strcmp(first.ret_name(),second.ret_name())<0)
            return true;
        return false;
    }
    
void student::input_student()
    {
        int ch=-1,k=1;
        
        input(1);
        
        
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nEnter Student Details:"<<endl<<"\nSRN: ";
        cin>>srn;
        cout<<"CGPA: ";
        cin>>cgpa;
        
        while(k==1)
        {
            cout<<"\nDegree:\n";
            for(int i=0;i<5;i++)
            {
                cout<<i+1<<". "<<def_deg[i]<<endl;
            }
            cout<<"\nEnter choice: ";
            cin>>ch;
            if(ch>=1&&ch<=5)
            {
                strcpy(degree,def_deg[ch-1]);
                k=0;
            }
            else
                cout<<"Wrong choice, try again"<<endl;
        }
        
        k=1;
        
        if(ch!=1 && ch!=2)
            strcpy(branch,"");
        else
        {
            while(k==1)
            {
                cout<<"\nBranch:\n";
                for(int i=0;i<6;i++)
                {
                    cout<<i+1<<". "<<def_tech[i]<<endl;
                }
                cout<<"\nEnter choice: ";
                cin>>ch;
                if(ch>=1&&ch<=6)
                {
                    strcpy(branch,def_tech[ch-1]);
                    k=0;
                }
                else
                    cout<<"Wrong choice, try again"<<endl;
            }
        }
        
        cout<<"Current Semester: ";
        cin>>curr_sem;
      
        char s[1];
        gets(s);
    }


void student::display_student()
    {
        display();
        
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nStudent Details:\n\nSRN          : "<<srn<<endl;
        cout<<"Degree       : "<<degree<<endl;
        cout<<"Branch       : "<<branch<<endl;
        cout<<"CGPA         : "<<cgpa<<endl;
        cout<<"Current SEM  : "<<curr_sem<<endl;
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }
    
    
int student::search_studentl(vector <student> &record, char* key)
    {
        for(int i=0;i<record.size();i++)
            if(strcmp(record[i].srn,key)==0)
                return i;
        
        return -1;
    }

    
void student::remove_student(vector <student> &record, char* key)
    {
        for(auto i=record.begin();i!=record.end();i++)
            if(strcmp(i->srn,key)==0)
            {
                i=record.erase(i);
                break;
            }
        
    }

    
void student::modify_student(vector <student> &record, char* key)
    {
        int k=-1;
        for(auto i=record.begin();i!=record.end();i++)
            if(strcmp(i->srn,key)==0)
            {
                k=1;
                cout<<"\nStudent found with SRN:"<<i->srn<<endl;
                student temp;
                
                temp.input_student();
                
                *i=temp;
            }
        
        if(k==-1)
            cout<<"\nStudent not found"<<endl;
        
    }

    
void student::display_all(vector <student> &record)
    {
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"Name                     SRN                      Degree                             Branch";
        cout<<"\n***************************************************************************************************************"<<endl;
             
        for(auto i=record.begin();i!=record.end();i++)
        {
            int l=strlen(i->ret_name());
            cout<<i->ret_name();
            for(int i=0;i<25-l;i++)
                cout<<" ";
            
            
            l=strlen(i->srn);
            cout<<i->srn;
            for(int i=0;i<25-l;i++)
                cout<<" ";
           
            
            l=strlen(i->degree);
            cout<<i->degree;
            for(int i=0;i<35-l;i++)
                cout<<" ";
            
            
            l=strlen(i->branch);
            cout<<i->branch;
            for(int i=0;i<25-l;i++)
                cout<<" ";
            
            cout<<endl;
            
        }
        
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }


void student::sort_srn(vector <student> record)
    {
        sort(record.begin(),record.end(),compare_srn);
        
        record[0].display_all(record);
    }
    

void student::sort_name(vector <student> record)
    {
        sort(record.begin(),record.end(),compare_name);
        
        record[0].display_all(record);
    }
    


teacher::teacher()
    {
        pes_info();
        dept[0]='\0';
        teachID[0]='\0';
    }
    

bool teacher::compare_id(const teacher &first, const teacher &second)
    {
        if(strcmp(first.teachID,second.teachID)<0)
            return true;
        return false;
    }
    

bool teacher::compare_name(teacher &first, teacher &second)
    {
        if(strcmp(first.ret_name(),second.ret_name())<0)
            return true;
        return false;
    }
    

void teacher::addresearch()
    {
        struct research temp;
        
        cout<<"\n***************************************************************************************************************"<<endl;
        
        cout<<"\nEnter Research Paper Details:\nPaper name: ";
        gets(temp.paper_name);
        cout<<"Conference name: ";
        gets(temp.conference_name);
        cout<<"Published year: ";
        cin>>temp.year;
        
        cout<<"\n***************************************************************************************************************"<<endl;
        
        collection.push_back(temp);
    }
    

void teacher::dispresearch(struct research temp)
    {
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nResearch paper name: "<<temp.paper_name<<endl;
        cout<<"Conference name      : "<<temp.conference_name<<endl;
        cout<<"Published year       : "<<temp.year<<endl;
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }
    

void teacher::input_teacher()
    {
        input(2);
        
        int ch=-1,k=1;
        
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nEnter Teacher Details:"<<endl<<"\nID: ";
        cin>>teachID;
        
        while(k==1)
        {
            cout<<"\nDegree:\n";
            for(int i=0;i<8;i++)
            {
                cout<<i+1<<". "<<def_tech[i]<<endl;
            }
            cout<<"\nEnter choice: ";
            cin>>ch;
            if(ch>=1&&ch<=8)
            {
                strcpy(dept,def_tech[ch-1]);
                k=0;
            }
            else
                cout<<"Wrong choice, try again"<<endl;
        }
        
        k=1;
        
        while(k)
        {
            cout<<"\n***************************************************************************************************************"<<endl;
            cout<<"\nResearch Papers: \n\n1.Add \n2.Quit \nEnter choice:";
            cin>>ch;
            
            char s[1];
            gets(s);
            
            if(ch==1)
                addresearch();
            else
                k=0;
        }
        
        
        
    }
    

void teacher::display_teacher()
    {
        display();
        
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nTeacher Details:\n\nTeacher ID     : "<<teachID<<endl;
        cout<<"Department     : "<<dept<<endl;
        
        for(int i=0;i<collection.size();i++)
        {
            cout<<"\n***************************************************************************************************************"<<endl;
            cout<<"Research paper "<<i+1;
            dispresearch(collection[i]);
        }

        cout<<"\n***************************************************************************************************************"<<endl;
        
    }
    

int teacher::search_teacherl(vector <teacher> &record, char* key)
    {
        for(int i=0;i<record.size();i++)
            if(strcmp(record[i].teachID,key)==0)
                return i;
        
        return -1;
    }
    

void teacher::remove_teacher(vector <teacher> &record, char* key)
    {
        for(auto i=record.begin();i!=record.end();i++)
            if(strcmp(i->teachID,key)==0)
            {
                i=record.erase(i);
                break;
            }
        
    }
    

void teacher::modify_teacher(vector <teacher> &record, char* key)
    {
        int k=-1;
        for(auto i=record.begin();i!=record.end();i++)
            if(strcmp(i->teachID,key)==0)
            {
                k=1;
                cout<<"\nTeacher found with ID:"<<i->teachID<<endl;
                teacher temp;
                
                temp.input_teacher();
                
                *i=temp;
            }
        
        if(k==-1)
            cout<<"\nTeacher not found"<<endl;
        
    }
    

void teacher::display_all(vector <teacher> &record)
    {
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"Name                     ID                       Department";
        cout<<"\n***************************************************************************************************************"<<endl;
        
        for(auto i=record.begin();i!=record.end();i++)
        {
            int l=strlen(i->ret_name());
            cout<<i->ret_name();
            for(int i=0;i<25-l;i++)
                cout<<" ";
            
            l=strlen(i->teachID);
            cout<<i->teachID;
            for(int i=0;i<25-l;i++)
                cout<<" ";
           
            l=strlen(i->dept);
            cout<<i->dept;
            for(int i=0;i<35-l;i++)
                cout<<" ";
            
            cout<<endl;
            
        }
        
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }
   

void teacher::sort_srn(vector <teacher> record)
    {
        sort(record.begin(),record.end(),compare_id);
        
        record[0].display_all(record);
    }
    
void teacher::sort_name(vector <teacher> record)
    {
        sort(record.begin(),record.end(),compare_name);
        
        record[0].display_all(record);
    }
    

