#include "player.h"
class AI_Player : public player {
	private:
		vector<char> asked;
		char next_ask;
		char previous_ask;
		int askedIdx;

	public:
		AI_Player(string name) : player(name), askedIdx(-1), previous_ask(0),next_ask(-1) {}
		void remember_Card(char card) {
			if(asked.end()!= find(asked.begin(), asked.end(), card) || !asked.size()) {
				asked.push_back(card);
			}
		}
		char make_your_move() {
			if(askedIdx < 0 || askedIdx >= static_cast<int> (hand.size())){
				askedIdx = rand() % static_cast<int>(hand.size());
			}
			char c;
			if (next_ask > -1) {
				c = next_ask;
				next_ask = -1;
			}
			else {
				while (hand[askedIdx].get_Rank() == previous_ask){
					if( ++askedIdx == hand.size() ) {
						askedIdx = 0;
						break;
					}
				}
				c = hand[askedIdx].get_Rank();
				if( rand() % 100 > 25 && asked.size() ) {
					for( vector<char>::iterator it = asked.begin(); it != asked.end(); it++ ) {
						if( holds( *it ) ) {
							c = ( *it );
							break;
						}
					}
				}
			}
			previous_ask = c;
			return c;
		}
		void clearMemory( char c ) {
			vector<char>::iterator it = find( asked.begin(), asked.end(), c );
			if( asked.end() != it ) {
				swap( ( *it ), asked.back() );
				asked.pop_back();
			}
		}
		bool addCard( card c ) {
			if( !holds( c.get_Rank() ) )
				next_ask = c.get_Rank();
			return player::addCard( c );
		}
};
