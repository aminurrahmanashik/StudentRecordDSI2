/*Ashik1704013*/

#include<bits/stdc++.h>
using namespace std;


int ts = 0;

struct student    
{ 
  int cls;
  string name;
  int subject[3];
  int marks[3] = {0};
  int taught[3] = {0};
  int earn = 0;
  int live = 0;
  int avg_marks = 0;
  int total_days = 0;
};

student rec[50];




void StRT(){
    cout <<"-------------------------------------------------------------------" << endl;
        cout <<"-----------------Student record Table-----------------------" << endl;
        cout <<"-------------------------------------------------------------------" << endl;
        cout <<"ID    " << "Name    " << "Math    " << "English     " << "Bangla    " << "T_Math    " << "T_English     " << "T_Bangla    "  << "Earning\n\n";
        cout <<"-------------------------------------------------------------------" << endl;
}
void SbRT(){
    cout <<"-------------------------------------------------------------------" << endl;
    cout <<"-----------------Subject record Table-----------------------" << endl;
    cout <<"-------------------------------------------------------------------" << endl;
    cout <<"ID    " << "Name    " << "Earning    " << "Taught\n\n";
    cout <<"-------------------------------------------------------------------" << endl;
}


void get_data(int i){       
    cout << "Choice class:\n";
    cout << "1. Class 8\n";
    cout << "2. Class 9\n";
    cout << "3. class 10\n";
    int cls;
    cin >> cls;
    rec[i].cls = cls;
    cout<<"Enter student name: ";
    cin>>rec[i].name;
    cout<<"Enter student's subject choice (1 for yes and 0 for no): \n";
    cout << "Math: ";
    cin >> rec[i].subject[0];
    cout << "English: ";
    cin >> rec[i].subject[1];
    cout << "Bangla: ";
    cin >> rec[i].subject[2];

    rec[i].live = 1;
}



void show_data(int searchkey){    
    int i = searchkey;
    cout << i <<"    ";
    cout << rec[i].name <<"     ";
    cout << (rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2])  <<"    ";
    cout << (rec[i].marks[0] + rec[i].marks[1] + rec[i].marks[2])/3  <<"   \n";
}

 // pick one and see details of individual
void show_data_indv(int searchkey){
    int i = searchkey;
    cout << i << "    ";
    cout << rec[i].name << "     ";
    (rec[i].subject[0] == 1)? cout << "Yes     ":cout << "No    ";
    (rec[i].subject[1] == 1)? cout << "Yes     ":cout << "No    ";
    (rec[i].subject[2] == 1)? cout << "Yes     ":cout << "No    ";
    (rec[i].subject[0] == 1)? cout << rec[i].taught[0] << "    ":cout << "    ";
    (rec[i].subject[1] == 1)? cout << rec[i].taught[1] << "    ":cout << "    ";
    (rec[i].subject[2] == 1)? cout << rec[i].taught[2] << "    ":cout << "    ";
    cout << rec[i].earn << " \n";
    // cout << (rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2])  <<"   \n";
}

 
void add_student(){
    cout << "Number of student will be added: ";
    int stdnt;
    cin >> stdnt;
    int i = 0;
    for(i = ts; i < stdnt + ts; i ++)
        get_data(i);
    ts = i;
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
}


void edit_student(){
    cout << "Enter Student ID: \n";
    int id;
    cin >> id;
    if(id >= 0 && id < 50){
        if(rec[id].live == 1){
            StRT();
            show_data_indv(id);
            cout << "\nNumber of days taught for each subject\n";
            if(rec[id].subject[0] == 1){
                cout << "For Math: ";
                cin >> rec[id].taught[0];
            }
            if(rec[id].subject[1] == 1){
                cout << "For English: ";
                cin >> rec[id].taught[1];
            }
            if(rec[id].subject[2] == 1){
                cout << "For Bangla: ";
                cin >> rec[id].taught[2];
            }
            cout << "\nNumber of marks for each subject\n";
            if(rec[id].subject[0] == 1){
                cout << "For Math: ";
                cin >> rec[id].marks[0];
            }
            if(rec[id].subject[1] == 1){
                cout << "For English: ";
                cin >> rec[id].marks[1];
            }
            if(rec[id].subject[2] == 1){
                cout << "For Bangla: ";
                cin >> rec[id].marks[2];
            }
        }
        else
            cout << "Not found\n";
    }
    else
        cout << "Out of bound\n";
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
}


void delete_student(){
    cout <<"--------Delete---------\n";
    cout << "Enter student id: ";
    int id;
    cin >> id;
    if(id >= 0 && id < 50){
        rec[id].live = 0;
        cout << "Successfully deleted\n";
    }
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
}



void show_individual(){
    cout << "Choose class:\n1. Class 8\n2. Class 9\n3. Class 10\n";
    int cls;
    cin >> cls;
    SbRT();
    for(int i = 0;i < ts;i ++){
        if(rec[i].live == 1 && rec[i].cls == cls){
            show_data(i);
        }
    }
    cout << "Want to show details: (y or n)\n";
    char dt;
    cin >> dt;
    if(dt == 'y'){
        cout << "Enter student ID: ";
        int id;
        cin >> id;
        StRT();
        for(int i = 0;i < ts; i ++){
            if(rec[i].live == 1 && rec[i].cls == cls){
                show_data_indv(i);
            }
        }
    }
    cout << "Press any key to go main page: ";
    char ch;
    cin >> ch;
}

void show_overall_info(){
    int class_overall[3] = {0};
    int earning_sub_overall[3] = {0};
    int mrks = 0;
    int tot_sub = 0;
    for(int i = 0;i < ts;i ++){
        // if(rec[i].live == 1){
            if(rec[i].cls == 1)
                class_overall[0] += rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2];
            if(rec[i].cls == 2)
                class_overall[1] += rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2];
            if(rec[i].cls == 3)
                class_overall[2] += rec[i].taught[0] + rec[i].taught[1] + rec[i].taught[2];
            earning_sub_overall[0] += rec[i].taught[0];
            earning_sub_overall[1] += rec[i].taught[1];
            earning_sub_overall[2] += rec[i].taught[2];

            if(rec[i].subject[0] == 1){
                mrks += rec[i].marks[0];
                tot_sub += 1;
            }
            if(rec[i].subject[1] == 1){
                mrks += rec[i].marks[1];
                tot_sub += 1;
            }
            if(rec[i].subject[2] == 1){
                mrks += rec[i].marks[2];
                tot_sub += 1;
            }
        // }     
    }
    cout << "Total days taught across all classes:  " << class_overall[0] + class_overall[1] + class_overall[2] << "\n";
    cout << "Individual days taught in each class:  " << "Class8 (" << class_overall[0] << ")  " << "Class9 (" << class_overall[1] << ")  " "Class10 (" << class_overall[2] << ")\n";

    cout << "Total earnings:  " << class_overall[0] + class_overall[1] + class_overall[2] << "\n";
    cout << "Individual earnings of each class:  " << "Class8 (" << class_overall[0] << ")  " << "Class9 (" << class_overall[1] << ")  " "Class10 (" << class_overall[2] << ")\n";

    cout << "Individual earnings of each subject:  " << "Class8 (" << earning_sub_overall[0] << ")  " << "Class9 (" << earning_sub_overall[1] << ")  " "Class10 (" << earning_sub_overall[2] << ")\n";


    cout << "Average marks of all students:  " << float((mrks * 1.0) / tot_sub) << "\n";


}


int control_panel(){
    // cout << "Control Panel\n";
    cout <<"\n\t\tWhat do you want to do?"<<endl;
    cout <<"\t\t----------------------"<<endl;
    cout <<"\t\t1-Add student"<<endl;
    cout <<"\t\t2-Edit student"<<endl;
    cout <<"\t\t3-Delete student"<<endl;
    cout <<"\t\t4-Individual Information"<<endl;
    cout <<"\t\t5-Overall Information"<<endl;
    cout <<"\t\t6-Exit"<<endl;
    cout <<"\t\t----------------------"<<endl;
    cout <<"Enter your choice: ";
    int t;
    cin >> t;
    return t;
}






int main(){

    while(1){
        int itr = control_panel();
        // cout << terminate;
        if(itr == 1)
            add_student();
        if(itr == 2)
            edit_student();
        if(itr == 3)
            delete_student();
        if(itr == 4)
            show_individual();
        if(itr == 5)
            show_overall_info();
        if(itr == 6)
            return 0;
    }

}
