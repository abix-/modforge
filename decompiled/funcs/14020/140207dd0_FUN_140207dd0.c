// Address: 0x140207dd0
// Ghidra name: FUN_140207dd0
// ============ 0x140207dd0 FUN_140207dd0 (size=112) ============


longlong FUN_140207dd0(char *param_1,short param_2,short param_3)



{

  longlong lVar1;

  int iVar2;

  

  _guard_check_icall();

  lVar1 = DAT_1403fd198;

  while ((lVar1 != 0 &&

         (((*(short *)(lVar1 + 0x20) != param_2 || (*(short *)(lVar1 + 0x22) != param_3)) ||

          (iVar2 = strcmp(*(char **)(lVar1 + 0x18),param_1), iVar2 != 0))))) {

    lVar1 = *(longlong *)(lVar1 + 0xb8);

  }

  return lVar1;

}




