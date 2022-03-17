#pragma once




class Unit
{
public:
	class Position
	{
	public:
		Position();
		void Move(int x, int y, int* stage, int* infoWindowType);
		int x;
		int y;
	};
private:
	string Name;
	int Level;
	int MaxHP;
	int CurrentHP;
	int Att;
	int Def;
	int Gold;
	int AddAtt;
	
public:
	Position pos;

	Unit();
	Unit(string name, int level, int maxhp, int att, int gold);

	string GetName();
	void SetName(string& name);

	int GetLV();
	void SetLV(int level);

	int GetMaxHP();
	int GetCurrentHP();
	int GetAtt();
	int GetDef();
	int GetGold();
	int GetAddAtt();

	void SetMaxHP(int maxhp);
	void SetCurrentHP(int hp);
	void SetAtt(int att);
	void SetDef(int def);
	void SetGold(int gold);
	void SetAddAtt(int addAtt);

	virtual void test();

};

class Character : public Unit
{
private:
	int Character_Class;
	int MaxExp;
	int CurrentExp;
	int MaxMP;
	int CurrentMP;
	
public:
	Inventory inventory;

	Character();
	Character(int Character_Class, int MaxExp, int CurrentExp, int MaxMp, int CurrentMP);


	int GetClass();
	int GetMaxExp();
	int GetCurrentExp();
	int GetMaxMP();
	int GetCurrentMP();

	void SetClass(int charac_class);
	void SetMaxExp(int max_exp);
	void SetCurrentExp(int current_exp);
	void SetMaxMP(int max_mp);
	void SetCurrentMP(int current_mp);
	void SetResurrection();

	void Attack(Monster* monster);
	void Dead();			// ƒ≥∏Ø≈Õ ªÁ∏¡Ω√ Ω∫≈»√ ±‚»≠, µ∑ »Í∏Æ±‚ µÓµÓ
};

class Monster : public Unit
{
private:
	int exp;
public:
	Monster();
	Monster(string name, int level, int maxhp, int att, int exp, int gold);

	void SetMonster(string name, int level, int maxhp, int att, int exp, int gold);
	void ShowMonster();


	int GetExp();
	void SetExp(int exp);


	void Attack(Character* character, int dungeonStage);
	void Dead();
};

