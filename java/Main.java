import java.io.*;
class Main{
  public static void main(String args[])throws IOException{
    if(args.length<2){
      System.out.println("Please Provide a Valid File");
      return;
    }
      String InputFile = args[0];
      String OutputFile = args[1];
      try{

    FileInputStream InputReader = new FileInputStream (InputFile);
    FileOutputStream OutputReader = new FileOutputStream(OutputFile);
    long FileSize = new File(InputFile).length();
    byte[] allbytes = new byte[(int)FileSize];
    InputReader.read(allbytes);
    OutputReader.write(allbytes);
    InputReader.close();
    OutputReader.close();
      }catch(Exception e ){
        System.out.println("Exceptoin Caught");
      }
}
}
