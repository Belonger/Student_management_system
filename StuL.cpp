#include "StuL.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

StuL stu[100];
int n=0;

StuL::StuL(){
	strcpy(name," ");
	strcpy(sex," ");
	number=0;
	className=0;
	total=0;
	average=0;
	for(int i=0;i<3;i++)score[i]=0;
}

void StuL::input(){
	cout<<"输入学生人数："<<endl;
	cin>>n;
	cout<<"输入学生信息 学号 姓名 语文成绩 数学成绩 英语成绩："<<endl;
	for(int i=0;i<n;i++){
		cin>>stu[i].number;
		cin>>stu[i].name;
		for(int j=0;j<3;j++){
			cin>>stu[i].score[j];
			stu[i].total+=stu[i].score[j];
		}
	} 
	cout<<"完成学生信息的输入！"<<endl;	
}

void StuL::insert(){
	int num,score1[3];
	char name1[20];
	cout<<"输入所要添加学生的学号:"<<endl;
	cin>>num;
	bool f=1;
	for(int i=0;i<n;i++)
	{
		if(num==stu[i].number){
			cout<<"无法添加该学生 该学生信息已经存在！"<<endl;
			f=0;
			break;
		}
	}
	if(f){
		cout<<"输入姓名 语文成绩 数学成绩 英语成绩："<<endl;
		cin>>name>>score1[0]>>score1[1]>>score1[2];
		stu[n].number=num;
		for(int p=0;p<3;p++){
			stu[n].score[p]=score1[p];
			stu[n].total+=score1[p];
		}
		strcpy(stu[n].name,name);
		cout<<"添加成功"<<endl;
		n++;
		write();//添加后要保存到文件中
	}	
} 

void StuL::display(){
	cout<<"输出学生信息：学号  姓名   语文成绩  数学成绩  英语成绩 总成绩："<<endl;
	for(int i=0;i<n;i++){
		cout<<setw(16)<<stu[i].number<<setw(8)<<stu[i].name<<" ";
		for(int j=0;j<3;j++){
			cout<<setw(8)<<stu[i].score[j]<<" ";
		}
		cout<<setw(7)<<stu[i].total; 
		cout<<endl;
	}
}

void StuL::sort1(){
	cout<<"选择排序方式：1--按照总成绩排序 2--按照语文成绩排序 3--按照数学成绩排序 4--按照英语成绩排序 5--返回菜单"<<endl;
	int m;
	cin>>m;
	while(1){
		if(m==1){
			for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					if(stu[j].total<stu[j+1].total){
						swap(stu[j],stu[j+1]);
					}
				}
			}	
			display();	
		} 
		else if(m==2){
			for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					if(stu[j].score[0]<stu[j+1].score[0]){
						swap(stu[j],stu[j+1]);
					}
				}
			}
			display();	
		}
		else if(m==3){
			for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					if(stu[j].score[1]<stu[j+1].score[1]){
						swap(stu[j],stu[j+1]);
					}
				}
			}
			display();	
		}
		else if(m==4){
			for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					if(stu[j].score[2]<stu[j+1].score[2]){
						swap(stu[j],stu[j+1]);
					}
				}
			}
			display();	
		}	
		else if(m==5){
			break;
		}	
		else{
			cout<<"输入号码选项序号错误！"<<endl;
		}
		cout<<"选择排序方式：1--按照总成绩排序 2--按照语文成绩排序 3--按照数学成绩排序 4--按照英语成绩排序 5--返回菜单"<<endl;					
		cin>>m;
	} 
}

void StuL::write(){
	for(int i=0;i<n;i++){//先按总成绩排序 再存入 
			for(int j=0;j<n-i-1;j++){
				if(stu[j].total<stu[j+1].total){
					swap(stu[j],stu[j+1]);
				}
			}
	}
	ofstream outfile("data.dat",ios::binary);
	if(!outfile)
	{
		cerr<<"保存学生信息时打开文件失败！"<<endl;
		exit(1);
	}
	cout<<"将学生信息读入文件当中....."<<endl;
	for(int i=0;i<n;i++)
	{
		outfile.write((char*)&stu[i],sizeof(StuL));
	}
	outfile.close();	
}

void StuL::read(){
	ifstream infile("data.dat",ios::binary);
	if(!infile)
	{
		cerr<<"读取学生信息时打开文件失败！"<<endl;
		exit(1);
	}
	cout<<"从文件中读取学生信息....."<<endl;
	int j=0;
	cout<<"输出学生信息：学号  姓名   语文成绩  数学成绩  英语成绩 总成绩："<<endl;
	while(infile.read((char*)&stu[j],sizeof(StuL)))
	{
		cout<<setw(16)<<stu[j].number<<setw(8)<<stu[j].name<<" ";
		for(int z=0;z<3;z++){
			cout<<setw(8)<<stu[j].score[z]<<" ";
		}
		cout<<setw(7)<<stu[j].total<<endl; 
		j++;
	}
	n=j; //保存学生人数
	cout<<"学生人数为："<<n<<endl;
	infile.close();	
}

void StuL::readOrClear(){
	cout<<"是否清空文件中的学生信息？(清空/第一次录入信息 需要输入学生信息，保存到文件中  yes--清空 no--不清空 )"<<endl;
	string s;
	cin>>s;
	if(s=="yes")
	{
		n=0;
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

void StuL::modify(){
	int pd=0;//判断有没有 
	int t;//记录位置 
	int num;
	cout<<"请输入你的学号: ";
	cin>>num;
	for(int i=0;i<n;i++){
		if(stu[i].number==num){
			pd=1;
			t=i;
		}
	}
	if(pd==0){
		cout<<"对不起，没有你要修改的学生信息"<<endl;
	}
	else{
		cout<< "请输入新的学号: "; 
		cin>>stu[t].number; 
		cout<< " 姓名: "; 
		cin>>stu[t].name; 
		cout<< " 语文成绩: "; 
		cin>>stu[t].score[0];		
		cout<< " 数学成绩: "; 
		cin>>stu[t].score[1];	
		cout<< " 英语成绩: "; 
		cin>>stu[t].score[2]; 
		stu[t].total=stu[t].score[0]+stu[t].score[1]+stu[t].score[2];
		write(); 
		cout<<" 修改成功 !"<<endl;					
	} 
}

void StuL::del(){
	int num;
	bool f=0;
	cout<<"输入你要删除的学生学号："<<endl;
	cin>>num;
	for(int i=0;i<n;i++){
		if(stu[i].number==num)
		{
			cout<<"找到该学生！进行删除操作..."<<endl;
			for(int j=i;j<n-1;j++)
			{
				stu[j].number=stu[j+1].number;
				strcpy(stu[j].name,stu[j+1].name);
				for(int p=0;p<3;p++){
					stu[j].score[p]=stu[j+1].score[p];
				}
			}
			cout<<"删除成功！"<<endl;
			n--;//学生人数-1
			f=1;
			break;
		}
	}
	if(f)
		write();
	else 
		cout<<"不存在该学生！无法删除！"<<endl;
		
}

void StuL::find(){
	cout<<"选择查询方式：0--学号 1--姓名:"<<endl;
	int s;
	cin>>s;
	while(1){
		if(s==0){
			cout<<"输入你要查询的学号："<<endl;
			int num;
			cin>>num;
			for(int i=0;i<n;i++){
				if(num==stu[i].number){
					cout<<"查询成功！"<<num<<"号学生信息 姓名："<<stu[i].name<<" ";
					cout<<"语文成绩 数学成绩 英语成绩："<<stu[i].score[0]<<" "<<stu[i].score[1]<<" "<<stu[i].score[2]<<endl;
				}
			}		
			break;
		}
		else if(s==1){
			cout<<"输入你要查询的学生姓名："<<endl;
			char name[20];
			cin>>name;
			for(int i=0;i<n;i++){
				if(strcmp(stu[i].name,name)==0){
					cout<<"查询成功！"<<name<<"学生信息 学号 成绩："<<stu[i].number<<" ";
					cout<<"语文成绩 数学成绩 英语成绩："<<stu[i].score[0]<<" "<<stu[i].score[1]<<" "<<stu[i].score[2]<<endl;
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

void StuL::stat(){
	cout<<"请选择统计方式 0--人数统计 1--总平均分统计 2--语文平均分统计 3--数学平均分统计 4--英语平均分统计 5--退出统计,返回菜单"<<endl; 
	
	double t=0,t1=0,t2=0,t3=0;
	for(int i=0;i<n;i++){
		t+=stu[i].total;
		t1+=stu[i].score[0]; 
		t2+=stu[i].score[1]; 
		t3+=stu[i].score[2]; 		
	}
	
	int m;
	cin>>m;
	int y=0;
	while(1){
		switch(m){
			case 0: cout<<"人数为："<<n<<endl; break;
			case 1: cout<<"总平均分为："<<t*1.0/n<<endl; break;
			case 2: cout<<"语文平均分为："<<t1*1.0/n<<endl; break;
			case 3: cout<<"数学平均分为："<<t2*1.0/n<<endl; break;
			case 4: cout<<"英语平均分为："<<t3*1.0/n<<endl; break;
			case 5: cout<<"退出统计"; y=1; break;
			default:cout<<"输入序号错误！请重新输入"<<endl;
		}
		if(y==1){
			cout<<endl;
			break;
		}
		cin>>m;
	}	
}

void StuL::menu(){
	readOrClear();
	while(1){
		cout<<endl;
		cout<<"|-------------小 学 生 成 绩 管 理 系 统----------------|"<<endl;
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
