#ifndef STUB_H
#define STUB_H
#include <string>
using namespace std;

class StuB{
	public:		
		StuB();//ѧ�����ݳ�ʼ���ͱ���ѧ������
		void input();//����ѧ����Ϣ 
		void insert();//���ѧ����Ϣ		
		void display();//��ʾѧ����Ϣ 
		void sort1();//��ѧ���ɼ��������� 
		void write();//����Ϣд���ļ�
		void read();//��ȡ�ļ���Ϣ
		void readOrClear();//���ѧ����Ϣ1 
		void modify();//�޸�ѧ����Ϣ
		void stat();//ͳ��ѧ����Ϣ
		void del();//ɾ��ѧ����Ϣ 
		void find();//����ѧ����Ϣ
		void menu();//�˵� 
	private:
		char name[20];//����
		char sex[5];//�Ա�
		int number;//ѧ��
		int className;//�༶
		int total;//�ܷ� 
		int average;//ƽ���� 		
		double score[5];
};

#endif
