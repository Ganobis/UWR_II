<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Zad1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <input type="text" name="p1" />
            <input type="submit" value="żądanie POST" onclick="return formGet();"/>
        </div>
    </form>
    <a href="WebForm2.aspx?p1=v1&p2=v2" onclick="return linkPost();">żądanie GET</a><br /><br />

    <script type="text/javascript">
        function linkPost() {
            var myForm = document.getElementById('form1');
            return myForm.submit();
        };

        function formGet() {
            document.location.href = "WebForm2.aspx?p1=v1&p2=v2";
            return false;
        }
    </script>
</body>
</html>

