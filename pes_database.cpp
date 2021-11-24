#include "iostream"
#include "vector"
#include "algorithm"
#include "string.h"

using namespace std;

char def_deg[][45]={"Bachelor of Technology (B.Tech)","Master of Technology (M.Tech)","Bachelor of Architecture (B.Arch)","Bachelor of Business Administration (BBA)","Master of Business Administration (MBA)"};
char def_tech[][35]={"Computer Science Engg.","Electronics Engg.","Electrical and Electronics Engg.","Mechanical Engg.","Biotech Engg.","Civil Engg.","Business Administration","Architecture"};


struct research
{
    char paper_name[30];
    char conference_name[20];
    int year;
};

class pes_info
{
    
    
    char name[50];
    char role[7];
    long phno;
    char email[50];
    char bloodgrp[3];
    
public:
    pes_info()
    {
        name[0]='\0';
        role[0]='\0';
        phno=0;
        email[0]='\0';
        bloodgrp[0]='\0';
    }

    void input(int d)
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
    
    void display()
    {
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nGeneral Details:\n\nName          : "<<name<<endl;
        cout<<"Role          : "<<role<<endl;
        cout<<"Phone Number  : "<<phno<<endl;
        cout<<"E-mail        : "<<email<<endl;
        cout<<"Blood Group   : "<<bloodgrp<<endl;
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }
    
    char* ret_name()
    {
        return name;
    }
    

};

class student: pes_info
{
    
    char srn[15];
    float cgpa;
    int curr_sem;
    char degree[45];
    char branch[35];
    
public:
    student()
    {
        pes_info();
        srn[0]='\0';
        cgpa=0;
        curr_sem=0;
        degree[0]='\0';
        branch[0]='\0';
    }
    
  
    static bool compare_srn(const student &first, const student &second)
    {
        if(strcmp(first.srn,second.srn)<0)
            return true;
        return false;
    }
    
    static bool compare_name(student &first, student &second)
    {
        if(strcmp(first.ret_name(),second.ret_name())<0)
            return true;
        return false;
    }
    
    void input_student()
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
    void display_student()
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
    
    
    int search_studentl(vector <student> &record, char* key)
    {
        for(int i=0;i<record.size();i++)
            if(strcmp(record[i].srn,key)==0)
                return i;
        
        return -1;
    }
    
    void remove_student(vector <student> &record, char* key)
    {
        for(auto i=record.begin();i!=record.end();i++)
            if(strcmp(i->srn,key)==0)
            {
                i=record.erase(i);
                break;
            }
        
    }
    
    void modify_student(vector <student> &record, char* key)
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
    
    void display_all(vector <student> &record)
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

    void sort_srn(vector <student> record)
    {
        sort(record.begin(),record.end(),compare_srn);
        
        record[0].display_all(record);
    }
    
    void sort_name(vector <student> record)
    {
        sort(record.begin(),record.end(),compare_name);
        
        record[0].display_all(record);
    }
    
};






class teacher: pes_info
{
    char dept[35];
    char teachID[15];
    vector <struct research> collection;
    
public:
    teacher()
    {
        dept[0]='\0';
        teachID[0]='\0';
    }
    
    static bool compare_id(const teacher &first, const teacher &second)
    {
        if(strcmp(first.teachID,second.teachID)<0)
            return true;
        return false;
    }
    
    static bool compare_name(teacher &first, teacher &second)
    {
        if(strcmp(first.ret_name(),second.ret_name())<0)
            return true;
        return false;
    }
    
    void addresearch()
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
    
    void dispresearch(struct research temp)
    {
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nResearch paper name: "<<temp.paper_name<<endl;
        cout<<"Conference name      : "<<temp.conference_name<<endl;
        cout<<"Published year       : "<<temp.year<<endl;
        cout<<"\n***************************************************************************************************************"<<endl;
        
    }
    
    void input_teacher()
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
    
    void display_teacher()
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
    
    int search_teacherl(vector <teacher> &record, char* key)
    {
        for(int i=0;i<record.size();i++)
            if(strcmp(record[i].teachID,key)==0)
                return i;
        
        return -1;
    }
    
    void remove_teacher(vector <teacher> &record, char* key)
    {
        for(auto i=record.begin();i!=record.end();i++)
            if(strcmp(i->teachID,key)==0)
            {
                i=record.erase(i);
                break;
            }
        
    }
    
    void modify_teacher(vector <teacher> &record, char* key)
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
    
    void display_all(vector <teacher> &record)
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
    
    void sort_srn(vector <teacher> record)
    {
        sort(record.begin(),record.end(),compare_id);
        
        record[0].display_all(record);
    }
    
    void sort_name(vector <teacher> record)
    {
        sort(record.begin(),record.end(),compare_name);
        
        record[0].display_all(record);
    }
    
    
    
};




int main()
{
    vector <student> stu_data;
    vector <teacher> tec_data;
    
    int k=1,ch=0;
   

    while(k)
    {
        char d[1];
        cout<<"Press enter to continue\n";
        gets(d);
        
        cout<<"\n***************************************************************************************************************"<<endl;
        cout<<"\nPES UNIVERSITY DATABASE\n";
        cout<<"\n1.ADD A STUDENT\n2.ADD A TEACHER\n3.DISPLAY ALL STUDENTS RECORD\n4.DISPLAY ALL TEACHERS RECORD\n5.SEARCH & DISPLAY STUDENT RECORD BASED ON SRN\n6.SEARCH & DISPLAY TEACHER RECORD BASED ON ID\n7.SEARCH & MODIFY STUDENT RECORD\n8.SEARCH & MODIFY TEACHER RECORD\n9.DISPLAY ALL STUDENTS RECORD ACCD. SRN\n10.DISPLAY ALL STUDENTS RECORD ACCD. NAME\n11.DISPLAY ALL TEACHERS RECORD ACCD. ID\n12.DISPLAY ALL STUDENTS RECORD ACCD. NAME\n13.EXIT DATABASE\n\nENTER CHOICE: ";
        cin>>ch;
        cout<<"\n***************************************************************************************************************"<<endl;
        
        if(ch==1)
        {
            gets(d);
            student t;
            t.input_student();
            stu_data.push_back(t);
        }
        else if(ch==2)
        {
      
            gets(d);
            teacher t;
            t.input_teacher();
            tec_data.push_back(t);
        }
        else if(ch==3)
        {
            stu_data[0].display_all(stu_data);
        }
        else if(ch==4)
        {
            tec_data[0].display_all(tec_data);
        }
        else if(ch==5)
        {
            gets(d);
            cout<<"\n***************************************************************************************************************"<<endl;
            char s[15];
            cout<<"Enter Student SRN to be searched & displayed: ";
            gets(s);
            
            int ind = stu_data[0].search_studentl(stu_data,s);
            
            if(ind!=-1)
                stu_data[ind].display_student();
            else
                cout<<"\nRecord Not Found\n";
            
            cout<<"\n***************************************************************************************************************"<<endl;
        }
        else if(ch==6)
        {
            cout<<"\n***************************************************************************************************************"<<endl;
            gets(d);
            char s[15];
            cout<<"Enter Teacher ID to be searched & displayed: ";
            gets(s);
            
            int ind = tec_data[0].search_teacherl(tec_data,s);
            
            if(ind!=-1)
                tec_data[ind].display_teacher();
            else
                cout<<"\nRecord Not Found\n";
            cout<<"\n***************************************************************************************************************"<<endl;
        }
        else if(ch==7)
        {
            cout<<"\n***************************************************************************************************************"<<endl;
            gets(d);
            char s[15];
            cout<<"Enter Student SRN to be searched & modified: ";
            gets(s);
            
            stu_data[0].modify_student(stu_data,s);
            cout<<"\n***************************************************************************************************************"<<endl;
        }
        else if(ch==8)
        {
            cout<<"\n***************************************************************************************************************"<<endl;
            gets(d);
            char s[15];
            cout<<"Enter Teacher ID to be searched & modified: ";
            gets(s);
            
            tec_data[0].modify_teacher(tec_data,s);
            cout<<"\n***************************************************************************************************************"<<endl;
        }
        else if(ch==9)
        {
            stu_data[0].sort_srn(stu_data);
        }
        else if(ch==10)
        {
            stu_data[0].sort_name(stu_data);
        }
        else if(ch==11)
        {
            tec_data[0].sort_srn(tec_data);
        }
        else if(ch==12)
        {
            tec_data[0].sort_name(tec_data);
        }
        else if(ch==13)
        {
            k=0;
            cout<<"\nQuitting Database\n";
            cout<<"\n***************************************************************************************************************"<<endl;
        }
        else
        {
            cout<<"\nIncorrect choice\n";
        }
    }
    

    
}
