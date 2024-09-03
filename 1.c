#include<stdio.h>
#include<stdlib.h>
struct day
{
char* dayname;
int date;
char* activitydescription;
};
struct day* createday()
{
struct day* newday=(struct day*)malloc(sizeof(struct day));
newday->dayname=(char*)malloc(sizeof(char));
newday->activitydescription=(char*)malloc(sizeof(char));
printf("enter day name:");
scanf("%s",newday->dayname);
printf("enter date:");
scanf("%d",&(newday->date));
printf("enter activity description:");
scanf(" %[^\n]",newday->activitydescription);
return newday;
}
void read(struct day* calendar[],int size)
{
for(int i=0;i<size;i++)
{
printf("enter details for day %d:\n",i+1);
calendar[i]=createday();
}
}

void display(struct day* calendar[],int size)
{
printf("\nweeks's activity details:\n");
for(int i=0;i<size;i++)
{
printf("day %d:\n",i+1);
printf("day name:%s\n",calendar[i]->dayname);
printf("date:%d\n",calendar[i]->date);
printf("activitydescription:%s\n",calendar[i]->activitydescription);
printf("\n");
}
}
void freememory(struct day* calendar[],int size)
{
for(int i=0;i<size;i++)
{
free(calendar[i]->dayname);
free(calendar[i]->activitydescription);
free(calendar[i]);
}
}
int main()
{
struct day* week[7];
read(week,7);
display(week,7);
freememory(week,7);
return 0;
}
