/*import java.security.*;
import java.util.*;
import java.math.*;*/
import java.util.*;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MerkleRoot {

    public static byte[] getSHA(String input) throws NoSuchAlgorithmException
       {
           // Static getInstance method is called with hashing SHA
           MessageDigest md = MessageDigest.getInstance("SHA-256");

           // digest() method called
           // to calculate message digest of an input
           // and return array of byte
           return md.digest(input.getBytes(StandardCharsets.UTF_8));
       }

       public static String toHexString(byte[] hash)
       {
           // Convert byte array into signum representation
           BigInteger number = new BigInteger(1, hash);

           // Convert message digest into hex value
           StringBuilder hexString = new StringBuilder(number.toString(16));

           // Pad with leading zeros
           while (hexString.length() < 32)
           {
               hexString.insert(0, '0');
           }

           return hexString.toString();
       }
    public static void main(String args[]){
        String[] input = {"33","23","55","27","65","78","95","88","4","99"};
        try
           {
	        	System.out.println("\nCalculating Hash of T1");
	            String H1 = toHexString(getSHA(input[0]));
	            System.out.println(input[0] + " : " + H1 + "\n");
	
	            System.out.println("\nCalculating Hash of T2");
	            String H2 = toHexString(getSHA(input[1]));
	            System.out.println(input[1] + " : " + H2 + "\n");
	            
	            System.out.println("\nCalculating Hash of T3");
	            String H3 = toHexString(getSHA(input[2]));
	            System.out.println(input[2] + " : " + H3 + "\n");
	
	            System.out.println("\nCalculating Hash of T4");
	            String H4 = toHexString(getSHA(input[3]));
	            System.out.println(input[3] + " : " + H4 + "\n");
	            
	            
	            
	            System.out.println("\nCalculating Hash of T5");
	            String H5 = toHexString(getSHA(input[4]));
	            System.out.println(input[4] + " : " + H5 + "\n");
	
	            System.out.println("\nCalculating Hash of T6");
	            String H6 = toHexString(getSHA(input[5]));
	            System.out.println(input[5] + " : " + H6 + "\n");
	            
	            System.out.println("\nCalculating Hash of T7");
	            String H7 = toHexString(getSHA(input[6]));
	            System.out.println(input[6] + " : " + H7 + "\n");
	
	            System.out.println("\nCalculating Hash of T8");
	            String H8 = toHexString(getSHA(input[7]));
	            System.out.println(input[7] + " : " + H8 + "\n");
	            
	            
	            System.out.println("\nCalculating Hash of T9");
	            String H9 = toHexString(getSHA(input[8]));
	            System.out.println(input[8] + " : " + H9 + "\n");
	
	            System.out.println("\nCalculating Hash of T10");
	            String H10 = toHexString(getSHA(input[1]));
	            System.out.println(input[9] + " : " + H10 + "\n");
	            
	            
	            System.out.println("\nCalculating Hash of H1,2");
	            String H12 = toHexString(getSHA(H1+H2));
	            System.out.println("H1,2" + " : " + H12 + "\n");
	
	            System.out.println("\nCalculating Hash of H3,4");
	            String H34 = toHexString(getSHA(H3+H4));
	            System.out.println("H3,4" + " : " + H34 + "\n");
	            
	            
	           
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	            
	                                       // TO DO: Calculate the Merkle Root
	            
	            
	           
	            
	            
	            
	            
        	
        	
        	
        	
               
               
               

           }
           // For specifying wrong message digest algorithms
           catch (NoSuchAlgorithmException e) {
               System.out.println("Exception thrown for incorrect algorithm: " + e);
           }
       }
}
