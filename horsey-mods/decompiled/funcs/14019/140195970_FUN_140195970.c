// Address: 0x140195970
// Ghidra name: FUN_140195970
// ============ 0x140195970 FUN_140195970 (size=60) ============


undefined8 FUN_140195970(short param_1,short param_2)



{

  ulonglong uVar1;

  

  uVar1 = 0;

  while ((param_1 != *(short *)((longlong)&DAT_14033a290 + uVar1) ||

         ((param_2 != *(short *)((longlong)&DAT_14033a292 + uVar1) &&

          (*(short *)((longlong)&DAT_14033a292 + uVar1) != 0))))) {

    uVar1 = uVar1 + 4;

    if (0x1f < uVar1) {

      return 0;

    }

  }

  return 1;

}




