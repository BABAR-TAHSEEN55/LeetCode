
//class Addition{
//   public int add(int a , int b){
//        return  a +b;
//    }
//        public int add(int a , int b,int c){
//        return  a +b+c;
//    }
//        public double add(double a , double b){
//        return  a +b;
//    }
//}
//    public class Main{
//            public static void main(String args[]){
//        Addition result = new Addition();
//        System.out.println(result.add(2,3));        System.out.println(result.add(2,3,5));
//        System.out.println(result.add(2.9,3.3));
//
//    }
//    }
//
//
//class  Car {
//  public Car(){
//    System.out.println("class car");
//  }
//
//  public void VehicleType(){
//    System.out.println("VehicleType:  car");
//  }
//
//  public void Brand(){
//    System.out.println("brand:  car");
//  }
//}
//class Maruti extends Car{
//  public  Maruti(){
//    System.out.println("Class :Maurit");
//  }
//  public void  Brand(){
//    System.out.println("Brand : Maruti");
//
//  }
//  public void  Speed(){
//    System.out.println("SPeed : 80kmp");
//  }
//}
//public class Main{
//      public static void main(String args[]){
//    Maruti m = new Maruti();
//    m.Brand();
//    m.Speed();
//  }
//
//}


//class single {
//  double width , height , length;
//  single(double w , double h , double l){
//    width=w;
//    height=h;
//    length=l;
//  }
//  double Volume(){
//    return width*height*length;
//  }
//}
//class BoxWeight extends single{
//  double weight;
//  BoxWeight(double m, double h , double l ,double w){
//      super(h,l,w);
//weight = m;
//
//  }
//  double Volume (){
//    return width*length*height*weight;
//  }
//}
//class Main{
//  public static void main(String args[]){
//    single s = new single(1,2,3);
//    BoxWeight bx = new BoxWeight(23,23,23,23);
//    System.out.println(s.Volume());
//    System.out.println(bx.Volume());
//  }

//interface Drawable {
//  void Draw();// This should be void and not public(not a constructor)
//}
//class Rectange implements Drawable{
//  public void Draw(){
//    System.out.println("Drawing rectangle");
//  }
//}
//
//class Circle implements Drawable{
//  public void Draw(){
//    System.out.println("Drawing Cirlce");
//  }
//}
//class Main{
//  public static void main(String[] args) {
//    Rectange r = new Rectange();
//
//    Circle d = new Circle();
//   d.Draw();
//    r.Draw();
//  }
//}



