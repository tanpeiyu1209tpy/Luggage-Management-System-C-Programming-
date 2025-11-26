#include <stdio.h>
#include <string.h>

#define MAX_LUGGAGE 10

struct luggage
{
  char name[50];
  char booking_number[10];
  float weight;
  char flight_time[10];
};

struct luggage luggage[MAX_LUGGAGE];

void add_fun(struct luggage *p);
void edit_fun(struct luggage *p);
void remove_fun(struct luggage *p);
void list_fun(struct luggage *p);

int main(){
  
  int num_luggage;
  
  // Loop until the user decides to quit
  while (1) {
    printf("\n*****WELCOME TO X AIRLINES*****\n");
    printf("1. Check in luggage\n");
    printf("2. View luggage details\n");
    printf("3. Edit the record\n");
    printf("4. Remove the record\n");
    printf("5. Quit\n");
    
    printf("Please enter your choice: ");
    
    //Choose what you want to do
    int choice, choice1;
    scanf("%d", &choice);

    if (choice == 1) 
    {
      //1. Check in luggage
      printf("\nPlease enter number of luggage that you want to add.\n");
      scanf("%d",&num_luggage);
      num_luggage--;
      add_fun(&luggage[num_luggage]);  
    } 
    
    else if (choice == 2) 
    {
      //2. View luggage details
      for (int i = 0; i < MAX_LUGGAGE+1; i++) 
      {
        printf("\n***Luggage %d***:\n", i + 1);
        list_fun(&luggage[i]); 
      }
    } 

    else if (choice ==3)
    {
      //3. Edit luggage messages
      printf("Please enter number of luggage that you want to edit.\n");
      scanf("%d",&num_luggage);
      num_luggage--;
      edit_fun(&luggage[num_luggage]);
    }
      
    else if(choice ==4)
    {
      //4. Remove luggage messages
      printf("Please enter number of luggage that you want to remove.\n");
      scanf("%d",&num_luggage);
      num_luggage--;
      remove_fun(&luggage[num_luggage]);
    }
      
    else if (choice == 5)
    {
      //6. Quit
      printf("\n*****Wishing you a happy journey! THANK YOU!*****");
      break;
    } 
    
    else 
    {
      // another choice
      printf("\n*****Invalid choice. Please enter again.*****\n\n");
    }
  }
}

//the part of function

//add_function (function 1)
void add_fun(struct luggage *p)
{
    printf("\n\nCustomer name: ");
    scanf("%s", p->name);

    printf("\nBooking number: ");
    scanf("%s", p->booking_number);

    printf("\nWeight of the luggage (in kg): ");
    scanf("%f", &p->weight);

    printf("\nFlight time: ");
    scanf("%s", p->flight_time);        
}

//edit function (function 2)
void edit_fun(struct luggage *p)
{
  printf("\n\nCustomer name: ");
  scanf("%s", p->name);
  
  printf("\nBooking number: ");
  scanf("%s", p->booking_number);
    
  printf("\nWeight of luggage (in kg): ");
  scanf("%f", &p->weight);
    
  printf("\nFlight time: ");
  scanf("%s", p->flight_time);   
}

//remove_function (function 3)
void remove_fun(struct luggage *p)
{
  memset(p->name,0,sizeof(p->name));
  memset(p->booking_number,0,sizeof(p->booking_number));
  p->weight=0;
  memset(p->flight_time,0,sizeof(p->flight_time));
}

//list function (function 4)
void list_fun(struct luggage *p)
{
  printf("\n  Customer name: %s\n", p->name);
  printf("  Booking number: %s\n", p->booking_number);
  printf("  Weight: %f kg\n", p->weight);
  printf("  Flight time: %s\n", p->flight_time);
  
  //Determine whether to add money
    if( p -> weight<=20)
    {
      printf("\n  Passengers do not need to pay for any money when the weight is less than 20 kg.");
      printf("\n  Cost: RM 0 \n");
    }

    else if( p -> weight <=30)
    {
      printf("\n  Passengers need to pay RM12.5 for each extra kilos after 20kg");
      printf("\n  Cost: RM %f\n", (p -> weight-20)*12.5);
    }
    else{
      printf("\n  Passengers need to pay RM12.5 for each extra kilos after 20kg and RM21.4 for each extra kilos after 30kg");
      printf("\n  Cost: RM %f\n", (p -> weight-30)*21.4 + 10*12.5);
    }
}
