public class Tricycle extends NonMotorVehicle{
    Tricycle()
    {
        super("","",3,1);
    }
    Tricycle(String brand, String color)
    {
        //调用父类的双参构造
        super(brand, color);
        //更改轮胎属性为3
        super._wheel = 3;
    }

    public void Display(){
        System.out.println("三轮车是一款有"+get_wheel()+"个轮子的非机动车");
    }

}
