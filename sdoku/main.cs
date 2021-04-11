using System;
using static System.Console;
public class Sdoku{
    public int [,] arr;
    public  Sdoku(){
         arr = new int[9,9]{
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
        };
    }
    public void show(){
        for(int i=0; i<arr.GetLength(0); i++){
            for(int j=0; j<arr.GetLength(1); j++){
                Write(arr[i,j]);
                Write(" ");
            }
            WriteLine();
        }
    }
}


public class Program{
    
        
    public static void Main(){
        Sdoku s = new Sdoku();
        s.show();
        
    }

}