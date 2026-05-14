// Address: 0x140142a20
// Ghidra name: FUN_140142a20
// ============ 0x140142a20 FUN_140142a20 (size=136) ============


ulonglong FUN_140142a20(char *param_1,uint param_2)



{

  int iVar1;

  ulonglong uVar2;

  

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    return (ulonglong)param_2;

  }

  uVar2 = FUN_14012ef60(param_1,"false");

  if ((int)uVar2 == 0) {

    return uVar2;

  }

  iVar1 = FUN_14012ef60(param_1,&DAT_14031ad1c);

  if (iVar1 != 0) {

    if ((*param_1 != '-') && (iVar1 = FUN_140190340((int)*param_1), iVar1 == 0)) {

      return (ulonglong)param_2;

    }

    uVar2 = thunk_FUN_1402d89dc(param_1);

    return uVar2;

  }

  return 1;

}




