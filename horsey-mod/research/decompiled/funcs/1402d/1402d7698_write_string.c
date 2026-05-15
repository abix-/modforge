// Address: 0x1402d7698
// Ghidra name: write_string
// ============ 0x1402d7698 write_string (size=165) ============


/* Library Function - Single Match

    public: void __cdecl __crt_stdio_output::string_output_adapter<wchar_t>::write_string(wchar_t

   const * __ptr64 const,int,int * __ptr64 const,class __crt_deferred_errno_cache & __ptr64)const

   __ptr64

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __thiscall

__crt_stdio_output::string_output_adapter<wchar_t>::write_string

          (string_output_adapter<wchar_t> *this,wchar_t *param_1,int param_2,int *param_3,

          __crt_deferred_errno_cache *param_4)



{

  undefined8 *puVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  if (param_2 != 0) {

    uVar3 = (ulonglong)param_2;

    puVar1 = *(undefined8 **)this;

    if (puVar1[2] == puVar1[1]) {

      if (*(char *)(puVar1 + 3) == '\0') {

        *param_3 = -1;

      }

      else {

        *param_3 = *param_3 + param_2;

      }

    }

    else {

      uVar2 = puVar1[1] - puVar1[2];

      uVar4 = uVar3;

      if (uVar2 < uVar3) {

        uVar4 = uVar2;

      }

      FUN_1402f8e20(*puVar1,param_1,uVar4 * 2);

      **(longlong **)this = **(longlong **)this + uVar4 * 2;

      *(longlong *)(*(longlong *)this + 0x10) = *(longlong *)(*(longlong *)this + 0x10) + uVar4;

      if (*(char *)(*(longlong *)this + 0x18) == '\0') {

        if (uVar4 == uVar3) {

          *param_3 = *param_3 + (int)uVar4;

        }

        else {

          *param_3 = -1;

        }

      }

      else {

        *param_3 = *param_3 + param_2;

      }

    }

  }

  return;

}




