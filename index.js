class Sort {

  maxNum(arr) {
    let max = arr[0]
    for (let i = 0; i< arr.length; i++) {
      if (arr[i] > max) 
        max = a[i]
    }
    return max
  }

  countingSort(a,b) {
    const c = [];
    let k = this.maxNum(a);

    for (let j = 0; j < k +1; j++) {
      c[j] = 0
    } 
    
    for (let t = 0; t<a.length; t++) {
      c[a[t]]++
    }

    for(let u = 1; u < c.length; u++) {
      c[u] = c[u] + c[u-1]
    }

    for (let z = a.length; z >= 0; z--) {
      b[--c[a[z]]] = a[z]
    }

    console.log(`Desordenado: ${a}`)
    console.log(`Ordenado: ${b}`)
  }

countingSortRadix(a, b, exp) {
  const c = [];
  let k = this.maxNum(a);

  for (let j = 0; j < k +1; j++) {
    c[j] = 0
  } 
  
  for (let t = 0; t<a.length; t++) {
    c[(a[t])]++
    count[ (arr[i]/exp)%10 ]++; 
  }

  for(let u = 1; u < c.length; u++) {
    c[u] = c[u] + c[u-1]
  }

  for (let z = a.length; z >= 0; z--) {
    b[--c[a[z]]] = a[z]
  }

    console.log(`Desordenado: ${a}`)
    console.log(`Ordenado: ${b}`)
  }
}


const s = new Sort();

const a = [5, 2, 3, 4, 2,1,2,3,20]
const b = new Array(a.length)

s.countingSort(a,b)
