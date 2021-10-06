// javascript is synchronous.
// execute the code block by order after hoisting
// hoisting : var, function

// console.log("1");
// setTimeout(()=>{console.log("2")}, 1000);
// console.log("3");

// //호이스팅에 의해서 함수가 맨 위로 올라감.
// //synchronous callback
// function printImmediately(print){
//   print();
// }
// printImmediately(() => console.log("hello"));

// // Asynchronous callback
// function printWithDelay(print, timeout){
//   setTimeout(print, timeout);
// }
// printWithDelay(()=> console.log('async callback'), 2000);

// 언어를 마다 콜백을 지원하는 방식이 여러가지이다.
// 콜백으로만 코드를 작성하면 화가 많이 난다. => 콜백 지옥

// Callback Hell example
class UserStorage{
  // 로그인 api
  loginUser(id, password, onSuccess, onError){
    setTimeout(()=>{
      if(
        (id==="ellie" && password==='dream') ||
        (id=="chaos" && password==="order")
      ){
        onSuccess(id);
      }else{
        onError(new Error("not found"));
      }

    },2000)
  }
  // 사용자 역할 얻어내는 api
  getRoles(user, onSuccess, onError){
    setTimeout(()=>{
      if(user==='ellie'){
        onSuccess({name: 'ellie', role: 'admin'});
      }else{
        onError(new Error("no access"));
      }
    }, 1000);
  } 
}
const us =  new UserStorage();
const id = "ellie";
const password = 'dream';
us.loginUser(id, password, (user)=>{
  us.getRoles(user, (userWithRole)=>{
    console.log(`Hello ${userWithRole.name}, you have a ${userWithRole.role} role`);
  },
  (error)=>{
    console.log(error);
  })
}, error=>{console.log(error)});
//가독성이 너무 떨어진다 ㅠ!
// 한 눈에 알아보기 어렵고, 디버깅도 어렵다. => 유지보수도 어렵다.
// 이런식으로 하면 안된다.
// promise와 async를 통해 어떻게 더 잘 짤 수 있을까 고민해보아라.