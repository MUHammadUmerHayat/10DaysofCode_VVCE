function processData(input) {
    num=1
    for(let z=0;z<input.length;z++){
        if(checkNum(input[z])) num++
        else break
    }
    queue = []
    for(let i=num;i<input.length;i++){
        if(parseInt(input[i])==1){
            oldi=i
            value=""
            for(let x=2;x<input.length;x++){
                if(checkNum(input[i+x])===true){
                    value+= `${input[i+x]}`
                } 
                else {
                    i+=x
                    break
                }
            }
            queue.push(parseInt(`${value}`))
        }
        else if(parseInt(input[i])===2){
            queue.shift()
            i++
        } 
        else if(parseInt(input[i])===3){
            if(queue[0]) console.log(queue[0])
            else console.log("")
            i++
        }
    }   
} 

function checkNum(value){
    return Number.isInteger(parseInt(value))
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
