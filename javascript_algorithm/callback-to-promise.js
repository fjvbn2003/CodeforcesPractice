class UserStorage{
  // 로그인 api
  loginUser(id, password){
    return new Promise((resolve, reject) =>{
      setTimeout(()=>{
        if(
          (id==="ellie" && password==='dream') ||
          (id=="chaos" && password==="order")
        ){
          resolve(id);
        }else{
          reject(new Error("not found"));
        }
  
      },2000)
    })
    
  }
  // 사용자 역할 얻어내는 api
  getRoles(user){
    return new Promise((resolve, reject) =>{
      setTimeout(()=>{
        if(user==='ellie'){
          resolve({name: 'ellie', role: 'admin'});
        }else{
          reject(new Error("no access"));
        }
      }, 1000);
    })
    
  } 
}

// promise와 그 안의resolve, reject로 콜벡 지옥을 해결!!
const us = new UserStorage();
const id = "ellie";
const password = 'dream';

us.loginUser(id, password)
.then((user)=> us.getRoles(user))
.then((user)=>{
  console.log(`Hello ${user.name}, you have a ${user.role} role`);
})
.catch(console.log);


// const us =  new UserStorage();
// const id = "ellie";
// const password = 'dream';
// us.loginUser(id, password, (user)=>{
//   us.getRoles(user, (userWithRole)=>{
//     console.log(`Hello ${userWithRole.name}, you have a ${userWithRole.role} role`);
//   },
//   (error)=>{
//     console.log(error);
//   })
// }, error=>{console.log(error)});