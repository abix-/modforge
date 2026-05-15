// Address: 0x14013c450
// Ghidra name: FUN_14013c450
// ============ 0x14013c450 FUN_14013c450 (size=159) ============


void FUN_14013c450(undefined8 param_1,longlong param_2,int param_3,char param_4)



{

  int iVar1;

  int *piVar2;

  longlong lVar3;

  

  _guard_check_icall();

  iVar1 = 0;

  if (0 < *(int *)(param_2 + 0x28)) {

    piVar2 = *(int **)(param_2 + 0x30);

    do {

      if ((*piVar2 == 1) && (param_3 == piVar2[1])) {

        if (piVar2[4] == 2) {

          lVar3 = 0x1c;

          if (param_4 == '\0') {

            lVar3 = 0x18;

          }

          FUN_140141cf0(param_1,param_2,piVar2[5],*(undefined2 *)(lVar3 + (longlong)piVar2));

          return;

        }

        FUN_140141d70(param_1,param_2,piVar2[5],param_4);

        return;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 8;

    } while (iVar1 < *(int *)(param_2 + 0x28));

  }

  return;

}




