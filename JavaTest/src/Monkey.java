public class Monkey {
    public String _name;
    public String _feature;

    Monkey(){
        this._name = "长尾猴";
        this._feature = "尾巴长";
        System.out.println("我是无参构造产生的猴子：");

    }
    Monkey(String name,String feature){
        this._name = name;
        this._feature = feature;
        System.out.println("我是使用带参构造产生的猴子：");
    }

}
