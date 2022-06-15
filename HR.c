#include<stdio.h>
#include<stdlib.h>

void addEmployees();
void listEmployees();
void Modify();
void Delete();
void salary_report();
void employeeAttendanceMarking();
void employeeAttendanceReport();
void empjob();

struct employees
    {
        int id;
        char name[20];
        char adders[50];
        char mobile_number[12];
        char birth_day[20];
        int salary;
        char daily_work[50];

    }employee[100];

struct attendance
	{
	char empId[10];
	char date[10];
	char name[20];
	char att[2];

	}atten;


int main(){

    int Option;

    do{

    printf("---------------------------------------------------------------\n\n");
    printf(" **** Human Resource Management System ****\n\n");

    printf("\t\t  Main Menu\n");
    printf("\t\t-------------\n\n");

    printf("\t[1]  Register New Employee's\n");
    printf("\t[2]  List Employee's Record\n");
    printf("\t[3]  Modify Employee's Record\n");
    printf("\t[4]  Delete Employee's Record\n");
    printf("\t[5]  Employee's Salary Report\n");
    printf("\t[6]  Employee's Attendance Marking\n");
    printf("\t[7]  Employee's Attendance Report\n");
    printf("\t[8]  Assign Job Roles\n");
    printf("\t[9]  Exit\n\n");

    printf(" Select your Option : ");
    scanf("%d",&Option);

    printf("\n---------------------------------------------------------------\n");

    switch(Option)
    {
        case 1:
            addEmployees();
            break;

        case 2:
            listEmployees();
            break;

        case 3:
            Modify();
            break;

        case 4:
            Delete();
            break;

        case 5:
            salary_report();
            break;

        case 6:
        	employeeAttendanceMarking();
        	break;

        case 7:
            employeeAttendanceReport();
            break;

        case 8:
            empjob();
            break;

        case 9:
            exit(1);

        default:
            printf("\nError!..Select given options above...\n\n");
    }

    } while (1);

    return 0;
}



void addEmployees(){

    char op;
    int i=0,x=0,k;

    printf("\n\t\t-----------------------------\n");
    printf("\t\t|  Register New Employee's  |\n");
    printf("\t\t-----------------------------\n\n");

    do
    {
        printf("\n----------------------------\n");

        printf("\n Enter Details of Employee [%d]\n\n", i+1);

        int j;
        printf(" Enter Employee Id(100x): ");
        scanf("%d", &j);
//        k=j%1000;
        employee[i].id = j;

        printf(" Enter Name: ");
        scanf("%s", employee[i].name);

        printf(" Enter Address: ");
        scanf("%s", employee[i].adders);

        printf(" Enter Mobile Number: ");
        scanf("%s", employee[i].mobile_number);

        printf(" Enter Birth day(YYYY.MM.DD):");
        scanf("%s", employee[i].birth_day);

        printf(" Enter Basic Sallery: ");
        scanf("%d", &employee[i].salary);

        printf("\n----------------------------\nContinue Y/N: ");
        scanf(" %c",&op);

        i++;

    }while(op=='y');


    FILE *fp;
    fp = fopen("data.txt","w");

    if(fp == NULL)
        printf("Cannot create file\n");
    else

    for(x=0;x<i;x++){
        fprintf(fp,"%d\t%s\t%s\t%s\t%s\t%d\n",employee[x].id,employee[x].name,employee[x].adders,employee[x].mobile_number,employee[x].birth_day,employee[x].salary);
    }

    fclose(fp);
}

void listEmployees(){

    char op;
    int i=0,x=0,k;

    printf("\n\n\t\t\t\t\t----------------------------\n");
    printf("\t\t\t\t\t|  List Employee's Record  |\n");
    printf("\t\t\t\t\t----------------------------\n\n");

    do{

    printf("\n -----------------------------------------------------------------------------------------------------------------------\n");

    while(i<100)
    {
        printf("\tID                 : %d\n\tEmployee Name      : %s\n\tAddress            : %s\n\tMobile Number      : %s\n\tBirth Day          : %s\n\tBasic Sallery (Rs) : %d\n\n",employee[x].id,employee[x].name,employee[x].adders,employee[x].mobile_number,employee[x].birth_day,employee[x].salary);
        i++;
        x++;
        if (employee[i].id==0){
            break;
        }
    }

    printf("\n\n---------------------\nClose to press Q: ");
    scanf(" %c",&op);

    }while(op!='q');



}


void Modify(){

    printf("\n\t\t------------------------------\n");
    printf("\t\t|  Modify Employee's Record  |\n");
    printf("\t\t------------------------------\n\n");

    int accNum,i=0,Option;

    printf("Enter Employee ID : ");
    scanf("%d",&accNum);

    while(i<100){
        if(accNum==employee[i].id){

            printf("\n\t[1]  Name\n");
            printf("\t[2]  Adders\n");
            printf("\t[3]  Mobile Number\n");
            printf("\t[4]  exit\n\n");

            printf(" Select your Option : ");
            scanf("%d",&Option);

            do{
                if(Option==1){
                    printf(" Enter your new Name : ");
                    scanf("%s",employee[i].name);

                }
                else if(Option==2){
                    printf(" Enter your new Adders : ");
                    scanf("%s",employee[i].adders);

                }
                else if(Option==3){
                    printf(" Enter your new Mobile Number : ");
                    scanf("%s",employee[i].mobile_number);

                }
                printf("\n Select your Option : ");
                scanf("%d",&Option);

            }while(Option!=4);
            break;

        }
        else{
            i++;
        }
    }
    if(i==100){
        printf("\n***Invalid ID number. Please enter correct ID***\n\n");
        Modify();
    }
}


void Delete(){

    printf("\n\t\t------------------------------\n");
    printf("\t\t|       Delete Employee      |\n");
    printf("\t\t------------------------------\n\n");

    int accNum,i=0,Option;

    printf("Enter Employee ID : ");
    scanf("%d",&accNum);
    int j=0;
    char c='0';
    while(i<100){
        if(accNum==employee[i].id){

            employee[i].id=j;
            employee[i].name[20]=c;
            employee[i].adders[50]=c;
            employee[i].mobile_number[12]=c;
            employee[i].birth_day[20]=c;
            employee[i].salary=j;


            break;
        }
        else{
            i++;
        }
    }
    if(i==100){
        printf("\n***Invalid ID number. Please enter correct ID***\n\n");
        Delete();
    }
}

void employeeAttendanceMarking(){

	char op;

    printf("\n\t\t----------------------------------------\n");
    printf("\t\t|       Employee Attendance Marking    |\n");
    printf("\t\t----------------------------------------\n\n");


    FILE*fi;
	fi=fopen("att.txt","w");

	if(fi == NULL){
			printf("Cannot create file\n");
		}
		printf("Enter date (dd/mm/yy): ");
    	scanf("%s",atten.date);
		fprintf(fi,"Date: %s\n\n",atten.date);
//		fprintf(fi,"------------------------------\n");
//		fprintf(fi,"EMP_ID\tName\tAttendance\n");
//		fprintf(fi,"------------------------------\n");
	do{
		printf("---------------------------\n");
		printf("Employee ID: ");
		scanf("%s",atten.empId);
		printf("Enter name: ");
		scanf("%s",atten.name);
		printf("Enter Attendance(Pr/Ab): ");
		scanf("%s",atten.att);
		printf("\n\nContinue ? Y/N : ");
		scanf(" %c",&op);
		fprintf(fi,"Employee ID   : %s\nEmployee Name :%s\nAttendance    :%s\n\n\n",atten.empId,atten.name,atten.att);

		}
	while(op=='y');

	fclose(fi);
}

void employeeAttendanceReport(){

    char op;

    do
    {
    printf("\n\t\t----------------------------------------\n");
    printf("\t\t|       Employee Attendance Report     |\n");
    printf("\t\t----------------------------------------\n\n");

	FILE *fp;
	char ch[500];
	fp=fopen("att.txt","r+");

	if(fp == NULL){
			printf("Cannot open the file\n");
		}
		else{
			fscanf(fp,"Date: %s\n\n",atten.date);
			printf("\nDate:%s\n\n",atten.date);
			while(fgets(ch,500,fp)!=NULL){
			printf("\t %s",ch);
		}
		}
		fclose(fp);

    printf("\n\n----------------------------\nClose to press Q: ");
    scanf(" %c",&op);
    }while(op!='q');
}

void empjob(){

    printf("\n\t\t---------------------------\n");
    printf("\t\t|       AssignJobRoles    |\n");
    printf("\t\t--------------------------\n\n");

	char op;
    int i=0,x=0,k,id,j,m=0,n=0;

	do{


    printf("ID\tName\tAddress\n\n");

    while(i<100)
    {
        printf("%d\t%s\t%s\n\n\n",employee[x].id,employee[x].name,employee[x].adders);
        i++;
        x++;
        if (employee[i].id==0){
            break;
        }
    }

	printf("-----------------------------------------------------\n\n");
	printf("Enter Employeer ID You Want select  - ");
	scanf("%d",&id);

	printf("\n\n-----------------------------------------------------\n");
	printf("Enter employeer position in these list\n");
	printf("-----------------------------------------------------\n");
	printf("    -Business Analist - BA\n");
	printf("    -Computer Service Technition - CST\n");
	printf("    -Cyber Security Specialist - CSS \n");
	printf("    -Data Analyst - DA \n");
	printf("    -Data Centre Technician - DCT \n");
	printf("    -Database Administrator - DBA \n");
	printf("------------------------------------------------------\n\n");

//	cfPtr = fopen("data.txt","a");

	for(j=0;j<100;j++){


	if(employee[j].id==id){


		printf("Enter %s 's potition - ",employee[j].name);
		scanf("%s",employee[j].daily_work);
		//fprintf(cfPtr,"%s",employee[j].daily_work);
		//fclose(cfPtr);
		//printf("\n\n Sucessfull !! %s was appointed as the %s \n\n\n ",employee[j].name,employee[j].daily_work);
		break;
	}



	}

	 printf("ID\tName\tAddress\tPosition\n\n");

 while(m<100)
    {
        printf("%d\t%s\t%s\t%s\n\n\n",employee[j].id,employee[j].name,employee[j].adders,employee[j].daily_work);
        m++;
        j++;
        if (employee[j].id==0){
            break;
        }
    }


	printf("\n\n----------------------------\nClose to press Q: ");
    scanf(" %c",&op);

    }
	while(op!='q');
}

void salary_report()
{
    printf("\n\t\t-------------------------------------\n");
    printf("\t\t|       Employee's Salary Report    |\n");
    printf("\t\t-------------------------------------\n\n");

	FILE *cfptr;
	cfptr = fopen("data.txt","r");
	char op;
	int insurance=2000;
	int net_salary;
	int i=0;

    do{
	while(i<100)
	{
		net_salary=employee[i].salary-insurance;
		printf("\tID                 : %d\n\tEmployee Name      : %s\n\tMobile Number      : %s\n\tBasic Sallery (Rs) : %d\n\tInsurance fee (Rs) : %d\n\tNet Salary    (Rs) : %d\n\n",employee[i].id,employee[i].name,employee[i].mobile_number,employee[i].salary,insurance,net_salary);
		i++;
		if(employee[i].id==0)
		{
			break;
		}
	}
	printf("\n\n----------------------------\nClose to press Q: ");
    scanf(" %c",&op);
    }while(op!='q');
}
