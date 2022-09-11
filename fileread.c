#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    char fname[25];
    char lname[25];
    char mj[40];
    char deg[40];
    float ggpa;
    int chour;
    char tta[10];
    char advis[50];

};

int main(){
    FILE *f;
    f=fopen("students_dataset.csv", "r");
     //check if the file exists
     int flag=0;
     int l=0;
    struct student s1[60];
    struct student s2[60];
    struct student s3[60];
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
            //printf("%s", firstname);

            strcpy(s1[i].fname, firstname);
            
            //printf("%s", s1[i].fname);
            
            //lastname
            sptr=strtok(NULL,",");
            strcpy(lastname,sptr);

            strcpy(s1[i].lname, lastname);
            //printf("%s ", s1[i].lname);

            //major
            sptr=strtok(NULL,",");
            strcpy(major,sptr);
            strcpy(s1[i].mj,major);
            //printf("%s ", s1[i].mj);

            //degree
            sptr=strtok(NULL,",");
            strcpy(degree,sptr);
            strcpy(s1[i].deg, degree);
            //printf("%s", s1[i].deg);
            


            //gpa
            sptr=strtok(NULL,",");
            gpa=atof(sptr);
            s1[i].ggpa=gpa;
            //printf("%.2f ", s1[i].ggpa);


            //credit hours
            sptr=strtok(NULL,",");
            credithour=atoi(sptr);
            s1[i].chour=credithour;
            //printf("%d", s1[i].chour);

            //TA
            sptr=strtok(NULL,",");
            strcpy(TA,sptr);

            //Advisor
            sptr=strtok(NULL,",");
            strcpy(Advisor,sptr);
            strcpy(s1[i].advis,Advisor);


            //printf("\n%s %s %s %s %.2f %d %s %s", firstname, lastname, major, degree, gpa, credithour, TA, Advisor);
            l++;
            i++;
        }

    }else{
        printf("File does not exits");
    }

    if(flag!=0){
        int c=0;
        int t=0;

        //1. degree count and display names
        strcpy(s2[0].deg, s1[0].deg); //initially assigning the first value of s1[0].deg to s2[0].deg
        //printf("%s", s2[0].deg);

        for(int i=0;i<l-1;i++){
            c=0;
            for(int j=0;strlen(s2[j].deg)!=0;j++){
                //printf("%s\n", s2[j].deg);
                if(strcmp(s2[j].deg, s1[i].deg)==0){
                    c=1; //if both the strings are equals 
                }
                t=j;
            }

            if(c==0){ //if the last string of s1[i].deg is not present in s2[i].deg
                strcpy(s2[t+1].deg, s1[i].deg); //it added to the s2 deg student struct
                //printf("%s\n", s2[t+1].deg);

            }
        }
        printf("1st point:\n");
        printf("Below shows the name of different degrees and total count\n");
        int dcount=0;
        for(int i=0;strlen(s2[i].deg)!=0;i++){
            printf("name of the degree:");
            printf("%s\n", s2[i].deg);
            dcount++;
        }

        printf("total number of degrees are : %d\n", dcount);

        //2. highest gpa students full name
        if(s1[0].ggpa>s1[1].ggpa && s1[0].ggpa>s1[2].ggpa){
            s2[2].ggpa=s1[0].ggpa;
            strcpy(s2[2].fname, s1[0].fname);
            strcpy(s2[2].lname, s1[0].lname);
            //printf("s10");
            if(s1[1].ggpa>s1[0].ggpa){
                s2[1].ggpa=s1[1].ggpa;
                s2[0].ggpa=s1[0].ggpa;
                strcpy(s2[1].fname, s1[1].fname);
                strcpy(s2[1].lname, s1[1].lname);

                strcpy(s2[0].fname, s1[0].fname);
                strcpy(s2[0].lname, s1[0].lname);
            }else{
                s2[0].ggpa=s1[1].ggpa;
                s2[1].ggpa=s1[0].ggpa;

                strcpy(s2[0].fname, s1[1].fname);
                strcpy(s2[0].lname, s1[1].lname);

                strcpy(s2[1].fname, s1[0].fname);
                strcpy(s2[1].lname, s1[0].lname);
            }

        } 

        else if (s1[1].ggpa>s1[0].ggpa && s1[1].ggpa>s1[2].ggpa){
            s2[2].ggpa=s1[1].ggpa;
            strcpy(s2[2].fname, s1[1].fname);
            strcpy(s2[2].lname, s1[1].lname);
            //printf("s11");
            if(s1[2].ggpa>s1[0].ggpa){
                s2[1].ggpa=s1[2].ggpa;
                s2[0].ggpa=s1[0].ggpa;

                strcpy(s2[1].fname, s1[2].fname);
                strcpy(s2[1].lname, s1[2].lname);

                strcpy(s2[0].fname, s1[0].fname);
                strcpy(s2[0].lname, s1[0].lname);
            }
            else{
                s2[1].ggpa=s1[0].ggpa;
                s2[0].ggpa=s1[2].ggpa;

                strcpy(s2[1].fname, s1[0].fname);
                strcpy(s2[1].lname, s1[0].lname);

                strcpy(s2[0].fname, s1[2].fname);
                strcpy(s2[0].lname, s1[2].lname);
                
            }
            
        }
        else if (s1[2].ggpa>s1[0].ggpa && s1[2].ggpa>s1[1].ggpa){
            s2[2].ggpa=s1[2].ggpa;
            strcpy(s2[2].fname,s1[2].fname);
            strcpy(s2[2].lname,s1[2].lname);

            //printf("%s %s ", s2[2].fname,s2[2].lname);
            //printf("s12 %.2f ", s2[2].ggpa);
            if(s1[0].ggpa>s1[1].ggpa){
                s2[1].ggpa=s1[0].ggpa;
                s2[0].ggpa=s1[1].ggpa;
                //printf("2nd\n");
                //printf("%.2f",s2[0].ggpa);
                //printf("%.2f",s2[1].ggpa);
                strcpy(s2[1].fname, s1[0].fname);
                strcpy(s2[1].lname, s1[0].lname);

                strcpy(s2[0].fname, s1[1].fname);
                strcpy(s2[0].lname,s1[1].lname);

                //printf("%s\n %s\n%s\n", s2[0].fname, s2[1].fname, s2[2].fname);
                //printf("%.2f\n%.2f\n%.2f\n", s2[0].ggpa,s2[1].ggpa,s2[2].ggpa);

            }
            else if(s1[1].ggpa>s1[0].ggpa){
                s2[1].ggpa=s1[1].ggpa;
                s2[0].ggpa=s1[0].ggpa;
                //printf("%.2f",s2[0].ggpa);
                //printf("%.2f",s2[1].ggpa);
                strcpy(s2[0].fname, s1[0].fname);
                strcpy(s2[0].lname, s1[0].lname);

                strcpy(s2[1].fname, s1[0].fname);
                strcpy(s2[1].lname,s1[0].lname);
            }
            //finding the max gpa and assiging it another struct array s2[i]
            for(int i=0;s1[i].ggpa>=1;i++){
                //printf("%.2f\n",s1[i].ggpa);
                if(s1[i].ggpa>s2[0].ggpa){
                    if(s1[i].ggpa>s2[1].ggpa){
                        if(s1[i].ggpa>s2[2].ggpa){
                            //passing s2[2] values to its corresponding variables
                            s2[0].ggpa=s2[1].ggpa;
                            strcpy(s2[0].fname,s2[1].fname);
                            strcpy(s2[0].lname,s2[1].lname);
                            s2[1].ggpa=s2[2].ggpa;
                            strcpy(s2[1].fname,s2[2].fname);
                            strcpy(s2[1].lname,s2[2].lname);
                            s2[2].ggpa=s1[i].ggpa;
                            strcpy(s2[2].fname,s1[i].fname);
                            strcpy(s2[2].lname,s1[i].lname);
                            //printf("2. %.2f\n", s2[2].ggpa);
                        }
                        else{
                            s2[0].ggpa=s2[1].ggpa;
                            strcpy(s2[0].fname,s2[1].fname);
                            strcpy(s2[0].lname,s2[1].lname);
                            s2[1].ggpa=s1[i].ggpa;
                            strcpy(s2[1].fname,s1[i].fname);
                            strcpy(s2[1].lname,s1[i].lname);
                            //printf("1. %.2f\n", s2[1].ggpa);

                        }
                    }
                    else{
                        s2[0].ggpa=s1[i].ggpa;
                        strcpy(s2[0].fname,s1[i].fname);
                        strcpy(s2[0].lname,s1[i].lname);
                        //printf("0. %.2f\n", s2[0].ggpa);
                    }
                }
            }


        }
        printf("2nd Point:\n");
        printf("Please find the below full names of 3 students with highest GPA:\n");
        printf("Firstname Lastname GPA\n");
        for(int i=2;i>=0;i--){
                printf("Name = %s %s gpa= %.2f\n", s2[i].fname, s2[i].lname, s2[i].ggpa);
        }

        //printf("Length of list: %d\n", l-1);
        //3. Avg credit hours
        float tot=0;
        for(int i=0;i<l-1;i++){
            tot=s1[i].chour+tot;
        }
        //printf("tot = %.2f\n",tot);
        printf("3rd point:\n");
        printf("Average credit hours = %.2f\n", tot/(l-1));

        //avg gpa of computer science l is length of the column
        int val=0;
        float tot1=0;
        for(int i=0;i<l-1;i++){
            if(strcmp(s1[i].mj,"Computer Science")==0){
                s2[val].ggpa=s1[i].ggpa;
                //printf("%s %.2f\n",s1[i].mj,s2[val].ggpa);
                tot1=s2[val].ggpa+tot1;
                val++;
            }
        }
        //4. computer science avg gpa
        //printf("count = %d tot = %.2f\n",val,tot1);
        printf("4th point:\n");
        printf("GPA of average computer science = %.2f\n", tot1/(val));
        
        //5. list of departments and total count of advisors
        printf("5th point\n");
        printf("Below are the list of departments\n");
        strcpy(s2[0].mj,s1[0].mj);
        for(int i=1;i<l-1;i++){
            c=0;
            for(int j=0;strlen(s2[j].mj)!=0;j++){
                if(strcmp(s2[j].mj,s1[i].mj)==0){
                    c=1;
                }
                t=j;
            }
            if(c==0){
                strcpy(s2[t+1].mj,s1[i].mj);
            }
        }

        for(int i=0;strlen(s2[i].mj)!=0;i++){
            printf("%s\n", s2[i].mj);
        }
        //printing the unique advisers
        int k=0, gtemp=0;
        int flag=2;
        int count=0;
        for(int i=0;strlen(s2[i].mj)!=0;i++){
            printf("course = %s\n", s2[i].mj);
            count=1;
            k=0;
            for(int j=0;strlen(s1[j].mj)!=0;j++){
                if(strcmp(s2[i].mj,s1[j].mj)==0){
                    strcpy(s2[k].advis,s1[j].advis);
                    //s2[k].ggpa=s1[j].ggpa;
                    k++;
                }
            }
            for(int l=0;strlen(s2[l].advis)!=0;l++){
                //printf("%s",s2[l].advis);
                
            }
            //////
            for(int l=0;strlen(s2[l].advis)!=0;l++){
                
                if(strlen(s3[0].advis)==0){
                    strcpy(s3[0].advis,s2[0].advis);
                    //s3[0].ggpa=s2[0].ggpa;
                }
                for(int m=0;strlen(s3[m].advis)!=0;m++){
                    if(strcmp(s3[m].advis,s2[l].advis)==0){
                        flag=1;
                        gtemp=m;
                        break;
                    }
                    else{
                        gtemp=m;
                        flag++;
                    }
                }
                if(flag!=1){
                    int len=strlen(s2[l].advis);
                    int sizes=0;
                    for(int pi=0;strlen(s3[pi].advis)!=0;pi++){
                        for(int m=0;m<len;m++){
                            if(s3[pi].advis[m]==s2[l].advis[m]){
                                sizes++;
                            }
                        }
                    }
                    if(sizes<10){
                        strcpy(s3[gtemp+1].advis,s2[l].advis);
                        sizes=0;
                        count++;
                    }
                    
                    //s3[gtemp+1].ggpa=s2[l].ggpa;
                }
            }
            printf("Number of advisors= %d\n", count);
            for(int l=0;strlen(s3[l].advis)!=0;l++){
                
                printf("advisor=%s", s3[l].advis);
                
            }
            
            for(int l=0;strlen(s3[l].advis)!=0;l++)
            {
                strcpy(s3[l].advis,"");

            }
            for(int l=0;strlen(s2[l].advis)!=0;l++)
            {
                strcpy(s2[l].advis,"");
            }
            
        }

    }

    
    fclose(f);
    return 0;
}
