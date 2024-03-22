public class DemoClass<T, F>
{
	private T t;
	private F f;
	
	DemoClass(T type1, F type2)
	{
		this.t = type1;
		this.f = type2;
	}
	
	public void setT(T t)
	{
		this.t = t;
	}
	
	public void setF(F f)
	{
		this.f = f;
	}
	
	public T getT()
	{
		return t;
	}
	
	public F getF()
	{
		return f;
	}
}
	
