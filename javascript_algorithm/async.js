/*
우리밋의 노드js 동작과정 유튜브를 보고 배운 것
< node js 구성요소>
콜스텍: 동기적인 동작을 하기 위한 스텍. 
콜백큐 (마이크로테스트 큐, 잡 큐): web api가 비동기 콜벡함수를 큐에 넣어 줌
web api(): 시스템에서 제공하는 서비스 들(setTimeout, axios)
event loop(): 콜 스텍이 비어있는지 계속 확인하다가 비어있으면 콜벡큐에서 넣어줌.
*/

// 드림코디이엘리 동영상 13강을 보고 정리한 것.

// async & await

//1. Promise

function fetchUser() {
  // do network request in 10 secs...
  return new Promise((resolve, reject) => {
    // setTimeout(()=>{
    //   resolve("get network resource (such as axios)");
    // },1000);
    resolve("get network resource (such as axios)");
  });
}
// promise 는 현재 pending 상태!
const user = fetchUser();
// 내가 언제 가져올지는 모르지만 네트워크 리소스를 가져오면
user.then(console.log).catch(console.log);
console.log("another task");

//2. async (synthetic sugar)
// async라는 키워드를 함수 앞에 쓰면 코드블록이 자동으로 프로미스 객체를 리턴하고
// 따라서 then, catch와 같은 메소드를 통해 비동기 코드를 구현할 수 있다.
async function fetchUser_async() {
  // do network request in 10 secs...
  return "async get network resource (such as axios)";
}
// promise 는 현재 pending 상태!
const user2 = fetchUser_async();
// 내가 언제 가져올지는 모르지만 네트워크 리소스를 가져오면
//console.log(user);
user2.then(console.log).catch(console.log);
//console.log(user);
console.log("another task");

// 3. await
function delay(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}
async function getApple() {
  await delay(3000);
  return "apple";
}
// async와 await은 함께 사용됨.
// await으로 되어있는 "비동기함수"를 기다렸다가 바나나를 리턴함.
// 만약 await을 쓰지 않았다면, banana가 바로 리턴됨.
async function getBanana() {
  await delay(3000);
  //throw 'error';
  return "banana";
}
// promise도 콜백 지옥 문제를 완전히 해결할 수는 없다. 3초 + 3초 걸림.
// (아래 코드도 이해할 수는 있으나 조금 지저분하다.)
// function pickFruits(){
//   return getApple()
//   .then(apple=>{
//     return getBanana()
//     .then(banana => `${apple} + ${banana}`);
//   })
// }
// pickFruits().then(console.log);

//병렬처리.
async function pickFruits_parellel() {
  try {
    const applePromise = getApple();
    const bananaPromise = getBanana();
    // 바나나랑 사과를 병렬적으로 처리.
    const apple = await applePromise;
    const banana = await bananaPromise;
    return `${apple} + ${banana}`;
  } catch {
    console.log("error");
  }
}
async function pickFruits() {
  try {
    const apple = await getApple();
    const banana = await getBanana();
    return `${apple} + ${banana}`;
  } catch {
    console.log("error");
  }
}
var start = new Date();
pickFruits().then((ret) => {
  const end = new Date();
  console.log("in pickFruits takes: ", end - start);
});

start = new Date();
pickFruits_parellel().then((ret) => {
  const end = new Date();
  console.log("in pickFruits_parallel takes: ", end - start);
});

console.log("another sync task!!");

// 4. useful Promise APIs
function pickAllFruits() {
  return Promise.all([getApple(), getBanana()]).then((fruits) =>
    fruits.join("+")
  );
}
pickAllFruits().then((ret) => {
  console.log("in pick all fruits: " + ret);
});

function pickOnlyOne() {
  //사과를 따는데 1초, 바나나 2초가 걸린다면 먼저 오는 것(사과)만 전달하려면
  return Promise.race([getApple(), getBanana()]);
}
pickOnlyOne().then(console.log);
