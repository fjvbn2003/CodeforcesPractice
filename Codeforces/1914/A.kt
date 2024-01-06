// https://codeforces.com/problemset/problem/1914/A
// date: 240106
import java.util.Collections
fun main(){
    var t = readLine()!!.toInt()
    while(t>0){
        var n = readLine()!!.toInt()
        var str = readLine()
        var arrayList = arrayListOf<Int>()
        for(i in 0..25)
            arrayList.add(0)

        for(c in str!!){
            var idx = c.toInt()-'A'.toInt()
            arrayList[idx]++
        }
        var ans: Int = 0
        for(i in 0..25){
            if(arrayList[i] > i){
                ans++
            }
        }
        println(ans)
        t--

    }
    return
}