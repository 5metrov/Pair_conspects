using System;

public class Test
{
	public static void Main()
	{
		/*double vklad = Convert.ToDouble(Console.ReadLine());
		if (vklad <= 0) Console.WriteLine("Ты куда отрицательные суммы вкладывать собрася? Переделывай");
	    else if (vklad < 100) vklad *= 1.05;
	    else if (vklad >= 100 && vklad < 200) vklad *= 1.07;
	    else if (vklad >= 200) vklad *= 1.10;
	    else Console.WriteLine("Неведомая ошибка. Переделывай");
		if (vklad > 0) Console.WriteLine($"Сумма вклада с начисленными процентами = {vklad}");*/
		
		/*
		int[] arr = new int[10];
		Random rn = new Random();
		for(int i = 0; i < 10; i++){
		    arr[i] = rn.Next(-7, 8);
		}
		Console.WriteLine("Массив создан и заполнен. Вот его содержание:");
		foreach(var i in arr){
		    Console.Write(i + " ");
		}
		int counter = 0;
		Console.WriteLine();
		Console.Write("Введите целочисленное число n для сравнения: ");
		int n = Convert.ToInt32(Console.ReadLine());
		foreach(var i in arr){
		    if (i < n) counter++;
		}
		Console.WriteLine($"Колличесво чисел в массиве меньше чем {n} - {counter}");
		*/
		
		Console.Write("Введите размерность двумерного массива: ");
		int n = Convert.ToInt32(Console.ReadLine());
		int m = Convert.ToInt32(Console.ReadLine());
		int[,] arrarr = new int [n,m];
		
		Random rn = new Random();
		Console.WriteLine($"Двумеррный массив с колличеством строк {n} и колличеством столбцов {m} создан.\nВот его содержимое");
		for(int i=0;i<n;i++){
		    for(int j=0;j<m;j++){
		        arrarr[i, j] = rn.Next(-3, 4);
		        Console.Write(arrarr[i, j] + " ");
		    }
		    Console.WriteLine();
		}
		
		int sum = 0;
		int counter = 0;
		int min = (n < m) ? n : m;
		for(int i = 0; i < min; i++){
		    sum += arrarr[i, i];
		    counter++;
		}
		double sa = Convert.ToDouble(sum) / Convert.ToDouble(counter);
		Console.WriteLine($"Текущее среднее арифмитическое главной диагонали: {sa}");
		
		
		for(int i=0;i<n;i++){
		    for(int j=0;j<m;j++){
		        arrarr[i, j] = Math.Abs(arrarr[i, j]);
		    }
		}
		Console.WriteLine("Весь двумерный массив был взят по модулю.");
		
		sum = 0;
		counter = 0;
		for(int i = 0; i < min; i++){
		    sum += arrarr[i, i];
		    counter++;
		}
		sa = Convert.ToDouble(sum) / Convert.ToDouble(counter);
		Console.WriteLine($"Текущее среднее арифмитическое главной диагонали: {sa}");
		
	}
}
