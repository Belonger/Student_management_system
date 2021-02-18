#ifndef STUB_H
#define STUB_H
#include <string>
using namespace std;

class StuB{
	public:		
		StuB();//学生数据初始化和保存学生数据
		void input();//输入学生信息 
		void insert();//添加学生信息		
		void display();//显示学生信息 
		void sort1();//对学生成绩进行排序 
		void write();//把信息写入文件
		void read();//读取文件信息
		void readOrClear();//清空学生信息1 
		void modify();//修改学生信息
		void stat();//统计学生信息
		void del();//删除学生信息 
		void find();//查找学生信息
		void menu();//菜单 
	private:
		char name[20];//姓名
		char sex[5];//性别
		int number;//学号
		int className;//班级
		int total;//总分 
		int average;//平均分 		
		double score[5];
};

#endif
