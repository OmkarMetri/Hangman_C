#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void showHangman(int);
char *randline(void)
{

FILE *fp;
fp=fopen("countries.txt", "r");
time_t t;
srand((unsigned)time(&t));
int ran=rand()%29;

char *buff;
buff=(char*)malloc(100);
int i;
for(i=0; i<ran; i++)
fgets(buff,50, fp);

fgets(buff, 50, fp);
return buff;
}

int main()
{
char *tempWord;
tempWord=(char*)malloc(100);
char *hangmanWord;
hangmanWord=(char*)malloc(100);
    char hangmanOutput[100];
    int wrongTry = 6 , matchFound = 0;
    int counter = 0 , position = 0, length , i;
    char alphabetFromUser;
int abc=0;

strcpy(hangmanWord,randline());

length = strlen(hangmanWord)-1;
    system("clear");

    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");
    printf("\n\n You will get 5 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");

    getchar();

    printf("\n\n\tHIT >>ENTER<< ");
 getchar();

    system("clear");
        printf("\n\t||===== ");
	printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);
    for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);

    }
    while(wrongTry != 0)
    {
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);

	    scanf("%c",&alphabetFromUser);
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z')
    {
        system("clear");
        printf("\n\n\t Wrong input TRY AGAIN ");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)    	    {
		    if(alphabetFromUser==hangmanWord[counter])
		     {
		       matchFound = 1;
                     }
            }

	   if(matchFound == 0)
	    {
     	      printf("\n\t :( You have %d tries left ",--wrongTry);
	          getchar();
              showHangman(wrongTry);
    getchar();
	    }

	   else
	   {
	     for(counter = 0; counter < length; counter++)
             {
     	         matchFound = 0;
                 if(alphabetFromUser == hangmanWord[counter])
	          {
     		     position = counter ;
     		     matchFound = 1;
	          }//end of if
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          hangmanOutput[i] = alphabetFromUser;
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z' )
                      {
                          continue;
                  	  }

                      else
                      {
                          hangmanOutput[i] = '_';
                      }
}
                tempWord[position] = alphabetFromUser;
                tempWord[length] = '\0';
                int winner = strcmp(hangmanOutput,hangmanWord);


                if(winner==0)
                {
                    printf("\n\n\t \t You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s \n",hangmanWord);exit(0);
                }
	       }
	    }
      }
     }

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanOutput[i]);
      }

    getchar();
    }

      if(wrongTry <= 0)
      {
          printf("\n\n\t The Word was %s ",hangmanWord);
          printf("\n\n\t The man is dead!!!!!");
	      printf("\n\n\t Better luck next time!!!\n");
exit(0);

      }

return 0;
}



void showHangman(int choice)
 {

     switch(choice)
     {

     case 0:
         system("clear");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 1:
         system("clear");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:
         system("clear");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:
         system("clear");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 4:
         system("clear");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 5:
         system("clear");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }

 }
