#include "main.h"



extern Character My_Character;
extern int Battle_log_row;


void Inventory::BuyItem(Item* item,Unit* unit)
{

	int noOverlap = 1;

	if (slots.size() < MAX_INVENTORY_SIZE)
	{
		if (unit->GetGold() - item->GetPrice() < 0)	// ������ ���� ���� (���� ������) 
		{
			setcolor(BLACK, WHITE);					// ��� ��ġ����, ������
			gotoxy(48, 65); cout << "\"" << item->GetName() << "\" ��(��) ������ ���� �����մϴ�.";
			setcolor(WHITE, BLACK);
			cout << "        ";
		}
		else										// ������ ���� ���� (���� ����� ������)
		{
			if (item->IsEquipment() == 0)			// ������ �������� �Һ��� �϶���
			{
				for (int i = 0; i < slots.size(); i++)			// �κ��� �ߺ��� ������ ���� �ø���
				{
					if (item->GetName() == slots[i]->GetName())
					{
						slots[i]->SetCount(item->GetCount() + slots[i]->GetCount());
						noOverlap = 0;
						break;
					}
				}
			}

			if (noOverlap == 1)	// �κ��� �ߺ��� ������ ���� ������ �߰�
			{
				slots.push_back(item);
			}

			unit->SetGold(unit->GetGold() - item->GetPrice());	// ���������� ���� ������ 
		}
	}
	else	// �κ��ִ밳�� �ʰ���
	{
		setcolor(BLACK, WHITE);	// ��� ��ġ����, ������
		gotoxy(48, 65); cout << "   �κ��丮 ������ �����մϴ�   ";
		setcolor(WHITE, BLACK);
		cout << "                                         ";
	}
}
void Inventory::UseItem(int input)
{
	
	int index = input - 48 - 1;		// �ƽ�Ű�� -48, �ε����� -1

	if (slots.size() > index)
	{

		if (slots[index]->IsEquipment() == 0)	// Potion �϶�
		{
			slots[index]->UseItem();
			// Battle_log_row
			gotoxy(72, Battle_log_row += 2); cout << "�� ";
			setcolor(GREEN, BLACK);	cout << My_Character.GetName();
			setcolor(WHITE, BLACK); cout << "��(��) ";
			setcolor(PURPLE, BLACK); cout << slots[index]->GetName();
			setcolor(WHITE, BLACK);	 cout << "����߽��ϴ�.";
			// Battle_log_row
		}
		else if (slots[index]->IsEquipment() == 1)	// ��� �϶�
		{
			for (int i = 0; i < slots.size(); i++)
			{
				slots[i]->SetIsUse(0);	// ��� ��� -> ����
			}
			// Battle_log_row
			slots[index]->SetIsUse(1);	// �� ��� ����
			slots[index]->UseItem();
			gotoxy(72, Battle_log_row += 2); cout << "�� ";
			setcolor(GREEN, BLACK);	cout << My_Character.GetName();
			setcolor(WHITE, BLACK); cout << "��(��) ";
			setcolor(PURPLE, BLACK); cout << slots[index]->GetName();
			setcolor(WHITE, BLACK);	 cout << "�����߽��ϴ�.";
			// Battle_log_row
		}

		if (slots[index]->GetCount() <= 0)		// 0���Ǹ� �κ��丮���� ����� 
		{
			slots.erase(slots.begin() + index);
		}
	}
	
}
void Inventory::Sell_Items(int index)
{
	if(slots.size() > index)
	{
		if (slots[index]->GetIsUse() != 1) // ������� �ƴҶ��� �ȼ��ֵ���.
		{
			// 1���Ǹ� (������ �������� 1�� ���̱�)
			slots[index]->SetCount(slots[index]->GetCount() - 1);
			// �Ǹ� �� ���ޱ� 
			My_Character.SetGold(My_Character.GetGold() + (slots[index]->GetPrice() / 2));
			// 0���Ǹ� �κ��丮���� ����� 
			if (slots[index]->GetCount() <= 0)
			{
				slots.erase(slots.begin() + index);
			}
		}
	}

	//setcolor(BLACK, WHITE);	// ���� ����׿� // �׽�Ʈ
	//gotoxy(48, 60); cout << "�Ǹ��� index : " << index;
	//setcolor(WHITE, BLACK);
}
void Inventory::ShowInventory()
{
	int invenSize = (int)slots.size();
	cout.width(15);
	gotoxy(73, 4); cout << "������   "; cout<< "     ����    ȿ��";
	gotoxy(73, 5); cout << "-------------------------------------";
	for (int i = 0; i < invenSize; i++)
	{
		gotoxy(71, 6+i);	cout << i + 1 << ".";
		gotoxy(73, 6+i); slots[i]->ShowInfo();
	}
	
	gotoxy(73, 6 + invenSize); cout << "-------------------------------------";
}
void Inventory::ShowInventory_In_Store()
{
	Game game;
	game.Remove_Inventory_In_Store();

	int invenSize = (int)slots.size();
	cout.width(15);
	gotoxy(85, 38); cout << "������   "; cout << "     ����    ȿ��   ";
	gotoxy(85, 39); cout << "=====================================";
	for (int i = 0; i < invenSize; i++)
	{
		gotoxy(83, 40 + i);	cout << i+1 << ".";
		gotoxy(85, 40 + i); slots[i]->ShowInfo();
	}
	gotoxy(85, 40 + invenSize); cout << "-------------------------------------";

}
void Inventory::ShowInventory_In_Battle()
{
	Game game;
	game.Remove_Inventory_In_Store(); // print �� ��ġ �����

	setcolor(CYAN, BLACK);
	gotoxy(2, 36); 	cout <<"[1~9] �����ۻ��  ";
	gotoxy(2, 37);  cout << "[SPACE] �ǵ��ư���";
	setcolor(WHITE, BLACK);

	int invenSize = (int)slots.size();
	cout.width(15);
	gotoxy(15, 38); cout << "������   "; cout << "     ����    ȿ��   ";
	gotoxy(15, 39); cout << "=====================================";
	for (int i = 0; i < invenSize; i++)
	{
		gotoxy(13, 40 + i);	cout << i + 1 << ".";
		gotoxy(15, 40 + i); slots[i]->ShowInfo();
	}
	gotoxy(15, 40 + invenSize); cout << "-------------------------------------";

}