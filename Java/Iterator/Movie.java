public class Movie
{
    private String name;
    private int date;

    Movie(String name, int date)
	{
		this.name = name;
		this.date = date;
	}
	
	public String getName()
	{
		return name;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public int getDate()
	{
		return date;
	}
	
	public void setDate(int date)
	{
		this.data = date;
	}

	public String toString()
	{
		return "NAME: " + name + "\n" + "DATE: " + date + "\n";
	}
}
