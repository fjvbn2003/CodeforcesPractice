//콜백을 대신해서 어떻게 깔끔하게 작성할 수 있을지
// 자바스크립트에서 제공하는 비동기 코드를 깔끔하게 작성하게 도와주는 오브젝트


// Promis is a JavaScript object for asynchronous operation

/*
  1. State
  2. Producer, Consumer

  State: pending -> fulfilled or rejected
  Producer vs Consumer

*/

// 프로미스를 만드는 순간, execute가 수행 됨.
// When new Promise is created, the executor runs automatically.

// // 1. Producer
// const promise  = new Promise((resolve, reject) =>{
//   // doing some heavy work
//   console.log("doing something...");
//   setTimeout(() =>{
//     //resolve('ellie');
//     reject(new Error('no network'));
//   }, 2000);
// });

// // 2. Consumers: then, catch, finally
// promise.then((value)=>{
//   console.log(value);
// }).catch( error=>{
//   console.log(error);
// }).finally(()=>{ // finally 는 성공하든 실패하든 무조건 실행됨.
//    console.log("finally");
// })

// //
// // 3. promise chaining
// // 프로미스는 값을 리턴할 수도 있고, 프로미스를 리턴할 수도 있다.
// const fetchNumber = new Promise((resolve, reject) =>{
//   setTimeout(() => resolve(1), 1000);
// });

// fetchNumber.then(num => num*2)
// .then(num => num*3)
// .then(num =>{
//   return new Promise((resolve, reject)=>{
//     setTimeout(() => resolve(num-1), 1000);
//   });
// })
// .then(num =>console.log(num));

// 4. Error Handling
// resolve를 호출하면 해당하는 인자가 리턴 됨.
const getHen = () => new Promise((resolve, reject)=>{
  setTimeout(()=> resolve('암탉'), 1000);
});
const getEgg = hen => new Promise((resolve, reject) =>{
  //setTimeout(()=> resolve(`${hen} => hen`), 1000);
  setTimeout(()=> reject(new Error(`error! ${hen}}`)), 1000);
});
const cook = egg => new Promise((resolve, reject) =>{
  setTimeout(()=> resolve(`${egg} => frypen`), 1000);
});

// getHen()
// .then(hen => getEgg(hen))
// .then(egg => cook(egg))
// .then(meal => console.log(meal));

//함수 인자가 한개라면, 암묵적으로 함수에 인자로 전달!
//이렇게도 가능!
getHen()
.then(getEgg)
.catch(error=>{ //애러가 나면 빵으로 채워줌. => 프로미스체인이 끝까지 이어주도록.
  return '빵';
})
.then(cook)
.then(console.log)
.catch(console.log);


