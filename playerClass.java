public class Player
{
	private String player = "";
	private int score = 0;
	Hand playerHand;

	public String getPlayer()
	{
		return player;
	}

	public void setplayer(String newPlayer)
	{
		player = newPlayer;
	}

	public int getScore()
	{
		return score;
	}

	public void set(int newScore)
	{
		score = newScore;
	}


	public int getcards()
	{
		return cards;
	}

	public void set(int newCards)
	{
		cards = newCards
	}

}
