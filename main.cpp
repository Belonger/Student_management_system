#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "StuL.h"
#include "StuM.h"
#include "StuB.h"
using namespace std;

int main() {
	int choose; 
	cout<<"�����������ѧ�����гɼ�ͳ�� 1--Сѧ�� 2--��ѧ�� 3--��ѧ��"<<endl;
	StuL ll;
	StuM mm;
	StuB bb; 
	cin>>choose;
	switch(choose){
		case 1: ll.menu(); break;
		case 2: mm.menu(); break;
		case 3: bb.menu(); break;
	}
 	
 	return 0;
}
