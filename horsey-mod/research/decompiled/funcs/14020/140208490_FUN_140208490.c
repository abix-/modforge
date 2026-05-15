// Address: 0x140208490
// Ghidra name: FUN_140208490
// ============ 0x140208490 FUN_140208490 (size=87) ============


void FUN_140208490(longlong param_1,char *param_2)



{

  undefined8 uVar1;

  int iVar2;

  

  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&

     ((*(char **)(param_1 + 0x28) == (char *)0x0 ||

      (iVar2 = strcmp(param_2,*(char **)(param_1 + 0x28)), iVar2 != 0)))) {

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x28));

    uVar1 = FUN_14012f0d0(param_2);

    *(undefined8 *)(param_1 + 0x28) = uVar1;

    FUN_140208b70(param_1);

  }

  return;

}




