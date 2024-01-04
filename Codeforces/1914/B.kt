//ttps://codeforces.com/problemset/problem/1914/B

/*
youngjukim@youngjukim-Dell-G15-5511:~/work/CodeforcesPractice/Codeforces/1914$ kotlinc B.kt -include-runtime -d B.jar
youngjukim@youngjukim-Dell-G15-5511:~/work/CodeforcesPractice/Codeforces/1914$ java -jar B.jar 
Hello, World!

$ alias runkt='f() { kotlinc $1.kt -include-runtime -d $1.jar && java -jar $1.jar; unset -f f; }; f'
 */


fun main() {
    println("Hello, World!")
  val (a, b) = readLine()!!.split(' ').map(String::toInt)
  println(a + b)
}


