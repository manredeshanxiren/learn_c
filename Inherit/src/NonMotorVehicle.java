public class NonMotorVehicle {
    public String _brand;
    public String _color;
    public int _wheel = 2;
    public int _seat = 1;

    //无参构造
    NonMotorVehicle()
    {}
    //双参构造
    NonMotorVehicle(String color, String brand)
    {
        _brand = brand;
        _color = color;
    }
    //四参构造
    NonMotorVehicle(String brand, String color, int wheel, int seat)
    {
        _brand = brand;
        _color = color;
        _wheel = wheel;
        _seat = seat;
    }

    public int get_seat() {
        return _seat;
    }

    public int get_wheel() {
        return _wheel;
    }

    public String get_brand() {
        return _brand;
    }

    public String get_color() {
        return _color;
    }

    public void Display(){
        System.out.println("这是一辆"+get_color()+"颜色的,"+get_brand()+"的非机动车,有"
                +get_wheel()+"个轮子,有"+get_seat()+"个座椅");
    }
}
