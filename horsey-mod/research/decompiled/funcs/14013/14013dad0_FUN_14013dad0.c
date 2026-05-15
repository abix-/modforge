// Address: 0x14013dad0
// Ghidra name: FUN_14013dad0
// ============ 0x14013dad0 FUN_14013dad0 (size=211) ============


ulonglong FUN_14013dad0(longlong param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  ulonglong uVar3;

  int iVar4;

  byte bVar5;

  

  bVar5 = 0;

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,5);

      if (cVar1 == '\0') goto LAB_14013db79;

    }

    cVar1 = FUN_1401596f0();

    if (cVar1 != '\0') {

      iVar4 = 0;

      if (0 < *(int *)(param_1 + 0x28)) {

        piVar2 = (int *)(*(longlong *)(param_1 + 0x30) + 0x14);

        while ((piVar2[-1] != 1 || (*piVar2 != param_2))) {

          iVar4 = iVar4 + 1;

          piVar2 = piVar2 + 8;

          if (*(int *)(param_1 + 0x28) <= iVar4) {

            FUN_14015bb10();

            return 0;

          }

        }

        bVar5 = 1;

      }

      FUN_14015bb10();

      return (ulonglong)bVar5;

    }

  }

LAB_14013db79:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




