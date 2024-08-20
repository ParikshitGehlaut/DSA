#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char postfix_final[2000];

int is_op(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return 0;
    }
}


// function to check whether expression is valid or not
int is_valid(char* infix_expression, int length, FILE *fp){
    for (int i=0; i < length; i++){
        char c = infix_expression[i];
        char temp = c;
        if ((temp>='a'&& temp<='z') || (temp>='A' && temp<='Z')){
            if (i < length-1){
                char next_ch = infix_expression[i+1];
                if ((next_ch >='a'&& next_ch <='z')||( next_ch >='A' && next_ch <='Z')){
                printf("2");
                fprintf(fp, "Invalid Expression");
                return 0;
            }
        }

        }else if (is_op(c)){
             if (i== length-1 || is_op(infix_expression[i+1])){
                printf("3");
                fprintf(fp,"Invalid Expression ");
                return 0;
             }
        }                
     }
     return 1;
 }
// funtion to check if Parenthesis
int Parenthesis(char str[], FILE *fp){
    int array[strlen(str)];
    int c = 0;
    for (int i = 0; str[i] != '\0';i++){
        if(str[i]=='('){
            array[c]=1;
            c++;
        }
        else if(str[i]==')'){
            array[c]=0;
            c++;       
        }

        
    }
    for(int j=0; j < c; j++){
        if(array[j]==1){
            for(int k=j; k<c; k++){
                if(array[k]==0){
                    array[j]=-1;
                    array[k]=-1;
                    break;
                }
            }
        }
    }

   
    for(int i = 0;i<c;i++)
    {
        if(array[i] != -1)
        {
            fprintf(fp, "unequal parentheis");
            return 0;
        }
    }
    return 1;
    
}

char *infix_to_postfix(char *infix_expression,int len, FILE *fp){
  int size=0;  
  char *stack = malloc(len * sizeof(char));
  int top = -1;
  len = strlen(infix_expression);
  char *postfix_expression = malloc((len+1) * sizeof(char));
  int postfix_index = 0;
 
for (int i=0;i< len ;i++){
    char c=infix_expression[i];
    if((c >= 'a' && c <= 'z')||(c >= 'A'&& c <= 'Z')){
        
        postfix_expression[postfix_index++] = c;
    }
    else if (is_op(c) || c == '(' || c == ')'){
        if(top == -1)
        {
            //push
            stack[++top] = c;

		    char string[40];
			sprintf(string, "%c pushed into stack\n", c);
            strcat(postfix_final, string);
            
        }
        else if (c == '('){
            stack[++top] = c;

            char string[40];
			sprintf(string, "%c pushed into stack\n", c);
            strcat(postfix_final, string);
        }

        else if (c == ')'){
            while(stack[top] != '('){
                char op = stack[top];
                top--;
                i--;
                postfix_expression[postfix_index++] = op;

                if (op != '('){
                char string[40];
                sprintf(string, "%c popped from stack\n", op);
                strcat(postfix_final, string);
                }
                }
            }

        else if (precedence(stack[top]) >= precedence(c)){
            char op = stack[top];
            top--;
            i--;
            postfix_expression[postfix_index++] = op;

            if (op != '('){
            char str[40];
			sprintf(str, "%c popped from stack\n", op);
            strcat(postfix_final, str);
            }

        }
        else if(precedence(c) > precedence(stack[top]))
        {
            stack[++top] = c;

            char str[40];
			sprintf(str, "%c pushed into stack\n", c);
            strcat(postfix_final, str);

        }
    }

        
    
 }
 while(top>-1){
        char op = stack[top--];
        if (op != '('){
        postfix_expression[postfix_index++] = op;
        char str[40];
		sprintf(str, "%c popped from stack\n", op);
        strcat(postfix_final, str);
    }}
    return postfix_expression;
}



int main(int argc, char *argv[]) {
   
    FILE *fp = fopen(argv[1], "r");
    if(fp==NULL){
            printf("Failed to open Input file %s\n",argv[1]);
        }
int co1unt = 0;
char input_string[100];
fscanf(fp,"%s",input_string);
int count = strlen(input_string);
for (int i=0; i<count;i++){
    if (input_string[i]=='+'||input_string[i]=='-'||input_string[i]=='*'||input_string[i]=='/'||input_string[i]=='^'||input_string[i]=='%'){
        co1unt++;
    }
}
if(!Parenthesis(input_string, fp))
return 0;

if(!is_valid(input_string, count, fp))
    return 0;

int len = strlen(input_string);
char *postfix_expression = malloc((len+1) * sizeof(char));
postfix_expression = infix_to_postfix(input_string, count, fp);

fclose(fp);

fprintf(fp, "%s", postfix_final);
fprintf(fp,"Posfix expression is: %s\n",postfix_expression);
fclose(fp);
}