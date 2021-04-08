public class Printer{
	public void print(string x){
		Console.WriteLine(x);
	}
}
public class ReportPrinter{
	private string data;
	private Printer printer;
	
	private void add_data(string x){
		data += x;
	}
	private void new_printer(){
		printer = new Printer();
	}
	
	public string GetData(){
		return data;
	}
	public void FormatDocument(string data){
		data = null;
	}
	public void PrintReport(string data){
		printer.print(data);
	}
}