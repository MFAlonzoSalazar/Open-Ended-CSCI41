#include "AI.h"

class goFish {
	private:

		player *player1;
		AI_Player *player2;
		bool plr;

		void showBooks() {
			if( player1->getBooksCount() > 0 ) {
				cout << "\nYour Book(s): ";
				player1->listBooks();
			}
			if( player2->getBooksCount() > 0 ) {
				cout << "\nMy Book(s): ";
				player2->listBooks();
			}
		}
		void showPlayerCards() {
			cout << "\n\n" << player1->name() << ", these are your cards:\n";
			player1->outputHand();
			showBooks();
		}
		char getInput() {
			char c;
			if( plr ) {
				if( !player1->hasCards() ) return -1;
				showPlayerCards();
				string w;
				while( true ) {
					cout << "\nWhat card(rank) do you want? "; std::cin >> w;
					c = toupper( w[0] );
					if( player1->holds( c ) ) break; 
					cout << player1->name() << ", you can't ask for a card you don't have!\n\n"; 
				}
			} else {
				if( !player2->hasCards() ) return -1;
				c = player2->make_your_move();
				showPlayerCards();
				string r;
				cout << "\nDo you have any " << c << "'s? (Y)es / (G)o Fish ";
				do {
					getline( std::cin, r );
					r = toupper( r[0] );
				}
				while( r[0] != 'Y' && r[0] != 'G' );
				bool hasIt = player1->holds( c );
				if( hasIt && r[0] == 'G' )
					cout << "Are you trying to cheat me?! I know you do...\n";
				if( !hasIt && r[0] == 'Y' )
					cout << "Nooooo, you don't have it!!!\n";
			}
			return c;
		}
		bool process( char c ) {
			if( c < 0 ) return true;
			if( plr ) player2->remember_Card( c );

			player *a, *b;
			a = plr ? player2 : player1;
			b = plr ? player1 : player2;
			bool r;
			if( a->holds( c ) ) {
				while( a->holds( c ) ) {
					r = b->addCard( a->takeCard( c ) );
				}
				if( plr && r )player2->clearMemory( c );
			} else {
				fish();
				plr = !plr;
			}
			return false;
		}
		void fish() {
			cout << "\n\n\t  *** GO FISH! ***\n\n";
			card c = deck::now()->draw_card();
			if( plr ) {
				cout << "Your new card: " << c << ".\n\n******** Your turn is over! ********\n" << std::string( 36, '-' ) << "\n\n";
				if( player1->addCard( c ) ) player2->clearMemory( c.get_Rank() );
			} else {
				cout << "\n********* My turn is over! *********\n" << string( 36, '-' ) << "\n\n";
				player2->addCard( c );
			}
		}
	public:
		goFish() {
			plr = true; 
			string n; 
			cout << "Hi there, enter your name: "; cin >> n; 
			player1 = new player( n ); 
			player2 = new AI_Player( "JJ" );
		}
		~goFish() { 
			if( player1 ) delete player1; 
			if( player2 ) delete player2;
			deck::now()->destruction();
		}
		void play() {
			while( true ) {
				if( process( getInput() ) ) break;
			}
			cout << "\n\n";
			showBooks();
			if( player1->getBooksCount() > player2->getBooksCount() ) {
				cout << "\n\n\t*** !!! CONGRATULATIONS !!! ***\n\n\n";
			} else {
				cout << "\n\n\t*** !!! YOU LOSE - HA HA HA !!! ***\n\n\n";
			}
		}
};


