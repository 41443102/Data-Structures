#include<iostream>
#include<string>
using namespace std;
class GameCharacter
{
public:
    string name;
    int hp, level;
    GameCharacter(string n, int h, int l) //建構子
    {
        name = n;
        hp = h;
        level = l;
    }
    void damage(int value) //扣血
    {
        hp = hp - value;
        if (hp < 0)
        {
            hp = 0;
        }
    }
    void heal(int value) //回血
    {
        hp = hp + value;
        if (hp > 100)
        {
            hp = 100;
        }
    }
    void levelUp() //升級
    {
        level = level + 1;
        hp = 100;
    }
    void show() //顯示角色資料
    {
        cout << "名稱: " << name << endl;
        cout << "血量: " << hp << endl;
        cout << "等級: " << level << endl;
    }
};
int main()
{
    string name;
    int hp, level, choice, value;
    cout << "請輸入角色資料" << endl;
    cout << "血量: ";
    cin >> hp;
    cout << "名稱: ";
    cin >> name;
    cout << "等級: ";
    cin >> level;
    GameCharacter p(name, hp, level); 
    cout << endl;
    //選單
    do
    {
        cout << endl;
        cout << "========== 選單 ==========" << endl;
        cout << "1. 扣血" << endl;
        cout << "2. 回血" << endl;
        cout << "3. 升級" << endl;
        cout << "4. Show角色資料" << endl;
        cout << "0. 結束程式" << endl;
        cout << "請選擇: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "請輸入扣血數值: ";
            cin >> value;

            if (value < 0)
            {
                cout << "扣血數值不能小於0" << endl;
            }
            else
            {
                p.damage(value);
                cout << "扣血完成" << endl;
                p.show();
            }
            break;

        case 2:
            cout << "請輸入回血數值: ";
            cin >> value;

            if (value < 0)
            {
                cout << "回血數值不能小於0" << endl;
            }
            else
            {
                p.heal(value);
                cout << "回血完成" << endl;
                p.show();
            }
            break;

        case 3:
            p.levelUp();
            cout << "升級完成" << endl;
            p.show();
            break;

        case 4:
            cout << endl;
            cout << "角色資料" << endl;
            p.show();
            break;

        default:
            cout << "選擇錯誤，請重新輸入" << endl;
        }
    } while (choice != 0); //choice不是0就繼續執行
    cout << "程式已結束" << endl;
    return 0;
}
