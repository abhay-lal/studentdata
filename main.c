//  project
//  Created by Abhay Lal on 22/03/21.
#include <stdio.h>
#include <string.h>
struct student
{
    int stdid,rno,std;
    char div;
    char na[26],dob[26],ad[50];
    float mat,sci,com;
};
typedef struct student stud;
int newstud()
{
        FILE *ptr;
        stud s;
        ptr=fopen("Student.Dat","a");

        if(ptr==NULL)
        {
            printf("Unable to create a file");
        }
        else
        {
            printf("Enter your roll number ");
            scanf("%d",&s.rno);
            fflush(stdin);
            printf("Enter your Name ");
            scanf("%s",s.na);
            fflush(stdin);
            printf("Enter your Standard ");
            scanf("%d",&s.std);
            fflush(stdin);
            printf("Enter your Division ");
            scanf("%c",&s.div);
            fflush(stdin);
            printf("Enter your address ");
            scanf("%s",s.ad);
            fflush(stdin);
            printf("Enter your date of birth ");
            scanf("%s",s.dob);
            fflush(stdin);
            printf("Enter your Science, Maths & Computer Marks ");
            scanf("%f%f%f",&s.sci,&s.mat,&s.com);
            fflush(stdin);
            
            fwrite(&s,sizeof(s),1,ptr);
            printf("One Record Added");
            fclose(ptr);
        }
        
    return 0;
}
int viewallstud()
{

    FILE *ptr;
    stud s;
    
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION            ADDRESS          DATE OF BIRTH         SCIENCE          MATHS          COMPUTERS\n");
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {
            printf("%2d %16s %16d %16c %19s %19s %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.ad,s.dob,s.sci,s.mat,s.com);
            //printf("%2d %25s %2d %c %25s %12s %6.2f %6.2f %6.2f\n",s.rno,s.na,s.std,s.div,s.ad,s.dob,s.sci,s.mat,s.com);
            
        }
        fclose(ptr);
    }
    return 0;
}
int findstudna(char n[])
{

    FILE *ptr;
    stud s;
   
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION            ADDRESS          DATE OF BIRTH         SCIENCE          MATHS          COMPUTERS\n");
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {

            if(strcmp(n,s.na)==0)
            {
                printf("%2d %16s %16d %16c %19s %19s %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.ad,s.dob,s.sci,s.mat,s.com);
                break;
            }
        }
        fclose(ptr);
    }
    return 0;
}
int findstudad(char n[])
{

    FILE *ptr;
    stud s;
 
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION            ADDRESS          DATE OF BIRTH         SCIENCE          MATHS          COMPUTERS\n");
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {

            if(strcmp(n,s.ad)==0)
            {
                printf("%2d %16s %16d %16c %19s %19s %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.ad,s.dob,s.sci,s.mat,s.com);
                break;
            }
        }
        
        fclose(ptr);
            
    }
    return 0;
}
int findstuddob(char n[])
{

    FILE *ptr;
    stud s;
 
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION            ADDRESS          DATE OF BIRTH         SCIENCE          MATHS          COMPUTERS\n");
        
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {

            if(strcmp(n,s.dob)==0)
            {
                printf("%2d %16s %16d %16c %19s %19s %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.ad,s.dob,s.sci,s.mat,s.com);
                break;
            }
        }
                fclose(ptr);
            
    }
    return 0;
}

int findstudsd(int n,char m)
{

    FILE *ptr;
    stud s;
    
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION            ADDRESS          DATE OF BIRTH         SCIENCE          MATHS          COMPUTERS\n");
        
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {

            if(n==s.std && m==s.div)
            {
                printf("%2d %16s %16d %16c %19s %19s %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.ad,s.dob,s.sci,s.mat,s.com);
                break;
            }
        }
                fclose(ptr);
            
    }
    return 0;
}

int delete(int n)
{

    FILE *ptr;
    FILE *ptr1;
    stud s;
   
    ptr=fopen("Student.Dat","r");
    ptr1=fopen("Student1.Dat","w");
    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
    
        
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {
       if(s.rno!=n)
       {
           fwrite(&s,sizeof(s),1,ptr1);
       }
    }
        printf("Updated\n");
        fclose(ptr);
        fclose(ptr1);
        remove("Student.dat");
        rename("Student1.dat","Student.dat");
        fclose(ptr);
            
    }
    return 0;
}

int sortstudsd()
{

    FILE *ptr;
    FILE *ptr1;
    stud s;
    ptr=fopen("Student.Dat","r");
    ptr1=fopen("Student1.Dat","w");
    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        int arr[50];
        int i=0;
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {
         arr[i]=s.std;
         i++;
        }
        int t,j;
        for(i=sizeof(arr)-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    t=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=t;
                }
                
            }
        }
        for(i=0;i<sizeof(arr);i++)
        {
            while(fread(&s,sizeof(s),1,ptr)!=NULL)
            {
                if(s.std==arr[i])
                {
                    fwrite(&s,sizeof(s),1,ptr1);
                    break;
                }
            }
        }
        
        printf("Updated\n");
        fclose(ptr);
        fclose(ptr1);
        remove("Student.dat");
        rename("Student1.dat","Student.dat");
        fclose(ptr);
        fclose(ptr);
        viewallstud();
            
    }
    return 0;
}

void displayData(stud s[],int m)
{
    int i;
    printf("RNO.          NAME          STANDARD          DIVISION            ADDRESS          DATE OF BIRTH         SCIENCE          MATHS          COMPUTERS\n");
    for(i=0;i<m;i++)
    {
        printf("%2d %16s %16d %16c %19s %19s %16.2f %16.2f %16.2f\n",s[i].rno,s[i].na,s[i].std,s[i].div,s[i].ad,s[i].dob,s[i].sci,s[i].mat,s[i].com);
       // printf("%2d %25s %2d %c %25s %12s %6.2f %6.2f %6.2f\n",s[i].rno,s[i].na,s[i].std,s[i].div,s[i].ad,s[i].dob,s[i].sci,s[i].mat,s[i].com);
    }
}
int sortstudstddiv()
{
    FILE *ptr;
    stud s[101],t;
    int i,j,count=0;
    ptr=fopen("Student.Dat","r");
    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        while(fread(&s[count++],sizeof(stud),1,ptr)!=NULL)
        {
        
        for(i=count-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
                if(s[j].div>s[j+1].div)
                {
                    
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
                if(s[j].std>s[j+1].std)
                {
                    
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
             
            }
        }
        }
        displayData(s,count-1);
        fclose(ptr);
        
}
    return 0;
}
int sortstudstdna()
{
    FILE *ptr;
    stud s[101],t;
    int i,j,count=0;
    ptr=fopen("Student.Dat","r");
    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        while(fread(&s[count++],sizeof(stud),1,ptr)!=NULL)
        {
        
        for(i=count-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
                if(strcasecmp(s[j].na,s[j+1].na)>0)
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
                if(s[j].std>s[j+1].std)
                {
                    
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
        }
        displayData(s,count-1);
        fclose(ptr);
        
}
    return 0;
}
int sortstudstdmarks()
{
    FILE *ptr;
    stud s[101],t;
    int i,j,count=0;
    ptr=fopen("Student.Dat","r");
    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        while(fread(&s[count++],sizeof(stud),1,ptr)!=NULL)
        {
        
        for(i=count-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
                float avg=(s[j].sci+s[j].mat+s[j].com)/3;
                float avg1=(s[j+1].sci+s[j+1].mat+s[j+1].com)/3;
                if(avg>avg1)
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
                if(s[j].std>s[j+1].std )
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
        }
        displayData(s,count-1);
        fclose(ptr);
        
}
    return 0;
}
int sortstuddetails()
{
 
    FILE *ptr;
    stud s[101],t;
    int i,j,count=0;
    ptr=fopen("Student.Dat","r");
    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        while(fread(&s[count++],sizeof(stud),1,ptr)!=NULL)
        {
        
        for(i=count-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
                if(s[j].std>s[j+1].std)
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
        }
        displayData(s,count-1);
        fclose(ptr);
        
}
    return 0;
}

int reportstd(int n)
{
    
    FILE *ptr;
    stud s;
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION          SCIENCE          MATHS          COMPUTERS          AVERAGE \n");
        
  while(fread(&s,sizeof(s),1,ptr)!=NULL)
  {
     
        if(s.std==n)
        {
            float avg=(s.sci+s.mat+s.com)/3;
            
            printf("%2d %16s %16d %16c %16.2f %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.sci,s.mat,s.com,avg);
        
        }
    }
        fclose(ptr);
            
    }
    return 0;
}
int reportstdiv(int n,char d)
{
    
    FILE *ptr;
    stud s;
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION          SCIENCE          MATHS          COMPUTERS          AVERAGE \n");
  while(fread(&s,sizeof(s),1,ptr)!=NULL)
  {
        if(s.std==n && s.div==d)
        {
            float avg=(s.sci+s.mat+s.com)/3;
            printf("%2d %16s %16d %16c %16.2f %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.sci,s.mat,s.com,avg);
       // printf("%2d %25s %2d %c %6.2f %6.2f %6.2f %6.2f\n",s.rno,s.na,s.std,s.div,s.sci,s.mat,s.com,avg);
        
        }
    }
        fclose(ptr);
            
    }
    return 0;
}
int reporttm(float n)
{
    
    FILE *ptr;
    stud s;
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION          SCIENCE          MATHS          COMPUTERS          AVERAGE \n");
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {
         float tm=(s.sci+s.mat+s.com)/3;
        if(tm==n)
        {
            float avg=(s.sci+s.mat+s.com)/3;
        
            printf("%2d %16s %16d %16c %16.2f %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.sci,s.mat,s.com,avg);
        
        }
    }
        fclose(ptr);
            
    }
    return 0;
}
int reportad(char x[])
{
    
    FILE *ptr;
    stud s;
    
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {printf("RNO.          NAME          STANDARD          DIVISION          SCIENCE          MATHS          COMPUTERS          AVERAGE \n");
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {
        
        if(strcmp(s.ad,x)==0)
        {
            float avg=(s.sci+s.mat+s.com)/3;
        
            printf("%2d %16s %16d %16c %16.2f %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.sci,s.mat,s.com,avg);
        
        }
    }
        fclose(ptr);
            
    }
    return 0;
}
int reportdob(char x[])
{
    
    FILE *ptr;
    stud s;
    
    ptr=fopen("Student.Dat","r");

    if(ptr==NULL)
    {
        printf("Unable to open a file");
    }
    else
    {
        printf("RNO.          NAME          STANDARD          DIVISION          SCIENCE          MATHS          COMPUTERS          AVERAGE \n");
        while(fread(&s,sizeof(s),1,ptr)!=NULL)
        {
        
        if(strcmp(s.dob,x)==0)
        {
            float avg=(s.sci+s.mat+s.com)/3;
        
            printf("%2d %16s %16d %16c %16.2f %16.2f %16.2f %16.2f\n",s.rno,s.na,s.std,s.div,s.sci,s.mat,s.com,avg);
        
        }
    }
        fclose(ptr);
            
    }
    return 0;
}

int searchmenu()
{
    int ch;
    do
        {
        printf("SEARCH MENU\n");
        printf("1)By name\n");
        printf("2)By address\n");
        printf("3)By date of birth\n");
        printf("4)By standard & division\n");
        printf("5)Back\n");
        printf("ENTER CHOICE:\n");
        scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                {  char y[26];
                    printf("Enter name to be searched ");
                    scanf("%s",y);
                    findstudna(y);
                    break;
                }
                case 2:
                {  char y[26];
                    printf("Enter address to be searched ");
                    scanf("%s",y);
                    findstudad(y);
                    break;
                }
                case 3:
                {  char y[26];
                    printf("Enter date of birth to be searched ");
                    scanf("%s",y);
                    findstuddob(y);
                    break;
                }
                case 4:
                {  char y;
                    int x;
                    printf("Enter standard to be searched \n");
                    scanf("%d",&x);
                    fflush(stdin);
                    printf("Enter division to be searched \n");
                    scanf("%c",&y);
                    findstudsd(x,y);
                    break;
                }
                    break;
                 default:
                    break;
                 
            }
        }while(ch!=5);
    return 0;
}
int editstud()
{
        FILE *ptr1,*ptr2;
        int rn;
        stud s;
        ptr1=fopen("Student.dat","r");
        ptr2=fopen("Temp.dat","a");

        if(ptr1==NULL)
        {
            printf("Unable to open a file");
        }
        else
        {
            printf("Enter your roll number ");
            scanf("%d",&rn);
            
            while(fread(&s,sizeof(s),1,ptr1)!=NULL)
            {
                if(rn==s.rno)
                {
                    printf("Enter your Name ");
                    scanf("%s",s.na);
                    fflush(stdin);
                    printf("Enter your Standard ");
                    scanf("%d",&s.std);
                    fflush(stdin);
                    printf("Enter your Division ");
                    scanf("%c",&s.div);
                    fflush(stdin);
                    printf("Enter your address ");
                    scanf("%s",s.ad);
                    fflush(stdin);
                    printf("Enter your date of birth ");
                    scanf("%s",s.dob);
                    fflush(stdin);
                    printf("Enter your Science, Maths & Computer Marks ");
                    scanf("%f%f%f",&s.sci,&s.mat,&s.com);
                    fflush(stdin);
                   
                }
                
                fwrite(&s,sizeof(s),1,ptr2);
               
            }
            printf("Updated\n");
            fclose(ptr1);
            fclose(ptr2);
            remove("Student.dat");
            rename("Temp.dat","Student.dat");
        }
    return 0;
}

int sortmenu()
{
    int ch;
    do
    {
        printf("SORT MENU\n");
        printf("1)By standard\n");
        printf("2)By standard & division\n");
        printf("3)By standard & name\n");
        printf("4)By standard & marks\n");
        printf("5)Back\n");
        printf("ENTER CHOICE:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               sortstuddetails();
                break;
            case 2:
                sortstudstddiv();
                break;
            case 3:
                sortstudstdna();
                break;
            case 4:
                sortstudstdmarks();
                break;
            case 5:
                break;
           
        }
    }while(ch!=5);
    return 0;
}
void studmenu()
{
    int ch;
    do
    {
        printf("STUDENT MENU\n");
        printf("1)New Student\n");
        printf("2)Edit Student\n");
        printf("3)View Student\n");
        printf("4)Search Student\n");
        printf("5)Sort Student\n");
        printf("6)Delete Student\n");
        printf("7)Back\n");
        printf("ENTER CHOICE:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                newstud();
                break;
            case 2:
               editstud();
                break;
            case 3:
                viewallstud();
                break;
            case 4:
                searchmenu();
                break;
            case 5:
                sortmenu();
                break;
            case 6:{
                int n;
                printf("Enter roll number to be deleted");
                scanf("%d",&n);
            delete(n);
            break;
                
            }
             
        }
    }while(ch!=7);
   
}
int reportmenu()
{
    
    int ch;
    do
    {
        printf("REPORT MENU\n");
        printf("1)By standard\n");
        printf("2)By standard & division\n");
        printf("3)By total marks\n");
        printf("4)By address\n");
        printf("5)By year of birth\n");
        printf("6)Back\n");
        printf("ENTER CHOICE:\n");
        scanf("%d",&ch);
        int n;
        char ad[26];
        
        switch(ch)
        {
            case 1:
            {
                viewallstud();
                printf("Enter the standard ");
                scanf("%d",&n);
               reportstd(n);
                break;}
            case 2:
            {
                viewallstud();
                char dv;
                printf("Enter the standard\n");
                scanf("%d",&n);
                fflush(stdin);
                printf("Enter the division\n");
                scanf("%c",&dv);
                
                reportstdiv(n,dv);
                break;
            }
            case 3:{
                viewallstud();
                float k;
                printf("Enter the average marks ");
                scanf("%f",&k);
          reporttm(k);
            break;
        }
                break;
            case 4:{
                viewallstud();
                printf("Enter the address ");
                scanf("%s",ad);
               reportad(ad);
                break;}
                break;
            case 5:
            {
                viewallstud();
                char db[26];
                printf("Enter the date of birth ");
                scanf("%s",db);
                reportdob(db);
                break;
            }
           
          
        }
    }  while(ch!=6);
    return 0;
}
int mainmenu()
{
    int ch;
    do
    {
    printf("MAIN MENU\n");
    printf("1)Student\n");
    printf("2)REPORT\n");
    printf("3)EXIT\n");
    printf("ENTER CHOICE:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            studmenu();
            break;
        case 2:
            reportmenu();
            break;
        default:
            break;
    }
    }while(ch!=3);
    return 0;
}

int main()
{
  
    mainmenu();
    return 0;
}
