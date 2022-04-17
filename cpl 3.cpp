#include <stdio.h>
#include <stdlib.h>



int heapbegin=0;
int Heapsz=19000;
int heapend=Heapsz+heapbegin;
struct Node
{
	
	int sz;
	int  addr;
	struct Node *next;

};

    struct Node*temp1 = NULL;


int Alloc(int sz) {
	
	struct Node* temp=NULL;
	
	if(sz > 0) 
	{
		if(temp1== NULL)
		{
		
			if(sz <= Heapsz) 
			{
				struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
					//assigning a base addres
				ptr1->sz = sz;
				ptr1->addr =heapbegin;
				//intialising values int ptr1
				ptr1->next = NULL;
				
				temp1= ptr1;
				
				temp = temp1;
				
				return temp->addr;
			}
		}
		else 
		{
			struct Node *pres;
		
			
			pres = temp1;
			
		
		
			if(pres->addr != heapbegin)
			{
				
				if( (heapbegin + sz - 1) < pres->addr)
				{
				       
					struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
					//assigning a base addres
					ptr1->addr = heapbegin;
					
					ptr1->sz = sz;
					
					ptr1->next = pres;
					 temp1= ptr1;
					temp = temp1;
					return temp->addr;
					
				}
			}

			
			while(pres->next != NULL)
			{
				if( (pres->addr + pres->sz + sz - 1) < pres->next->addr) 
				{
					struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
					ptr1->addr = pres->addr + pres->sz;
					ptr1->sz = sz;
					ptr1->next = pres->next;
					pres->next = ptr1;
					temp = ptr1;
					return temp->addr ;
				}
				pres = pres->next;
			}
			
		
			if( (pres->addr + pres->sz + sz - 1) <=heapend) 
			{
			    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
			   ptr1->addr= pres->addr + pres->sz;
				ptr1->sz = sz;
				ptr1->next = pres->next;
				pres->next = ptr1;
				temp = ptr1;
				return temp->addr ;
			}
		}
	}
	
	if(temp == NULL) 
	{
		printf(" sry we Can Not allocate any size  for you: %d",sz) ;
		return -1;
	}
	 ;
}

void Free(int add) 
{

	struct Node *pres, *prev;
	pres = temp1, prev = NULL;
	if(temp1->addr == add) 
	{
		temp1= pres->next;
		
	}
    else 
    {
        int check = 0;
        while(pres!= NULL && !check)
        {
            if(pres->addr == add)
            {
                struct Node* temp2;
                temp2 = pres->next;
                prev->next = temp2;
                check =1;
            }
            else
            {
                prev = pres;
                pres= pres->next;
            }
        }
    }
    
    if (pres == NULL)
    {
        printf("Failed to free given memory\n");
    }
}

void display() 
{
	struct Node *pres = temp1;
	printf("After\n");
	while(pres != NULL) 
	{           
		printf("base_add : %d size : %d \n",pres->addr, pres->sz);
		pres = pres->next;
	}
}

int main()
 {
	int memo1 = Alloc(12);

   display();
	int memo2 = Alloc(78);	
display();
	int memo3 = Alloc(298);
	display();
	int memo4 = Alloc(482);	

   printf("free process \n");
	Free(memo3);
						
	display();
	int memo5 = Alloc(200);	
	display();
	printf("free process \n");
	Free(memo1);					
	display();
	int memo6 = Alloc(678);
   display();
	int memo7 = Alloc(149);
	printf("free process \n");
	Free(memo2);						
   display();
   printf("free process \n");
	Free(memo4);					
	display();
	printf("free process \n");
	Free(memo5);					
	display();
	printf("free process \n");
	Free(memo6);					
display();
	return 0;
}
