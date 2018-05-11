#include <iostream>
using namespace std;

const string s = "CDHS";
const string v = "A23456789TJQK";
const int handcards = 9;
const int drawCards = 3;

class card {
	private:
		char suit;
		char val;
	public:
		friend ostream& operator << (ostream& os,const card& card) {
			os << v[card.val] << s[card.suit];
		}
		bool valid() {
			return val > -1;
		}
		void set (char s, char v) {
			suit = s; val = v;
		}
		char get_Rank() {
			return v[val];
		}
		bool operator == (const char op) {
			return v[val] == op;
		}
		bool operator < (const card& cardd) {
			if (val == cardd.val) {
				return suit < cardd.suit;
			}
			else return val < cardd.val;
		}
};

