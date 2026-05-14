// Address: 0x14016d280
// Ghidra name: FUN_14016d280
// ============ 0x14016d280 FUN_14016d280 (size=229) ============


undefined8 FUN_14016d280(int param_1,int *param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined8 uVar5;

  

  lVar4 = FUN_14016dd00();

  lVar1 = DAT_1403fc410;

  if (lVar4 == 0) {

    return 0;

  }

  if (param_2 != (int *)0x0) {

    if (*(longlong *)(DAT_1403fc410 + 0x28) != 0) {

      param_2[0] = 0;

      param_2[1] = 0;

      param_2[2] = 0;

      param_2[3] = 0;

      cVar2 = (**(code **)(lVar1 + 0x28))(lVar1,lVar4,param_2);

      if (cVar2 != '\0') {

        return 1;

      }

    }

    iVar3 = FUN_14016dba0();

    if (param_1 == iVar3) {

      param_2[0] = 0;

      param_2[1] = 0;

    }

    else {

      iVar3 = FUN_14016d5f0(param_1);

      FUN_14016d280(**(undefined4 **)

                      ((longlong)iVar3 * 8 + -8 + *(longlong *)(DAT_1403fc410 + 0x330)),param_2);

      *param_2 = *param_2 + param_2[2];

    }

    param_2[2] = *(int *)(*(longlong *)(lVar4 + 0x48) + 8);

    param_2[3] = *(int *)(*(longlong *)(lVar4 + 0x48) + 0xc);

    return 1;

  }

  uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030db68);

  return uVar5;

}




