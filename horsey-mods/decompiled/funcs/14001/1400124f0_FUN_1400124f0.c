// Address: 0x1400124f0
// Ghidra name: FUN_1400124f0
// ============ 0x1400124f0 FUN_1400124f0 (size=177) ============


void FUN_1400124f0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,code *param_4)



{

  undefined8 uVar1;

  undefined4 uVar2;

  char cVar3;

  

  cVar3 = (*param_4)(param_2,param_1);

  if (cVar3 != '\0') {

    uVar1 = *param_2;

    uVar2 = *(undefined4 *)(param_2 + 1);

    *param_2 = *param_1;

    *(undefined4 *)(param_2 + 1) = *(undefined4 *)(param_1 + 1);

    *param_1 = uVar1;

    *(undefined4 *)(param_1 + 1) = uVar2;

  }

  cVar3 = (*param_4)(param_3,param_2);

  if (cVar3 != '\0') {

    uVar2 = *(undefined4 *)(param_3 + 1);

    uVar1 = *param_3;

    *param_3 = *param_2;

    *(undefined4 *)(param_3 + 1) = *(undefined4 *)(param_2 + 1);

    *param_2 = uVar1;

    *(undefined4 *)(param_2 + 1) = uVar2;

    cVar3 = (*param_4)(param_2,param_1);

    if (cVar3 != '\0') {

      uVar1 = *param_2;

      uVar2 = *(undefined4 *)(param_2 + 1);

      *param_2 = *param_1;

      *(undefined4 *)(param_2 + 1) = *(undefined4 *)(param_1 + 1);

      *param_1 = uVar1;

      *(undefined4 *)(param_1 + 1) = uVar2;

    }

  }

  return;

}




