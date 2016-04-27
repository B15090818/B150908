/* ①consumption.h文件的完整内容 */
#ifndef _CONSUMPTION             /*条件编译，防止重复包含的错误*/
#define _CONSUMPTION
#include <string.h>
#define NUM 30               /*定义每月天数，此处可以根据实际需要修改常量值*/
struct Date                   /*消费记录的数据域*/
{
	int year;
	int month;
	int day;
};
typedef struct Date Date;

struct Consumption                   /*消费记录的数据域*/
{
	Date date;
	double fourObj[4];
	char detail[4][40];
	double total;
	int rank;
};
typedef struct Consumption Consumption;

#define sizeCon sizeof(Consumption)                   /*一个消费记录所需要的内存空间大小*/
int readCon(Consumption *con,int n);                  /*读入消费记录值，记录时停止*/
void readDate(Consumption *c, int condition);          /*输入日期并付给consumption,便于searchCon函数的应用*/
void printCon(Consumption  *con , int n);             /*输出所有消费记录的值*/
void reverse(Consumption *con,int n);                 /*消费记录数组元素逆置*/
void calcuTotal(Consumption con[],int n);             /*计算所有消费的总分*/
void calcuRank(Consumption con[],int n);              /*根据总分计算消费的名次，允许有并列名次*/
void sortCon(Consumption con[],int n);                /*选择法从小到大排序，按condition所规定的条件*/
int searchCon(Consumption con[],int n,Consumption c,int condition,int f[]);/*从数组中进行选择*/ 
int insertCon(Consumption con[],int n,Consumption c);                   /*向数组中插入一个元素按日期有序*/
int deleteCon(Consumption con[],int n,Consumption c);                   /*从数组中删除一个指定日期的元素*/
#endif