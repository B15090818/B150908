/*��car.c�ļ�����������*/
#include "car.h"
#include <stdio.h>

int readche(car  *che , int n)          /*���복����¼ֵ�����ƺ�Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	if(n>NUM||n<0)printf("���������룺");
	for (i=0;i<n;i++)
	{
		printf("Input one cheliang\'s information\n");
		printf("number:  ");
	     scanf("%s", &che[i].number);
		if (che[i].number==0) break;
		printf("name: ");
		scanf("%s",che[i].name);	
		printf("color:  ");
		scanf("%s",che[i].color);
		printf("�ͺ�:  ");
		scanf("%s",che[i].chexing);
		printf("�������۷֣�");
		scanf("%d",&che[i].grade);	
		printf("�����뷣��ʱ�䣺");
	    scanf("%s",che[i].time);
		printf("�����뷣�����");
		scanf("%d",che[i].money);
		printf("������ɷ�״̬��");
		scanf("%6s",che[i].jiao);
		che[i].rank=0;                 /*������Ҫ�����ܿ۷������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printche (car  *che , int n)       /*������г�����¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%7s  ", che[i].number);
		printf("%8s", che[i].name);
		printf("%8s",che[i].chexing);
		printf("%8s", che[i].color);
		printf("%12s",che[i].weigui);
		printf("%6s",che[i].jiao);
		printf("%10",che[i].time);
	    printf("%7d",che[i].grade);
		printf("%5d",che[i].money);
	    printf("%5d\n",che[i].rank);
	}
}

int equal(car s1,car s2,int condition)  /*����ж�����car��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϳ��ƺ�*/
		return s1.number==s2.number;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚϳ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ���ɫ*/
	     return s1.color==s2.color;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚϳ���*/
		return s1.chexing==s2.chexing;
	else return 1;                       /*�����������1*/
} 

int larger(car s1,car s2,int condition)  /*����condition�����Ƚ�����car��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϳ��ƺ�*/
		return s1.number>s2.number;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܿ۷�*/
		return s1.grade>s2.grade;	
	else return 1; /*�����������1*/
}

void reverse(car che[],int n)             /*����Ԫ������*/
{
	int i;
	car temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=che[i];
		che[i]=che[n-1-i];
		che[n-1-i]=temp;
	}
}


void calcuRank(car che[],int n)          /*�����ܿ۷ּ������г������������۷���ͬ��������ͬ*/
{
	int i ;                       
	sortche(che,n,2);                     /*�ȵ���sortche�㷨�����ܷ���С��������*/
	reverse(che,n);                      /*�����ã����ܷ��ɴ�С������*/
	che[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(che[i],che[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܿ۷����*/
			che[i].rank=che[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			che[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}


void sortche(car che[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	car t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(che[minpos],che[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=che[i];
			che[i]=che[minpos];
			che[minpos]=t;
		}
	}
}

int searchche(car che[],int n,car s,int condition,int f[ ])  /*��che��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(che[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertche(car che[],int n,car s)              /*��che�����������ƺŵ�������һ��Ԫ��s*/
{
	int i;
	sortche(che,n,1);                              /*�Ȱ����ƺ�����*/
	for (i=0;i<n;i++)
	{
		if (equal(che[i],s,1))                      /*������ͬ��������룬��֤���ƺŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*�����ƺŴ�С��������*/
	{
		if (!larger(che[i],s,1))                    /*���s���ڵ�ǰԪ��che[i]�����˳�ѭ��*/
		break;
		che[i+1]=che[i];                         /*����Ԫ��che[i]����һ��λ��*/
	}
	che[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteche(car che[],int n,car s)            /*��������ɾ��ָ�����ƺŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(che[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(che[i],s,1)����*/ 
		che[j]=che[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
