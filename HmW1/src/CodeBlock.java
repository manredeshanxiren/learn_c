public class CodeBlock {
    //创建外部类CodeBlock构造块(构造块)
    {
        System.out.println("CodeBlock构造块");
    }
    //创建外部类CodeBlock静态代码块(静态代码块)
    static {
        System.out.println("CodeBlock静态代码块");
    }
    public static void main(String[] args) {
        System.out.println("CodeBlock的主方法");


        System.out.println("产生Code类实例对象");
        Code C = new Code();

        System.out.println("产生CodeBlock类实例对象");
        CodeBlock CB = new CodeBlock();

    }
    //创建外部类CodeBlock构造方法(构造方法)
    public CodeBlock(){
        System.out.println("CodeBlock构造方法");
    }
}
