<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="zad2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Strona Główna</title>
</head>
    <body>
		<asp:Label ID="label1" runat="server" />
		<form id="SignoutForm" runat="server">
			<asp:Button
			ID="button1"
			OnClick="Wyloguj"
			Text="Wyloguj"
			runat="server"/>
		</form>
    </body>
</html>
