public class Tricycle extends NonMotorVehicle{
    Tricycle()
    {
        super("","",3,1);
    }
    Tricycle(String brand, String color)
    {
        super(brand, color);
    }

    public void Display(){
        System.out.println("三轮车是一款有"+get_wheel()+"个轮子的非机动车");
    }

}
