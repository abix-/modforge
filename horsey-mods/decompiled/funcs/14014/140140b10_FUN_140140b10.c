// Address: 0x140140b10
// Ghidra name: FUN_140140b10
// ============ 0x140140b10 FUN_140140b10 (size=260) ============


void FUN_140140b10(longlong *param_1,undefined4 *param_2)



{

  char cVar1;

  uint uVar2;

  ulonglong uVar3;

  int *piVar4;

  ulonglong uVar5;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  _guard_check_icall();

  uVar3 = 0;

  param_1[2] = *(longlong *)(param_2 + 4);

  *(undefined4 *)(param_1 + 5) = 0;

  param_1[4] = (longlong)param_2;

  if ((*(int *)(*param_1 + 0x44) != 0) && (param_1[7] != 0)) {

    FUN_1402f94c0(param_1[7],0,(longlong)*(int *)(*param_1 + 0x44) << 3);

  }

  FUN_140142530(param_1);

  FUN_140142320(param_1);

  FUN_140140d60(param_1,*(undefined8 *)(param_2 + 6));

  local_18 = *param_2;

  uStack_14 = param_2[1];

  uStack_10 = param_2[2];

  uStack_c = param_2[3];

  cVar1 = FUN_1401594b0(&local_18);

  if (cVar1 != '\0') {

    FUN_14013d680(param_1);

  }

  uVar5 = uVar3;

  if (0 < (int)param_1[5]) {

    do {

      piVar4 = (int *)(param_1[6] + uVar5);

      if (((*piVar4 == 2) && (piVar4[4] == 2)) && ((piVar4[5] == 4 || (piVar4[5] == 5)))) {

        if (piVar4[1] < *(int *)(*param_1 + 0x44)) {

          *(short *)(*(longlong *)(*param_1 + 0x48) + 4 + (longlong)piVar4[1] * 10) =

               (short)piVar4[2];

          *(undefined2 *)(*(longlong *)(*param_1 + 0x48) + 2 + (longlong)piVar4[1] * 10) =

               *(undefined2 *)(*(longlong *)(*param_1 + 0x48) + 4 + (longlong)piVar4[1] * 10);

        }

      }

      uVar2 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar2;

      uVar5 = uVar5 + 0x20;

    } while ((int)uVar2 < (int)param_1[5]);

  }

  return;

}




