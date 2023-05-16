'''
Author - Debag101
Purpose - Count the number of consonants and vowels in a string
Date - 16 - 5 - 2023
'''

def main():
#Creating a list of all the vowels in both upper and lower case
	vowel_list = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']
#Initialising counters to 0
	vowelCounter = consonantCounter = 0
#getting the string
	inputString = input("Enter the string => ")
#Iterating through the string
	for char in inputString:
#if character of string is in vowel_list then it is vowel
		if char in vowel_list:
#if vowel we increment vowel counter
			vowelCounter += 1
		else:
#if not vowel we increment consonant counter
			consonantCounter += 1
#Printing the number of consonants and vowels
	print(f"Number of consonants is {consonantCounter} number of vowles is {vowelCounter}")

#Calling main
if __name__ == '__main__':
	main()
