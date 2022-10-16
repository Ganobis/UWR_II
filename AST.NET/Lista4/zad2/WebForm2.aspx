<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="zad2.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Strona Logowania</title>
</head>
    <body>
		<form id="LoginForm" runat="server">
			Logowanie
			<br/>
				ID:
				<asp:TextBox ID="_id" runat="server" />
				<asp:RequiredFieldValidator ID="_id_requirer" 
					ControlToValidate="_id"
					ErrorMessage="Nie może być puste" 
					runat="server"
				/>
			<br/>	
				Hasło:
				<asp:TextBox ID="_haslo" TextMode="Password" runat="server" />
				<asp:RequiredFieldValidator ID="_haslo_requirer" 
					ControlToValidate="_haslo"
					ErrorMessage="Nie może być puste" 
					runat="server"
				/>
			<br/>
				Zapamiętać użytwnika?
				<asp:CheckBox ID="_zap" runat="server" />
			<br/>
				<asp:Button ID="_zaloguj" OnClick="Zaloguj" Text="Zaloguj" runat="server" />
			<br/>
				<asp:Label ID="_blad" ForeColor="red" runat="server" />
		</form>
    </body>
</html>
