#include <stdio.h>
#include <string.h>


/******************************************************************************
        Part 1 : To convert int to roman numerals till 1 mil
*******************************************************************************/

// Function to find the correct index of number to print

int sharvysLoop(int num, int array[])
{
	int index;
	for (int i = 0; i < 25; i++ )
	{
		if (num - array[i] < 0)
		{
			index = i - 1;
			break;
		}
	}
	return(index);
}


//Main roman to integer translator

int intToRoman()
{
	// Required information for translation :
		// User Input
	int num ;
		// Data

	int  reqNum[256] =
		{1,4,5,9,10,40,50,90,100,400,500,900,1000,4000,5000,9000,
		10000,40000,50000,90000,100000,400000,500000,900000,1000000};

	char romSym[256][128] =
		{"I", "IV", "V", "IX", "X", "XL", "L", 
		"XC", "C", "CD", "D", "CM", "M", "MV\u0305", "V\u0305", "MX\u0305",
		"X\u0305", "X\u0305L\u0305", "L\u0305", "X\u0305C\u0305", "C\u0305", 
		"C\u0305D\u0305", "D\u0305", "C\u0305M\u0305", "M\u0305"};
	
	// Asking for user input
	char title[256] = "Integer To Roman Numeral Translator\n";
	char sep[256] = "-----------------------------------------------------------\n";
	printf("\e[38;5;27m");
	printf("%97s", sep);
	printf("\e[1m\e[38;5;228m");
	printf("%85s", title);
	printf("\e[38;5;27m");
	printf("%97s", sep);
	printf("\n");
	printf("\e[38;5;27m");
	printf("Enter a number: \e[38;5;228m");
	scanf("%d", &num);
	printf("\n\e[38;5;27mRoman Conversion: \e[38;5;228m");
	
	// Main Running Code
	char translation[30];
	int ind;
	while (num > 0)
	{
		ind = sharvysLoop(num, reqNum);
		printf("%s", romSym[ind]);
		num -= reqNum[ind];
	}
	printf("\n\n");
	return 0;
}

//______________________________________________________________________________


/******************************************************************************
       Part 2 : To convert roman numerals to int till <4000
*******************************************************************************/

// Switch type function to return value of every IVXLCDM character
int digit(char c){
	
	int value=0;
	
	switch(c){
		case 'I': value = 1; break;
		case 'V': value = 5; break;
		case 'X': value = 10; break;
		case 'L': value = 50; break;
		case 'C': value = 100; break;
		case 'D': value = 500; break;
		case 'M': value = 1000; break;
		case '\0': value = 0; break;
		default: value = -1;
	}
	
	return value;
}

// Main translator function
int romanToInt(){
	
	char romNum[256];
	int i=0;
	long int number =0;
	
	// User input
	char title[256] = "Roman numeral to integer Translator\n";
	char sep[256] = "-----------------------------------------------------------\n";
	printf("\e[38;5;197m");
	printf("%97s", sep);
	printf("\e[1m\e[38;5;228m");
	printf("%85s", title);
	printf("\e[38;5;197m");
	printf("%97s", sep);
	printf("\n");
	
	printf("Enter any roman number (Less than 4000): ");
	
	printf("\e[38;5;228m");
	scanf("%s",romNum);
	printf("\n");
	while(romNum[i]){
		
		// Check for invalid character
		if(digit(romNum[i]) < 0){
			printf("\e[38;5;197mInvalid roman digit : \e[38;5;228m%c\n\n",romNum[i]);
			return 0;
		}
		
		// Check for invalid sequence of Roman number
		if((strlen(romNum) -i) > 2){
			if(digit(romNum[i]) < digit(romNum[i+2])){
				printf("\e[38;5;197mInvalid roman number\n\n");
				return 0;
			}
		}
		
		// Final return after all the req checks
		if(digit(romNum[i]) >= digit(romNum[i+1]))
			number = number + digit(romNum[i]);
		else{
			number = number + (digit(romNum[i+1]) - digit(romNum[i]));
			i++;
		}
		i++;
	}
	
	printf("\e[38;5;197m");
	printf("Integral Form is: ");
	printf("\e[38;5;228m %ld", number);
	printf("\n\n");
	
	return 0;
	
}


/******************************************************************************
        Part 3 : To convert int to roman running function
*******************************************************************************/


int nprintf(char chr, int count){
	for (int i=0; i<count; i++){
		printf("%c", chr);
	}
	return 0;
}
int replays() {
	int choice;
	// Ask user to chose what to translate
	
	char hello[256] = "\e[1m\e[38;5;208m|\e[1m\e[38;5;228m   Hello There\e[1m\e[38;5;208m   |\n\n";

	
	printf("\e[1;38;5;122m");
	printf("\nChoose one from available translator types:\n\n");	
	printf("\e[38;5;197m");
	printf("1) Integer to Roman Numerals (For numbers less than 1 million)\n2) Roman Numerals to Integer (For numbers less than 4000)\n\n");
	printf("\e[1;38;5;122m");
	printf("Input your choice: \e[38;5;197m");
	scanf("%d", &choice);
	
	
	
	if (choice == 1){
		printf("\033[1J\033[H\n");
		intToRoman();
	}
	
	else if (choice == 2) {
		printf("\033[1J\033[H\n");
		romanToInt();
	}
	
	else{
		printf("\n\e[38;5;196mERROR: Please select a valid choice you IDIOT!!!\n\n");
	}
	return 0;
}


int main() {
	
	printf("\033[1J\033[H\n"); // Clear screen
	
	char hello[256] = "\e[1m\e[38;5;208m|\e[1m\e[38;5;228m   Hello There\e[1m\e[38;5;208m   |\n\n";
	printf("%122s",hello);
	
	int testCase;
	char texTestCase[256] = "Test Case: ";
	printf("\e[1;37mEnter number of test cases: ");
	scanf("%d", &testCase);
	printf("\033[1J\033[H\n");
	
	for (int i=0; i < testCase; i++){
		char dashes = '-';
		printf("\e[1;37m");
		nprintf(dashes, 130);
		printf("\n");
		printf("%70s", texTestCase);
		printf("%d\n", i + 1);
		nprintf(dashes, 130);
		printf("\n");
		replays();
		char contChoice[256];
		char exit[256] = "e";
		char cont[256] = "c";
		printf("\e[38;5;228m");
		if (testCase != 1 && testCase != i+1){
			printf("Enter c to continue or e to exit .....: ");
			printf("\e[38;5;197m");
			scanf("%s", contChoice);
			int check = 1;
			if (!strcmp(contChoice, cont)){
				printf("\033[1J\033[H\n");
			}
			else if (!strcmp(contChoice, exit)){
				printf("\n");
				break;
			}
			else{
				printf("\033[1J\033[H\n");
			}
		}
	}
	char thanks[256] = "\e[1m\e[38;5;208m|\e[1m\e[38;5;228m   Visit Again\e[1m\e[38;5;208m   |\n\n";
	printf("%122s", thanks);
	printf("\e[38;5;228m");
	

	return 0;
}
