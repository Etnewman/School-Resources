public class PrimaryClass implements Visitable
{
	private int id;
	
	PrimaryClass(int item)
	{
		this.id = item;
	}
	
	int getID()
	{
		return id;
	}
	
	public int accept(Visitor obj)
	{
		return obj.visit(this);
	}
}

