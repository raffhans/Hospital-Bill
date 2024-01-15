#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

// function prototypes for getting the types, cost, names
int getSurgery(int);
int getMedicine(int);
int getRoomType (int );
int NumberOfPatient(int);
double getSurgeryCost(double);
double getMedicineCost(double);
double getServiceCost(double);
double getRoomCost (double); 
int getFood(int);
double getFoodCost(double);

string SurgeryChoiceBill(string);
string MedicineChoiceBill(string);
string FoodChoiceBill(string);
string RoomChoiceBill(string);
string PatientName (string [], int);

const string SER = "3 services          "; //constant variable
	
	//	main function 
int main()
{
	int SurgeryType, MedicineType, ServiceType,RoomType;
	double SurgeryCost,MedicineCost,ServiceCost, RoomCost;
	
	int FoodType;
	double FoodCost;
	
	string SurgeryChoice, MedicineChoice, FoodChoice,RoomChoice, name;
	
	// welcome menu
	cout << "\n --------VARLEN HOSPITAL--------" << endl;
	cout << " Welcome to the hospital's billing system " << endl;
	cout << " >Enter patient name: ";
	getline(cin, name) ;
	cout << endl;

	// calling functions (surgery, medicine, service, room)
	  SurgeryType = getSurgery(SurgeryType);   // Get the type of surgery
	  SurgeryCost = getSurgeryCost(SurgeryCost); // calculate the cost of surgery
	  SurgeryChoice = SurgeryChoiceBill(SurgeryChoice);
	  
	  MedicineType = getMedicine(MedicineType); // Get the type of medicine
	  MedicineCost = getMedicineCost(MedicineCost); // calculate the cost of medicine
	  MedicineChoice = MedicineChoiceBill(MedicineChoice);
	  
	  ServiceCost = getServiceCost(ServiceCost); //Calculate the cost of service
	  
	  FoodType = getFood(FoodType);
	  FoodCost = getFoodCost(FoodCost);
	  FoodChoice = FoodChoiceBill(FoodChoice);
	  
	  RoomType = getRoomType(RoomType);
	  RoomCost = getRoomCost(RoomCost);
	  RoomChoice = RoomChoiceBill (RoomChoice);
	 
	 
	 // stay duration (not a function)
	int dayenter, monthenter, yearenter;
	int dayout, monthout, yearout;
	int dayminus, monthminus, yearminus;
	
	// getting 2 dates
	
  cout << "\n --------VARLEN HOSPITAL--------";
  
  //Date Check in
  cout << "\n >Date checked in (DD/MM/YY): ";

  cout << "\n>Day: ";
  cin >> dayenter;

  cout << ">Month: ";
  cin >> monthenter;

  cout << ">Year: ";
  cin >> yearenter;
  
  //Date Checkout
  cout << "\n >Date checked Out (DD/MM/YY): ";

  cout << "\n>Day: ";
  cin >> dayout;

  cout << ">Month: ";
  cin >> monthout;

  cout << ">Year: ";
  cin >> yearout;
  
  
	
	// comparing between 2 dates
	if (dayout < dayenter)
	{
		if (monthout==3)
		{
			if ((yearout % 4 == 0 && yearout % 100 != 0) || (yearout % 400 == 0)) 
                dayout += 29;
            
			else
                dayout += 28;							
		}
			
		else if (monthout == 0 || monthout == 2 || monthout == 4 || monthout == 6 || monthout == 9 || monthout == 13)
			dayout +=31;
	
		else 
			dayout += 30;		
		
		monthout -=	1;
	}
	
	if (monthout < monthenter)
	{
		monthout += 12;
		yearout -= 1;
	}
	
	dayminus = dayout - dayenter;
	monthminus = monthout - monthenter;
	yearminus = yearout - yearenter;
	
	cout << " total days: " << dayminus << endl; //<< " months: " << monthminus << " years: " << yearminus << endl << endl;
	
	
	// total amount for billing purpose (not a function) 
	// calculation for the amounts	
	float grandtotal, foodtotal, staytotal;
	
	staytotal = dayminus * RoomCost;
	foodtotal = dayminus * FoodCost;
	
	grandtotal = SurgeryCost + MedicineCost + ServiceCost + foodtotal + staytotal;  
	  
	// displaying the amounts
	  
	  system ("cls");
	  cout << "\n -------------------VARLEN HOSPITAL--------------------------";
	  cout << "\n                      Billing ";
	  cout << "\n Patient name: " << name;
	  cout << "\n Total days : " << dayminus << " Days";
	  cout << "\n Surgery    : " <<setw(3)<< SurgeryChoice << setw(15) << "Price: " << "RM" << fixed << setprecision(2) << SurgeryCost;
	  cout << "\n Medicine   : " << setw(3) << MedicineChoice << setw(15) << "Price: " << "RM" << fixed << setprecision(2) << MedicineCost;
	  cout << "\n Service    : " << setw(3)<<SER<< setw(15) << "Price: " << "RM" << fixed << setprecision(2) << ServiceCost;
	  cout << "\n Food       : " << setw(3)<<FoodChoice << setw(12) << " Price: "<< "RM" << fixed << setprecision(2) << FoodCost;
	  cout << "\n              " <<setw(35) << "Price: " << "RM" << fixed << setprecision(2) << foodtotal;
	  cout << "\n Room       : "<<setw(3)<< RoomChoice << setw(12) << " Price: " << "RM" << fixed << setprecision(2) << RoomCost;
	  cout << "\n ============================================================";
	  cout << "\n Grand total: " << setw(30) << "RM" << fixed << setprecision(2) << grandtotal << endl << endl;	
	  cout << " >>Thank your for using our program! " << endl  << endl;
	   
	return 0;
}

//functions

// surgery 1 - getting 1 surgery type
int getSurgery(int SurgeryType) //Surgery menu user need to choose one surgery peform
{
	int choice;
	
    cout << " --------VARLEN HOSPITAL--------";
	cout << "\n What is the type of surgery?" << endl
         << " [1] Spinal Surgery" << endl
         << " [2] Coronary Artery Bypass Surgery" << endl
         << " [3] Lobectomy Surgery " << endl
         << " [4] Fibroadenoma Surgery " << endl
         << " [5] Vascular Surgery " << endl
         << " -------------------------------" << endl;
    cout << " >Please enter number from 1 to 5: ";
    cin  >> choice;  //User need to enter char given in the menu
    while (choice < 1 || choice > 5)
    {
    	cout << " >Error! Please enter number again: ";
    	cin  >> choice;
	}
	return choice;
}

// surgery 2 - getting surgery cost
double getSurgeryCost(double SurgeryCost) // This is cost of surgery count after user choose
{
int choice;
	switch(choice)
	{
		case(1): SurgeryCost=55000.00;
	    break;
	    
	    case(2): SurgeryCost=80000.00;
	    break;
	    
	    case(3): SurgeryCost=56000.00;
	    break;
	    
	    case(4): SurgeryCost=6869.84;
	    break;
	    
	    case(5): SurgeryCost=6780.00;
	    break;
	  
	  default: ; //Do not add any charges
	}
	return SurgeryCost;
}

// medicine 1 - getting medicine type
int getMedicine(int MedicineType) //Medicine menu to choose which medicine for patient
{

	int choice;
		
    cout << "\n --------VARLEN HOSPITAL--------";
	cout << "\n What is the type of medicine?" << endl
         << " [1] Albuterol" << endl
         << " [2] Acetaminophen" << endl
         << " [3] Simvastatin " << endl
         << " [4] Amlodipine " << endl
         << " [5] Gabapentin " << endl
         << "-------------------------------" << endl;
    cout << " >Please enter number from 1 to 5: ";
    cin  >> choice;  //User need to enter char given in the menu
    while (choice < 1 || choice > 5)
    {
    	cout << " >Error! Please enter number again: ";
    	cin  >> choice;
	}
	
	return MedicineType;

}

// medicine 2 - getting medicine cost
double getMedicineCost(double MedicineCost) //Medicine cost count after choose
{
	int choice;
	switch(choice)
	{
		case(1): MedicineCost=29.80;
	    break;
	    
	    case(2): MedicineCost=73;
	    break;
	    
	    case(3): MedicineCost=6.50;
	    break;
	    
	    case(4): MedicineCost=15.60;
	    break;
	    
	    case(5): MedicineCost=13.30;
	    break;
	  
	  default: ; //Do not add any charges
	}
	return MedicineCost;
	
	}
	
// food 1 - getting food type	
	int getFood (int FoodType) //food menu user need to choose one food peform
{
	int choice;
		
    cout << " --------VARLEN HOSPITAL--------";
	cout << "\n Food Menu" << endl
         << " [1] Chicken Rice" << endl
         << " [2] Fish and chips" << endl
         << " [3] Beef stew " << endl
         << " [4] Porridge" << endl
         << " [5] Vege fried rice" << endl
         << "-------------------------------" << endl;
    cout << " >Please enter number from 1 to 5: ";
    cin  >> choice;  //User need to enter char given in the menu
    while (choice < 1 || choice > 5)
    {
    	cout << " >Error! Please enter number again: ";
    	cin  >> choice;
	}
	return FoodType;
}

// food 2 - getting food cost
double getFoodCost (double FoodCost) // This is cost of food count after user choose
{
int choice;
	switch(choice)
	{
		case(1): FoodCost=7.50;
	    break;
	    
	    case(2): FoodCost=10.00;
	    break;
	    
	    case(3): FoodCost=14.00;
	    break;
	    
	    case(4): FoodCost=8.90;
	    break;
	    
	    case(5): FoodCost=5.60;
	    break;
	  
	  default: ; //Do not add any charges
	}
	return FoodCost;
}


// service - getting 3 service types and add all costs
double getServiceCost(double ServiceCost) //Service cost count based on the choice
{
  	char choicea, choiceb, choicec;
  	double costa, costb, costc;
  	
  		
    cout << "\n --------VARLEN HOSPITAL--------";
             
	// 1
	cout << "\n (1) Emergency room service " 
		 << "\n [a] = Urgent"
		 << "\n [b] = Non-urgent"
		 << "\n [c] = Immediate"
		 << "\n >Enter letter: ";
	cin >> choicea;
	
	while (choicea < 'a' || choicea > 'c')
    {
    	cout << " >Error! Please enter letter again: ";
    	cin  >> choicea;
	}	
	
	switch (choicea)
	{
		case 'a':
			costa = 500;
		case 'b':
			costa = 300;
		case 'c':
			costa = 700;			
	}
	
	//2
	cout << "\n (2) X-ray service " 
		 << "\n [a] = Full body"
		 << "\n [b] = Chest "
		 << "\n [c] = Other parts"
		 << "\n >Enter letter: ";
	cin >> choiceb;
	
	while (choiceb < 'a' || choiceb > 'c')
    {
    	cout << "Error! Please enter letter again: ";
    	cin  >> choiceb;
	}	
	
	switch (choiceb)
	{
		case 'a':
			costb = 300;
		case 'b':
			costb = 200;
		case 'c':
			costb = 100;
	}
	
	//3
	cout << "\n (3) Blood test letter: " 
		 << "\n [a] = Complete "
		 << "\n [b] = Normal "
		 << "\n [c] = Blood clotting"
		 << "\nEnter letter: ";
	cin >> choicec;
	
	while (choicec < 'a' || choicec > 'c')
    {
    	cout << " >Error! Please enter letter again: " ;
    	cin  >> choicec;
	}	
	
	switch (choicec)
	{
		case 'a':
			costc = 200;
		case 'b':
			costc = 50;
		case 'c':
			costc = 100;
	}
	
	cout << endl;
	cout << " -------------------------------" << endl << endl;
	
	ServiceCost = costa + costb + costc;
	
	return ServiceCost;
}

// room 1 - getting room type
	int getRoomType(int RoomType) 
{
 int choice;
 	
    cout << "\n --------VARLEN HOSPITAL--------";
	cout << "\n What is the room type" << endl
         << " [1]Superior Room" << "\t" << "300"<< endl
         << " [2]Deluxe Room" << "\t\t"<<"700"<< endl
         << " [3]Luxury Room " <<"\t"<<"1200"<< endl
         << "-------------------------------" << endl;
    cout << " >Please enter number from 1 to 3: ";
    cin  >> choice;  //User need to enter char given in the menu
    while (choice < 1 || choice > 3)
    {
    	cout << " >Error! Please enter number again: ";
    	cin  >> choice;
	}
	return RoomType;
}

// room 2 - getting room cost
double getRoomCost (double RoomCost)
{
	int choice;
	switch(choice)
	{
		case(1): RoomCost = 300;
	    break;
	    
	    case(2): RoomCost = 700;
	    break;
	    
	    case(3): RoomCost = 1200;
	    break;
	    
	    
	  default: ; //Do not add any charges
	}
	return RoomCost;
}


//-------------------------------------------------------------------------------//
// surgery 3 - getting surgery name (for biliing purpose)
string SurgeryChoiceBill(string SurgeryChoice)
{
	int SurgeryType;
    switch (SurgeryType)
		
		
	{
		case(1): SurgeryChoice="Spinal Surgery      ";
	    break;                                       
	    
	    case(2): SurgeryChoice="CAB Surgery         ";
	    break;
	    
	    case(3): SurgeryChoice="Lobectomy Surgery   ";
	    break;
	    
	    case(4): SurgeryChoice="Fibroadenoma Surgery";
	    break;
	    
	    case(5): SurgeryChoice="Vascular Surgery    ";
	    break;
	  
	  default: ; //Do not add any charges
	}
	return SurgeryChoice;
}

// 	medicine 3 - getting medicine name (for billing purpose)			
string MedicineChoiceBill(string MedicineChoice)
{
	int MedicineType;
    switch (MedicineType)
		                        
	{
		case(1): MedicineChoice="Alboterol           ";
	    break;
	    
	    case(2): MedicineChoice="Acetaminophen       ";
	    break;
	    
	    case(3): MedicineChoice="Simvastatin         ";
	    break;
	    
	    case(4): MedicineChoice="Amlodipine          ";
	    break;
	    
	    case(5): MedicineChoice="Gabapentin          ";
	    break;
	  
	  default: ; //Do not add any charges
	}
	return MedicineChoice;
}

// food 3 - getting food name (for billing purpose)
string FoodChoiceBill(string FoodChoice)
{
	int FoodType;
    switch (FoodType)
		
		
	{
		case(1): FoodChoice="Chicken Rice           ";
	    break;
	    
	    case(2): FoodChoice="Fish and Chips         ";
	    break;
	    
	    case(3): FoodChoice="Beef Stew              ";
	    break;
	    
	    case(4): FoodChoice="Porridge               ";
	    break;
	    
	    case(5): FoodChoice="Vege Fried Rice        ";
	    break;
	  
	  default: ; //Do not add any charges
	}
	return FoodChoice;
		}

// room 3 - getting room name (for billing purpose)
string RoomChoiceBill(string RoomChoice)
{
	int RoomType;
    switch (RoomType)
		
		
	{
		case(1): RoomChoice="Superior Room          ";
	    break;
	    
	    case(2): RoomChoice="Deluxe Room            ";
	    break;
	    
	    case(3): RoomChoice="Luxury Room            ";
	    break;
	    
	    
	  
	  default: ; //Do not add any charges
	}
	return RoomChoice;
		}
		
int NumberOfPatient (int patient )
{
	cout << "How many patient: " << endl;
	cin  >> patient;
	
	while(patient < 0)
	{
		cout << "\nPlease enter number of patient again: ";
		cin  >> patient;
	}
	return patient;
}

string* PatientName(int patient)
{
    cout << "\n>Enter patient names: ";
    string* patientNames = new string[patient];  // Dynamically allocate an array of strings

    for (int x = 0; x < patient; x++)
    {
        cout << (x + 1) << ") ";
        getline(cin, patientNames[x]);
    }

    cout << endl;

    return patientNames;
}

