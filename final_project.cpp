#include<iostream>
#include<fstream>
#include<raylib.h>
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
};
int character::total_characters = 0;
                             // HERO CLASSES
class GodOfThunder: public character {
public:
	GodOfThunder() : character("THOR",100,27){}
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
class MysticArts : public character {
public:
	MysticArts() : character("DOCTOR STRANGE", 100, 30) {}
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
class ArmoredAvenger : public character {
public:
	ArmoredAvenger() : character("IRON-MAN", 100, 20) {}
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
class Archer : public character {
public:
	Archer() : character("HAWKAYE", 100, 17) {}
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
class SuperSoldier : public character {
public:
	SuperSoldier() : character("CAPTAIN-AMERICA", 100, 22) {}
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
class GammaRadiation : public character {
public:
	GammaRadiation() : character("HULK", 100, 24) {}
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
                                       //   ENEMY CLASSES
class ChitauriSoldier : public character {
public:
	ChitauriSoldier() : character("LOKI", 100, 24) {}
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
	LivingAutomaton() : character("ULTRON", 100, 24) {}
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
	BlackDwarf() : character("CullObsibian", 100, 24) {}
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
	Abonymow() : character("Abomination", 100, 24) {}
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
	TitanWarLord() : character("THANOS", 100, 24) {}
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
	TimeVariantKing() : character("KANG", 100, 24) {}
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

}
