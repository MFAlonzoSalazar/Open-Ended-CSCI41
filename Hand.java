public class Hand {
	private Card[] hand = new Card[26];
	private last = 0;
	//starting hand
	public Hand(Deck deck) {
		for (int i = 0; i < 26; i++) {
			if (i < 7) hand[i] = deck.draw();
			else hand[i] = new Card("", 0);
			last++;
		}
	}
	//print
	public void print() {
		System.out.println("You have:");
		int i = 0;
		while (hand[i].getRank() != 0 && i < last + 1) {
			hand[i].print();
			i++;
		}
	}
	//add a card
	public void push(Deck deck) {
		while (hand[i].getRank() != 0) {
			i++;
		}
		hand[i] = deck.draw();
		last++;
	}
	//search for a card
	public bool search(int x) {
		int i = 0;
		while (hand[i].getRank() != 0 && i < last + 1) {
			if (hand[i].getRank() == x) return true;
			else i++;
		}
		return false;
	}
	//remove a card
	public void pop(int x) {
		int i = 0;
		while (hand[i].getRank() != 0 && i < last + 1) {
			if (hand[i].getRank() == x) {
				hand[i] = hand[last];
				hand[last] = new Card("", 0)
				break;
			} else i++;
		}
	}
}
