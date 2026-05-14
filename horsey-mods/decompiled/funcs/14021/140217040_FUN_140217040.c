// Address: 0x140217040
// Ghidra name: FUN_140217040
// ============ 0x140217040 FUN_140217040 (size=135) ============


int FUN_140217040(longlong param_1,longlong param_2,int param_3)



{

  longlong *plVar1;

  int iVar2;

  int iVar3;

  

  plVar1 = *(longlong **)(param_1 + 200);

  iVar3 = param_3;

  if (*plVar1 != 0) {

    iVar2 = FUN_14012c730(*plVar1,param_2,(longlong)param_3);

    iVar3 = param_3 - iVar2;

    param_2 = param_2 + iVar2;

    if (0 < iVar3) {

      FUN_14012bd50(*plVar1);

      *plVar1 = 0;

    }

  }

  FUN_1402f94c0(param_2,*(undefined4 *)(param_1 + 0x88),(longlong)iVar3);

  return param_3;

}




