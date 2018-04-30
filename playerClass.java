public class Player
{
	private String player = "";
	private int score = 0;
	private int[] cards = new int[7];

	public final String getPlayer()
	{
		return player;
	}

	public final void setplayer(String newPlayer)
	{
		player = newPlayer;
	}

	public final int getScore()
	{
		return score;
	}

	public final void set(int newScore)
	{
		score = newScore;
	}


	public final int getcards()
	{
		return cards;
	}

	public final void set(int newCards)
	{
		cards = newCards
	}

}
