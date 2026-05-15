// Address: 0x1402e8010
// Ghidra name: operator()<<lambda_410d79af7f07d98d83a3f525b3859a53>,<lambda_3e16ef9562a7dcce91392c22ab16ea36>&___ptr64,<lambda_38119f0e861e05405d8a144b9b982f0a>_>
// ============ 0x1402e8010 operator()<<lambda_410d79af7f07d98d83a3f525b3859a53>,<lambda_3e16ef9562a7dcce91392c22ab16ea36>&___ptr64,<lambda_38119f0e861e05405d8a144b9b982f0a>_> (size=110) ============


/* Library Function - Single Match

    public: void __cdecl __crt_seh_guarded_call<void>::operator()<class

   <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36> &

   __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a> >(class

   <lambda_410d79af7f07d98d83a3f525b3859a53> && __ptr64,class

   <lambda_3e16ef9562a7dcce91392c22ab16ea36> & __ptr64,class

   <lambda_38119f0e861e05405d8a144b9b982f0a> && __ptr64) __ptr64

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __thiscall

__crt_seh_guarded_call<void>::

operator()<<lambda_410d79af7f07d98d83a3f525b3859a53>,<lambda_3e16ef9562a7dcce91392c22ab16ea36>&___ptr64,<lambda_38119f0e861e05405d8a144b9b982f0a>_>

          (__crt_seh_guarded_call<void> *this,<lambda_410d79af7f07d98d83a3f525b3859a53> *param_1,

          <lambda_3e16ef9562a7dcce91392c22ab16ea36> *param_2,

          <lambda_38119f0e861e05405d8a144b9b982f0a> *param_3)



{

  longlong lVar1;

  longlong *plVar2;

  

  __acrt_lock(*(undefined4 *)param_1);

  for (plVar2 = &DAT_1403ff150; plVar2 != (longlong *)&DAT_1403ff158; plVar2 = plVar2 + 1) {

    if ((undefined **)*plVar2 != &PTR_DAT_1403e8d30) {

      lVar1 = _updatetlocinfoEx_nolock(plVar2,&PTR_DAT_1403e8d30);

      *plVar2 = lVar1;

    }

  }

  __acrt_unlock(*(undefined4 *)param_3);

  return;

}




