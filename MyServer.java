import java.io.*; 
import java.net.*; 
public class MyServer { 
public static void main(String[] args){ 
try{ 
ServerSocket ss=new ServerSocket(6665); 
Socket s=ss.accept();//establishes connection 
DataInputStream dis=new DataInputStream(s.getInputStream()); 
String str=(String)dis.readUTF(); 
System.out.println("message= "+str); 
ss.close(); 
}catch(Exception e){System.out.println(e);} 
} 
} 





import java.io.*; 
import java.net.*; 
public class MyClient { 
public static void main(String[] args) { 
try{ 
Socket s=new Socket("localhost",6665); dout.writeUTF("Hello Student"); 
dout.flush(); 
dout.close(); 
s.close(); 
}catch(Exception e){System.out.println(e);} 
} 
}