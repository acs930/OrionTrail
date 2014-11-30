#include <iostream>
#include <cmath>
#include <string>
#include <unistd.h>

using namespace std;

//I can probably make this a terminal game if I have to


class player{
private:
	string name;
	int occupation;
	int condition;
	int missionChoice;

	int spaceFood;
	int spaceCredits;
	int spaceMedicine;
	int spaceTorpedos;
	int shipParts;
	int cannonParts;
	bool hasShip;

public:

	player();
	
	void setUpPlayer(string myName, int myOccupation, int myCondition, int myMission);

	string getName();
	string getOccupationName();
	string missionLookup();
	string conditionLookup();

	void setFood(int newFood);
	void setCreds(int newCreds);
	void setMeds(int newMeds);
	void setTorpedos(int newTorpedos);
	void setShip(bool haz);
	void setCanPart(int newCanPart);
	void setShipPart(int newShipPart);
	void setCondition(int newCond);

	int getOccupation();
	int getFood();
	int getCreds();
	int getMeds();
	int getTorpedos();
	int getMission();
	int getShipPart();
	int getCanPart();
	int getTotalSupplies();
	int getCondition();
	double getMissionDistance();

	bool haveShip();


	void printStats();

};

class playerShip {

private:
	double currentPosition;
	double currentVelocity;
	double currentTime;
	
	int type;
	int maxWeight;
	int currentWeight;

	int cannonShots;
	int cannonShotWidth;

	int shipUpgrades;
	int cannonUpgrades;
	

public:

	playerShip();
	void setShip(double theVel, int theType, int theMax, int theCurrent, int shipUpgrades, int cannonUpgrades);


	double getPos();
	double getVel();
	double getTime();

	int getType();
	int getCurrentWeight();
	int getMaxWeight();

	int getCannonShots();
	int getCannonShotWidth();

	int getUpgradesShip();
	int getUpgradesCannon();

	void setPos(double newPosition);
	void setVel(double newVelocity);
	void setTime(double newTime);
	void setCurrentWeight(int newCurrent);
	void setMaxWeight(int newMax);
	void setCannonShot(int newCanShot);
	void setCannonWidth(int newWidth);
	void setShipUpgrades(int newShipUpgrade);
	void setCannonUpgrades(int newCanUpgrade);

	string shipTypeLookUp(int type);

	void printStats();


};

double getReleFactor(double v);  //enter in V and it will return 1/sqrt(1-(v^2)/(c^2))

double solveTimeDil(double properTime, double velocity);  //solves time dilation problems

double solveLengthCon(double properLength, double velocity); //solves length contraction problems

double solveTime(double theLength, double velocity); //does a classical equation to solve the time it will take(will only work if all args in same inertial frame)

double solveLength(double timePassed, double velocity); //does classical equation to solve for length d = v/t

int getRandInt(int range);

double convertLightYears(double distLY);

int gameSetup();

void waitFor2();

void clear();

void upgradeShipShop();

void upgradeCannonShop();

void supplySetup();

void clearShowStats(player myGuy, playerShip myShip);

player thePlayerCharacter;

playerShip thePlayerShip;

double c = 299792458;

string occupationList[10];


	/*"Delivery Person",  //salary: 120,000  +1 condition, base(100,000) ship unlocked at start +1 ship part
	"Doctor", //salary: 400,000  start with 100 space meds
	"Admiral", //salary: 250,000 start with 100 torpedos +1 cannon part start with base ship
	"Scientist",//salary: 300,000 distance -100LY or something
	"Hunter",//salary:  350,000 wider angle shot so instead of 20degrees its 30 deg of chances to hit
	"Cat", //salary: 450,000 start with 100 food -1 condition  a superstar of the future
	"Barber",//salary: 180,000 start with 25 space med  10% store discount at bases 
	"Movie Producer", //salary: 200,000 start with 150 space med, 150 torpedo, 150 space food
	"Cook" //salary:   80,000 start with 150 food and big(150,000) ship no part unlocked
	"Engineer" //salary: 200,000  start with small(50,000) ship +1 ship part +1cannon part
	*/


void splashScreen();

void fateRoll();



int main()
{
srand(time(NULL));
clear();
splashScreen();

waitFor2();
clear();

gameSetup();



return 0;



}



double getReleFactor(double v)
{

	long double reletivisticFactor = 0;
	long double cSqr = pow(c, 2);
	long double vSqr = pow(v,2);
	long double botVal = 1.0 - (vSqr/cSqr);



	reletivisticFactor = 1.0/(sqrt(botVal));


	return reletivisticFactor;
}


double solveTimeDil(double properTime, double velocity)
{
	double answer;

	double thisReleFactor = getReleFactor(velocity);

	answer = thisReleFactor * properTime;

	return answer;

}

double solveLengthCon(double properLength, double velocity)
{
	double answer;
	double thisReleFactor = getReleFactor(velocity);

	answer = properLength/thisReleFactor;

	return answer; //tested and working correctly


}

void shipSetup();

int getRandInt(int range)
{

	return (rand()%range + 1);  // not working fix it fix it fix it
}


double convertLightYears(double distLY)
{
	return distLY * 9460730472580800;
}

double solveLength(double timePassed, double velocity) //d = v *t
{
	double answer;
	answer = timePassed * velocity;
	return answer;
}

double solveTime(double theLength, double velocity)  //t = d/v
{

	double answer;

	return answer = theLength/velocity;

}
void splashScreen()
{
	cout << "WELCOME TO ORION TRAIL..." << endl;
	
}

void waitFor2() // sleeps for arg seconds;
{
 system("sleep 1s");
     
}
void clear()
{

	system("clear");
}

int gameSetup()
{
   string playerName;
   int playerOccupation;
   int playerCondition = 4;
   int playerTripChoice;
   char playerInput;

   cout <<"The year is irrelevant but very very far in the future and Manifest Destiny has hit Earth once again, prompting a mass migration to the Orion Star System" << endl;
   cout << "You have decided to leave the planet in search of a better tomorrow..." << endl;

   cout << "Please enter your name:" <<endl;
   cin >> playerName;//now you have a name
   waitFor2();
   cout << "Please enter the number corresponding to your occupation below.\n\n";
   cout << "OCCUPATION 0: Delivery Person SAVINGS: 120,000 credits SHIP: yes\n"
   		   "OCCUPATION 1: Doctor          SAVINGS: 400,000 credits SHIP: no \n"
   		   "OCCUPATION 2: Admiral         SAVINGS: 250,000 credits SHIP: yes\n"
   		   "OCCUPATION 3: Scientist       SAVINGS: 300,000 credits SHIP: no \n"
   		   "OCCUPATION 4: Hunter          SAVINGS: 350,000 credits SHIP: no \n"
   		   "OCCUPATION 5: Cat             SAVINGS: 450,000 credits SHIP: no \n"
   		   "OCCUPATION 6: Barber          SAVINGS: 180,000 credits SHIP: no \n"
   		   "OCCUPATION 7: Movie Producer  SAVINGS: 200,000 credits SHIP: no \n"
   	   	   "OCCUPATION 8: Cook            SAVINGS:  80,000 credits SHIP: yes\n"
   	   	   "OCCUPATION 9: Engineer        SAVINGS: 200,000 credits SHIP: yes\n\n";

   	cout << "OCCUPATION NUM: ";
   	cin >> playerOccupation; // a former job I'd like to have descriptions of the jobs if possible to describe their benefits
   	if(playerOccupation < 0 || playerOccupation > 9)
   	{
   			cout << "A METEOR CRASHED INTO YOUR FACE PRE TAKE OFF!(choose between 0 and 9 next time)" << endl;
			return 2;
   	}
   	waitFor2();
   	clear();

	cout <<"Trails have been established to 7 of the major stars in the Orion constellation." << endl;
	cout <<"Listed below are the Trip Manifests, the longer the trip the harder it will be to get there, enter the number of the manifest to decide." << endl;

	cout << endl << endl << "TRIP MANIFESTS:" << endl;
cout << "MISSION 0: Betelgeuse, DISTANCE: 643  Light Years\n"
		"MISSION 1: Rigel,      DISTANCE: 772  Light Years\n"
		"MISSION 2: Bellatrix,  DISTANCE: 243  Light Years\n"
		"MISSION 3: Mintaka,    DISTANCE: 900  Light Years\n"
		"MISSION 4: Alnilam,    DISTANCE: 1359 Light Years\n"
		"MISSION 5: Alnitak,    DISTANCE: 800  Light Years\n"
		"MISSION 6: Saiph,      DISTANCE: 724  Light Years\n";

cout << "\nTrip Choice: ";
cin >> playerTripChoice;

if(playerTripChoice > 6 || playerTripChoice < 0)
{
	cout << "A METEOR CRASHED INTO YOUR FACE PRE TAKE OFF!(choose between 0 and 6 next time)" << endl;
	return 2;
}

else 
{
	cout << "You've chosen trip " << playerTripChoice << "\nCongratulations, we hope your journey goes smoothly, good luck." << endl;
	
	waitFor2();
	clear();
}


thePlayerCharacter.setUpPlayer(playerName, playerOccupation, playerCondition, playerTripChoice);

thePlayerCharacter.printStats();

cout << "\nReady to continue(enter y to proceed)\n";
cin >> playerInput;


shipSetup();

supplySetup();

clear();

thePlayerCharacter.printStats();
thePlayerShip.printStats();

cout << "\n\nWow it looks like you're all set, time for take off. You ready?\n(y to continue)\n";



cin >> playerInput;

while(playerInput != 'y')
{
	cout << "Huh, I didn't catch that?" << endl;
	cin  >> playerInput;
}

waitFor2();
clear();
cout << "\nGood Luck.\n";

clear();

waitFor2();

cout << "LIFT OFF IN:" << " 5" << endl;
waitFor2();
clear();
cout << "LIFT OFF IN:" << " 4" << endl;
waitFor2();
clear();
cout << "LIFT OFF IN:" << " 3" << endl;
waitFor2();
clear();
cout << "LIFT OFF IN:" << " 2" << endl;
waitFor2();
clear();
cout << "LIFT OFF IN:" << " 1" << endl;
waitFor2();
clear();
cout << "LIFT OFF" << endl;

waitFor2();
clear();
cout << "LIFT OFF." << endl;
waitFor2();
waitFor2();
clear();
cout << "LIFT OFF.." << endl;
waitFor2();
waitFor2();
clear();
cout << "LIFT OFF..." << endl;
waitFor2();
waitFor2();
clear();
cout << "LIFT OFF...." << endl;

fateRoll();



return 1;


}

void fateRoll()
{
	int boom = getRandInt(20);



	
	if (boom > 2)
	{
		double totLength = solveLengthCon(convertLightYears(thePlayerCharacter.getMissionDistance()),thePlayerShip.getVel());
		double totTime = solveTime(totLength, thePlayerShip.getVel())/60/60/24/365;
		cout << "Successful lift off." << endl;
		waitFor2();
		clear();
		cout << "You make it to your destination, here are the results:" <<endl;
		waitFor2();

		if(thePlayerCharacter.getFood() + 100 < totTime)
		{
			thePlayerCharacter.setCondition(2);
			thePlayerCharacter.setFood(0);
			cout << "\nYou did not have nearly enough food for your trip despite being in cryosleep.\nYour condition suffered immensly from this.\n";
		}

		if(thePlayerCharacter.getMeds() + 50 < totTime/2)
		{
			thePlayerCharacter.setCondition(thePlayerCharacter.getCondition() - 1);
			thePlayerCharacter.setMeds(0);
			cout << "\nYou were not stocked up on medicine and became sick upon arrival.\n";  
		}

		if(thePlayerCharacter.getTorpedos() + 20 < totTime/4)
		{
			thePlayerCharacter.setCondition(thePlayerCharacter.getCondition()-1);
			thePlayerCharacter.setTorpedos(0);
			cout << "\nYou did not have enough torpedos to fend off space bandits, the damage to your ship hurt you.\n";
		}


		cout << endl;
		thePlayerCharacter.printStats();

		cout << "Distance traveled(by you):     " << solveLengthCon(convertLightYears(thePlayerCharacter.getMissionDistance()), thePlayerShip.getVel()) << endl;
		cout << "Distance traveled(from earth): " << convertLightYears(thePlayerCharacter.getMissionDistance()) << endl;
		cout << "Trip Time(passed for you):     " << totTime << " years." << endl;
		cout << "Trip Time(passed on Earth):    " << solveTimeDil(totTime, thePlayerShip.getVel()) << " years." << endl;

		if(thePlayerCharacter.getCondition() > 0)
		{
			cout << "\nGreat job you made it to your destination alive and well.\n";
		}
		else
		{
			cout << "\nWhile your ship made it to your destination, you are nothing more than a sack of bones upon arrival, better luck next time.\n";
		}
		
		cout << "\n\nGood Bye\n";
		
	}

	else
	{
		waitFor2();
		waitFor2();
		clear();
		waitFor2();
		cout << "Catastrophic Failure on Launch." <<endl;
		cout << "Mission failed.";
		waitFor2();
		


	}
}

void supplySetup()
{
		//buying supplies 
	char playerChoice = 'a';
	int amountToBuy;
	int playerMoney = thePlayerCharacter.getCreds();
	clear();
	cout << " WELCOME TO SPACE DEPOT:  FOR ALL OF YOUR INTERGALATIC NEEDS" << endl <<endl;

	cout << "We have everything you need here at space depot, space suits, space food, space guns, space knives, space torpedos, space chicken, space eggs, space fries, space spices, space Tylenol, space Advil, and many other space related medicines, please have a look around and let me know if I can help." << endl;

	

	while(playerChoice == 'a')
	{
		cout << "(Press f for food, m for meds, t for torpedos)" << endl;	
		cin >> playerChoice;
		if(playerChoice == 'f')
		{
			cout << "We sell by the crate so its gonna be 1000 credits for 10 units of space food...(enter 1 for 10 space food, 2 for 20 etc.)" << endl;
			cin >> amountToBuy;
			if(((amountToBuy * 1000) > thePlayerCharacter.getCreds()) || ((amountToBuy * 1000) < 0) || ((thePlayerShip.getCurrentWeight() + amountToBuy*10)>thePlayerShip.getMaxWeight()))
			{
				cout << "\nInsufficient Funds or Space" <<endl;
				playerChoice = 'a';
			}
			else
			{
				int newPlayerCreds = thePlayerCharacter.getCreds() - (amountToBuy*1000);
				int newWeight = thePlayerShip.getCurrentWeight() + amountToBuy*10;
				int newFood = thePlayerCharacter.getFood() +  amountToBuy*10;
				thePlayerCharacter.setFood(newFood);
				thePlayerCharacter.setCreds(newPlayerCreds);
				thePlayerShip.setCurrentWeight(newWeight);
				cout << endl;
				thePlayerCharacter.printStats();
				thePlayerShip.printStats();

				cout << "\nWould you like anything else?(enter a for yes, z for no)" << endl;
				cin >> playerChoice;
			}
		}

		else if(playerChoice == 'm')
		{
			cout << "We sell by the crate so its gonna be 1500 credits for 10 units of space medicine...(enter 1 for 10 space meds, 2 for 20 etc.)" << endl;
			cin >> amountToBuy;
			if(((amountToBuy * 1500) > thePlayerCharacter.getCreds()) || ((amountToBuy * 1500) < 0) || ((thePlayerShip.getCurrentWeight() + amountToBuy*10)>thePlayerShip.getMaxWeight()))
			{
				cout << "\nInsufficient Funds or Space" <<endl;
				playerChoice = 'a';
			}
			else
			{
				int newPlayerCreds = thePlayerCharacter.getCreds() - (amountToBuy*1500);
				int newWeight = thePlayerShip.getCurrentWeight() + amountToBuy*10;
				int newMeds = thePlayerCharacter.getMeds() + amountToBuy*10;
				thePlayerCharacter.setCreds(newPlayerCreds);
				thePlayerShip.setCurrentWeight(newWeight);
				thePlayerCharacter.setMeds(newMeds);
				cout << endl;
				thePlayerCharacter.printStats();
				thePlayerShip.printStats();

				cout << "\nWould you like anything else?(enter a for yes, z for no)" << endl;
				cin >> playerChoice;
			}
		}

		else if(playerChoice == 't')
		{
			cout << "We sell by the crate so its gonna be 500 credits for 10 units of space torpedos...(enter 1 for 10 space torpedos, 2 for 20 etc.)" << endl;
			cin >> amountToBuy;
			if(((amountToBuy * 500) > thePlayerCharacter.getCreds()) || ((amountToBuy * 500) < 0) || ((thePlayerShip.getCurrentWeight() + amountToBuy*10)>thePlayerShip.getMaxWeight()))
			{
				cout << "\nInsufficient Funds or Space" <<endl;
				playerChoice = 'a';
			}
			else
			{
				int newPlayerCreds = thePlayerCharacter.getCreds() - (amountToBuy*500);
				int newWeight = thePlayerShip.getCurrentWeight() + amountToBuy*10;
				int newTorp = thePlayerCharacter.getTorpedos() + amountToBuy*10;
				thePlayerCharacter.setCreds(newPlayerCreds);
				thePlayerShip.setCurrentWeight(newWeight);
				thePlayerCharacter.setTorpedos(newTorp);
				cout << endl;
				thePlayerCharacter.printStats();
				thePlayerShip.printStats();

				cout << "\nWould you like anything else?(enter a for yes, z for no)" << endl;
				cin >> playerChoice;
			}
		}

		else
		{
			if(playerChoice != 'z')
			{
				playerChoice = 'a';
				
			}
		}
		if(playerChoice != 'z')
		{
			playerChoice = 'a';
		}
	}

	cout << "Thanks have a great journey. I wonder when you'll get there..." << endl << endl;

	waitFor2();
	clear();
	thePlayerCharacter.printStats();
	thePlayerShip.printStats();

	//clearShowStats(thePlayerCharacter, thePlayerShip);




}

void clearShowStats(player myGuy, playerShip myShip)
{
	clear();
	myGuy.printStats();
	myShip.printStats();
	waitFor2();
	waitFor2();
}

void shipSetup()
{
	int shipChoice = 0;

	clear();
	cout << "Hello and welcome to Seymour's Spaceship Shop\n";
	cout << "We've got all sorts of space vehicles ready to fly. We also install parts. Take a look and let me know what you'd like.";
	if(thePlayerCharacter.haveShip() == false){
	cout << "\n\nCHOOSE A SHIP:" << endl << endl;

	cout << "The Cruiser:" <<endl;
	cout << "  Size:   Small\n"
			"  Speed:  .95c\n"
			"  Cost:   75,000 Credits\n"
			"  Option: 1\n"
			"  Desc:  The Cruiser is the tinyest starting ship only able to carry 300 supplies, this lack of weight is made up with a speed increase and price drop.\n\n";
	cout << "Ol' Reliable:" <<endl;
	cout << "  Size:  Medium\n"	
			"  Speed: .925c\n"
			"  Cost:  125,000 Credits\n"
			"  Option: 2\n"
			"  Desc:  Ol' Reliable is exactly what it says on the tin, if you want to make it wherever you're going this ship is a safe choice, it can carry 750 supplies and with a fast speed and moderate pricing, its the safest choice for not dying.\n\n";

    cout << "The Conestoga" << endl;
    cout << "  Size: Big\n"
    		"  Speed: .9c\n"
    		"  Cost:  150,000 Credits\n"
    		"  Option: 3\n"
    		"  Desc:  The Conestoga is the ship for you if you want to always be stocked up.  It's got by far the most space, capable of carrying up to 1500 supplies.  Perfect for long hauls and slow going.\n";

    cout << "\nYou have ";
    cout << thePlayerCharacter.getCreds(); 
    cout << " Credits.  Enter the option number of the ship you want." << endl;
    

    while(shipChoice == 0)
    {
    	cout << "\nOPTION NUMBER: ";
    	cin >> shipChoice;
    	if(shipChoice == 1)
    	{
    		int shipPurchase = thePlayerCharacter.getCreds() - 75000;
    		thePlayerCharacter.setCreds(shipPurchase);
    		thePlayerCharacter.setShip(true);
    		thePlayerShip.setShip((.95*c), 1, 300, thePlayerCharacter.getTotalSupplies(), thePlayerCharacter.getShipPart(), thePlayerCharacter.getCanPart());
    		break;
    	}
    	else if(shipChoice == 2)
    	{
    		int shipPurchase = thePlayerCharacter.getCreds() - 125000;
    		thePlayerCharacter.setCreds(shipPurchase);
    		thePlayerCharacter.setShip(true);
    		thePlayerShip.setShip((.925*c), 2, 750, thePlayerCharacter.getTotalSupplies(), thePlayerCharacter.getShipPart(), thePlayerCharacter.getCanPart());
    		break;
    	}
    	else if(shipChoice == 3)
    	{
    		int shipPurchase = thePlayerCharacter.getCreds() - 150000;
    		thePlayerCharacter.setCreds(shipPurchase);
    		thePlayerCharacter.setShip(true);
    		thePlayerShip.setShip((.9*c), 3, 1500, thePlayerCharacter.getTotalSupplies(), thePlayerCharacter.getShipPart(), thePlayerCharacter.getCanPart());
    		break;
    	}
    	else
    	{
    		cout << "\nThat's not a choice.";
    		shipChoice = 0;
    	}
    }

    if(thePlayerCharacter.getOccupation() == 4)
    {
    	thePlayerShip.setCannonWidth(thePlayerShip.getCannonShotWidth() + 10);
    }

    cout << "Congratulations on your purchase" << endl << endl;
    waitFor2();

    clear();
    thePlayerCharacter.printStats();
    cout << endl;
    thePlayerShip.printStats();

    waitFor2();
    waitFor2();
    waitFor2();
    waitFor2();



	}

	else
	{
		switch(thePlayerCharacter.getOccupation())
		{
			case 0:  thePlayerShip.setShip((.925*c), 2, 750, thePlayerCharacter.getTotalSupplies(), thePlayerCharacter.getShipPart(), thePlayerCharacter.getCanPart());
			case 2:  thePlayerShip.setShip((.95*c), 1, 300, thePlayerCharacter.getTotalSupplies(), thePlayerCharacter.getShipPart(), thePlayerCharacter.getCanPart());
			case 8:  thePlayerShip.setShip((.9*c), 3, 1500, thePlayerCharacter.getTotalSupplies(), thePlayerCharacter.getShipPart(), thePlayerCharacter.getCanPart());
			case 9:  thePlayerShip.setShip((.95*c), 1, 300, thePlayerCharacter.getTotalSupplies(), thePlayerCharacter.getShipPart(), thePlayerCharacter.getCanPart());

		}
		cout << "\nAh I see you've already got a ship, if you have any parts to install I'll be happy to help." << endl;
	}

	if(thePlayerCharacter.getShipPart() > 0)
	{
		//this will activate upgrade ship function which will take the player characters ship parts and add them to the ships upgrade parts and increase a value of the ship(V, maxWeight)
		upgradeShipShop();

	}

	if(thePlayerCharacter.getCanPart() > 0)
	{
		//This will activate the cannon upgrade shop which does the same as the ship one but increases shots fired or spread angle
		upgradeCannonShop();
	}


	cout << "Now that you're done here you should go pick up any supplies from across then street, happy trails!" <<endl;

	waitFor2();
	waitFor2();





}

void upgradeShipShop()
{
	int playerChoice = 0;

	cout << "\nIt appears as if you have a ship part to install.  We have 2 options for you to choose from." << endl;
	cout << "\nOPTION 1:  Engine Modification, with this upgrade we can boost the output of your ship's main engine" << endl;
	cout << "  allowing it to reach speeds .025c faster than your current speed." << endl <<endl;
	cout << "OPTION 2:  Size Enhancement, with this upgrade we add some internal storage to your ship allowing it to carry 100 more supplies, without losing any speed." << endl;

	cout << "\n\nSo which upgrade would you like?" << endl;

	while(playerChoice == 0){

		cout << "OPTION NUMBER: ";
		cin >> playerChoice;

		if(playerChoice == 1)
		{
			cout << "Your Engine Modification is complete." << endl;

			thePlayerCharacter.setShipPart(thePlayerCharacter.getShipPart()-1);
			thePlayerShip.setShipUpgrades(thePlayerShip.getUpgradesShip()+1);
			thePlayerShip.setVel(thePlayerShip.getVel()+ (.01*c));

			cout << endl << "Your newly upgraded ship specs:" << endl;
			thePlayerShip.printStats();
			waitFor2();
			waitFor2();

		}

		else if (playerChoice == 2)
		{
			cout << "Your Storage Modification is complete." << endl;

			thePlayerCharacter.setShipPart(thePlayerCharacter.getShipPart()-1);
			thePlayerShip.setShipUpgrades(thePlayerShip.getUpgradesShip()+1);
			thePlayerShip.setMaxWeight(thePlayerShip.getMaxWeight() + 100);

			cout << endl << "Your newly upgraded ship specs:" << endl;
			thePlayerShip.printStats();
			waitFor2();
			waitFor2();
		}

		else
		{
			cout << "That's not a choice" << endl;
		}
	}

}

void upgradeCannonShop()
{
		int playerChoice = 0;

	cout << "\nIt appears as if you have a cannon part to install.  We have 2 options for you to choose from." << endl;
	cout << "\nOPTION 1:  Shot Modification, with this upgrade we can increase the amount of shots you fire at targets by 10, increasing your chances of hitting the target." << endl;
	
	cout << "OPTION 2:  Spread Modification, with this upgrade we allow the cannon to shoot at a wider angle allowing a larger attack area by 10 degrees." << endl;

	cout << "\n\nSo which upgrade would you like?" << endl;

	while(playerChoice == 0){

		cout << "OPTION NUMBER: ";
		cin >> playerChoice;

		if(playerChoice == 1)
		{
			cout << "Your Shot Modification is complete." << endl;

			thePlayerCharacter.setCanPart(thePlayerCharacter.getCanPart()-1);
			thePlayerShip.setCannonUpgrades(thePlayerShip.getUpgradesCannon() + 1);
			thePlayerShip.setCannonShot(thePlayerShip.getCannonShots()+ 5);

			cout << endl << "Your newly upgraded ship specs:" << endl;
			thePlayerShip.printStats();
			waitFor2();
			waitFor2();

		}

		else if (playerChoice == 2)
		{
			cout << "Your Spread Modification is complete." << endl;

			thePlayerCharacter.setCanPart(thePlayerCharacter.getCanPart()-1);
			thePlayerShip.setCannonUpgrades(thePlayerShip.getUpgradesCannon() + 1);
			thePlayerShip.setCannonWidth(thePlayerShip.getCannonShotWidth()+ 10);

			cout << endl << "Your newly upgraded ship specs:" << endl;
			thePlayerShip.printStats();
			waitFor2();
			waitFor2();
		}

		else
		{
			cout << "That's not a choice" << endl;
		}
	}

}

	player::player()
	{
		name = "NULL";
		occupation = 0;
		condition = 0;
		missionChoice = -1;

	}

	void player::setUpPlayer(string myName, int myOccupation, int myCondition , int myMission)
	{
		name = myName;
		occupation = myOccupation;
		condition = myCondition;
		missionChoice = myMission;

		switch(occupation)
		{
			case 0: //Delivery Person
				condition++;
				spaceFood = 0;
				spaceCredits = 120000;
				spaceMedicine = 0;
				spaceTorpedos = 0;
				hasShip = true;
				shipParts = 1;
				cannonParts = 0;
				break;

			case 1: //Doctor
				spaceFood = 0;
				spaceCredits = 400000;
				spaceMedicine = 100;
				spaceTorpedos = 0;
				hasShip = false;
				shipParts = 0;
				cannonParts = 0;
				break;

			case 2: //Admiral
				spaceFood = 0;
				spaceCredits = 250000;
				spaceMedicine = 0;
				spaceTorpedos = 100;
				hasShip = true;
				shipParts = 0;
				cannonParts = 1;
				break;

			case 3: //Scientist
				spaceFood = 0;
				spaceCredits = 300000;
				spaceMedicine = 0;
				spaceTorpedos = 0;
				hasShip = false;
				shipParts = 0;
				cannonParts = 0;
				break;			

			case 4: //Hunter
				spaceFood = 0;
				spaceCredits = 350000;
				spaceMedicine = 0;
				spaceTorpedos = 0;
				hasShip = false;
				shipParts = 0;
				cannonParts = 0;
				break;	

			case 5: //Cat
				spaceFood = 100;
				spaceCredits = 450000;
				spaceMedicine = 0;
				spaceTorpedos = 0;
				hasShip = false;
				shipParts = 0;
				cannonParts = 0;
				condition--;
				break;	

			case 6: //Barber
				spaceFood = 0;
				spaceCredits = 180000;
				spaceMedicine = 25;
				spaceTorpedos = 0;
				hasShip = false;
				shipParts = 0;
				cannonParts = 0;
				break;	

			case 7: //Movie Producer
				spaceFood = 150;
				spaceCredits = 200000;
				spaceMedicine = 150;
				spaceTorpedos = 150;
				hasShip = false;
				shipParts = 0;
				cannonParts = 0;
				break;	

			case 8: //Cook
				spaceFood = 150;
				spaceCredits = 80000;
				spaceMedicine = 0;
				spaceTorpedos = 0;
				hasShip = true;		//has the biggest ship
				shipParts = false;
				cannonParts = false;
				break;	

			case 9: //Engineer
				spaceFood = 0;
				spaceCredits = 200000;
				spaceMedicine = 0;
				spaceTorpedos = 0;
				hasShip = true;
				shipParts = 1;
				cannonParts = 1;
				break;	
		}
		
	}

	void player::setCondition(int newCond)
	{
		condition = newCond;
	}

	string player::getName()
	{
		return name;
	}

	string player::getOccupationName()
	{
		switch(occupation)
		{
			case 0: return "Delivery Person";
			case 1: return "Doctor";
			case 2: return "Admiral";
			case 3: return "Scientist";
			case 4: return "Hunter";
			case 5: return "Cat";
			case 6: return "Barber";
			case 7: return "Movie Producer";
			case 8: return "Cook";
			case 9: return "Engineer";

		}

		return "NULL";
	}

	string player::missionLookup()
	{
		switch(missionChoice)
		{
			case 0: return "Betelgeuse";
			case 1: return "Rigel";
			case 2: return "Bellatrix";
			case 3: return "Mintaka";
			case 4: return "Alnilam";
			case 5: return "Alnitak";
			case 6: return "Saiph";
		}
		return "NULL";
	}

	void player::setFood(int newFood)
	{
		spaceFood = newFood;

	}

	void player::setCreds(int newCreds)
	{
		spaceCredits = newCreds;
	}

	void player::setTorpedos(int newTorpedos)
	{
		spaceTorpedos = newTorpedos;
	}

	void player::setMeds(int newMeds)
	{
		spaceMedicine = newMeds;
	}

	void player::setShip(bool haz)
	{
		hasShip = haz;
	}

	int player::getCondition()
	{
		return condition;
	}
	int player::getOccupation()
	{
		return occupation;
	}

	int player::getFood()
	{
		return spaceFood;
	}

	int player::getCreds()
	{
		return spaceCredits;
	}

	int player::getMeds()
	{
		return spaceMedicine;
	}

	int player::getTorpedos()
	{
		return spaceTorpedos;
	}

	int player::getMission()
	{
		return missionChoice;
	}

	int player::getShipPart()
	{
		return shipParts;
	}

	int player::getCanPart()
	{
		return cannonParts;
	}

	bool player::haveShip()
	{
		return hasShip;
	}

	string player::conditionLookup()
	{
		switch(condition)
		{
			case 0: return "Dead :(";
			case 1: return "Looking to kick the bucket";
			case 2: return "Not feeling to hot";
			case 3: return "OK";
			case 4: return "Good";
			case 5: return "Great :)";
		}
		return "NULL";
	}

	void player::printStats()
	{
		//system("clear");
		cout << "NAME: " << getName() << endl;
		cout << "OCCUPATION: " << getOccupationName() << endl;
		cout << "DESTINATION SYSTEM: " << missionLookup() << endl;
		cout << "CONDITION: " << conditionLookup() << endl;
		cout << "CREDITS: " << getCreds() << endl;

		cout << "\nSUPPLIES:\n";
		cout << "  Space Food: " << getFood() << endl;
		cout << "  Medicine:   " << getMeds() << endl;
		cout << "  Torpedos:   " << getTorpedos() << endl;

	}

	int player::getTotalSupplies()
	{
		return spaceTorpedos + spaceMedicine + spaceFood;
	}

	void player::setShipPart(int newShipPart)
	{
		shipParts = newShipPart;
	}

	void player::setCanPart(int newCanPart)
	{
		cannonParts = newCanPart;
	}

	double player::getMissionDistance()
	{
		switch(missionChoice)
		{
			case 0: return 643;
			case 1: return 772;
			case 2: return 243;
			case 3: return 900;
			case 4: return 1359;
			case 5: return 800;
			case 6: return 724;

		}
		return 0;
	}


	playerShip::playerShip()
{
	currentPosition = 0;
	currentVelocity = 0;
	currentTime = 0;

	type = 0;
	maxWeight = 0;
	currentWeight = 0;

	cannonShots = 10;
	cannonShotWidth = 20;

	shipUpgrades = 0;
	cannonUpgrades = 0;
}

void playerShip::setShip(double theVel, int theType, int theMax, int theCurrent, int theShipUpgrades, int theCannonUpgrades)
{
	currentPosition = 0;
	currentVelocity = theVel;
	currentTime = 0;

	type = theType;
	maxWeight = theMax;
	currentWeight = theCurrent;

	cannonShots = 10;
	cannonShotWidth = 20;

	shipUpgrades = theShipUpgrades;
	cannonUpgrades = theCannonUpgrades;
}

double playerShip::getPos()
{
	return currentPosition;
}

double playerShip::getVel()
{
	return currentVelocity;
}

double playerShip::getTime()
{
	return currentTime;
}

int playerShip::getType()
{
	return type;
}

int playerShip::getMaxWeight()
{
	return maxWeight;
}

int playerShip::getCurrentWeight()
{
	return currentWeight;
}

int playerShip::getCannonShots()
{
	return cannonShots;
}

int playerShip::getCannonShotWidth()
{
	return cannonShotWidth;
}

int playerShip::getUpgradesShip()
{
	return shipUpgrades;
}

int playerShip::getUpgradesCannon()
{
	return cannonUpgrades;
}

void playerShip::setPos(double newPosition)
{
	currentPosition = newPosition;
}

void playerShip::setVel(double newVelocity)
{
	currentVelocity = newVelocity;
}

void playerShip::setTime(double newTime)
{
	currentTime = newTime;
}

void playerShip::setCurrentWeight(int newCurrent)
{
	currentWeight = newCurrent;
}

void playerShip::setMaxWeight(int newMax)
{
	maxWeight = newMax;
}

void playerShip::setCannonShot(int newCanShot)
{
	cannonShots = newCanShot;
}

void playerShip::setCannonWidth(int newWidth)
{
	cannonShotWidth = newWidth;
}

string playerShip::shipTypeLookUp(int type)
{
	switch(type)
	{
		case 1: return "The Cruiser"; break;
		case 2: return "Ol' Reliable"; break;
		case 3: return "The Conestoga"; break;
	}

	return "NULL";
}

void playerShip::printStats()
{
	cout << "YOUR SHIP:  " <<endl;
	cout << "  TYPE:    " << thePlayerShip.shipTypeLookUp(thePlayerShip.getType()) << endl;
	cout << "  WEIGHT:  " << thePlayerShip.getCurrentWeight() << "/" << thePlayerShip.getMaxWeight() << endl;
	cout << "  SPEED:   " << thePlayerShip.getVel()/c << "c" << endl;
	cout << "\nYOUR CANNON:" <<endl;
	cout << "  SHOTS PER VOLLEY:  " << thePlayerShip.getCannonShots() << " shots." << endl;
	cout << "  CANNON SPREAD:     " <<  thePlayerShip.getCannonShotWidth() << " degrees." <<endl;

}

void playerShip::setShipUpgrades(int newShipUpgrade)
{
	shipUpgrades = newShipUpgrade;
}

void playerShip::setCannonUpgrades(int newCanUpgrade)
{
	cannonUpgrades = newCanUpgrade;
}


//Game setup complete (potential end game sequence also done)
//next up is the main game loop you've taken off into space and your supplies start going down and such
// Not sure if I'll be able to finish all that in time but now I have something that can at least be shown off



//next up I'm trying to figure out how best to impliment mining/hunting 
//scenarios into the game using the multiple velocities formula
//I want to have 3 velocities going at once
//ship X is going left at .5c  ship y is going right at .5c or something 
// I want ship y to fire a torpedo at ship x, 
// and I want the user to enter the angle to shoot at, or a range of angles (20 degree range)
//how do I calculate velocity for the torpedo/check that it will be hit or not

//figured out several options, a mining option on the screen to go shoot some asteroids
//there will be a hunting option to go hunt an animal/ship(that will be the first scenario on the paper)

