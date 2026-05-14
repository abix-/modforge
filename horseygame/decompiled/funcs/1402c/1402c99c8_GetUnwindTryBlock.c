// Address: 0x1402c99c8
// Ghidra name: GetUnwindTryBlock
// ============ 0x1402c99c8 GetUnwindTryBlock (size=41) ============


/* Library Function - Single Match

    public: static int __cdecl __FrameHandler3::GetUnwindTryBlock(unsigned __int64 * __ptr64,struct

   _xDISPATCHER_CONTEXT * __ptr64,struct _s_FuncInfo const * __ptr64)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



int __cdecl

__FrameHandler3::GetUnwindTryBlock

          (__uint64 *param_1,_xDISPATCHER_CONTEXT *param_2,_s_FuncInfo *param_3)



{

  longlong *plVar1;

  

  plVar1 = (longlong *)FUN_1402c85ec();

  return *(int *)((longlong)param_3->dispUnwindHelp + 4 + *plVar1);

}




