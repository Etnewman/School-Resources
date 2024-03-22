import matrix.MatrixCreator;
import matrix.MatrixOperationsInterface;



public class MatrixDriver {

	public static void main(String[] args) {

		//MatrixOperationsInterface is static, so I don't need to create an obj.
		
		MatrixOperationsInterface A = MatrixCreator.create(3,3);
		A.setElement(1,1,1.6);
		A.setElement(1,2,2.4);
		A.setElement(1,3,-3.7);
		A.setElement(2,1,17.6);
		A.setElement(2,2,-5.6);
		A.setElement(2,3,0.05);
		A.setElement(3,1,-2.0);
		A.setElement(3,2,2.0);
		A.setElement(3,3,25.3);
		
		MatrixOperationsInterface B = MatrixCreator.create(1, 3);
		B.setElement(1, 1, -22.10);
		B.setElement(1, 2, -4.35);
		B.setElement(1, 3, 233.70);
		
		MatrixOperationsInterface Ainv = A.inverse();
		MatrixOperationsInterface x = Ainv.multiply(B);
		
		System.out.println(x);	
	}
}
