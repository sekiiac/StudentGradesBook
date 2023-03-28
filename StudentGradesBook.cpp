#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<sstream>
using namespace std;

struct lesson
{
    int lessonNumber;            //课程编号
    string name;                 //课程名称
    int grade;                   //课程成绩
    int credit;                  //课程学分
};

struct Student
{
    int id;                      //学号（8位，前6位为班级编号，后2位为序号）
    string name;                 //姓名
    lesson lessons[10];          //课程信息(仅支持每个学生最多10门课程，若需支持更多课程，请自行修改)
    int lessonIndex=0;          //课程数量
    int totalCredit;             //总学分
};

Student students[200];           //学生信息(仅支持存储200个学生,若需要支持更多学生,请自行修改)

int studentIndex = 0;            //学生数量

void main_interface();           //主界面绘制

void add_grade();                //添加成绩

void alter_grade();              //修改或删除成绩

void modify_grade();             //修改成绩

void delete_grade();             //删除成绩

void check_personal_grade();             //查询个人成绩

void check_class_grade();                //查询班级成绩

void write_file();                           //写入文件

void read_file();                            //读取文件

void quit();                                  //退出

int main(){
    system("cls");
    while(1){
        main_interface();
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                add_grade();
                break;
            case 2:
                alter_grade();
                break;
            case 3:
                check_personal_grade();
                break;
            case 4:
                check_class_grade();
                break;
            case 5:
                write_file();
                break;
            case 6:
                read_file();
                break;
            case 0:
                quit();
                break;
            default :
                cout<<"输入错误，请重新输入！"<<endl;
                system("pause");
                main();
        }
    }
}

void main_interface(){
    //显示主界面
    system("cls");
    cout<<"*********************************************************"<<endl;
    cout<<"*                       成绩记录簿                       *"<<endl;
    cout<<"*                                                        *"<<endl;
    cout<<"*                     1.添加成绩                         *"<<endl;
    cout<<"*                     2.修改或删除成绩                   *"<<endl;
    cout<<"*                     3.查询个人成绩                     *"<<endl;
    cout<<"*                     4.查询班级成绩                     *"<<endl;
    cout<<"*                     5.写入文件                         *"<<endl;
    cout<<"*                     6.读取文件                         *"<<endl;
    cout<<"*                     0.退出系统                         *"<<endl;
    cout<<"*                                                        *"<<endl; 
    cout<<"*********************************************************"<<endl;
    cout<<"请选择：";
}

void add_grade(){
    //添加成绩
    system("cls");
    cout<<"*********************************************************"<<endl;
    cout<<"*                       添加成绩                        *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*                     1.输入成绩                        *"<<endl;
    cout<<"*                     2.返回主界面                      *"<<endl;
    cout<<"*                                                       *"<<endl; 
    cout<<"*********************************************************"<<endl;
    cout<<"请选择：";
    int choice;
    cin>>choice;
    if(choice==1){
        int index_s=0;
        cout<<"请输入学号"<<endl;
        int input_id;
        string input_name;
        cin>>input_id;
        cout<<"请输入姓名"<<endl;
        cin>>input_name;
        for(;index_s<studentIndex;index_s++){                        //查询学生是否已存在
            if(students[index_s].id==input_id and students[index_s].name==input_name){
                break;
            }
        }
        if(index_s<studentIndex){                              //学生已存在，查询学生课程是否已存在
            cout<<"请输入课程编号"<<endl;
            int input_lessonNumber;
            cin>>input_lessonNumber;
            for(int j=0;j<students[index_s].lessonIndex;j++){
                if(students[index_s].lessons[j].lessonNumber==input_lessonNumber){
                    cout<<"该学生课程成绩已存在,"<<endl;
                    system("pause");
                    add_grade();
                }
            }
            students[index_s].lessons[students[index_s].lessonIndex].lessonNumber=input_lessonNumber;
            cout<<"请输入课程名称"<<endl;
            cin>>students[index_s].lessons[students[index_s].lessonIndex].name;
            cout<<"请输入课程成绩"<<endl;
            cin>>students[index_s].lessons[students[index_s].lessonIndex].grade;
            cout<<"请输入课程学分"<<endl;
            cin>>students[index_s].lessons[students[index_s].lessonIndex].credit;
            students[index_s].lessonIndex++;
        }
        else if(index_s==studentIndex){                        //学生还未存在，添加学生信息
            students[studentIndex].id=input_id;
            students[studentIndex].name=input_name;
            cout<<"请输入课程编号"<<endl;
            cin>>students[studentIndex].lessons[students[studentIndex].
            lessonIndex].lessonNumber;
            cout<<"请输入课程名称"<<endl;
            cin>>students[studentIndex].lessons[students[studentIndex].lessonIndex].name;
            cout<<"请输入课程成绩"<<endl;
            cin>>students[studentIndex].lessons[students[studentIndex].lessonIndex].grade;
            cout<<"请输入课程学分"<<endl;
            cin>>students[studentIndex].lessons[students[studentIndex].lessonIndex].credit;
            students[studentIndex].lessonIndex++;
            studentIndex++;
        }
        cout<<endl;
        cout<<"添加成功,是否继续输入"<<endl;
        cout<<"1.是  "<<"2.否"<<endl;
        int input_choice;
        cin>>input_choice;
        if(input_choice==1){
            system("cls");
            add_grade();
        }
        else if(input_choice==2){
            system("cls");
            main;
        }
        else {
            cout<<"无效输入,自动返回添加界面"<<endl;
            system("pause");
            add_grade();
        }
    }
    else if(choice==2){
        main();
    }
    else{
        cout<<"输入错误，请重新输入！"<<endl;
        system("pause");
        system("cls");
        add_grade();
    }
}

void alter_grade(){
    //修改或删除成绩
    system("cls");
    cout<<"**********************************************************"<<endl;
    cout<<"*                     修改或删除成绩                     *"<<endl;
    cout<<"*                                                        *"<<endl;
    cout<<"*                     1.修改成绩                         *"<<endl;
    cout<<"*                     2.删除成绩                         *"<<endl;
    cout<<"*                     3.返回主界面                       *"<<endl;
    cout<<"*                                                        *"<<endl; 
    cout<<"*********************************************************"<<endl;
    cout<<"请选择：";
    int choice_alter;
    cin>>choice_alter;
    if(choice_alter==1){                                                      //代码重构，将模块分工细化
        //修改成绩
        modify_grade();
    }
    else if(choice_alter==2){
        //删除成绩
        delete_grade();
    }
    else if(choice_alter==3){
        main();
    }
    else{
        cout<<"输入错误，请重新输入！"<<endl;
        system("pause");
        alter_grade();
    }
}

void modify_grade(){
    //修改成绩
    cout<<"请依次输入学号、姓名、课程编号"<<endl;
    int input_id,input_lessonNumber,index_s=0,index_l=0;                                //先用index_s和index_l记录学生和课程的位置
    string input_name;
    cin>>input_id>>input_name>>input_lessonNumber;
    for(;index_s<=studentIndex;index_s++){                                              
        if(students[index_s].id==input_id and students[index_s].name==input_name){
            break;
        }
    }
    if(index_s>studentIndex){                                                          //如果没有找到该学生
        cout<<"找不到该学生"<<endl;
        system("pause");
        alter_grade();
    }
    else {                                                                             //如果找到该学生，则查找该学生的课程
        for(;index_l<=students[index_s].lessonIndex;index_l++){
            if(students[index_s].lessons[index_l].lessonNumber==input_lessonNumber){
                break;
            }
        }
        if(index_l>students[index_s].lessonIndex){                                     //如果没有找到该课程
            cout<<"未录入学生该课程信息"<<endl;
            system("pause");
            alter_grade();
        }
        else {
            cout<<"请输入修改后的成绩"<<endl;
            cin>>students[index_s].lessons[index_l].grade;
            cout<<"修改成功"<<endl;
            system("pause");
            alter_grade();
        }
    }
}

void delete_grade(){
    //删除成绩
    cout<<"请依次输入学号、姓名、课程编号"<<endl;
    int input_id,input_lessonNumber,index_s=0,index_l=0;                             
    string input_name;
    cin>>input_id>>input_name>>input_lessonNumber;
    for(;index_s<=studentIndex;index_s++){
        if(students[index_s].id==input_id and students[index_s].name==input_name){     //先通过index_s和index_l来记录学生和课程的位置
            break;
        }
    }
    if(index_s>studentIndex){                                                          //如果没有找到该学生
        cout<<"找不到该学生"<<endl;
        system("pause");
        alter_grade();
    }
    else {                                                                             //如果找到该学生，则查找该学生的课程
        for(;index_l<=students[index_s].lessonIndex;index_l++){
            if(students[index_s].lessons[index_l].lessonNumber==input_lessonNumber){
                break;
            }
        }
        if(index_l>students[index_s].lessonIndex){                                     //如果没有找到该课程
            cout<<"未录入学生该课程信息"<<endl;
            system("pause");
            alter_grade();
        }
        else {
            for(int i=index_l;i<students[index_s].lessonIndex;i++){
                students[index_s].lessons[i]=students[index_s].lessons[i+1];
            }
            students[index_s].lessons[index_l].name="";
            students[index_s].lessons[index_l].lessonNumber=0;
            students[index_s].lessons[index_l].grade=0;
            students[index_s].lessons[index_l].credit=0;
            students[index_s].lessonIndex--;
            cout<<"删除成功"<<endl;
            system("pause");
            alter_grade();
        }
    }
}

void check_personal_grade(){
    //查询个人成绩
    system("cls");
    cout<<"*********************************************************"<<endl;
    cout<<"*                     查询个人成绩                       *"<<endl;
    cout<<"*                                                        *"<<endl;
    cout<<"*                   1.输入学号和姓名                     *"<<endl;
    cout<<"*                   2.返回主界面                         *"<<endl;
    cout<<"*                                                        *"<<endl; 
    cout<<"*********************************************************"<<endl;
    cout<<"请输入您的选择：";
    int choice;
    cin>>choice;
    if(choice==1){
        //输入学号和姓名并检索再查找后输出成绩
        cout<<"请依次输入学号和姓名"<<endl;
        int input_id,index_s=0,index_l=0;
        string input_name;
        cin>>input_id>>input_name;
        for(;index_s<=studentIndex;index_s++){                                      //先通过index_s和index_l来记录学生和课程的位置
            if(students[index_s].id==input_id and students[index_s].name==input_name){
                break;
            }
        }
        if(index_s>studentIndex){
            cout<<"找不到该学生"<<endl;
            system("pause");
            check_personal_grade();
        }
        else {
            int total_credit=0;
            for(;index_l<students[index_s].lessonIndex;index_l++){
                cout<<students[index_s].lessons[index_l].name<<" "<<
                students[index_s].lessons[index_l].lessonNumber<<" "<<
                students[index_s].lessons[index_l].grade<<" "<<
                students[index_s].lessons[index_l].credit<<endl;
                total_credit+=students[index_s].lessons[index_l].credit;
            }
            cout<<"总学分："<<total_credit<<endl;
            cout<<endl;
            cout<<"是否继续查找"<<endl;
            cout<<"1.是  2.否"<<endl;
            int choice_0;
            cin>>choice_0;
            if(choice_0==1){
                check_personal_grade();
            }
            else if(choice_0==2) {
                main();
            }
            else {
                cout<<"无效输入,自动返回查找界面"<<endl;
                system("pause");
                check_personal_grade();
            }
        }
    }
    else if(choice==2){
        main();
    }
    else{
        cout<<"输入错误，请重新输入！"<<endl;
        system("pause");
        check_personal_grade();
    }
}

void check_class_grade(){
    //查询班级成绩
    system("cls");
    cout<<"*********************************************************"<<endl;
    cout<<"*                     查询班级成绩                       *"<<endl;
    cout<<"*                                                        *"<<endl;
    cout<<"*                   1.输入课程编号                       *"<<endl;
    cout<<"*                   2.返回主界面                         *"<<endl;
    cout<<"*                                                        *"<<endl; 
    cout<<"*********************************************************"<<endl;
    cout<<"请输入您的选择：";
    int choice;
    cin>>choice;
    if(choice==1){
        //输入课程编号并检索再查找后按班级输出成绩
        cout<<"请输入课程编号"<<endl;
        int input_lessonNumber;
        cin>>input_lessonNumber;
        int index_s=0,class_nums=0;                                   //class_nums用来记录班级数量，index_class用来记录班级的位置
        int class_list[5][40]={0};                                    //默认分为5个班级，每个班最多为40人(如需改变，可以改变数组大小)
        int class_students_nums[5]={0};                               //记录每个班级的人数
        int class_Numbers[5]={0};                                     //记录每个班级的编号
        for(;index_s<studentIndex;index_s++){                         //按学号给班级分组
            int index_class=0;
            int classNumber=students[index_s].id/100;
            for(;index_class<class_nums;index_class++){
                if(classNumber==class_Numbers[index_class]){
                    break;
                }
            }
            if(index_class==0 and index_class==class_nums){
                class_Numbers[index_class]=classNumber;
                class_list[index_class][class_students_nums[index_class]]=index_s;
                class_students_nums[index_class]++;
                class_nums++;
            }
            else if(index_class==class_nums and index_class!=0){
                class_Numbers[index_class]=classNumber;
                class_list[index_class][class_students_nums[index_class]]=index_s;
                class_students_nums[index_class]++;
                class_nums++;
            }
            else{
                class_list[index_class][class_students_nums[index_class]]=index_s;
                class_students_nums[index_class]++;
            }
        }
        for(int i=0;i<class_nums;i++){
            float class_avg=0;
            float pass_rate=0;
            int nums_0_40=0,nums_40_60=0,nums_60_80=0,nums_80_100=0;
            cout<<"班级："<<class_Numbers[i]<<endl;
            for(int j=0;j<class_students_nums[i];j++){
                for(int k=0;k<=students[class_list[i][j]].lessonIndex;k++){
                    if(students[class_list[i][j]].lessons[k].lessonNumber==input_lessonNumber){
                        cout<<students[class_list[i][j]].id<<" "<<
                        students[class_list[i][j]].name<<" "<<
                        students[class_list[i][j]].lessons[k].name<<" "<<
                        students[class_list[i][j]].lessons[k].lessonNumber<<" "<<
                        students[class_list[i][j]].lessons[k].grade<<endl;
                        class_avg+=students[class_list[i][j]].lessons[k].grade;
                        if(students[class_list[i][j]].lessons[k].grade>=0 and students[class_list[i][j]].lessons[k].grade<40){
                            nums_0_40++;
                        }
                        else if(students[class_list[i][j]].lessons[k].grade>=40 and students[class_list[i][j]].lessons[k].grade<60){
                            nums_40_60++;
                        }
                        else if(students[class_list[i][j]].lessons[k].grade>=60 and students[class_list[i][j]].lessons[k].grade<80){
                            nums_60_80++;
                        }
                        else if(students[class_list[i][j]].lessons[k].grade>=80 and students[class_list[i][j]].lessons[k].grade<=100){
                            nums_80_100++;
                        }
                        if(students[class_list[i][j]].lessons[k].grade>=60){
                            pass_rate=pass_rate+1;
                        }
                    }
                }
            }
            class_avg=class_avg/class_students_nums[i];
            printf("班级平均成绩：%.2f\n",class_avg);
            cout<<"0-40分人数:"<<nums_0_40<<endl;
            cout<<"40-60分人数:"<<nums_40_60<<endl;
            cout<<"60-80分人数:"<<nums_60_80<<endl;
            cout<<"80-100分人数:"<<nums_80_100<<endl;
            pass_rate=pass_rate/class_students_nums[i];
            printf("通过率：%.2f%%\n",pass_rate*100);
        }
        cout<<endl;
        cout<<"是否继续查找"<<endl;
        cout<<"1.是  2.否"<<endl;
        int choice_0;
        cin>>choice_0;
        if(choice_0==1){
            check_class_grade();
        }
        else if(choice_0==2) {
            main();
        }
        else {
            cout<<"无效输入,自动返回查找界面"<<endl;
            system("pause");
            check_class_grade();
        }
    }
    else if(choice==2){
        main();
    }
    else{
        cout<<"输入错误，请重新输入！"<<endl;
        system("pause");
        check_class_grade();
    }
}

void write_file(){
    //写入文件
    system("cls");
    ofstream outfile;
    outfile.open("save.txt");
    for(int i=0;i<studentIndex;i++){
        for(int j=0;j<students[i].lessonIndex;j++){
            outfile<<students[i].id<<" "<<
            students[i].name<<" "<<
            students[i].lessons[j].lessonNumber<<" "<<
            students[i].lessons[j].name<<" "<<
            students[i].lessons[j].grade<<" "<<
            students[i].lessons[j].credit<<endl;
        }
    }
    outfile.close();
    cout<<"保存成功！"<<endl;
    cout<<endl;
    system("pause");
}

void read_file(){
    //从save.txt读取文件
    system("cls");
    string readline_static;
    ifstream infile;
    infile.open("save.txt");
    while(getline(infile,readline_static)){
        stringstream readline(readline_static);
        string id,name,lessonNumber,lessonName,grade,credit;
        getline(readline,id,' ');
        getline(readline,name,' ');
        getline(readline,lessonNumber,' ');
        getline(readline,lessonName,' ');
        getline(readline,grade,' ');
        getline(readline,credit);
        cout<<id<<" "<<name<<" "<<lessonNumber<<" "<<lessonName<<" "<<grade<<" "<<credit<<endl;
        int i=0;
        for(;i<studentIndex;i++){
            if(students[i].id==stoi(id)){
                students[i].lessons[students[i].lessonIndex].lessonNumber=stoi(lessonNumber);
                students[i].lessons[students[i].lessonIndex].name=lessonName;
                students[i].lessons[students[i].lessonIndex].grade=stoi(grade);
                students[i].lessons[students[i].lessonIndex].credit=stoi(credit);
                students[i].lessonIndex++;
                break;
            }
        }
        if(i==studentIndex){
            students[studentIndex].id=stoi(id);
            students[studentIndex].name=name;
            students[studentIndex].lessons[students[studentIndex].lessonIndex].lessonNumber=stoi(lessonNumber);
            students[studentIndex].lessons[students[studentIndex].lessonIndex].name=lessonName;
            students[studentIndex].lessons[students[studentIndex].lessonIndex].grade=stoi(grade);
            students[studentIndex].lessons[students[studentIndex].lessonIndex].credit=stoi(credit);
            students[studentIndex].lessonIndex++;
            studentIndex++;
        }
    }
    cout<<"读取成功！"<<endl;
    system("pause");
}

void quit(){
    //退出系统，关闭终端
    exit(0);
}