'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the countSort function below.
function countSort(arr) {

arr.sort(function(a,b){
    return (parseInt(a[0])==parseInt(b[0]))*(parseInt(a[2])-parseInt(b[2]))+(parseInt(a[0])!=parseInt(b[0]))*(parseInt(a[0])-parseInt(b[0]))
    })

    answer(arr)
    
}

function answer(arr){
    let answer = ""
    for(let j=0;j<arr.length;j++) answer+=`${arr[j][1]} `
    console.log(answer)
}

function check(i,arr){

}

function main() {
    const n = parseInt(readLine());

    let arr = Array(n);

    for (let i = 0; i < n; i++) {
        arr[i] = readLine().split(' ');
        arr[i][2] = i
        if(i<arr.length/2) arr[i][1]="-"
    }
    // console.log(inputString)
    countSort(arr);
}
