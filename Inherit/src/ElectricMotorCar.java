public class ElectricMotorCar extends NonMotorVehicle{

    private String _Battery;
    ElectricMotorCar()
    {}


    ElectricMotorCar(String Battery ,String color, String brand){
        //调用父类的双参构造
        super(color, brand);
        //并且初始化电动车的额外参数电池的品牌
        _Battery = Battery;
    }

    public String get_Battery() {
        return _Battery;
    }

    public void Display(){
        System.out.println("这是一辆使用"+get_Battery()+"牌电池的电动车");
    }

}
