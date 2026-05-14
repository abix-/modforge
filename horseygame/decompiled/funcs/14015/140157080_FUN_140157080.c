// Address: 0x140157080
// Ghidra name: FUN_140157080
// ============ 0x140157080 FUN_140157080 (size=176) ============


ulonglong FUN_140157080(int *param_1,uint param_2,undefined8 param_3,undefined8 param_4,

                       undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8,

                       undefined4 param_9)



{

  ulonglong uVar1;

  longlong lVar2;

  

  if (*param_1 != -1) {

    lVar2 = 0;

    do {

      uVar1 = FUN_140157130(param_1[lVar2],(ulonglong)param_2,param_3,param_4,param_5,param_6,

                            param_7,param_8,param_9);

      if ((uint)uVar1 != param_2) {

        return uVar1;

      }

      lVar2 = lVar2 + 1;

    } while (lVar2 < 3);

  }

  return (ulonglong)param_2;

}




