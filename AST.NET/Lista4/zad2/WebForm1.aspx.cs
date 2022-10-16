using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;

namespace zad2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        void Page_Load(object sender, EventArgs e)
        {
            label1.Text = "Jesteś zalogowany jako " + Context.User.Identity.Name;
        }
        protected void Wyloguj(object sender, EventArgs e)
        {
            FormsAuthentication.SignOut();
            Response.Redirect("WebFrom2.aspx");
        }
    }
}