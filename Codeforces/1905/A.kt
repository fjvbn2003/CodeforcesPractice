// https://codeforces.com/contest/1905/problem/A

fun main() {
    var t = readLine()!!.toInt()
    while (t > 0) {
        var (n, m) = readLine()!!.split(" ").map { it.toInt() }
        println(if (n > m) n else m)
        t--

        // Define a 2D array of integers with 3 rows and 4 columns
        val twoDArray = Array(3) { IntArray(4) }

        // Initialize the array with values
        for (i in twoDArray.indices) {
            for (j in twoDArray[i].indices) {
                twoDArray[i][j] = i + j // Just an example; you can initialize it as needed
            }
        }

        for (i in twoDArray.indices) {
            for (j in twoDArray[i].indices) {
                print("${twoDArray[i][j]} ")
            }
            println()
        }
    }
}
