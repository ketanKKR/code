#include<stdio.h>
#include<conio.h>
typedef enum Bool {false,true}Bool;
typedef struct Employee
{
   int empcode;
   char name[40];
   int sal;
}Emp;
void Menu()
{
   printf("\n1..Add Record");
   printf("\n2..Display Record");
   printf("\n3..Search Record");
   printf("\n4..Modify Record");
   printf("\n5..Delete Record");
   printf("\n6..Exit");
   printf("\n\nEnter your choice");
}
void main()
{
  Bool flag=false,tag=false;
  Emp emp;
  int recsize=sizeof(emp),ch;
  char ename[40];
  FILE *fp,*ft;

  do
  {
     clrscr();
     Menu();
     scanf("%d",&ch);
     if(flag==false)
     {
	  fp=fopen("emp.dat","rb+");
	  if(fp==NULL)
	  {
	    fp=fopen("emp.dat","wb+");
	     if(fp==NULL)
	     {
	       printf("\nFile can't open");
	       getch();
	       return;
	     }
	  }
     }
     switch(ch)
     {
     case 1://Add Record
     fseek(fp,0,SEEK_END);
     printf("\nEnter empcode name and salary of employee");
     scanf("%d%s%d",&emp.empcode,emp.name,&emp.sal);
     fwrite(&emp,sizeof(emp),1,fp);
     printf("\nRecord Added Succussfully");
     flag=true;
     break;
     case 2://Display record
     rewind(fp);
     printf("\nEmpCode\t\tName\t\tSalary");
     while(fread(&emp,sizeof(emp),1,fp)==1)
     {
       printf("\n%d\t\t%s\t\t%d",emp.empcode,emp.name,emp.sal);
     }
     flag=true;
     break;
     case 3://Search Record
     tag=false;
     printf("\nEnter name for search");
     scanf("%s",ename);
     rewind(fp);
     while(fread(&emp,sizeof(emp),1,fp)==1)
     {
	if(strcmp(ename,emp.name)==0)
	{
	  printf("\nRecord found");
	  printf("\n%d\t\t%s\t\t%d",emp.empcode,emp.name,emp.sal);
	  tag=true;
	  break;
	}
     }
     if(tag==false)
     printf("\nRecord not found");
     flag=true;
     break;
     case 4://Modify Record
     tag=false;
     printf("\nEnter name to modify ");
     scanf("%s",ename);
     rewind(fp);
     while(fread(&emp,sizeof(emp),1,fp)==1)
     {
	if(strcmp(ename,emp.name)==0)
	{
	   fseek(fp,-recsize,SEEK_CUR);
	   printf("\nEnter empcode name and salary of employee");
	   scanf("%d%s%d",&emp.empcode,emp.name,&emp.sal);
	   fwrite(&emp,sizeof(emp),1,fp);
	   printf("\nRecord Modified Succussfully");
	   tag=true;
	   break;
	}
     }
     if(tag==false)
     printf("\nRecord not found");
     break;
     case 5://Delete record
     tag=false;
     ft=fopen("tmp.dat","wb+");
     if(ft==NULL)
     {
       printf("\nTmp file can't open");
       getch();
       return;
     }
     printf("\nEnter name to delete ");
     scanf("%s",ename);
     rewind(fp);
     while(fread(&emp,sizeof(emp),1,fp)==1)
     {
	if(strcmp(ename,emp.name)!=0)
	{
	   fwrite(&emp,sizeof(emp),1,ft);
	   tag=true;
	   flag=false;
	}
     }

     if(tag==false)
     printf("\nRecord not found");
     else
     {
	 fclose(fp);
	 fclose(ft);
	 remove("emp.dat");
	 rename("tmp.dat","emp.dat");
	 printf("\nRecord deleted succussfully");
     }

     break;
     case 6://Exit
     break;
     default:
     printf("\nWrong choice");
     }
      if(ch!=6)
      getch();
  }while(ch!=6);
}
