import java.util.ArrayList;

public class Database
{
	private PrimaryClass database = new ArrayList<PrimaryClass>;
	
	public void addPerson(int ID, String name, double salary)
	{
		PrimaryClass temp = new PrimaryClass(ID, name, salary);
		database.add(temp);
	}
	
	public PrimaryClass getList()
	{
		return database;
	}