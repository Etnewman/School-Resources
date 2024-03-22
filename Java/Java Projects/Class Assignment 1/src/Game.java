import java.io.Serializable;

public class Game implements Serializable {

	private static final long serialVersionUID = 1L;
	
	String name;
	String dateMade;
	String genre;
	double price;

	public Game(String name, String dateMade, String genre, double price)
	{
		this.name = name;
		this.dateMade = dateMade;
		this.genre = genre;
		this.price = price;
	}
}
