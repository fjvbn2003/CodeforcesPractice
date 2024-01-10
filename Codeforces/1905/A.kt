// https://codeforces.com/contest/1905/problem/A


fun main(){
    var t = readLine()!!.toInt()
    while(t>0){
        var (n, m) = readLine()!!.split(" ").map{it.toInt()}
        println(if(n>m) n else m)
        t--
    }

}