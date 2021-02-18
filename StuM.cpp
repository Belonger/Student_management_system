#include "StuM.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

StuM stu1[100];
int n1=0;

StuM::StuM(){
	strcpy(name," ");
	strcpy(sex," ");
	number=0;
	className=0;
	total=0;
	average=0;
	for(int i=0;i<5;i++)score[i]=0;
}

void StuM::input(){
	cout<<"输入学生人数："<<endl;
	cin>>n1;
	cout<<"输入学生信息 学号 姓名 语文成绩 数学成绩 英语成绩 地理成绩 历史成绩："<<endl;
	for(int i=0;i<n1;i++){
		cin>>stu1[i].number;
		cin>>stu1[i].name;
		for(int j=0;j<5;j++){
			cin>>stu1[i].score[j];
			stu1[i].total+=stu1[i].score[j];
		}
	} 
	cout<<"完成学生信息的输入！"<<endl;	
}

void StuM::insert(){
	int num,score1[5];
	char name1[20];
	cout<<"输入所要添加学生的学号:"<<endl;
	cin>>num;
	bool f=1;
	for(int i=0;i<n1;i++)
	{
		if(num==stu1[i].number){
			cout<<"无法添加该学生 该学生信息已经存在！"<<endl;
			f=0;
			break;
		}
	}
	if(f){
		cout<<"输入姓名 语文成绩 数学成绩 英语成绩 地理成绩 历史成绩："<<endl;
		cin>>name>>score1[0]>>score1[1]>>score1[2]>>score1[3]>>score[4];
		stu1[n1].number=num;
		for(int p=0;p<5;p++){
			stu1[n1].score[p]=score1[p];
			stu1[n1].total+=score1[p];
		}
		strcpy(stu1[n1].name,name);
		cout<<"添加成功"<<endl;
		n1++;
		write();//添加后要保存到文件中
	}	
} 

void StuM::display(){
	cout<<"输出学生信息：学号  姓名    语文成绩    数学成绩    英语成绩    地理成绩    历史成绩   总成绩："<<endl;
	for(int i=0;i<n1;i++){
		cout<<setw(16)<<stu1[i].number<<setw(8)<<stu1[i].name<<" ";
		for(int j=0;j<5;j++){
			cout<<setw(10)<<stu1[i].score[j]<<" ";
		}
		cout<<setw(11)<<stu1[i].total; 
		cout<<endl;
	}
}

void StuM::sort1(){
	cout<<"选择排序方式：1--按总成绩排序 2--按语文成绩排序 3--按数学成绩排序 4--按英语成绩排序 5--按地理成绩排序 6--按历史成绩排序 7--返回菜单"<<endl;		
	int m;
	cin>>m;
	while(1){
		if(m==1){
			for(int i=0;i<n1;i++){
				for(int j=0;j<n1-i-1;j++){
					if(stu1[j].total<stu1[j+1].total){
						swap(stu1[j],stu1[j+1]);
					}
				}
			}	
			display();	
		} 
		else if(m==2){
			for(int i=0;i<n1;i++){
				for(int j=0;j<n1-i-1;j++){
					if(stu1[j].score[0]<stu1[j+1].score[0]){
						swap(stu1[j],stu1[j+1]);
					}
				}
			}
			display();	
		}
		else if(m==3){
			for(int i=0;i<n1;i++){
				for(int j=0;j<n1-i-1;j++){
					if(stu1[j].score[1]<stu1[j+1].score[1]){
						swap(stu1[j],stu1[j+1]);
					}
				}
			}	
			display();
		}
		else if(m==4){
			for(int i=0;i<n1;i++){
				for(int j=0;j<n1-i-1;j++){
					if(stu1[j].score[2]<stu1[j+1].score[2]){
						swap(stu1[j],stu1[j+1]);
					}
				}
			}
			display();	
		}	
		else if(m==5){
			for(int i=0;i<n1;i++){
				for(int j=0;j<n1-i-1;j++){
					if(stu1[j].score[3]<stu1[j+1].score[3]){
						swap(stu1[j],stu1[j+1]);
					}
				}
			}
			display();			
		}
		else if(m==6){
			for(int i=0;i<n1;i++){
				for(int j=0;j<n1-i-1;j++){
					if(stu1[j].score[4]<stu1[j+1].score[4]){
						swap(stu1[j],stu1[j+1]);
					}
				}
			}
			display();			
		}
		else if(m==7){
			break;
		}	
		else{
			cout<<"输入号码选项序号错误！"<<endl;
		}
		cout<<"选择排序方式：1--按总成绩排序 2--按语文成绩排序 3--按数学成绩排序 4--按英语成绩排序 5--按地理成绩排序 6--按历史成绩排序 7--返回菜单"<<endl;					
		cin>>m;
	} 
}

void StuM::write(){
	for(int i=0;i<n1;i++){//先按总成绩排序 再存入 
			for(int j=0;j<n1-i-1;j++){
				if(stu1[j].total<stu1[j+1].total){
					swap(stu1[j],stu1[j+1]);
				}
			}
	}
	ofstream outfile("dataM.dat",ios::binary);
	if(!outfile)
	{
		cerr<<"保存学生信息时打开文件失败！"<<endl;
		exit(1);
	}
	cout<<"将学生信息读入文件当中....."<<endl;
	for(int i=0;i<n1;i++)
	{
		outfile.write((char*)&stu1[i],sizeof(StuM));
	}
	outfile.close();	
}

void StuM::read(){
	ifstream infile("dataM.dat",ios::binary);
	if(!infile)
	{
		cerr<<"读取学生信息时打开文件失败！"<<endl;
		exit(1);
	}
	cout<<"从文件中读取学生信息....."<<endl;
	int j=0;
	cout<<"学号 姓名      语文成绩    数学成绩   英语成绩   地理成绩   历史成绩："<<endl;
	while(infile.read((char*)&stu1[j],sizeof(StuM)))
	{
		cout<<" "<<stu1[j].number<<"   "<<stu1[j].name<<" "; 
		for(int p=0;p<5;p++){
			cout<<setw(11)<<stu1[j].score[p];
		}
		cout<<endl;
		j++;
	}
	n1=j; //保存学生人数
	cout<<"学生人数为："<<n1<<endl;
	infile.close();	
}

void StuM::readOrClear(){
	cout<<"是否清空文件中的学生信息？(清空/第一次录入信息 需要输入学生信息，保存到文件中  yes--清空 no--不清空 )"<<endl;
	string s;
	cin>>s;
	if(s=="yes")
	{
		n1=0;
		input();//清空后调用 输入学生信息函数
		write();//并将信息保存到文件中
		read();
	}
	if(s=="no")
	{
		read();
		cout<<"读取信息完毕！"<<endl;
	}	
}

void StuM::modify(){
	int pd=0;//判断有没有 
	int t;//记录位置 
	int num;
	cout<<"请输入你的学号: ";
	cin>>num;
	for(int i=0;i<n1;i++){
		if(stu1[i].number==num){
			pd=1;
			t=i;
		}
	}
	if(pd==0){
		cout<<"对不起，没有你要修改的学生信息"<<endl;
	}
	else{
		cout<<"请输入新的学号: "; 
		cin>>stu1[t].number; 
		cout<<" 姓名: "; 
		cin>>stu1[t].name; 
		cout<<"语文成绩 数学成绩 英语成绩 地理成绩 历史成绩："; 
		for(int h=0;h<5;h++){
			cin>>stu1[t].score[h];
			stu1[t].total+=stu1[t].score[h];
		}
		write();
		cout<<" 修改成功 !"<<endl;					
	} 
}

void StuM::del(){
	int num;
	bool f=0;
	cout<<"输入你要删除的学生学号："<<endl;
	cin>>num;
	for(int i=0;i<n1;i++){
		if(stu1[i].number==num)
		{
			cout<<"找到该学生！进行删除操作..."<<endl;
			for(int j=i;j<n1-1;j++)
			{
				stu1[j].number=stu1[j+1].number;
				strcpy(stu1[j].name,stu1[j+1].name);
				for(int p=0;p<5;p++){
					stu1[j].score[p]=stu1[j+1].score[p];
				}
			}
			cout<<"删除成功！"<<endl;
			n1--;//学生人数-1
			f=1;
			break;
		}
	}
	if(f)
		write();
	else 
		cout<<"不存在该学生！无法删除！"<<endl;
		
}

void StuM::find(){
	cout<<"选择查询方式：0--学号 1--姓名:"<<endl;
	int s;
	cin>>s;
	while(1){
		if(s==0){
			cout<<"输入你要查询的学号："<<endl;
			int num;
			cin>>num;
			for(int i=0;i<n1;i++){
				if(num==stu1[i].number){
					cout<<"查询成功！"<<num<<"号学生信息 姓名："<<stu1[i].name<<" ";
					cout<<"语文成绩 数学成绩 英语成绩 地理成绩 历史成绩 总成绩："; 
					for(int h=0;h<5;h++){
						cout<<stu1[i].score[h]<<" ";
					}		
					cout<<stu1[i].total; 
					cout<<endl;		
				}
			}		
			break;
		}
		else if(s==1){
			cout<<"输入你要查询的学生姓名："<<endl;
			char name[20];
			cin>>name;
			for(int i=0;i<n1;i++){
				if(strcmp(stu1[i].name,name)==0){
					cout<<"查询成功！"<<name<<"学生信息 学号 成绩："<<stu1[i].number<<" ";
					cout<<"语文成绩 数学成绩 英语成绩 地理成绩 历史成绩 总成绩："; 
					for(int h=0;h<5;h++){
						cout<<stu1[i].score[h]<<" "; 
					}		
					cout<<stu1[i].total;
					cout<<endl;							
				}
			}	
			break;
		}
		else{
			cout<<"输入的选项序号有误，请重新输入："<<endl;
			cin>>s;
		}
	}	
}

void StuM::stat(){
	cout<<"请选择统计方式 0--人数 1--总平均分 2--语文平均分 3--数学平均分 4--英语平均分 5--地理平均分 6--历史平均分 7--退出统计,返回菜单"<<endl; 
	double t=0,t1=0,t2=0,t3=0,t4=0,t5=0;
	for(int i=0;i<n1;i++){
		t+=stu1[i].total;
		t1+=stu1[i].score[0]; 
		t2+=stu1[i].score[1]; 
		t3+=stu1[i].score[2];
		t4+=stu1[i].score[3];
		t5+=stu1[i].score[4]; 		
	}
	
	int m;
	cin>>m;
	int y=0;
	while(1){
		switch(m){
			case 0: cout<<"人数为："<<n1<<endl; break;
			case 1: cout<<"总平均分为："<<t*1.0/n1<<endl; break;
			case 2: cout<<"语文平均分为："<<t1*1.0/n1<<endl; break;
			case 3: cout<<"数学平均分为："<<t2*1.0/n1<<endl; break;
			case 4: cout<<"英语平均分为："<<t3*1.0/n1<<endl; break;
			case 5: cout<<"地理平均分为："<<t4*1.0/n1<<endl; break; 
			case 6: cout<<"历史平均分为："<<t5*1.0/n1<<endl; break; 			
			case 7: cout<<"退出统计"; y=1; break;
			default:cout<<"输入序号错误！请重新输入"<<endl;
		}
		if(y==1){
			cout<<endl;
			break;
		}		
		cout<<"请选择统计方式 0--人数 1--总平均分 2--语文平均分 3--数学平均分 4--英语平均分 5--地理平均分 6--历史平均分 7--退出统计,返回菜单"<<endl;
		cin>>m;
	}	
}

void StuM::menu(){
	readOrClear();
	while(1){
		cout<<endl;
		cout<<"|-------------中 学 生 成 绩 管 理 系 统----------------|"<<endl;
		cout<<"|-------------------1 查询学生信息----------------------|"<<endl;
		cout<<"|-------------------2 添加学生信息----------------------|"<<endl;
		cout<<"|-------------------3 删除学生信息----------------------|"<<endl;
		cout<<"|-------------------4 显示学生信息----------------------|"<<endl;
		cout<<"|-------------------5 编辑学生信息----------------------|"<<endl;
		cout<<"|-------------------6 统计学生信息----------------------|"<<endl;
		cout<<"|-------------------7 学生成绩排序----------------------|"<<endl;
		cout<<"|-------------------8 清空屏幕信息----------------------|"<<endl;		
		cout<<"|-------------------9 退出管理系统----------------------|"<<endl;
		cout<<"|-------------------------------------------------------|"<<endl;
		int m;
		cout<<"输入你的选择："<<endl;
		cin>>m;
		switch(m){
		case 1:find();break;
		case 2:insert();break;
		case 3:del();break;
		case 4:read();break;
		case 5:modify();break;
		case 6:stat();break;
		case 7:sort1();break;
		case 8:system("cls");break;
		case 9:cout<<"退出成功!";exit(0);
		default:cout<<"输入选项序号错误！"<<endl;
		}
	}	
}
