//PROJECT-1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char nameofdisease[6][20]={"COVID19","PNEUMONIA","COMMON COLD","FLU","ALLERGY","NO DISEASE"};
char str1[20]="NO DISEASE";
struct disease 
{
	int s[16];

};

struct disease arrayofdisease[]={{1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0},{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,1},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0},{0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};



void swap(char *, char *, int);
void main()

{
	FILE *fptr;
	fptr=fopen("Digitaldiagnosis.txt","w");

	if(fptr==NULL)
	{
		printf("CANNOT OPEN FILE");
		exit(1);
	}
	
	int symptomsans[20],temp,temp1,n,value;
	
	fprintf(fptr,"!!!!REPORT!!!!\n");
			
	printf("\n\nTHIS IS a DISEASE DIAGNOSIS PLATFORM\nPLEASE ENTER 1 FOR YES AND 0 FOR NO.\n\n");

	printf("Do you have fever?\n");
	scanf("%d",&symptomsans[0]);

	printf("Is your cough dry?\n");
	scanf("%d",&symptomsans[1]);

	printf("Do you lack taste or smell?\n");
	scanf("%d",&symptomsans[2]);

	printf("Do you have  body aches?\n");
	scanf("%d",&symptomsans[3]);

	printf("Do you have blood in mucus or have yellowish green mucus?\n");
	scanf("%d",&symptomsans[4]);

	printf("Do you have difficulty in breathing?\n");
	scanf("%d",&symptomsans[5]);

	printf("Do you generally sweat and shiver?\n");
	scanf("%d",&symptomsans[6]);

	printf("Does you chest have a sharp or stabbing pain?\n");
	scanf("%d",&symptomsans[7]);

	printf("Does your body itch?\n");
	scanf("%d",&symptomsans[8]);

	printf("Do you have nausea or vomiting?\n");
	scanf("%d",&symptomsans[9]);

	printf("Is sneezing common?\n");
	scanf("%d",&symptomsans[10]);

	printf("Do you have diarrhoea?\n");
	scanf("%d",&symptomsans[11]);

	printf("Do you have a pink eye?\n");
	scanf("%d",&symptomsans[12]);

	printf("Do you have rashes on your body?\n");
	scanf("%d",&symptomsans[13]);

	printf("Is your throat sore?\n");
	scanf("%d",&symptomsans[14]);

	printf("Do you feel sleepy all the time?\n");
	scanf("%d",&symptomsans[15]);

	system("clear");

	int RSS[6];

	for(int i=0;i<6;i++){

		int raw=0;


		for(int j=0;j<16;j++)
		{
			raw += pow((symptomsans[j]-arrayofdisease[i].s[j]),2);

		}
		RSS[i] = raw;


	}

	fprintf(fptr,"DISEASE PROBABILITY:\n");

	printf("DISEASE PROBABILITY:\n");
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			if(RSS[i]>RSS[j]){
				temp=RSS[i];
				RSS[i]=RSS[j];
				RSS[j]=temp;

				swap(nameofdisease[i],nameofdisease[j],n);

			}


		}
		if(i<2){
			int percent = 100 - RSS[i];

			value=strcmp(nameofdisease[0],str1);

			if(value==0)
			{
				fprintf(fptr,"%s - %d %%\n",nameofdisease[0],percent);
				printf("%s - %d %%\n",nameofdisease[0],percent);
				break;	
			}
			else
			{	
				fprintf(fptr,"%s - %d %%\n",nameofdisease[i],percent);
				printf("%s - %d %%\n",nameofdisease[i],percent);
			}
		}


	}


	fclose(fptr);
}

void swap( char *nameofdisease1,  char *nameofdisease2, int n  )
{
	char temp1[n];

	strcpy( temp1, nameofdisease1 );
	strcpy( nameofdisease1, nameofdisease2 );
	strcpy( nameofdisease2, temp1 );
}


