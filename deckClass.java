public class Deck {
    public static void main(String[] args) {
        String[] suits = {"Hearts", "Diamonds", "Spades", "Clubs"};
        String[] ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        int size = suits.length * ranks.length;
        int spot = 0;

        //initialize
        String[] deck =  new String[size];
        for(int i = 0; i < suits.length; i++){
            for(int j = 0;j < ranks.length; j++){
                deck[spot] = ranks[j] + " - " + suits[i];
                spot++;
            }
        }

        //print
        for (int i = 0; i < size; i++){
            System.out.println(deck[i]);
        }

        //shuffle (?)
        for(int i = 0; i < size; i++){
            int r = i + (int) (Math.random() * (size-i));
            String temp = deck[r];
            deck[r] = deck[i];
            deck[i] = temp;
        }
    }
}
