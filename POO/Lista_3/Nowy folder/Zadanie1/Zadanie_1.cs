public interface ICalculator
{
	int Add(int num1, int num2);
 
    int Subtraction(int num1, int num2);
 
    int Multiply(int num1, int num2);
 
    double Divide(int num1, int num2);
}

public class Calculator : ICalculator
{
	public int x;
	private int y;
	public string model = "v0.1";
	
	public int Add()
	{
		return x + y;
	}
	
	public int Subtraction()
	{
		return x - y;
	}
	
	public int Multuply()
	{
		return x * y;
	}
	
	public double Divide()
	{
		return x / y;
	}
	
	public void _PrintModel()
	{
		Console.WriteLine("Model kalkulatora: " + model);
	}
}

public class Calculator2 : Calculator
{
	public new string model = "v0.2";

	public int Add(int y)
	{
		return x + y;
	}
	
	public int Subtraction(int y)
	{
		return x - y;
	}
	
	public int Multuply(int y)
	{
		return x * y;
	}
	
	public double Divide(int y)
	{
		return x / y;
	}
}

public class Calculator3 : Calculator
{
	private new string model = "v0.3";

	public int Add(int x, int y)
	{
		return x + y;
	}
	
	public int Subtraction(int x, int y)
	{
		return x - y;
	}
	
	public int Multuply(int x, int y)
	{
		return x * y;
	}
	
	public double Divide(int x, int y)
	{
		return x / y;
	}
}

// Creator - Calculator jest odpowiedzialny za stworznie Calculator2
// High Cohesion - obiekty mają prosty cel oraz odpowiadają za jedną rzecz
// Protected Variations - klasy są spięte przez jeden interfejs
// Low Coupling - klasy powiązane są jednym interfejsem
// Indirection - między klasą Calculator 2 a Interfejsem jest klasa pośrednia Calculator
