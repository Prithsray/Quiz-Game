#include<stdio.h>
#include<string.h>

///////// GLOBAL VARIABLE DECLARATION //////////

int score=0,correct_answer=0;


///// STRUCTURE FOR QUESTIONS AND ANSWERS  //////////


struct question
{     
      char q1[100],q2[100],q3[100],q4[100],q5[100];
      
      char a1[100],a2[100],a3[100],a4[100],a5[100];
}q;

struct leaderboard
{
    char name[20];
    int points;
    int correct;
}l;

///////////   FUNCTION FOR INCORRECT OPTION   /////////


int incorrect(char p[],char q[]){
if(strcmp(p,q)!=0 || strcmp(p,q)>0){
     printf("\nINCORRECT !! you get no point\n");
     score=score+0;
 }
return 0;
}


/////////    FUNCTION FOR CORRECT OPTION    /////////////


int correct(char a[],char b[]){
    
if(strcmp(a,b)==0 || strcmp(a,b)== -1){

     printf("\nCORRECT !! you get 5 ponts\n ");
      score=score+5;
      correct_answer=correct_answer+1;
     
 }

 else{
     
     incorrect(a,b);
     
 }
return 0;
}


//////////   MAIN FUCTION    /////////////


int main()
{

      FILE *fp,*fp1;
      char Q[100],A[100];
      int qcount=0,acount=0,maincount=0;


 //////   TAKING INPUT FROM QUESTION SET    ///////


      fp=fopen("question.txt","r");

  char c = getc(fp);
    while (c != EOF)
    {       
        if (c == '\n')
        {
            fgets(Q,sizeof(Q),fp);
            if(qcount==0){
                for(int k=0;k<100;k++)
                q.q1[k]=Q[k];
            //printf("%s",q.q1);
            }
            qcount=qcount+1;
            if(qcount==2){
                for(int i=0;i<100;i++)
                q.q2[i] = Q[i];
             //printf("%s",q.q2);
            }
            if(qcount==3){
                for(int j=0;j<100;j++)
                q.q3[j] = Q[j];
             //printf("%s",q.q3);
            }
            if(qcount==4){
                for(int l=0;l<100;l++)
                q.q4[l] = Q[l];
             //printf("%s",q.q2);
            }
            if(qcount==5){
                for(int m=0;m<100;m++)
                q.q5[m] = Q[m];
             //printf("%s",q.q2);
            }

        }       
        c = getc(fp);
    }
    fclose(fp);


///////    TAKING INPUT FROM ANSWER SET    ////////


    fp1=fopen("answer.txt","r");
      
  char ch = getc(fp1);
    while (ch != EOF)
    {        
        if (ch == '\n')
        {
            fgets(A,sizeof(A),fp1);
            if(acount==0){
                for(int z=0;z<100;z++)
                q.a1[z]=A[z];
            printf("%s",q.a1);
            }
            acount=acount+1;
            if(acount==2){
                for(int x=0;x<100;x++)
                q.a2[x] = A[x];
             printf("%s",q.a2);
            }
            if(acount==3){
                for(int y=0;y<100;y++)
                q.a3[y] = A[y];
             printf("%s",q.a3);
            }
            if(acount==4){
                for(int w=0;w<100;w++)
                q.a4[w] = A[w];
             printf("%s",q.a4);
            }
            if(acount==5){
                for(int v=0;v<100;v++)
                q.a5[v] = A[v];
             printf("%s",q.a5);
            }

        }
        ch = getc(fp1);
    }
    fclose(fp1);


////////    DISPLAYING THE QUESTION AS OUPUT AND TAKING ANSWER AS INPUT     /////////


char r[20];
int w=0;
printf("\t====================================================================\n");
printf("\t\t\t\tWELCOME TO THE QUIZ GAME\n");
printf("\t====================================================================\n");

    while(w<5){
        
if(maincount==0){
        printf("\n1. %s\n",q.q1);
        printf("\n1)thomas alva tdison \n2)alexander graham bell \n3)nikola tesla ");
        printf("\n write your answer here -> ");
        gets(r);
        correct(r,q.a1); 
        
        }
if(maincount==1){
        printf("\n2. %s\n",q.q2);
        printf("\n1)venus \n2)mercury \n3)jupiter ");
        printf("\n write your answer here -> ");
        gets(r);
        correct(r,q.a2);        
        }
if(maincount==2){
        printf("\n3. %s\n",q.q3);
        printf("\n1) Newton \n2) Einstein \n3)wright brothers");
        printf("\n write your answer here -> ");
        gets(r);
        correct(r,q.a3);
        }
if(maincount==3){
        printf("\n4. %s\n",q.q4);
        printf("\n1)mimas \n2)titan \n3)rhea ");
        printf("\n write your answer here -> ");
        gets(r);
        correct(r,q.a4); 
        }
if(maincount==4){
        printf("\n5. %s\n",q.q5);
        printf("\n1)bee hummingbirds \n2)eagle \n3)sparrow ");
        printf("\n write your answer here -> ");
        gets(r);
        correct(r,q.a5); 
        }


    maincount=maincount+1;
    w++;
    

}
printf("  \n*************************  LEADERBOARD  ************************ \n");
    printf("================================================================\n");
    printf("   NAME           |   Correct Answers  |  Total Score | \n");
    printf("================================================================\n");
    printf("%s                         %d                 %d  ",l.name,correct_answer,score);

//printf("\nTOTAL POINT SCORED -> %d\n",score);
//printf("\nNO. OF CORRECT ANSWERS -> %d\n",correct_answer);

      return 0;
}
