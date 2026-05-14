// Address: 0x1402c90a8
// Ghidra name: __AdjustPointer
// ============ 0x1402c90a8 __AdjustPointer (size=35) ============


/* Library Function - Single Match

    __AdjustPointer

   

   Library: Visual Studio */



longlong __AdjustPointer(longlong param_1,int *param_2)



{

  longlong lVar1;

  

  lVar1 = *param_2 + param_1;

  if (-1 < param_2[1]) {

    lVar1 = lVar1 + (longlong)*(int *)((longlong)param_2[2] + *(longlong *)(param_2[1] + param_1)) +

                    (longlong)param_2[1];

  }

  return lVar1;

}




