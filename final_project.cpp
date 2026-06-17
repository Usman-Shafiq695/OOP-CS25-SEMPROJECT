#include<iostream>
#include<fstream>
#include<windows.h>
#include"mystr.h"
using namespace std;
class character {
	mystr name;
	int health;
	int attacking_power;
	int static total_characters;
	int total_health;
public:
	character(mystr _name, int _health, int _attacking_power) {
		name = _name;
		health = _health;
		total_health = _health;
		attacking_power = _attacking_power;
		total_characters++;
	}
	mystr chr_name() {
		return name;
	}
	int chr_health() {
		return health;
	}
	int chr_attacking_power() {
		return attacking_power;
	}
	void get_health(int a) {
		health = health - a;
	}
	virtual int attack() = 0;
	virtual void defend(int h) = 0;
	virtual int power() = 0;
	virtual void healthgain(int h) {
		int a = health + h;
		if (a > total_health) {
			health = total_health;
		}
		else {
			health = a;
		}
	}
	virtual void display() {
		cout << "NAME :" << name << endl;
		cout << "HEALTH: " << health << endl;
		cout << "ATTACKING POWER: " << attacking_power << endl;
	}
};
int character::total_characters = 0;
                             // HERO CLASSES
class GodOfThunder: public character {
public:
	GodOfThunder() : character("THOR ",100,27){}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
	void display() {
		character::display();
	}
};
class MysticArts : public character {
public:
	MysticArts() : character("DOCTOR STRANGE ", 100, 30) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
	void display() {
		character::display();
	}
};
class ArmoredAvenger : public character {
public:
	ArmoredAvenger() : character("IRON-MAN ", 100, 20) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
	void display() {
		character::display();
	}
};
class Archer : public character {
public:
	Archer() : character("HAWKAYE ", 100, 17) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
	void display() {
		character::display();
	}
};
class SuperSoldier : public character {
public:
	SuperSoldier() : character("CAPTAIN-AMERICA ", 100, 22) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
	void display() {
		character::display();
	}
};
class GammaRadiation : public character {
public:
	GammaRadiation() : character("HULK ", 100, 24) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
	void display() {
		character::display();
	}
};
                                       //   ENEMY CLASSES
class ChitauriSoldier : public character {
public:
	ChitauriSoldier() : character("LOKI ", 100, 24) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
};
class LivingAutomaton : public character {
public:
	LivingAutomaton() : character("ULTRON ", 100, 24) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
};
class BlackDwarf : public character {
public:
	BlackDwarf() : character("CullObsibian ", 100, 24) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
};
class Abonymow : public character {
public:
	Abonymow() : character("Abomination ", 100, 24) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
};
class TitanWarLord : public character {
public:
	TitanWarLord() : character("THANOS ", 100, 24) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
};
class TimeVariantKing : public character {
public:
	TimeVariantKing() : character("KANG ", 100, 24) {}
	int attack()override {
		return chr_attacking_power();
	}
	void defend(int h)override {
		int a = h / 3;
		get_health(a);
	}
	int power()override {
		int a = chr_attacking_power();
		return a * 2;
	}
	void healthgain(int h)override {
		character::healthgain(h);
	}
};
class levels {
	int level_no;
	mystr environment;
public:
	levels() {
		level_no = 0;
		environment;
	}
	character* generate_enemy() {
		if (level_no == 0) {
			character* enemies = new ChitauriSoldier;
			return enemies;
		}
		else if (level_no == 1) {
			character* enemies = new LivingAutomaton;
			return enemies;
		}
		else if (level_no == 2) {
			character* enemies = new BlackDwarf;
			return enemies;
		}
		else if (level_no == 3) {
			character* enemies = new Abonymow;
			return enemies;
		}
		else if (level_no == 4) {
			character* enemies = new TitanWarLord;
			return enemies;
		}
		else if (level_no == 5) {
			character* enemies = new TimeVariantKing;
			return enemies;
		}
	}
	void showintro() {
		if (level_no == 0) {
			cout << "THE BATTLE FIELD IS IN NEW YORK MANHATTAN NAME AS BATTLE OF NEW YORK" << endl;
		}
		else if (level_no == 1) {
			cout << "THE BATTLE FIELD IS IN SKOVIA NAME AS BATTLE OF SKOVIA" << endl;
		}
		else if (level_no == 2) {
			cout << "THE BATTLE FIELD IS IN WAKANDA NAME AS BATTLE OF WAKANDA" << endl;
		}
		else if (level_no == 3) {
			cout << "THE BATTLE FIELD IS IN ASGARD NAME AS BATTLE OF ASGARD" << endl;
		}
		else if (level_no == 4) {
			cout << "THE BATTLE FIELD IS IN TITAN NAME AS BATTLE OF TITAN" << endl;
		}
		else if (level_no == 5) {
			cout << "THE BATTLE FIELD IS IN QUANTUM REALM NAME AS BATTLE OF TIME" << endl;
		}
	}
	int healthbonus() {
		if (level_no == 0) {
			return 10;
		}
		else if (level_no == 1) {
			return 15;
		}
		else if (level_no == 2) {
			return 17;
		}
		else if (level_no == 3) {
			return 20;
		}
		else if (level_no == 4) {
			return 23;
		}
		else if (level_no == 5) {
			return 27;
		}
	}
};
int main() {
	bool flag = true, bulb = true;
	int t = 0, a = 0;
	character* hero = nullptr;
	cout << "                 ..........WELCOME TO MARVEL BATTLE ARENA GAME..............." << endl;
	cout << endl ;
	cout << "    THERE ARE TOTAL 6 CHARACTERS IN THIS GAME." << endl<<endl;
	cout << "    WHEREAS THE LEVEL IN THIS GAME ARE ALSO SIX IF YOU DEFEAT THE KANG IN THE FINAL LEVEL THEN YOU WILL WIN THIS GAME" << endl << endl;
	cout << "   WHICH CHARACTER DO YOU WANT TO CHOOSE FOR GAME LEVELS" << endl;
	while (flag == true) {
		cout << "1. THOR (GOD OF THUNDER)" << endl;
		cout << "2. DOCTOR STRANGE (MYSTIC ARTS)" << endl;
		cout << "3. IRON-MAN (ArmoredAvenger)" << endl;
		cout << "4. HAWKAYE (Archer)" << endl;
		cout << "5. CAPTAIN AMERICA (SuperSoldier)" << endl;
		cout << "6. HULK (GAMMA-RADIATION)" << endl;
		cout << "ENTER YOUR INPUT" << endl;
		cin >> t;
		if (t < 1 || t>6) {
			cout << "INVALID INPUT. TRY AGAIN" << endl;
		}
		else {
			if (t == 1) {
				 hero = new GodOfThunder;
			}
			else if (t == 2) {
				 hero = new MysticArts;
			}
			else if (t == 3) {
				 hero = new ArmoredAvenger;
			}
			else if (t == 4) {
				 hero = new Archer;
			}
			else if (t == 5) {
				 hero = new SuperSoldier;
			}
			else if (t == 6) {
				 hero = new GammaRadiation;
			}
			cout <<endl<< "THE CHOSEN CHARACTER CHARACTERISTIC :" << endl;
			hero[0].display();
			flag = false;
		}
	}
	while (flag == false) {
		cout << "DO YOU WANT TO READ THE TUTORIAL OF THIS GAME (1.YES  AND  2.NO) :" << endl;
		cin >> t;
		if (t < 1 || t>2) {
			cout << "INVALID INPUT. TRY AGAIN" << endl;
		}
		else {
			if (t == 1) {
				while (bulb == true) {
					system("cls");
					cout << "THIS GAME HAS 3 MODES: " << endl;
					cout << "1. ATTACK:  Give normal damage to the enemy." << endl;
					cout << "2 DEFEND:  Reduces the damage received from the enemy's next attack." << endl;
					cout << "3. POWERBOOM:  Uses a special ability that deals higher damage than a normal attack." << endl;
					cout << "YOU CAN PRESS ONE BUTTON AT ANY TIME IN ONE MINUTE ROUND OF EVERY LEVEL" << endl;
					cout << "THE OPPONENT ALSO ATTACKS YOU OR DEFEND HIMSELF AT ANY TIME" << endl;
					cout << endl;
					cout << "           DO YOU UNDERSTAND THE TUTORIAL (1.YES  AND  2.NO)" << endl;
					cin >> a;
					if (a < 1 || a>2) {
						cout << "INVALID INPUT. I MOVE TO THE GAME" << endl;
						bulb = false;
					}
					else {
						if (a == 2) {
							cout << "READ AGAIN THE TUTORIAL" << endl;
							Sleep(1000);
						}
						else {
							cout << "NOW THE GAME HAS BEEN STARTED" << endl;
							bulb = false;
						}
						
					}
				}
				flag = true;
			}
			else if (t == 2) {
				cout << "OK. THEN THE GAME HAS BEEN STARTED" << endl;
				flag = true;
			}
		}
	}
	Sleep(500);
	system("cls");
	
	
	

}
