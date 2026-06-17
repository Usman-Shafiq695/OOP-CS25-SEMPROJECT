#include<iostream>
#include<fstream>
#include<raylib.h>
#include"mystr.h"
using namespace std;
Color green = Color{ 38,185,154,255 };
Color light_green = Color{ 129,204,184,255 };
Color Dark_green = Color{ 20,160,133,255 };
Color Yellow = Color{ 243,213,91,255 };
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
    virtual mystr chr_name() {
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
		DrawText(TextFormat("NAME: %s",name.print()), 1280 / 10, 350, 50, BLACK);
		DrawText(TextFormat("HEALTH: %i", health), 1280 / 10, 420, 50, BLACK);
		DrawText(TextFormat("ATTACKING POWER: %i", attacking_power), 1280 / 10, 490, 50, BLACK);
	}
};
int character::total_characters = 0;
// HERO CLASSES
class GodOfThunder : public character {
public:
	GodOfThunder() : character("THOR ", 100, 27) {}
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	mystr chr_name() {
		return character::chr_name();
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
	int level_number() {
		return level_no + 1;
	}
	character* generate_enemy(character* hero) {
		if (level_no == 0) {
			return hero = new ChitauriSoldier;
			
		}
		else if (level_no == 1) {
			 return hero = new LivingAutomaton;
		}
		else if (level_no == 2) {
				return hero = new BlackDwarf;
		}
		else if (level_no == 3) {
				return hero=new Abonymow;
		}
		else if (level_no == 4) {
				return hero = new TitanWarLord;
		}
		else if (level_no == 5) {
			return hero=new TimeVariantKing;
		}
	}
	mystr showintro() {
		mystr c;
		if (level_no == 0) {
			c = "THE BATTLE FIELD IS IN NEW YORK MANHATTAN NAME AS BATTLE OF NEW YORK ";
		}
		else if (level_no == 1) {
			c = "THE BATTLE FIELD IS IN SKOVIA NAME AS BATTLE OF SKOVIA " ;
		}
		else if (level_no == 2) {
			c = "THE BATTLE FIELD IS IN WAKANDA NAME AS BATTLE OF WAKANDA " ;
		}
		else if (level_no == 3) {
			c = "THE BATTLE FIELD IS IN ASGARD NAME AS BATTLE OF ASGARD " ;
		}
		else if (level_no == 4) {
			c = "THE BATTLE FIELD IS IN TITAN NAME AS BATTLE OF TITAN " ;
		}
		else if (level_no == 5) {
			c = "THE BATTLE FIELD IS IN QUANTUM REALM NAME AS BATTLE OF TIME " ;
		}
		return c;
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
	void increase_level() {
		level_no++;
	}
};
int main() {
	int a = 0;
	bool flag = true;
	mystr _n;
	character* hero = nullptr;
	character* villian = new GammaRadiation;
	levels level;
	const int screen_width = 1280;
	const int screen_length = 800;
	InitWindow(screen_width, screen_length, "MARVEL BATTLE ARENA");
	SetTargetFPS(60);
	float timer = 0;
	Font myFont = LoadFont("Roboto-Regular.ttf");
	cout << myFont.texture.id << endl;
	while (WindowShouldClose() == false) {
		timer += GetFrameTime();
		BeginDrawing();
	//drawing
		if (a == 0) {
			ClearBackground(BLACK);
			DrawRectangle(screen_width / 5+50, 0, screen_width / 5+100,screen_length,RED);
			DrawRectangle(screen_width -256, 0, screen_width-256, screen_length, RED);
			DrawText("WELCOME", screen_width / 3-60, 60, 120, WHITE);
			DrawText("TO", screen_width / 3+100, 200, 120, WHITE);
			DrawText("MARVEL BATTLE", screen_width / 8, 340, 120, WHITE);
			DrawText("ARENA", screen_width / 3, 500, 120, WHITE);
			if (timer >= 10.0f) {
				cout << "timer passed" << endl;
				timer = 0;
				a++;
			}
			if (IsKeyPressed(KEY_ENTER)) {
				timer = 0;
				a++;
			}
		}
		else if (a == 1) {
			ClearBackground(LIGHTGRAY);
			DrawText("SELECT CHARACTER", screen_width / 4-60, 60, 80, BLACK);
			DrawText("1. THOR   (god of thunder)", screen_width / 10, 200, 30, BLACK);
			DrawText("2. DOCTOR STRANGE   (mystic arts)", screen_width / 10, 250, 30, BLACK);
			DrawTextEx(myFont, "3. IRON-MAN   (armored avenger)", Vector2{ screen_width / 10, 300 }, 30, 2, BLACK);
			DrawTextEx(myFont, "4. HAWKAYE   (archer)", Vector2{ screen_width / 10, 350 }, 30, 2, BLACK);
			DrawTextEx(myFont, "5. CAPTAIN-AMERICA   (super soldier)", Vector2{ screen_width / 10, 400 }, 30, 2, BLACK);
			DrawTextEx(myFont, "6. HULK   (gamma radiation)", Vector2{ screen_width / 10, 450 }, 30, 2, BLACK);
			DrawTextEx(myFont, "ENTER YOUR CHOICE: ", Vector2{ screen_width / 10, 550 }, 30, 2, BLACK);
				if (IsKeyDown(KEY_ONE)) {
					hero = new GodOfThunder;
					a = 3;
				}
			    if (IsKeyDown(KEY_TWO)) {
					hero = new MysticArts;
					a = 3;
				}
				if (IsKeyDown(KEY_THREE)) {
					hero = new ArmoredAvenger;
					a = 3;
				}
			    if (IsKeyDown(KEY_FOUR)) {
					hero = new Archer;
					a = 3;
				}
			    if (IsKeyDown(KEY_FIVE)) {
					hero = new SuperSoldier;
					a = 3;
				}
			    if (IsKeyDown(KEY_SIX)) {
					hero = new GammaRadiation;
					a = 3;
				}
		}
		else if (a == 3) {
			ClearBackground(LIGHTGRAY);
			DrawText("CHARACTERISTICS", screen_width / 4 - 60, 60, 80, BLACK);
			DrawText("OF", screen_width / 2, 150, 80, BLACK);
			DrawText("CHOSEN CHARACTER", screen_width / 4 - 60, 220, 80, BLACK);
			hero[0].display();
			DrawText("DO YOU WANT TO READ TUTORIAL", screen_width / 10, 590, 50, WHITE);
			DrawText("(1.YES  AND  2.NO)", screen_width / 4, 650, 37, WHITE);
			if (IsKeyPressed(KEY_ONE)) {
				a = 4;
			}
			if (IsKeyPressed(KEY_TWO)) {
				a = 5;
			}
		}
		else if (a == 4) {
			ClearBackground(LIGHTGRAY);
			DrawText("THIS GAME HAS 3 MODES:", screen_width /6, 50, 60, BLACK);
			DrawText("1. ATTACK:", screen_width / 10, 150, 35, BLACK);
			DrawText("Give normal damage to the enemy.", screen_width / 4+20, 160, 30, DARKBROWN);
			DrawText("1. DEFEND:", screen_width / 10, 200, 35, BLACK);
			DrawText("Reduces the damage received from the enemy's next attack.", screen_width / 4 + 20, 210, 30, DARKBROWN);
			DrawText("1. POWERBOOM:", screen_width / 10, 250, 35, BLACK);
			DrawText("Uses a special ability that deals higher damage than a ", screen_width / 4 + 90, 260, 30, DARKBROWN);
			DrawText("normal attack.", screen_width / 4 + 90, 290, 30, DARKBROWN);
			DrawText("YOU CAN PRESS ONE BUTTON AT ANY TIME IN ONE MINUTE ", screen_width / 15, 430, 35, BLACK);
			DrawText(" ROUND OF EVERY LEVEL.", screen_width / 3, 470, 35, BLACK);
			DrawText("THE OPPONENT ALSO ATTACKS YOU OR DEFEND HIMSELF  ", screen_width / 15, 570, 35, BLACK);
			DrawText(" AT ANY TIME.", screen_width / 3, 610, 35, BLACK);
			DrawText("CAN WE START THE GAME ", screen_width / 15, 670, 35, BLACK);
			DrawText("(1.YES  AND  2.NO)", screen_width / 15, 720, 35, BLACK);
			if (IsKeyPressed(KEY_ONE)) {
				a = 5;

			}
			if (IsKeyPressed(KEY_TWO)) {
			}
		}
		else if (a == 5) {
			ClearBackground(light_green);
			DrawText(TextFormat("LEVEL: %i", level.level_number()), screen_width / 2 - 100, 40, 40, BLACK);
			villian = level.generate_enemy(villian);
			_n = villian[0].chr_name();
			DrawText(TextFormat("OPPONENT: ", _n.print()), screen_width / 2 - 180, 100, 40, BLACK);
			DrawText(TextFormat("%s ", _n.print()), screen_width / 2+100 , 99, 50, DARKBLUE);
			DrawText("ENVIRONMENT OF BATTLE FIELD:", screen_width / 2 - 350, 160, 40, BLACK);
			DrawText(TextFormat("%s", level.showintro().print()), screen_width / 5- 210, 220, 29, BLACK);
			DrawRectangle(screen_width / 15, 300,540,450,LIGHTGRAY);
			DrawRectangle(650, 300, 570, 450, LIGHTGRAY);
			DrawText(TextFormat("%s", hero->chr_name().print()), 200, 320, 30, BLACK);
			DrawText(TextFormat("%s", villian->chr_name().print()), 765, 320, 30, BLACK);
			DrawText("ATTACK", screen_width / 15 + 30 , 400, 27, BLACK);
			DrawText("PRESS ", screen_width/15 + 180, 400, 27, BLACK);
			DrawText("A", screen_width/15 + 280, 400, 27, RED);
			DrawText(" FOR ATTACK", screen_width/15 + 297, 400, 27, BLACK);
			DrawText("ATTACK", 650 + 30, 400, 27, BLACK);
			DrawText("PRESS ", 650 + 180, 400, 27, BLACK);
			DrawText("A", 650 + 280, 400, 27, RED);
			DrawText(" FOR ATTACK", 650 + 297, 400, 27, BLACK);
			DrawText("DEFEND", 650 + 30, 450, 27, BLACK);
			DrawText("PRESS ", 650 + 180, 450, 27, BLACK);
			DrawText("D", 650 + 280, 450, 27, RED);
			DrawText(" FOR DEFEND", 650 + 297, 450, 27, BLACK);
			DrawText("DEFEND", screen_width/15 + 30, 450, 27, BLACK);
			DrawText("PRESS ", screen_width / 15 + 180, 450, 27, BLACK);
			DrawText("D", screen_width / 15 + 280, 450, 27, RED);
			DrawText(" FOR DEFEND", screen_width / 15 + 297, 450, 27, BLACK);
			DrawText("POWER(BOOM)", screen_width / 15 + 7, 500, 25, BLACK);
			DrawText("PRESS ", screen_width / 15 + 190, 500, 25, BLACK);
			DrawText("P", screen_width / 15 + 285, 500, 25, RED);
			DrawText(" FOR POWER BOOM", screen_width / 15 + 300, 500, 25, BLACK);
			DrawText("POWER(BOOM)", 650 + 7, 500, 25, BLACK);
			DrawText("PRESS ", 650 + 190, 500, 25, BLACK);
			DrawText("P", 650 + 285, 500, 25, RED);
			DrawText(" FOR POWER BOOM", 650 + 300, 500, 25, BLACK);
			DrawText(TextFormat("HEALTH:", hero->chr_health()), screen_width / 15 + 30, 570, 40, BLACK);
			DrawText(TextFormat(" %i", hero->chr_health()), screen_width / 15 + 230, 570, 40, green);
			DrawText(TextFormat("HEALTH:", villian->chr_health()), 650 + 30, 570, 40, BLACK);
			DrawText(TextFormat(" %i", villian->chr_health()), 650 + 230, 570, 40, green);







		}
		EndDrawing();
	}


	CloseWindow();
	return 0;
}
