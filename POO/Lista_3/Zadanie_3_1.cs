public class TaxCalculator 
{
	public Decimal _tax;
	
	public Decimal tax
	{
		get { return _tax; }
		set { _tax = value;}
	}
	
	public Decimal CalculateTax( Decimal Price ) { return Price * _tax }
}
public class Item {
	public Decimal Price 
	{ 
		get { return Price; }  
		set { Price = value;} 
	}
	public string Name 
	{ 
		get { return Name; } 
		set { Name = value;} 
	}

	public Item(Decimal price, string name)
	{
		this.Price = price;
		this.Name = name;
	}
}
public class CashRegister {
	public TaxCalculator taxCalc = new TaxCalculator();
	public Decimal CalculatePrice( Item[] Items ) {
		Decimal _price = 0;
		foreach ( Item item in Items ) {
			_price += itemPrice + taxCalc.CalculateTax( item.Price );
		}
		return _price;
	}
	public void PrintBill( Item[] Items ) {
		foreach ( var item in Items )
			Console.WriteLine( "towar {0} : cena {1} + podatek {2}",
				item.Name, item.Price, taxCalc.CalculateTax( item.Price ) );
	}
}
