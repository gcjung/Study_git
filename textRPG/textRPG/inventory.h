#pragma once

#define MAX_INVENTORY_SIZE 21		// 인벤토리 화면 출력의 한계로,, 21로 지정 (최대 인벤토리 사이즈)

//=====================================================
// 인벤토리 클래스 
//=====================================================
class Inventory
{
private:
	vector<Item*> slots;
public:
	void BuyItem(Item* Item, Unit* unit);
	void UseItem(int index);
	void Sell_Items(int index);

	void ShowInventory();
	void ShowInventory_In_Store();
	void ShowInventory_In_Battle();
};