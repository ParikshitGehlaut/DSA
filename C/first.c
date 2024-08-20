#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int top = -1;
int stack[500];

char* generate_output(char *string)
{
	static char text[2000];

	strcat(text, string);
	strcat(text, "\n");

	return text;
}

void generate_error(char *string)
{
	char text[100];

	strcat(text, string);
	strcat(text, "\n");

	FILE *ptr; 

	ptr = fopen("output.txt", "w");

	fprintf(ptr, "%s", text);
}

int ifoperator(char character){
	if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^' || character == '%' || character == '(' || character == ')' ){
		return 1;
	}
	else{
		return 0;
	}
}

int ifparan(char character){
	if (character == '(' || character == ')'){
		return 1;
	}
	else{
		return 0;
	}
}
int assign_precedene(char ch){	
	if (ch == '^'){
		return 3;
	}
	else if (ch == '*' || ch == '/' || ch == '%'){
		return 2;
	}
	else if (ch == '+' || ch == '-'){
		return 1;
	}
	else{
		return 0;
	}
}

int ifStackempty(){
	if (top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int ifStackfull(){
	if (top >= 500){
		return 1;
	}else{
        return 0;
    }	
}

int pop(){
	if (!ifStackempty()){
		int tmp = stack[top];
		top--;
		return tmp;
	}
	else{
		printf("Stack is empty");
	}

}

void push(char c){	
	if (!ifStackfull()){
		top++;
		stack[top] = c;

		char str[100];
		sprintf(str, "%c pushed into stack", c);
		generate_output(str);
	}
	else{
		printf("Stack is full");
	}
}

void check_pre(char ch, char* pfix_expression, int* end){
	if (ifStackempty()){
		push(ch);
		return;
	}
		if (ch == '('){
			push(ch);
			return;
		}
		else if (ch == ')'){
			while(stack[top] != '('){

				char output[100];
				char oper = pop();

				if (!(oper == '(')){
				pfix_expression[*end] = oper;
				*end = *end + 1;}

				sprintf(output, "%c popped from stack", oper);
				generate_output(output);
			}
			pop();
		}
		else{
			if (assign_precedene(ch) > assign_precedene(stack[top])){
				push(ch);
			}
			else{
				while(assign_precedene(ch) <= assign_precedene(stack[top])){
					char output[100];
					char oper = pop();
					
					if (!(oper == '(')){
					pfix_expression[*end] = oper;
					*end = *end + 1;}

					sprintf(output, "%c popped from stack", oper);
					generate_output(output);
				}
				push(ch);
			}
	}
}

int main(int argc, char* argv[]){
	
	FILE *fp;
	
	fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("File not found!");
		return 0;
	}


	char chr;
	char* postfix_expres = malloc(1000*sizeof(char));
	int pfix_pointer = 0;
	
	int ifprev_oper = 1;
	
	while((chr=fgetc(fp)) != EOF){

		if (ifoperator(chr)){
			if (ifparan(chr)){

				if (chr == ')'){
					if (ifprev_oper){
				
						generate_error("Invalid expression");
						return 0;
					}
				}
				check_pre( chr, postfix_expres, &pfix_pointer);
				continue;
			}

			if (ifprev_oper){
				
				generate_error("Invalid expression");
				return 0;
			}
			else{
				
				check_pre(chr, postfix_expres, &pfix_pointer);
				ifprev_oper = 1;
			}
		}
		else if(chr != '\n'){

			postfix_expres[pfix_pointer] = (char) chr;
			pfix_pointer++;
			ifprev_oper = 0;
		}
	}


	if (ifprev_oper){
		generate_error("Invalid expression");
		return 0;
	}

	while(!ifStackempty(&stack)){
		
		char val = pop(stack);
		if (!(val == '(' || val == ')')){
			char output[30];
			sprintf(output, "%c popped from stack", val);
			generate_output(output);
			postfix_expres[pfix_pointer] = val;
		}
		if (val == '(' || val == ')'){
			generate_error("Unequal Parathesis");
			return 0;
		}
		pfix_pointer++;
	}

	char string[1000];
	sprintf(string, "Postfix expression is:%s\n", postfix_expres);
	char *output_text = generate_output(string);

	
	FILE *fp1;
	fp1 = fopen("output.txt", "w");
	fprintf(fp1, "%s", output_text);
	fclose(fp1);

	fclose(fp);
	return 0;
}