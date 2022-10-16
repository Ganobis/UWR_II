<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="Zad2.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label runat="server" ID="txtCookieUserName" />
        </div>
        <div>
           <asp:Button id="Button1" Text="Usuń ciastko" OnClick="SubmitBtn_Click" runat="server"/>
        </div>
    </form>
</body>
</html>
