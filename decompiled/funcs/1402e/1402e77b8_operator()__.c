// Address: 0x1402e77b8
// Ghidra name: operator()<>
// ============ 0x1402e77b8 operator()<> (size=59) ============


/* Library Function - Multiple Matches With Same Base Name

    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class

   <lambda_638799b9deba96c50f710eeac98168cd>,class <lambda_22ebabd17bc4fa466a2aca6d8deb888d> &

   __ptr64,class <lambda_a6f7d7db0129f75315ebf26d50c089f1> >(class

   <lambda_638799b9deba96c50f710eeac98168cd> && __ptr64,class

   <lambda_22ebabd17bc4fa466a2aca6d8deb888d> & __ptr64,class

   <lambda_a6f7d7db0129f75315ebf26d50c089f1> && __ptr64) __ptr64

    public: int __cdecl __crt_seh_guarded_call<int>::operator()<class

   <lambda_b8c45f8f788dd370798f47cfe8ac3a86>,class <lambda_4e60a939b0d047cfe11ddc22648dfba9> &

   __ptr64,class <lambda_332c3edc96d0294ec56c57d38c1cdfd5> >(class

   <lambda_b8c45f8f788dd370798f47cfe8ac3a86> && __ptr64,class

   <lambda_4e60a939b0d047cfe11ddc22648dfba9> & __ptr64,class

   <lambda_332c3edc96d0294ec56c57d38c1cdfd5> && __ptr64) __ptr64

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined4

operator()<>(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 *param_4)



{

  undefined4 uVar1;

  

  __acrt_lock(*param_2);

  uVar1 = FUN_1402e7830(param_3);

  __acrt_unlock(*param_4);

  return uVar1;

}




