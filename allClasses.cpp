#include "allClasses.h"
#define  _CRT_SECURE_NO_WARNINGS
using namespace std;

Animal::Animal()//set the default color to GRAY and other params to 0
{
	this->m_color = new char[5];
	strcpy(this->m_color, "GRAY");
	this->m_childCount = 0;
	this->m_avgLifetime = 0;
}
Animal::Animal(const char* color, int childs, float avgLifetime)//init the Animal with a given attributes
{
	this->m_color = new char[strlen(color) + 1];
	strcpy(this->m_color, color);

	this->m_childCount = childs;
	this->m_avgLifetime = avgLifetime;

}

void Animal::setColor(const char* color)
{
	this->m_color = new char[strlen(color) + 1];
	strcpy(this->m_color, color);
}
void Animal::setChildCount(int child)
{
	this->m_childCount = child;
}
void Animal::setLifetime(float life)
{
	this->m_avgLifetime = life;
}



Animal::Animal(ifstream& in_file)//init the Animal from a binary file
{
	int n;
	in_file.read((char*)&n, sizeof(n));
	m_color = new char[n + 1];
	in_file.read(m_color, n);
	m_color[n] = '\0';
	in_file.read((char*)&m_childCount, sizeof(m_childCount));
	in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));
}

Animal::~Animal()
{
	delete[] this->m_color;
}

Animal::Animal(const Animal& other)
{
	//Copy C'tor
	this->m_color = new char[strlen(other.m_color) + 1];
	strcpy(this->m_color, other.m_color);
	this->m_avgLifetime = other.m_avgLifetime;
	this->m_childCount = other.m_childCount;
}

const char* Animal::GetColor() const//return the color of the animal
{
	return this->m_color;
}
int	Animal::GetChildCount() const//return the child count of the animal
{
	return this->m_childCount;
}
float Animal::GetLifetime() const//return the life time of the animal
{
	return this->m_avgLifetime;
}

void Animal::saveType(ofstream& out) const
{
	int num = 1;
	out.write((char*)&num, sizeof(num));
}

void Animal::save1(ofstream& out) const
{
	int len = strlen(this->m_color);
	out.write((char*)&len, sizeof(len));
	out.write(this->m_color, len);
	out.write((char*)&(this->m_childCount), sizeof(this->m_childCount));
	out.write((char*)&(this->m_avgLifetime), sizeof(this->m_avgLifetime));
}



void Animal::savetype2(ofstream& out) const
{
	int type = 1;
	out << type << endl;
}
void Animal::savetxt(ofstream& out) const
{
	out << strlen(this->m_color) << endl;
	out << this->m_color << endl;
	out << this->m_childCount << endl;
	out << this->m_avgLifetime << endl;
}
void Animal::Load2(ifstream& ifs)
{
	int size;
	ifs >> size;
	this->m_color = new char[size];
	ifs >> this->m_color;
	ifs >> this->m_childCount;
	ifs >> this->m_avgLifetime;
}

//*******************************************************************************************************//


Mammals::Mammals() : Animal()
{
	//set the default color to GRAY and other params to 0
	this->m_milkLiters = 0;
	this->m_pregnancyTime = 0;
}
Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk)
	: Animal(color, childs, avgLifetime)
{
	//init the Mammals with a given attributes

	this->m_milkLiters = milk;
	this->m_pregnancyTime = preg;

}
Mammals::Mammals(ifstream& in_file) : Animal(in_file)
{
	//init the Mammals from a binary file

	in_file.read((char*)&m_milkLiters, sizeof(m_milkLiters));
	in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));

}
Mammals:: ~Mammals()
{
}

Mammals::Mammals(const Mammals& other) : Animal(other.GetColor(), other.GetChildCount(), other.GetLifetime())
{
	this->m_milkLiters = other.GetMilk();
	this->m_pregnancyTime = other.GetPregnanceTime();
}

float Mammals::GetPregnanceTime() const
{
	//return the pregnance time of the animal
	return this->m_pregnancyTime;
}
float Mammals::GetMilk() const
{
	//return the milk liters of the animal
	return this->m_milkLiters;
}

void Mammals::saveType(ofstream& out) const
{
	int num = 2;
	out.write((char*)&num, sizeof(num));
}

void Mammals::save1(ofstream& out) const
{
	Animal::save1(out);

	out.write((char*)&(this->m_milkLiters), sizeof(this->m_milkLiters));
	out.write((char*)&(this->m_pregnancyTime), sizeof(this->m_pregnancyTime));
}



void Mammals::savetype2(ofstream& out) const
{
	int type = 2;
	out << type << endl;
}
void Mammals::savetxt(ofstream& out) const
{
	Animal::savetxt(out);
	out << this->m_pregnancyTime << endl;
	out << this->m_milkLiters << endl;
}

void Mammals::Load2(ifstream& ifs)
{
	Animal::Load2(ifs);
	ifs >> this->m_pregnancyTime;
	ifs >> this->m_milkLiters;
}


//*******************************************************************************************************//


Birds::Birds() : Animal()//set the default color to GRAY and other params to 0
{
	this->m_incubationTime = 0;
}

Birds::Birds(const char* color, int childs, float avgLifetime, float incubation)//init the Birds with a given attributes
	: Animal(color, childs, avgLifetime)
{
	this->m_incubationTime = incubation;
}
Birds::Birds(ifstream& in_file) : Animal(in_file)//init the Birds from a binary file
{
	in_file.read((char*)&m_incubationTime, sizeof(m_incubationTime));
}
Birds::~Birds()
{
}

Birds::Birds(const Birds& other) :Animal(other.m_color, other.m_childCount, other.m_avgLifetime) {
	//Copy C'tor
	this->m_incubationTime = other.m_incubationTime;
}

float Birds::GetIncubationTime() const//return the incubation time of the animal
{
	return this->m_incubationTime;
}

void Birds::saveType(ofstream& out) const
{
	int num = 3;
	out.write((char*)&num, sizeof(num));

}

void Birds::save1(ofstream& out) const
{
	Animal::save1(out);

	out.write((char*)&(this->m_incubationTime), sizeof(this->m_incubationTime));
}



void Birds::savetype2(ofstream& out) const
{
	int type = 3;
	out << type << endl;
}
void Birds::savetxt(ofstream& out) const
{
	Animal::savetxt(out);
	out << this->m_incubationTime << endl;

}
void Birds::Load2(ifstream& ifs)
{
	Animal::Load2(ifs);
	ifs >> this->m_incubationTime;
}
//*******************************************************************************************************//


Fish::Fish() : Animal()//set the default color to GRAY and other params to 0
{
	this->m_finCount = 0;
	this->m_gillsCount = 0;
}
Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills)//init the Fish with a given attributes
	: Animal(color, childs, avgLifetime)
{
	this->m_finCount = fin;
	this->m_gillsCount = gills;
}
Fish::Fish(ifstream& in_file) : Animal(in_file)//init the Fish from a binary file
{
	in_file.read((char*)&m_finCount, sizeof(m_finCount));
	in_file.read((char*)&m_gillsCount, sizeof(m_gillsCount));
}
Fish::~Fish()
{
}

Fish::Fish(const Fish& other) :Animal(other.GetColor(), other.GetChildCount(), other.GetLifetime())
{
	this->m_finCount = other.GetFinCount();
	this->m_gillsCount = other.GetGillsCount();
}

int	Fish::GetFinCount() const//return the fin count of the animal
{
	return this->m_finCount;
}
int	Fish::GetGillsCount() const//return the gills count of the animal
{
	return this->m_gillsCount;
}

void Fish::saveType(ofstream& out) const
{
	int num = 4;
	out.write((char*)&num, sizeof(num));
}

void Fish::save1(ofstream& out) const
{
	Animal::save1(out);

	out.write((char*)&(this->m_finCount), sizeof(this->m_finCount));
	out.write((char*)&(this->m_gillsCount), sizeof(this->m_gillsCount));
}


void Fish::savetype2(ofstream& out) const
{
	int type = 4;
	out << type << endl;
}
void Fish::savetxt(ofstream& out) const
{
	Animal::savetxt(out);
	out << this->m_finCount << endl;
	out << this->m_gillsCount << endl;
}
void Fish::Load2(ifstream& ifs)
{
	Animal::Load2(ifs);
	ifs >> this->m_finCount;
	ifs >> this->m_gillsCount;
}

//*******************************************************************************************************//


Horse::Horse() : Mammals()//set the default color to GRAY and other params to 0 
{
	this->m_type = NULL;
}
Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type)
	: Animal(color, childs, avgLifetime), Mammals(color, childs, avgLifetime, preg, milk)
{
	//init the Horse with a given attributes
	this->m_type = new char[strlen(type) + 1];
	strcpy(this->m_type, type);
}
Horse::Horse(ifstream& in_file) : Animal(in_file), Mammals(in_file) //init the Horse from a binary file
{
	int n;
	in_file.read((char*)&n, sizeof(n));
	m_type = new char[n + 1];
	in_file.read(m_type, n);
	m_type[n] = '\0';
	//char* m_type;
}
Horse::~Horse()
{
	delete[] m_type;
}

Horse::Horse(const Horse& other) : Animal(other.m_color, other.m_childCount, other.m_avgLifetime)
, Mammals(other.m_color, other.m_childCount, other.m_avgLifetime, other.m_pregnancyTime, other.m_milkLiters) {
	this->m_type = new char[strlen(other.m_type) + 1];
	strcpy(this->m_type, other.m_type);
}

const char* Horse::GetType() const//return the type of the horse
{
	return this->m_type;
}

void Horse::saveType(ofstream& out) const
{
	int num = 5;
	out.write((char*)&num, sizeof(num));
}

void Horse::save1(ofstream& out) const
{
	Mammals::save1(out);
	int len = strlen(this->m_type);
	out.write((char*)&len, sizeof(len));
	out.write(this->m_type, len);
}


void Horse::savetype2(ofstream& out) const
{
	int type = 5;
	out << type << endl;
}
void Horse::savetxt(ofstream& out) const
{
	Mammals::savetxt(out);
	out << strlen(this->m_type) << endl;
	out << this->m_type << endl;
}

void Horse::Load2(ifstream& ifs)
{
	Mammals::Load2(ifs);
	int size;
	ifs >> size;
	this->m_type = new char[size];
	ifs >> this->m_type;


	char buffer7[150];
	ifs.getline(buffer7, 150);
	//this->m_type = new char[strlen(buffer7) + 1];
	//strcpy(this->m_type, buffer7);

	strcat(this->m_type, buffer7);
}

//*******************************************************************************************************//


Flamingo::Flamingo() : Birds()//set the default color to GRAY and other params to 0
{
	this->m_avgHeight = 0;
}
Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight)
	: Birds(color, childs, avgLifetime, incubation)
{
	//init the Flamingo with a given attributes
	this->m_avgHeight = avgHeight;
}
Flamingo::Flamingo(ifstream& in_file) : Birds(in_file)//init the Flamingo from a binary file
{
	in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));

}
Flamingo::~Flamingo()
{
}

Flamingo::Flamingo(const Flamingo& other)
	:Birds(other.GetColor(), other.GetChildCount(), other.GetLifetime(), other.GetIncubationTime())
{
	this->m_avgHeight = other.GetHeight();
}

float Flamingo::GetHeight() const//return the avg height of the flamingo
{
	return this->m_avgHeight;
}


void Flamingo::saveType(ofstream& out) const
{
	int num = 6;
	out.write((char*)&num, sizeof(num));
}

void Flamingo::save1(ofstream& out) const
{
	Birds::save1(out);
	out.write((char*)&m_avgHeight, sizeof(m_avgHeight));
}



void Flamingo::savetype2(ofstream& out) const
{
	int type = 6;
	out << type << endl;
}
void Flamingo::savetxt(ofstream& out) const
{
	Birds::savetxt(out);
	out << this->m_avgHeight << endl;
}

void Flamingo::Load2(ifstream& ifs)
{
	Birds::Load2(ifs);
	ifs >> this->m_avgHeight;
}

//***********************************************************************************//


MammalsFish::MammalsFish()//set the default color to GRAY and other params to 0
	: Animal(), Mammals(), Fish()
{
}
MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
	: Animal(color, childs, avgLifetime), Mammals(color, childs, avgLifetime, preg, milk),
	Fish(color, childs, avgLifetime, fin, gills)
{

	//init the MammalsFish with a given attributes
}
MammalsFish::MammalsFish(ifstream& in_file) : Animal(in_file), Mammals(in_file), Fish(in_file)
//init the MammalsFish from a binary file
{

}
MammalsFish::~MammalsFish()
{
}

MammalsFish::MammalsFish(const MammalsFish& other)
	:Animal(other.m_color, other.m_childCount, other.m_avgLifetime),
	Mammals(other.m_color, other.m_childCount, other.m_avgLifetime, other.m_pregnancyTime, other.m_milkLiters),
	Fish(other.m_color, other.m_childCount, other.m_avgLifetime, other.m_finCount, other.m_gillsCount) {
}

void MammalsFish::saveType(ofstream& out) const
{
	int num = 7;
	out.write((char*)&num, sizeof(num));
}

void MammalsFish::save1(ofstream& out) const
{
	Mammals::save1(out);
	out.write((char*)&(this->m_finCount), sizeof(this->m_finCount));
	out.write((char*)&(this->m_gillsCount), sizeof(this->m_gillsCount));

}



void MammalsFish::savetype2(ofstream& out) const
{
	int type = 7;
	out << type << endl;
}
void MammalsFish::savetxt(ofstream& out) const
{
	Mammals::savetxt(out);
	out << this->m_finCount << endl;
	out << this->m_gillsCount << endl;

}

void MammalsFish::Load2(ifstream& ifs)
{
	Mammals::Load2(ifs);
	ifs >> this->m_finCount;
	ifs >> this->m_gillsCount;
}

//*******************************************************************************************************//

GoldFish::GoldFish()//set the default color to GRAY and other params to 0
	: MammalsFish()
{
	this->m_avgLength = 0;
	this->m_avgWeight = 0;
}
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL)
	: Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
{
	this->m_avgLength = avgL;
	this->m_avgWeight = avgW;

	//init the GoldFish with a given attributes
}
GoldFish::GoldFish(ifstream& in_file) : Animal(in_file), MammalsFish(in_file)//init the GoldFish from a binary file
{
	in_file.read((char*)&m_avgWeight, sizeof(m_avgWeight));
	in_file.read((char*)&m_avgLength, sizeof(m_avgLength));

}
GoldFish::~GoldFish()
{
}

GoldFish::GoldFish(const GoldFish& other)
	:Animal(other.GetColor(), other.GetChildCount(), other.GetLifetime()),
	MammalsFish(other.GetColor(), other.GetChildCount(), other.GetLifetime(),
		other.GetPregnanceTime(), other.GetMilk(), other.GetFinCount(), other.GetGillsCount())
{
	this->m_avgLength = other.GetLength();
	this->m_avgWeight = other.GetWeight();

}

float GoldFish::GetWeight() const//return the avg weight of the gold fish
{
	return this->m_avgWeight;
}
float GoldFish::GetLength() const//return the avg length of the gold fish
{
	return this->m_avgLength;
}

void GoldFish::saveType(ofstream& out) const
{
	int num = 8;
	out.write((char*)&num, sizeof(num));
}

void GoldFish::save1(ofstream& out) const
{
	MammalsFish::save1(out);
	out.write((char*)&m_avgWeight, sizeof(m_avgWeight));
}



void GoldFish::savetype2(ofstream& out) const
{
	int type = 8;
	out << type << endl;
}
void GoldFish::savetxt(ofstream& out) const
{
	MammalsFish::savetxt(out);
	out << this->m_avgWeight << endl;
	out << this->m_avgLength << endl;
}


void GoldFish::Load2(ifstream& ifs)
{
	MammalsFish::Load2(ifs);
	ifs >> this->m_avgWeight;
	ifs >> this->m_avgLength;
}


//*******************************************************************************************************

Mermaid::Mermaid()//set the default color to GRAY and other params to 0
	: MammalsFish()
{
	this->m_firstName = NULL;
	this->m_lastName = NULL;
}
Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)
	: Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
{
	this->m_firstName = new char[strlen(firstName) + 1];
	this->m_lastName = new char[strlen(lastName) + 1];
	strcpy(m_firstName, firstName);
	strcpy(m_lastName, lastName);


}//init the Mermaid with a given attributes

Mermaid::Mermaid(ifstream& in_file) : Animal(in_file), MammalsFish(in_file)//init the Mermaid from a binary file
{
	int n1, n2;
	in_file.read((char*)&n1, sizeof(n1));
	m_firstName = new char[n1 + 1];
	in_file.read(m_firstName, n1);
	m_firstName[n1] = '\0';


	in_file.read((char*)&n2, sizeof(n2));
	m_lastName = new char[n2 + 1];
	in_file.read(m_lastName, n2);
	m_lastName[n2] = '\0';
}

Mermaid::~Mermaid()
{
	delete[] this->m_firstName;
	delete[] this->m_lastName;

}

Mermaid::Mermaid(const Mermaid& other)
	:Animal(other.m_color, other.m_childCount, other.m_avgLifetime),
	MammalsFish(other.m_color, other.m_childCount, other.m_avgLifetime, other.m_pregnancyTime, other.m_milkLiters,
		other.m_finCount, other.m_gillsCount) {
	this->m_firstName = new char[strlen(other.m_firstName) + 1];
	this->m_lastName = new char[strlen(other.m_lastName) + 1];
	strcpy(this->m_firstName, other.m_firstName);
	strcpy(this->m_lastName, other.m_lastName);
}

const char* Mermaid::GetFirstName() const//return the first name of the mermaid
{
	return this->m_firstName;
}
const char* Mermaid::GetLastName() const//return the last name of the mermaid
{
	return this->m_lastName;
}

void Mermaid::saveType(ofstream& out) const
{
	int num = 9;
	out.write((char*)&num, sizeof(num));
}

void Mermaid::save1(ofstream& out) const
{
	MammalsFish::save1(out);

	int len = strlen(this->m_firstName);
	out.write((char*)&len, sizeof(len));
	out.write(this->m_firstName, len);

	int len2 = strlen(this->m_lastName);
	out.write((char*)&len2, sizeof(len2));
	out.write(this->m_lastName, len2);

}


void Mermaid::savetype2(ofstream& out) const
{
	int type = 9;
	out << type << endl;
}
void Mermaid::savetxt(ofstream& out) const
{
	MammalsFish::savetxt(out);
	out << strlen(this->m_firstName) << endl;
	out << this->m_firstName << endl;
	out << strlen(this->m_lastName) << endl;
	out << this->m_lastName << endl;
}

void Mermaid::Load2(ifstream& ifs)
{
	MammalsFish::Load2(ifs);
	int size;
	ifs >> size;
	this->m_firstName = new char[size];
	ifs >> this->m_firstName;
	ifs >> size;
	this->m_lastName = new char[size];
	ifs >> this->m_lastName;
}

//*******************************************************************************************************

Zoo::Zoo()//default c'tor  - all to 0 or null
{
	this->m_name = NULL;
	this->m_address = NULL;
	this->m_ticketPrice = 0;
	this->m_openHours = NULL;
	this->m_closeHours = NULL;
	this->m_numOfAnimals = 0;
	this->m_animals = NULL;
}
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)//c'tor with data - init class
{
	this->m_name = new char[strlen(name) + 1];
	strcpy(this->m_name, name);
	this->m_address = new char[strlen(address) + 1];
	strcpy(this->m_address, address);

	this->m_ticketPrice = ticket;

	this->m_openHours = new char[strlen(open) + 1];
	strcpy(this->m_openHours, open);
	this->m_closeHours = new char[strlen(close) + 1];
	strcpy(this->m_closeHours, close);
	this->m_numOfAnimals = 0;
	this->m_animals = NULL;

}

Zoo::~Zoo()//d'tor
{
	if (this != NULL)
	{
		delete[] this->m_name;
		delete[] this->m_address;
		delete[] this->m_openHours;
		delete[] this->m_closeHours;
		for (int i = 0; i < this->m_numOfAnimals; i++)
		{
			//delete this->m_animals[i];
		}
		if (this->m_numOfAnimals != 0)
		{
			delete[] this->m_animals;
		}
	}
}

const char* Zoo::GetName() const//return the name of the zoo
{
	return this->m_name;
}
const char* Zoo::GetAddress() const//return the address of the zoo
{
	return this->m_address;
}
float Zoo::GetTicketPrice() const//return the ticket price of the zoo
{
	return this->m_ticketPrice;
}
const char* Zoo::GetOpenHour() const//return the open hour of the zoo
{
	return this->m_openHours;
}
const char* Zoo::GetCloseHour() const//return the close hour of the zoo
{
	return this->m_closeHours;
}
int	Zoo::GetNumOfAnimals() const//return the num of animals in the zoo
{
	return this->m_numOfAnimals;
}
Animal** Zoo::GetAnimals() const//return the animals array of the zoo
{
	return this->m_animals;
}

void Zoo::AddAnimal(Animal* an)//creates a copy of "an" (deep copy) and adds an animal to the array
{
	Animal** tmp;
	tmp = new Animal * [this->m_numOfAnimals + 1];
	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		tmp[i] = this->m_animals[i];
	}
	delete[] this->m_animals;
	this->m_numOfAnimals++;

	if (typeid(*an).name() == typeid(Animal).name())
	{
		tmp[this->m_numOfAnimals - 1] = *(new Animal * (an));
	}
	if (typeid(*an).name() == typeid(Flamingo).name())
	{
		Flamingo* f = dynamic_cast<Flamingo*> (an);
		tmp[this->m_numOfAnimals - 1] = new Flamingo(*f);
	}
	if (typeid(*an).name() == typeid(Horse).name())
	{
		Horse* f = dynamic_cast<Horse*> (an);
		tmp[this->m_numOfAnimals - 1] = new Horse(*f);
	}
	if (typeid(*an).name() == typeid(Mermaid).name())
	{
		Mermaid* f = dynamic_cast<Mermaid*> (an);
		tmp[this->m_numOfAnimals - 1] = new Mermaid(*f);
	}
	if (typeid(*an).name() == typeid(GoldFish).name())
	{
		GoldFish* f = dynamic_cast<GoldFish*> (an);
		tmp[this->m_numOfAnimals - 1] = new GoldFish(*f);
	}
	if (typeid(*an).name() == typeid(Fish).name())
	{
		Fish* f = dynamic_cast<Fish*> (an);
		tmp[this->m_numOfAnimals - 1] = new Fish(*f);
	}
	if (typeid(*an).name() == typeid(Mammals).name())
	{
		Mammals* f = dynamic_cast<Mammals*> (an);
		tmp[this->m_numOfAnimals - 1] = new Mammals(*f);
	}
	if (typeid(*an).name() == typeid(MammalsFish).name())
	{
		MammalsFish* f = dynamic_cast<MammalsFish*> (an);
		tmp[this->m_numOfAnimals - 1] = new MammalsFish(*f);
	}
	if (typeid(*an).name() == typeid(Birds).name())
	{
		Birds* f = dynamic_cast<Birds*> (an);
		tmp[this->m_numOfAnimals - 1] = new Birds(*f);
	}

	//tmp[this->m_numOfAnimals - 1] = an;

	this->m_animals = tmp;
}

Zoo& Zoo::operator+(Animal* an)
{
	Animal** tmp;
	tmp = new Animal * [this->m_numOfAnimals + 1];
	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		tmp[i] = this->m_animals[i];
	}
	tmp[this->m_numOfAnimals] = an;
	delete this->m_animals;
	this->m_numOfAnimals++;
	this->m_animals = tmp;
	return *this;
}
//adds an animal (only pointer, no copy needed) to the class and returns this with the change
Zoo Zoo::operator+(const Zoo& other) const
{
	int i = 0;
	Zoo* tmp = new Zoo(this->GetName(), this->GetAddress(), this->GetTicketPrice(), this->GetOpenHour(), this->GetCloseHour());
	int size = this->GetNumOfAnimals() + other.GetNumOfAnimals();
	//tmp->m_numOfAnimals = size;
	tmp->m_animals = new Animal * [size];

	for (i = 0;i < this->GetNumOfAnimals(); i++)
	{
		tmp->AddAnimal(this->m_animals[i]);
		//tmp->m_animals[i] = this->GetAnimals()[i];
	}

	for (int j = 0; j < other.GetNumOfAnimals(); j++)
	{
		tmp->AddAnimal(other.m_animals[j]);
		//tmp.m_animals[i] = other.m_animals[j];
		//i++;
	}

	return *tmp;

}
//returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)


Zoo& Zoo::operator+=(Animal* an)
{
	this->AddAnimal(an);
	return *this;
}


void Zoo::SaveBin(ofstream& ofs) const//method to save the info to a binary file
{
	int len = strlen(this->m_name);
	ofs.write((char*)&(len), sizeof(len));
	ofs.write(this->m_name, len);

	int len2 = strlen(this->m_address);
	ofs.write((char*)&(len2), sizeof(len2));
	ofs.write(this->m_address, len2);

	int len3 = strlen(this->m_openHours);
	ofs.write((char*)&(len3), sizeof(len3));
	ofs.write(this->m_openHours, len3);

	int len4 = strlen(this->m_closeHours);
	ofs.write((char*)&(len4), sizeof(len4));
	ofs.write(this->m_closeHours, len4);

	ofs.write((char*)&this->m_ticketPrice, sizeof(this->m_ticketPrice));
	ofs.write((char*)&this->m_numOfAnimals, sizeof(this->m_numOfAnimals));

	for (int i = 0; i < this->m_numOfAnimals; i++)
	{

		this->m_animals[i]->saveType(ofs);
		this->m_animals[i]->save1(ofs);
	}
}

Zoo::Zoo(ifstream& in_file) //c'tor that gets a binary file and loads the data of the zoo from the file
{
	int len, len2, len3, len4;
	int t;
	in_file.read((char*)&len, sizeof(len));
	this->m_name = new char[len + 1];
	in_file.read(this->m_name, len);
	this->m_name[len] = '\0';

	in_file.read((char*)&len2, sizeof(len2));
	this->m_address = new char[len2 + 1];
	in_file.read(this->m_address, len2);
	this->m_address[len2] = '\0';

	in_file.read((char*)&len3, sizeof(len3));
	this->m_openHours = new char[len3 + 1];
	in_file.read(this->m_openHours, len3);
	this->m_openHours[len3] = '\0';

	in_file.read((char*)&len4, sizeof(len4));
	this->m_closeHours = new char[len4 + 1];
	in_file.read(this->m_closeHours, len4);
	this->m_closeHours[len4] = '\0';

	in_file.read((char*)&(this->m_ticketPrice), sizeof(this->m_ticketPrice));
	in_file.read((char*)&(this->m_numOfAnimals), sizeof(this->m_numOfAnimals));
	this->m_animals = new Animal * [this->m_numOfAnimals];

	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		in_file.read((char*)&t, sizeof(t));
		if (t == 2)
			this->m_animals[i] = new Mammals(in_file);
		else if (t == 3)
			this->m_animals[i] = new Birds(in_file);
		else if (t == 4)
			this->m_animals[i] = new Fish(in_file);
		else if (t == 5)
			this->m_animals[i] = new Horse(in_file);
		else if (t == 6)
			this->m_animals[i] = new Flamingo(in_file);
		else if (t == 7)
			this->m_animals[i] = new MammalsFish(in_file);
		else if (t == 8)
			this->m_animals[i] = new GoldFish(in_file);
		else if (t == 9)
			this->m_animals[i] = new Mermaid(in_file);
		//cout << typeid(*(this->m_animals[i])).name() << " loaded from the file..." << endl;
	}
}

void Zoo::Save(ofstream& ofs) const//method to save the info to a text file
{
	//ofs << strlen(this->GetName()) << endl;
	ofs << this->m_name << endl;

	//ofs << strlen(this->GetAddress()) << endl;
	ofs << this->GetAddress() << endl;

	//ofs << strlen(this->GetOpenHour()) << endl;
	ofs << this->GetOpenHour() << endl;

	//ofs << strlen(this->GetCloseHour()) << endl;
	ofs << this->GetCloseHour() << endl;

	ofs << this->GetTicketPrice() << endl;
	ofs << this->GetNumOfAnimals() << endl;

	for (int i = 0; i < this->GetNumOfAnimals(); i++)
	{
		this->m_animals[i]->savetype2(ofs);
		this->m_animals[i]->savetxt(ofs);
	}
}
void Zoo::Load(ifstream& ifs)//method to load the info from a text file
{
	int size, size2, size3, size4;
	char buffer[150];
	ifs.getline(buffer, 150);
	this->m_name = new char[strlen(buffer) + 1];
	strcpy(this->m_name, buffer);

	ifs.getline(buffer, 150);
	this->m_address = new char[strlen(buffer) + 1];
	strcpy(this->m_address, buffer);

	ifs.getline(buffer, 150);
	this->m_openHours = new char[strlen(buffer) + 1];
	strcpy(this->m_openHours, buffer);

	ifs.getline(buffer, 150);
	this->m_closeHours = new char[strlen(buffer) + 1];
	strcpy(this->m_closeHours, buffer);

	ifs >> this->m_ticketPrice;

	ifs >> this->m_numOfAnimals;


	this->m_animals = new Animal * [this->m_numOfAnimals];

	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		int t;
		ifs >> t;
		if (t == 2)
		{
			this->m_animals[i] = new Mammals;
		}
		if (t == 3)
		{
			this->m_animals[i] = new Birds;
		}
		if (t == 4)
		{
			this->m_animals[i] = new Fish;
		}
		if (t == 5)
		{
			this->m_animals[i] = new Horse;
		}
		if (t == 6)
		{
			this->m_animals[i] = new Flamingo;
		}
		if (t == 7)
		{
			this->m_animals[i] = new MammalsFish;
		}
		if (t == 8)
		{
			this->m_animals[i] = new GoldFish;
		}
		if (t == 9)
		{
			this->m_animals[i] = new Mermaid;
		}
		this->m_animals[i]->Load2(ifs);
	}

}

ofstream& operator<<(ofstream& out, const Zoo& z)
{
	z.Save(out);
	return out;
}
ifstream& operator>>(ifstream& in, Zoo& z)
{
	z.Load(in);
	return in;
}

//
//void loadline(char* str, ifstream& in, int size)
//{
//	char ch = NULL;
//	int i = 0;
//	while (ch != '\n')
//	{
//		in >> ch;
//		str[i] = ch;
//		i++;
//	}
//	str[i] = '\0';
//}