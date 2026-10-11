
//                                           "CCP PROJECT"
//                                 "RESTURANT MANAGEMENT SYSTEM / APP"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ITEMS = 60;
const int MAX_ORDERS = 300;

// ---------- STRUCTURES ----------
struct FoodItem 
{
    int id;
    string name;
    double price;
    int stock;
};

struct Order
{
    int orderID;
    int itemID;
    string itemName;
    int quantity;
    double totalPrice;
    string status;
    string waiter;
};

// ---------- GLOBAL DATA ----------
FoodItem menu[MAX_ITEMS];
Order orders[MAX_ORDERS];
int itemCount=0;
int orderCount=0;
int nextOrderID=1001;

// ---------- FUNCTION DECLARATIONS ----------
void loadMenu();
void saveMenu();
void displayMenu();
void searchFood();
void placeOrder();
void viewOrders();
void searchOrder();
void updateOrderStatus();
void generateBill();
void viewInventory();
void mainMenu();

// ---------- LOAD MENU ----------
void loadMenu() 
{
    ifstream file("menu.txt");
    if (!file) 
    {
        ofstream out("menu.txt");
        string names[60] = {
            "Burger_Classic","Burger_Cheese","Burger_Zinger","Burger_BBQ",
            "Pizza_Tikka","Pizza_Fajita","Pizza_Pepperoni","Pizza_Cheese",
            "Shawarma_Chicken","Shawarma_Beef","Fries_Simple","Fries_Masala","Fries_Loaded",
            "Chicken_Karahi_Half","Chicken_Karahi_Full","Mutton_Karahi","Chicken_Handi",
            "Biryani_Chicken","Biryani_Beef","Pulao","Nihari","Haleem","Daal_Chawal",
            "Club_Sandwich","Grilled_Sandwich","Chicken_Roll","Beef_Roll",
            "Nuggets","Hot_Wings","Chicken_Patties",
            "Cola","Sprite","Fanta","Water","Energy_Drink",
            "Chocolate_Shake","Vanilla_Shake","Strawberry_Shake","Mango_Shake","Banana_Shake",
            "Orange_Juice","Apple_Juice","Mango_Juice","Pineapple_Juice","Watermelon_Juice",
            "IceCream_Vanilla","IceCream_Chocolate","IceCream_Strawberry","IceCream_Mango",
            "Brownie","Chocolate_Cake","Gulab_Jamun","Kheer",
            "Tea","Coffee","Hot_Chocolate",
            "Extra_Item_1","Extra_Item_2","Extra_Item_3","Extra_Item_4"
        };

        double prices[60]={
            550,610,700,720,
            1550,1450,1500,1450,
            320,450,150,180,350,
            1700,3400,2650,1800,
            400,650,380,900,450,320,
            420,560,200,250,
            250,300,200,
            120,120,120,80,250,
            500,450,500,450,450,
            250,220,240,280,270,
            320,350,350,320,
            250,1350,180,300,
            100,350,450,
            0,0,0,0
        };

        for(int i=0; i<60; i++)
        {
            out<<i+1<<" "<<names[i]<<" "<<prices[i]<<" 100\n";
        }
        out.close();
        file.open("menu.txt");
    }

    while(file>>menu[itemCount].id>>menu[itemCount].name>>menu[itemCount].price>>menu[itemCount].stock)
    {
        itemCount++;
    }
    file.close();
}

// ---------- SAVE MENU ----------
void saveMenu()
{
    ofstream file("menu.txt");
    for(int i=0; i<itemCount; i++)
    {
        file<<menu[i].id<<" "<<menu[i].name<<" "<<menu[i].price<<" "<<menu[i].stock<<endl;
    }
    file.close();
}

// ---------- DISPLAY MENU ----------
void displayMenu()
{
    cout << "\n================= FOOD MENU =================\n";

    cout << left << setw(5) << "ID"
         << setw(25) << "Item"
         << setw(10) << "Price"
         << setw(10) << "Stock" << endl;

    // ---------- FAST FOOD ----------
    cout << "\n----------------- FAST FOOD -----------------\n";
    cout << "\n";

    for(int i=0; i<itemCount; i++)
    {
        if(menu[i].name.find("Burger")!=string::npos ||
           menu[i].name.find("Pizza")!=string::npos ||
           menu[i].name.find("Sandwich")!=string::npos ||
           menu[i].name.find("Roll")!=string::npos ||
           menu[i].name.find("Fries")!=string::npos ||
           menu[i].name.find("Nuggets")!=string::npos ||
           menu[i].name.find("Wings")!=string::npos ||
           menu[i].name.find("Patties")!=string::npos)
        {
            cout<<setw(5)<<menu[i].id
                <<setw(25)<<menu[i].name
                <<setw(10)<<menu[i].price
                <<setw(10)<<menu[i].stock<<endl;
        }
    }

    // ---------- DESI FOOD ----------
    cout << "\n---------------- DESI FOOD ----------------\n";
    cout << "\n";

    for(int i=0; i<itemCount; i++)
    {
        if(menu[i].name.find("Karahi")!=string::npos ||
           menu[i].name.find("Handi")!=string::npos ||
           menu[i].name.find("Biryani")!=string::npos ||
           menu[i].name.find("Pulao")!=string::npos ||
           menu[i].name.find("Nihari")!=string::npos ||
           menu[i].name.find("Haleem")!=string::npos ||
           menu[i].name.find("Daal")!=string::npos ||
           menu[i].name.find("Kheer")!=string::npos ||
           menu[i].name.find("Gulab")!=string::npos)
        {
            cout<<setw(5)<<menu[i].id
                <<setw(25)<<menu[i].name
                <<setw(10)<<menu[i].price
                <<setw(10)<<menu[i].stock<<endl;
        }
    }

    // ---------- BBQ / GRILL ----------
    cout << "\n---------------- BBQ / GRILL ---------------\n";
    cout << "\n";

    for(int i=0; i<itemCount; i++)
    {
			if(menu[i].name.find("Tikka")!=string::npos ||
  			   menu[i].name.find("Shawarma")!=string::npos ||
   			   menu[i].name.find("Grilled")!=string::npos)
        {
            cout<<setw(5)<<menu[i].id
                <<setw(25)<<menu[i].name
                <<setw(10)<<menu[i].price
                <<setw(10)<<menu[i].stock<<endl;
        }
    }

    // ---------- DRINKS ----------
    cout << "\n------------------ DRINKS ------------------\n";
    cout << "\n";

    for(int i=0; i<itemCount; i++)
    {
        if(menu[i].name.find("Cola")!=string::npos ||
           menu[i].name.find("Sprite")!=string::npos ||
           menu[i].name.find("Fanta")!=string::npos ||
           menu[i].name.find("Water")!=string::npos ||
           menu[i].name.find("Juice")!=string::npos ||
           menu[i].name.find("Tea")!=string::npos ||
           menu[i].name.find("Coffee")!=string::npos ||
           menu[i].name.find("Hot_Chocolate")!=string::npos)
        {
            cout<<setw(5)<<menu[i].id
                <<setw(25)<<menu[i].name
                <<setw(10)<<menu[i].price
                <<setw(10)<<menu[i].stock<<endl;
        }
    }

    // ---------- ICE CREAM & SHAKES ----------
    cout << "\n------------ ICE CREAM & SHAKES ------------\n";
    cout << "\n";

    for(int i=0; i<itemCount; i++)
    {
        if(menu[i].name.find("IceCream")!=string::npos ||
           menu[i].name.find("Shake")!=string::npos)
        {
            cout<<setw(5)<<menu[i].id
                <<setw(25)<<menu[i].name
                <<setw(10)<<menu[i].price
                <<setw(10)<<menu[i].stock<<endl;
        }
    }
}

// ---------- SEARCH FOOD ----------
void searchFood()
{
    string name;
    cout<<"Enter Item Name: ";
    cin>>name;

    for(int i=0; i<itemCount; i++)
    {
        if(menu[i].name == name)
        {
            cout<<"\nItem: "<<menu[i].name<<" | Price: "<<menu[i].price<<" | Stock: "<<menu[i].stock<<endl;
            return;
        }
    }
    cout<<"Item not found!\n";
}

// ---------- PLACE ORDER ----------
void placeOrder()
{
    int numItems;
    displayMenu();
    cout<<"\nHow many items to order? ";
    cin>>numItems;

    for(int n=0; n<numItems; n++)
    {
        string itemName;
        int qty;
        bool found = false;

        cout<<"\nEnter Item Name: ";
        cin>>itemName;
        cout<<"Enter Quantity: ";
        cin>>qty;

        for(int i=0; i<itemCount; i++)
        {
            if(menu[i].name == itemName)
            {
                found = true;
                if(menu[i].stock<qty)
                {
                    cout<<"Insufficient stock!\n";
                    n--;
                    break;
                }

                orders[orderCount].orderID = nextOrderID;
                orders[orderCount].itemID = menu[i].id;
                orders[orderCount].itemName = menu[i].name;
                orders[orderCount].quantity = qty;
                orders[orderCount].totalPrice = qty*menu[i].price;
                orders[orderCount].status = "Pending";
                orders[orderCount].waiter = "";

                menu[i].stock -= qty;
                saveMenu();
                orderCount ++;

                cout<<"Item added.\n";
                break;
            }
        }

        if(!found)
        {
            cout<<"Invalid Item Name!\n";
            n--;
        }
    }

    string waiter;
    cout<<"\nEnter Waiter Name: ";
    cin>>waiter;

    for(int i=0; i<orderCount; i++)
    {
        if(orders[i].orderID == nextOrderID)
        {
            orders[i].waiter = waiter;
        }
    }

    cout<<"\nOrder Placed Successfully!\nOrder ID: "<<nextOrderID<<endl;
    nextOrderID ++;
}

// ---------- VIEW ORDERS ----------
void viewOrders()
{
    cout<<"\n========== ALL ORDERS ==========\n";
    for(int i=0; i<orderCount; i++)
    {
        cout<<"Order ID: "<<orders[i].orderID
            <<" | Item: "<<orders[i].itemName
            <<" | Qty: "<<orders[i].quantity
            <<" | Total: "<<orders[i].totalPrice
            <<" | Status: "<<orders[i].status
            <<" | Waiter: "<<orders[i].waiter<<endl;
    }
}

// ---------- SEARCH ORDER ----------
void searchOrder()
{
    int id;
    cout<<"\nEnter Order ID: ";
    cin>>id;

    bool found = false;
    for(int i=0; i<orderCount; i++)
    {
        if(orders[i].orderID == id)
        {
            found = true;
            cout<<"\n"<<orders[i].itemName<<" | Qty: "<<orders[i].quantity
                <<" | Total: "<<orders[i].totalPrice
                <<" | Status: "<<orders[i].status<<endl;
        }
    }
    if(!found) cout<<"Order not found!\n";
}

// ---------- UPDATE ORDER STATUS ----------
void updateOrderStatus()
{
    int id;
    cout<<"\nEnter Order ID: ";
    cin>>id;

    cout<<"1. Pending\n2. Preparing\n3. Completed\n";
    int ch;
    cin>>ch;

    string newStatus;
    if(ch==1)newStatus ="Pending";
    else if(ch==2)newStatus ="Preparing";
    else if(ch==3)newStatus ="Completed";
    else return;

    bool found = false;
    for(int i=0; i<orderCount; i++)
    {
        if(orders[i].orderID == id)
        {
            orders[i].status = newStatus;
            found = true;
        }
    }

    if(found) cout<<"Status updated successfully!\n";
    else cout<<"Order not found!\n";
}

// ---------- GENERATE BILL ----------
void generateBill()
{
    int id;
    cout<<"Enter Order ID: ";
    cin>>id;

    ofstream billFile("bills.txt", ios::app);   // 👈 bill file

    double totalAmount=0;
    bool anyCompleted = false;
    string waiterName ="";
    int serial =1;

    cout<<"\n==========================================================\n";
    cout<<"                       RESTAURANT BILL            \n";
    cout<<"==========================================================\n";

    billFile<<"\n==========================================================\n";
    billFile<<"                       RESTAURANT BILL            \n";
    billFile<<"==========================================================\n";

    cout<<left<<setw(5)<<"S.No"<<setw(25)<<"Item"<<setw(10)<<"Qty"
        <<setw(10)<<"Price"<<setw(10)<<"Total"<<endl;

    billFile<<left<<setw(5)<<"S.No"<<setw(25)<<"Item"<<setw(10)<<"Qty"
            <<setw(10)<<"Price"<<setw(10)<<"Total"<<endl;

    cout<<"----------------------------------------------------------\n";
    billFile<<"----------------------------------------------------------\n";

    for(int i=0; i<orderCount; i++)
    {
        if(orders[i].orderID == id && orders[i].status == "Completed")
        {
            anyCompleted = true;
            double itemTotal = orders[i].totalPrice;
            totalAmount += itemTotal;

            if(waiterName=="")
                waiterName = orders[i].waiter;

            cout<<setw(5)<<serial
                <<setw(25)<<orders[i].itemName
                <<setw(10)<<orders[i].quantity
                <<setw(10)<<orders[i].totalPrice/orders[i].quantity
                <<setw(10)<<itemTotal<<endl;

            billFile<<setw(5)<<serial
                    <<setw(25)<<orders[i].itemName
                    <<setw(10)<<orders[i].quantity
                    <<setw(10)<<orders[i].totalPrice/orders[i].quantity
                    <<setw(10)<<itemTotal<<endl;

            serial++;
        }
    }

    if(anyCompleted)
    {
        cout<<"----------------------------------------------------------\n";
        cout<<setw(50)<<"TOTAL AMOUNT: "<<totalAmount<<endl;
        cout<<"Waiter: "<<waiterName<<endl;

        billFile<<"----------------------------------------------------------\n";
        billFile<<"TOTAL AMOUNT: "<<totalAmount<<endl;
        billFile<<"Waiter: "<<waiterName<<endl;
        billFile<<"Order ID: "<<id<<endl;
        billFile<<"==========================================================\n";
    }
    else
    {
        cout<<"Order not completed or not found!\n";
        billFile<<"Order ID "<<id<<" not completed or not found!\n";
    }

    billFile.close();   // 👈 file band
}


// ---------- VIEW INVENTORY ----------
void viewInventory()
{
    cout<<"\n===============================================\n";
    cout<<"                 INVENTORY STATUS          \n";
    cout<<"===============================================\n";
    cout<<left<<setw(5)<<"ID"<<setw(25)<<"Item"<<setw(10)<<"Stock"<<setw(10)<<"Price"<<endl;
    cout<<"-----------------------------------------------\n";

    for(int i=0; i<itemCount; i++)
    {
        cout<<setw(5)<<menu[i].id<<setw(25)<<menu[i].name<<setw(10)<<menu[i].stock<<setw(10)<<menu[i].price<<endl;
    }
}

// ---------- MAIN MENU ----------
void mainMenu()
{
    int choice;
    do
    {
        cout<<"\n=============== RESTAURANT MANAGEMENT SYSTEM ===============\n";
        cout<<"1. View Menu"<<endl;
		cout<<"2. Search Food"<<endl;
		cout<<"3. Place Order"<<endl;
		cout<<"4. View Orders"<<endl;
		cout<<"5. Search Order"<<endl;
		cout<<"6. Update Order Status"<<endl;
		cout<<"7. Generate Bill"<<endl;
		cout<<"8. View Inventory"<<endl;
		cout<<"9. Exit System\n"<<endl;
		
		cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
		 	displayMenu();
			break;
        case 2: 
			searchFood();
			break;
        case 3: 
			placeOrder(); 
			break;
        case 4:
			viewOrders(); 
			break;
        case 5:
			searchOrder();
			break;
        case 6: 
			updateOrderStatus(); 
			break;
        case 7: 
			generateBill();
			break;
        case 8:
			viewInventory();
			break;
        case 9:
			cout<<"Exiting...\nThank You! For Using The System :) ";
			break;
        default:
			cout<<"Invalid choice!\n";
        }
        
    } while(choice!=9);
}

// ---------- MAIN FUNCTION ----------
int main()
{
    loadMenu();
    mainMenu();
    return 0;
}
