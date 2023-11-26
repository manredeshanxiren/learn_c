import java.util.Arrays;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        //创建UserManager对象
        UserManager UM = new UserManager();

        //创建一个临时对象存储用户输入的User对象信息
        User In = new User();

        User u1 = new User("Mike", "123456");
        User u2 = new User("Lucy", "123456");
        u1.Display();
        u2.Display();

        System.out.println("===========================");


        UM.equals(u2,u1);
    }
}
