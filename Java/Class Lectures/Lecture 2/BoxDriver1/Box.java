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