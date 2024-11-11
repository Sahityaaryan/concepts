// class MinHeap1{

//   public arr:Array<number> = [];
//   public size!:number;

//   constructor(
//     public capacity:number,
//   ){ this.size = 0;}


//   // constructor(
//   //   public capacity:number = 20,
//   // ){ 
//   //     //   this.arr = [40, 20, 30, 35,25,80, 32, 100, 70, 60];
//   //     this.arr = [10, 20, 30, 40, 50, 35, 38, 45];
//   //     this.size = this.arr.length;
//   //   this.capacity = 20;
//   // }


//   public left(i:number):number{
//     if(i >= this.size || i < 0){
//       throw new Error("Index out of bound");
//     }
//     return (2*i + 1);
//   }

//   public right(i:number):number{
//     if(i >= this.size || i < 0){
//       throw new Error("Index out of bound");
//     }
//     return (2*i + 2);
//   }

//   public parent(i:number):number{
//     if(i >= this.size || i < 0){
//       throw new Error("Index out of bound");
//     }

//     if(i == 0){
//       return -1;
//     }

//     return Math.floor((i-1)/2);
//   }

//   public insert(val:number){

//     if(this.capacity < this.size + 1){
//       this.capacity *= 2;
//     }

//     if(this.size < this.arr.length){
//       this.arr[this.size+1] = val;
//     } else {
//       this.arr.push(val);
//     }

//     let currIndex:number = this.size;
//     this.size++;
//     let parentIndex:number = this.parent(currIndex);

//     while(parentIndex >= 0 && this.arr[parentIndex] > this.arr[currIndex]){
      
//       let temp:number = this.arr[parentIndex];
//       this.arr[parentIndex] = this.arr[currIndex];
//       this.arr[currIndex] = temp;

//       currIndex = parentIndex;
//       parentIndex = this.parent(currIndex);
//     }
//   }
  

//   // Implementation of MinHeapify
  
//   public MinHeapify(currIndex:number = 0){
//       if(currIndex >= this.size){
//         return;
//       }

//       let leftIndex:number = this.left(currIndex);
//       let rightIndex:number = this.right(currIndex);
//       let smallestIndex:number = currIndex;

//       if(leftIndex < this.size && this.arr[leftIndex] < this.arr[smallestIndex]){
//         smallestIndex = leftIndex;
//       }

//       if(rightIndex < this.size && this.arr[rightIndex] < this.arr[smallestIndex]){
//         smallestIndex = rightIndex;
//       }

//       if(smallestIndex != currIndex){
//         let temp:number = this.arr[smallestIndex];
//         this.arr[smallestIndex] = this.arr[currIndex];
//         this.arr[currIndex] = temp;

//         this.MinHeapify(smallestIndex);
//       }
      
//     }

//   // Implementation Decrease key

//   public decreaseKey(i:number, val:number){

//       if(i >= this.size){
//           return;
//       }

//       if(i == 0){
//           this.arr[0] = val;
//           this.MinHeapify(0);
//           return;
//       }

//       this.arr[i] = val;

//       let parentIndex:number = this.parent(i);
//       let currIndex:number = i;

//       while( parentIndex >= 0 && this.arr[currIndex] < this.arr[parentIndex]){

//           // swap
          
//           [this.arr[currIndex], this.arr[parentIndex]] = [this.arr[parentIndex], this.arr[currIndex]];

//           currIndex = parentIndex;
//           parentIndex = this.parent(currIndex);
//       }
//   }


//   // Implementing Delete Key

//   public deleteKey(i:number){
//       if(i < 0 || i >= this.size){
//           return;
//       }
//       this.arr[i] = Number.MAX_SAFE_INTEGER;
//       this.MinHeapify(i);
//       this.size--;
//   }

//   // Printing heap
//   public printHeap(){

//    let tempArr:Array<number> = [];

//    for(let i = 0;i<this.size;i++){
//     tempArr.push(this.arr[i]);
//    }

//    console.log(tempArr);

//   //  tempArr = []; // by this garbage collector of js will free up the space taken previously because I have removed the reference of the previous array and hence it will be deallocated from the memory
//   }


//   }




// let heap1:MinHeap1 = new MinHeap1(8);

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

// //   let arr:Array<number> = [40, 20, 30, 35,25,80, 32, 100, 70, 60];

// //   let heap3:MinHeap1 = new MinHeap1();

// console.log("before: ")
// heap1.printHeap();
// //   heap3.MinHeapify();
// //   heap3.decreaseKey(4,1);
// heap1.deleteKey(3);
// console.log("after: ")

// heap1.printHeap();


