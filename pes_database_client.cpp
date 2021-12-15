#include "pes_database.h"


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
