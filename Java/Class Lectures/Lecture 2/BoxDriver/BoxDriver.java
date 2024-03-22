class Box
{
  //attributes
  private double length; 
  private double width;
  private double height;
  
  
  //Methods
  
  //constructor
  Box(double boxWidth, double boxHeight, double boxLength)
  {
    height = boxHeight;
    length = boxLength;
    width = boxWidth;
    
  }
  
  public double volume()
  {
    double volume = length * width * height;
    
    return volume;
  }
  
  public double area()
  {
    double area = 2* length * width + 2 * width * height + 2 * length * height;
    
    return area;
  }
  
}



public class BoxDriver
{
  public static void main(String[]args)
  {
    
    Box box1 = new Box(2.5, 5.0, 6.0);
    
    System.out.println( "Area: "  + box1.area() + " volume: " + box1.volume() );
    
    
    
    // System.out.println( "length: " + box1.length + " height: " + box1.height +
    //                     "width:  " + box1.width )  ;

    
  }
}
