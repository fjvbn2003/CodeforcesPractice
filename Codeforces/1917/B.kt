fun main(){
    var t = readLine()!!.toInt()
    while(t>0){
        var n = readLine()!!.toInt()
        var str = readLine()
        var arrayList = arrayListOf<Int>()
        for(i in 1..26){
            arrayList.add(-1)
        }
        for(idx in 0..(n-1)){
            var ch : Char = str!![idx]
            if(arrayList[(ch.toInt()-'a'.toInt())] == -1){
                arrayList[(ch.toInt()-'a'.toInt())] = idx
            }
        }
        var ans = 0
        for(i in 0..25){
            // print("${arrayList[i]} ")
            if(arrayList[i] != -1)
                ans += (n-arrayList[i])
        }
        println(ans)
        t--
    }
}