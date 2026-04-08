#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
// 表示單張撲克牌的類別
class Card {
public:
string colors; //儲存撲克牌的花色
string rank; //儲存撲克牌的數值
Card(string s, string r) : colors(s), rank(r) {} //建立 constructor來初始化物件,當 Card 物件建立時,它會自動執行這個函式,並把 s 和 r 的值存入colors 和 rank
void display() const { //顯示撲克牌的資訊
cout << rank << " of " << colors << endl;
}
};

// 實作 Stack
class Stack {
private:
vector<Card> stack; //表示 stack 是一個能存放 Card 類別物件的 vector

public:
void push(const Card& card) {
stack.push_back(card); //將 card 加入 stack 的末尾
}
Card pop() {
if (!stack.empty()) { //檢查 stack 是否為空
Card card = stack.back();  //
stack.pop_back();
return card;
}
throw invalid_argument("Stack is empty");
}
bool isEmpty() const {
return stack.empty();
}
};

// 代表一副撲克牌的類別
class Deck {
private:
vector<Card> cards; // 存放未洗牌的撲克牌
Stack shuffledDeck; // 存放洗過的牌,用實作的 stack 來管理
public:
Deck() { //建立 constructor 來初始化物件
string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
//儲存撲克牌的花色
string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9",
"10", "J", "Q", "K", "A" }; //儲存撲克牌的數值
//利用迴圈將 52 張牌加入 cards 這個 vector 裡面
for (int i = 0; i < 4; i++) { // 四種花色
for (int j = 0; j < 13; j++) { // 13 種點數
cards.push_back(Card(colors[i], ranks[j]));
}
}
}
//洗牌(Hint:使用 shuffle 函數)
void shuffleDeck() {
        random_device rd;
        mt19937 g(rd());
        shuffle(cards.begin(), cards.end(), g);

        for (int i = 0; i < cards.size(); i++) {
            shuffledDeck.push(cards[i]);
        }
}
//發牌
void drawAllCards() {
    while (!shuffledDeck.isEmpty()) { //判斷 shuffledDeck 是否還有值,如果不是空的就重複執行迴圈
    Card card = shuffledDeck.pop(); //從 shuffledDeck 中取出一張牌
        card.display(); //顯示這張牌的資訊
    }
}
};

int main() {
    Deck deck; //建立 deck 產生 52 張撲克牌
    deck.shuffleDeck(); //進行洗牌並放入堆疊
    cout << "Shuffled deck:" << endl;
    deck.drawAllCards(); //依序取出堆疊內的牌並顯示
    return 0;
}