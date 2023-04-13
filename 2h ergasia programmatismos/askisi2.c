#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
	/** den exw xrhsimopoihsei thn strcpy alla katalava pou tha mporousa ,sto programma auto ,na thn balw .omws logw xronou 
		to afhnw etsi kai gia na mhn xalasw thn apotelesmatikothta tou programmatos**/
	
	int mem[9][4];
	int i ,j ;
	int R1[4];
	int R2[4];
	int address;

	void boot()

{
	for (i=0;i<4;i++)
	{
		R1[i]=rand()%2;
		if (R1[i]<0){
			R1[i]=-R1[i];
		}
		R2[i]=rand()%2;
		if (R2[i]<0)
			R2[i]=-R2[i];
	}
	
	for (i=0;i<=9;i++)
	{
		for (j=0;j<4;j++)
		{
			mem[i][j]= rand()%2;
			if (mem[i][j]<0)
				mem[i][j]=-mem[i][j];
			
		}
	} 
}
int loadR1(int address)
{
	

	if (address>=0 && address<=9){

		 i=address;
		 for(j=0;j<4;j++){
		 	R1[j]=mem[address][j];
	   }
	   return 1;

		} 
		else
			return 0;
}


int loadR2(int address)
{

	if (address>=0 && address<=9){

		 i=address;
		 for(j=0;j<4;j++){
		 	R2[j]=mem[address][j];
	   }
	   return 1;

		} 
		else
			return 0;
}

int storeR1(int address)
{
	if (address>=0 && address<=9)
	{
		 
		 for(j=0;j<4;j++)
		 	{
		 	mem[address][j]=R1[j];
			}
				
		return 1;
	}
		else return 0;
}

int storeR2(int address)
{
	if (address>=0 && address<=9)
	{
		
		 for(j=0;j<4;j++)
		 	{
		 	mem[address][j]=R2[j];
			}
				
		return 1;
	}
		else return 0;

}

void addRegistersR1()
{
	int count=0;
		
		for(i=0;i<4;i++)
		{
		if(R1[i]==1) count=2*count+1;
		else count = 2 * count;
		}

		int count1=0;
		

		for(i=0;i<4;i++)
		{
		if(R2[i]==1) count1=2*count1+1;
		else count1 = 2 * count1;
		}

		int sum=0;
		sum=count+count1;

		if (sum<=15)
    	{

        for(i=0;i<4;i++){
        R1[i] = sum % 2;
        sum = sum / 2;
    	}
        
       
      	for(i=0;i<4/2;i++)
			{
				int c1=R1[i];
				int c2=R1[4-i-1];
				R1[i]=c2;
				R1[4-i-1]=c1;
			}
		}
		else 
			{
				for (i=0;i<4;i++)
				{
					R1[i]=0;
				}
			}

}

void addRegistersR2()
{
	int count=0;
		
		for(i=0;i<4;i++)
		{
		if(R1[i]==1) count=2*count+1;
		else count = 2 * count;
		}

		int count1=0;
		

		for(i=0;i<4;i++)
		{
		if(R2[i]==1) count1=2*count1+1;
		else count1 = 2 * count1;
		}

		int sum=0;
		sum=count+count1;

		if (sum<=15)
    	{

        for(i=0;i<4;i++){
        R2[i] = sum % 2;
        sum = sum / 2;
    	}
        
      	for(i=0;i<4/2;i++)
			{
				int c1=R2[i];
				int c2=R2[4-i-1];
				R2[i]=c2;
				R2[4-i-1]=c1;
			}
		}
		else 
			{
				for (i=0;i<4;i++)
				{
					R2[i]=0;
				}
				
			}
}

void subRegistersR1()
{
	int count=0;
		
		for(i=0;i<4;i++)
		{
		if(R1[i]==1) count=2*count+1;
		else count = 2 * count;
		}

		int count1=0;
	
		for(i=0;i<4;i++)
		{
		if(R2[i]==1) count1=2*count1+1;
		else count1 = 2 * count1;
		}

		int sum=0;
		sum=count-count1;
  
        if (sum>=0)
    	{

    	
        for(i=0;i<4;i++){
        R1[i] = sum % 2;
        sum = sum / 2;
    	}
        
       
      	for(i=0;i<4/2;i++)
			{
				int c1=R1[i];
				int c2=R1[4-i-1];
				R1[i]=c2;
				R1[4-i-1]=c1;
			}
		}
		else 
			{
				for (i=0;i<4;i++)
				{
					R1[i]=1;
				}
			}

}
void subRegistersR2()
{
	int count=0;
		
		for(i=0;i<4;i++)
		{
		if(R1[i]==1) count=2*count+1;
		else count = 2 * count;
		}

		int count1=0;

		for(i=0;i<4;i++)
		{
		if(R2[i]==1) count1=2*count1+1;
		else count1 = 2 * count1;
		}

		int sum=0;
		sum=count-count1;
  
        if (sum>=0)
    	{

        for(i=0;i<4;i++){
        R2[i] = sum % 2;
        sum = sum / 2;
    	}
        
       
      	for(i=0;i<4/2;i++)
			{
				int c1=R2[i];
				int c2=R2[4-i-1];
				R2[i]=c2;
				R2[4-i-1]=c1;
			}
		}
		else 
			{
				for (i=0;i<4;i++)
				{
					R2[i]=1;
				}
			}
}

void displayMemory()
{
	for (i=0;i<=9;i++){

		for (j=0;j<4;j++)
		{
			printf("%d", mem[i][j] );
		
		if (j==3){
			printf("\n");
			}
		}
	}
	
}

void displayR1()
{
	for(j=0;j<4;j++){
			printf("%d",R1[j]);
		}
		 printf("\n");
}

 void displayR2()
 {
 	for(j=0;j<4;j++){
			printf("%d",R2[j]);

		}
		printf("\n");
 }


 /** Αυτή η συνάρτηση θα σβήσει το γράμμα από το x στην θέση pos **/ 
void removeCharInPos(char x[],int pos)
{
	int i;
	for(i=pos;i<strlen(x);i++)
	{
		x[i]=x[i+1];
	}
}

/** Αυτή η συνάρτηση θα σβήσει τα κενά που είναι πάνω από ένα
 * συνεχομένα **/ 
void removeSpaces(char x[])
{
  int i;
  
  int spaceFound=1;
  
  while(spaceFound)
  {
	  spaceFound=0;
	for(i=0;i<strlen(x)-1;i++)
	{
	  if(x[i]==' ' && x[i+1]==' ')
	  {
		  removeCharInPos(x,i);
		  spaceFound=1;
		  break;
	  }
	}
  }
}

 int main()
{
	printf("\n");
	printf("Oi epitreptes entoles einai: \n BOOT \n LOAD R N\n STORE R N\n ADD R\n SUB R\n SHOW R\n MEM\n\n Opou R einai R1 h R2 kai N apo 1 ews 10\n");
	printf("\n Tha prepei na kanete run toulaxiston mia fora to BOOT allios den tha gemisoun\n oi theseis mnhmhs kai tha exete anepithimita apotelesmata \n\n");
	printf("DEKTOI EINAI MONO OI KEFALAIOI XARAKTHRES\n");	     
	
	
	do 
	{
	printf("\n");
	char x[100];
	printf("Dose entoli \n");
	gets(x);
	removeSpaces(x);
	char entoli[100];
	char orisma[100];
	char n[100];

	int i,icount=0;
	
	int flag=0;
	int flag1=0;

	/* edw spame to command se entoli meta to R to kanoume save se ena pinaka me onoma orisma 
	* kai meta pairnoume to N kai to vazoume se enan pinaka n gia na to xrhsimopoihsoyme meta san orisma 
	*Omws epeidi einai san char meta pio katw me mia entolh to metatrepoume se integer gia na perasei sta functions kai apothikeuetai se metabliti n1 */
	for(i=0;i<strlen(x);i++)
	{
		if(x[i]!=' ') 
		{
			if(flag==0 )
			entoli[icount++]=x[i];
			else if (flag1==0)
				{
					orisma[icount++]=x[i]; 
					
				}
				else n[icount++]=x[i];
		}
		else
		{
			 if(flag==0)
			 {
			 entoli[icount]='\0';
			 flag=1;
			
			}
			else if (flag1==0) 
			{
				orisma[icount]='\0';
				
				flag1=1;
			}
			else 
			{
				n[icount]='\0';
				
			}
			icount =0;
			
		 }
	}

  if(x[strlen(x)-1]!=' ')
	{
		if(flag==0) 
		{
			entoli[icount]='\0';
		
		}
		else if (flag1==0)
		{
			orisma[icount]='\0';
			
		}
		else 
			n[icount]='\0';
			
	}


	int n1=atol(n);

		if(strcmp(entoli,"BOOT")==0)
		{
			boot();
		}
	 	else if(strcmp(entoli,"LOAD")==0)
		{
			if(strcmp(orisma,"R1")==0)
			{
				if (n1>=1&& n1<=10) /* ME  1-10 kai n1-1 apofeygoume thn periptwsh o xristis na dwsei <<LAOD R1 >> xwris n kai na eisaxthei automata to 0 sti thesi tou n */
				loadR1(n1-1);
				else printf("edoses lathos N \n");
			}
			else if (strcmp(orisma,"R2")==0)
			{
				if (n1>=1&& n1<=10)
				loadR2(n1-1);
				else printf("edoses lathos N \n");
			}
			else printf("Edoses lathos R\n");
		}
		else if (strcmp(entoli,"STORE")==0)
		{
			if (strcmp(orisma,"R1")==0)
			{
				if (n1>=1 && n1<=10)
				storeR1(n1-1);
				else printf("Edoses lathos N\n");
			}
			else if (strcmp(orisma,"R2")==0)
			{	
				if (n1>=1&& n1<=10)
				storeR2(n1-1);
				else printf("Edoses lathos N\n");
			}
			else printf("Edoses lathos R \n");
		}
		else if (strcmp(entoli,"ADD")==0)
		{
			if (strcmp(orisma,"R1")==0)
			{
				addRegistersR1();
			}
			else if (strcmp(orisma,"R2")==0)
			{
				addRegistersR2();
			}
			else printf("Edoses lathos R \n");
		}
		else if (strcmp(entoli,"SUB")==0)
		{
			if (strcmp(orisma,"R1")==0)
			{
				subRegistersR1();			}
			else if (strcmp(orisma,"R2")==0)
			{
				subRegistersR2();
			}
			else printf("Edoses lathos R \n");
		}
		
		else if (strcmp(entoli,"MEM")==0)
		{
			printf("\n");
			displayMemory();
		}
		else if (strcmp(entoli,"SHOW")==0)
		{
			if(strcmp(orisma,"R1")==0)
			{
				printf("\n");
				displayR1();
			}
			else if (strcmp(orisma,"R2")==0)
			{
				printf("\n");
				displayR2();
			}
			else printf("Edoses lathos R\n");
		}
		else 
			{
				printf("\n");
				printf("Edoses lathos entoli\n");
			}
			/* edw kanw reset tou pinakes giati ama px edina load r1 1 kai meta patousa show edeixne to periexomeno tou R1 dioti htan mesa ston pinaka orisma*/
		 	entoli[0]='\0';
			orisma[0]='\0';
		 	n[0]='\0';
}
while(1);
}