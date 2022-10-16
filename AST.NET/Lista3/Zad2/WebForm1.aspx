<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Zad2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form runat="server" id="Form1">
        <div>
            <asp:TextBox runat="server" ID="txtUserName" OnTextChanged="txtUserName_TextChanged"/>
        </div>
        <div>
            <asp:TextBox runat="server" ID="txtPassword" TextMode="Password"/>
        </div>
        <div>
            <button>Wyślij</button>
        </div>
        <div>
            <asp:Label runat="server" ID="lblMessage"/>
        </div>
    </form>
</body>
</html>
