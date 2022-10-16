using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zad2
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        HttpCookie qr;
        protected void Page_Load(object sender, EventArgs e)
        {
            qr = new HttpCookie("MyCookie");
            qr = this.Request.Cookies["username"];
            if (qr != null)
            {
                this.txtCookieUserName.Text = "Twoja nazwa użytkownika na ciastku to:" + qr.Value;
            }
            else
            {
                this.txtCookieUserName.Text = "Nie ma ciastek do wyświetlenia";
            }
        }
        protected void SubmitBtn_Click(object sender, EventArgs e)
        {
            if (Request.Cookies["username"] != null)
            {
                Response.Cookies["username"].Expires = DateTime.Now.AddDays(-1);
                qr = null;
            }
        }
    }
}