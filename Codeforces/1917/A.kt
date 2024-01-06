// https://codeforces.com/problemset/problem/1917/A
// 240107
fun main(){
    var t  = readLine()!!.toInt()
    while(t>0){
        var n = readLine()!!.toInt()
        var arr = readLine()!!.split(" ").map{it.toInt()}
        var num_minus = 0
        var num_zeros = 0
        for(i in 0..n-1){
            if(arr[i] <0){
                num_minus++
            }
            if(arr[i] == 0){
                num_zeros++
            }
        }
        if(num_minus%2 ==1 ||  num_zeros>0){
            println(0)
        }else{
            println(1)
            println("1 0")
        }
        t--
    }
}