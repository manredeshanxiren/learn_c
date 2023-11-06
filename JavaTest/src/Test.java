public class Test {
    public static void main(String[] args) {
        Monkey m1 = new Monkey();
        System.out.println("名称："+m1._name);
        System.out.println("特征："+m1._feature);
        System.out.println("==========================");
        Monkey m2 = new Monkey("白头叶猴" , "头上有白毛，喜欢吃树叶");
        System.out.println("名称："+m2._name);
        System.out.println("特征："+m2._feature);
    }
}
