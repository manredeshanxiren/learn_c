public class ElectricMotorCar extends NonMotorVehicle{
    ElectricMotorCar()
    {}

    ElectricMotorCar(String brand, String color){
        super(brand, color);
    }

    public void Display(){
        System.out.println("这是一辆使用"+get_brand()+"牌电池的电动车");
    }

}
