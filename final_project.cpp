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
	virtual void get_health(int a) {
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
	virtual void display(Font myFonts) {
		DrawTextEx(myFonts, TextFormat("NAME: %s", name.print()), Vector2{ 1280 / 10, 350 }, 50, 2, WHITE);
		DrawTextEx(myFonts, TextFormat("HEALTH: %i", health), Vector2{ 1280 / 10, 420 }, 50, 2, WHITE);
		DrawTextEx(myFonts, TextFormat("ATTACKING POWER: %i", attacking_power), Vector2{ 1280 / 10, 490 }, 50, 2, WHITE);
	}
};
int character::total_characters = 0;
// HERO CLASSES
class GodOfThunder : public character {
public:
	GodOfThunder() : character("THOR ", 100, 9) {}
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
	void display(Font myFonts){
		character::display(myFonts);
	}
	mystr chr_name() {
		return character::chr_name();
	}
	void get_health(int a) {
		character::get_health(a);
	}
};
class MysticArts : public character {
public:
	MysticArts() : character("DOCTOR STRANGE ", 100, 12) {}
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
	void display(Font myFonts) {
		character::display(myFonts);
	}
	mystr chr_name() {
		return character::chr_name();
	}
	void get_health(int a) {
		character::get_health(a);
	}
};
class ArmoredAvenger : public character {
public:
	ArmoredAvenger() : character("IRON-MAN ", 100, 7) {}
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
	void display(Font myFonts) {
		character::display(myFonts);
	}
	mystr chr_name() {
		return character::chr_name();
	}
	void get_health(int a) {
		character::get_health(a);
	}
};
class Archer : public character {
public:
	Archer() : character("HAWKAYE ", 100, 5) {}
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
	void display(Font myFonts) {
		character::display(myFonts);
	}
	mystr chr_name() {
		return character::chr_name();
	}
	void get_health(int a) {
		character::get_health(a);
	}
};
class SuperSoldier : public character {
public:
	SuperSoldier() : character("CAPTAIN-AMERICA ", 100, 8) {}
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
	void display(Font myFonts) {
		character::display(myFonts);
	}
	mystr chr_name() {
		return character::chr_name();
	}
	void get_health(int a) {
		character::get_health(a);
	}
};
class GammaRadiation : public character {
public:
	GammaRadiation() : character("HULK ", 100, 6) {}
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
	void display(Font myFonts) {
		character::display(myFonts);
	}
	mystr chr_name() {
		return character::chr_name();
	}
	void get_health(int a) {
		character::get_health(a);
	}
};
//   ENEMY CLASSES
class ChitauriSoldier : public character {
public:
	ChitauriSoldier() : character("LOKI ", 100, 6) {}
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
	void get_health(int a) {
		character::get_health(a);
	}
};
class LivingAutomaton : public character {
public:
	LivingAutomaton() : character("ULTRON ", 100, 7) {}
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
	void get_health(int a) {
		character::get_health(a);
	}
};
class BlackDwarf : public character {
public:
	BlackDwarf() : character("CullObsibian ", 100, 8) {}
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
	void get_health(int a) {
		character::get_health(a);
	}
};
class Abonymow : public character {
public:
	Abonymow() : character("Abomination ", 100, 9) {}
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
	void get_health(int a) {
		character::get_health(a);
	}
};
class TitanWarLord : public character {
public:
	TitanWarLord() : character("THANOS ", 100, 10) {}
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
	void get_health(int a) {
		character::get_health(a);
	}
};
class TimeVariantKing : public character {
public:
	TimeVariantKing() : character("KANG ", 100, 12) {}
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
	void get_health(int a) {
		character::get_health(a);
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
	int a = 0, z = 0, b = 0, y = 0;
	bool flag = true;
	mystr _n;
	character* hero = nullptr;
	character* villian = new GammaRadiation;
	levels level;
	const int screen_width = 1280;
	const int screen_length = 800;
	InitWindow(screen_width, screen_length, "MARVEL BATTLE ARENA");
	InitAudioDevice();
	SetTargetFPS(60);
	Texture2D Front_Page = LoadTexture("front_page.jpg");
	Texture2D Selection = LoadTexture("selection.jpg");
	Texture2D Tutorial = LoadTexture("tutorial.jpg");
	Texture2D level1 = LoadTexture("lokiscene1.jpeg");
	Music theme = LoadMusicStream("marvel.mp3.mp3");
	float timer = 0, time = 0, enemytimer = 0, tim = 0, pause = 0, paus = 0;
	Font myFont = LoadFont("googlesans.ttf");
	cout << myFont.texture.id << endl;
	PlayMusicStream(theme);
	while (WindowShouldClose() == false) {
		UpdateMusicStream(theme);
		timer += GetFrameTime();
		time += GetFrameTime();
		enemytimer += GetFrameTime();
		tim += GetFrameTime();
		pause += GetFrameTime();
		paus += GetFrameTime();
		BeginDrawing();
	//drawing
		if (a == 0) {
			//ClearBackground(BLACK);
			DrawTexturePro(Front_Page,Rectangle{ 0, 0, (float)Front_Page.width, (float)Front_Page.height },Rectangle{ 0, 0, (float)screen_width, (float)screen_length },Vector2{ 0, 0 },0,WHITE);
			/*DrawRectangle(screen_width / 5+50, 0, screen_width / 5+100,screen_length,RED);
			DrawRectangle(screen_width -256, 0, screen_width-256, screen_length, RED);
			*/DrawText("WELCOME", screen_width / 3 - 60, 60, 120, WHITE);
			/*DrawTextEx(myFont, "WELCOME", Vector2{ screen_width / 3 - 60, 60 }, 120, 4, WHITE);
			DrawTextEx(myFont, "TO", Vector2{ screen_width / 3 + 100, 200 }, 120, 4, WHITE);
			DrawTextEx(myFont, "WELCOME", Vector2{ screen_width / 8, 340 }, 120, 4, WHITE);
			DrawTextEx(myFont, "WELCOME", Vector2{ screen_width / 3, 500 }, 120, 4, WHITE);
			*/DrawText("TO", screen_width / 3+100, 200, 120, WHITE);
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
			DrawTexturePro(Selection,Rectangle{ 0, 0, (float)Selection.width, (float)Selection.height }, Rectangle{ 0, 0, (float)screen_width, (float)screen_length }, Vector2{ 0, 0 }, 0, WHITE);
			DrawText("SELECT CHARACTER", screen_width / 4-60, 60, 80, WHITE);
			//DrawText("1. THOR   (god of thunder)", screen_width / 10, 200, 30, BLACK);
			//DrawText("2. DOCTOR STRANGE   (mystic arts)", screen_width / 10, 250, 30, BLACK);
			DrawTextEx(myFont, "1. THOR   (god of thunder)", Vector2{ screen_width / 10, 200 }, 30, 4, WHITE);
			DrawTextEx(myFont, "2. DOCTOR STRANGE   (mystic arts)", Vector2{ screen_width / 10, 250 }, 30, 4, WHITE);
			DrawTextEx(myFont, "3. IRON-MAN   (armored avenger)", Vector2{ screen_width / 10, 300 }, 30, 4, WHITE);
			DrawTextEx(myFont, "4. HAWKAYE   (archer)", Vector2{ screen_width / 10, 350 }, 30, 4, WHITE);
			DrawTextEx(myFont, "5. CAPTAIN-AMERICA   (super soldier)", Vector2{ screen_width / 10, 400 }, 30, 4, WHITE);
			DrawTextEx(myFont, "6. HULK   (gamma radiation)", Vector2{ screen_width / 10, 450 }, 30, 4, WHITE);
			//DrawTextEx(myFont, "ENTER YOUR CHOICE: ", Vector2{ screen_width / 10, 550 }, 30, 2, BLACK);
			DrawText("ENTER YOUR CHOICE: ", screen_width / 10, 550, 30, RED);
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
			//ClearBackground(LIGHTGRAY);
			DrawTexturePro(Front_Page, Rectangle{ 0, 0, (float)Front_Page.width, (float)Front_Page.height }, Rectangle{ 0, 0, (float)screen_width, (float)screen_length }, Vector2{ 0, 0 }, 0, WHITE);
			DrawText("CHARACTERISTICS", screen_width / 4 - 60, 60, 80, WHITE);
			DrawText("OF", screen_width / 2, 150, 80, WHITE);
			DrawText("CHOSEN CHARACTER", screen_width / 4 - 60, 220, 80, WHITE);
			hero[0].display(myFont);
			DrawText("DO YOU WANT TO READ TUTORIAL", screen_width / 10, 590, 50, WHITE);
			//DrawText("(1.YES  AND  2.NO)", screen_width / 4, 650, 37, WHITE);
			DrawTextEx(myFont, "(1.YES  AND  2.NO)", Vector2{ screen_width / 4, 650 }, 37, 4, WHITE);
			if (IsKeyPressed(KEY_ONE)) {
				a = 4;
			}
			if (IsKeyPressed(KEY_TWO)) {
				a = 5;
			}
		}
		else if (a == 4) {
			ClearBackground(LIGHTGRAY);
			DrawTexturePro(Tutorial, Rectangle{ 0, 0, (float)Tutorial.width, (float)Tutorial.height }, Rectangle{ 0, 0, (float)screen_width, (float)screen_length }, Vector2{ 0, 0 }, 0, WHITE);

			DrawText("THIS GAME HAS 3 MODES:", screen_width /6, 50, 60, LIGHTGRAY);
			DrawText("1. ATTACK:", screen_width / 10, 150, 35, LIGHTGRAY);
			//DrawText("Give normal damage to the enemy.", screen_width / 4+20, 160, 30, DARKBROWN);
			DrawTextEx(myFont, "Give normal damage to the enemy.", Vector2{ screen_width / 4 + 20, 160 }, 30, 3, WHITE);
			DrawText("1. DEFEND:", screen_width / 10, 200, 35, LIGHTGRAY);
			//DrawText("Reduces the damage received from the enemy's next attack.", screen_width / 4 + 20, 210, 30, DARKBROWN);
			DrawTextEx(myFont, "Reduces the damage received from the enemy's next attack.", Vector2{ screen_width / 4 + 20, 210 }, 30, 4, WHITE);
			DrawText("1. POWERBOOM:", screen_width / 10, 250, 35, LIGHTGRAY);
			//DrawText("Uses a special ability that deals higher damage than a ", screen_width / 4 + 90, 260, 30, DARKBROWN);
			DrawTextEx(myFont, "Uses a special ability that deals higher damage than a", Vector2{ screen_width / 4 + 90, 260 }, 30, 4, WHITE);
			DrawTextEx(myFont, "normal attack.", Vector2{ screen_width / 4 + 90, 290 }, 30, 4, WHITE);
			//DrawText("normal attack.", screen_width / 4 + 90, 290, 30, DARKBROWN);
			//DrawText("YOU CAN PRESS ONE BUTTON AT ANY TIME IN ONE MINUTE ", screen_width / 15, 430, 35, BLACK);
			DrawTextEx(myFont, "YOU CAN PRESS ONE BUTTON AT ANY TIME IN ONE MINUTE", Vector2{ screen_width / 15+30, 500 }, 35, 4, LIGHTGRAY);
			//DrawText(" ROUND OF EVERY LEVEL.", screen_width / 3, 470, 35, BLACK);
			DrawTextEx(myFont, " ROUND OF EVERY LEVEL.", Vector2{ screen_width / 3+30, 540 }, 35, 4, LIGHTGRAY);
			//DrawText("THE OPPONENT ALSO ATTACKS YOU OR DEFEND HIMSELF  ", screen_width / 15, 570, 35, BLACK);
			DrawTextEx(myFont, "THE OPPONENT ALSO ATTACKS YOU OR DEFEND HIMSELF  ", Vector2{ screen_width / 15+30, 600 }, 35, 4, LIGHTGRAY);
			//DrawText(" AT ANY TIME.", screen_width / 3, 610, 35, BLACK);
			DrawTextEx(myFont, " AT ANY TIME.", Vector2{ screen_width / 3+30, 640 }, 35, 4, LIGHTGRAY);
			DrawText("CAN WE START THE GAME ", screen_width / 15, 700, 35, LIGHTGRAY);
			DrawTextEx(myFont, "(1.YES  AND  2.NO)", Vector2{ screen_width / 15, 750 }, 35, 4, LIGHTGRAY);
			//DrawText("(1.YES  AND  2.NO)", screen_width / 15, 720, 35, BLACK);
			if (IsKeyPressed(KEY_ONE)) {
				a = 5;

			}
			if (IsKeyPressed(KEY_TWO)) {
			}
		}
		else if (a == 5) {
			if (level.level_number() == 1) {
				ClearBackground(SKYBLUE);
				DrawTexturePro(level1, Rectangle{ 0, 0, (float)level1.width, (float)level1.height }, Rectangle{ 0, 0, (float)screen_width, (float)screen_length }, Vector2{ 0, 0 }, 0, WHITE);
			}
			else if (level.level_number() == 2) {
				ClearBackground(MAGENTA);
			}
			else if (level.level_number() == 3) {
				ClearBackground(light_green);
			}
			else if (level.level_number() == 4) {
				ClearBackground(light_green);
			}
			else if (level.level_number() == 5) {
				ClearBackground(light_green);
			}
			else if (level.level_number() == 6) {
				ClearBackground(light_green);
			}
			DrawText(TextFormat("LEVEL: %i", level.level_number()), screen_width / 2 - 100, 40, 40, WHITE);
			villian = level.generate_enemy(villian);
			_n = villian[0].chr_name();
			DrawText(TextFormat("OPPONENT: ", _n.print()), screen_width / 2 - 180, 100, 40, WHITE);
			DrawText(TextFormat("%s ", _n.print()), screen_width / 2+100 , 99, 50, PURPLE);
			DrawText("ENVIRONMENT OF BATTLE FIELD:", screen_width / 2 - 350, 160, 40, WHITE);
			DrawText(TextFormat("%s", level.showintro().print()), screen_width / 5- 210, 220, 29, WHITE);
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
			if (IsKeyPressed(KEY_A)) {
				if (b != 5) {
					villian->get_health(hero->attack());
				}
			}
			if (IsKeyPressed(KEY_P)) {
				if (b != 5) {
					villian->get_health(hero->power());
				}
			}
			if (IsKeyPressed(KEY_D)) {
				b = 5;
				if (time >= 2.0f) {
					cout << "timer passed" << endl;
					time = 0;
					b = 6;
				}
			}
			DrawText(TextFormat("HEALTH:", hero->chr_health()), screen_width / 15 + 30, 570, 40, BLACK);
			DrawText(TextFormat(" %i", hero->chr_health()), screen_width / 15 + 230, 570, 40, green);
			DrawText(TextFormat("HEALTH:", villian->chr_health()), 650 + 30, 570, 40, BLACK);
			DrawText(TextFormat(" %i", villian->chr_health()), 650 + 230, 570, 40, green);
			DrawText("YOU HAVE ONE MINUTE FOR EVERY ROUND", screen_width / 15 + 150, 760, 30, WHITE);
			DrawText("PRESS ENTER KEY TO START THE ROUND", screen_width / 15 + 150, 270, 30, WHITE);
			if (z == 0) {
				if (IsKeyPressed(KEY_ENTER)) {
					z = 1;
					timer = 0;
					a = 6;
				}
			}
			if (z == 1) {
				if (timer <= 60.0f) {
					DrawText(TextFormat("TIME: %.0f", timer), screen_width / 3, 700, 40, BLACK);
				}
				else if (timer > 60.0f) {
					timer = 0;
					a++;
				}
			}
		}
		else if (a == 6) {
			if (level.level_number() == 1) {
				ClearBackground(SKYBLUE);
				DrawTexturePro(Front_Page, Rectangle{ 0, 0, (float)Front_Page.width, (float)Front_Page.height }, Rectangle{ 0, 0, (float)screen_width, (float)screen_length }, Vector2{ 0, 0 }, 0, WHITE);
			}
			else if (level.level_number() == 2) {
				ClearBackground(MAGENTA);
			}
			else if (level.level_number() == 3) {
				ClearBackground(light_green);
			}
			else if (level.level_number() == 4) {
				ClearBackground(light_green);
			}
			else if (level.level_number() == 5) {
				ClearBackground(light_green);
			}
			else if (level.level_number() == 6) {
				ClearBackground(light_green);
			}
			DrawText(TextFormat("LEVEL: %i", level.level_number()), screen_width / 2 - 100, 40, 40, BLACK);
			_n = villian[0].chr_name();
			DrawText(TextFormat("OPPONENT: ", _n.print()), screen_width / 2 - 180, 100, 40, BLACK);
			DrawText(TextFormat("%s ", _n.print()), screen_width / 2 + 100, 99, 50, DARKBLUE);
			DrawText("ENVIRONMENT OF BATTLE FIELD:", screen_width / 2 - 350, 160, 40, BLACK);
			DrawText(TextFormat("%s", level.showintro().print()), screen_width / 5 - 210, 220, 29, BLACK);
			DrawRectangle(screen_width / 15, 300, 540, 450, LIGHTGRAY);
			DrawRectangle(650, 300, 570, 450, LIGHTGRAY);
			DrawText(TextFormat("%s", hero->chr_name().print()), 200, 320, 30, BLACK);
			DrawText(TextFormat("%s", villian->chr_name().print()), 765, 320, 30, BLACK);
			DrawText("ATTACK", screen_width / 15 + 30, 400, 27, BLACK);
			DrawText("PRESS ", screen_width / 15 + 180, 400, 27, BLACK);
			DrawText("A", screen_width / 15 + 280, 400, 27, RED);
			DrawText(" FOR ATTACK", screen_width / 15 + 297, 400, 27, BLACK);
			DrawText("ATTACK", 650 + 30, 400, 27, BLACK);
			DrawText("PRESS ", 650 + 180, 400, 27, BLACK);
			DrawText("A", 650 + 280, 400, 27, RED);
			DrawText(" FOR ATTACK", 650 + 297, 400, 27, BLACK);
			DrawText("DEFEND", 650 + 30, 450, 27, BLACK);
			DrawText("PRESS ", 650 + 180, 450, 27, BLACK);
			DrawText("D", 650 + 280, 450, 27, RED);
			DrawText(" FOR DEFEND", 650 + 297, 450, 27, BLACK);
			DrawText("DEFEND", screen_width / 15 + 30, 450, 27, BLACK);
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
			if (IsKeyPressed(KEY_A)) {
				if (y != 5&&y==0) {
					villian->get_health(hero->attack());
					y = 2;
				}
			}
			if (IsKeyPressed(KEY_P)) {
				if (y != 5&&y==0) {
					villian->get_health(hero->power());
					y = 2;
				}
			}
			if (IsKeyPressed(KEY_D)) {
				if (y == 0) {
					b = 5;
					time = 0;
					y = 2;
				}
			}
			if (time >= 4.0f) {
				cout << "timer passed" << endl;
				time = 0;
				b = 0;
			}
			if (enemytimer >= 2.0f) {
				int choice = rand() % 3;
				if (choice == 0) {
					if (b != 5&&b==0) {
						hero->get_health(villian->power());
						b = 2;
					}
					enemytimer = 0;
				}
				else if (choice == 1) {
					if (b != 5&&b==0) {
						hero->get_health(villian->attack());
						b = 2;
					}
					enemytimer = 0;
				}
				else if (choice == 2) {
					if (b == 0) {
						y = 5;
						tim = 0;
						enemytimer = 0;
						b = 2;
					}
				}
				if (tim >= 4.0f) {
					cout << "timer passed" << endl;
					tim = 0;
					y = 0;
				}
				if (b == 2) {
					pause = 0;
					if (pause >= 2.0f) {
						cout << "timer passed" << endl;
						b = 0;
					}
				}
				if (y == 2) {
					pause = 0;
					if (paus >= 2.0f) {
						cout << "timer passed" << endl;
						y = 0;
					}
				}
			}
			DrawText(TextFormat("HEALTH:", hero->chr_health()), screen_width / 15 + 30, 570, 40, BLACK);
			DrawText(TextFormat(" %i", hero->chr_health()), screen_width / 15 + 230, 570, 40, green);
			DrawText(TextFormat("HEALTH:", villian->chr_health()), 650 + 30, 570, 40, BLACK);
			DrawText(TextFormat(" %i", villian->chr_health()), 650 + 230, 570, 40, green);
			DrawText("YOU HAVE ONE MINUTE FOR EVERY ROUND", screen_width / 15 + 150, 760, 30, BLACK);
			DrawText("PRESS ENTER KEY TO START THE ROUND", screen_width / 15 + 150, 270, 30, BLACK);
			if (z == 1) {
				if (timer <= 60.0f) {
					DrawText(TextFormat("TIME: %.0f", timer), screen_width / 3, 700, 40, BLACK);
				}
				else if (timer > 60.0f) {
					timer = 0;
					a = 7;
				}
			}
			if (villian->chr_health() <= 0) {
				a = 5;
				level.increase_level();
				z = 0;
			}
			if (hero->chr_health() <= 0) {
				a = 7;
			}
		}
		else if (a == 7) {
			ClearBackground(BLACK);
		}
		EndDrawing();
	}

	UnloadMusicStream(theme);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
