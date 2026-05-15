// Address: 0x1402e808c
// Ghidra name: __acrt_uninitialize_locale
// ============ 0x1402e808c __acrt_uninitialize_locale (size=46) ============


/* Library Function - Single Match

    __acrt_uninitialize_locale

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __acrt_uninitialize_locale(void)



{

  <lambda_3e16ef9562a7dcce91392c22ab16ea36> local_res8 [8];

  undefined4 local_res10 [2];

  undefined4 local_res18 [4];

  

  local_res10[0] = 4;

  local_res18[0] = 4;

  __crt_seh_guarded_call<void>::

  operator()<<lambda_410d79af7f07d98d83a3f525b3859a53>,<lambda_3e16ef9562a7dcce91392c22ab16ea36>&___ptr64,<lambda_38119f0e861e05405d8a144b9b982f0a>_>

            ((__crt_seh_guarded_call<void> *)local_res8,

             (<lambda_410d79af7f07d98d83a3f525b3859a53> *)local_res18,local_res8,

             (<lambda_38119f0e861e05405d8a144b9b982f0a> *)local_res10);

  return;

}




