// Address: 0x140268130
// Ghidra name: FUN_140268130
// ============ 0x140268130 FUN_140268130 (size=86) ============


longlong FUN_140268130(longlong param_1,int *param_2)



{

  longlong lVar1;

  int iVar2;

  longlong *plVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  iVar2 = 0;

  plVar3 = (longlong *)(lVar1 + 0x18);

  while ((lVar1 = *plVar3, lVar1 == 0 || (*(int *)(lVar1 + 0xc) != *param_2))) {

    iVar2 = iVar2 + 1;

    plVar3 = plVar3 + 1;

    if (7 < iVar2) {

      return 0;

    }

  }

  return lVar1;

}




