import java.io.*;
import java.net.URL;
public class Download
{
 public static void main(String[] args) throws Exception
 {
 try
 {
//String fileName = "Assessment_Schedule_ND19.pdf";
// String website = "https://coe1.annauniv.edu/aucoe/pdf/2019_nd"+fileName;
// String fileName = "Rainbow_Rose_%283366550029%29.jpg";
//String website = "https://upload.wikimedia.org/wikipedia/commons/6/61/"+fileName;
String fileName = "JPEG_example_JPG_RIP_100.jpg";
String website =
"https://upload.wikimedia.org/wikipedia/commons/b/b4/"+fileName;
System.out.println("Downloading File From: " + website);
URL url = new URL(website);
InputStream inputStream = url.openStream();
OutputStream outputStream = new FileOutputStream(fileName);
byte[] buffer = new byte[2048];
int length = 0;
while ((length = inputStream.read(buffer)) != -1) 
{
System.out.println("Buffer Read of length: " + length);
outputStream.write(buffer, 0, length);
}
inputStream.close();
outputStream.close();
 }
catch(Exception e)
{
System.out.println("Exception: " + e.getMessage());
}
 }
}
