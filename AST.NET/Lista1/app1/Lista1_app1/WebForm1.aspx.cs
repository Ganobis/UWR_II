using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Lista1_app1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            int x = 0;
            while (true)
            {
                x++;
                Label2.Text = "Czas " + x;
                Thread.Sleep(1000);
            }
        }
    }
}