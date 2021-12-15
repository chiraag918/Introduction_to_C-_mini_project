#include "iostream"
#include "vector"
#include "algorithm"
#include "string.h"

using namespace std;


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
    char bloodgrp[4];
    
public:
    
    pes_info();
    
    void input(int);
    
    void display();
    
    char* ret_name();
};

class student: pes_info
{

    char srn[15];
    float cgpa;
    int curr_sem;
    char degree[45];
    char branch[35];
    
public:
    student();
    
    static bool compare_srn(const student &, const student &);
    
    static bool compare_name(student &, student &);
    
    void input_student();
    
    void display_student();
    
    int search_studentl(vector <student> &, char* );
    
    void remove_student(vector <student> &, char* );
    
    void modify_student(vector <student> &, char* );
    
    void display_all(vector <student> &);
    
    void sort_srn(vector <student> );
    
    void sort_name(vector <student> );

};


class teacher: pes_info
{
    char dept[35];
    char teachID[15];
    vector <struct research> collection;
    
public:
    teacher();
    
    static bool compare_id(const teacher &, const teacher &);
    
    static bool compare_name(teacher &, teacher &);
    
    void addresearch();
    
    void dispresearch(struct research );
    
    void input_teacher();
    
    void display_teacher();
    
    int search_teacherl(vector <teacher> &, char* );
    
    void remove_teacher(vector <teacher> &, char* );
    
    void modify_teacher(vector <teacher> &, char* );
    
    void display_all(vector <teacher> &);

    void sort_srn(vector <teacher> );
    
    void sort_name(vector <teacher> );
 
};
    
    

