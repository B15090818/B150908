/* ��consumption.h�ļ����������� */
#ifndef _CONSUMPTION             /*�������룬��ֹ�ظ������Ĵ���*/
#define _CONSUMPTION
#include <string.h>
#define NUM 30               /*����ÿ���������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Date                   /*���Ѽ�¼��������*/
{
	int year;
	int month;
	int day;
};
typedef struct Date Date;

struct Consumption                   /*���Ѽ�¼��������*/
{
	Date date;
	double fourObj[4];
	char detail[4][40];
	double total;
	int rank;
};
typedef struct Consumption Consumption;

#define sizeCon sizeof(Consumption)                   /*һ�����Ѽ�¼����Ҫ���ڴ�ռ��С*/
int readCon(Consumption *con,int n);                  /*�������Ѽ�¼ֵ����¼ʱֹͣ*/
void readDate(Consumption *c, int condition);          /*�������ڲ�����consumption,����searchCon������Ӧ��*/
void printCon(Consumption  *con , int n);             /*����������Ѽ�¼��ֵ*/
void reverse(Consumption *con,int n);                 /*���Ѽ�¼����Ԫ������*/
void calcuTotal(Consumption con[],int n);             /*�����������ѵ��ܷ�*/
void calcuRank(Consumption con[],int n);              /*�����ּܷ������ѵ����Σ������в�������*/
void sortCon(Consumption con[],int n);                /*ѡ�񷨴�С�������򣬰�condition���涨������*/
int searchCon(Consumption con[],int n,Consumption c,int condition,int f[]);/*�������н���ѡ��*/ 
int insertCon(Consumption con[],int n,Consumption c);                   /*�������в���һ��Ԫ�ذ���������*/
int deleteCon(Consumption con[],int n,Consumption c);                   /*��������ɾ��һ��ָ�����ڵ�Ԫ��*/
#endif