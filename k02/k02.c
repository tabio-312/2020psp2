#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

#define MU_A 170.8
#define MU_B 169.7
#define sigma_A 5.43
#define sigma_B 5.5

int main(void)
{
    double val,a,b,g,h,YUDO_A=1,YUDO_B=1;
    char fname[FILENAME_MAX];
    char buf[256];
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

        a=(val-MU_A)/sigma_A;
        b=(val-MU_B)/sigma_B;
        g=p_stdnorm(a);
        h=p_stdnorm(b);
        YUDO_A=YUDO_A*g;
        YUDO_B=YUDO_B*h;




    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",YUDO_A);
    printf("L_B: %f\n",YUDO_B);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

