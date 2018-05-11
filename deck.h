#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "card.h"

using namespace std;

class deck {
	private:
	
		vector<card>cards;
		static deck* pointerr;
		
		deck() {
			new_deck();
		}
		void new_deck() {
			card card_1;
			for (char s = 0; s < 4; s++) {
				for (char v = 0; v < 13; v++) {
					card_1.set(s,v);
					cards.push_back(card_1);
				}
			}
			random_shuffle(cards.begin(),cards.end());
		}
	public:
		static deck* now() {
			if(!pointerr) pointerr = new deck();
			return pointerr;
		}
		void destruction() {
			delete pointerr;
			pointerr = 0;
		}
		card draw_card() {
			card card;
			if(cards.size() > 0) {
				card = cards.back();
				cards.pop_back();
				return card;
			}
			card.set(-1,-1);
			return card;
		}
	};


