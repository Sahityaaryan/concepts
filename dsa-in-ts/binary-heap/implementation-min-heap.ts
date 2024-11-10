class MinHeap{

    public arr:Array<number> = [];
    public size!:number;

    constructor(
      public capacity:number,
    ){ this.size = 0;}



    // ** Fake constructor 

    // constructor(
    //   public capacity:number = 20,
    // ){ 
    //   this.size = 10;
    //   this.arr = [40, 20, 30, 35,25,80, 32, 100, 70, 60];
    //   this.capacity = 20;
    // }


    public left(i:number):number{
      if(i >= this.size || i < 0){
        throw new Error("Index out of bound");
      }
      return (2*i + 1);
    }

    public right(i:number):number{
      if(i >= this.size || i < 0){
        throw new Error("Index out of bound");
      }
      return (2*i + 2);
    }

    public parent(i:number):number{
      if(i >= this.size || i < 0){
        throw new Error("Index out of bound");
      }

      if(i == 0){
        return -1;
      }

      return Math.floor((i-1)/2);
    }


    // Implementation of Insertion

    public insert(val:number){

      if(this.capacity < this.size + 1){
        this.capacity *= 2;
      }

      this.arr.push(val);

      let currIndex:number = this.size;
      this.size++;
      let parentIndex:number = this.parent(currIndex);

      while(parentIndex >= 0 && this.arr[parentIndex] > this.arr[currIndex]){
        
        let temp:number = this.arr[parentIndex];
        this.arr[parentIndex] = this.arr[currIndex];
        this.arr[currIndex] = temp;

        currIndex = parentIndex;
        parentIndex = this.parent(currIndex);
      }
    }


    // Implementation of MinHeapify
    
    public MinHeapify(currIndex:number = 0){
      if(currIndex >= this.size){
        return;
      }

      let leftIndex:number = this.left(currIndex);
      let rightIndex:number = this.right(currIndex);
      let smallestIndex:number = currIndex;

      if(leftIndex < this.size && this.arr[leftIndex] < this.arr[smallestIndex]){
        smallestIndex = leftIndex;
      }

      if(rightIndex < this.size && this.arr[rightIndex] < this.arr[smallestIndex]){
        smallestIndex = rightIndex;
      }

      if(smallestIndex != currIndex){
        let temp:number = this.arr[smallestIndex];
        this.arr[smallestIndex] = this.arr[currIndex];
        this.arr[currIndex] = temp;

        this.MinHeapify(smallestIndex);
      }
      
    }
  }



  // let heap1:MinHeap = new MinHeap(8);

  // heap1.insert(10);
  // heap1.insert(20);
  // heap1.insert(15);
  // heap1.insert(40);
  // heap1.insert(50);
  // heap1.insert(100);
  // heap1.insert(25);
  // heap1.insert(45);
  // heap1.insert(12);

  // console.log(heap1.arr);

