#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


class Casa {

private:
	
	const int numar;//atribut const.numarul casei
	float suprafata;
	float	pret;
	bool mobilata;
	int nr_camere;
	int* camere;
	static float tva; //atribut static
public:

// Constructor fara parametri
	Casa():numar(0){
		this->suprafata = 0;
		this->pret = 0;
		this->mobilata = 0; //0=fals
		this->nr_camere = 0;
		this->camere = NULL;
   }
//Constructor cu parametri 
	Casa(const int numar,float suprafata, float pret, bool mobilata, int nr_camere, int* camere):numar(numar) {
    	this->suprafata = suprafata;
		this->pret = pret;
		this->mobilata = mobilata;
		if (nr_camere > 0 && camere != NULL) {
			this->nr_camere = nr_camere;
			this->camere = new int[this->nr_camere];
			for (int i = 0; i < this->nr_camere; i++) {
				this->camere[i] = camere[i];
			}

		}
		else {
			this->nr_camere = 0;
			this->camere = NULL;
		}
		
  }
//const. de copiere
	Casa(const Casa& c) :numar(c.numar) {
		this->suprafata = c.suprafata;
		this->pret = c.pret;
		this->mobilata = c.mobilata;
		if (c.nr_camere > 0 && c.camere != NULL) {
			this->nr_camere = c.nr_camere;
			this->camere = new int[this->nr_camere];
			for (int i = 0; i < this->nr_camere; i++) {
				this->camere[i] = c.camere[i];
			}

		}
		else {
			this->nr_camere = 0;
			this->camere = NULL;
		}
	}


	//get
	float getSuprafata() {
		return this->suprafata;
	}
	float getPret() {
		return this->pret;
	}
	bool getMobilata() {
		return this->mobilata;
	}
	int getCamere(int i) {
		if (i <= this->nr_camere) {
			return this->camere[i];
		}
		else {
			cout << "Camera nu exista";
		}
	}
	int getNr_camere() {
		return this->nr_camere;
	}
	int getNumar() {
		return this->numar;
	}
	//set
	void setSuprafata(float suprafata) {
		if (suprafata >= 0) {
			this->suprafata = suprafata;
		}
		else {
			cout << "Nu se poate";
		}
	}
	void setPret(float pret) {
		if (pret >= 0) {
			this->pret = pret;
		}
		else {
			throw new exception("pret incorect");
		}
	}
	void setMobilata(bool mobilata) {
		this->mobilata = mobilata;
	}
	void setCamere(int nr_camere, int* camere) {
		if (nr_camere > 0 && camere != NULL) {
			this->nr_camere = nr_camere;
			delete[] this->camere;
			this->camere = new int[nr_camere];
			for (int i = 0; i <= nr_camere; i++) {
				this->camere[i] = camere[i];
			}
		}
		else {
			this->nr_camere = 0;
			this->camere = NULL;
		}
	}
	//destructor
	~Casa() {
		//cout << "destructor" << endl;
		delete[] this->camere;
	}

};
float Casa::tva = 0.05;


class Apartament {
private:
	const string strada;
	float suprafata_ap;
	float	pret_ap;
	bool decomandat;//0=nedecomandat
	char* nume_proprietar;
	static int nr_apartamente;
public:
	//const fara param
	Apartament():strada("nu exista") {
		this->suprafata_ap = 0;
		this->pret_ap = 0;
		this->decomandat = 0;
		this->nume_proprietar = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume_proprietar, "Necunoscut");
		nr_apartamente++;
	}
	//constr. cu param.
	Apartament(const string strada, float suprafata_ap, float pret_ap, bool decomandat, const char* nume_proprietar):strada(strada) {
		this->suprafata_ap = suprafata_ap;
		this->pret_ap = pret_ap;
		this->decomandat = decomandat;
		this->nume_proprietar = new char[strlen(nume_proprietar) + 1];
		strcpy(this->nume_proprietar, nume_proprietar);
		nr_apartamente++;
	}
	
	//constr. de copiere
	Apartament(const Apartament& a) :strada(a.strada) {
		this->suprafata_ap = a.suprafata_ap;
		this->pret_ap = a.pret_ap;
		this->decomandat = a.decomandat;
		this->nume_proprietar = new char[strlen(a.nume_proprietar) + 1];
		strcpy(this->nume_proprietar, a.nume_proprietar);
		nr_apartamente++;
	}
	//get
	string getStrada() {
		return this->strada;
	}
	float getSuprafata_ap() {
		return this->suprafata_ap;
	}
	float getPret_ap() {
		return this->pret_ap;
	}
	bool getDecomandat() {
		return this->decomandat;
	}
	char* getNume_proprietar() {
		return this->nume_proprietar;
	}
	//set
	void setSuprafata_ap(float suprafata_ap) {
		this->suprafata_ap=suprafata_ap;
	}
	void setPret_ap(float pret_ap) {
		this->pret_ap = pret_ap;
	}
	void setDecomandat(bool decomandat) {
		this->decomandat = decomandat;
	}
	void setNume_proprietar(const char* nume_proprietar) {
		delete[] this->nume_proprietar;
		this->nume_proprietar = new char[strlen(nume_proprietar) + 1];
		strcpy(this->nume_proprietar, nume_proprietar);
	}

	//op. =
	Apartament& operator =(const Apartament& a) {
		
		this->suprafata_ap = a.suprafata_ap;
		this->pret_ap = a.pret_ap;
		this->decomandat = a.decomandat;
		delete[] this->nume_proprietar;
		this->nume_proprietar = new char[strlen(a.nume_proprietar) + 1];
		strcpy(this->nume_proprietar, a.nume_proprietar);
		nr_apartamente++;

		return *this;
	}

	~Apartament() {
		delete this->nume_proprietar;
	}
	//supraincarcarea operatorilor
	//op <<; op. binar, op din stanga nu este de tipul clasei => fct. friend
	friend ostream& operator << (ostream& out, const Apartament& a);

};
int Apartament::nr_apartamente = 0; 

//op<<
ostream& operator << (ostream& out, const Apartament& a) {
	cout << "strada:" << a.strada << endl << "suprafata:" << a.suprafata_ap << endl << "pret:" << a.pret_ap << endl << "decomandat:" << a.decomandat << endl << "nume_proprietar:" << a.nume_proprietar << endl;
	return out;
}

class Vila {
private:
	string nume_proprietar_vila;
	float pret_vila;
	int nr_camere_vila;
	int* camere_vila;
public:
	//constr. fara param.
	Vila() {
		this->nume_proprietar_vila = "Nu exista";
		this->pret_vila = 0;
		this->nr_camere_vila = 0;
		this->camere_vila = NULL;
	}
	//constr. cu param.
	Vila(string nume_proprietar_vila, float pret_vila, int nr_camere_vila, int* camere_vila) {
		this->nume_proprietar_vila = nume_proprietar_vila;
		this->pret_vila = pret_vila;
		if (nr_camere_vila > 0 && camere_vila != NULL) {
			this->nr_camere_vila = nr_camere_vila;
			this->camere_vila = new int[this->nr_camere_vila];
			for (int i = 0; i < this->nr_camere_vila; i++) {
				this->camere_vila[i] = camere_vila[i];
			}

		}
		else {
			this->nr_camere_vila = 0;
			this->camere_vila = NULL;
		}
	}
	//constr. de copiere
		Vila(const Vila& v) {
			this->nume_proprietar_vila = v.nume_proprietar_vila;
			this->pret_vila = v.pret_vila;
			if (v.nr_camere_vila > 0 && v.camere_vila != NULL) {
				this->nr_camere_vila = v.nr_camere_vila;
				this->camere_vila = new int[this->nr_camere_vila];
				for (int i = 0; i < this->nr_camere_vila; i++) {
					this->camere_vila[i] = v.camere_vila[i];
				}

			}
			else {
				this->nr_camere_vila = 0;
				this->camere_vila = NULL;
			}
	}
		//get
		string getNume_proprietar_vila() {
			return this->nume_proprietar_vila;
		}
		float getPret_vila() {
			return this->pret_vila;
		}
		int getNr_camere_vila() {
			return this->nr_camere_vila;
		}
		int getCamere_vila(int i) {
			if (i <= this->nr_camere_vila) {
				return this->camere_vila[i];
			}
			else {
				cout << "Camera nu exista";
			}
		}
		//set
		void setNume_proprietar_vila(string nume_proprietar_vila) {
			this->nume_proprietar_vila = nume_proprietar_vila;
		}
		void setPret_vila(float pret_vila) {
			this->pret_vila = pret_vila;
		}
		void setCamere(int nr_camere_vila, int* camere_vila) {
			if (nr_camere_vila > 0 && camere_vila != NULL) {
				this->nr_camere_vila = nr_camere_vila;
				delete[] this->camere_vila; //pt a evita memory leak 
				this->camere_vila = new int[this->nr_camere_vila];
				for (int i = 0; i < this->nr_camere_vila; i++) {
					this->camere_vila[i] = camere_vila[i];
				}
			}

		}


		~Vila() {
			delete this->camere_vila;
		}
};

int main()
{ //ob. construit cu ajutorul const. fara param.
	Casa c1;
	cout << c1.getPret() << endl;
	try {
		c1.setPret(32000);
	}
	catch (exception* ex) {
		cout << ex->what();
	}
	cout << c1.getPret() << endl;
	c1.setSuprafata(24);
	cout << endl << endl;
	for (int i = 0; i < c1.getNr_camere(); i++) {
		cout << c1.getCamere(i) << endl;
	}
	int camere1[] = { 1,2,3,4 };
	c1.setCamere(4, camere1);
	for (int i = 0; i < c1.getNr_camere(); i++) {
		cout << c1.getCamere(i) << endl;
	}
	//ob. construit cu ajutorul const. fara param.
	Casa c2;
	cout << endl;
	cout << c2.getPret();
	for (int i = 0; i < c2.getNr_camere(); i++) {
		cout << c2.getCamere(i);
	}
	cout << endl;
	c2.setPret(400000);

	//ob. construit cu ajutorul const. cu param.
	int camere3[] = { 1,2,3,4 };
	Casa c3(23,20000,32000.7,1,4,camere3);
	cout << c3.getSuprafata() << endl;
	//constr. de copiere 
	Casa c4(c3);
	Apartament a1("Ghioceilor",240000, 667219,0,"Bindileu");
	Apartament a2(a1);//constr. de copiere
	Apartament a3;
	a3 = a2;//op. =
	cout << a3;// operandul din stanga este de tip ostream
	Vila v1;
	Vila v2(v1);
	return 0;
}