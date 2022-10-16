<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm3.aspx.cs" Inherits="zad2.WebForm3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
	<body>
		<form id="form1" runat="server">
			Rejestracja
			<br/>
				ID:
				<asp:TextBox ID="_id" runat="server" />
				<asp:RequiredFieldValidator ID="_id_required" 
					ControlToValidate="_id"
					ErrorMessage="Musić wpisać jakąś wartość" 
					runat="server"
				/>
			<br/>
				Hasło:
				<asp:TextBox ID="_haslo" TextMode="Password" runat="server" />
				<asp:RequiredFieldValidator ID="haslo_required" 
					ControlToValidate="_haslo"
					ErrorMessage="Musić wpisać jakąś wartość" 
					runat="server"
				/>
			<br/>
				<asp:Button ID="_rejestracja" OnClick="Rejestracja" Text="Rejestracja" runat="server" />
			<br/>
				<asp:Label ID="_blad" ForeColor="red" runat="server" />
		</form>
	</body>
</html>
