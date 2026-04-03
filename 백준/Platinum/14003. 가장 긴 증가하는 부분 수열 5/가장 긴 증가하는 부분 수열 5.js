const fs = require('fs');
const input = fs.readFileSync(0, 'utf-8').trim().split('\n');

function solve() {
    const N = +input[0];
    const A = input[1].split(' ').map(Number);
    const parent = Array.from({length: N}, (_, i) => i);
    const C = [];

    for (let i=0 ; i<N ; i++) {
        let lo = -1, hi = C.length;
        while (lo + 1 < hi) {
            const mid = ((lo + hi) / 2) | 0;
            if (A[C[mid]] < A[i]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (hi === C.length) C.push(i);
        else C[hi] = i;
        
        parent[i] = C[hi-1];
    }

    let result = C.length + '\n';

    const temp = [];
    let x = C[C.length-1];
    while (x !== parent[x]) {
        temp.push(A[x]);
        x = parent[x];
    }
    result += temp.reverse().join(' ');

    return result;
}

console.log(solve());