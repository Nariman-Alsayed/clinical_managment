#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned char u8_t;
typedef signed char s8_t;	
typedef unsigned short u16_t;
typedef signed short s16_t;
typedef unsigned long u32_t;
typedef signed long s32_t;
typedef float f32_t;
typedef  double f64_t;

typedef struct Mystruct new_patient_t;

struct Mystruct
{
	u8_t patient_Name[30];
	u16_t patient_Age;
	u8_t patient_Gender[30];
	u16_t patient_ID;
	new_patient_t *next_ptr;
};

u8_t name[30];
u8_t gender[30];
u32_t age , id , flag = 0 , no_patient=0 , id_test , x ,time_reservation , ID_reservation ,i , id_cancel;
u32_t arr[5]={-1,-1,-1,-1,-1};
new_patient_t *head_ptr;
new_patient_t *last_ptr;
new_patient_t *current_ptr;

void add_patient(u8_t N[] , u32_t A , u8_t G[] , u32_t I);
void Edit_List(u32_t id);
void Time_Reservation() ;
void Cancel_Res(u32_t ID);
void Print_List(u32_t id);
void Print_Res();

int main(void)
{  
    u32_t number_entered , password_entered , number_features_entered ,i=1 , j=0;
	printf("Enter 1 for admin mode (or) enter 2 for user mode \n");
	scanf("%d", &number_entered);
	if(number_entered == 1)
	{
		printf("\t\t\t******** Admin Mode ********\n\n");
		printf("Please enter the password \n");
		while(i<4)
		{
			scanf("%d", &password_entered);
		    if( password_entered != 1234 && i<3)
				printf("Please try again\n");
			
			else if( password_entered != 1234 && i==3)
				printf("In correct password \n");
			else
			{
				printf("Thank you \n");
		        break;
			}
			i++;	
		}
		while(1)
		{
			printf("To add new patient record enter 1\n");
		    printf("To edit patient record enter 2\n");
		    printf("To reserve a slot with doctor enter 3\n");
		    printf("To calcel reservation enter 4\n");
		    printf("Your choice: ");
	        scanf("%d", &number_features_entered);
		
		   if(number_features_entered == 1)
		   {
			    printf("Please Enter your Name :\n");
				scanf(" %[^\n]%*c",name);
			    printf("Please Enter Age :\n");
			    scanf("%d", &age);
			    printf("Are you male or female :\n");
				scanf(" %[^\n]%*c",gender);
			    printf("Please Enter your ID :\n");
			    scanf("%d", &id);
		        add_patient(name , age , gender , id);
		   }
		   else if(number_features_entered == 2)
		   {
			    printf("Enter your ID :\n");
				scanf("%d", &id_test);
				Edit_List(id_test);	
		   }
		   else if(number_features_entered == 3)
		   {
			   Time_Reservation();
		   }
		   else if(number_features_entered == 4)
		   {
			   printf("Enter your ID :\n");
			   scanf("%d", &id_cancel);
			   Cancel_Res(id_cancel);
		   }
		   else
		   {
			  printf("Invalid Choice please try again\n");   
		   }
			
		}
		
		
		
		
	}

	else if(number_entered == 2)
	{
		printf("\t\t\t******** User Mode ********\n\n");
		printf("For Patient record press 1\n");
		printf("For today's reservation press 2\n");
		printf("Your choice: ");
		scanf("%d",&number_features_entered);
		switch (number_features_entered)
		{
			case 1 : printf("Enter Your ID: ");
					 scanf("%d",&id);
					 printf("\t\t\t********** Patient Record **********\n\n");
					 Print_List(id);
					 break;
			case 2 : printf("\t\t\t****** Today's Reservation ******\n\n ");
					Print_Res();
					break;
			default: printf("Invalid Choice please try again\n"); break;
		}
	}
	
	else 
		printf("Wrong entry\n");
	}
	}

    return 0;	
}

void add_patient(u8_t N[30] , u32_t A , u8_t G[30] , u32_t I)
{
	no_patient++;
	new_patient_t*fresh_node_ptr = (new_patient_t*)malloc( 1 * sizeof( new_patient_t));
	strcpy(fresh_node_ptr -> patient_Name,N);
	//fresh_node_ptr -> patient_Name[30] = N[30];
	fresh_node_ptr -> patient_Age = A;
	strcpy(fresh_node_ptr -> patient_Gender,G);
	//fresh_node_ptr -> patient_Gender[30] = G[30];
	fresh_node_ptr -> patient_ID = I;
	fresh_node_ptr -> next_ptr = NULL;
	printf("Patient is added successfully \n\n\n");
	
	if(flag==0)
	{
		head_ptr = fresh_node_ptr;
		last_ptr = fresh_node_ptr;
		
		flag++;	
	}
	else
	{
		last_ptr -> next_ptr = fresh_node_ptr;
		last_ptr = fresh_node_ptr;
			
	}
	return;
}

void Edit_List(u32_t id)
{
	
	current_ptr = head_ptr;
	x=0;
    while(current_ptr != NULL && x==0)
    {
					
		if(id == current_ptr -> patient_ID)
	    {
			printf("Enter Your edit name :\n");
			scanf(" %[^\n]%*c",current_ptr->patient_Name);
			//stpcpy(current_ptr->patient_Name ,name );
			printf("Enter Your edit age\n");
			scanf("%d",&current_ptr->patient_Age);
			//current_ptr->patient_Age = age;
			printf("Enter Your edit gender \n");
			scanf(" %[^\n]%*c",& current_ptr->patient_Gender);
			//stpcpy(current_ptr->patient_Gender ,gender);
			printf("Enter Your edit id\n");
			scanf("%d",& current_ptr-> patient_ID);	
			x=1;
			return;
		}
		current_ptr = current_ptr -> patient_ID;
	}
	if(x ==0)
	{
	    printf("ID is incorrect :\n");
	}
	return;
}

void Time_Reservation() 
{	 x=0;
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0]!=-1) break;
						else printf("From 2pm to 2:30pm available, to reserve this slot please press 1\n"); break;
			case 1 : if(arr[1]!=-1) break;
						else printf("From 2:30pm to 3pm available, to reserve this slot please press 2\n"); break;		
			case 2 : if(arr[2]!=-1) break;
						else printf("From 3:30pm to 4pm available, to reserve this slot please press 3\n"); break;
			case 3 : if(arr[3]!=-1) break;
						else printf("From 4pm to 4:30pm available, to reserve this slot please press 4\n"); break;
			case 4 : if(arr[4]!=-1) break;
						else printf("From 4:30pm to 5pm available, to reserve this slot please press 5\n"); break;						
		}
	}
	printf("Your choice: ");
	scanf("%d",&time_reservation);
	printf("Please Enter your ID: ");
	scanf("%d",&ID_reservation);
	current_ptr = head_ptr;
   while(current_ptr != NULL)
   {
      if(current_ptr->patient_ID == ID_reservation)
      {
        arr[time_reservation-1]=ID_reservation;
		x=1;
        return;
      }
      current_ptr = current_ptr->next_ptr;
   }
   if (x==0)
	   printf("This ID is not exist, please sign up first\n");
		return;
}

void Cancel_Res(u32_t ID)
{
	u8_t y=0;
	for(i=0;i<5;i++)
	{
			if(arr[i]==ID)
			{
				arr[i]=-1;
				y=1;
			}
    }
	if(y==0)
	{
		printf("Wrong ID\n");
	}
	return;
}

void Print_List(u32_t id)
{	u8_t x=0;
    current_ptr=head_ptr;
   while(current_ptr != NULL)
   {
      if(current_ptr->patient_ID == id)
      {
		printf("Name: ");
        printf(current_ptr->patient_Name);
	    printf("\n");
	    printf("Age: %d\n",current_ptr->patient_Age);
	    printf("Gender: ");
	    printf(current_ptr->patient_Gender);
	    printf("\n");
	    printf("ID: %d\n",current_ptr->patient_ID);
	  x=1;
	  }
      current_ptr = current_ptr->next_ptr;
   }
   if(x==0)
   printf("This ID is not exist");
   return;
}

void Print_Res()
{
	
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0]==-1) break;
						else printf("From 2pm to 2:30pm is reserved by the ID Num: %d\n",arr[0]); break;
			case 1 : if(arr[1]==-1) break;
						else printf("From 2:30pm to 3pm is reserved by the ID Num: %d\n",arr[1]); break;		
			case 2 : if(arr[2]==-1) break;
						else printf("From 3:30pm to 4pm is reserved by the ID Num: %d\n",arr[2]); break;
			case 3 : if(arr[3]==-1) break;
						else printf("From 4pm to 4:30pm is reserved by the ID Num: %d\n",arr[3]); break;
			case 4 : if(arr[4]==-1) break;
						else printf("From 4:30pm to 5pm is reserved by the ID Num: %d\n",arr[4]); break;						
		}
	}
	return;
}