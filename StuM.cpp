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
	cout<<"����ѧ��������"<<endl;
	cin>>n1;
	cout<<"����ѧ����Ϣ ѧ�� ���� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� ����ɼ� ��ʷ�ɼ���"<<endl;
	for(int i=0;i<n1;i++){
		cin>>stu1[i].number;
		cin>>stu1[i].name;
		for(int j=0;j<5;j++){
			cin>>stu1[i].score[j];
			stu1[i].total+=stu1[i].score[j];
		}
	} 
	cout<<"���ѧ����Ϣ�����룡"<<endl;	
}

void StuM::insert(){
	int num,score1[5];
	char name1[20];
	cout<<"������Ҫ���ѧ����ѧ��:"<<endl;
	cin>>num;
	bool f=1;
	for(int i=0;i<n1;i++)
	{
		if(num==stu1[i].number){
			cout<<"�޷���Ӹ�ѧ�� ��ѧ����Ϣ�Ѿ����ڣ�"<<endl;
			f=0;
			break;
		}
	}
	if(f){
		cout<<"�������� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� ����ɼ� ��ʷ�ɼ���"<<endl;
		cin>>name>>score1[0]>>score1[1]>>score1[2]>>score1[3]>>score[4];
		stu1[n1].number=num;
		for(int p=0;p<5;p++){
			stu1[n1].score[p]=score1[p];
			stu1[n1].total+=score1[p];
		}
		strcpy(stu1[n1].name,name);
		cout<<"��ӳɹ�"<<endl;
		n1++;
		write();//��Ӻ�Ҫ���浽�ļ���
	}	
} 

void StuM::display(){
	cout<<"���ѧ����Ϣ��ѧ��  ����    ���ĳɼ�    ��ѧ�ɼ�    Ӣ��ɼ�    ����ɼ�    ��ʷ�ɼ�   �ܳɼ���"<<endl;
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
	cout<<"ѡ������ʽ��1--���ܳɼ����� 2--�����ĳɼ����� 3--����ѧ�ɼ����� 4--��Ӣ��ɼ����� 5--������ɼ����� 6--����ʷ�ɼ����� 7--���ز˵�"<<endl;		
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
			cout<<"�������ѡ����Ŵ���"<<endl;
		}
		cout<<"ѡ������ʽ��1--���ܳɼ����� 2--�����ĳɼ����� 3--����ѧ�ɼ����� 4--��Ӣ��ɼ����� 5--������ɼ����� 6--����ʷ�ɼ����� 7--���ز˵�"<<endl;					
		cin>>m;
	} 
}

void StuM::write(){
	for(int i=0;i<n1;i++){//�Ȱ��ܳɼ����� �ٴ��� 
			for(int j=0;j<n1-i-1;j++){
				if(stu1[j].total<stu1[j+1].total){
					swap(stu1[j],stu1[j+1]);
				}
			}
	}
	ofstream outfile("dataM.dat",ios::binary);
	if(!outfile)
	{
		cerr<<"����ѧ����Ϣʱ���ļ�ʧ�ܣ�"<<endl;
		exit(1);
	}
	cout<<"��ѧ����Ϣ�����ļ�����....."<<endl;
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
		cerr<<"��ȡѧ����Ϣʱ���ļ�ʧ�ܣ�"<<endl;
		exit(1);
	}
	cout<<"���ļ��ж�ȡѧ����Ϣ....."<<endl;
	int j=0;
	cout<<"ѧ�� ����      ���ĳɼ�    ��ѧ�ɼ�   Ӣ��ɼ�   ����ɼ�   ��ʷ�ɼ���"<<endl;
	while(infile.read((char*)&stu1[j],sizeof(StuM)))
	{
		cout<<" "<<stu1[j].number<<"   "<<stu1[j].name<<" "; 
		for(int p=0;p<5;p++){
			cout<<setw(11)<<stu1[j].score[p];
		}
		cout<<endl;
		j++;
	}
	n1=j; //����ѧ������
	cout<<"ѧ������Ϊ��"<<n1<<endl;
	infile.close();	
}

void StuM::readOrClear(){
	cout<<"�Ƿ�����ļ��е�ѧ����Ϣ��(���/��һ��¼����Ϣ ��Ҫ����ѧ����Ϣ�����浽�ļ���  yes--��� no--����� )"<<endl;
	string s;
	cin>>s;
	if(s=="yes")
	{
		n1=0;
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

void StuM::modify(){
	int pd=0;//�ж���û�� 
	int t;//��¼λ�� 
	int num;
	cout<<"���������ѧ��: ";
	cin>>num;
	for(int i=0;i<n1;i++){
		if(stu1[i].number==num){
			pd=1;
			t=i;
		}
	}
	if(pd==0){
		cout<<"�Բ���û����Ҫ�޸ĵ�ѧ����Ϣ"<<endl;
	}
	else{
		cout<<"�������µ�ѧ��: "; 
		cin>>stu1[t].number; 
		cout<<" ����: "; 
		cin>>stu1[t].name; 
		cout<<"���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� ����ɼ� ��ʷ�ɼ���"; 
		for(int h=0;h<5;h++){
			cin>>stu1[t].score[h];
			stu1[t].total+=stu1[t].score[h];
		}
		write();
		cout<<" �޸ĳɹ� !"<<endl;					
	} 
}

void StuM::del(){
	int num;
	bool f=0;
	cout<<"������Ҫɾ����ѧ��ѧ�ţ�"<<endl;
	cin>>num;
	for(int i=0;i<n1;i++){
		if(stu1[i].number==num)
		{
			cout<<"�ҵ���ѧ��������ɾ������..."<<endl;
			for(int j=i;j<n1-1;j++)
			{
				stu1[j].number=stu1[j+1].number;
				strcpy(stu1[j].name,stu1[j+1].name);
				for(int p=0;p<5;p++){
					stu1[j].score[p]=stu1[j+1].score[p];
				}
			}
			cout<<"ɾ���ɹ���"<<endl;
			n1--;//ѧ������-1
			f=1;
			break;
		}
	}
	if(f)
		write();
	else 
		cout<<"�����ڸ�ѧ�����޷�ɾ����"<<endl;
		
}

void StuM::find(){
	cout<<"ѡ���ѯ��ʽ��0--ѧ�� 1--����:"<<endl;
	int s;
	cin>>s;
	while(1){
		if(s==0){
			cout<<"������Ҫ��ѯ��ѧ�ţ�"<<endl;
			int num;
			cin>>num;
			for(int i=0;i<n1;i++){
				if(num==stu1[i].number){
					cout<<"��ѯ�ɹ���"<<num<<"��ѧ����Ϣ ������"<<stu1[i].name<<" ";
					cout<<"���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� ����ɼ� ��ʷ�ɼ� �ܳɼ���"; 
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
			cout<<"������Ҫ��ѯ��ѧ��������"<<endl;
			char name[20];
			cin>>name;
			for(int i=0;i<n1;i++){
				if(strcmp(stu1[i].name,name)==0){
					cout<<"��ѯ�ɹ���"<<name<<"ѧ����Ϣ ѧ�� �ɼ���"<<stu1[i].number<<" ";
					cout<<"���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� ����ɼ� ��ʷ�ɼ� �ܳɼ���"; 
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
			cout<<"�����ѡ������������������룺"<<endl;
			cin>>s;
		}
	}	
}

void StuM::stat(){
	cout<<"��ѡ��ͳ�Ʒ�ʽ 0--���� 1--��ƽ���� 2--����ƽ���� 3--��ѧƽ���� 4--Ӣ��ƽ���� 5--����ƽ���� 6--��ʷƽ���� 7--�˳�ͳ��,���ز˵�"<<endl; 
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
			case 0: cout<<"����Ϊ��"<<n1<<endl; break;
			case 1: cout<<"��ƽ����Ϊ��"<<t*1.0/n1<<endl; break;
			case 2: cout<<"����ƽ����Ϊ��"<<t1*1.0/n1<<endl; break;
			case 3: cout<<"��ѧƽ����Ϊ��"<<t2*1.0/n1<<endl; break;
			case 4: cout<<"Ӣ��ƽ����Ϊ��"<<t3*1.0/n1<<endl; break;
			case 5: cout<<"����ƽ����Ϊ��"<<t4*1.0/n1<<endl; break; 
			case 6: cout<<"��ʷƽ����Ϊ��"<<t5*1.0/n1<<endl; break; 			
			case 7: cout<<"�˳�ͳ��"; y=1; break;
			default:cout<<"������Ŵ�������������"<<endl;
		}
		if(y==1){
			cout<<endl;
			break;
		}		
		cout<<"��ѡ��ͳ�Ʒ�ʽ 0--���� 1--��ƽ���� 2--����ƽ���� 3--��ѧƽ���� 4--Ӣ��ƽ���� 5--����ƽ���� 6--��ʷƽ���� 7--�˳�ͳ��,���ز˵�"<<endl;
		cin>>m;
	}	
}

void StuM::menu(){
	readOrClear();
	while(1){
		cout<<endl;
		cout<<"|-------------�� ѧ �� �� �� �� �� ϵ ͳ----------------|"<<endl;
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
