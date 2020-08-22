'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(str => str.trim());

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the equalStacks function below.
 */
function equalStacks(n1,n2,n3,h1, h2, h3) {
    let sum1=h1.reduce(function(a, b){return a + b;}, 0)
    let sum2=h2.reduce(function(a, b){return a + b;}, 0)
    let sum3=h3.reduce(function(a, b){return a + b;}, 0)
    let z1=0
    let z2=0
    let z3=0
    while(sum1!=sum2 || sum2!=sum3 || sum3!=sum1){
            if(sum1>sum2 && sum1>sum3) sum1-=h1[z1++]
            else if(sum2>sum3) sum2-=h2[z2++];
            else sum3-=h3[z3++];
    }
    return (sum1+sum2+sum3)/3
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n1N2N3 = readLine().split(' ');

    const n1 = parseInt(n1N2N3[0], 10);

    const n2 = parseInt(n1N2N3[1], 10);

    const n3 = parseInt(n1N2N3[2], 10);

    const h1 = readLine().split(' ').map(h1Temp => parseInt(h1Temp, 10));

    const h2 = readLine().split(' ').map(h2Temp => parseInt(h2Temp, 10));

    const h3 = readLine().split(' ').map(h3Temp => parseInt(h3Temp, 10));

    let result = equalStacks(n1,n2,n3,h1, h2, h3);

    ws.write(result + "\n");

    ws.end();
}
