public class Printer{
	public void print(string x){
		Console.WriteLine(x);
	}
}
public class Report_Printer{
	private Printer printer;
	
	private void new_printer(){
		printer = new Printer();
	}
	
	public void PrintReport(string data){
		printer.print(data);
	}
}

public class Data_Getter{
	private string data;
	
	private void add_data(string x){
		data += x;
	}
	
	public string GetData(){
		return data;
	}
}

public class Document_Formatter{
	public void FormatDocument(string data){
		data = null;
	}
}