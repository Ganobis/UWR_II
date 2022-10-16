using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;

namespace zad2
{
	public partial class WebForm3 : System.Web.UI.Page
	{
		protected void Page_Load(object sender, EventArgs e)
		{

		}
		protected void Rejestracja(object sender, EventArgs e)
		{
			try
			{
				Membership.CreateUser(_id.Text, _haslo.Text);
				FormsAuthentication.RedirectToLoginPage();
			}
			catch (MembershipCreateUserException exc)
			{
				_blad.Text = "Błąd: " + exc.Message;
			}
		}
	}
}