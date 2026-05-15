// Address: 0x1402083c0
// Ghidra name: FUN_1402083c0
// ============ 0x1402083c0 FUN_1402083c0 (size=104) ============


void FUN_1402083c0(undefined8 *param_1,char *param_2)



{

  undefined2 uVar1;

  int iVar2;

  undefined8 uVar3;

  size_t sVar4;

  

  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&

     (iVar2 = strcmp(param_2,(char *)*param_1), iVar2 != 0)) {

    FUN_1401841e0(*param_1);

    uVar3 = FUN_14012f0d0(param_2);

    *param_1 = uVar3;

    sVar4 = strlen(param_2);

    uVar1 = FUN_140191680(0,param_2,sVar4);

    FUN_14015b420(param_1 + 6,uVar1);

  }

  return;

}




