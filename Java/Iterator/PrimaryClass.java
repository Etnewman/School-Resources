public class PrimaryClass
{
	private int ID;
	private String name;
	private double salary;
	
	PrimaryClass(int ID, String name, double salary)
	{
		this.ID = ID;
		this.name = name;
		this.salary = salary;
	}
	
	public int getId() {
		return id;
	}
	
	public void setId(int ID) {
		this.ID = ID;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public double getSalary()
	{
		return salary;
	}
	
	public void setSalary(double salary)
	{
		this.salary = salary;
	}
	
	public String toString()
	{
		return "ID: " + ID + "\n" + "Name: " + name + "\n" + "Salary: " + salary + "\n";
	}
}	
	