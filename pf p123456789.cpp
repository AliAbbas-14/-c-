#include <iostream>
#include <fstream>
#include <iomanip> // For formatting output
#include <string>
using namespace std;
// Maximum number of medicines
const int MAX_MEDICINES = 100;
// Arrays to store medicine names and quantities
string medicineNames[MAX_MEDICINES];
int medicineQuantities[MAX_MEDICINES];
int numMedicines = 0;
// Define or include necessary variables or headers for suppliers and customers
const int MAX_SUPPLIERS = 100; // For example, define maximum number of suppliers
const int MAX_CUSTOMERS = 100; // For example, define maximum number of customers
string supplierNames[MAX_SUPPLIERS]; // Array to store supplier names
int numSuppliers = 0; // Variable to track number of suppliers
string customerNames[MAX_CUSTOMERS]; // Array to store customer names
string customerContactInfo[MAX_CUSTOMERS]; // Array to store customer contact info
int numCustomers = 0; // Variable to track number of customers
// Global variables for sales and expenses tracking
double daily_sales = 0.0;
double weekly_sales = 0.0;
double monthly_sales = 0.0;
double expenses = 0.0;
double daily_purchases_total = 0.0;
double weekly_purchases_total = 0.0;
double monthly_purchases_total = 0.0;
// Function prototypes
void welcome();
void main_menu();
void bill();
void about();
void medicine();
void medi_sale();
void stock();
void update_stock();
void medi_entry();
void medi_search();
void remainder();
void supplier();
void supp_entry();
void supp_list();
void sup_update();
void search_id();
void customer();
void cust_search();
void search_cname();
void cust_entry();
void cust_list();
void cust_update();
void report_menu();
void report();
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();
void enter_daily_data();
void reset_daily_data();
void update_weekly_monthly_sales();
void update_weekly_monthly_purchases();

// Function to write bill details to a file
void write_bill_to_file(double totalCost) {
    ofstream billFile("bill_slip.txt", ios::app);
    if (billFile.is_open()) {
        billFile << "Total Cost: $" << totalCost << endl;
        billFile.close();
    }
    else {
        cout << "Unable to open file for writing bill." << endl;
    }
}

// Function to write about menu details to a file
void write_about_to_file() {
    ofstream aboutFile("about_menu.txt");
    if (aboutFile.is_open()) {
        aboutFile << "\nPharmacy System Management purpose\n";
        aboutFile << "1. The Pharmacy System Management manages medicine name or medicine quantity.\n";
        aboutFile << "2. It saves the data and record of patients in history.\n";
        aboutFile << "3. It has a record of the medicine sales cost and it helps in improving efficiency.\n";
        aboutFile << "4. It reduces errors and enhances customer service.\n";
        aboutFile << "\nPharmacy System Management Features\n";
        aboutFile << "1. Inventory Management\n";
        aboutFile << "2. Sales Management\n";
        aboutFile << "3. Purchase Management\n";
        aboutFile << "4. Reporting and Analytics\n";
        aboutFile << "5. Customer Management\n";
        aboutFile << "\nTHE DEVELOPER OF MEDICAL STORE MANAGEMENT SYSTEM IS ALI ABBASS\n";
        aboutFile.close();
    }
    else {
        cout << "Unable to open file for writing about menu." << endl;
    }
}

// Function to write medicine details to a file
void write_medicine_to_file(const string& filename) {
    ofstream medicineFile(filename, ios::app); // Use the provided filename parameter
    if (medicineFile.is_open()) {
        medicineFile << "\nMedicine Details:\n";
        for (int i = 0; i < numMedicines; ++i) {
            medicineFile << "Medicine Name: " << medicineNames[i] << ", Quantity: " << medicineQuantities[i] << endl;
        }
        medicineFile.close();
        cout << "Medicine details have been successfully written to the file." << endl;
    }
    else {
        cout << "Unable to open file for writing medicine details." << endl;
    }
}


// Function to write supplier details to a file
void write_supplier_to_file() {
    ofstream supplierFile("supplier_details.txt");
    if (supplierFile.is_open()) {
        supplierFile << "\nSupplier Details:\n";
        for (int i = 0; i < numSuppliers; ++i) {
            supplierFile << i + 1 << ". " << supplierNames[i] << endl;
        }
        supplierFile.close();
    }
    else {
        cout << "Unable to open file for writing supplier details." << endl;
    }
}

// Function to write customer details to a file
void write_customer_to_file() {
    ofstream customerFile("customer_details.txt");
    if (customerFile.is_open()) {
        customerFile << "\nCustomer Details:\n";
        for (int i = 0; i < numCustomers; ++i) {
            customerFile << i + 1 << ". " << customerNames[i] << " (" << customerContactInfo[i] << ")" << endl;
        }
        customerFile.close();
    }
    else {
        cout << "Unable to open file for writing customer details." << endl;
    }
}

// Function to write report details to a file
void write_report_to_file() {
    ofstream reportFile("report_details.txt");
    if (reportFile.is_open()) {
        reportFile << "\nReport Details:\n";
        reportFile << "Daily Sales: $" << daily_sales << endl;
        reportFile << "Weekly Sales: $" << weekly_sales << endl;
        reportFile << "Monthly Sales: $" << monthly_sales << endl;
        reportFile << "Daily Purchases: $" << daily_purchases_total << endl;
        reportFile << "Weekly Purchases: $" << weekly_purchases_total << endl;
        reportFile << "Monthly Purchases: $" << monthly_purchases_total << endl;
        reportFile.close();
    }
    else {
        cout << "Unable to open file for writing report details." << endl;
    }
}

int main() {
    system("color 0a");
    cout << "\t\t\t----------------------------------------------------------------" << endl;
    cout << "\t\t\t            | [ Programming fundamentl Final Project] | " << endl;
    cout << "\t\t\t----------------------------------------------------------------" << endl << endl << endl;
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t            | [Ali Abbas] | " << endl;
    cout << "\t\t\t---------------------------------------" << endl << endl << endl;
    cout << "\t\t\t------------------------------------------------------------------------" << endl;
    cout << "\t\t\t| [****$WELCOME TO The Medical store system developed by ALI ABBASS$****] | " << endl;
    cout << "\t\t\t-------------------------------------------------------------------------" << endl << endl << endl;
    welcome();
    main_menu();
    return 0;
}

void welcome() {
    // Display a welcome message
    cout << "\t\t\tWelcome to Pharmacy System Management\n\n\n" << endl;
    cout << "\t\t\tManage by ALI abbas\n\n";
}

void main_menu() {
    int choice;
    // Display main menu options
    cout << "Main Menu" << endl;
    cout << "1. Bill" << endl;
    cout << "2. About" << endl;
    cout << "3. Medicine Menu" << endl;
    cout << "4. Supplier Menu" << endl;
    cout << "5. Customer Menu" << endl;
    cout << "6. Report Menu" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Handle user's choice
    switch (choice) {
    case 1:
        bill();
        break;
    case 2:
        about();
        break;
    case 3:
        medicine();
        break;
    case 4:
        supplier();
        break;
    case 5:
        customer();
        break;
    case 6:
        report_menu();
        break;
    case 7:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        main_menu();
    }
}

void bill() {
    // Implement billing process
   /*double unitCost, salesCost;
    int quantity;

    // Ask user for input
    cout << "Enter the unit cost of the medicine: ";
    cin >> unitCost;
    cout << "Enter the sales cost of the medicine: ";
    cin >> salesCost;
    cout << "Enter the quantity of medicine: ";
    cin >> quantity;
    // Calculate total cost
    double totalCost = (unitCost + salesCost) * quantity;

    // Display the total cost
    cout << "The total cost of the medicine is: " << totalCost << endl;

    // Write bill details to file
    write_bill_to_file(totalCost);/**/
    double unitCost, salesCost, totalCost = 0; // Initialize totalCost with 0
    int quantity;

   
    while (true) {
        // Ask user for input
        cout << "Enter the unit cost of the medicine (or -1 to finish): ";
        cin >> unitCost;

       
        if (unitCost == -1)
            break;

        cout << "Enter the sales cost of the medicine: ";
        cin >> salesCost;
        cout << "Enter the quantity of medicine: ";
        cin >> quantity;

       
        double transactionTotal = (unitCost + salesCost) * quantity;
        totalCost += transactionTotal; 

       
        cout << "The total cost of the medicine is: $" << transactionTotal << endl;
    }

    // Display the total daily sales
    cout << "Total Daily Sales: $" << totalCost << endl;

    // Write daily sales report to file
    write_bill_to_file(totalCost);

 
}

void about() {
    // Display information about the system
    cout << "\n\t\t\t\t\t*****Pharmacy System Management purpose*****";
    cout << "\n1. The Pharmacy System Management manages medicine name or medicine quantity.\n";
    cout << "2. It saves the data and record of patients in history. ";
    cout << "\n3. It has a record of the medicine sales cost and it helps in improving efficiency.";
    cout << "\n4. It reduces errors and enhances customer service.\n\n";

    cout << "\t\t\t\t\t*****Pharmacy System Management Features*****";
    cout << "\nIt has different Features as follows: ";
    cout << "\n1. Inventory Management";
    cout << "\n2. Sales Management";
    cout << "\n3. Purchase Management";
    cout << "\n4. Reporting and Analytics";
    cout << "\n5. Customer Management\n\n";
    cout << "\t\t$$$$$ THE DEVELOPER OF MEDICAL STORE MANAGEMENT SYSTEM IS ALI ABBASS $$$$$\n\n ";

    // Write about menu details to file
    write_about_to_file();
}

void medicine() {
    // Implement medicine-related operations
    int choice1;
    do {
        cout << "MEDICINE MENU:" << endl;
        cout << "1. Medicine entry " << endl;
        cout << "2. Medicine stock" << endl;
        cout << "3. Medicine update stock " << endl;
        cout << "4. Medicine sale " << endl;
        cout << "5. Medicine search" << endl;
        cout << "6. Medicine remainder" << endl;
        cout << "7. Main menu " << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice1;

        switch (choice1) {
        case 1:
            medi_entry();
            break;
        case 2:
            stock();
            break;
        case 3:
            update_stock();
            break;
        case 4:
            medi_sale();
            break;
        case 5:
            medi_search();
            break;
        case 6:
            remainder();
            break;
        case 7:
            main_menu();
            break;
        case 8:
            cout << "Exiting..." << endl;
            cout << "\n******************************************************************************************\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 7." << endl;
        }
    } while (choice1 != 8);
}

void medi_sale() {
    // Handle sale of medicines
    int amount_medicines;
    cout << "Enter the amount of the medicines: ";
    cin >> amount_medicines;
    // Write medicine details to file
    write_medicine_to_file("medicine_details.txt");

}

void stock() {
    // Display current stock of medicines
    cout << "\t\t\nFollowing medicine current stock available in the inventory.\n\n";
    string str;
    for (int i = 1; i <= 10; i++) {
        cout << "\nEnter the " << i << " medicine name:\n ";
        cin >> str;
    }

    // Write medicine details to file
    write_medicine_to_file("medicine_details.txt");

}

void update_stock() {
    // Function to update the stock of a specific medicine
    int medicineIndex;
    cout << "Enter the index of the medicine you want to update: ";
    cin >> medicineIndex;

    if (medicineIndex >= 0 && medicineIndex < MAX_MEDICINES) {
        string newName;
        cout << "Enter the updated name for the medicine: ";
        cin >> newName;

        // Update the name of the medicine at the specified index
        medicineNames[medicineIndex] = newName;
        cout << "Medicine updated successfully!" << endl;
    }
    else {
        cout << "Invalid medicine index!" << endl;
    }
    // Write medicine details to file
    write_medicine_to_file("medicine_details.txt");

}

void medi_entry() {
    // Allow user to add new medicines to inventory
    int n;
    cout << "Enter the number of medicines you want to enter: ";
    cin >> n;

    ofstream medicineFile("New.txt", ios::app); // Open the file for appending

    if (medicineFile.is_open()) {
        for (int i = 1; i <= n; i++) {
            int id;
            cout << "Enter the " << i << " medicine ID:";
            cin >> id;
            string medicine_name;
            cout << "Enter the " << i << " medicine name: ";
            cin >> medicine_name;
            int Rack_NO;
            cout << "Enter the " << i << " Rack number:";
            cin >> Rack_NO;
            int cabinet_No;
            cout << "Enter the " << i << " cabinet number: ";
            cin >> cabinet_No;
            string company_name;
            cout << "Enter the " << i << " company name:";
            cin >> company_name;

            // Write the details of the current medicine being entered
            medicineFile << "\nMedicine Details:\n";
            medicineFile << "Medicine Name: " << medicine_name << ", Rack number: " << Rack_NO << ", Cabinet number: " << cabinet_No << ", Company name: " << company_name << endl;
        }
        medicineFile.close(); // Close the file after all medicines have been entered
        cout << "Medicine details have been successfully written to the file." << endl;
    }
    else {
        cout << "Unable to open file for writing medicine details." << endl;
    }

    // Write medicine details to file
    write_medicine_to_file("medicine_details.txt");
}


void medi_search() {
    // Function to search for medicines by name
    string searchName;
    cout << "Enter the name of the medicine to search: ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < numMedicines; ++i) {
        if (medicineNames[i] == searchName) {
            cout << "Medicine found: " << medicineNames[i] << ", Quantity: " << medicineQuantities[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Medicine not found." << endl;
    }
    // Write medicine details to file
    write_medicine_to_file("medicine_details.txt");

}

void remainder() {
    // Function to display reminders for medicines running low in stock
    cout << "Medicines running low in stock: " << endl;
    for (int i = 0; i < numMedicines; ++i) {
        if (medicineQuantities[i] < 10) { // Example threshold for low stock, adjust as needed
            cout << "Name: " << medicineNames[i] << ", Quantity: " << medicineQuantities[i] << endl;
        }
    }
    // Write medicine details to file
    write_medicine_to_file("medicine_details.txt");

}

// Function to handle supplier operations
void supplier() {
    int choice2;
    do {
        cout << "SUPPLIER MENU:" << endl;
        cout << "1. Supplier entry " << endl;
        cout << "2. Supplier list " << endl;
        cout << "3. Supplier update" << endl;
        cout << "4. Search by ID" << endl;
        cout << "5. Main menu " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice2;

        switch (choice2) {
        case 1:
            supp_entry();
            break;
        case 2:
            supp_list();
            break;
        case 3:
            sup_update();
            break;
        case 4:
            search_id();
            break;
        case 5:
            cout << "Returning to the main menu..." << endl;
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    } while (choice2 != 5 && choice2 != 6);
}

void supp_entry() {
    int numNewSuppliers;
    cout << "Enter the number of suppliers you want to enter: ";
    cin >> numNewSuppliers;

    for (int i = 0; i < numNewSuppliers; i++) {
        if (numSuppliers >= MAX_SUPPLIERS) {
            cout << "Maximum number of suppliers reached!" << endl;
            break;
        }

        string name;
        cout << "Enter the name of supplier " << i + 1 << ": ";
        cin >> name;

        supplierNames[numSuppliers] = name;
        numSuppliers++;
    }

    // Write supplier details to file
    write_supplier_to_file();
}

void supp_list() {
    if (numSuppliers == 0) {
        cout << "No suppliers available." << endl;
    }
    else {
        cout << "List of suppliers:" << endl;
        for (int i = 0; i < numSuppliers; i++) {
            cout << i + 1 << ". " << supplierNames[i] << endl;
        }
    }
}

void sup_update() {
    if (numSuppliers == 0) {
        cout << "No suppliers available to update." << endl;
    }
    else {
        int index;
        cout << "Enter the index of the supplier you want to update: ";
        cin >> index;

        if (index < 1 || index > numSuppliers) {
            cout << "Invalid index!" << endl;
        }
        else {
            string newName;
            cout << "Enter the updated name for supplier " << index << ": ";
            cin >> newName;

            supplierNames[index - 1] = newName;
            cout << "Supplier updated successfully!" << endl;
        }
    }
}

void search_id() {
    if (numSuppliers == 0) {
        cout << "No suppliers available to search." << endl;
    }
    else {
        int index;
        cout << "Enter the index of the supplier you want to search: ";
        cin >> index;

        if (index < 1 || index > numSuppliers) {
            cout << "Invalid index!" << endl;
        }
        else {
            cout << "Supplier found at index " << index << ": " << supplierNames[index - 1] << endl;
        }
    }
}

// Function to handle customer operations
void customer() {
    int choice3;
    do {
        cout << "CUSTOMER MENU:" << endl;
        cout << "1. Customer entry " << endl;
        cout << "2. Customer list " << endl;
        cout << "3. Customer update" << endl;
        cout << "4. Search by Name" << endl;
        cout << "5. Main menu " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice3;

        switch (choice3) {
        case 1:
            cust_entry();
            break;
        case 2:
            cust_list();
            break;
        case 3:
            cust_update();
            break;
        case 4:
            search_cname();
            break;
        case 5:
            main_menu();
            break;
        case 6:
            cout << "Exiting..." << endl;
            cout << "\n******************************************************************************************\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    } while (choice3 != 6);
}

void search_cname() {
    // Allow user to search for customer based on name
    string name;
    cout << "Enter the name to search for: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < numCustomers; ++i) {
        if (customerNames[i] == name) {
            cout << "Customer Found: " << customerNames[i] << " (" << customerContactInfo[i] << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Customer with name " << name << " not found." << endl;
    }
}

void cust_entry() {
    // Allow user to enter information about a new customer
    int n;
    cout << "Enter the number of customers you want to enter: ";
    cin >> n;

    // Input new customer data
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter the " << i + 1 << " customer name: ";
        cin >> customerNames[numCustomers + i];
        cout << "Enter the contact information: ";
        cin >> customerContactInfo[numCustomers + i];
    }

    // Update number of customers
    numCustomers += n;

    // Write customer details to file
    write_customer_to_file();
}

void cust_list() {
    // Display list of all customers
    cout << "CUSTOMER LIST:" << endl;
    for (int i = 0; i < numCustomers; ++i) {
        cout << i + 1 << ". " << customerNames[i] << " (" << customerContactInfo[i] << ")" << endl;
    }
}

void cust_update() {
    // Allow user to update information of an existing customer
    int index;
    cout << "Enter the index of the customer you want to update: ";
    cin >> index;
    if (index >= 1 && index <= numCustomers) {
        cout << "Enter the updated name for customer " << index << ": ";
        cin >> customerNames[index - 1];
        cout << "Enter the updated contact information: ";
        cin >> customerContactInfo[index - 1];
    }
    else {
        cout << "Invalid index!" << endl;
    }

    // Write customer details to file
    write_customer_to_file();
}

// Function to handle report menu operations
void report_menu() {
    int choice;
    do {
        cout << "\nREPORT MENU\n";
        cout << "------------------------\n";
        cout << "1. Enter Daily Data\n";
        cout << "2. Generate Sales Report\n";
        cout << "3. Generate Purchase Report\n";
        cout << "4. Generate Profit Report\n";
        cout << "5. Main Menu\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            enter_daily_data();
            break;
        case 2:
            sale_rpt();
            break;
        case 3:
            pur_rpt();
            break;
        case 4:
            profit_rpt();
            break;
        case 5:
            main_menu();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);
}

void enter_daily_data() {
    // Function to enter daily sales and purchases data
    double dailySales, dailyPurchases;
    cout << "Enter total sales for the day: $";
    cin >> dailySales;
    cout << "Enter total purchases for the day: $";
    cin >> dailyPurchases;

    // Update daily sales and purchases
    daily_sales += dailySales;
    daily_purchases_total += dailyPurchases;

    // Update weekly and monthly sales and purchases
    update_weekly_monthly_sales();
    update_weekly_monthly_purchases();
}

void reset_daily_data() {
    // Reset daily sales and purchases
    daily_sales = 0.0;
    daily_purchases_total = 0.0;

    // Update weekly and monthly sales and purchases
    update_weekly_monthly_sales();
    update_weekly_monthly_purchases();
}

void update_weekly_monthly_sales() {
    // Update weekly and monthly sales based on daily sales
    weekly_sales += daily_sales;
    monthly_sales += daily_sales;
}

void update_weekly_monthly_purchases() {
    // Update weekly and monthly purchases based on daily purchases
    weekly_purchases_total += daily_purchases_total;
    monthly_purchases_total += daily_purchases_total;
}

void sale_rpt() {
    // Generate and display sales report
    cout << "SALES REPORT" << endl;
    cout << "----------------------" << endl;
    cout << "Daily Sales: $" << daily_sales << endl;
    cout << "Weekly Sales: $" << weekly_sales << endl;
    cout << "Monthly Sales: $" << monthly_sales << endl;
}

void pur_rpt() {
    // Generate and display purchase report
    cout << "PURCHASE REPORT" << endl;
    cout << "----------------------" << endl;
    cout << "Daily Purchases: $" << daily_purchases_total << endl;
    cout << "Weekly Purchases: $" << weekly_purchases_total << endl;
    cout << "Monthly Purchases: $" << monthly_purchases_total << endl;
}

void profit_rpt() {
    // Generate and display profit report
    double daily_profit = daily_sales - daily_purchases_total;
    double weekly_profit = weekly_sales - weekly_purchases_total;
    double monthly_profit = monthly_sales - monthly_purchases_total;

    cout << "PROFIT REPORT" << endl;
    cout << "----------------------" << endl;
    cout << "Daily Profit: $" << daily_profit << endl;
    cout << "Weekly Profit: $" << weekly_profit << endl;
    cout << "Monthly Profit: $" << monthly_profit << endl;
}
