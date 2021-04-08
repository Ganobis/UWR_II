public class Printer{
	public void print(string x){
		Console.WriteLine(x);
	}
}

public abstract class ReportComposer{
	public IData_Getter _dataGetter;
	public IReport_Printer _reportPrinter;
	public IDocument_Formatter _documentFormatter;
	
	public ReportComposer(IData_Getter dataGetter, IReport_Printer reportPrinter, IDocument_Formatter documentFormatter)
    {
      _dataGetter = dataGetter;
      _reportPrinter = reportPrinter;
      _documentFormatter = documentFormatter;
    }

    public void ComposeReport()
    {
      string data = _documentFormatter.FormatDocument(_dataGetter.GetData());
      _reportPrinter.PrintReport(data);
    }
}

public interface IReport_Printer
{
	public void PrintReport(string data);
}

public interface IData_Getter
{
	public string GetData();
}

public interface IDocument_Formatter
{
	public string FormatDocument(string data);
}

public class Report_Printer : IReport_Printer{
	private Printer printer;
	
	private void new_printer(){
		printer = new Printer();
	}
	
	public void PrintReport(string data){
		printer.print(data);
	}
}

public class Data_Getter : IData_Getter{
	private string data;
	
	private void add_data(string x){
		data += x;
	}
	
	public string GetData(){
		return data;
	}
}

public class Document_Formatter : IDocument_Formatter{
	public string FormatDocument(string data){
		return data = null;
	}
}