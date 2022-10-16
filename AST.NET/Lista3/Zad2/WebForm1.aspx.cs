using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zad2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(txtUserName.Text) && txtUserName.Text == txtPassword.Text)
            {
                var cookie = new HttpCookie("username");
                cookie.Value = txtUserName.Text;

                this.Response.SetCookie(cookie);

                this.Response.Redirect("/WebForm2.aspx");
            }
            else
            {
                this.lblMessage.Text = "Złe hasło lub nazwa użytkownika";
            }
        }
        protected void txtUserName_TextChanged(object sender, EventArgs e)
        {
            this.lblMessage.Text = "Pole tekstowe zmieniło się!";
        }
    }
}