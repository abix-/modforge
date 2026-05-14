// Address: 0x14027d190
// Ghidra name: FUN_14027d190
// ============ 0x14027d190 FUN_14027d190 (size=133) ============


undefined1 FUN_14027d190(undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)



{

  int iVar1;

  longlong lVar2;

  undefined1 uVar3;

  

  lVar2 = *(longlong *)(param_2 + 0xa0);

  if (lVar2 != 0) {

    iVar1 = *(int *)(param_3 + 3);

    if (*(uint *)(param_3 + 7) + iVar1 <= *(uint *)(param_2 + 0xa8)) {

      if (iVar1 != 0) {

        FUN_1402f8e20(lVar2 + (ulonglong)*(uint *)(param_3 + 7),param_4,iVar1);

        return 1;

      }

      uVar3 = FUN_14027cf20(param_1,param_2,param_3,lVar2,*(uint *)(param_2 + 0xa8));

      FUN_14027cef0(param_2);

      return uVar3;

    }

  }

  return 0;

}




