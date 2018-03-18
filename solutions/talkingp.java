// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	    String linea  =bf.readLine();
	    int n = Integer.parseInt(linea);
	    while(n-->0) {
	    	linea = bf.readLine();
	    	linea = linea.replaceAll("u", "upu").replaceAll("a", "apa")
	    			.replaceAll("e", "epe").replaceAll("i", "ipi").replaceAll("o", "opo");
	    	System.out.println(linea);
	    }
	 
	}
}
