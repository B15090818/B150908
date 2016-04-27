/*②consumption.c文件的完整内容*/
#include "consumption.h"
#include <stdio.h>

int readCon(Consumption *con,int n)          /*读入消费记录值，直到为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0; i<n; i++)
	{
		printf("Input one consumption\'s information\n");
		printf("Input date\n");
		printf("year:  ");
		scanf("%ld", &con[i].date.year);
		printf("month:  ");
		scanf("%ld", &con[i].date.month);
		printf("day:  ");
		scanf("%ld", &con[i].date.day);
		printf("expense detail: ");
    	con[i].total=0;                                 /*总消费金额需要计算求得，初值置为0*/
		printf("Input four object of the consumption and the datail:\n");
		for (j=0; j<4; j++)
	    {
		    scanf("%ld",&con[i].fourObj[j]);
			scanf("%s",&con[i].detail);	
		}
		con[i].rank=0;                 /*名次需要根据总分来计算，初值置为0*/
	}
	return i;                                                /*返回实际读入的记录条数*/
}

void readDate(Consumption *c, int condition)             /*输入日期*/
{                   
	Date date;
	int i;
	printf("Input date\n");
	switch (condition)
	{
		case 1:	
			printf("Input the year will be searched:\n");							/*输入year日期*/
			scanf("%d",&date.year);
			c->date.year = date.year;
			break;
		case 2:											/*输入month日期*/
			printf("Input the year and month will be searched:\n");
			scanf("%d%d",&date.year,&date.month);
			c->date.year = date.year;
			c->date.month = date.month;
			break;
		case 3:											/*输入day日期*/
			printf("Input the year,the month and the day  will be searched:\n");
			scanf("%d%d%d",&date.year,&date.month,&date.day);
			c->date.year = date.year;
			c->date.month = date.month;
			c->date.day = date.day;
			break;
	}
	for (i=0; i<4; i++)
	    {
		    c->fourObj[i] = 0;
			//c->detail[i] = "      ";
		}
	 c->total = 0;
	 c->rank = 0;
}

void printCon (Consumption *con, int n)                     /*输出所有消费记录的值*/
{
    int i,j;
	for (i=0; i<n; i++)
	{
		printf("%d-%d-%d\t",con[i].date.year,con[i].date.month,con[i].date.day);
		for (j=0; j<4; j++)
		{
		   printf("%ld",con[i].fourObj[j]);
		   printf("(%s)\t", con[i].detail[i]);
		}
	    printf("%ld\t\n",con[i].total);
	    
	}
}

void reverse(Consumption *con, int n)             /*数组元素逆置*/
{
	int i;
	Consumption temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=con[i];
		con[i]=con[n-1-i];
		con[n-1-i]=temp;
	}
}

void calcuTotal(Consumption con[],int n)         /*计算所有消费的的金额*/
{
	int i,j;
	for (i=0; i<n; i++)                          /*外层循环控制一个月的消费记录*/
	{
		con[i].total =0;
		for (j=0; j<4; j++)                      /*内层循环控制四个项目*/
		con[i].total +=con[i].fourObj[j];
	}	
}

void calcuRank(Consumption con[],int n)          /*根据总分计算所有日期中的消费总金额的排名，消费总金额相同者名次相同*/
{
	int i ;                       
	sortCon(con,n);                       /*先调用sortStu算法，按总分由小到大排序*/
	reverse(con,n);                          /*再逆置，则按消费总金额由大到小排序了*/
	con[0].rank=1;                           /*第一条记录的名次一定是1*/
	for (i=1; i<n; i++)                        /*从第二条记录一直到最后一条进行循环*/
	{
		if (con[i].total == con[i-1].total)         /*当前记录与其相邻的前一条记录如果消费总金额相等*/
			con[i].rank=con[i-1].rank;        /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			con[i].rank=i+1;                 /*不相等时当前记录名次等于其下标号+1*/
	}
}

void sortCon(Consumption con[],int n)  /*选择法排序，按date条件由小到大排序*/
{
	int i,j1,j2,j3,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Consumption c;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		         /*寻找本趟最小元素所在的下标*/
			for (j1=i+1; j1<n; j1++)
			{
				if (con[i].date.year > con[j1].date.year)
					minpos=j1;
			}
			if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
			{
				c=con[i];
				con[i]=con[minpos];
				con[minpos]=c;
			}
	}
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		         /*寻找本趟最小元素所在的下标*/
			for (j2=i+1; j2<n; j2++)
			{
				if (con[i].date.year == con[j1].date.year && con[i].date.month > con[j1].date.month)
					minpos=j2;
			}
			if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
			{
				c=con[i];
				con[i]=con[minpos];
				con[minpos]=c;
			}
	}
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		         /*寻找本趟最小元素所在的下标*/
			for (j3=i+1; j3<n; j3++)
			{
				if (con[i].date.year == con[j1].date.year && con[i].date.month == con[j1].date.month && con[i].date.day == con[j1].date.day)
					minpos=j1;
			}
			if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
			{
				c=con[i];
				con[i]=con[minpos];
				con[minpos]=c;
			}
	}
			
}

int searchCon(Consumption con[],int n,Consumption c,int condition,int f[])  /*在con数组中依date条件查找*/
/*与c相同的元素*/
{
	int i,j=0,find=0;
	switch (condition)
	{
		case 1:	for (i=0; i<n; i++)                                 /*待查找的元素按照年*/
					if (con[i].date.year == c.date.year)  
					{
						f[j++]=i;								/*找到了相等的元素，将其下标放到find中*/
						find++;
					}
					return find;                                /*返回find，其值为0则表示没找到*/ 
		case 2:	for (i=0; i<n; i++)                                 /*待查找的元素按照年月*/
					if (con[i].date.year == c.date.year && con[i].date.month == c.date.month)  
					{
						f[j++]=i;								/*找到了相等的元素，将其下标放到find中*/
						find++;
					}
					return find;                                /*返回find，其值为0则表示没找到*/ 
		case 3:for (i=0; i<n; i++)                                 /*待查找的元素按照年月日*/
					if (con[i].date.year == c.date.year && con[i].date.month == c.date.month && con[i].date.day == c.date.day)  
					{
						f[j++]=i;								/*找到了相等的元素，将其下标放到find中*/
						find++;
					}
					return find;                                /*返回find，其值为0则表示没找到*/ 
	}	
}

int insertCon(Consumption con[],int n,Consumption c)              /*向con数组中依date增插入一个元素c*/
{
	int i;
	sortCon(con,n);                              /*先date排序*/
	for (i=0;i<n;i++)
	{
		if (con[i].date.year == c.date.year && con[i].date.month == c.date.month && con[i].date.day == c.date.day)                      /*学号相同不允许插入，保证学号的唯一性*/
		{
		    printf("this date exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按从小到大有序*/
	{
		if (!(con[i].date.year == c.date.year && con[i].date.month == c.date.month && con[i].date.day > c.date.day))                    /*如果s大于当前元素stu[i]，则退出循环*/
		break;
		con[i+1]=con[i];                         /*否则元素con[i]后移一个位置*/
	}
	con[i+1]=c;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteCon(Consumption con[],int n,Consumption c)            /*从数组中删除指定学号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (con[i].date.year == c.date.year && con[i].date.month == c.date.month && con[i].date.day == c.date.day)   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(stu[i],s,1)成立*/ 
		con[j]=con[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}
