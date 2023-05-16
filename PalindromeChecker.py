'''
Author - Debag101
Purpose - Checking if a given string is palindrome or not
Date - 16 - 5 - 2023
'''

def main():
	#getting the string
	userInput = input("Enter the string => ")
	#reversing the string and storing it in a different variable
	reversedString = userInput[::-1]
	#checking if string is a palindrome
	if userInput == reversedString:
		print("String is palindrome ")
	else:
		print("String is not palindrome")
#calling main
if __name__ == '__main__':
	main()