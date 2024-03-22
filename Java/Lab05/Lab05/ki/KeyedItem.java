//place this file in the ki subdirectory
package ki;

public abstract class KeyedItem
{
	//create private instance variable of type Comparable
	private Comparable key;
  
   public KeyedItem(Comparable key) 
   {
	   this.key = key;
	   
   }  

   public Comparable getKey() 
   {
	   return key;
	   
   }  

   //Use Comparable's toString() method
   public String toString()
   {
	   return key.toString();
	   
   }
}