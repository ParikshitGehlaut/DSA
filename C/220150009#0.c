#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
FILE *input , *out;
int num, total = 0, max = 0, min = 0, sum = 0;
float avg;

// reading the input file
input = fopen(argv[1],"r");
if (input == NULL){
printf("Error : input file not found");
exit(1);
}

// writing the output file
out = fopen("output.txt","w");
if (out == NULL){
printf("Error : output file not found");
exit(1);
}
int flag=0;
while(fscanf(input,"%d",&num) == 1){
total++;
sum += num;
if(flag==0) {
min = num;
max = num;
flag=1;
}
if(num > max){
max = num;}

if(num < min){
min = num;}
}

if(total>0){
avg = (float)sum/total;
}else{
avg = 0.00;
}

fprintf(out,"%d\n",total);
if(total>0){
fprintf(out,"%d\n",max);
fprintf(out,"%d\n",min);
fprintf(out,"%d\n",sum);
fprintf(out,"%.2f\n",avg);
}

fclose(input);
fclose(out);
return 0;
}
