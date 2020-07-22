#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

extern void get_bound(int a, int b, double* c,double* d);
extern int choose(int n, int t);

struct D{double ID; int gender; double height;};

int main(void)
{
    int i,n;
    double val,id,ID;
    char fname[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    char buf[256];
    char buf2[256];
    FILE* fp,*fp2;
    int a,e,f,b;
    int gender;
    struct D date[14];

    i=-1;
    n=0;

    printf("input the file name of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample: %s\n",fname);

    printf("input the filename of sample ID:");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] = '\0';
    printf("the filename of sample: %s\n",fname2);

    fp=fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fp2=fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    a=e=f=0;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%lf",&gender, &val);
        i++;
        date[i].gender=gender;
        date[i].height=val;

        if(gender==1){
            a++;
        }elseif(gender==2){
            e++;
        }else{
            f++;
        }
    }
    b = a + e + f;

    i=0;
    printf("Input the ID:");
    scanf("%lf",&id);
    printf("---\n");

    while(fgets(buf2,sizeof(buf2),fp2) != NULL){
        sscanf(buf2,"%lf",&ID);
        i++;
        date[i].ID=ID;
    }
    for(i=1;i<=b;i++){
        if(date[i].ID==id){
            printf("ID:%.01f\n",date[i].ID);
            printf("gender:");
            if(date[i].gender==1){
                printf("male\n");
            }else{
                printf("female\n");
            }printf("height:%.1lf\n",date[i].height);
            n=1;
        }
    }
    if(n==0){
        printf("No date\n");
    }printf("---\n");
}
