using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;

namespace zad2
{
    public partial class WebForm2 : System.Web.UI.Page
    {
		protected void Page_Load(object sender, EventArgs e)
		{

		}
		protected void Zaloguj(object sender, EventArgs e)
		{
			if (Membership.ValidateUser(_id.Text, _haslo.Text))
			{
				FormsAuthentication.RedirectFromLoginPage(_id.Text, _zap.Checked);
			}
			else
			{
				_blad.Text = "Błąd przy logowaniu.";
			}
		}
	}
}