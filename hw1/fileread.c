#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *f;
    f=fopen("students_dataset.csv", "r");
     //check if the file exists
     int flag=0;
     char arrdegree[1000];
    if(f!=NULL){
        flag=1;
        //printf("file exists");
        char cline[1000];

        char firstname[25];
        char lastname[25];
        char major[40];
        char degree[40];
        float gpa;
        int credithour;
        char TA[10];
        char Advisor[1000];
        
        int l=0;
        char *sptr;

        
        int dint=0; 
        int i=0;

        while(fgets(cline, 1000, f)!=NULL){
            //printf("%d", l);
            if(l==0){
                l++;
                continue;
            }
            //printf("\n%s", cline);
            //firstname
            sptr=strtok(cline,",");
            strcpy(firstname,sptr);
            
            //lastname
            sptr=strtok(NULL,",");
            strcpy(lastname,sptr);

            //major
            sptr=strtok(NULL,",");
            strcpy(major,sptr);

            //degree
            sptr=strtok(NULL,",");
            strcpy(degree,sptr);
            if(dint==0){
                arrdegree[dint]=degree[0];
                dint++;
            }
            else{
                arrdegree[dint]=degree[0];
                dint++;
            }
            printf(arrdegree);


            //gpa
            sptr=strtok(NULL,",");
            gpa=atof(sptr);

            //credit hours
            sptr=strtok(NULL,",");
            credithour=atoi(sptr);

            //TA
            sptr=strtok(NULL,",");
            strcpy(TA,sptr);

            //Advisor
            sptr=strtok(NULL,",");
            strcpy(Advisor,sptr);


            printf("\n%s %s %s %s %.2f %d %s %s", firstname, lastname, major, degree, gpa, credithour, TA, Advisor);
            l++;
            
        }

    }else{
        printf("File does not exits");
    }

    if(flag!=0){
        printf("file exists");
        printf("%s", arrdegree);
        printf("\n%d\n", sizeof(arrdegree));
        //referred from https://www.tutorialgateway.org/c-program-to-remove-all-duplicate-character-in-a-string/
        for(int i=0;arrdegree[i]!='\0';i++){
            //printf("%c",arrdegree[i]);
            for(int j=i+1;arrdegree[j]!='\0';j++){
                if (arrdegree[i]==arrdegree[j]){
                    printf("%c = %c \n", arrdegree[i], arrdegree[j]);
                    arrdegree[j]=arrdegree[j+1];
                    printf("after %c = %c \n", arrdegree[i], arrdegree[j]);

                }
            }
        }
        printf("\n%s", arrdegree);
    }
    fclose(f);
    return 0;
}