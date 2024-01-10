// https://codeforces.com/problemset/problem/1916/A
fun main(){
    var t  = readLine()!!.toInt()
    while(t>0){
        var (n, k) = readLine()!!.split(" ").map{it.toInt()}
        var arr = readLine()!!.split(" ").map{it.toInt()}
        var flag = true
        var year = 2023
        for( i in 0..n-1){
            if(year%arr[i] !=0){
                flag = false
            }else{
                year = year/arr[i]
            }
        }
        if(flag){
            println("YES")
            for(i in 1..k-1){
                print("1 ")
            }
            print(year)
            println()
        }else{
            println("NO")
        }
        t--
    }
}