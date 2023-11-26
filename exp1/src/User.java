public class User {
    //用户名
    private String _UserName;
    //密码
    private String _Passwd;

    //无参构造函数
    public User()
    {}

    //双参构造
    public User(String UserName, String Passwd)
    {
        _UserName = UserName;
        _Passwd = Passwd;
    }

    //打印函数
    public void Display()
    {
        System.out.println("用户名：" + _UserName);
        System.out.println("密码：" + _Passwd);
    }
    public String get_Passwd() {
        return _Passwd;
    }

    public String get_UserName() {
        return _UserName;
    }

    public void set_UserName(String _UserName) {
        this._UserName = _UserName;
    }

    public void set_Passwd(String _Passwd) {
        this._Passwd = _Passwd;
    }
}
