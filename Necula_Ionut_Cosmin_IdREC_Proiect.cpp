#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

/*Proiectul meu este despre concerte.Sunt un fan al concertelor, mai ales a celor in aer liber
dar nu as zice nu niciodata unui concert intr-o sala mare. Mi-ar placea sa fiu persoana care s-ar ocupa
de tot ce inseamna managementul unui concert. Intrucat nu am fost niciodata la un concert intr-o sala
am ales sa fac proiectul exact pe aceasta structura. Bineinteles, pot fi adaugate si concerte in aer liber, 
gen pe o pajiste pe care sunt puse si scaune
*/
using namespace std;

class SalaConcert
{
private:
	const int nrSalaConcert;
	static int nrTotalSaliConcert;
	char* numeSalaConcert;
	int nrRanduri;
	int nrLocuriPeRand;
	int** locuriSalaConcert;
	int orarSalaConcert[7][10];
	int pretLocSala;
	string tipSalaConcert;

public:
	SalaConcert() : nrSalaConcert(++nrTotalSaliConcert)
	{
		numeSalaConcert = new char[] {""};
		nrRanduri = 10;
		nrLocuriPeRand = 10;

		locuriSalaConcert = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
		{
			this->locuriSalaConcert[i] = new int[nrLocuriPeRand];
		}
		for (int i = 0; i < nrRanduri; i++)
		{
			for (int j = 0; j < nrLocuriPeRand; j++)
			{
				this->locuriSalaConcert[i][j] = 0;
			}
		}

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 3; j++)
			{
				orarSalaConcert[i][j] = 0;
			}
		}
		pretLocSala = 25;
		tipSalaConcert = "Aer liber";
	}

	SalaConcert(char* numeSala, int nrRanduri, int nrLocuriPeRand, string tipSala) :nrSalaConcert(++nrTotalSaliConcert)
	{
		if (numeSala != nullptr)
		{
			this->numeSalaConcert = new char[strlen(numeSala) + 1];
			strcpy_s(this->numeSalaConcert, strlen(numeSala) + 1, numeSala);
		}
		else
		{
			this->numeSalaConcert = nullptr;
		}

		if (nrRanduri > 0 && nrLocuriPeRand > 0)
		{
			this->locuriSalaConcert = new int* [nrRanduri];
			for (int i = 0; i < nrRanduri; i++)
			{
				this->locuriSalaConcert[i] = new int[nrLocuriPeRand];
			}
			for (int i = 0; i < nrRanduri; i++)
			{
				for (int j = 0; j < nrLocuriPeRand; j++)
				{
					this->locuriSalaConcert[i][j] = 0;
				}
			}
		}
		else
		{
			this->locuriSalaConcert = nullptr;
		}

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 3; j++)
			{
				orarSalaConcert[i][j] = 0;
			}
		}

		this->nrRanduri = nrRanduri;
		this->nrLocuriPeRand = nrLocuriPeRand;
		this->tipSalaConcert = tipSala;
		pretLocSala = 25;
	}

	SalaConcert(const SalaConcert& s) :nrSalaConcert(s.nrSalaConcert)
	{
		if (strlen(s.numeSalaConcert) != 0)
		{
			this->numeSalaConcert = new char[strlen(s.numeSalaConcert) + 1];
			strcpy_s(this->numeSalaConcert, strlen(s.numeSalaConcert) + 1, s.numeSalaConcert);
		}
		else
		{
			this->numeSalaConcert = nullptr;
		}

		if (s.nrRanduri > 0 && s.nrLocuriPeRand > 0)
		{
			this->locuriSalaConcert = new int* [s.nrRanduri];
			for (int i = 0; i < s.nrRanduri; i++)
			{
				this->locuriSalaConcert[i] = new int[s.nrLocuriPeRand];
			}

			for (int i = 0; i < s.nrRanduri; i++)
			{
				for (int j = 0; j < s.nrLocuriPeRand; j++)
				{
					this->locuriSalaConcert[i][j] = s.locuriSalaConcert[i][j];
				}
			}

		}
		else
		{
			this->locuriSalaConcert = nullptr;
		}

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 3; j++)
			{
				this->orarSalaConcert[i][j] = s.orarSalaConcert[i][j];
			}
		}

		this->nrRanduri = s.nrRanduri;
		this->nrLocuriPeRand = s.nrLocuriPeRand;
		this->tipSalaConcert = s.tipSalaConcert;
		this->pretLocSala = s.pretLocSala;
	}


	SalaConcert& operator=(const SalaConcert& s)
	{
		delete[] numeSalaConcert;
		delete[] locuriSalaConcert;

		if (this != &s)
		{
			if (s.numeSalaConcert != nullptr)
			{
				this->numeSalaConcert = new char[strlen(s.numeSalaConcert) + 1];
				strcpy_s(this->numeSalaConcert, strlen(s.numeSalaConcert) + 1, s.numeSalaConcert);
			}
			else
			{
				this->numeSalaConcert = nullptr;
			}

			if (s.nrRanduri > 0 && s.nrLocuriPeRand > 0)
			{
				this->locuriSalaConcert = new int* [s.nrRanduri];
				for (int i = 0; i < s.nrRanduri; i++)
				{
					this->locuriSalaConcert[i] = new int[s.nrLocuriPeRand];
				}
				for (int i = 0; i < s.nrRanduri; i++)
				{
					for (int j = 0; j < s.nrLocuriPeRand; j++)
					{
						this->locuriSalaConcert[i][j] = s.locuriSalaConcert[i][j];	//modificat aici
					}
				}

			}
			else
			{
				this->locuriSalaConcert = nullptr;
			}

			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 3; j++)
				{
					this->orarSalaConcert[i][j] = s.orarSalaConcert[i][j];
				}
			}

			this->nrRanduri = s.nrRanduri;
			this->nrLocuriPeRand = s.nrLocuriPeRand;
			this->tipSalaConcert = s.tipSalaConcert;
			this->pretLocSala = s.pretLocSala;
		}
		return *this;
	}

	~SalaConcert()
	{
		delete[] numeSalaConcert;
		delete[] locuriSalaConcert;
	}

	//setter adaugat


	static void setNrSala(int nr)
	{
		SalaConcert::nrTotalSaliConcert = nr;
	}

	static int getNrSali()
	{
		return SalaConcert::nrTotalSaliConcert;
	}

	void setDenumireSala(char* denumireSala)
	{
		if (numeSalaConcert != nullptr)
		{
			delete[] numeSalaConcert;
		}
		numeSalaConcert = new char[strlen(denumireSala) + 1];
		strcpy_s(numeSalaConcert, strlen(denumireSala) + 1, denumireSala);
	}


	void setLocuriSala(int rand, int loc)
	{
		locuriSalaConcert[rand - 1][loc - 1] = 1;
	}

	void setOrarSala(int zi, int ora, int idConcert)
	{

		zi -= 1;
		if (ora == 10)
		{
			ora = 0;
		}
		if (ora == 14)
		{
			ora = 1;
		}
		if (ora == 18)
		{
			ora = 2;
		}

		orarSalaConcert[zi][ora] = idConcert;
	}

	//NEW - Verifica daca daca este un concert intr-o anumita zi si la o anumita ora 
	bool ExistaSustinereConcert(int zi, int ora)
	{

		zi -= 1;
		if (ora == 10)
		{
			ora = 0;
		}
		if (ora == 14)
		{
			ora = 1;
		}
		if (ora == 18)
		{
			ora = 2;
		}

		if (orarSalaConcert[zi][ora] != 0)
			return true;
		else
			return false;
	}

	//NEW
	void stergeConcert(int idconcert)
	{

		for (int zi = 0; zi < 7; zi++)
		{
			for (int indx = 0; indx < 3; indx++)
			{

				if (this->orarSalaConcert[zi][indx] == idconcert)
					this->orarSalaConcert[zi][indx] = 0;

			}
		}

	}


	//NEW
	int getnrRanduri()
	{

		return this->nrRanduri;

	}

	//NEW
	int getnrLocuriPeRand()
	{

		return this->nrLocuriPeRand;

	}

	void setPretLocSala(int pret)
	{
		pretLocSala = pret;
	}

	int getIdSala()
	{
		return nrSalaConcert;
	}

	char* getDenumireSala()
	{
		return numeSalaConcert;
	}

	void getLocuriSala()
	{
		int locuriLibere = 0;
		if (locuriSalaConcert != nullptr)
		{
			int** matrice = new int* [nrRanduri];
			for (int i = 0; i < nrRanduri; i++)
			{
				matrice[i] = new int[nrLocuriPeRand];
			}

			cout << numeSalaConcert << ", id " << nrSalaConcert << endl;
			cout << "====================================" << endl;

			for (int i = 0; i < nrRanduri; i++)
			{
				cout << "Rand " << i + 1 << ": ";
				for (int j = 0; j < nrLocuriPeRand; j++)
				{
					cout << " " << locuriSalaConcert[i][j];
					if (locuriSalaConcert[i][j] == 0)
					{
						locuriLibere++;
					}

				}
				cout << endl;
			}
			cout << endl;
			cout << "Locuri disponibile: " << locuriLibere << endl << endl;
		}
	}

	void getOrarSala()
	{
		cout << numeSalaConcert << ", id " << nrSalaConcert << endl;
		cout << "===================" << endl;
		string zile[7] = { "L ", "Ma", "Mi", "J ", "V ", "S ", "D " };
		int ore[3] = { 10, 14, 18 };
		cout << "Ora: ";
		for (int i = 0; i < 3; i++)
		{
			cout << ore[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < 7; i++)
		{
			cout << zile[i] << " : ";
			for (int j = 0; j < 3; j++)
			{
				cout << orarSalaConcert[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}

	//Operator indexare [] - Verifica cate locurile disponibile sunt pe un anumit rand
	int operator[](int indexRand)
	{
		int locuriDisponibile = 0;
		for (int index = 0; index < this->nrLocuriPeRand; index++)
		{
			if (this->locuriSalaConcert[indexRand][index] == 0)
				locuriDisponibile++;
		}
		return locuriDisponibile;
	}

	//operator +  adaugare locuri pe un rand
	SalaConcert operator+(int nrLocuriNoi)
	{
		this->nrLocuriPeRand += nrLocuriNoi;
		return *this;
	}

	//operatorul ++ adauga un rand intr-o sala
	SalaConcert operator++(int i)
	{
		SalaConcert copie = *this;
		nrRanduri++;
		return copie;
	}

	//operatorul cast (catre orice tip) explicit --cout string Sala 5
	//Returneaza tipul salii
	explicit operator string()
	{
		return this->tipSalaConcert;
	}

	//operatorul cast implicit 
	operator char* ()
	{
		return numeSalaConcert;
	}

	//operatorul ! pentru negatie => Returneaza daca sala are mai mult de 5 randuri
	bool operator!()
	{
		if (this->nrRanduri > 5)

			return true;
		else
			return false;
	}
	//Operator conditional (<,>,=<,>=)  -- comparare nrLocuri intre 2 sali
	bool operator>=(SalaConcert& s)
	{
		int locuriSala1 = s.nrRanduri * s.nrLocuriPeRand;
		int locuriSala2 = this->nrRanduri * this->nrLocuriPeRand;

		if (locuriSala1 >= locuriSala2)
			return true;
		else
			return false;
	}

	//operatorul pentru testarea egalitatii dintre 2 obiecte ==  verificare nrLocuri ocupate  intre 2 sali
	bool operator == (SalaConcert& s)
	{
		int locuriOcupateSala1 = 0;
		int locuriOcupateSala2 = 0;

		for (int i = 0; i < this->nrRanduri; i++)
		{
			for (int j = 0; j < this->nrLocuriPeRand; j++)
			{
				if (this->locuriSalaConcert[i][j] == 1)
					locuriOcupateSala1++;
			}
		}

		for (int i = 0; i < s.nrRanduri; i++)
		{
			for (int j = 0; j < s.nrLocuriPeRand; j++)
			{
				if (s.locuriSalaConcert[i][j] == 1)
					locuriOcupateSala2++;
			}
		}

		if (locuriOcupateSala1 == locuriOcupateSala2)
			return true;
		else
			return false;
	}


	//serializare adaugata
	void serializareSala(ofstream& f, SalaConcert s)
	{

		f.write((char*)&nrSalaConcert, sizeof(nrSalaConcert));
		f.write(numeSalaConcert, (long long)strlen(numeSalaConcert) + 1);
		f.write((char*)&nrRanduri, sizeof(nrRanduri));
		f.write((char*)&nrLocuriPeRand, sizeof(nrLocuriPeRand));

		for (int i = 0; i < nrRanduri; i++)
		{
			for (int j = 0; j < nrLocuriPeRand; j++)
			{
				f.write((char*)&locuriSalaConcert[i][j], sizeof(locuriSalaConcert[i][j]));
			}
		}

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				f.write((char*)&orarSalaConcert[i][j], sizeof(orarSalaConcert[i][j]));
			}
		}

		f.write((char*)&pretLocSala, sizeof(pretLocSala));
		int length = tipSalaConcert.length() + 1;
		f.write((char*)&length, sizeof(length));
		f.write(tipSalaConcert.c_str(), length);

	}


	void deserializareSala(ifstream& f, SalaConcert s)
	{

		f.read((char*)&nrSalaConcert, sizeof(nrSalaConcert));

		string buffer = "";
		char c = 0;
		while ((c = f.get()) != 0)
		{
			buffer += c;
		}
		delete[] numeSalaConcert;
		numeSalaConcert = new char[buffer.length() + 1];
		strcpy_s(numeSalaConcert, buffer.length() + 1, buffer.c_str());

		f.read((char*)&nrRanduri, sizeof(nrRanduri));
		f.read((char*)&nrLocuriPeRand, sizeof(nrLocuriPeRand));

		//delete[] locuriSala;
		locuriSalaConcert = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
		{
			locuriSalaConcert[i] = new int[nrLocuriPeRand];
		}
		for (int i = 0; i < nrRanduri; i++)
		{
			for (int j = 0; j < nrLocuriPeRand; j++)
			{
				f.read((char*)&locuriSalaConcert[i][j], sizeof(locuriSalaConcert[i][j]));
			}
		}

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				f.read((char*)&orarSalaConcert[i][j], sizeof(orarSalaConcert[i][j]));
			}
		}

		f.read((char*)&pretLocSala, sizeof(pretLocSala));

		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f.read(aux, length);
		tipSalaConcert = aux;

	}

	friend ostream& operator<< (ostream&, SalaConcert);
	friend istream& operator>> (istream&, SalaConcert&);
	friend class Concert;
};

int SalaConcert::nrTotalSaliConcert = 0; //static


ostream& operator<< (ostream& out, SalaConcert s)
{

	out << "Nr Sala: " << s.nrSalaConcert << endl;
	if (s.numeSalaConcert != nullptr)
	{
		out << "Nume sala: " << s.numeSalaConcert << endl;
	}
	out << "Randuri: " << s.nrRanduri << endl;
	out << "Locuri pe rand: " << s.nrLocuriPeRand << endl;
	out << "Pret loc sala: " << s.pretLocSala << endl;
	out << "Tip sala: " << s.tipSalaConcert << endl << endl;

	s.getOrarSala();

	return out;
}

istream& operator>> (istream& in, SalaConcert& s)
{
	string buffer;

	delete[] s.numeSalaConcert;
	cout << "Nume sala concert: ";
	in >> ws;

	getline(in, buffer);
	s.numeSalaConcert = new char[buffer.length() + 1];
	strcpy_s(s.numeSalaConcert, buffer.length() + 1, buffer.c_str());

	delete[] s.locuriSalaConcert;
	cout << "Randuri: ";
	in >> s.nrRanduri;

	while (in.fail() || s.nrRanduri <= 0)
	{

		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduceti un numar > 0 : ";

		in >> s.nrRanduri;

	}

	in.clear();
	in.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Locuri pe rand: ";
	in >> s.nrLocuriPeRand;

	while (in.fail() || s.nrLocuriPeRand <= 0)
	{

		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduceti un numar > 0 : ";

		in >> s.nrLocuriPeRand;

	}

	in.clear();
	in.ignore(numeric_limits<streamsize>::max(), '\n');


	if (s.nrRanduri > 0 && s.nrLocuriPeRand > 0)
	{
		s.locuriSalaConcert = new int* [s.nrRanduri];
		for (int i = 0; i < s.nrRanduri; i++)
		{
			s.locuriSalaConcert[i] = new int[s.nrLocuriPeRand];
		}
		for (int i = 0; i < s.nrRanduri; i++)
		{
			for (int j = 0; j < s.nrLocuriPeRand; j++)
			{
				s.locuriSalaConcert[i][j] = 0;
			}
		}
	}

	cout << "Pret loc sala: ";
	in >> s.pretLocSala;

	while (in.fail() || s.pretLocSala <= 0)
	{

		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduceti un pret > 0 : ";

		in >> s.pretLocSala;

	}

	in.clear();
	in.ignore(numeric_limits<streamsize>::max(), '\n');


	cout << "Tip sala concert: ";
	in >> ws;
	getline(in, s.tipSalaConcert);

	cout << endl;

	return in;
}


class Concert
{

private:
	const int idConcert;
	static int nrConcerte;
	char* nume;
	int nrZile; //In cate zile este concertul intr-o saptamana
	int* zileSustinereConcert; // Zilele de concert (L, Ma, Mi. etc)
	int nrSustineriConcerteZi; //De catre ori se tine acelasi concert intr-o zi
	int* oreSustineri;////la ce ore se tine intr-o zi
	string gen;
	int durata;
	int idSala;

public:
	Concert() : idConcert(++nrConcerte)
	{
		nume = nullptr;
		nrZile = 0;
		zileSustinereConcert = nullptr;
		nrSustineriConcerteZi = 0;
		oreSustineri = nullptr;
		gen = "";
		durata = 90;
		idSala = 0;
	}

	Concert(char* nume, int nrZile, int* zileProiectii, int nrProiectiiZi, int* oreProiectii, int idSala) : idConcert(++nrConcerte)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
		{
			this->nume = nullptr;
		}

		if (zileProiectii != nullptr && nrZile > 0)
		{
			this->nrZile = nrZile;
			this->zileSustinereConcert = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->zileSustinereConcert[i] = zileProiectii[i];
			}
		}
		else
		{
			this->zileSustinereConcert = nullptr;
			this->nrZile = 0;
		}

		if (oreProiectii != nullptr && nrProiectiiZi > 0)
		{
			this->nrSustineriConcerteZi = nrProiectiiZi;
			this->oreSustineri = new int[nrProiectiiZi];
			for (int i = 0; i < nrProiectiiZi; i++)
			{
				this->oreSustineri[i] = oreProiectii[i];
			}
		}
		else
		{
			this->oreSustineri = nullptr;
			this->nrSustineriConcerteZi = 0;
		}

		gen = "";
		durata = 90;
		this->idSala = idSala;
	}

	Concert(const Concert& f) :idConcert(f.idConcert)
	{

		if (f.nume != nullptr)
		{
			this->nume = new char[strlen(f.nume) + 1];
			strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
		}
		else
		{
			this->nume = nullptr;
		}

		if (f.zileSustinereConcert != nullptr && f.nrZile > 0)
		{
			this->nrZile = f.nrZile;

			this->zileSustinereConcert = new int[f.nrZile];

			for (int i = 0; i < f.nrZile; i++)
			{
				this->zileSustinereConcert[i] = f.zileSustinereConcert[i];
			}
		}
		else
		{
			this->zileSustinereConcert = nullptr;
			this->nrZile = 0;
		}

		if (f.oreSustineri != nullptr && f.nrSustineriConcerteZi > 0)
		{
			this->nrSustineriConcerteZi = f.nrSustineriConcerteZi;
			this->oreSustineri = new int[f.nrSustineriConcerteZi];
			for (int i = 0; i < f.nrSustineriConcerteZi; i++)
			{
				this->oreSustineri[i] = f.oreSustineri[i];
			}
		}
		else
		{
			this->oreSustineri = nullptr;
			this->nrSustineriConcerteZi = 0;
		}

		this->gen = f.gen;
		this->durata = f.durata;
		this->idSala = f.idSala;
	}

	~Concert()
	{
		delete[] nume;
		delete[] zileSustinereConcert;
	}

	Concert& operator=(const Concert& f)
	{
		delete[] nume;
		delete[] zileSustinereConcert;

		if (this != &f)
		{
			if (f.nume != nullptr)
			{
				this->nume = new char[strlen(f.nume) + 1];
				strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
			}
			else
			{
				this->nume = nullptr;
			}

			if (f.zileSustinereConcert != nullptr && nrZile > 0)
			{
				this->zileSustinereConcert = new int[nrZile];

				for (int i = 0; i < nrZile; i++)
				{
					this->zileSustinereConcert[i] = f.zileSustinereConcert[i];
				}
			}
			else
			{
				this->zileSustinereConcert = nullptr;
				nrZile = 0;
			}

			this->gen = f.gen;
			this->durata = f.durata;
			this->idSala = f.idSala;
		}
		return *this;
	}


	static int getnrConcerte()
	{

		return nrConcerte;

	}

	static void setnrConcerte(int nrconcerte)
	{

		Concert::nrConcerte = nrconcerte;

	}

	void setNumeConcert(const char* nume)
	{
		if (this->nume != nullptr)
		{
			delete[] this->nume;
		}
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
		{
			this->nume = nullptr;
		}
	}

	int getIdConcert()
	{
		return idConcert;
	}

	int getIdSala()
	{

		return this->idSala;

	}

	char* getNume()
	{
		if (nume != nullptr)
		{
			return nume;
		}
		return nullptr;
	}

	string getGen()
	{
		return gen;
	}

	int* getProgram()
	{
		return this->zileSustinereConcert;
	}

	int getDurata()
	{
		return durata;
	}

	//operatorul ++ se mai aloca 1 zi la nr de zile pt sustinere concerte
	Concert operator++()
	{
		bool alocare_zi = false;
		int indx = 6;
		do
		{
			if (this->zileSustinereConcert[indx] == 0)
			{
				this->zileSustinereConcert[indx] = 1;
				alocare_zi = true;
			}
			indx--;
		} while ((indx < 0) || (!alocare_zi));

		return *this;
	}

	Concert operator++(int i)
	{
		Concert copie = *this;
		bool alocare_zi = false;
		int indx = 6;

		do
		{
			if (copie.zileSustinereConcert[indx] == 0)
			{
				copie.zileSustinereConcert[indx] = 1;
				alocare_zi = true;
			}
			indx--;
		} while ((indx < 0) || (!alocare_zi));
		return copie;
	}


	explicit operator string()
	{
		return this->nume;
	}

	//Returneaza durata concertului 
	operator int()
	{
		return durata;
	}

	//Care din concertele comparate ruleaza mai multe zile intr-o saptamana
	Concert operator>=(const Concert& f)
	{
		int nr_zile_concert1 = 0, nr_zile_concert2 = 0;
		for (int indx = 0; indx < 7; indx++)
		{
			if (this->zileSustinereConcert[indx] == 1)
				nr_zile_concert1++;

			if (f.zileSustinereConcert[indx] == 1)
				nr_zile_concert2++;
		}

		if (nr_zile_concert1 >= nr_zile_concert2)
			return *this;

		if (nr_zile_concert1 < nr_zile_concert2)
			return f;

	}

	//Verifica daca doua concerte ruleaza in aceleasi zile
	bool operator==(Concert& f)
	{
		for (int indx = 0; indx < 7; indx++)
		{
			if (this->zileSustinereConcert[indx] != f.zileSustinereConcert[indx])
				return false;
		}
		return true;
	}

	void serializareConcert(ofstream& f, Concert concert_crt)
	{

		f.write((char*)&idConcert, sizeof(idConcert));
		//f.write(nume, strlen(nume) + 1);

		f.write(nume, (long long)strlen(nume) + 1);

		f.write((char*)&nrZile, sizeof(nrZile));
		for (int i = 0; i < nrZile; i++)
		{
			f.write((char*)&zileSustinereConcert[i], sizeof(zileSustinereConcert[i]));
		}

		f.write((char*)&nrSustineriConcerteZi, sizeof(nrSustineriConcerteZi));
		for (int i = 0; i < nrSustineriConcerteZi; i++)
		{
			f.write((char*)&oreSustineri[i], sizeof(oreSustineri[i]));
		}

		int length2 = gen.length() + 1;
		f.write((char*)&length2, sizeof(length2));
		f.write(gen.c_str(), length2);

		f.write((char*)&durata, sizeof(durata));
		f.write((char*)&idSala, sizeof(idSala));

	}

	void deserializareFilm(ifstream& f2, Concert concert_crt)
	{

		f2.read((char*)&idConcert, sizeof(idConcert));

		string buffer = "";
		char c = 0;
		while ((c = f2.get()) != 0)
		{
			buffer += c;
		}
		delete[] nume;
		nume = new char[buffer.length() + 1];
		strcpy_s(nume, buffer.length() + 1, buffer.c_str());

		f2.read((char*)&nrZile, sizeof(nrZile));

		delete[] zileSustinereConcert;
		zileSustinereConcert = new int[nrZile];
		for (int i = 0; i < nrZile; i++)
		{
			f2.read((char*)&zileSustinereConcert[i], sizeof(zileSustinereConcert[i]));
		}

		f2.read((char*)&nrSustineriConcerteZi, sizeof(nrSustineriConcerteZi));
		delete[] oreSustineri;
		oreSustineri = new int[nrSustineriConcerteZi];
		for (int i = 0; i < nrSustineriConcerteZi; i++)
		{
			f2.read((char*)&oreSustineri[i], sizeof(oreSustineri[i]));
		}

		int length2 = 0;
		f2.read((char*)&length2, sizeof(length2));
		char* aux = new char[length2];
		f2.read(aux, length2);
		gen = aux;

		f2.read((char*)&durata, sizeof(durata));
		f2.read((char*)&idSala, sizeof(idSala));

	}

	friend ostream& operator<< (ostream&, Concert);
	friend istream& operator>> (istream&, Concert&);
	friend class BiletConcert;
};

int Concert::nrConcerte = 0;

//Operator afisare info Concerte
ostream& operator<< (ostream& out, Concert f)
{
	ifstream fluxDeserializare;
	ofstream fluxSerializare;
	SalaConcert** vectorSali = nullptr;
	int dimensiuneVector = 0;

	fluxDeserializare.open("sala.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
	vectorSali = new SalaConcert * [dimensiuneVector];

	for (int i = 0; i < dimensiuneVector; i++)
	{
		vectorSali[i] = new SalaConcert();
		vectorSali[i]->deserializareSala(fluxDeserializare, *vectorSali[i]);
	}
	fluxDeserializare.close();

	out << endl;
	if (f.idConcert != 0)
		out << "ID Concert: " << f.idConcert << endl;

	if (f.nume != nullptr)
	{
		out << "Nume Concert: " << f.nume;
	}

	out << endl;

	if (f.zileSustinereConcert != nullptr && f.nrZile > 0)
	{
		cout << "Zile sustinere concerte: ";
		for (int i = 0; i < f.nrZile; i++)
		{
			out << f.zileSustinereConcert[i] << " ";
		}
	}

	out << endl;

	if (f.oreSustineri != nullptr && f.nrSustineriConcerteZi > 0)
	{
		out << "Ore sustinere concerte: ";
		for (int i = 0; i < f.nrSustineriConcerteZi; i++)
		{
			out << f.oreSustineri[i] << " ";
		}
	}

	out << endl;

	cout << "Genul Concertului: " << f.gen << endl;
	cout << "Durata Concertului: " << f.durata << endl;
	for (int indx = 0; indx < dimensiuneVector; indx++)
	{
		if (vectorSali[indx]->getIdSala() == f.idSala)
			cout << "Sala: " << vectorSali[indx]->getDenumireSala() << endl;

	}

	return out;
}

//Operator citire info Concerte
istream& operator>> (istream& in, Concert& f)
{

	ifstream fluxDeserializare;
	ofstream fluxSerializare;
	SalaConcert** vectorSali = nullptr;
	int dimensiuneVector = 0;

	fluxDeserializare.open("sala.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
	vectorSali = new SalaConcert * [dimensiuneVector];

	for (int i = 0; i < dimensiuneVector; i++)
	{
		vectorSali[i] = new SalaConcert();
		vectorSali[i]->deserializareSala(fluxDeserializare, *vectorSali[i]);
	}
	fluxDeserializare.close();


	cout << endl << "Nume Concert: ";
	delete[] f.nume;
	char buffer[50];
	in >> ws;
	in.getline(buffer, 49);
	f.nume = new char[strlen(buffer) + 1];
	strcpy_s(f.nume, strlen(buffer) + 1, buffer);

	cout << "Gen: ";
	in >> ws;
	getline(in, f.gen);

	cout << "Durata: ";
	in >> f.durata;

	while (in.fail() || f.durata <= 0)
	{

		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduceti un numar > 0 : ";

		in >> f.durata;

	}

	in.clear();
	in.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;

	bool exista_concert;
	do
	{
		exista_concert = false;
		if (dimensiuneVector == 0)
		{
			cout << "Nu exista sali! Trebuie sa adaugati mai intai o sala! " << endl;
		}
		else
		{
			cout << "Sali existente: ";
			for (int i = 0; i < dimensiuneVector; i++)
			{
				cout << "ID " << vectorSali[i]->getIdSala() << " - " << vectorSali[i]->getDenumireSala() << " ";
			}
		}

		int exista_sala = 0;
		cout << endl << "Selecteaza id-ul salii de concert: ";

		do
		{
			in >> f.idSala;
			while (in.fail() || f.idSala <= 0)
			{

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Selectati un ID valid : ";

				in >> f.idSala;

			}

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');

			for (int i = 0; i < dimensiuneVector; i++)
			{
				if (f.idSala == vectorSali[i]->getIdSala())
				{
					vectorSali[i]->getOrarSala();
					exista_sala = 1;
				}
			}

			if (!exista_sala)
				cout << "Introduceti un ID valid: ";

		} while (!exista_sala);

		cout << "In cate zile pe saptamana va fi concertul sustinut: ";
		in >> f.nrZile;

		while (in.fail() || f.nrZile <= 0 || f.nrZile > 7)
		{

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti un numar cuprins intre 1 si 7 : ";

			in >> f.nrZile;

		}

		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');

		if (f.nrZile > 0)
		{
			bool zi_incorecta;
			cout << "Ex: pentru ziua 'Luni' introduceti cifra 1:" << endl;
			f.zileSustinereConcert = new int[f.nrZile];
			int indx = 0;

			do {
				zi_incorecta = false;
				cout << "Zi " << indx + 1 << ": ";
				in >> f.zileSustinereConcert[indx];

				while (in.fail() || f.zileSustinereConcert[indx] < 1 || f.zileSustinereConcert[indx] > 7)
				{

					in.clear();
					in.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Optiunea este invalida! [Introduceti doar numere de la 1 la 7]";

					in >> f.zileSustinereConcert[indx];

				}

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');

				//Se verifica sa nu se dubleze ziua (ex. 1, 2,1)
				for (int indx2 = 0; indx2 < indx; indx2++)
				{
					if (f.zileSustinereConcert[indx2] == f.zileSustinereConcert[indx])
					{

						cout << "Nu puteti introduce aceeasi de doua ori! " << endl;
						zi_incorecta = true;

					}
				}

				if (!zi_incorecta)
					indx++;

			} while (indx < f.nrZile || zi_incorecta);


			cout << "Introduceti numarul sustineri concertelor pe zi ";
			in >> f.nrSustineriConcerteZi;

			while (in.fail() || f.nrSustineriConcerteZi <= 0 || f.nrSustineriConcerteZi > 3)
			{

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Numarul maxim de concerte intr-o zi este 3! Incearca din nou!" << endl;

				in >> f.nrSustineriConcerteZi;

			}

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');

			f.oreSustineri = new int[f.nrSustineriConcerteZi];
			for (int i = 0; i < f.nrSustineriConcerteZi; i++)
			{
				while (true)
				{
					cout << "Ora [" << i + 1 << "] (11, 15 sau 19): ";
					in >> f.oreSustineri[i];

					while (in.fail() || f.oreSustineri[i] < 11)
					{

						in.clear();
						in.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti o ora valida [11, 15 sau 19]: " << endl;

						in >> f.oreSustineri[i];

					}

					in.clear();
					in.ignore(numeric_limits<streamsize>::max(), '\n');


					if (i == 2 && f.oreSustineri[i] == f.oreSustineri[i - 1] || f.oreSustineri[i] == f.oreSustineri[i - 2])
					{
						cout << "Ora este invalida, incearca din nou!" << endl;
					}
					else if (i == 1 && f.oreSustineri[i] == f.oreSustineri[i - 1])
					{
						cout << "Ora este invalida, incearca din nou!" << endl;
					}
					else if (f.oreSustineri[i] == 11 || f.oreSustineri[i] == 15 || f.oreSustineri[i] == 19)
					{

						for (int j = 0; j < f.nrZile; j++)
						{
							//Se verifica daca este vreun concert la data si orele introduse
							if (vectorSali[f.idSala - 1]->ExistaSustinereConcert(f.zileSustinereConcert[j], f.oreSustineri[i]))
								exista_concert = true;
						}

						break;
					}
					else
					{
						cout << "Ora este invalida, incearca din nou!" << endl;
					}
				}
			}
		}

		if (!exista_concert)
		{
			for (int i = 0; i < f.nrSustineriConcerteZi; i++)
			{
				for (int j = 0; j < f.nrZile; j++)
				{
					vectorSali[f.idSala - 1]->setOrarSala(f.zileSustinereConcert[j], f.oreSustineri[i], f.idConcert);
				}
			}
		}
		else
		{

			cout << "La data si orele selectate este alt concert! Introduceti alte date! " << endl << endl;

		}
	} while (exista_concert);

	fluxSerializare.open("sala.bin", ios::binary);
	fluxSerializare.write((char*)&dimensiuneVector, sizeof(dimensiuneVector));

	for (int i = 0; i < dimensiuneVector; i++)
	{
		if (vectorSali[i] != nullptr)
		{
			vectorSali[i]->serializareSala(fluxSerializare, *vectorSali[i]);
		}
	}

	fluxSerializare.close();

	return in;
}

class BiletConcert
{

private:
	const int codBilet;
	static int nrBileteEmise;
	char* dataConcert;
	int rand;
	int nrLocuri;
	int* locuri;
	int idConcert;

public:

	BiletConcert() : codBilet{ ++nrBileteEmise }
	{
		dataConcert = nullptr;
		rand = 0;
		nrLocuri = 0;
		locuri = nullptr;
		idConcert = 0;
	}

	BiletConcert(char* dataFilm, int rand, int nrLocuri, int* locuri, int idFilm) :codBilet(++nrBileteEmise)
	{

		if (dataFilm != nullptr)
		{

			this->dataConcert = new char[strlen(dataFilm) + 1];
			strcpy_s(this->dataConcert, strlen(dataFilm) + 1, dataFilm);

		}
		else
		{

			this->dataConcert = nullptr;

		}

		this->rand = rand;
		this->nrLocuri = nrLocuri;

		if (locuri != nullptr && nrLocuri > 0)
		{
			this->locuri = new int[nrLocuri];
			for (int i = 0; i < nrLocuri; i++)
				this->locuri[i] = locuri[i];
		}
		else
		{
			this->locuri = nullptr;
			this->nrLocuri = 0;
		}

		this->idConcert = idFilm;
	}

	BiletConcert(const BiletConcert& b) : codBilet{ b.codBilet }
	{
		if (b.dataConcert != nullptr)
		{

			this->dataConcert = new char[strlen(b.dataConcert) + 1];
			strcpy_s(this->dataConcert, strlen(b.dataConcert) + 1, b.dataConcert);

		}
		else
		{

			this->dataConcert = nullptr;
		}

		this->rand = b.rand;
		this->nrLocuri = b.nrLocuri;

		if (b.locuri != nullptr && b.nrLocuri > 0)
		{
			this->locuri = new int[b.nrLocuri];
			for (int i = 0; i < b.nrLocuri; i++)
				this->locuri[i] = b.locuri[i];

		}
		else
		{
			this->locuri = nullptr;
			this->nrLocuri = 0;
		}

		this->idConcert = b.idConcert;
	}

	BiletConcert& operator=(const BiletConcert& b)
	{

		delete[] dataConcert;
		delete[] locuri;

		if (this != &b)
		{

			if (b.dataConcert != nullptr)
			{

				this->dataConcert = new char[strlen(b.dataConcert) + 1];
				strcpy_s(this->dataConcert, strlen(b.dataConcert) + 1, b.dataConcert);

			}
			else
			{

				this->dataConcert = nullptr;
			}

			this->rand = b.rand;
			if (b.locuri != nullptr && b.nrLocuri > 0)
			{
				this->nrLocuri = b.nrLocuri;
				this->locuri = new int[b.nrLocuri];

				for (int i = 0; i < b.nrLocuri; i++)
					this->locuri[i] = b.locuri[i];

			}
			else
			{
				this->locuri = nullptr;
				this->nrLocuri = 0;
			}

			this->idConcert = b.idConcert;
		}
		return*this;
	}

	~BiletConcert()
	{
		delete[] dataConcert;
		delete[] locuri;
	}

	
	BiletConcert operator++()
	{
		nrLocuri++;
		return *this;
	}

	BiletConcert operator++(int x)
	{
		BiletConcert copie_bilet = *this;
		copie_bilet.nrLocuri++;

		return copie_bilet;

	}

	explicit operator string()
	{
		return dataConcert;
	}

	bool operator>=(BiletConcert& b)
	{
		if (nrLocuri >= b.nrLocuri)
			return true;
		else
			return false;
	}

	//NEW
	int getNrBileteEmise()
	{
		return BiletConcert::nrBileteEmise;
	}

	//NEW
	int getcodBIlet()
	{
		return codBilet;
	}

	//NEW
	void setdataConcert(string dataConcert)
	{

		if (dataConcert != "")
		{

			this->dataConcert = new char[dataConcert.length() + 1];
			strcpy_s(this->dataConcert, dataConcert.length() + 1, dataConcert.c_str());

		}
		else
		{

			this->dataConcert = nullptr;
		}

	}

	//NEW
	void setrand(int rand)
	{

		if (rand > 0)
		{

			this->rand = rand;
		}
		else
		{

			this->rand = 0;
		}

	}

	//NEW
	void setlocuri(int* locuri, int nrLocuri)
	{

		if (nrLocuri > 0 && locuri != nullptr)
		{

			this->nrLocuri = nrLocuri;
			this->locuri = new int[nrLocuri];

			for (int indx = 0; indx < nrLocuri; indx++)
				this->locuri[indx] = locuri[indx];
		}
		else
		{

			this->nrLocuri = 0;
			this->locuri = nullptr;
		}

	}

	//NEW
	static int getnrBileteEmise()
	{

		return nrBileteEmise;

	}

	//NEW
	static void setnrBileteEmise(int nrbilete)
	{

		BiletConcert::nrBileteEmise = nrbilete;

	}

	//Validare data
	static bool validare_date(string Data)
	{

		bool data_corecta = true;

		//1. Verificare data maxim 10 caractere
		if (Data.length() < 10)
		{

			data_corecta = false;
		}
		else
		{

			//2. Se incarac ziua, luna anul
			int zi{ 0 }, luna{ 0 }, an{ 0 };
			int poz_sep_zi{ 0 }, poz_sep_luna{ 0 };

			poz_sep_zi = Data.find(".");
			zi = stoi(Data.substr(0, poz_sep_zi));

			poz_sep_luna = Data.find(".", poz_sep_zi + 1);
			luna = stoi(Data.substr(poz_sep_zi + 1, poz_sep_luna));

			an = stoi(Data.substr(poz_sep_luna + 1, 4));

			if (an < 2020)
				data_corecta = false;

			if (luna >= 1 && luna <= 12)
			{
				switch (luna)
				{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					if (zi > 31 || zi <= 0)
						data_corecta = false;
					break;

				case 2:
					if (zi > 28 || zi <= 0)
						data_corecta = false;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					if (zi > 31 || zi <= 0)
						data_corecta = false;
					break;

				default:
					data_corecta = false;
				}
			}
			else
			{

				data_corecta = false;

			}
		}
		return data_corecta;
	}

	//NEW
	int getrand()
	{

		return this->rand;
	}

	//NEW
	int getnrlocuri()
	{

		return this->nrLocuri;

	}

	//NEW
	int* getLocuri()
	{

		return this->locuri;

	}

	//NEW
	char* getdataConcert()
	{

		return this->dataConcert;

	}

	void serializareBilet(ofstream& f, BiletConcert bilet_crt)
	{

		f.write((char*)&codBilet, sizeof(codBilet));
		f.write((char*)&idConcert, sizeof(idConcert));

		f.write(dataConcert, (long long)strlen(dataConcert) + 1);

		f.write((char*)&rand, sizeof(rand));
		f.write((char*)&nrLocuri, sizeof(nrLocuri));

		for (int indx = 0; indx < nrLocuri; indx++)
			f.write((char*)&locuri[indx], sizeof(locuri[indx]));

	}

	void deserializareBilet(ifstream& f, BiletConcert bilet_crt)
	{

		f.read((char*)&codBilet, sizeof(codBilet));
		f.read((char*)&idConcert, sizeof(idConcert));

		string buffer = "";
		char c = 0;
		while ((c = f.get()) != 0)
		{
			buffer += c;
		}
		delete[] dataConcert;
		dataConcert = new char[buffer.length() + 1];
		strcpy_s(dataConcert, buffer.length() + 1, buffer.c_str());

		f.read((char*)&rand, sizeof(rand));

		delete[] locuri;
		f.read((char*)&nrLocuri, sizeof(nrLocuri));
		locuri = new int[nrLocuri];

		for (int indx = 0; indx < nrLocuri; indx++)
			f.read((char*)&locuri[indx], sizeof(locuri[indx]));

	}

	friend istream& operator>> (istream&, BiletConcert&);
	friend ostream& operator<< (ostream&, BiletConcert);
	friend ofstream& operator<<(ofstream&, BiletConcert);
	friend ifstream& operator>>(ifstream&, BiletConcert&);

	friend class RezervareConcert;
};
int BiletConcert::nrBileteEmise = 0;

//Operator afisare info Bilete
ostream& operator<< (ostream& out, BiletConcert b)
{
	ifstream fluxDeserializare;
	ofstream fluxSerializare;
	Concert** vectorConcerte = nullptr;
	SalaConcert** vectorisali = nullptr;
	int dimensiuneVector = 0, dimensiuneVectorSali = 0;
	int randuri_sala{ 0 }, nrlocuri_rand{ 0 };

	//Deserializare filme
	fluxDeserializare.open("concert.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
	vectorConcerte = new Concert * [dimensiuneVector];

	for (int i = 0; i < dimensiuneVector; i++)
	{
		vectorConcerte[i] = new Concert();
		vectorConcerte[i]->deserializareFilm(fluxDeserializare, *vectorConcerte[i]);
	}
	fluxDeserializare.close();

	//Deserializare sali
	fluxDeserializare.open("sala.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVectorSali, sizeof(dimensiuneVectorSali));
	vectorisali = new SalaConcert * [dimensiuneVectorSali];

	for (int i = 0; i < dimensiuneVectorSali; i++)
	{
		vectorisali[i] = new SalaConcert();
		vectorisali[i]->deserializareSala(fluxDeserializare, *vectorisali[i]);
	}
	fluxDeserializare.close();


	out << "ID Bilet : " << b.codBilet << endl;

	for (int indx = 0; indx < dimensiuneVector; indx++)
	{

		if (vectorConcerte[indx]->getIdConcert() == b.idConcert)
			out << "Concert : " << vectorConcerte[indx]->getNume() << endl;

	}

	out << "Data Concert : " << b.dataConcert << endl;

	for (int indx = 0; indx < dimensiuneVector; indx++)
	{

		if (vectorConcerte[indx]->getIdConcert() == b.idConcert)
		{
			for (int indx2 = 0; indx2 < dimensiuneVectorSali; indx2++)
			{

				if (vectorConcerte[indx]->getIdSala() == indx2)
				{

					out << "Sala : " << vectorisali[indx2]->getDenumireSala() << endl;

				}
			}

		}

	}

	out << "Rand : " << b.rand << endl;
	out << "Locuri rezervate : ";
	for (int indx = 0; indx < b.nrLocuri; indx++)
		out << b.locuri[indx] << " ";

	out << endl << endl;
	return out;
}

//Operator citire info Bilete
istream& operator>> (istream& in, BiletConcert& b)
{
	ifstream fluxDeserializare;
	ofstream fluxSerializare;
	Concert** vectorConcerte = nullptr;
	SalaConcert** vectorisali = nullptr;
	BiletConcert** VectorBilete = nullptr;
	int dimensiuneVector = 0, dimensiuneVectorSali = 0, dimensiuneVectorBIlete = 0;
	int randuri_sala{ 0 }, nrlocuri_rand{ 0 };

	//Deserializare filme
	fluxDeserializare.open("concert.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
	vectorConcerte = new Concert * [dimensiuneVector];

	for (int i = 0; i < dimensiuneVector; i++)
	{
		vectorConcerte[i] = new Concert();
		vectorConcerte[i]->deserializareFilm(fluxDeserializare, *vectorConcerte[i]);
	}
	fluxDeserializare.close();

	//Deserializare sali
	fluxDeserializare.open("sala.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVectorSali, sizeof(dimensiuneVectorSali));
	vectorisali = new SalaConcert * [dimensiuneVectorSali];

	for (int i = 0; i < dimensiuneVectorSali; i++)
	{
		vectorisali[i] = new SalaConcert();
		vectorisali[i]->deserializareSala(fluxDeserializare, *vectorisali[i]);
	}
	fluxDeserializare.close();

	//Deserializare bilete
	fluxDeserializare.open("bilet.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVectorBIlete, sizeof(dimensiuneVectorBIlete));
	VectorBilete = new BiletConcert * [dimensiuneVectorBIlete];

	for (int i = 0; i < dimensiuneVectorBIlete; i++)
	{
		VectorBilete[i] = new BiletConcert();
		VectorBilete[i]->deserializareBilet(fluxDeserializare, *VectorBilete[i]);
	}
	fluxDeserializare.close();

	cout << "Lista concerte :";
	for (int indx = 0; indx < dimensiuneVector; indx++)
	{

		cout << " ID " << vectorConcerte[indx]->getIdConcert() << " - " << vectorConcerte[indx]->getNume() << " ";

	}

	int exista_concert = 0;
	cout << endl << "ID concert: ";
	do
	{

		in >> b.idConcert;

		//Model validare int
		while (in.fail() || b.idConcert <= 0)
		{

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti un ID valid: ";

			in >> b.idConcert;

		}

		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');


		for (int i = 0; i < dimensiuneVector; i++)
		{
			if (b.idConcert == vectorConcerte[i]->getIdConcert())
			{
				exista_concert = 1;
			}
		}
		if (exista_concert == 0)
			cout << "Introduceti un ID valid: ";

	} while (exista_concert == 0);

	string buffer;

	delete[] b.dataConcert;
	cout << "Data Concertului (ZZ.LL.AAAA): ";
	in >> ws;
	getline(in, buffer);

	while (!BiletConcert::validare_date(buffer))
	{
		cout << "Introduceti o data valida (ZZ.LL.AAAA): ";
		in >> ws;
		getline(in, buffer);

	}

	b.dataConcert = new char[buffer.length() + 1];
	strcpy_s(b.dataConcert, buffer.length() + 1, buffer.c_str());

	cout << "Detalii sala: ";
	for (int indx = 0; indx < dimensiuneVector; indx++)
	{

		if (b.idConcert == vectorConcerte[indx]->getIdConcert())
		{
			int idsala = vectorConcerte[indx]->getIdSala();

			for (int indx_sala = 0; indx_sala < dimensiuneVectorSali; indx_sala++)
			{

				if (vectorisali[indx_sala]->getIdSala() == idsala)
				{

					cout << "Denumire : " << vectorisali[indx_sala]->getDenumireSala() << " | ";

					randuri_sala = vectorisali[indx_sala]->getnrRanduri();
					cout << "Nr. randuri: " << randuri_sala << " | ";

					nrlocuri_rand = vectorisali[indx_sala]->getnrLocuriPeRand();
					cout << "Locuri pe rand : " << nrlocuri_rand << " | " << endl;

				}
			}

		}
	}

	bool eroare_bilet;
	do {
		eroare_bilet = false;
		cout << "Numarul randului: ";
		do
		{
			in >> b.rand;
			//Model validare int
			while (in.fail() || b.rand <= 0)
			{

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduceti un numar valid: ";

				in >> b.rand;

			}

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');

			if (b.rand > randuri_sala)
				cout << "Numarul randului nu trebuie sa depaseasca numarul de randuri din sala: ";

		} while (b.rand > randuri_sala);


		cout << "Numarul de locuri dorite: ";
		do
		{
			in >> b.nrLocuri;
			//Model validare int
			while (in.fail() || b.nrLocuri <= 0)
			{

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduceti un numar valid : ";

				in >> b.nrLocuri;

			}

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');


			if (b.nrLocuri > nrlocuri_rand)
				cout << "Numarul de locuri selectate nu trebuie sa depaseasca numarul de locuri de pe rand: ";

		} while (b.nrLocuri > nrlocuri_rand);

		delete[] b.locuri;
		b.locuri = new int[b.nrLocuri];
		bool eroare_rezervare;
		for (int indx = 0; indx < b.nrLocuri; indx++)
		{
			cout << "Locul [" << indx + 1 << "]: ";

			do
			{
				eroare_rezervare = false;
				in >> b.locuri[indx];
				//Model validare int

				while (in.fail() || b.locuri[indx] <= 0)
				{

					in.clear();
					in.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar valid : ";

					in >> b.locuri[indx];;

				}
				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');


				//1. Se valideaza ca locul sa nu fie > ca nr de locui de pe rand
				if (b.locuri[indx] > nrlocuri_rand)
				{

					cout << "Numarul locului selectat nu trebuie sa depaseasca numarul de locuri de pe rand: ";
					eroare_rezervare = true;
				}
				else
				{
					//2. se verifica ca locul selectat sa nu fi fost deja rezervat pe acelas bilet
					for (int indx2 = 0; indx2 < indx; indx2++)
					{

						if (b.locuri[indx] == b.locuri[indx2])
						{
							cout << "Locul este deja rezervat pe acelasi bilet!" << endl;
							cout << "Locul [" << indx + 1 << "]: ";
							eroare_rezervare = true;

						}

					}
				}

			} while (eroare_rezervare);

		}

		//Se verifica daca locuri au fost deja rezervate
		for (int indx_bilete = 0; indx_bilete < dimensiuneVectorBIlete; indx_bilete++)
		{

			if (!strcmp(b.dataConcert, VectorBilete[indx_bilete]->getdataConcert()) && b.rand == VectorBilete[indx_bilete]->getrand())
			{

				for (int indx_loc_bilet = 0; indx_loc_bilet < b.nrLocuri; indx_loc_bilet++)
				{
					for (int indx_loc = 0; indx_loc < VectorBilete[indx_bilete]->getnrlocuri(); indx_loc++)
					{

						if (b.locuri[indx_loc_bilet] == VectorBilete[indx_bilete]->getLocuri()[indx_loc])
							eroare_bilet = true;

					}
				}

			}

		}

		if (eroare_bilet)
			cout << "Locurile au fost deja rezervate!" << endl;


	} while (eroare_bilet);

	return in;
}

//Operator info Bilete salvare in fisier text
ofstream& operator<<(ofstream& file_out, BiletConcert b)
{

	if (file_out.is_open())
	{
		file_out << b.codBilet << endl;
		file_out << b.dataConcert << endl;
		file_out << b.rand << endl;
		file_out << b.nrLocuri << endl;
		for (int indx = 0; indx < b.nrLocuri; indx++)
		{

			file_out << b.locuri[indx] << endl;
		}
	}

	return file_out;
}

//Operator info Bilete citire din fisier text
ifstream& operator>>(ifstream& file_in, BiletConcert& b)
{
	string buffer;
	int idbilet, rand, nrlocuri;
	int* locuri;

	if (file_in.is_open())
	{
		file_in >> idbilet;

		file_in >> ws;
		getline(file_in, buffer);
		b.setdataConcert(buffer);

		file_in >> rand;
		b.setrand(rand);

		file_in >> nrlocuri;
		locuri = new int[nrlocuri];
		for (int indx = 0; indx < nrlocuri; indx++)
			file_in >> locuri[indx];

		b.setlocuri(locuri, nrlocuri);
	}

	return file_in;
}


class Cumparator
{
private:
	const int idCumparatori;
	static int nrCumparatori;
	char* numeCumparator;
	int nrCarduri;
	int* nrAsociatCard;
	string numeUtilizatorCumparator;

public:
	Cumparator() : idCumparatori(++nrCumparatori)
	{
		numeCumparator = nullptr;
		nrCarduri = 0;
		nrAsociatCard = nullptr;
		numeUtilizatorCumparator = "";
	}

	Cumparator(char* nume, int nrCarduri, int* nrAsociatCard, string numeUtilizatorClient) : idCumparatori(++nrCumparatori)
	{
		if (nume != nullptr)
		{
			this->numeCumparator = new char[strlen(nume) + 1];
			strcpy_s(this->numeCumparator, strlen(nume) + 1, nume);
		}
		else
		{
			this->numeCumparator = nullptr;
		}

		if (nrAsociatCard != nullptr && nrCarduri > 0)
		{
			this->nrAsociatCard = new int[nrCarduri];
			for (int i = 0; i < nrCarduri; i++)
			{
				this->nrAsociatCard[i] = nrAsociatCard[i];
			}
			this->nrCarduri = nrCarduri;
		}
		else
		{
			this->nrAsociatCard = nullptr;
			this->nrCarduri = 0;
		}

		this->numeUtilizatorCumparator = numeUtilizatorClient;
	}

	Cumparator(const Cumparator& c) : idCumparatori(c.idCumparatori)
	{
		if (c.numeCumparator != nullptr)
		{
			numeCumparator = new char[strlen(c.numeCumparator) + 1];
			strcpy_s(numeCumparator, strlen(c.numeCumparator) + 1, c.numeCumparator);
		}
		else
		{
			numeCumparator = nullptr;
		}

		if (c.nrAsociatCard != nullptr && c.nrCarduri > 0)
		{
			nrAsociatCard = new int[c.nrCarduri];
			for (int i = 0; i < c.nrCarduri; i++)
			{
				nrAsociatCard[i] = c.nrAsociatCard[i];
			}
			nrCarduri = c.nrCarduri;
		}
		else
		{
			nrAsociatCard = nullptr;
			nrCarduri = 0;
		}

		numeUtilizatorCumparator = c.numeUtilizatorCumparator;
	}

	~Cumparator()
	{
		delete[] numeCumparator;
		delete[] nrAsociatCard;
	}

	Cumparator& operator=(Cumparator& c)
	{
		delete[] numeCumparator;
		delete[] nrAsociatCard;

		if (c.numeCumparator != nullptr)
		{
			numeCumparator = new char[strlen(c.numeCumparator) + 1];
			strcpy_s(numeCumparator, strlen(c.numeCumparator) + 1, c.numeCumparator);
		}
		else
		{
			numeCumparator = nullptr;
		}

		if (c.nrAsociatCard != nullptr && c.nrCarduri > 0)
		{
			nrAsociatCard = new int[c.nrCarduri];
			for (int i = 0; i < c.nrCarduri; i++)
			{
				nrAsociatCard[i] = c.nrAsociatCard[i];
			}
			nrCarduri = c.nrCarduri;
		}
		else
		{
			nrAsociatCard = nullptr;
			nrCarduri = 0;
		}

		numeUtilizatorCumparator = c.numeUtilizatorCumparator;

		return *this;
	}

	int getIdCumparator()
	{
		return idCumparatori;
	}

	static int getNrCumparatori()
	{

		return nrCumparatori;

	}

	static void setNrCumparatori(int nrCumparatori)
	{

		Cumparator::nrCumparatori = nrCumparatori;

	}
	char* getNume()
	{
		if (numeCumparator == nullptr)
			return nullptr;
		char* copie = new char[strlen(numeCumparator) + 1];
		strcpy_s(copie, strlen(numeCumparator) + 1, numeCumparator);
		return copie;
	}

	void setNume(char* nume)
	{
		if (nume != nullptr)
		{
			if (this->numeCumparator != nullptr)
				delete[]this->numeCumparator;
			this->numeCumparator = new char[strlen(nume) + 1];
			strcpy_s(this->numeCumparator, strlen(nume) + 1, nume);
		}
	}


	int* getNrAsociatCard()
	{
		if (nrAsociatCard != nullptr)
		{
			int* copie = new int[nrCarduri];
			for (int i = 0; i < nrCarduri; i++)
			{
				copie[i] = nrAsociatCard[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getNrCarduri()
	{
		return nrCarduri;
	}

	void setNrAsociatCard(int* nrAsociatCard, int nrCarduri)
	{
		if (nrAsociatCard != nullptr && nrCarduri > 0)
		{
			if (this->nrAsociatCard != nullptr)
				delete[]this->nrAsociatCard;
			this->nrAsociatCard = new int[nrCarduri];
			for (int i = 0; i < nrCarduri; i++)
			{
				this->nrAsociatCard[i] = nrAsociatCard[i];
			}
		}
	}

	string getNumeUtilizatorCumparator()
	{
		return numeUtilizatorCumparator;
	}

	int operator[](int index)
	{
		if (index >= 0 && index > nrCarduri)
		{
			return nrAsociatCard[index];
		}
		return -1;
	}

	friend Cumparator operator+(int, Cumparator);

	//Creste numarul de zile selectate //forma 1: functie metoda
	Cumparator operator++()
	{
		nrCarduri++;
		return *this;
	}

	//forma 2:functie globala
	friend Cumparator operator++(Cumparator);

	explicit operator string()
	{
		return this->numeCumparator;
	}

	//Verifica daca clientul a selectat un numar de carduri
	bool operator!()
	{
		if (nrCarduri == 0)
			return true;
		return false;
	}

	//Compara numarul de zile selectate de doi clienti
	Cumparator operator>=(const Cumparator& c)
	{
		if (nrCarduri >= c.nrCarduri)
			return *this;
		return c;
	}

	//Verifica daca doi clienti au selectat acelasi numar de carduri
	bool operator==(Cumparator& c)
	{
		if (nrCarduri == c.nrCumparatori)
			return true;
		return false;
	}


	void serializeCumparator(ofstream& f, Cumparator cumparator_crt)
	{
		f.write((char*)&idCumparatori, sizeof(idCumparatori));

		f.write(numeCumparator, (long long)strlen(numeCumparator) + 1);

		f.write((char*)&nrCarduri, sizeof(nrCarduri));
		for (int i = 0; i < nrCarduri; i++)
		{
			f.write((char*)&nrAsociatCard[i], sizeof(nrAsociatCard[i]));
		}

		int length = numeUtilizatorCumparator.length() + 1;
		f.write((char*)&length, sizeof(length));
		f.write(numeUtilizatorCumparator.c_str(), length);

	}

	void deserializeClient(ifstream& f2, Cumparator cumparator_crt)
	{
		f2.read((char*)&idCumparatori, sizeof(idCumparatori));

		string buffer = "";
		char c = 0;
		while ((c = f2.get()) != 0)
		{
			buffer += c;
		}
		delete[] numeCumparator;
		numeCumparator = new char[buffer.length() + 1];
		strcpy_s(numeCumparator, buffer.length() + 1, buffer.c_str());

		f2.read((char*)&nrCarduri, sizeof(nrCarduri));
		delete[] nrAsociatCard;
		nrAsociatCard = new int[nrCarduri];
		for (int i = 0; i < nrCarduri; i++)
		{
			f2.read((char*)&nrAsociatCard[i], sizeof(nrAsociatCard[i]));
		}

		int length = 0;
		f2.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f2.read(aux, length);
		numeUtilizatorCumparator = aux;

	}

	friend ostream& operator<<(ostream&, Cumparator);
	friend istream& operator>>(istream&, Cumparator&);
	friend class RezervareConcert;
};

int Cumparator::nrCumparatori = 0;

ostream& operator<<(ostream& out, Cumparator c)
{
	out << "ID client: " << c.idCumparatori << endl;
	if (c.numeCumparator != nullptr)
	{
		out << endl << "Nume: " << c.numeCumparator << endl;
	}
	out << "Email: " << c.numeUtilizatorCumparator << endl;

	if (c.nrCarduri > 0)
	{
		out << "Numar carduri " << c.nrCarduri << endl;
	}
	else if (c.nrCarduri == 0)
	{
		cout << "Nu aveti carduri inregistrate" << endl;
	}

	if (c.nrAsociatCard != nullptr)
	{
		for (int i = 0; i < c.nrCarduri; i++)
		{
			out << "Card " << i + 1 << ": " << c.nrAsociatCard[i] << endl;
		}
	}

	out << "Nume utilizator cumparator" << endl;
	out << c.numeUtilizatorCumparator;

	cout << endl;
	return out;
}

istream& operator>>(istream& in, Cumparator& c)
{
	cout << endl << "Nume: ";
	delete[] c.numeCumparator;
	char buffer[50];
	in >> ws;
	in.getline(buffer, 49);
	c.numeCumparator = new char[strlen(buffer) + 1];
	strcpy_s(c.numeCumparator, strlen(buffer) + 1, buffer);

	cout << endl << "Email: ";
	//in >> ws;
	getline(in, c.numeUtilizatorCumparator);
	cout << endl;

	if (c.nrAsociatCard != nullptr)
	{
		delete[] c.nrAsociatCard;
	}

	cout << "Doriti sa salvati datele cardului pentru plati ulterioare? Apasati 1 pentru DA, 0 pentru NU: ";
	int optiune = 0;
	in >> optiune;
	if (optiune == 1)
	{
		cout << endl << "Introduceti numarul de carduri pe care doriti sa le salvati: ";
		in >> c.nrCarduri;

		while (in.fail() || c.nrCarduri <= 0)
		{

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti un numar valid > 0 :" << endl;

			in >> c.nrCarduri;

		}
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');

		if (c.nrCarduri > 0)
		{

			c.nrAsociatCard = new int[c.nrCarduri];
			for (int i = 0; i < c.nrCarduri; i++)
			{
				cout << "Intordu numarul asociat pentru ";
				cout << "Cardul " << i + 1 << " (max. 9 cifre): ";
				in >> c.nrAsociatCard[i];

				while (in.fail() || c.nrAsociatCard[i] <= 0)
				{

					in.clear();
					in.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Numar invalid!  Cardul " << i + 1 << " (max. 9 cifre): " << endl;

					in >> c.nrAsociatCard[i];

				}

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');

			}
		}
		else
		{
			c.nrCarduri = 0;
			c.nrAsociatCard = nullptr;
		}
		cout << endl;
	}

	cout << "Nume utilizator cumparator ";
	in >> c.numeUtilizatorCumparator;

	return in;
}

//Creste numarul de carduri selectate
Cumparator operator+(int x, Cumparator c)
{
	c.nrCarduri += x;
	return c;
}

Cumparator operator++(Cumparator c)
{
	c.nrCarduri++;
	return c;
}

class RezervareConcert
{
private:
	const int idRezervareConcert;
	static int nrRezervari;
	char* dataRezervareConcert;
	int* nrBileteRezervate;
	int nrBilete;
	bool achitat;
	string numeUtilizatorCumparator;
	int idBilet;

public:
	RezervareConcert() :idRezervareConcert(++nrRezervari)
	{
		dataRezervareConcert = nullptr;
		nrBileteRezervate = nullptr;
		nrBilete = 0;
		achitat = false;
		numeUtilizatorCumparator = "";
		idBilet = 0;
	}

	RezervareConcert(int nrBilete) :idRezervareConcert(++nrRezervari)
	{
		dataRezervareConcert = new char[] {""};
		this->nrBilete = nrBilete;
		nrBileteRezervate = new int[nrBilete];
		achitat = false;
		numeUtilizatorCumparator = "";
		idBilet = 0;
	}

	RezervareConcert(char* dataRezervare, int* nrBileteRezervate, int nrBilete, bool achitat, string numeUtilizatorClient, int idBilet) :idRezervareConcert(++nrRezervari)
	{
		if (dataRezervare != nullptr)
		{
			this->dataRezervareConcert = new char[strlen(dataRezervare) + 1];
			strcpy_s(this->dataRezervareConcert, strlen(dataRezervare) + 1, dataRezervare);
		}
		else
		{
			this->dataRezervareConcert = nullptr;
		}

		if (nrBileteRezervate != nullptr && nrBilete < 0)
		{
			this->nrBilete = nrBilete;
			this->nrBileteRezervate = new int[nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				this->nrBileteRezervate[i] = nrBileteRezervate[i];
			}
		}
		else
		{
			this->nrBileteRezervate = nullptr;
			this->nrBilete = 0;
		}
		this->achitat = achitat;
		this->numeUtilizatorCumparator = numeUtilizatorClient;
		this->idBilet = idBilet;

	}

	RezervareConcert(const RezervareConcert& r) :idRezervareConcert(r.idRezervareConcert)
	{
		if (r.dataRezervareConcert != nullptr)
		{
			dataRezervareConcert = new char[strlen(r.dataRezervareConcert) + 1];
			strcpy_s(dataRezervareConcert, strlen(r.dataRezervareConcert) + 1, r.dataRezervareConcert);
		}
		else
		{
			dataRezervareConcert = nullptr;
		}

		if (r.nrBileteRezervate != nullptr && nrBilete > 0)
		{
			nrBilete = r.nrBilete;
			nrBileteRezervate = new int[r.nrBilete];
			for (int i = 0; i < r.nrBilete; i++)
			{
				nrBileteRezervate[i] = r.nrBileteRezervate[i];
			}
		}
		else
		{
			nrBileteRezervate = nullptr;
			nrBilete = 0;
		}
		achitat = r.achitat;
		numeUtilizatorCumparator = r.numeUtilizatorCumparator;
		idBilet = r.idBilet;
	}

	~RezervareConcert()
	{
		delete[]dataRezervareConcert;
		delete[]nrBileteRezervate;
	}

	RezervareConcert& operator=(const RezervareConcert& r)
	{
		delete[]dataRezervareConcert;
		delete[]nrBileteRezervate;
		if (r.dataRezervareConcert != nullptr)
		{
			dataRezervareConcert = new char[strlen(r.dataRezervareConcert) + 1];
			strcpy_s(dataRezervareConcert, strlen(r.dataRezervareConcert) + 1, r.dataRezervareConcert);
		}
		else
		{
			dataRezervareConcert = nullptr;
		}

		if (r.nrBileteRezervate != nullptr)
		{
			nrBilete = r.nrBilete;
			nrBileteRezervate = new int[r.nrBilete];
			for (int i = 0; i < r.nrBilete; i++)
			{
				nrBileteRezervate[i] = r.nrBileteRezervate[i];
			}
		}
		else
		{
			nrBileteRezervate = nullptr;
			nrBilete = 0;
		}
		achitat = r.achitat;
		numeUtilizatorCumparator = r.numeUtilizatorCumparator;
		idBilet = r.idBilet;

		return *this;
	}

	int getIdRezervareConcert()
	{
		return idRezervareConcert;
	}

	static int getNrRezervari()
	{

		return nrRezervari;

	}

	static void setNrRezervari(int nrRezervari)
	{

		RezervareConcert::nrRezervari = nrRezervari;

	}

	//Validare data
	static bool validare_date(string Data)
	{

		bool data_corecta = true;

		//1. Verificare data maxim 10 caractere
		if (Data.length() < 10)
		{

			data_corecta = false;
		}
		else
		{

			//2. Se incarac ziua, luna anul
			int zi{ 0 }, luna{ 0 }, an{ 0 };
			int poz_sep_zi{ 0 }, poz_sep_luna{ 0 };

			poz_sep_zi = Data.find(".");
			zi = stoi(Data.substr(0, poz_sep_zi));

			poz_sep_luna = Data.find(".", poz_sep_zi + 1);
			luna = stoi(Data.substr(poz_sep_zi + 1, poz_sep_luna));

			an = stoi(Data.substr(poz_sep_luna + 1, 4));

			if (an < 2021)
				data_corecta = false;

			if (luna >= 1 && luna <= 12)
			{
				switch (luna)
				{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					if (zi > 31 || zi <= 0)
						data_corecta = false;
					break;

				case 2:
					if (zi > 28 || zi <= 0)
						data_corecta = false;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					if (zi > 31 || zi <= 0)
						data_corecta = false;
					break;

				default:
					data_corecta = false;
				}
			}
			else
			{

				data_corecta = false;

			}
		}
		return data_corecta;
	}

	char* getDataRezervareConcert()
	{
		if (dataRezervareConcert == nullptr)
			return nullptr;
		char* copie = new char[strlen(dataRezervareConcert) + 1];
		strcpy_s(copie, strlen(dataRezervareConcert) + 1, dataRezervareConcert);
		return copie;
	}

	void setDataRezervareConcert(char* dataRezervareConcert)
	{
		if (dataRezervareConcert != nullptr)
		{
			if (this->dataRezervareConcert != nullptr)
				delete[]this->dataRezervareConcert;
			this->dataRezervareConcert = new char[strlen(dataRezervareConcert) + 1];
			strcpy_s(this->dataRezervareConcert, strlen(dataRezervareConcert) + 1, dataRezervareConcert);

		}
	}

	int* getNrBileteRezervate()
	{
		if (nrBileteRezervate != nullptr)
		{
			int* copie = new int[nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				copie[i] = nrBileteRezervate[i];
			}
			return copie;
		}
		return nullptr;
	}

	int getNrBilete()
	{
		return nrBilete;
	}

	void setNrBileteRezervate(int* nrBileteRezervate, int nrBilete)
	{
		if (nrBileteRezervate != nullptr && nrBilete > 0)
		{
			if (this->nrBileteRezervate != nullptr)
				delete[]this->nrBileteRezervate;
			this->nrBileteRezervate = new int[nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				this->nrBileteRezervate[i] = nrBileteRezervate[i];
			}
		}
	}

	int operator[](int index)
	{
		if (index >= 0 && index < (int)(nrBilete / sizeof(int)) && nrBileteRezervate != nullptr)
		{
			return nrBileteRezervate[index];
		}
		return 0;
	}

	friend RezervareConcert operator+(int, RezervareConcert);

	//Modifica rezervarea prin anularea unor bilete 
	//forma 1: functie metoda
	RezervareConcert operator--()
	{
		nrBilete--;
		return *this;
	}

	//forma 2: functie globala
	friend RezervareConcert operator--(RezervareConcert);

	explicit operator string()
	{
		return dataRezervareConcert;
	}

	bool operator!()
	{
		return achitat != false;
	}

	//Verifica care dintre cele doua rezervari are mai multe bilete
	RezervareConcert operator > (RezervareConcert& r)
	{
		if (nrBilete > r.nrBilete)
			return *this;
		return r;
	}

	//Verifica daca cele doua rezervari comparate au acelasi numar de bilete
	bool operator == (RezervareConcert& r)
	{
		if (nrBilete == r.nrBilete)
			return true;
		return false;
	}

	void serializeRezervare(ofstream& f, RezervareConcert rezervare_crt)
	{
		f.write((char*)&idRezervareConcert, sizeof(idRezervareConcert));

		f.write(dataRezervareConcert, (long long)strlen(dataRezervareConcert) + 1);

		f.write((char*)&nrBilete, sizeof(nrBilete));
		for (int i = 0; i < nrBilete; i++)
		{
			f.write((char*)&nrBileteRezervate[i], sizeof(nrBileteRezervate[i]));
		}

		int length = numeUtilizatorCumparator.length() + 1;
		f.write((char*)&length, sizeof(length));
		f.write(numeUtilizatorCumparator.c_str(), length);

	}

	void deserializeRezervare(ifstream& f2, RezervareConcert rezervare_crt)
	{
		f2.read((char*)&idRezervareConcert, sizeof(idRezervareConcert));

		string buffer = "";
		char c = 0;
		while ((c = f2.get()) != 0)
		{
			buffer += c;
		}
		delete[] dataRezervareConcert;
		dataRezervareConcert = new char[buffer.length() + 1];
		strcpy_s(dataRezervareConcert, buffer.length() + 1, buffer.c_str());

		f2.read((char*)&nrBilete, sizeof(nrBilete));
		delete[] nrBileteRezervate;
		nrBileteRezervate = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			f2.read((char*)&nrBileteRezervate[i], sizeof(nrBileteRezervate[i]));
		}

		int length = 0;
		f2.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f2.read(aux, length);
		numeUtilizatorCumparator = aux;

	}

	friend ostream& operator<<(ostream&, RezervareConcert);
	friend istream& operator>>(istream&, RezervareConcert&);
	friend class BiletConcert;
};

int RezervareConcert::nrRezervari = 0;

ostream& operator<<(ostream& out, RezervareConcert r)
{

	ifstream fluxDeserializare;
	ofstream fluxSerializare;
	BiletConcert** vectorBilete = nullptr;
	int dimensiuneVector = 0;

	fluxDeserializare.open("bilet.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
	vectorBilete = new BiletConcert * [dimensiuneVector];

	for (int i = 0; i < dimensiuneVector; i++)
	{
		vectorBilete[i] = new BiletConcert();
		vectorBilete[i]->deserializareBilet(fluxDeserializare, *vectorBilete[i]);
	}
	fluxDeserializare.close();

	out << "Detalii legate de rezervare: " << endl;
	out << "ID rezervare: " << r.idRezervareConcert << endl;
	if (r.dataRezervareConcert != nullptr)
	{
		out << "Data rezervarii: " << r.dataRezervareConcert << endl;
	}
	out << "Numarul de bilete rezervate: " << r.nrBilete << endl;
	if (r.nrBileteRezervate != nullptr)
	{
		for (int i = 0; i < r.nrBilete; i++)
		{
			out << "Id-ul biletului " << i + 1 << ": " << r.nrBileteRezervate[i] << endl;

		}
	}

	out << "Numele cumparatorului: " << r.numeUtilizatorCumparator;
	out << endl;

	return out;
}

istream& operator>>(istream& in, RezervareConcert& r)
{
	ifstream fluxDeserializare;
	ofstream fluxSerializare;
	BiletConcert** vectorBilete = nullptr;
	int dimensiuneVector = 0;

	fluxDeserializare.open("bilet.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
	vectorBilete = new BiletConcert * [dimensiuneVector];

	for (int i = 0; i < dimensiuneVector; i++)
	{
		vectorBilete[i] = new BiletConcert();
		vectorBilete[i]->deserializareBilet(fluxDeserializare, *vectorBilete[i]);
	}
	fluxDeserializare.close();


	delete[]r.dataRezervareConcert;
	string buffer;
	cout << "Data rezervarii (de forma ZZ.LL.AAAA): ";
	in >> ws;
	getline(in, buffer);

	while (!RezervareConcert::validare_date(buffer))
	{
		cout << "Introduceti o data valida (ZZ.LL.AAAA): ";
		in >> ws;
		getline(in, buffer);

	}

	r.dataRezervareConcert = new char[buffer.length() + 1];
	strcpy_s(r.dataRezervareConcert, buffer.length() + 1, buffer.c_str());

	cout << "Introduceti numarul de bilete pe care doriti sa le rezervati: ";
	in >> r.nrBilete;

	while (in.fail() || r.nrBilete <= 0)
	{

		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduceti un numar valid >0 : ";

		in >> r.nrBilete;

	}

	in.clear();
	in.ignore(numeric_limits<streamsize>::max(), '\n');

	if (dimensiuneVector < r.nrBilete)
	{
		while (dimensiuneVector < r.nrBilete)
		{
			cout << "Nu exista " << r.nrBilete << " bilet(e) disponibil(e)! Introduceti o optiune valida: ";
			in >> r.nrBilete;

			while (in.fail() || r.nrBilete <= 0)
			{

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduceti un numar valid > 0: " << endl;

				in >> r.nrBilete;

			}

			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else
	{
		cout << "Bilete disponibile: ";
		for (int i = 0; i < dimensiuneVector; i++)
		{
			cout << "ID " << vectorBilete[i]->getcodBIlet() << " ";
		}
	}
	cout << endl;

	if (r.nrBilete > 0)
	{
		cout << "Selectati biletele " << endl;
		r.nrBileteRezervate = new int[r.nrBilete];
		for (int i = 0; i < r.nrBilete; i++)
		{
			int nr_bilete_selectate = 0;
			while (true)
			{
				cout << "Biletul " << i + 1 << ": ";
				in >> r.nrBileteRezervate[i];

				while (in.fail() || r.nrBileteRezervate[i] <= 0)
				{

					in.clear();
					in.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar valid > 0: " << endl;

					in >> r.nrBileteRezervate[i];

				}

				in.clear();
				in.ignore(numeric_limits<streamsize>::max(), '\n');

				for (int j = 0; j < dimensiuneVector; j++)
				{
					if (r.nrBileteRezervate[i] == vectorBilete[j]->getcodBIlet())
					{

						nr_bilete_selectate = 1;
						r.nrBileteRezervate[i] = vectorBilete[j]->getcodBIlet();

					}
				}

				if (nr_bilete_selectate == 0)
					cout << "Optiunea este invalida!" << endl;
				else
				{
					break;
				}
			}
		}
	}

	ifstream fluxDeserializare1;
	ofstream fluxSerializare1;
	Cumparator** vectorClienti = nullptr;
	int dimensiuneVector1 = 0;

	fluxDeserializare1.open("cumparatori.bin", ios::_Nocreate | ios::binary);
	fluxDeserializare1.read((char*)&dimensiuneVector1, sizeof(dimensiuneVector1));
	vectorClienti = new Cumparator * [dimensiuneVector1];

	for (int i = 0; i < dimensiuneVector1; i++)
	{
		vectorClienti[i] = new Cumparator();
		vectorClienti[i]->deserializeClient(fluxDeserializare1, *vectorClienti[i]);
	}
	fluxDeserializare1.close();

	int exista_utilizator = 0;
	cout << "Introduceti numele de utilizator: ";
	do
	{
		in >> r.numeUtilizatorCumparator;
		for (int i = 0; i < dimensiuneVector1; i++)
		{
			if (r.numeUtilizatorCumparator == vectorClienti[i]->getNumeUtilizatorCumparator())
			{
				exista_utilizator = 1;
			}
		}

		if (exista_utilizator == 0)
		{
			cout << "Ne pare rau! Nu exista niciun client cu acest nume de utilizator!" << endl;
			cout << "Incercati din nou: ";
		}


	} while (exista_utilizator == 0);



	fluxSerializare.open("bilet.bin", ios::binary);
	fluxSerializare.write((char*)&dimensiuneVector, sizeof(dimensiuneVector));

	for (int i = 0; i < dimensiuneVector; i++)
	{
		if (vectorBilete[i] != nullptr)
		{
			vectorBilete[i]->serializareBilet(fluxSerializare, *vectorBilete[i]);
		}
	}

	fluxSerializare.close();


	return in;
}

//Modifica ziua rezervarii. Rezervarea se va putea modifica doar daca a fost facuta in prima parte a lunii (pana in ziua 15 a lunii).
//Rezervarea poate fi modificata doar cu 7 zile mai tarziu, nu mai mult
RezervareConcert operator+(int x, RezervareConcert rez)
{
	int zi = atoi(rez.dataRezervareConcert);
	if (zi <= 15 && x <= 7)
	{
		zi += x;
		string zi_noua = zi_noua + to_string(zi);
		rez.dataRezervareConcert[0] = zi_noua[0];
		rez.dataRezervareConcert[1] = zi_noua[1];
	}

	return rez;
}

RezervareConcert operator--(RezervareConcert r)
{
	r.nrBilete--;
	return r;
}

class null_exception : public exception
{
public:
	null_exception()
	{

	}

	null_exception(const char* message) : exception(message)
	{

	}
};


SalaConcert** administrareSala(SalaConcert** vectorSala)
{
	int optiune = 0;
	int nrSali = 0;
	int nrSaliNoi = 0;
	bool existaIdSala = false;
	bool sterge_sala = true;
	ofstream f1;
	ifstream f2;

	system("cls");

	do
	{

		cout << endl <<
			"==== Administrare sali: ====" << endl << endl <<
			"1. Adaugare sala" << endl <<
			"2. Modificare sala" << endl <<
			"3. Stergere sala" << endl <<
			"4. Afisare info sala" << endl <<
			"0. Inchidere" << endl;

		cout << endl << "Selecteaza optiunea: ";
		cin >> optiune;

		while (cin.fail() || optiune < 0 || optiune > 4)
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Selectati o optiune valida : ";

			cin >> optiune;

		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		f2.open("sala.bin", ios::_Nocreate | ios::binary);
		f2.read((char*)&nrSali, sizeof(nrSali));

		if (nrSali != 0)
		{
			if (optiune == 1)
			{

				cout << "Introduceti numarul de sali pe care doriti sa le adaugati: ";
				cin >> nrSaliNoi;

				while (cin.fail() || nrSaliNoi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar valid : ";

					cin >> nrSaliNoi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				vectorSala = new SalaConcert * [nrSali + nrSaliNoi];
			}
			else
			{

				vectorSala = new SalaConcert * [nrSali];

			}
			for (int indx = 0; indx < nrSali; indx++)
			{
				vectorSala[indx] = new SalaConcert();
				vectorSala[indx]->deserializareSala(f2, *vectorSala[indx]);
			}

		}
		else
		{

			if (optiune == 1)
			{

				cout << "Introduceti numarul de sali pe care doriti sa le adaugati: ";
				cin >> nrSaliNoi;

				while (cin.fail() || nrSaliNoi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Selectati o optiune valida : ";

					cin >> nrSaliNoi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				vectorSala = new SalaConcert * [nrSaliNoi];

			}
			else
			{
				cout << "Nu exista sali salvate in fisierul binar!" << endl;
			}

		}

		f2.close();

		switch (optiune)
		{
		case 1:

			if (nrSali != 0)
			{

				int index_film = 1;
				for (int indx = 0; indx < nrSali; indx++)
				{

					if (vectorSala[indx]->getIdSala() > index_film)
						index_film = vectorSala[indx]->getIdSala();

				}

				SalaConcert::setNrSala(index_film);

			}

			for (int indx = nrSali; indx < nrSali + nrSaliNoi; indx++)
			{
				vectorSala[indx] = new SalaConcert();
				cin >> (*vectorSala[indx]);
			}

			nrSali += nrSaliNoi;
			break;

		case 2:
			int idSala;

			if (nrSali != 0)
			{
				cout << "Introduceti ID-ul salii pe care doriti sa o modificati: ";
				do
				{
					cin >> idSala;

					while (cin.fail() || idSala <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Selectati un ID valid : ";

						cin >> idSala;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					existaIdSala = false;

					for (int indx = 0; indx < nrSali; indx++)
					{

						if (vectorSala[indx]->getIdSala() == idSala)
						{

							existaIdSala = true;
							cin >> (*vectorSala[indx]);
						}
					}

					if (!existaIdSala)
						cout << "Introduceti un ID valid: ";

				} while ((!existaIdSala) || (idSala < 1));

			}
			break;

		case 3:
			sterge_sala = true;
			if (nrSali != 0)
			{

				cout << "Introduceti ID-ul salii pe care doriti sa o stergeti: ";

				do
				{

					cin >> idSala;

					while (cin.fail() || idSala <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un ID valid: ";

						cin >> idSala;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					existaIdSala = false;

					for (int indx = 0; indx < nrSali; indx++)
					{

						if (vectorSala[indx]->getIdSala() == idSala)
							existaIdSala = true;
					}

					if (!existaIdSala)
						cout << "Introduceti un ID valid: ";

				} while ((!existaIdSala) || (idSala < 1));

				for (int indx = 0; indx < nrSali; indx++)
				{

					if (vectorSala[indx]->getIdSala() == idSala)
					{

						for (int zi = 1; zi < 8; zi++)
						{

							//Se pot sterge doar salile care nu au filme care ruleaza
							if (vectorSala[vectorSala[indx]->getIdSala() - 1]->ExistaSustinereConcert(zi, 10) || vectorSala[vectorSala[indx]->getIdSala() - 1]->ExistaSustinereConcert(zi, 14
								|| vectorSala[vectorSala[indx]->getIdSala() - 1]->ExistaSustinereConcert(zi, 18)))
							{

								sterge_sala = false;

							}
						}
						if (sterge_sala)
						{
							existaIdSala = true;
							delete vectorSala[indx];
							vectorSala[indx] = nullptr;
							nrSaliNoi = nrSali - 1;
						}
						else
						{

							cout << "Sala nu poate fi stearsa intrucat este un concert in acest moment!" << endl;

						}
					}

				}
			}
			break;
		case 4:
			if (nrSali != 0)
			{
				cout << "Lista Sali inregistrate" << endl;
				cout << "===========================" << endl;

				for (int indx = 0; indx < nrSali; indx++)
				{

					if (vectorSala[indx] != nullptr)
						cout << (*vectorSala[indx]);

				}
			}
			break;
		}

		if (nrSali != 0 && optiune < 4)
		{

			f1.open("sala.bin", ios::binary);

			if (optiune == 3 && sterge_sala)
			{

				f1.write((char*)&nrSaliNoi, sizeof(nrSali));

			}
			else
			{

				f1.write((char*)&nrSali, sizeof(nrSali));

			}

			for (int indx = 0; indx < nrSali; indx++)
			{

				if (vectorSala[indx] != nullptr)
					vectorSala[indx]->serializareSala(f1, *vectorSala[indx]);

			}

			f1.close();

			if (optiune == 3 && sterge_sala)
				nrSali = nrSaliNoi;

			switch (optiune)
			{

			case 1:
				cout << endl << "Datele despre sali au fost inregistrate cu succes in fisierul binar!" << endl;
				break;

			case 2:
				cout << endl << "Informatiile au fost actualizate cu succes in fisierul binar!" << endl;
				break;

			case 3:
				cout << endl << "Informatiile au fost sterse din fisierul binar!" << endl;
				break;
			}

		}

	} while (optiune != 0);

	return vectorSala;
}

Concert** administrare_concerte(Concert** lista_concerte)
{
	int optiune;
	int nr_concerte = 0;
	int nr_concerte_noi = 0;
	bool exista_idconcert = false;
	ofstream f1;
	ifstream f2;

	system("cls");

	do
	{

		cout << endl <<
			"==== Administrare concerte: ====" << endl << endl <<
			"1. Adaugare concerte" << endl <<
			"2. Modificare concert" << endl <<
			"3. Stergere concert" << endl <<
			"4. Afisare info concert" << endl <<
			"0. Inchidere" << endl;

		cout << endl << "Selecteaza optiunea: ";

		cin >> optiune;

		while (cin.fail() || optiune < 0 || optiune > 4)
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Selectati o optiune valida : ";

			cin >> optiune;

		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		f2.open("film.bin", ios::_Nocreate | ios::binary);
		f2.read((char*)&nr_concerte, sizeof(nr_concerte)); 

		if (nr_concerte != 0)
		{
			if (optiune == 1)
			{

				cout << "Introduceti numarul de concerte pe care doriti sa le adaugati: ";
				cin >> nr_concerte_noi;

				while (cin.fail() || nr_concerte_noi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar valid: ";

					cin >> nr_concerte_noi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');


				lista_concerte = new Concert * [nr_concerte + nr_concerte_noi];
			}
			else
			{

				lista_concerte = new Concert * [nr_concerte];

			}

			for (int indx = 0; indx < nr_concerte; indx++)
			{
				lista_concerte[indx] = new Concert();
				lista_concerte[indx]->deserializareFilm(f2, *lista_concerte[indx]);
			}

		}
		else
		{

			if (optiune == 1)
			{

				cout << "Introduceti numarul de concerte pe care doriti sa le adaugati: ";
				cin >> nr_concerte_noi;

				while (cin.fail() || nr_concerte_noi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar > 0: ";

					cin >> nr_concerte_noi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');



				lista_concerte = new Concert * [nr_concerte_noi];

			}
			else
			{

				cout << "Nu exista concerte salvate in fisierul binar!" << endl;

			}

		}

		f2.close();

		switch (optiune)
		{

		case 1:
			//se inregistreaza concerte noi

			if (nr_concerte != 0)
			{

				int index_film = 1;
				for (int indx = 0; indx < nr_concerte; indx++)
				{

					if (lista_concerte[indx]->getIdConcert() > index_film)
						index_film = lista_concerte[indx]->getIdConcert();

				}

				Concert::setnrConcerte(index_film);

			}

			for (int indx = nr_concerte; indx < nr_concerte + nr_concerte_noi; indx++)
			{
				lista_concerte[indx] = new Concert();
				cin >> (*lista_concerte[indx]);
			}

			nr_concerte += nr_concerte_noi;

			break;

		case 2:
			// Modificare info concert
			int IdConcert;

			if (nr_concerte != 0)
			{
				cout << "Introduceti ID-ul concertului pe care doriti sa-l modificati: ";
				do
				{
					
					cin >> IdConcert;

					while (cin.fail() || IdConcert <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un ID valid >0: ";

						cin >> IdConcert;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					exista_idconcert = false;

					for (int indx = 0; indx < nr_concerte; indx++)
					{

						if (lista_concerte[indx]->getIdConcert() == IdConcert)
						{

							ifstream fluxDeserializare;
							ofstream fluxSerializare;
							SalaConcert** vectorSali = nullptr;
							int dimensiuneVector = 0;

							fluxDeserializare.open("sala.bin", ios::_Nocreate | ios::binary);
							fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
							vectorSali = new SalaConcert * [dimensiuneVector];

							for (int i = 0; i < dimensiuneVector; i++)
							{
								vectorSali[i] = new SalaConcert();
								vectorSali[i]->deserializareSala(fluxDeserializare, *vectorSali[i]);
							}
							fluxDeserializare.close();

							//Se sterge filmul din programul salii
							vectorSali[lista_concerte[indx]->getIdSala() - 1]->stergeConcert(IdConcert);

							// Se actualizaeaza datele in fisier
							fluxSerializare.open("sala.bin", ios::binary);
							fluxSerializare.write((char*)&dimensiuneVector, sizeof(dimensiuneVector));

							for (int i = 0; i < dimensiuneVector; i++)
							{
								if (vectorSali[i] != nullptr)
								{
									vectorSali[i]->serializareSala(fluxSerializare, *vectorSali[i]);
								}
							}

							fluxSerializare.close();
						}
					}

					for (int indx = 0; indx < nr_concerte; indx++)
					{

						if (lista_concerte[indx]->getIdConcert() == IdConcert)
						{

							exista_idconcert = true;
							cin >> (*lista_concerte[indx]);
						}
					}

					if (!exista_idconcert)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idconcert) || (IdConcert < 1));

			}
			break;

		case 3:
			//Stergere concerte
			if (nr_concerte != 0)
			{
				cout << "Introduceti ID-ul concertului pe care doriti sa-l stergeti: ";

				do
				{
					cin >> IdConcert;

					while (cin.fail() || IdConcert <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un ID valid > 0: ";

						cin >> IdConcert;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');



					exista_idconcert = false;

					for (int indx = 0; indx < nr_concerte; indx++)
					{

						if (lista_concerte[indx]->getIdConcert() == IdConcert)
							exista_idconcert = true;
					}

					if (!exista_idconcert)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idconcert) || (IdConcert < 1));

				for (int indx = 0; indx < nr_concerte; indx++)
				{

					if (lista_concerte[indx]->getIdConcert() == IdConcert)
					{

						//Se incarca datele pentru sali 
						ifstream fluxDeserializare;
						ofstream fluxSerializare;
						SalaConcert** vectorSali = nullptr;
						int dimensiuneVector = 0;

						fluxDeserializare.open("sala.bin", ios::_Nocreate | ios::binary);
						fluxDeserializare.read((char*)&dimensiuneVector, sizeof(dimensiuneVector));
						vectorSali = new SalaConcert * [dimensiuneVector];

						for (int i = 0; i < dimensiuneVector; i++)
						{
							vectorSali[i] = new SalaConcert();
							vectorSali[i]->deserializareSala(fluxDeserializare, *vectorSali[i]);
						}
						fluxDeserializare.close();

				
						vectorSali[lista_concerte[indx]->getIdSala() - 1]->stergeConcert(IdConcert);

				
						fluxSerializare.open("sala.bin", ios::binary);
						fluxSerializare.write((char*)&dimensiuneVector, sizeof(dimensiuneVector));

						for (int i = 0; i < dimensiuneVector; i++)
						{
							if (vectorSali[i] != nullptr)
							{
								vectorSali[i]->serializareSala(fluxSerializare, *vectorSali[i]);
							}
						}

						fluxSerializare.close();

				
						exista_idconcert = true;
						delete lista_concerte[indx];
						lista_concerte[indx] = nullptr;

						nr_concerte_noi = nr_concerte - 1;

					}

				}
			}
			break;
		case 4:
					
			if (nr_concerte != 0)
			{
				cout << "Lista concerte inregistrate" << endl;
				cout << "===========================" << endl;

				for (int indx = 0; indx < nr_concerte; indx++)
				{

					if (lista_concerte[indx] != nullptr)
						cout << (*lista_concerte[indx]);

				}
			}
			break;
		}

		// La finalul oricarei operatiuni se inregistreaza concerte in fisierul binar daca exista filem de inregistrat
		if (nr_concerte != 0 && optiune < 4)
		{

			f1.open("concert.bin", ios::binary);

			
			if (optiune == 3)
			{

				f1.write((char*)&nr_concerte_noi, sizeof(nr_concerte_noi));

			}
			else
			{

				f1.write((char*)&nr_concerte, sizeof(nr_concerte));

			}

			for (int indx = 0; indx < nr_concerte; indx++)
			{

				if (lista_concerte[indx] != nullptr)
					lista_concerte[indx]->serializareConcert(f1, *lista_concerte[indx]);

			}

			f1.close();

			if (optiune == 3)
				nr_concerte = nr_concerte_noi;

			switch (optiune)
			{

			case 1:
				cout << endl << "Datele despre concert au fost inregistrate cu succes!" << endl;
				break;

			case 2:
				cout << endl << "Informatiile au fost actualizate cu succes!" << endl;
				break;

			case 3:
				cout << endl << "Informatiile au fost sterse!" << endl;
				break;
			}

		}

	} while (optiune != 0);

	return lista_concerte;
}

BiletConcert** administrare_bilete(BiletConcert** lista_bilete)
{
	int optiune;
	int nr_bilete = 0;
	int nr_bilete_noi = 0;
	bool exista_idbilet = false;
	ofstream f1;
	ifstream f2;

	system("cls");

	do
	{

		cout << endl <<
			"==== Administrare bilete: ====" << endl << endl <<
			"1. Adaugare bilete" << endl <<
			"2. Modificare bilet" << endl <<
			"3. Stergere bilet" << endl <<
			"4. Afisare info bilete" << endl <<
			"5. Printare bilete" << endl <<
			"0. Inchidere" << endl;

		cout << endl << "Selecteaza optiunea: ";

		cin >> optiune;

		while (cin.fail() || optiune < 0 || optiune > 6)
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Selectati o optiune valida : ";

			cin >> optiune;

		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//Se citesc nr. de filme salvate din fisier
		f2.open("bilet.bin", ios::_Nocreate | ios::binary);
		f2.read((char*)&nr_bilete, sizeof(nr_bilete)); //nr bilete inregistrate in fisier

		if (nr_bilete != 0)
		{
			if (optiune == 1)
			{

				cout << "Introduceti numarul de bilete pe care doriti sa le adaugati: ";
				cin >> nr_bilete_noi;

				while (cin.fail() || nr_bilete_noi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar > 0: ";

					cin >> nr_bilete_noi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				lista_bilete = new BiletConcert * [nr_bilete + nr_bilete_noi];
			}
			else
			{

				lista_bilete = new BiletConcert * [nr_bilete];

			}

			for (int indx = 0; indx < nr_bilete; indx++)
			{
				lista_bilete[indx] = new BiletConcert();
				lista_bilete[indx]->deserializareBilet(f2, *lista_bilete[indx]);
			}

		}
		else
		{

			if (optiune == 1)
			{

				cout << "Introduceti numarul de bilete pe care doriti sa le adaugati: ";
				cin >> nr_bilete_noi;

				while (cin.fail() || nr_bilete_noi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar > 0: ";

					cin >> nr_bilete_noi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				lista_bilete = new BiletConcert * [nr_bilete_noi];

			}
			else
			{

				cout << "Nu exista bilete salvate!" << endl;

			}

		}

		f2.close();

		switch (optiune)
		{

		case 1:
			//Inregistrare BIlete noi

			if (nr_bilete != 0)
			{

				int index_bilet = 1;
				for (int indx = 0; indx < nr_bilete; indx++)
				{

					if (lista_bilete[indx]->getcodBIlet() > index_bilet)
						index_bilet = lista_bilete[indx]->getcodBIlet();

				}

				BiletConcert::setnrBileteEmise(index_bilet);

			}

			for (int indx = nr_bilete; indx < nr_bilete + nr_bilete_noi; indx++)
			{
				lista_bilete[indx] = new BiletConcert();
				cin >> (*lista_bilete[indx]);
			}

			// Se seteaza nr de bilete la nr de bilete din fisierul binar + nr bilete noi inregistrate 
			nr_bilete += nr_bilete_noi;

			break;

		case 2:
		
			int IDBilet;

			if (nr_bilete != 0)
			{
				cout << "Introduceti ID-ul concertului pe care doriti sa-l modificati: ";
				do
				{
					
					cin >> IDBilet;

					while (cin.fail() || IDBilet <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un ID > 0: ";

						cin >> IDBilet;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					exista_idbilet = false;

					for (int indx = 0; indx < nr_bilete; indx++)
					{

						if (lista_bilete[indx]->getcodBIlet() == IDBilet)
						{

							exista_idbilet = true;
							cin >> (*lista_bilete[indx]);
						}
					}

					if (!exista_idbilet)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idbilet) || (IDBilet < 1));

			}
			break;

		case 3:
			
			if (nr_bilete != 0)
			{
				cout << "Introduceti ID-ul biletului pe care doriti sa-l stergeti: ";

				do
				{
					//Se verifica daca ID-ul biltului este valid (este ID-ul unui bilet existent)

					cin >> IDBilet;

					while (cin.fail() || IDBilet <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un ID > 0: ";

						cin >> IDBilet;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					exista_idbilet = false;

					for (int indx = 0; indx < nr_bilete; indx++)
					{

						if (lista_bilete[indx]->getcodBIlet() == IDBilet)
							exista_idbilet = true;
					}

					if (!exista_idbilet)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idbilet) || (IDBilet < 1));

				for (int indx = 0; indx < nr_bilete; indx++)
				{

					if (lista_bilete[indx]->getcodBIlet() == IDBilet)
					{

						exista_idbilet = true;
						delete lista_bilete[indx];
						lista_bilete[indx] = nullptr;

						nr_bilete_noi = nr_bilete - 1;

					}

				}
			}
			break;
		case 4:
					
			if (nr_bilete != 0)
			{
				cout << "Lista Bilete inregistrate" << endl;
				cout << "===========================" << endl;

				for (int indx = 0; indx < nr_bilete; indx++)
				{

					if (lista_bilete[indx] != nullptr)
						cout << (*lista_bilete[indx]);

				}
			}
			break;

		case 5:

			cout << "Printare bilete:" << endl;
			cout << "=============================" << endl;
			f2.open("bilete.txt");

			f2 >> nr_bilete;

			for (int indx = 0; indx < nr_bilete; indx++)
			{

				if (lista_bilete[indx] != nullptr)
					f2 >> (*lista_bilete[indx]);

			}

			f2.close();

			for (int indx = 0; indx < nr_bilete; indx++)
			{

				if (lista_bilete[indx] != nullptr)
					cout << (*lista_bilete[indx]);

			}

			break;
		}

		
		if (nr_bilete != 0 && optiune < 4)
		{

			f1.open("bilet.bin", ios::binary);

			if (optiune == 3)
			{

				f1.write((char*)&nr_bilete_noi, sizeof(nr_bilete_noi));

			}
			else
			{

				f1.write((char*)&nr_bilete, sizeof(nr_bilete));

			}

			for (int indx = 0; indx < nr_bilete; indx++)
			{

				if (lista_bilete[indx] != nullptr)
					lista_bilete[indx]->serializareBilet(f1, *lista_bilete[indx]);

			}

			f1.close();

			if (optiune == 3)
				nr_bilete = nr_bilete_noi;

			switch (optiune)
			{

			case 1:
				cout << endl << "Datele despre bilete au fost inregistrate cu succes!" << endl;
				break;

			case 2:
				cout << endl << "Informatiile au fost actualizate cu succes!" << endl;
				break;

			case 3:
				cout << endl << "Informatiile au fost sterse!" << endl;
				break;
			}

		}

	} while (optiune != 0);

	return lista_bilete;
}


RezervareConcert** administrare_rezervari(RezervareConcert** lista_rezervari)
{
	int optiune;
	int nr_rezervari = 0;
	int nr_rezervari_noi = 0;
	bool exista_idrezervare = false;
	ofstream f1;
	ifstream f2;

	system("cls");

	do
	{
		cout << endl <<
			"==== Administrare rezervari: ====" << endl << endl <<
			"1. Adaugare rezervari" << endl <<
			"2. Modificare rezervari" << endl <<
			"3. Stergere rezervari" << endl <<
			"4. Afisare info rezervari" << endl <<
			"0. Inchidere" << endl;

		cout << endl << "Selecteaza optiunea: ";

		cin >> optiune;

		while (cin.fail() || optiune < 0 || optiune > 4)
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Selectati o optiune valida : ";

			cin >> optiune;

		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		f2.open("rezervare.bin", ios::_Nocreate | ios::binary);
		f2.read((char*)&nr_rezervari, sizeof(nr_rezervari)); 
		if (nr_rezervari != 0)
		{
			if (optiune == 1)
			{

				cout << "Introduceti numarul de rezervari pe care doriti sa le adaugati: ";
				cin >> nr_rezervari_noi;

				while (cin.fail() || nr_rezervari_noi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar > 0: ";

					cin >> nr_rezervari_noi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				lista_rezervari = new RezervareConcert * [nr_rezervari + nr_rezervari_noi];
			}
			else
			{

				lista_rezervari = new RezervareConcert * [nr_rezervari];

			}
			
			for (int i = 0; i < nr_rezervari; i++)
			{
				lista_rezervari[i] = new RezervareConcert();
				lista_rezervari[i]->deserializeRezervare(f2, *lista_rezervari[i]);
			}
		}
		else
		{
			if (optiune == 1)
			{

				cout << "Introduceti numarul de rezervari pe care doriti sa le adaugati: ";
				cin >> nr_rezervari_noi;

				while (cin.fail() || nr_rezervari_noi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar > 0: ";

					cin >> nr_rezervari_noi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				lista_rezervari = new RezervareConcert * [nr_rezervari_noi];

			}
			else
			{

				cout << "Nu exista rezervari salvate!" << endl;

			}
		}

		f2.close();

		switch (optiune)
		{
		case 1:
			
			if (nr_rezervari != 0)
			{

				int index_rezervare = 1;
				for (int i = 0; i < nr_rezervari; i++)
				{

					if (lista_rezervari[i]->getIdRezervareConcert() > index_rezervare)
						index_rezervare = lista_rezervari[i]->getIdRezervareConcert();

				}

				RezervareConcert::setNrRezervari(index_rezervare);

			}

			for (int i = nr_rezervari; i < nr_rezervari + nr_rezervari_noi; i++)
			{
				lista_rezervari[i] = new RezervareConcert();
				cin >> (*lista_rezervari[i]);
			}

			nr_rezervari += nr_rezervari_noi;

			break;

		case 2:
			// Modificare informatii rezervare
			int IDRezervare;

			if (nr_rezervari != 0)
			{
				cout << "Introduceti ID-ul rezervarii pe care doriti sa o modificati: ";
				do
				{
					//Se verifica daca ID-ul rezervarii este valid (este ID-ul unei rezervari existente)

					cin >> IDRezervare;

					while (cin.fail() || IDRezervare <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un numar > 0: ";

						cin >> IDRezervare;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					exista_idrezervare = false;

					for (int i = 0; i < nr_rezervari; i++)
					{

						if (lista_rezervari[i]->getIdRezervareConcert() == IDRezervare)
						{

							exista_idrezervare = true;
							cin >> (*lista_rezervari[i]);
						}
					}

					if (!exista_idrezervare)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idrezervare) || (IDRezervare < 1));

			}
			break;

		case 3:
			//Stergere rezervari
			if (nr_rezervari != 0)
			{
				cout << "Introduceti ID-ul rezervarii pe care doriti sa o stergeti: ";

				do
				{
					//Se verifica daca ID-ul rezervarii este valid 

					cin >> IDRezervare;

					while (cin.fail() || IDRezervare <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un numar > 0: ";

						cin >> IDRezervare;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					exista_idrezervare = false;

					for (int i = 0; i < nr_rezervari; i++)
					{

						if (lista_rezervari[i]->getIdRezervareConcert() == IDRezervare)
							exista_idrezervare = true;
					}

					if (!exista_idrezervare)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idrezervare) || (IDRezervare < 1));

				for (int i = 0; i < nr_rezervari; i++)
				{

					if (lista_rezervari[i]->getIdRezervareConcert() == IDRezervare)
					{

						exista_idrezervare = true;
						delete lista_rezervari[i];
						lista_rezervari[i] = nullptr;

						//Setam nr rezervari cu unu mai putin
						nr_rezervari_noi = nr_rezervari - 1;

					}

				}
			}
			break;

		case 4:
			//Afisare lista rezervari			
			if (nr_rezervari != 0)
			{
				cout << "Lista rezervari inregistrate" << endl;
				cout << "===========================" << endl;

				for (int i = 0; i < nr_rezervari; i++)
				{

					if (lista_rezervari[i] != nullptr)
						cout << (*lista_rezervari[i]);

				}
			}
			break;
		}
		if (nr_rezervari != 0 && optiune < 4)
		{

			f1.open("rezervare.bin", ios::binary);

			//Se scrie nr. de rezervari in fisier
			if (optiune == 3)
			{

				f1.write((char*)&nr_rezervari_noi, sizeof(nr_rezervari_noi));

			}
			else
			{

				f1.write((char*)&nr_rezervari, sizeof(nr_rezervari));

			}

			for (int i = 0; i < nr_rezervari; i++)
			{

				if (lista_rezervari[i] != nullptr)
					lista_rezervari[i]->serializeRezervare(f1, *lista_rezervari[i]);

			}

			f1.close();

			if (optiune == 3)
				nr_rezervari = nr_rezervari_noi;

			switch (optiune)
			{

			case 1:
				cout << endl << "Datele despre rezervari au fost inregistrate cu succes!" << endl;
				break;

			case 2:
				cout << endl << "Informatiile au fost actualizate cu succes!" << endl;
				break;

			case 3:
				cout << endl << "Informatiile au fost sterse!" << endl;
				break;
			}

		}

	} while (optiune != 0);

	return lista_rezervari;
}



Cumparator** administrare_cumparatori(Cumparator** lista_cumparatori)
{
	int optiune;
	int nr_cumparatori = 0;
	int nr_cumparatori_noi = 0;
	bool exista_idcumparator = false;
	ofstream f1;
	ifstream f2;

	system("cls");

	do
	{
		cout << endl <<
			"==== Administrare cumparatori: ====" << endl << endl <<
			"1. Adaugare cumparatori" << endl <<
			"2. Modificare cumparatori" << endl <<
			"3. Stergere cumparatori" << endl <<
			"4. Afisare info cumparatori" << endl <<
			"0. Inchidere" << endl;

		cout << endl << "Selecteaza optiunea: ";

		cin >> optiune;

		while (cin.fail() || optiune < 0 || optiune > 4)
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduceti o optiune valida: ";

			cin >> optiune;

		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		f2.open("cumparatori.bin", ios::_Nocreate | ios::binary);
		f2.read((char*)&nr_cumparatori, sizeof(nr_cumparatori)); 

		if (nr_cumparatori != 0)
		{
			if (optiune == 1)
			{

				cout << "Introduceti numarul de cumparatori pe care doriti sa ii adaugati: ";
				cin >> nr_cumparatori_noi;

				lista_cumparatori = new Cumparator * [nr_cumparatori + nr_cumparatori_noi];
			}
			else
			{

				lista_cumparatori = new Cumparator * [nr_cumparatori];

			}
			for (int i = 0; i < nr_cumparatori; i++)
			{
				lista_cumparatori[i] = new Cumparator();
				lista_cumparatori[i]->deserializeClient(f2, *lista_cumparatori[i]);
			}
		}
		else
		{
			if (optiune == 1)
			{

				cout << "Introduceti numarul de cumparatori pe care doriti sa ii adaugati: ";
				cin >> nr_cumparatori_noi;

				while (cin.fail() || nr_cumparatori_noi <= 0)
				{

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduceti un numar > 0: ";

					cin >> nr_cumparatori_noi;

				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				lista_cumparatori = new Cumparator * [nr_cumparatori_noi];

			}
			else
			{

				cout << "Nu exista cumparatori salvati in fisierul binar!" << endl;

			}
		}

		f2.close();

		switch (optiune)
		{
		case 1:
			
			if (nr_cumparatori != 0)
			{

				int index_cumparator = 1;
				for (int i = 0; i < nr_cumparatori; i++)
				{

					if (lista_cumparatori[i]->getIdCumparator() > index_cumparator)
						index_cumparator = lista_cumparatori[i]->getIdCumparator();

				}

				Cumparator::setNrCumparatori(index_cumparator);

			}

			for (int i = nr_cumparatori; i < nr_cumparatori + nr_cumparatori_noi; i++)
			{
				lista_cumparatori[i] = new Cumparator();
				cin >> (*lista_cumparatori[i]);
			}

			nr_cumparatori += nr_cumparatori_noi;

			break;

		case 2:
			// Modificare informatii cumparator
			int IdCumparator;

			if (nr_cumparatori != 0)
			{
				cout << "Introduceti ID-ul cumparatorului pe ale carui informatii doriti sa le modificati: ";
				do
				{
					

					cin >> IdCumparator;

					while (cin.fail() || IdCumparator <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un numar > 0: ";

						cin >> IdCumparator;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					exista_idcumparator = false;

					for (int i = 0; i < nr_cumparatori; i++)
					{

						if (lista_cumparatori[i]->getIdCumparator() == IdCumparator)
						{

							exista_idcumparator = true;
							cin >> (*lista_cumparatori[i]);
						}
					}

					if (!exista_idcumparator)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idcumparator) || (IdCumparator < 1));

			}
			break;

		case 3:
	
			if (nr_cumparatori != 0)
			{
				cout << "Introduceti ID-ul cumparatorului pe care doriti sa il stergeti: ";

				do
				{


					cin >> IdCumparator;

					while (cin.fail() || IdCumparator <= 0)
					{

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Introduceti un numar > 0: ";

						cin >> IdCumparator;

					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					exista_idcumparator = false;

					for (int i = 0; i < nr_cumparatori; i++)
					{

						if (lista_cumparatori[i]->getIdCumparator() == IdCumparator)
							exista_idcumparator = true;
					}

					if (!exista_idcumparator)
						cout << "Introduceti un ID valid: ";

				} while ((!exista_idcumparator) || (IdCumparator < 1));

				for (int i = 0; i < nr_cumparatori; i++)
				{

					if (lista_cumparatori[i]->getIdCumparator() == IdCumparator)
					{

						exista_idcumparator = true;
						delete lista_cumparatori[i];
						lista_cumparatori[i] = nullptr;

						nr_cumparatori_noi = nr_cumparatori - 1;

					}

				}
			}
			break;

		case 4:
				
			if (nr_cumparatori != 0)
			{
				cout << "Lista cumparatori inregistrati" << endl;
				cout << "===========================" << endl;

				for (int i = 0; i < nr_cumparatori; i++)
				{

					if (lista_cumparatori[i] != nullptr)
						cout << (*lista_cumparatori[i]);

				}
			}
			break;
		}
		// La finalul oricarei operatiuni se inregistreaza cumparatorii in fisierul binar daca exista clienti de inregistrat
		if (nr_cumparatori != 0 && optiune < 4)
		{

			f1.open("cumparatori.bin", ios::binary);

			if (optiune == 3)
			{

				f1.write((char*)&nr_cumparatori_noi, sizeof(nr_cumparatori_noi));

			}
			else
			{

				f1.write((char*)&nr_cumparatori, sizeof(nr_cumparatori));

			}

			for (int i = 0; i < nr_cumparatori; i++)
			{

				if (lista_cumparatori[i] != nullptr)
					lista_cumparatori[i]->serializeCumparator(f1, *lista_cumparatori[i]);

			}

			f1.close();

			if (optiune == 3)
				nr_cumparatori = nr_cumparatori_noi;

			switch (optiune)
			{

			case 1:
				cout << endl << "Datele despre cumparator au fost inregistrate cu succes!" << endl;
				break;

			case 2:
				cout << endl << "Informatiile au fost actualizate!" << endl;
				break;

			case 3:
				cout << endl << "Informatiile au fost sterse!" << endl;
				break;
			}

		}

	} while (optiune != 0);

	return lista_cumparatori;
}


int main()
{

	SalaConcert** lista_sali = nullptr;
	Concert** lista_concerte = nullptr;
	Cumparator** lista_cumparatori = nullptr;
	BiletConcert** lista_bilete = nullptr;
	RezervareConcert** lista_rezervari = nullptr;
	int nr_sali{ 0 }, nr_concerte{ 0 }, nr_bilete{ 0 }, nr_cumparatori{ 0 }, nr_rezervari{ 0 };

	string username = "administrator";
	string password = "parola";
	string revenireMeniu = "1";
	int optiuneFilm = 0;
	int rand = 0;
	int loc = 0;
	int optiune;

	do
	{


		//Se citesc nr. de sali - daca nu sunt sali nu se pot inregistra filme
		ifstream fluxDeserializare;
		fluxDeserializare.open("sala.bin", ios::_Nocreate | ios::binary);
		fluxDeserializare.read((char*)&nr_sali, sizeof(nr_sali));
		fluxDeserializare.close();

		//Se citesc nr. de filme - daca nu sunt fil;me nu se pot inregistra bilete
		fluxDeserializare.open("concert.bin", ios::_Nocreate | ios::binary);
		fluxDeserializare.read((char*)&nr_concerte, sizeof(nr_concerte));
		fluxDeserializare.close();

		//Se citesc nr. de bilete - daca nu sunt bilete nu se pot inregistra rezervarile si clientii
		fluxDeserializare.open("bilet.bin", ios::_Nocreate | ios::binary);
		fluxDeserializare.read((char*)&nr_bilete, sizeof(nr_bilete));
		fluxDeserializare.close();

		//Se citesc nr. de clienti - daca nu sunt clienti nu se pot inregistra rezervari
		fluxDeserializare.open("cumparatori.bin", ios::_Nocreate | ios::binary);
		fluxDeserializare.read((char*)&nr_cumparatori, sizeof(nr_cumparatori));
		fluxDeserializare.close();

		cout << endl <<
			"==== Meniu: ====" << endl << endl <<
			"1. Administrare sali" << endl <<
			"2. Administrare concerte" << endl <<
			"3. Administrare bilete" << endl <<
			"4. Administrare cumparatori" << endl <<
			"5. Administrare rezervare" << endl <<
			"6. Cont cumparator" << endl <<
			"0. Inchidere" << endl;

		cout << endl << "Selecteaza optiunea: ";
		cin >> optiune;

		while (cin.fail() || optiune < 0 || optiune >6)
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Selectati o optiune valida : ";

			cin >> optiune;

		}


		switch (optiune)
		{
		case 1:
			administrareSala(lista_sali);
			break;
		case 2:
			if (nr_sali < 1)
			{
				cout << "Trebuie adaugata cel putin o sala pentru a putea inregistra un concert";
			}
			else
			{
				administrare_concerte(lista_concerte);
			}
			break;
		case 3:
			if (nr_concerte < 1)
			{
				cout << "Trebuie adaugat cel putin un concert pentru a putea inregistra bilete";
			}
			else
			{
				administrare_bilete(lista_bilete);
			}
			break;
		case 4:
			if (nr_bilete < 1)
			{
				cout << "Trebuie adaugat cel putin un bilet pentru a putea inregistra un cumparator";
			}
			else
			{
				administrare_cumparatori(lista_cumparatori);
			}
			break;
		case 5:
			if (nr_cumparatori < 1)
			{
				cout << "Trebuie adaugat cel putin un cumparator pentru a putea inregistra o rezervare";
			}
			else
			{
				administrare_rezervari(lista_rezervari);
			}
			break;
		case 6:
			break;
		}
	} while (optiune != 0);
};
