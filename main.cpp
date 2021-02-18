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
	cout<<"请输入对那类学生进行成绩统计 1--小学生 2--中学生 3--大学生"<<endl;
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
