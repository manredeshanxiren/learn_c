public class Main {
    public static void main(String[] args) {
        System.out.print("父类信息测试:");
        NonMotorVehicle Nv = new NonMotorVehicle("天宇牌", "红", 4, 2);
        Nv.Display();

        System.out.print("自行车信息测试:");
        Bike B = new Bike("黄", "捷安特");
        B.Display();

        System.out.print("电动车信息测试:");
        ElectricMotorCar ec = new ElectricMotorCar("飞鸽","飞鸽","蓝色");
        ec.Display();

        System.out.print("三轮车信息测试:");
        Tricycle tc = new Tricycle();
        tc.Display();
    }
}