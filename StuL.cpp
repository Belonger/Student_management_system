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
	cout<<"����ѧ��������"<<endl;
	cin>>n;
	cout<<"����ѧ����Ϣ ѧ�� ���� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ���"<<endl;
	for(int i=0;i<n;i++){
		cin>>stu[i].number;
		cin>>stu[i].name;
		for(int j=0;j<3;j++){
			cin>>stu[i].score[j];
			stu[i].total+=stu[i].score[j];
		}
	} 
	cout<<"���ѧ����Ϣ�����룡"<<endl;	
}

void StuL::insert(){
	int num,score1[3];
	char name1[20];
	cout<<"������Ҫ���ѧ����ѧ��:"<<endl;
	cin>>num;
	bool f=1;
	for(int i=0;i<n;i++)
	{
		if(num==stu[i].number){
			cout<<"�޷���Ӹ�ѧ�� ��ѧ����Ϣ�Ѿ����ڣ�"<<endl;
			f=0;
			break;
		}
	}
	if(f){
		cout<<"�������� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ���"<<endl;
		cin>>name>>score1[0]>>score1[1]>>score1[2];
		stu[n].number=num;
		for(int p=0;p<3;p++){
			stu[n].score[p]=score1[p];
			stu[n].total+=score1[p];
		}
		strcpy(stu[n].name,name);
		cout<<"��ӳɹ�"<<endl;
		n++;
		write();//��Ӻ�Ҫ���浽�ļ���
	}	
} 

void StuL::display(){
	cout<<"���ѧ����Ϣ��ѧ��  ����   ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ� �ܳɼ���"<<endl;
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
	cout<<"ѡ������ʽ��1--�����ܳɼ����� 2--�������ĳɼ����� 3--������ѧ�ɼ����� 4--����Ӣ��ɼ����� 5--���ز˵�"<<endl;
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
			cout<<"�������ѡ����Ŵ���"<<endl;
		}
		cout<<"ѡ������ʽ��1--�����ܳɼ����� 2--�������ĳɼ����� 3--������ѧ�ɼ����� 4--����Ӣ��ɼ����� 5--���ز˵�"<<endl;					
		cin>>m;
	} 
}

void StuL::write(){
	for(int i=0;i<n;i++){//�Ȱ��ܳɼ����� �ٴ��� 
			for(int j=0;j<n-i-1;j++){
				if(stu[j].total<stu[j+1].total){
					swap(stu[j],stu[j+1]);
				}
			}
	}
	ofstream outfile("data.dat",ios::binary);
	if(!outfile)
	{
		cerr<<"����ѧ����Ϣʱ���ļ�ʧ�ܣ�"<<endl;
		exit(1);
	}
	cout<<"��ѧ����Ϣ�����ļ�����....."<<endl;
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
		cerr<<"��ȡѧ����Ϣʱ���ļ�ʧ�ܣ�"<<endl;
		exit(1);
	}
	cout<<"���ļ��ж�ȡѧ����Ϣ....."<<endl;
	int j=0;
	cout<<"���ѧ����Ϣ��ѧ��  ����   ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ� �ܳɼ���"<<endl;
	while(infile.read((char*)&stu[j],sizeof(StuL)))
	{
		cout<<setw(16)<<stu[j].number<<setw(8)<<stu[j].name<<" ";
		for(int z=0;z<3;z++){
			cout<<setw(8)<<stu[j].score[z]<<" ";
		}
		cout<<setw(7)<<stu[j].total<<endl; 
		j++;
	}
	n=j; //����ѧ������
	cout<<"ѧ������Ϊ��"<<n<<endl;
	infile.close();	
}

void StuL::readOrClear(){
	cout<<"�Ƿ�����ļ��е�ѧ����Ϣ��(���/��һ��¼����Ϣ ��Ҫ����ѧ����Ϣ�����浽�ļ���  yes--��� no--����� )"<<endl;
	string s;
	cin>>s;
	if(s=="yes")
	{
		n=0;
		input();//��պ���� ����ѧ����Ϣ����
		write();//������Ϣ���浽�ļ���
		read();
	}
	if(s=="no")
	{
		read();
		cout<<"��ȡ��Ϣ��ϣ�"<<endl;
	}	
}

void StuL::modify(){
	int pd=0;//�ж���û�� 
	int t;//��¼λ�� 
	int num;
	cout<<"���������ѧ��: ";
	cin>>num;
	for(int i=0;i<n;i++){
		if(stu[i].number==num){
			pd=1;
			t=i;
		}
	}
	if(pd==0){
		cout<<"�Բ���û����Ҫ�޸ĵ�ѧ����Ϣ"<<endl;
	}
	else{
		cout<< "�������µ�ѧ��: "; 
		cin>>stu[t].number; 
		cout<< " ����: "; 
		cin>>stu[t].name; 
		cout<< " ���ĳɼ�: "; 
		cin>>stu[t].score[0];		
		cout<< " ��ѧ�ɼ�: "; 
		cin>>stu[t].score[1];	
		cout<< " Ӣ��ɼ�: "; 
		cin>>stu[t].score[2]; 
		stu[t].total=stu[t].score[0]+stu[t].score[1]+stu[t].score[2];
		write(); 
		cout<<" �޸ĳɹ� !"<<endl;					
	} 
}

void StuL::del(){
	int num;
	bool f=0;
	cout<<"������Ҫɾ����ѧ��ѧ�ţ�"<<endl;
	cin>>num;
	for(int i=0;i<n;i++){
		if(stu[i].number==num)
		{
			cout<<"�ҵ���ѧ��������ɾ������..."<<endl;
			for(int j=i;j<n-1;j++)
			{
				stu[j].number=stu[j+1].number;
				strcpy(stu[j].name,stu[j+1].name);
				for(int p=0;p<3;p++){
					stu[j].score[p]=stu[j+1].score[p];
				}
			}
			cout<<"ɾ���ɹ���"<<endl;
			n--;//ѧ������-1
			f=1;
			break;
		}
	}
	if(f)
		write();
	else 
		cout<<"�����ڸ�ѧ�����޷�ɾ����"<<endl;
		
}

void StuL::find(){
	cout<<"ѡ���ѯ��ʽ��0--ѧ�� 1--����:"<<endl;
	int s;
	cin>>s;
	while(1){
		if(s==0){
			cout<<"������Ҫ��ѯ��ѧ�ţ�"<<endl;
			int num;
			cin>>num;
			for(int i=0;i<n;i++){
				if(num==stu[i].number){
					cout<<"��ѯ�ɹ���"<<num<<"��ѧ����Ϣ ������"<<stu[i].name<<" ";
					cout<<"���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ���"<<stu[i].score[0]<<" "<<stu[i].score[1]<<" "<<stu[i].score[2]<<endl;
				}
			}		
			break;
		}
		else if(s==1){
			cout<<"������Ҫ��ѯ��ѧ��������"<<endl;
			char name[20];
			cin>>name;
			for(int i=0;i<n;i++){
				if(strcmp(stu[i].name,name)==0){
					cout<<"��ѯ�ɹ���"<<name<<"ѧ����Ϣ ѧ�� �ɼ���"<<stu[i].number<<" ";
					cout<<"���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ���"<<stu[i].score[0]<<" "<<stu[i].score[1]<<" "<<stu[i].score[2]<<endl;
				}
			}	
			break;
		}
		else{
			cout<<"�����ѡ������������������룺"<<endl;
			cin>>s;
		}
	}	
}

void StuL::stat(){
	cout<<"��ѡ��ͳ�Ʒ�ʽ 0--����ͳ�� 1--��ƽ����ͳ�� 2--����ƽ����ͳ�� 3--��ѧƽ����ͳ�� 4--Ӣ��ƽ����ͳ�� 5--�˳�ͳ��,���ز˵�"<<endl; 
	
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
			case 0: cout<<"����Ϊ��"<<n<<endl; break;
			case 1: cout<<"��ƽ����Ϊ��"<<t*1.0/n<<endl; break;
			case 2: cout<<"����ƽ����Ϊ��"<<t1*1.0/n<<endl; break;
			case 3: cout<<"��ѧƽ����Ϊ��"<<t2*1.0/n<<endl; break;
			case 4: cout<<"Ӣ��ƽ����Ϊ��"<<t3*1.0/n<<endl; break;
			case 5: cout<<"�˳�ͳ��"; y=1; break;
			default:cout<<"������Ŵ�������������"<<endl;
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
		cout<<"|-------------С ѧ �� �� �� �� �� ϵ ͳ----------------|"<<endl;
		cout<<"|-------------------1 ��ѯѧ����Ϣ----------------------|"<<endl;
		cout<<"|-------------------2 ���ѧ����Ϣ----------------------|"<<endl;
		cout<<"|-------------------3 ɾ��ѧ����Ϣ----------------------|"<<endl;
		cout<<"|-------------------4 ��ʾѧ����Ϣ----------------------|"<<endl;
		cout<<"|-------------------5 �༭ѧ����Ϣ----------------------|"<<endl;
		cout<<"|-------------------6 ͳ��ѧ����Ϣ----------------------|"<<endl;
		cout<<"|-------------------7 ѧ���ɼ�����----------------------|"<<endl;
		cout<<"|-------------------8 �����Ļ��Ϣ----------------------|"<<endl;		
		cout<<"|-------------------9 �˳�����ϵͳ----------------------|"<<endl;
		cout<<"|-------------------------------------------------------|"<<endl;
		int m;
		cout<<"�������ѡ��"<<endl;
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
		case 9:cout<<"�˳��ɹ�!";exit(0);
		default:cout<<"����ѡ����Ŵ���"<<endl;
		}
	}	
}
