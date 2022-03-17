#include "main.h"


extern Character My_Character;


//=====================================================
// Item Class 정의
//=====================================================
Item::Item() : Name("NONAME"), Price(0) {}
Item::Item(string name, int price) : Name(name), Price(price){}
Item::~Item()
{
	//setcolor(BLACK, WHITE);	// 상점 디버그용 // 테스트
	gotoxy(48, 59); cout << "~Item 해제";
	//setcolor(WHITE, BLACK);
}

// setter
void Item::SetName(const string& name)
{
	Name = name;
}
void Item::SetPrice(int)
{
}

// getter
string Item::GetName()
{
	return Name;
}
int Item::GetPrice()
{
	return this->Price;
}


// virtual
int Item::GetCount()
{
	return VIRTUAL_RETURN;
}
void Item::SetCount(int count)
{

}

int Item::GetIsUse()
{
	return 0;		// 물약에 대해선 장착장비가 아니니깐 항상 0, 
}
void Item::SetIsUse(int isuse)
{

}

void Item::UseItem()
{

}
void Item::ShowInfo()
{
	cout << "Item" << endl;
}
int Item::IsEquipment()
{
	return VIRTUAL_RETURN;
}



//=====================================================
// Equipment Class 정의
//=====================================================
Equipment::Equipment() :HP(0), MP(0), Att(0), Def(0), IsUse(0),Count(1) {}
Equipment::Equipment(string Name, int Price, int Att)	// 무기용
	:Item(Name,Price), Att(Att), IsUse(0), Count(1),HP(0), MP(0), Def(0) {}
Equipment::Equipment(string Name, int Price, int Hp, int Mp, int Def) // 방어구용
	:Item(Name, Price), HP(Hp), MP(Mp),Def(Def),IsUse(0), Count(1), Att(0) {}


//virtual
int Equipment::GetCount()
{
	return this->Count;
}
void Equipment::SetCount(int count)
{
	this->Count = count;
}

int Equipment::GetIsUse()
{
	return IsUse;
}
void Equipment::SetIsUse(int isuse)
{
	this->IsUse = isuse;
}

void Equipment::UseItem()
{
	My_Character.SetAddAtt(this->Att);
}
void Equipment::ShowInfo()
{
	if (this->GetName() == "초심자의 대검")
	{
		cout.width(15);
		cout << this->GetName();
		if (IsUse) { cout << "(장착)";	cout.width(2); }
		else cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "공격력 +10";
	}
	else if (this->GetName() == "초심자의 죽창")
	{
		cout.width(15);
		cout << this->GetName();
		if (IsUse) { cout << "(장착)";	cout.width(2); }
		else cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "공격력 +20";
	}
	else if (this->GetName() == "중급자의 대검")
	{
		cout.width(15);
		cout << this->GetName();
		if (IsUse) { cout << "(장착)";	cout.width(2); }
		else cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "공격력 +40";
	}
	else if (this->GetName() == "중급자의 죽창")
	{
		cout.width(15);
		cout << this->GetName();
		if (IsUse) { cout << "(장착)";	cout.width(2); }
		else cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "공격력 +55";
	}
}
int Equipment::IsEquipment()	// [1] - 장비 아이템, [0] - 소비아이템 
{
	return 1;
}



//=====================================================
// Potion Class 정의
//=====================================================
Potion::Potion() :Count(0), HP(0), MP(0) {}
Potion::Potion(string Name, int Hp, int Mp, int Price, int Count)
	: Item(Name, Price), Count(Count), HP(Hp), MP(Mp) {}


//virtual
int Potion::GetCount()
{
	return this->Count;
}
void Potion::SetCount(int count)
{
	this->Count = count;
}

int Potion::GetIsUse()
{
	return VIRTUAL_RETURN;
}
void Potion::SetIsUse(int isuse)
{

}

void Potion::UseItem()
{
	SetCount(GetCount() - 1);	// 1개판매 (개수가 여러개면 1개 줄이기)

	// HP 회복
	if ((My_Character.GetCurrentHP() + this->HP) > My_Character.GetMaxHP()) // HP회복했을때 MaxMP보다 클때
	{
		My_Character.SetCurrentHP(My_Character.GetMaxHP());
	}
	else	// HP회복했을때 Max보다 작을때
	{
		My_Character.SetCurrentHP(My_Character.GetCurrentHP() + this->HP);
	}

	// MP 회복
	if (My_Character.GetCurrentMP() + this->MP > My_Character.GetMaxMP()) // MP회복했을때 MaxMP보다 클때
	{
		My_Character.SetCurrentMP(My_Character.GetMaxMP());
	}
	else	// MP회복했을때 Max보다 작을때
	{
		My_Character.SetCurrentMP(My_Character.GetCurrentMP() + this->MP);
	}

}
void Potion::ShowInfo()
{
	if (this->GetName() == "빨간포션")
	{
		cout.width(15);
		cout << this->GetName();
		cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "HP +30";
	}
	else if (this->GetName() == "파란포션")
	{
		cout.width(15);
		cout << this->GetName();
		cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "MP +30";
	}
	else if (this->GetName() == "주황포션")
	{
		cout.width(15);
		cout << this->GetName();
		cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "MP +70";
	}
	else if (this->GetName() == "남색포션")
	{
		cout.width(15);
		cout << this->GetName();
		cout.width(8);
		cout << this->Count;
		cout.width(13);
		cout << "MP +80";
	}
}

int Potion::IsEquipment()
{
	return 0;
}