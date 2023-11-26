public class UserManager {
    //equals方法
    public void equals(User Input, User Ori)
    {
        if(Input.get_UserName().equals(Ori.get_UserName()) && Input.get_Passwd().equals(Ori.get_Passwd()))
        {
            System.out.println("用户名和密码一致");
        }
        else
        {
            System.out.println("用户名或密码不一致");
        }
    }
}
