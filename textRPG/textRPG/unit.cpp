#include "main.h"




extern char tempMap[27][68];
extern bool FLAG_mapUpdate;
extern bool FLAG_infoWindowUpdate;
extern bool FLAG_Monster_More_information;
extern bool FLAG_playing_battle;
extern int Battle_log_row;
extern Character My_Character;

//=======================================================
// Unit Class �Լ� ����
//=======================================================
Unit::Unit() : Name("NONAME"), Level(1), MaxHP(100), CurrentHP(100), Att(10), Def(5), Gold(1000), AddAtt(0)
{

}
Unit::Unit(string name, int level, int maxhp, int att, int gold)
	:Name(name), Level(level), MaxHP(maxhp), CurrentHP(maxhp), Att(att), Def(0), Gold(30), AddAtt(0)
{

}

Unit::Position::Position() : x(1), y(1)
{

}

void Unit::Position::Move(int inputX,int inputY,int * dungeonStage,int *infoWindowType)	// �̵� �� ������Ʈ ��ȣ�ۿ�
{
	char mapObject = tempMap[this->y + inputY - 1][this->x + inputX - 2]; // �̸� �̵��� ���� ������Ʈ
	Game game;
	if (mapObject == '0')		// �� ĭ
	{
		setcolor(WHITE, BLACK);
		gotoxy(this->x, this->y);
		cout << " ";

		setcolor(YELLOW, BLACK);
		gotoxy(this->x + inputX, this->y + inputY);
		cout << "@";
		setcolor(WHITE, BLACK);

		this->x += inputX;
		this->y += inputY;
	}
	else if (mapObject == 's')	// ����
	{
		game.Store_Process(*dungeonStage, infoWindowType);
	}
	else if (mapObject == 'm')	// ����
	{
		game.Battle_Process(*dungeonStage, infoWindowType);
		tempMap[this->y + inputY - 1][this->x + inputX - 2] = '0';	// ���� ���� �� ������� ������ֱ�
	}
	else if (mapObject == 'd')	// ������
	{
		// (* dungeonStage)++; << ���߻���ҿ���
		*dungeonStage = (*dungeonStage % 3) + 1;	// �׽�Ʈ, 
		FLAG_mapUpdate = true;			// ���� ���������, �ʾ�����Ʈ
		FLAG_infoWindowUpdate = true;	// ���� ���������, ����â�� ���������� �����ϱ�����
	}

}

// Getter �Լ�
string Unit::GetName()
{
	return this->Name;
}
int Unit::GetLV()
{
	return this->Level;
}
int Unit::GetMaxHP()
{
	return this->MaxHP;
}
int Unit::GetCurrentHP()
{
	return this->CurrentHP;
}
int Unit::GetAtt()
{
	return this->Att;
}
int Unit::GetDef()
{
	return this->Def;
}
int Unit::GetGold()
{
	return this->Gold;
}
int Unit::GetAddAtt()
{
	return this->AddAtt;
}


// Setter �Լ�
void Unit::SetName(string& name)
{
	this->Name = name;
}
void Unit::SetLV(int level)
{
	this->Level = level;
}
void Unit::SetMaxHP(int maxhp)
{
	this->MaxHP = maxhp;
}
void Unit::SetCurrentHP(int hp)
{
	this->CurrentHP = hp;
}
void Unit::SetAtt(int att)
{
	this->Att = att;
}
void Unit::SetDef(int def)
{
	this->Def = def;
}
void Unit::SetGold(int gold)
{
	this->Gold = gold;
}
void Unit::SetAddAtt(int addAtt)
{
	this->AddAtt = addAtt;
}
void Unit::test()
{

}


//=======================================================
// Charactor Class �Լ� ����
//=======================================================
Character::Character() : Character_Class(0), MaxExp(100), CurrentExp(0), MaxMP(100), CurrentMP(100),Unit()
{

}
Character::Character(int Character_Class, int MaxExp, int CurrentExp, int MaxMp, int CurrentMP)
	: Character_Class(Character_Class), MaxExp(MaxExp), CurrentExp(CurrentExp), MaxMP(MaxMp), CurrentMP(CurrentMP)
{

}

// Getter �Լ�
int Character::GetClass()
{
	return this->Character_Class;
}
int Character::GetMaxExp()
{
	return this->MaxExp;
}
int Character::GetCurrentExp()
{
	return this->CurrentExp;
}
int Character::GetMaxMP()
{
	return this->MaxMP;
}
int Character::GetCurrentMP()
{
	return this->CurrentMP;
}

// Setter �Լ�
void Character::SetClass(int charac_class)
{
	this->Character_Class = charac_class;
}
void Character::SetMaxExp(int max_exp)
{
	this->MaxExp = max_exp;
}
void Character::SetCurrentExp(int current_exp)
{
	this->CurrentExp = current_exp;
}
void Character::SetMaxMP(int max_mp)
{
	this->MaxMP = max_mp;
}
void Character::SetCurrentMP(int current_mp)
{
	this->CurrentMP = current_mp;
}
void Character::SetResurrection()
{
	this->CurrentMP = MaxMP; 
	this->SetCurrentHP(this->GetMaxHP());
	this->CurrentExp = (this->CurrentExp) - (this->CurrentExp/10);
	this->SetGold(this->GetGold() - (this->GetGold()/10));
}


void Character::Attack(Monster* monster)
{
	Game game;
	int totalAtt = this->GetAtt() + this->GetAddAtt();
	int damage= 0;
	damage = (rand() % totalAtt) + (totalAtt / 2);	// ex) �Ѱ��ݷ� 100�� ��, 50~150�� ������������ �ش�.
													// ex) �Ѱ��ݷ� 150�� ��, 75~225�� ������������ �ش�.

	if ((monster->GetCurrentHP() - damage) <= 0)		// ���� ü�� 0���� �϶�
	{
		monster->SetCurrentHP(0);


		gotoxy(72, Battle_log_row += 2); cout << "�� ";
		setcolor(RED, BLACK);	cout << monster->GetName();
		setcolor(WHITE, BLACK);	cout << "�� óġ�߽��ϴ�.";
		monster->Dead();			// ���� ����

		FLAG_playing_battle = false;
		game.Remove_At_Battle_End(); //
	}
	else												// ���� ü�� 1�̻� �϶�
	{
		monster->SetCurrentHP(monster->GetCurrentHP() - damage);
		
		gotoxy(72, Battle_log_row += 2); cout << "�� ";
		setcolor(RED, BLACK);	cout << monster->GetName();
		setcolor(WHITE, BLACK); cout << "��(��) ";
		setcolor(PURPLE, BLACK);cout << damage;
		setcolor(WHITE, BLACK);	cout << "�� ���ظ� �Ծ���.";
	}
}
void Character::Dead()			
{

}
//=======================================================
// Monster Class �Լ� ����
//=======================================================
Monster::Monster() : Unit(), exp(0) {}
Monster::Monster(string name, int level, int maxhp, int att, int exp, int gold) : Unit(name,level,maxhp,att,gold), exp(exp)
{

}

void Monster::SetMonster(string name, int level, int maxhp, int att, int exp, int gold)
{
	this->SetName(name);
	this->SetLV(level);
	this->SetMaxHP(maxhp);
	this->SetCurrentHP(maxhp);
	this->SetAtt(att);
	this->SetAddAtt(0);
	this->SetGold(gold);
	this->exp = exp;
}
void Monster::ShowMonster()
{
	int row = 37;
	gotoxy(16, row++); cout << "====================" << "          ";
	gotoxy(16, row++); cout << "[LV." << GetLV() << "]  " << GetName() << "          "; row++;
	gotoxy(16, row++); cout << "HP : " << GetCurrentHP() << " / " << GetMaxHP() << "           ";
	gotoxy(16, row++); cout << "���ݷ� : " << GetAtt() << endl;
	if (FLAG_Monster_More_information)
	{
		gotoxy(16, row++);  cout << "ȹ�� ����ġ: " << GetExp() << "           ";
		gotoxy(16, row++);  cout << "ȹ��  GOLD : " << GetGold() << "           ";
	}
	gotoxy(16, row++); cout << "====================";
}

int Monster::GetExp()
{
	return this->exp;
}
void Monster::SetExp(int exp)
{
	this->exp = exp;
}

void Monster::Attack(Character* character,int dungeonStage)
{
	int totalAtt = this->GetAtt() + this->GetAddAtt();
	int damage = 0;
	damage = (rand() % totalAtt) + (totalAtt / 2);	// ex) �Ѱ��ݷ� 100�� ��, 50~150�� ������������ �ش�.
													// ex) �Ѱ��ݷ� 150�� ��, 75~225�� ������������ �ش�.
	Game game;

	if ((character->GetCurrentHP() - damage) <= 0)		// ĳ���� ü�� 0���� �϶�
	{
		character->SetCurrentHP(character->GetCurrentHP() - damage);
		
		gotoxy(72, Battle_log_row += 2); cout << "�� ";
		setcolor(GREEN, BLACK);	cout << My_Character.GetName();
		setcolor(WHITE, BLACK); cout << "��(��) ";
		setcolor(PURPLE, BLACK); cout << damage;
		setcolor(WHITE, BLACK);	cout << "�� ���ظ� �԰� ";
		setcolor(RED, BLACK); cout << "�׾����ϴ�.";
		setcolor(WHITE, BLACK);


		FLAG_playing_battle = false;	
		game.Remove_At_Battle_End();	// ������ ȭ������� ����
		game.Map_Window(dungeonStage);	// �ؼ������ǡ� �׾����� ���� ������
	}
	else
	{
		gotoxy(72, Battle_log_row += 2);
		cout << "�� ";
		setcolor(GREEN, BLACK); cout << character->GetName();
		setcolor(WHITE, BLACK); cout << "��(��) ";
		setcolor(PURPLE, BLACK);cout << damage;
		setcolor(WHITE, BLACK);	cout <<"�� ���ظ� �Ծ���.";

	//	��
		character->SetCurrentHP(character->GetCurrentHP() - damage);
	}
	
}
void Monster::Dead()
{
	My_Character.SetGold(this->GetGold() + My_Character.GetGold());			// �� ȹ��

	if (My_Character.GetCurrentExp() + this->GetExp() >= My_Character.GetMaxExp()) // �������ؾߵ�
	{
		My_Character.SetCurrentExp(0);					// ���� ����ġ�� 0
		My_Character.SetLV(My_Character.GetLV() + 1);	// LV ��
		My_Character.SetMaxExp(My_Character.GetMaxExp() + My_Character.GetMaxExp() / 25);	// �ִ��ġ 20%����
		My_Character.SetMaxHP(My_Character.GetMaxHP() + (My_Character.GetMaxHP() / 15));
		My_Character.SetMaxMP(My_Character.GetMaxMP() + (My_Character.GetMaxMP() / 15));
	}
	else
	{
		My_Character.SetCurrentExp(My_Character.GetCurrentExp() + this->GetExp());
	}
}