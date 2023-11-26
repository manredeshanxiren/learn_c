public class Bike extends NonMotorVehicle {
    //无参构造
    Bike()
    {}
    Bike(String color, String Brand)
    {
        //调用父类的双参构造
        super(color, Brand);
    }

    public  void Display(){
        System.out.println("这是一辆"+get_color()+"颜色的,"+get_brand()+"的自行车");
    }

}
