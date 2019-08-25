class Sort {

  maxNum(arr) {
    let max = arr[0]
    for (let i = 0; i< arr.length; i++) {
      if (arr[i] > max) 
        max = a[i]
    }
    return max
  }

  swap(arr, minor, major) {
    const aux = arr[minor];
    arr[minor] = arr[major];
    arr[major] = aux;
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

  bubbleSort(arr, n) {
    for(let i = 0; i < n-1; i++) {
      for (let j=0; j < n-i-1; j++) {
        if(arr[j] > arr[j+1])
          this.swap(arr,j, j+1)
      }
    }
    console.log(arr)
  }
}


const s = new Sort();

const a = [5, 2, 3, 4, 2,1,2,3,20]
const b = new Array(a.length)

// s.countingSort(a,b)
s.bubbleSort(a, a.length)
