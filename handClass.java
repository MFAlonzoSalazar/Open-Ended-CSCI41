public class Hand {
    String[] hand = new String[25];

    //initialize
    void init(){
        for(int i = 0; i < 25; i++){
            hand[i] = "0";
        }
    }
    
    //starting hand
    void new_hand(){
        for(int i = 0; i < 7; i++){
            int j = 0;
            while(true){
                if(deck[j] != "0"){
                    hand[i] = deck[j];
                    deck[j] = "0";
                    break;
                }
                else{
                    j++;
                }
            }
        }

    }

    //print
    void printHand(){
        System.out.println("You have:");
        for (int i = 0; i < 7; i++) {
            if (hand[i] != "0") {
                System.out.print(hand[i] + " | ");
            }
        }
    }

    //draw a card *Add the initial hand sizes' total to i to save time
    
    void fish(){
        int i = 13;
        while(true){
            if (deck[i] != "0") {
                int j = 0;
                while(true){
                    if(hand[j] == "0"){
                        hand[j] = deck[i];
                        break;
                    }
                    else{
                        j++;
                    }
                }
                deck[i] = "0";
                break;
            } else {
                i++;
            }
        }
    }

}
