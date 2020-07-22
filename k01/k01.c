#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int N);
extern double var_online(double val,double ave,double a,int N);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    int N=0;
    double ave=0;
    double var, a, varM;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

        N++;
        var=var_online(val,ave,a,N);
        ave=ave_online(val,ave,N);
        a=ave_online(pow(val,2),a,N);
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

varM=N*var/(N-1);
printf("標本平均 %f\n",ave);
printf("標本分散 %f\n",var);
printf("母集団平均 %f\n",ave);
printf("母集団分散 %f\n",varM);
    return 0;
}

double ave_online(double val,double ave,int N)
{
    return(((N-1)*ave/N)+(val/N));
}
double var_online(double val,double ave,double a,int N)
{
    return(((N-1)*a/N)+pow(val,2)/N)-pow((((N-1)*ave/N)+(val/N)),2);
}