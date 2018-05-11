#include "deck.h"
using namespace std;

class player {

	protected:
		string nm;
		vector<card> hand;
		vector<char> books;
	public:
		player(string name) : nm(name) {
			for (int x = 0; x < handcards; x++)
				hand.push_back(deck::now()->draw_card());
			sort(hand.begin(), hand.end());
		}
		void outputHand() {
			for (vector<card>::iterator x = hand.begin(); x != hand.end(); x++)
				cout << (*x) << " ";
			cout << "\n";
		}
		bool addCard(card c) {
			hand.push_back(c);
			return checkForBook();
		}
		string name() {
			return nm;
		}
		bool holds(char c) {
			return (hand.end() != find(hand.begin(), hand.end(), c));
		}
		card takeCard(char c) {
			vector<card>::iterator it = find(hand.begin(), hand.end(), c);
			swap((*it), hand.back());
			card d = hand.back();
			hand.pop_back();
			hasCards();
			sort(hand.begin(), hand.end());
			return d;
		}
		size_t getBooksCount() {
			return books.size();
		}
		void listBooks() {
			for (vector<char>::iterator it = books.begin(); it != books.end(); it++)
				cout << (*it) << "'s ";
			cout << "\n";
		}
		bool checkForBook() {
			bool ret = false;
			map<char, int> countMap;
			for (vector<card>::iterator it = hand.begin(); it != hand.end(); it++)
				countMap[(*it).get_Rank()]++;
			for (map<char, int>::iterator it = countMap.begin(); it != countMap.end(); it++) {
				if ((*it).second == 4) {
					do {
						takeCard((*it).first);
					} while (holds((*it).first));
					books.push_back((*it).first);
					(*it).second = 0;
					ret = true;
				}
			}
			sort(hand.begin(), hand.end());
			return ret;
		}
		bool hasCards() {
			if (hand.size() < 1) {
				card c;
				for (int x = 0; x < drawCards; x++) {
					c = deck::now()->draw_card();
					if (c.valid()) addCard(c);
					else break;
				}
			}
			return (hand.size() > 0);
		}


};
