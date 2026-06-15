#include <iostream>
#include <iomanip>
#include <string>

using namespace std;






void registerCustomer(string &customerName , string &contactNumber , string &orderType , int &persons);

void displayMenu();

void displayFoodMenu(string foodItems[] , double prices[] , int size);

double placeOrder(string foodItems[] , double prices[] , int size);

double calcServiceCharges(double foodBill , string orderType);

double calcGST(double amount);

double calcDiscount(double amount);

void displayBill(string customerName , string orderType , int persons , double foodBill , double serviceCharges , double gst ,
                      double discount , double totalBill);
                      
void displayCustomerDetails(string customerName , string contactNumber , string orderType , int persons);                      
                  
                      
                      
                      
                      

int main()
{


    string customerName , orderType , contactNumber;
    int persons ;
	
	registerCustomer(customerName , contactNumber , orderType , persons);
	
	
	string foodItems[8] = {"Chicken Burger" , "Zinger Burger" , "Pizza Small" , "Pizza Large" , "Chicken Biryani" , "BBQ Platter" ,
	                       "Fries" , "Cold Drink" };

    double prices[8] = { 450 , 550 , 900 , 1800 , 350 , 1200 , 250 , 120 };

    int MainChoice;    
    int foodBill = 0;
	double serviceCharges = 0;
    double gst = 0;
    double discount = 0;
    double totalBill = 0;
    
do{    
    displayMenu();
    cin >> MainChoice;
	
	if(MainChoice == 1)
	{
		displayFoodMenu(foodItems , prices , 8);
	}
	else if(MainChoice == 2)
	{
		foodBill += placeOrder(foodItems, prices, 8);
	}
	else if(MainChoice == 3)
	{
	    serviceCharges = calcServiceCharges(foodBill , orderType);
	    
	    gst = calcGST(foodBill);
	    
	    discount = calcDiscount(foodBill);
	    
	    totalBill = foodBill + serviceCharges + gst - discount;
	    
	    displayBill(customerName , orderType , persons , foodBill , serviceCharges , gst , discount , totalBill);
	    
	}
	else if(MainChoice == 4)
	{
		displayCustomerDetails(customerName , contactNumber , orderType , persons);
	}
	else if(MainChoice == 5)
	{
		cout << "\n\t\t\t\t            >>>Program Exited Successfully<<<" << endl;
		    cout << "\n\n========================================================================================================================";
	}
	else{
		cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	}
	
}while(MainChoice != 5);

	return 0;
}






void registerCustomer(string &customerName , string &contactNumber , string &orderType , int &persons)
{
    int op;
    
	cout << "================================================ CUSTOMER REGISTRATION ================================================" << endl ;
	
    cout << "\n\tEnter Customer Name: ";
    cin >> customerName;

    cout << "\tEnter Contact Number: ";
    cin >> contactNumber;
    
    cout << "\tEnter Number of Persons: ";
    cin >> persons;
	
do{  
    cout << "\n\tEnter Order Type :" << endl;
    cout << "\t1. Dine-in " << endl;
    cout << "\t2.Takeaway " << endl;
    cout << "\n\t\tEnter Choice : " ;
    cin >> op ;
    if(op==1)
	{
    	orderType = "Dine-in";
	} 
	else if(op==2)
	{
		orderType = "Takeaway";
	}
	else
	{
		cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
	}
}while(op != 1  &&  op != 2);

    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    cout << "\n\t\t\t\t\t>>>Customer Registered Successfully<<<\n";
}

void displayMenu()
{
    cout << "\n\n====================================================== MAIN MENU ======================================================\n" << endl ;

    cout << "\n\t1. View Food Menu " << endl ;
    cout << "\t2. Place Order " << endl ;
    cout << "\t3. Calculate Bill " << endl ;
    cout << "\t4. View Customer Details " << endl ;
    cout << "\t5. Exit " << endl ;

    cout << "\n\t\tEnter Your Choice: ";
}

void displayFoodMenu(string foodItems[] , double prices[] , int size)
{
    cout << "\n\n====================================================== FOOD MENU ======================================================\n" << endl ;
    
    for(int i = 0; i < size; i++)
    {
        cout << "\n\t" << i + 1 << ". " << foodItems[i] << " - Rs. " << prices[i] << endl;
    }
}

double placeOrder(string foodItems[] , double prices[] , int size)
{
    int itemNo, quantity;
    char choice;

    double total = 0;
	
	cout << "\n\n===================================================== PLACE ORDER =====================================================\n" << endl ;
        
        for(int i = 0; i < size; i++)
    {
        cout << "\n\t" << i + 1 << ". " << foodItems[i] << " - Rs. " << prices[i] << endl;
    }

    do
    {
    cout << "\n\t\tEnter Item Number: ";
    cin >> itemNo;

    cout << "\t\tEnter Quantity: ";
    cin >> quantity;

    if(itemNo >= 1 && itemNo <= size)
    {
        total += prices[itemNo - 1] * quantity;

    cout << "\n\t\t\t\t\t               >>>Items Added Successfully<<<\n";
    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    }
    else
    {
		cout << "\n\t\t\t\t   >>>Invalid Item Number. Please Try Again<<<" << endl ;
		cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    }

        cout << "\n\t\tDo you want to order more? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return total;
}

double calcServiceCharges(double foodBill , string orderType)
{
    if(orderType == "Dine-in")
    {
        return foodBill * 0.10;
    }
    else
    {
        return foodBill * 0.05;
    }
}

double calcGST(double amount)
{
    return amount * 0.16;
}

double calcDiscount(double amount)
{
    if(amount >= 3000 && amount <= 5000)
    {
        return amount * 0.05;
    }
    else if(amount >= 5001 && amount <= 10000)
    {
        return amount * 0.10;
    }
    else if(amount > 10000)
    {
        return amount * 0.15;
    }
    else
    {
        return 0;
    }
}

void displayBill(string customerName , string orderType , int persons , double foodBill , double serviceCharges , double gst,
                      double discount , double totalBill)
{
    cout << fixed << setprecision(2);

    cout << "\n\n=================================================== RESTAURANT BILL ===================================================\n" << endl ;

    cout << "\tCustomer Name: " << customerName << endl;

    cout << "\tOrder Type: " << orderType << endl;

    cout << "\tNumber of Persons: " << persons << endl;

    cout << "\n\tFood Bill: Rs. " << foodBill << endl;

    cout << "\tService Charges: Rs. " << serviceCharges << endl;

    cout << "\tGST: Rs. " << gst << endl;

    cout << "\tDiscount: Rs. " << discount << endl;

    if(totalBill > 5000)
    {
        cout << "\tFree Delivery Added!" << endl;
    }

    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;

    cout << "\t\tTotal Payable Amount: Rs. "
         << totalBill << endl;

    cout << "\tEnjoy Your Meal :)" << endl;

    cout << "\n\n========================================================================================================================";
}

void displayCustomerDetails(string customerName , string contactNumber , string orderType , int persons)
{
    cout << "\n\n=================================================== CUSTOMER DETAILS ===================================================" << endl;

    cout << "\n\tCustomer Name: " << customerName << endl;

    cout << "\tContact Number: " << contactNumber << endl;

    cout << "\tOrder Type:  " << orderType << endl;

    cout << "\tNumber of Persons: "<< persons << endl;

    cout << "\n\n========================================================================================================================";
}
