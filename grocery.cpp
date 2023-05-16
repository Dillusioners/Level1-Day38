# include <iostream>
# include <random>


// storing all the items in the store
std::string all_items[] = {"Tomato at $6/kg", "Potato at $9/kg", "Milk at $8/kg", "Watermelon at $5", "Bananas at $6.9/kg"};
// the last item sold
std::string last_sold = all_items[4];

// function to reduce syntax for input
inline std::string input(std::string msg){
	std::string inp; // to store the input
	
	// asking user for the input
	std::cout << msg;
	std::cin >> inp;
	
	// returning the input
	return inp;
}

// orders an item for the customer
void order(bool direct){
	// variable declaration and asking user for details
	std::string name = input("Enter your name: "),
	address = input("Enter your address: "),
	phone = input("Enter your phone number: ");
	int itemCode = std::stoi(input("Enter your item code: "));
	
	// checking if the item code is valid
	 if(itemCode < 1 || itemCode > 5){
	 	std::cout << "Invalid item code provided.\nCheck shop items to get item list.";
	 	return;	
	 }
	 
	 // updating the last sold item
	 last_sold = all_items[itemCode - 1];
	 // checking if the item was a direct purchase or an order 
	 if(direct) std::cout << "Successfully purchased " << all_items[itemCode - 1] << ".";
	 else std::cout << "Sucessfully ordered your request: " << all_items[itemCode - 1] << ".";
}

// prints all the items in the store
void storeItems(){
	std::cout << "The following are avaliable:\n";
	// iterating through the all items array
	for(int i = 0; i < 5; i++){
		std::cout << i + 1 << ". " << all_items[i] << '\n';
	}
}

// to track the recent sales data for the dev
void track(){
	// setting up random seed and random generatior
	std::random_device rd;
	std::mt19937 mt(rd());
	
	// generating all the data and then printing them chronologically
	std::cout << "The following are the store statistics in the last 30 days:\n";
	std::cout << "\nSales is $" << (mt() % 200) + 1 << "k";
	std::cout << "\nTotal People in store were " << (mt() % 50) + 1 << "k";
	std::cout << "\nTotal items sold were " << (mt() % 800) + 1 << "k";
	std::cout << "\nAverage rating is " << (mt() % 10) + 1 << " stars";
}

// the menu for the login as customer
void customerMenu(){
	// variable declaration
	bool run = true;
	int choice;
	
	while(run){
		// printing the customer menu and taking user choice
		std::cout << "\n\nCustomer menu options:\n";
		std::cout << "1. Order Directly\n2. Order by delivery\n3. Store Items\n4. Exit\n>> ";
		std::cin >> choice;
		std::cout << std::endl;
		
		// checking the value of choice
		switch(choice){
			case 1: { // order directly
				order(true);
				continue;	
			}
			
			case 2: { // order by delivery
				order(false);
				continue;	
			}
			
			case 3: { // store items
				storeItems();
				continue;	
			}
			
			case 4: { // exit customer menu
				run = false;
				continue;	
			}
			
			default: { // any other garbage value
				std::cout << "Invalid choice provided.";	
			}
		}		
	}
}

// the menu for the store developers
void storeMenu(){
	// variable declaration
	bool run = true;
	int choice;
	
	while(run){
		// printing the store menu and asking user for choice
		std::cout << "\n\nDeveloper menu options:\n";
		std::cout << "1. Store Items\n2. Show last sold item\n3. Track Sales\n4. Exit\n>> ";
		std::cin >> choice;
		std::cout << std::endl;
		
		// checking the value of the user choice
		switch(choice){
			case 1: { // store items
				storeItems();
				continue;	
			}
			
			case 2: { // show last ordered item
				std::cout << "The last sold item is " << last_sold;
				continue;	
			}
			
			case 3: { // tracking the sales
				track();
				continue;	
			}
			
			case 4: { // exit
				run = false;
				continue;	
			}
			
			default: { // any other garbage value
				std::cout << "Invalid choice provided.";	
			}
		}		
	}
}

// execution starts from here
int main(int argc, char** argv){
	// variables declared
	bool run = true;
	int choice;
	
	std::cout << "DILLUSIONERS GROCERY STORE";
	while(run){
		// printing the main menu asking user for choice
		std::cout << "\n\nThe following are your options:\n";
		std::cout << "1. Login as Customer\n2. Login as Developer\n3. Exit\n>> ";
		std::cin >> choice;
		std::cout << std::endl;
	
		// checking for the user choice
		switch(choice){
			case 1: { // login as customer
				customerMenu();
				continue;	
			}
			case 2: { // login as dev
				storeMenu();
				continue;	
			}
			
			case 3: { // exit
				run = false;
				continue;	
			}
			default: { // invalid garbage value
				std::cout << "Invalid choice provided.";	
			}
		}
	}	
	return 0;	
}
