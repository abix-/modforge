// Address: 0x140217650
// Ghidra name: FUN_140217650
// ============ 0x140217650 FUN_140217650 (size=175) ============


longlong FUN_140217650(longlong param_1,uint *param_2,undefined8 param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_140217610(param_1 + 0x48);

  if (lVar1 != 0) {

    lVar2 = FUN_140217c10(param_1,param_2,param_3,lVar1,0,

                          *(ulonglong *)(param_1 + 0x50) -

                          *(ulonglong *)(param_1 + 0x50) %

                          (ulonglong)((*param_2 >> 3 & 0x1f) * param_2[1]),&LAB_140217790,param_1);

    if (lVar2 != 0) {

      return lVar2;

    }

    FUN_1402177a0(param_1 + 0x48,lVar1);

  }

  return 0;

}




