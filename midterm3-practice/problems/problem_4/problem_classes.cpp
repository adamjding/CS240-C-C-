#ifndef PROBLEM_CLASSES_CPP
#define PROBLEM_CLASSES_CPP

// Problem (1/4)
/******************************************************************************
 * TODO: Create a parent class called Appliance. Add the following:
 * One instance variable, both should be protected, of type String 
 		representing the name of the appliance.
 *			IMPORTANT: Use std::string for the type instead of char*
 * A constructor that takes no parameters that does nothing.
 * A constructor that takes one parameter: An string, corresponding to the
 * 		name of the appliance.
 * A getName() method that returns the name of the appliance.
 * A virtual getEnergyUsed(int) method that takes an int as a parameter 
 *		(representing time) and return an int.
 *****************************************************************************/
class Appliance{
	protected:
	std::string name;
	int energyUsed = 0;

	public:
	Appliance(std::string s){
		name = s;
	}
	Appliance();
	
	std::string getName(){
		return name;
	}
	
	virtual int getEnergyUsed(){
		return energyUsed;
	}
};
// Problem (2/4)
/******************************************************************************
 * TODO: Create a child class Dishwasher which inherits Appliance. Add
 * the following:
 * One private instance variable (called "dishes") representing the number of dishes 
 *		in the dishwasher.
 * A constructor that takes one parameter, same as the constructor. Also, initialize 
 *		dishes to 0.
 * A loadDishes(int) method that takes an int as a parameter, representing the
 *		number of dishes to add to the dishwasher. Update the dishes variable by
 *		adding the parameter to it. loadDishes(int) should return void.
 * Override the getEnergyUsed() method from the parent. Use the following formula:
 * 		energyUsed = 500 + dishes * 3
 *****************************************************************************/
class Dishwasher : public Appliance{
	private:
	int dishes = 0;
	
	public:
	Dishwasher(std::string s) : Appliance(s){
		dishes = 0;
	}

	void loadDishes(int add){
		dishes += add;
	}

	virtual int getEnergyUsed(){
		energyUsed = 500 + dishes *3;
		return energyUsed;
	}
};
// Problem (3/4)
/******************************************************************************
 * TODO: Create a child class Washer which inherits Appliance. Add the following:
 * One private instance variable (called "clothes") representing the number of 
 *		clothes in the washer.
 * A constructor that takes one parameter, same as the constructor. Also, initialize 
 *		clothes to 0.
 * A loadClothes(int) method that takes an int as a parameter, representing the
 *		number of clothes to add to the dishwasher. Update the clothes variable by
 *		adding the parameter to it. loadClothes(int) should return void.
 * Override the getEnergyUsed() method from the parent. Use the following formula:
 * 		energyUsed = 200 + clothes * 10
 *****************************************************************************/
class Washer: public Appliance{
	private:
	int clothes = 0;
	
	public:
	Washer(std::string s) : Appliance(s){
		clothes = 0;
	}
	
	void loadClothes(int add){
		clothes += add;
	}
	
	virtual int getEnergyUsed(){
		energyUsed = 200 + clothes * 10;
		return energyUsed;
	}
};

// Problem (4/4)
/******************************************************************************
 * TODO: Create a child class Microwave which inherits Appliance. Add the following:
 * One private instance variable (called "food") representing the number of 
 *		food in the microwave.
 * A constructor that takes one parameter, same as the constructor. Also, initialize 
 *		food to 0.
 * A addFood(int) method that takes an int as a parameter, representing the
 *		amount of food to add to the microwave. Update the food variable by
 *		adding the parameter to it. addFood(int) should return void.
 * Override the getEnergyUsed() method from the parent. Use the following formula:
 * 		energyUsed = 300 + food
 *****************************************************************************/
class Microwave: public Appliance{
	private:
	int food;

	public:
	Microwave(std::string s) : Appliance(s){
		food = 0;
	}
	
	void addFood(int add){
		food += add;
	}
	
	virtual int getEnergyUsed(){
		energyUsed = 300 + food;
		return energyUsed;
	}
};
#endif
