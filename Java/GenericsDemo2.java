

//A Simple Java program to show multiple 
//type parameters in Java Generics 

//We use < > to specify Parameter type 
class Test1<T, U> 
{ 
	T obj1; // An object of type T 
	U obj2; // An object of type U 

	// constructor 
	Test1(T obj1, U obj2) 
	{ 
		this.obj1 = obj1; 
		this.obj2 = obj2; 
	} 

	// To print objects of T and U 
	public void print() 
	{ 
		System.out.println(obj1); 
		System.out.println(obj2); 
	} 
} 

//Driver class to test above 
public class GenericsDemo2 
{ 
	public static void main (String[] args) 
	{ 
		Test1 <String, Integer> obj = 
			new Test1<String, Integer>("CSC 2310 demo 2", 15); 

		obj.print(); 
	} 
}
