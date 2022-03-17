#pragma once

enum charactor_class{ NO_CLASS, WARRIOR, ARCHER, WIZARD};

class Item
{
private:
	string Name;
	int Price;

public:
	Item();
	Item(string, int);
	virtual ~Item();

	
	void SetName(const string& name);
	void SetPrice(int);

	string GetName();
	int GetPrice();

	// virtual
	virtual int GetIsUse();
	virtual int GetCount();
	
	virtual void SetIsUse(int isuse);
	virtual void SetCount(int count);
	
	virtual void UseItem();
	virtual void ShowInfo();
	virtual int IsEquipment();
};

class Equipment : public Item
{
private:
	int HP;
	int MP;
	int Att;
	int Def;
	bool IsUse;
	int Count;

public:
	Equipment();
	Equipment(string Name, int Price, int Att); // 무기용
	Equipment(string Name, int Price, int Hp, int Mp, int Def); // 방어구용


	// virtual
	int GetIsUse();
	void SetIsUse(int isuse);

	int GetCount();
	void SetCount(int count);

	void UseItem();
	void ShowInfo();
	int IsEquipment();
};

class Potion : public Item
{
private:
	int Count;
	int HP;
	int MP;
public:
	Potion();
	Potion(string Name, int Hp, int Mp, int Price, int Count);


	// virtual
	int GetCount();
	void SetCount(int count);

	int GetIsUse();
	void SetIsUse(int isuse);

	void UseItem();
	void ShowInfo();
	int IsEquipment();
};
