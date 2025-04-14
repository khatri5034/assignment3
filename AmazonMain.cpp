#include <iostream>
#include <string>
#include "Amazon340.h"
#include "Vendor.h"
#include<memory>

using namespace std;

/**  
 * cisplays the application's main menu
 * @pre create a new object of type Vendor
 * @param vendor - vendor object to interact with
 **/
void displayVendorMenu(Vendor& vendor)
{
	int vendorChoice = 0; //store vendor choice

	do
	{
		cout << endl << "Hi, " << vendor.getUsername() << ", what would you like to do:\n" //prompt for choice
			<< "1. Display Profile\n"
			<< "2. Modify Password\n"
			<< "3. Create Product\n"
			<< "4. Display All Products\n"
			<< "5. Display Kth Product\n"
			<< "6. Modify Product\n"
			<< "7. Sell Product\n"
			<< "8. Delete Product\n"
			<< "0. Logout\n"
			<< "Choice: ";
		cin >> vendorChoice;
		cin.ignore();
		cout << endl;

		switch (vendorChoice) //switch case for vendor choice
		{
			case 1: //display profile
			{
				cout<<vendor;
				break;
			}
			case 2: //modify password
			{
				string password; //store new password

				cout << "Enter new password: " << endl; //prompt for new password
				getline(cin, password);

				if (vendor.modifyPassword(password)) //modify success
					cout << "Your password has been modified successfully." << endl;
				else //modify fail (case: same as old password)
					cout << "Your new password cannot be same as old password." << endl;

				break;
			}
			case 3: //create product
			{
				int productType; //store product type
			    string name, description; //store product name and description
				int appendChoice, position; //store append choice and append position

			    cout << "Enter the type of product (1 for Media, 2 for Good, 0 for Return): "; //prompt for product type
			    cin >> productType;
			    cin.ignore();
			    cout << endl;

			    switch (productType) //switch case for product type
			    {
			        case 1: //media
			        {
			            string type, targetAudience; //store media type and target audience
						shared_ptr<Media> media(new Media());
			         	cin>>*media;


			            cout << endl;
			            cout << "Do you want to append at a specific position? (1 for Yes, 0 for No): "; //prompt for append choice
			            cin >> appendChoice;
			            cin.ignore();
			            cout << endl;

			            if (appendChoice == 1) //append
						{
			                cout << "Enter the position to append (1 to " << vendor.getProductListSize() << "): "; //prompt for position to append
			                cin >> position;
			                cin.ignore();
			                cout << endl;

			                if (vendor.appendK(media, position)) //append success
								cout << media->getName() << " has been appended successfully at position " << position << "." << endl;
			                else //append fail
			                    cout << "Failed to append media at position " << position << "." << endl;	
			            }
			            else //not to append
						{
			                if (vendor.createProduct(media)) //create success
			                    cout << media->getName() << " has been created successfully." << endl;
			                else //create fail
			                    cout << "Failed to create media." << endl;
			            }
			            break;
			        }
			        case 2: //good
			        {
			            string expirationDate; //store good expiration date
			            int quantity; //store good quantity
						shared_ptr<Good> good(new Good());
			            cin>> *good;


			            cout << endl;

			            cout << "Do you want to append at a specific position? (1 for Yes, 0 for No): "; //prompt for append choice
			            cin >> appendChoice;
			            cin.ignore();
			            cout << endl;

			            if (appendChoice == 1) //append
						{
			                cout << "Enter position to append (1 to " << vendor.getProductListSize() << "): "; //prompt for position to append
			                cin >> position;
			                cin.ignore();
			                cout << endl;

			                if (vendor.appendK(good, position)) //append success
			                    cout << good->getName() << " has been appended successfully at position " << position << "." << endl;
			                else //append fail
			                    cout << "Failed to append good at position " << position << "." << endl;
			            }
			            else //not to append
						{
			                if (vendor.createProduct(good)) //create success
			                    cout << good->getName() << " has been created successfully." << endl;
			                else //create fail
			                    cout << "Failed to create good." << endl;
			            }
			            break;
			        }
			        case 0: //return
			            break;
			        default: //invalid choice
			            cout << "Invalid choice." << endl;
			    }
			    break;
			}
			case 4: //display all products
			{
				cout << "Product List: " << endl;
				vendor.displayAllProducts();

				break;
			}
			case 5: //display kth product
			{
				int k, size = vendor.getProductListSize(); //store k and size of product list

				cout << "Enter the value K: "; //prompt for k
				cin >> k;
				cin.ignore();
				cout << endl;

				if (k < 1 || k > size) //invalid k
					cout << "Value entered must be between 1 and the product list size." << endl
						<< "Product list size: " << size << endl;
				else //valid k
					vendor.displayProductK(k);

				break;
			}
			case 6: //modify product
			{
				int k, size = vendor.getProductListSize(); //store k and size of product list

				cout << "Enter the product index to modify: "; //prompt for k
				cin >> k;
				cin.ignore();

				if (k < 1 || k > size) //invalid k
					cout << "Value entered must be between 1 and the product list size." << endl
					<< "Product list size: " << size << endl;
				else //valid k
				{
					string name, description; //store new name and description

					cout << "Enter new name: " << endl; //prompt for new info
					getline(cin, name);

					cout << "Enter new description: " << endl;
					getline(cin, description);

					cout << endl;

					if (vendor.modifyProduct(k, name, description)) //modify success
						cout << "Product has been modified." << endl;
					else //modify fail
						cout << "Failed to modify product." << endl;
				}

				break;
			}
			case 7: //sell product
			{
				int k, size = vendor.getProductListSize(); //store k and size of product list

				cout << "Enter the product index to sell: "; //prompt for k
				cin >> k;
				cin.ignore();

				if (k < 1 || k > size) //invalid k
					cout << "Value entered must be between 1 and the product list size." << endl
					<< "Product list size: " << size << endl;
				else //valid k
				{
					int quantity; //store quantity to sell

					cout << "Enter the quantity to sell: "; //prompt for quantity
					cin >> quantity;
					cin.ignore();

					cout << endl;

					if (vendor.sellProduct(k, quantity)) //sell success
						cout << "Product has been sold." << endl;
					else //sell fail (case: sold-out)
						cout << "The product is sold-out." << endl;
				}

				break;
			}
			case 8: //delete product
			{
				int k, size = vendor.getProductListSize(); //store k and size of product list

				cout << "Enter the product index to delete: "; //prompt for k
				cin >> k;
				cin.ignore();

				cout << endl;

				if (k < 1 || k > size) //invalid k
					cout << "Value entered must be between 1 and the product list size." << endl
					<< "Product list size: " << size << endl;
				else //valid k
					if (vendor.deleteProduct(k)) //delete success
						cout << "Product has been deleted." << endl;
					else //delete fail
						cout << "Failed to delete product." << endl;

				break;
			}
			case 0: //logout
			{
				cout << "Logging you out." << endl;
				break;
			}
			default: //invalid choice
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (vendorChoice != 0);
}


int main() //main
{
	Amazon340 amazon340; //store amazon340 object
	string username, email, password, bio, profilePicture; //store vendor info

	cout << "Welcome to Amazon340:" << endl;


			Vendor vendor;
			cin>>vendor;





	displayVendorMenu(vendor); //display main menu
				
	return 0;
}
