#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *input , *out;
    int num, total = 0, max = 0, min = 0, sum =0;
    float avg;
    // open file for reading
    input = fopen("input.txt","r");
    if(input == NULL){
        printf("Error: could not open input file\n");
        exit(1);
    }
    //open output file for writing
    out = fopen("output.txt","w");
    if(out == NULL){
        printf("Error: could not open output file\n");
        exit(1);

    }
    //Read the input and compute statistics
    while(fscanf(input,"%d",&num)==1){
        total++;
        sum += num;

        if(total==1 || num > max){
            max = num;
        }
        if(total==1 || num < min){
            min = num;
        }

    }
    if(total>0){
        avg = (float)sum/total;
    }else{
        avg = 0.00;
    }

    fprintf(out,"%d\n",total);
    if(total>0){
        fprintf(out,"%d\n",min);
        fprintf(out,"%d\n",max);
        fprintf(out,"%d\n",sum);
        fprintf(out,"%.2f\n",avg);
    }else{
        fprintf(out,"0\n0\n0\n0.00\n");
    }
    return 0;
}