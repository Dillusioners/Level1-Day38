# include <iostream>

// function to find the factorial of a number
// n -> the number
unsigned long long factorial(int n){
	unsigned long long fac = 1; // the factorial of the number
	
	// iterating from 2 to the number
	for(int i = 2; i <= n; i++){
		// multiplying the current iteration to the factorial
		fac *= i;
	}
	
	return fac;	
}

// execution starts from here
int main(int argc, char** argv){
	int num;
	
	// asking user for the number
	std::cout << "Enter your number: ";
	std::cin >> num;
	
	// number being printed
	std::cout << "The factorial is " << factorial(num);	
	return 0;
}
